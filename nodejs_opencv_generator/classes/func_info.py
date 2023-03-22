from .func_variant import FuncVariant 
from collections import namedtuple
from nodejs_opencv_generator.utils import (
    get_type_format_string, 
    ignored_arg_types, 
    pass_by_val_types, 
    normalize_class_name,
    FormatStrings
)
from string import Template

ArgTypeInfo = namedtuple('ArgTypeInfo',
                        ['atype', 'format_str', 'default_value',
                         'strict_conversion'])
# strict_conversion is False by default
ArgTypeInfo.__new__.__defaults__ = (False,)

from nodejs_opencv_generator.templates import (
	gen_template_check_self, 
	gen_template_call_constructor_prelude,
	gen_template_call_constructor,
	gen_template_simple_call_constructor_prelude,
	gen_template_simple_call_constructor,
	gen_template_parse_args,
	gen_template_func_body,
	gen_template_mappable,
	gen_template_type_decl,
	gen_template_map_type_cvt,
	gen_template_set_prop_from_map,
	gen_template_overloaded_function_call
)

simple_argtype_mapping = {
    "bool": ArgTypeInfo("bool", FormatStrings.unsigned_char, "0", True),
    "size_t": ArgTypeInfo("size_t", FormatStrings.unsigned_long_long, "0", True),
    "int": ArgTypeInfo("int", FormatStrings.int, "0", True),
    "float": ArgTypeInfo("float", FormatStrings.float, "0.f", True),
    "double": ArgTypeInfo("double", FormatStrings.double, "0", True),
    "c_string": ArgTypeInfo("char*", FormatStrings.string, '(char*)""'),
    "string": ArgTypeInfo("std::string", FormatStrings.object, None, True),
    "Stream": ArgTypeInfo("Stream", FormatStrings.object, 'Stream::Null()', True),
    "UMat": ArgTypeInfo("UMat", FormatStrings.object, 'UMat()', True),  # FIXIT: switch to CV_EXPORTS_W_SIMPLE as UMat is already a some kind of smart pointer
}

class FuncInfo(object):
    def __init__(self, classname, name, cname, isconstructor, namespace, is_static):
        self.classname = classname
        self.name = name
        self.cname = cname
        self.isconstructor = isconstructor
        self.namespace = namespace
        self.is_static = is_static
        self.variants = []

    def add_variant(self, decl, known_classes, isphantom=False):
        self.variants.append(
            FuncVariant(self.namespace, self.classname, self.name, decl,
                        self.isconstructor, known_classes, isphantom)
        )

    def get_wrapper_name(self):
        name = self.name
        if self.classname:
            classname = self.classname + "_"
            if "[" in name:
                name = "getelem"
        else:
            classname = ""

        if self.is_static:
            name += "_static"

        return "pyopencv_" + self.namespace.replace('.','_') + '_' + classname + name

    def get_wrapper_prototype(self, codegen):
        full_fname = self.get_wrapper_name()
        if self.isconstructor:
            return "static int {fn_name}(jsopencv_{type_name}_t* self, PyObject* py_args, PyObject* kw)".format(
                    fn_name=full_fname, type_name=codegen.classes[self.classname].name)

        if self.classname:
            self_arg = "self"
        else:
            self_arg = ""
        # PyObject* %s, PyObject* py_args, PyObject* kw % (full_fname, self_arg)
        return "static Napi::Value %s(const Napi::CallbackInfo &info)" % (full_fname)

    def get_tab_entry(self):
        prototype_list = []
        docstring_list = []

        have_empty_constructor = False
        for v in self.variants:
            s = v.py_prototype
            if (not v.py_arglist) and self.isconstructor:
                have_empty_constructor = True
            if s not in prototype_list:
                prototype_list.append(s)
                docstring_list.append(v.docstring)

        # if there are just 2 constructors: default one and some other,
        # we simplify the notation.
        # Instead of ClassName(args ...) -> object or ClassName() -> object
        # we write ClassName([args ...]) -> object
        if have_empty_constructor and len(self.variants) == 2:
            idx = self.variants[1].py_arglist != []
            s = self.variants[idx].py_prototype
            p1 = s.find("(")
            p2 = s.rfind(")")
            prototype_list = [s[:p1+1] + "[" + s[p1+1:p2] + "]" + s[p2:]]

        # The final docstring will be: Each prototype, followed by
        # their relevant doxygen comment
        full_docstring = ""
        for prototype, body in zip(prototype_list, docstring_list):
            full_docstring += Template("$prototype\n$docstring\n\n\n\n").substitute(
                prototype=prototype,
                docstring='\n'.join(
                    ['.   ' + line
                     for line in body.split('\n')]
                )
            )

        # Escape backslashes, newlines, and double quotes
        full_docstring = full_docstring.strip().replace("\\", "\\\\").replace('\n', '\\n').replace("\"", "\\\"")
        # Convert unicode chars to xml representation, but keep as string instead of bytes
        full_docstring = full_docstring.encode('ascii', errors='xmlcharrefreplace').decode()

        return Template('    {"$py_funcname", CV_JS_FN_WITH_KW_($wrap_funcname, $flags), "$py_docstring"},\n'
                        ).substitute(py_funcname = self.variants[0].wname, wrap_funcname=self.get_wrapper_name(),
                                     flags = 'METH_STATIC' if self.is_static else '0', py_docstring = full_docstring)

    def gen_code(self, codegen):
        all_classes = codegen.classes
        proto = self.get_wrapper_prototype(codegen)
        code = "%s\n{\n" % (proto,)
        code += "    using namespace %s;\n\n" % self.namespace.replace('.', '::')

        selfinfo = None
        ismethod = self.classname != "" and not self.isconstructor
        # full name is needed for error diagnostic in PyArg_ParseTupleAndKeywords
        fullname = self.name

        if self.classname:
            selfinfo = all_classes[self.classname]
            if not self.isconstructor:
                if not self.is_static:
                    code += gen_template_check_self.substitute(
                        name=selfinfo.name,
                        cname=selfinfo.cname if selfinfo.issimple else "Ptr<{}>".format(selfinfo.cname),
                        pname=(selfinfo.cname + '*') if selfinfo.issimple else "Ptr<{}>".format(selfinfo.cname),
                        cvt='' if selfinfo.issimple else '*'
                    )
                fullname = selfinfo.wname + "." + fullname

        all_code_variants = []

        for v in self.variants:
            code_decl = ""
            code_ret = ""
            code_cvt_list = []

            code_args = "("
            all_cargs = []

            if v.isphantom and ismethod and not self.is_static:
                code_args += "_self_"

            # declare all the C function arguments,
            # add necessary conversions from Python objects to code_cvt_list,
            # form the function/method call,
            # for the list of type mappings
            instantiated_args = set()
            for a in v.args:
                if a.tp in ignored_arg_types:
                    defval = a.defval
                    if not defval and a.tp.endswith("*"):
                        defval = "0"
                    assert defval
                    if not code_args.endswith("("):
                        code_args += ", "
                    code_args += defval
                    all_cargs.append([[None, ""], ""])
                    continue
                tp1 = tp = a.tp
                amp = ""
                defval0 = ""
                if tp in pass_by_val_types:
                    tp = tp1 = tp[:-1]
                    amp = "&"
                    if tp.endswith("*"):
                        defval0 = "0"
                        tp1 = tp.replace("*", "_ptr")
                tp_candidates = [a.tp, normalize_class_name(self.namespace + "." + a.tp)]
                if any(tp in codegen.enums.keys() for tp in tp_candidates):
                    defval0 = "static_cast<%s>(%d)" % (a.tp, 0)

                if tp in simple_argtype_mapping:
                    arg_type_info = simple_argtype_mapping[tp]
                else:
                    if tp in all_classes:
                        tp_classinfo = all_classes[tp]
                        cname_of_value = tp_classinfo.cname if tp_classinfo.issimple else "Ptr<{}>".format(tp_classinfo.cname)
                        arg_type_info = ArgTypeInfo(cname_of_value, FormatStrings.object, defval0, True)
                        assert not (a.is_smart_ptr and tp_classinfo.issimple), "Can't pass 'simple' type as Ptr<>"
                        if not a.is_smart_ptr and not tp_classinfo.issimple:
                            assert amp == ''
                            amp = '*'
                    else:
                        # FIXIT: Ptr_ / vector_ / enums / nested types
                        arg_type_info = ArgTypeInfo(tp, FormatStrings.object, defval0, True)

                parse_name = a.name
                if a.py_inputarg and arg_type_info.strict_conversion:
                    parse_name = "jsobj_" + a.full_name.replace('.', '_')
                    code_decl += "    Napi::Value* %s = NULL;\n" % (parse_name,)
                    if a.tp == 'char':
                        code_cvt_list.append("convert_to_char(%s, &%s, %s)" % (parse_name, a.full_name, a.crepr()))
                    else:
                        code_cvt_list.append("jsopencv_to_safe(info, %s, %s, %s)" % (parse_name, a.full_name, a.crepr()))

                all_cargs.append([arg_type_info, parse_name])

                # Argument is actually a part of the named arguments structure,
                # but it is possible to mimic further processing like it is normal arg
                if a.enclosing_arg:
                    a = a.enclosing_arg
                    arg_type_info = ArgTypeInfo(a.tp, FormatStrings.object,
                                                default_value=a.defval,
                                                strict_conversion=True)
                    # Skip further actions if enclosing argument is already instantiated
                    # by its another field
                    if a.name in instantiated_args:
                        continue
                    instantiated_args.add(a.name)

                defval = a.defval
                if not defval:
                    defval = arg_type_info.default_value
                else:
                    if "UMat" in tp:
                        if "Mat" in defval and "UMat" not in defval:
                            defval = defval.replace("Mat", "UMat")
                    if "cuda::GpuMat" in tp:
                        if "Mat" in defval and "GpuMat" not in defval:
                            defval = defval.replace("Mat", "cuda::GpuMat")
                # "tp arg = tp();" is equivalent to "tp arg;" in the case of complex types
                if defval == tp + "()" and arg_type_info.format_str == FormatStrings.object:
                    defval = ""
                if a.outputarg and not a.inputarg:
                    defval = ""
                if defval:
                    code_decl += "    %s %s=%s;\n" % (arg_type_info.atype, a.name, defval)
                else:
                    code_decl += "    %s %s;\n" % (arg_type_info.atype, a.name)

                if not code_args.endswith("("):
                    code_args += ", "

                if a.isrvalueref:
                    code_args += amp + 'std::move(' + a.name + ')'
                else:
                    code_args += amp + a.name

            code_args += ")"

            if self.isconstructor:
                if selfinfo.issimple:
                    templ_prelude = gen_template_simple_call_constructor_prelude
                    templ = gen_template_simple_call_constructor
                else:
                    templ_prelude = gen_template_call_constructor_prelude
                    templ = gen_template_call_constructor

                code_prelude = templ_prelude.substitute(name=selfinfo.name, cname=selfinfo.cname)
                code_fcall = templ.substitute(name=selfinfo.name, cname=selfinfo.cname, py_args=code_args)
                if v.isphantom:
                    code_fcall = code_fcall.replace("new " + selfinfo.cname, self.cname.replace("::", "_"))
            else:
                code_prelude = ""
                code_fcall = ""
                if v.rettype:
                    code_decl += "    " + v.rettype + " retval;\n"
                    code_fcall += "retval = "
                if not v.isphantom and ismethod and not self.is_static:
                    code_fcall += "_self_->" + self.cname
                else:
                    code_fcall += self.cname
                code_fcall += code_args

            if code_cvt_list:
                code_cvt_list = [""] + code_cvt_list

            # add info about return value, if any, to all_cargs. if there non-void return value,
            # it is encoded in v.py_outlist as ("retval", -1) pair.
            # As [-1] in Python accesses the last element of a list, we automatically handle the return value by
            # adding the necessary info to the end of all_cargs list.
            if v.rettype:
                tp = v.rettype
                tp1 = tp.replace("*", "_ptr")
                default_info = ArgTypeInfo(tp, FormatStrings.object, "0")
                arg_type_info = simple_argtype_mapping.get(tp, default_info)
                all_cargs.append(arg_type_info)

            if v.args and v.py_arglist:
                # form the format spec for PyArg_ParseTupleAndKeywords
                fmtspec = "".join([
                    get_type_format_string(all_cargs[argno][0])
                    for _, argno in v.py_arglist
                ])
                if v.py_noptargs > 0:
                    fmtspec = fmtspec[:-v.py_noptargs] + "|" + fmtspec[-v.py_noptargs:]
                fmtspec += ":" + fullname

                # form the argument parse code that:
                #   - declares the list of keyword parameters
                #   - calls PyArg_ParseTupleAndKeywords
                #   - converts complex arguments from PyObject's to native OpenCV types
                code_parse = gen_template_parse_args.substitute(
                    kw_list=", ".join(['"' + v.args[argno].export_name + '"' for _, argno in v.py_arglist]),
                    fmtspec=fmtspec,
                    parse_arglist=", ".join(["&" + all_cargs[argno][1] for _, argno in v.py_arglist]),
                    code_cvt=" &&\n        ".join(code_cvt_list))
            else:
                code_parse = "if (PyObject_Size(js_args) == 0 && (!kw || PyObject_Size(kw) == 0))"

            if len(v.py_outlist) == 0:
                code_ret = "Py_RETURN_NONE"
            elif len(v.py_outlist) == 1:
                if self.isconstructor:
                    code_ret = "return 0"
                else:
                    aname, argno = v.py_outlist[0]
                    code_ret = "return jsopencv_from(info, %s)" % (aname,)
            else:
                # there is more than 1 return parameter; form the tuple out of them
                fmtspec = "N"*len(v.py_outlist)
                code_ret = "return Js_BuildValue(info, \"(%s)\", %s)" % \
                    (fmtspec, ", ".join(["jsopencv_from(info, " + aname + ")" for aname, argno in v.py_outlist]))

            all_code_variants.append(gen_template_func_body.substitute(code_decl=code_decl,
                code_parse=code_parse, code_prelude=code_prelude, code_fcall=code_fcall, code_ret=code_ret))

        if len(all_code_variants)==1:
            # if the function/method has only 1 signature, then just put it
            code += all_code_variants[0]
        else:
            # try to execute each signature, add an interlude between function
            # calls to collect error from all conversions
            code += '    jsPrepareArgumentConversionErrorsStorage({});\n'.format(len(all_code_variants))
            code += '    \n'.join(gen_template_overloaded_function_call.substitute(variant=v)
                                  for v in all_code_variants)
            code += '    jsRaiseCVOverloadException(info, "{}");\n'.format(self.name)

        def_ret = "info.Env().Null()"
        if self.isconstructor:
            def_ret = "-1"
        code += "\n    return %s;\n}\n\n" % def_ret

        cname = self.cname
        classinfo = None
        #dump = False
        #if dump: pprint(vars(self))
        #if dump: pprint(vars(self.variants[0]))
        if self.classname:
            classinfo = all_classes[self.classname]
            #if dump: pprint(vars(classinfo))
            if self.isconstructor:
                py_name = classinfo.full_export_name
            else:
                py_name = classinfo.full_export_name + "." + self.variants[0].wname

            if not self.is_static:
                cname = classinfo.cname + '::' + cname
        else:
            py_name = '.'.join([self.namespace, self.variants[0].wname])
        #if dump: print(cname + " => " + py_name)
        py_signatures = codegen.py_signatures.setdefault(cname, [])
        for v in self.variants:
            s = dict(name=py_name, arg=v.py_arg_str, ret=v.py_return_str)
            for old in py_signatures:
                if s == old:
                    break
            else:
                py_signatures.append(s)

        return code