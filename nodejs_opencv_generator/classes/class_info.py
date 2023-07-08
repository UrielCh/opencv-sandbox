from .class_prop import ClassProp 
import sys
import re
from nodejs_opencv_generator.utils import normalize_class_name
from nodejs_opencv_generator.templates import (
    gen_template_type_impl, 
    gen_template_get_prop, 
    gen_template_get_prop_algo,
    gen_template_set_prop,
    gen_template_set_prop_from_map,
    gen_template_prop_init,
    gen_template_set_prop_algo,
    gen_ts_class_typing,
    gen_h_class,
    gen_template_init_static_method,
    gen_template_cpp_init,
    gen_template_init_instance_method,
    gen_template_type_decl,
    gen_cpp_class_file,
    gen_template_mappable,
    gen_template_map_type_cvt,
    gen_template_class_ref_cpp
)
if sys.version_info[0] >= 3:
    from io import StringIO
else:
    from cStringIO import StringIO


class ClassInfo(object):
    def __init__(self, name, decl=None, codegen=None):

        # if name == 'cv.BOWKMeansTrainer':
        #     print('decl', name, decl)

        # Scope name can be a module or other class e.g. cv::SimpleBlobDetector::Params
        scope_name, self.original_name = name.rsplit(".", 1)

        # In case scope refer the outer class exported with different name
        if codegen:
            scope_name = codegen.get_export_scope_name(scope_name)
        self.scope_name = re.sub(r"^cv\.?", "", scope_name)

        self.export_name = self.original_name

        self.class_id = normalize_class_name(name)

        self.cname = name.replace(".", "::")
        self.ismap = False
        self.is_parameters = False
        self.issimple = False
        self.isalgorithm = False
        self.methods = {}
        self.props = []
        self.mappables = []
        self.consts = {}
        self.base = None
        self.constructor = None

        if decl:
            bases = decl[1].split()[1:]
            if len(bases) > 1:
                print("Note: Class %s has more than 1 base class (not supported by Python C extensions)" % (self.cname,))
                print("      Bases: ", " ".join(bases))
                print("      Only the first base class will be used")
                #return sys.exit(-1)
            elif len(bases) == 1:
                self.base = bases[0].strip(",")
                if self.base.startswith("cv::"):
                    self.base = self.base[4:]
                if self.base == "Algorithm":
                    self.isalgorithm = True
                self.base = self.base.replace("::", "_")

            for m in decl[2]:
                if m.startswith("="):
                    # Aliasing only affects the exported class name, not class identifier
                    self.export_name = m[1:]
                elif m == "/Map":
                    self.ismap = True
                elif m == "/Simple":
                    self.issimple = True
                elif m == "/Params":
                    self.is_parameters = True
                    self.issimple = True
            self.props = [ClassProp(p) for p in decl[3]]

        if not self.has_export_alias and self.original_name.startswith("Cv"):
            self.export_name = self.export_name[2:]

    @property
    def wname(self):
        if len(self.scope_name) > 0:
            return self.scope_name.replace(".", "_") + "_" + self.export_name

        return self.export_name

    @property
    def name(self):
        return self.class_id

    @property
    def full_scope_name(self):
        return "cv." + self.scope_name if len(self.scope_name) else "cv"

    @property
    def full_export_name(self):
        return self.full_scope_name + "." + self.export_name

    @property
    def full_original_name(self):
        return self.full_scope_name + "." + self.original_name

    @property
    def has_export_alias(self):
        return self.export_name != self.original_name

    def gen_map_code(self, codegen):
        all_classes = codegen.classes
        code = "static bool jsopencv_to(Napi::Value* src, %s& dst, const ArgInfo& info)\n{\n    const Napi::Value* tmp;\n    bool ok;\n" % (self.cname)
        code += "".join([gen_template_set_prop_from_map.substitute(propname=p.name,proptype=p.tp) for p in self.props])
        if self.base:
            code += "\n    return jsopencv_to_safe(src, (%s&)dst, info);\n}\n" % all_classes[self.base].cname
        else:
            code += "\n    return true;\n}\n"
        return code
    def gen_ts(self, codegen) -> str:
        methods_str = ""

        if self.constructor:
            methods_str +="\n\t" + "\n\t".join(self.constructor.gen_ts(codegen))

        for method_key in self.methods:
            methods_str+="\n\t" + "\n\t".join(sorted(self.methods[method_key].gen_ts(codegen)))

        result = gen_ts_class_typing.substitute(
            indent="",
            export_name=self.export_name,
            methods=methods_str
        )
        return result
    def gen_h(self, codegen) -> str:
        methods_h = StringIO()

        indentation = '    ';
        if self.constructor is not None:
            methods_h.write(indentation+self.constructor.gen_h(codegen)+'\n')
        
        sorted_methods = self.get_sorted_methods()
        for mname, m in sorted_methods:
            methods_h.write(indentation+m.gen_h(codegen)+'\n')
            # methods_inits.write(m.get_tab_entry())
        method_defs = methods_h.getvalue()
        generated = gen_h_class.substitute(
            class_name=self.name,
            inst_name=self.name.lower(),
            method_defs=method_defs
        )
        return generated
    def get_sorted_methods(self):
        sorted_methods = list(self.methods.items())
        sorted_methods.sort()
        return sorted_methods
    def gen_cpp(self, codegen) -> str:
        code_str = self.gen_code_cpp(codegen)
        return gen_cpp_class_file.substitute(
            code=code_str,
            name=self.name
        )
    def gen_code_cpp(self, codegen) -> str:
        all_classes = codegen.classes
        if self.ismap:
            return self.gen_map_code(codegen)

        getset_code = StringIO()


        sorted_props = [(p.name, p) for p in self.props]
        sorted_props.sort()

        access_op = "->"
        if self.issimple:
            access_op = "."
        for pname, p in sorted_props:
            if self.isalgorithm:
                getset_code.write(gen_template_get_prop_algo.substitute(name=self.name, cname=self.cname, member=pname, membertype=p.tp, access=access_op))
            else:
                getset_code.write(gen_template_get_prop.substitute(name=self.name, member=pname, membertype=p.tp, access=access_op))
            if not p.readonly:
                if self.isalgorithm:
                    getset_code.write(gen_template_set_prop_algo.substitute(name=self.name, cname=self.cname, member=pname, membertype=p.tp, access=access_op))
                else:
                    getset_code.write(gen_template_set_prop.substitute(name=self.name, member=pname, membertype=p.tp, access=access_op))

        methods_code = StringIO()
        methods_cstr_code = StringIO()

        sorted_methods = self.get_sorted_methods()

        if self.constructor is not None:
            methods_code.write(self.constructor.gen_cpp(codegen))

        for mname, m in sorted_methods:
            methods_code.write(m.gen_cpp(codegen))
            if m.is_static:
                methods_cstr_code.write("        "+gen_template_init_static_method.substitute(name=self.name, method_name=m.name, binding_name=m.get_binding_name())+"\n")
            else:
                methods_cstr_code.write("        "+gen_template_init_instance_method.substitute(name=self.name, method_name=m.name, binding_name=m.get_binding_name())+"\n")
        
        init_code = gen_template_cpp_init.substitute(
            wrapper_name=self.name,
            class_name=self.name,
            full_name=self.cname.replace('::', '.'),
            methods_cstr_code=methods_cstr_code.getvalue()
        )
        code_types = StringIO()
        if self.ismap:
            code_types.write(gen_template_map_type_cvt.substitute(name=self.name, cname=self.cname))
        else:
            mappable_code = "\n".join([
                                    gen_template_mappable.substitute(cname=self.cname, mappable=mappable)
                                        for mappable in self.mappables])
            code = gen_template_type_decl.substitute(
                name=self.name,
                cname=self.cname if self.issimple else "Ptr<{}>".format(self.cname),
                mappable_code=mappable_code
            )
            code_types.write(code)
        
        class_ref_code = StringIO()

        class_ref_code.write(gen_template_class_ref_cpp.substitute(
            name= self.name,
            cname=self.cname if self.issimple else "Ptr<{}>".format(self.cname)
        ))

        code = gen_template_type_impl.substitute(name=self.name,
                                                 getset_code=getset_code.getvalue(),
                                                 methods_code=methods_code.getvalue(),
                                                 init_code=init_code,
                                                 code_types=code_types.getvalue(),
                                                 class_ref_code=class_ref_code.getvalue())

        return code
