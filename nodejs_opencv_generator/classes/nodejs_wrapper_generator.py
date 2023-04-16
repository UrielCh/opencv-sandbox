import sys
import re
from typing import Dict, Any, List, Tuple, Union
from nodejs_opencv_generator import hdr_parser
from nodejs_opencv_generator.utils import normalize_class_name
from nodejs_opencv_generator.classes.namespace import Namespace
from .func_info import FuncInfo 
from .class_info import ClassInfo
from nodejs_opencv_generator.templates import (
    gen_template_type_decl,
    gen_template_map_type_cvt,
    gen_template_mappable,
    gen_ts_class_typing
)

if sys.version_info[0] >= 3:
    from io import StringIO
else:
    from cStringIO import StringIO

class NodejsWrapperGenerator(object):
    def __init__(self):
        self.clear()

    def clear(self) -> None:
        self.classes: Dict[str, ClassInfo] = {}
        self.namespaces: Dict[str, Namespace] = {}
        self.consts: Dict[str, Any] = {}
        self.enums: Dict[str, Any] = {}
        self.code_include: StringIO = StringIO()      # jsopencv_generated_include.h

        self.code_enums: StringIO = StringIO()        # jsopencv_generated_enums.h
        self.code_enums.write("#ifndef __JSOPENCV_GENERATED_ENUMS_H__\n")
        self.code_enums.write("#define __JSOPENCV_GENERATED_ENUMS_H__\n")
        self.code_enums.write("#include <napi.h>\n")
        self.code_enums.write('#include "../cc-common/js_as_py.h"\n')
        self.code_enums.write('#include "../cc-common/cv2_convert.h"\n')
        self.code_enums.write('#include "../cc-common/jscompat.hpp"\n')
        # self.code_enums.write('#include <opencv2/opencv.hpp>\n')
        self.code_enums.write('#include "./jsopencv_generated_include.h"\n')

        self.code_enums.write("\n")
        self.code_enums.write("using namespace cv;\n")
        self.code_enums.write("\n")

        self.code_funcs: StringIO = StringIO()        # jsopencv_generated_funcs.h
        self.code_funcs.write("#ifndef __JSOPENCV_GENERATED_FUNCS_H__\n")
        self.code_funcs.write("#define __JSOPENCV_GENERATED_FUNCS_H__\n")
        self.code_funcs.write("#include <napi.h>\n")
        self.code_funcs.write("#include <opencv2/opencv.hpp>\n")
        self.code_funcs.write('#include "../cc-common/js_as_py.h"\n')
        self.code_funcs.write('#include "../cc-common/cv2_convert.h"\n')
        self.code_funcs.write('#include "./jsopencv_generated_enums.h"\n')
        self.code_funcs.write('#include "../cc-common/cv2_macro.hpp"\n')
        self.code_funcs.write("\n")
        self.code_funcs.write("using namespace cv;\n")
        self.code_funcs.write("\n")

        self.code_ns_reg: StringIO = StringIO()       # jsopencv_generated_modules_content.h
        self.code_ns_reg.write("#ifndef __JSOPENCV_GENERATED_MODULES_CONTENT_H__\n")
        self.code_ns_reg.write("#define __JSOPENCV_GENERATED_MODULES_CONTENT_H__\n")
        self.code_ns_reg.write("#include <napi.h>\n")
        self.code_ns_reg.write('#include "../cc-common/jscompat.hpp"\n')
        self.code_ns_reg.write('#include "./jsopencv_generated_funcs.h"\n')
        self.code_ns_reg.write("\n")

        self.code_ns_init: StringIO = StringIO()      # jsopencv_generated_modules.h
        self.code_ns_init.write("// This code will be import within the function:\n")
        self.code_ns_init.write("// init_body(Napi::Env env, Napi::Object exports) function in cv2.cpp\n")
        self.code_ns_init.write("// an Napi::Env env, and a Napi::Object exports will be provided\n")
        self.code_ns_init.write("// CVJS_MODULE macro will invoque init_submodule\n")
        self.code_ns_init.write("\n")

        self.code_types: StringIO = StringIO()        # jsopencv_generated_types_content.h
        self.code_types.write("#ifndef __JSOPENCV_GENERATED_TYPES_CONTENT_H__\n")
        self.code_types.write("#define __JSOPENCV_GENERATED_TYPES_CONTENT_H__\n")
        self.code_types.write("#include <napi.h>\n")
        self.code_types.write('#include "../cc-common/js_as_py.h"\n')
        self.code_types.write('#include "../cc-common/cv2_convert.h"\n')
        # self.code_types.write('// #include "../cc-common/cv2.hpp"\n') // can not include cv2
        self.code_types.write('#include "../cc-common/cv2_util.h"\n')
        # self.code_types.write('#include "./jsopencv_generated_include.h"\n')
        self.code_types.write('#include "./jsopencv_generated_enums.h"\n')
        self.code_types.write('#include "./jsopencv_generated_types.h"\n')

        self.code_types.write("\n")

        self.code_type_publish: StringIO = StringIO() # jsopencv_generated_types.h
        self.code_type_publish.write("#ifndef __JSOPENCV_GENERATED_TYPES_H__\n")
        self.code_type_publish.write("#define __JSOPENCV_GENERATED_TYPES_H__\n")
        self.code_type_publish.write('#include "../cc-common/cv2_macro.hpp"\n')
        self.code_type_publish.write('#include "../cc-common/js_as_py.h"\n')
        self.code_type_publish.write('#include "./jsopencv_generated_include.h"\n')

        #include "opencv2/opencv_modules.hpp"
        #include "opencv2/core.hpp"
        #include "opencv2/opencv.hpp"
        #include "opencv2/core/utils/logger.hpp"

        self.code_type_publish.write("\n")
        
        self.code_ts_types: StringIO = StringIO() # cv.d.ts
        self.code_ts_types.write("declare namespace cv {\n")
        self.py_signatures: Dict[str, List[Dict[str, Any]]] = dict()         # jsopencv_signatures.json

        self.class_idx: int = 0


    def add_class(self, stype: str, name: str, decl: List[str]) -> None:
        classinfo = ClassInfo(name, decl, self)
        classinfo.decl_idx = self.class_idx
        self.class_idx += 1

        if classinfo.name in self.classes:
            print("Generator error: class %s (cname=%s) already exists" \
                % (classinfo.name, classinfo.cname))
            sys.exit(-1)
        self.classes[classinfo.name] = classinfo

        namespace, _, _ = self.split_decl_name(name)
        namespace = '.'.join(namespace)
        # Registering a namespace if it is not already handled or
        # doesn't have anything except classes defined in it
        self.namespaces.setdefault(namespace, Namespace())

        # Add Class to json file.
        py_name = classinfo.full_export_name  # use wrapper name
        py_signatures = self.py_signatures.setdefault(classinfo.cname, [])
        py_signatures.append(dict(name=py_name))
        
        
        # print(classinfo.cname, dict(name=py_name))
        #print('class: ' + classinfo.cname + " => " + py_name)

    def get_export_scope_name(self, original_scope_name: str) -> str:
        # Outer classes should be registered before their content - inner classes in this case
        class_scope = self.classes.get(normalize_class_name(original_scope_name), None)

        if class_scope:
            return class_scope.full_export_name

        # Otherwise it is a namespace.
        # If something is messed up at this point - it will be revelead during
        # library import
        return original_scope_name

    def split_decl_name(self, name: str) -> Tuple[List[str], List[str], str]:
        chunks = name.split('.')
        namespace = chunks[:-1]
        classes = []
        while namespace and '.'.join(namespace) not in self.parser.namespaces:
            classes.insert(0, namespace.pop())
        return namespace, classes, chunks[-1]


    def add_const(self, name: str, decl: List[Any]) -> None:
        cname = name.replace('.','::')
        namespace, classes, name = self.split_decl_name(name)
        namespace = '.'.join(namespace)
        name = '_'.join(classes+[name])
        ns = self.namespaces.setdefault(namespace, Namespace())
        if name in ns.consts:
            print("Generator error: constant %s (cname=%s) already exists" \
                % (name, cname))
            sys.exit(-1)
        ns.consts[name] = cname

        value = decl[1]
        py_name = '.'.join([namespace, name])
        py_signatures = self.py_signatures.setdefault(cname, [])
        py_signatures.append(dict(name=py_name, value=value))
        #print(cname + ' => ' + str(py_name) + ' (value=' + value + ')')

    def add_enum(self, name: str, decl: List[Any]) -> None:
        wname = normalize_class_name(name)
        if wname.endswith("<unnamed>"):
            wname = None
        else:
            self.enums[wname] = name
        const_decls = decl[3]

        for decl in const_decls:
            name = decl[0]
            self.add_const(name.replace("const ", "").strip(), decl)

    def add_func(self, decl: List[Any]) -> None:
        namespace, classes, barename = self.split_decl_name(decl[0])
        cname = "::".join(namespace+classes+[barename])
        name = barename
        classname = ''
        bareclassname = ''
        if classes:
            classname = normalize_class_name('.'.join(namespace+classes))
            bareclassname = classes[-1]
        namespace_str = '.'.join(namespace)

        isconstructor = name == bareclassname
        is_static = False
        isphantom = False
        mappable = None
        for m in decl[2]:
            if m == "/S":
                is_static = True
            elif m == "/phantom":
                isphantom = True
                cname = cname.replace("::", "_")
            elif m.startswith("="):
                name = m[1:]
            elif m.startswith("/mappable="):
                mappable = m[10:]
                self.classes[classname].mappables.append(mappable)
                return

        if isconstructor:
            name = "_".join(classes[:-1]+[name])

        if is_static:
            # Add it as a method to the class
            func_map = self.classes[classname].methods
            func = func_map.setdefault(name, FuncInfo(classname, name, cname, isconstructor, namespace_str, is_static))
            func.add_variant(decl, self.classes, isphantom)

            # Add it as global function
            g_name = "_".join(classes+[name])
            w_classes = []
            for i in range(0, len(classes)):
                classes_i = classes[:i+1]
                classname_i = normalize_class_name('.'.join(namespace+classes_i))
                w_classname = self.classes[classname_i].wname
                namespace_prefix = normalize_class_name('.'.join(namespace)) + '_'
                if w_classname.startswith(namespace_prefix):
                    w_classname = w_classname[len(namespace_prefix):]
                w_classes.append(w_classname)
            g_wname = "_".join(w_classes+[name])
            func_map = self.namespaces.setdefault(namespace_str, Namespace()).funcs
            # Exports static function with internal name (backward compatibility)
            func = func_map.setdefault(g_name, FuncInfo("", g_name, cname, isconstructor, namespace_str, False))
            func.add_variant(decl, self.classes, isphantom)
            if g_wname != g_name:  # TODO OpenCV 5.0
                wfunc = func_map.setdefault(g_wname, FuncInfo("", g_wname, cname, isconstructor, namespace_str, False))
                wfunc.add_variant(decl, self.classes, isphantom)
        else:
            if classname and not isconstructor:
                if not isphantom:
                    cname = barename
                func_map = self.classes[classname].methods
            else:
                func_map = self.namespaces.setdefault(namespace_str, Namespace()).funcs

            func = func_map.setdefault(name, FuncInfo(classname, name, cname, isconstructor, namespace_str, is_static))
            func.add_variant(decl, self.classes, isphantom)

        if classname and isconstructor:
            self.classes[classname].constructor = func


    def gen_namespace(self, ns_name: str) -> None:
        ns = self.namespaces[ns_name]
        wname = normalize_class_name(ns_name)

        self.code_ns_reg.write('static JsMethodDef methods_%s[] = {\n'%wname)
        for name, func in sorted(ns.funcs.items()):
            if func.isconstructor:
                continue
            self.code_ns_reg.write(func.get_tab_entry())
        custom_entries_macro = 'JSOPENCV_EXTRA_METHODS_{}'.format(wname.upper())
        self.code_ns_reg.write('#ifdef {}\n    {}\n#endif\n'.format(custom_entries_macro, custom_entries_macro))
        self.code_ns_reg.write('    {NULL, NULL}\n};\n\n')

        self.code_ns_reg.write('static ConstDef consts_%s[] = {\n'%wname)
        for name, cname in sorted(ns.consts.items()):
            self.code_ns_reg.write('    {"%s", static_cast<long>(%s)},\n'%(name, cname))
            compat_name = re.sub(r"([a-z])([A-Z])", r"\1_\2", name).upper()
            if name != compat_name:
                self.code_ns_reg.write('    {"%s", static_cast<long>(%s)},\n'%(compat_name, cname))
        custom_entries_macro = 'JSOPENCV_EXTRA_CONSTANTS_{}'.format(wname.upper())
        self.code_ns_reg.write('#ifdef {}\n    {}\n#endif\n'.format(custom_entries_macro, custom_entries_macro))
        self.code_ns_reg.write('    {NULL, 0}\n};\n\n')

    def gen_enum_reg(self, enum_name: str) -> None:
        name_seg = enum_name.split(".")
        is_enum_class = False
        if len(name_seg) >= 2 and name_seg[-1] == name_seg[-2]:
            enum_name = ".".join(name_seg[:-1])
            is_enum_class = True

        wname = normalize_class_name(enum_name)
        cname = enum_name.replace(".", "::")

        code = ""
        if re.sub(r"^cv\.", "", enum_name) != wname:
            code += "typedef {0} {1};\n".format(cname, wname)
        code += "CV_JS_FROM_ENUM({0});\nCV_JS_TO_ENUM({0});\n\n".format(wname)
        self.code_enums.write(code)

    def save(self, path: str, name: str, buf: StringIO) -> None:
        with open(path + "/" + name, "wt") as f:
            f.write(buf.getvalue())

    def save_json(self, path: str, name: str, value: Union[Dict, List]) -> None:
        import json
        with open(path + "/" + name, "wt") as f:
            json.dump(value, f)

    def gen(self, srcfiles: List[str], output_path: str) -> None:
        self.clear()
        self.parser = hdr_parser.CppHeaderParser(generate_umat_decls=True, generate_gpumat_decls=True)

        # step 1: scan the headers and build more descriptive maps of classes, consts, functions
        for hdr in srcfiles:
            decls = self.parser.parse(hdr)
            if len(decls) == 0:
                continue

            if hdr.find('misc/python/shadow_') < 0:  # Avoid including the "shadow_" files
                if hdr.find('opencv2/') >= 0:
                    # put relative path
                    self.code_include.write('#include "{0}"\n'.format(hdr[hdr.rindex('opencv2/'):]))
                else:
                    self.code_include.write('#include "{0}"\n'.format(hdr))

            for decl in decls:
                name = decl[0]
                if name.startswith("struct") or name.startswith("class"):
                    # class/struct
                    p = name.find(" ")
                    stype = name[:p]
                    name = name[p+1:].strip()
                    self.add_class(stype, name, decl)
                elif name.startswith("const"):
                    # constant
                    self.add_const(name.replace("const ", "").strip(), decl)
                elif name.startswith("enum"):
                    # enum
                    self.add_enum(name.rsplit(" ", 1)[1], decl)
                else:
                    # function
                    self.add_func(decl)

        # step 1.5 check if all base classes exist
        for name, classinfo in self.classes.items():
            if classinfo.base:
                chunks = classinfo.base.split('_')
                base = '_'.join(chunks)
                while base not in self.classes and len(chunks)>1:
                    del chunks[-2]
                    base = '_'.join(chunks)
                if base not in self.classes:
                    print("Generator error: unable to resolve base %s for %s"
                        % (classinfo.base, classinfo.name))
                    sys.exit(-1)
                base_instance = self.classes[base]
                classinfo.base = base
                classinfo.isalgorithm |= base_instance.isalgorithm  # wrong processing of 'isalgorithm' flag:
                                                                    # doesn't work for trees(graphs) with depth > 2
                self.classes[name] = classinfo

        # tree-based propagation of 'isalgorithm'
        processed = dict()
        def process_isalgorithm(classinfo):
            if classinfo.isalgorithm or classinfo in processed:
                return classinfo.isalgorithm
            res = False
            if classinfo.base:
                res = process_isalgorithm(self.classes[classinfo.base])
                #assert not (res == True or classinfo.isalgorithm is False), "Internal error: " + classinfo.name + " => " + classinfo.base
                classinfo.isalgorithm |= res
                res = classinfo.isalgorithm
            processed[classinfo] = True
            return res
        for name, classinfo in self.classes.items():
            process_isalgorithm(classinfo)

        # step 2: generate code for the classes and their methods
        classlist = list(self.classes.items())
        classlist.sort()
        
        current_tree = []
        code_ts_types_str = ""
        
        for name, classinfo in classlist:
            self.code_types.write("//{}\n".format(80*"="))
            self.code_types.write("// {} ({})\n".format(name, 'Map' if classinfo.ismap else 'Generic'))
            self.code_types.write("//{}\n".format(80*"="))
            self.code_types.write(classinfo.gen_code(self))
            if classinfo.ismap:
                self.code_types.write(gen_template_map_type_cvt.substitute(name=classinfo.name, cname=classinfo.cname))
            else:
                mappable_code = "\n".join([
                                      gen_template_mappable.substitute(cname=classinfo.cname, mappable=mappable)
                                          for mappable in classinfo.mappables])
                code = gen_template_type_decl.substitute(
                    name=classinfo.name,
                    cname=classinfo.cname if classinfo.issimple else "Ptr<{}>".format(classinfo.cname),
                    mappable_code=mappable_code
                )
                self.code_types.write(code)
            
            # Write typescript code
            if(classinfo.scope_name == ""):
                tree_scopes = []
                if(len(current_tree) > 0):
                    to_close = len(current_tree)
                    for closing_level in range(0,to_close):
                        code_ts_types_str+= "{}}}\n".format(((to_close-closing_level))*"\t")
                    current_tree = []
            else:
                tree_scopes = classinfo.scope_name.split(".")
            
            level = 0
            
            for scope in tree_scopes:
                
                if(len(current_tree) <= level or current_tree[level] != scope):
                    to_close = len(current_tree[level:])
                    for closing_level in range(0,to_close):
                        code_ts_types_str+= "{}}}\n".format((level+(to_close-closing_level))*"\t")
                    code_ts_types_str+= "{}namespace {} {{\n".format((level+1)*"\t", scope)
                    current_tree[level:] = [scope]

                level+=1
            
            code_ts_types_str+=gen_ts_class_typing.substitute(
                indent=(len(current_tree)+1)*"\t",
                export_name=classinfo.export_name,
                prop=", ".join([prop.name+":"+prop.tp for prop in classinfo.props])
            )
        
        to_close = len(current_tree)
        for closing_level in range(0,to_close):
            code_ts_types_str+= "{}}}\n".format(((to_close-closing_level))*"\t")
        self.code_ts_types.write(code_ts_types_str)

        # register classes in the same order as they have been declared.
        # this way, base classes will be registered in Python before their derivatives.
        classlist1 = [(classinfo.decl_idx, name, classinfo) for name, classinfo in classlist]
        classlist1.sort()

        published_types = set()  # ensure toposort with base classes
        for decl_idx, name, classinfo in classlist1:
            if classinfo.ismap:
                continue
            def _registerType(classinfo):
                if classinfo.decl_idx in published_types:
                    #print(classinfo.decl_idx, classinfo.name, ' - already published')
                    return
                published_types.add(classinfo.decl_idx)

                if classinfo.base and classinfo.base in self.classes:
                    base_classinfo = self.classes[classinfo.base]
                    #print(classinfo.decl_idx, classinfo.name, ' - request publishing of base type ', base_classinfo.decl_idx, base_classinfo.name)
                    _registerType(base_classinfo)

                #print(classinfo.decl_idx, classinfo.name, ' - published!')
                self.code_type_publish.write(classinfo.gen_def(self))

            _registerType(classinfo)


        # step 3: generate the code for all the global functions
        for ns_name, ns in sorted(self.namespaces.items()):
            if ns_name.split('.')[0] != 'cv':
                continue
            for name, func in sorted(ns.funcs.items()):
                if func.isconstructor:
                    continue
                code = func.gen_code(self)
                self.code_funcs.write(code)
            self.gen_namespace(ns_name)
            self.code_ns_init.write('CVJS_MODULE("{}", {});\n'.format(ns_name[2:], normalize_class_name(ns_name)))

        # step 4: generate the code for enum types
        enumlist = list(self.enums.values())
        enumlist.sort()
        for name in enumlist:
            self.gen_enum_reg(name)

        # step 5: generate the code for constants
        constlist = list(self.consts.items())
        constlist.sort()
        for name, constinfo in constlist:
            self.gen_const_reg(constinfo)

        self.code_funcs.write("#endif\n")
        self.code_enums.write("#endif\n")
        # self.code_ns_init.write("#endif\n")
        self.code_types.write("#endif\n")
        self.code_ns_reg.write("#endif\n")
        self.code_type_publish.write("#endif\n")
        
        self.code_ts_types.write("}\n")

        # That's it. Now save all the files
        self.save(output_path, "jsopencv_generated_include.h", self.code_include)
        self.save(output_path, "jsopencv_generated_funcs.h", self.code_funcs)
        self.save(output_path, "jsopencv_generated_enums.h", self.code_enums)
        self.save(output_path, "jsopencv_generated_types.h", self.code_type_publish)
        self.save(output_path, "jsopencv_generated_types_content.h", self.code_types)
        self.save(output_path, "jsopencv_generated_modules.h", self.code_ns_init)
        self.save(output_path, "jsopencv_generated_modules_content.h", self.code_ns_reg)
        self.save(output_path, "cv.d.ts", self.code_ts_types)
        self.save_json(output_path, "jsopencv_signatures.json", self.py_signatures)
