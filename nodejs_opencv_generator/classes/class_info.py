from typing import Union, Dict, List, Any, cast, TYPE_CHECKING

if TYPE_CHECKING:
    from .nodejs_wrapper_generator import NodejsWrapperGenerator
    from .func_info import FuncInfo

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
    gen_template_rw_prop_init,
    gen_template_set_prop_algo,
    gen_ts_class_typing
)
if sys.version_info[0] >= 3:
    from io import StringIO
else:
    from cStringIO import StringIO

class ClassInfo(object):
    def __init__(self, name: str, decl: Union[List[Any], None] = None, codegen: Union["NodejsWrapperGenerator", None] = None, decl_idx: int = 0):

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
        self.methods: Dict[str, Union[ClassInfo, "FuncInfo"]] = {}
        self.props: List[ClassProp] = []
        self.mappables: List[str] = []
        self.consts: Dict[str, str] = {}
        self.base:  Union[str, None] = None
        self.constructor:  Union[ClassInfo, "FuncInfo", None] = None
        self.decl_idx: int = decl_idx

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

    def gen_map_code(self, codegen: "NodejsWrapperGenerator"):
        all_classes = codegen.classes
        code = "static bool jsopencv_to(Napi::Value* src, %s& dst, const ArgInfo& info)\n{\n    const Napi::Value* tmp;\n    bool ok;\n" % (self.cname)
        code += "".join([gen_template_set_prop_from_map.substitute(propname=p.name,proptype=p.tp) for p in self.props])
        if self.base:
            code += "\n    return jsopencv_to_safe(src, (%s&)dst, info);\n}\n" % all_classes[self.base].cname
        else:
            code += "\n    return true;\n}\n"
        return code
    
    def gen_ts_typings(self, codegen: "NodejsWrapperGenerator") -> str:
        methods_str = ""

        if self.constructor:
            methods_str +="\n\t" + "\n\t".join(self.constructor.gen_ts_typings(codegen))

        for method_key in self.methods:
            methods_str += "\n\t" + "\n\t".join(sorted(self.methods[method_key].gen_ts_typings(codegen)))

        result = gen_ts_class_typing.substitute(
            indent="",
            export_name=self.export_name,
            methods=methods_str
        )
        return result
    

    def gen_code(self, codegen: "NodejsWrapperGenerator") -> str:
        """
        for all classes
        generate a block like:
        // GetSet (AKAZE)
        // ...
        // Methods (AKAZE)
        // ...
        // Tables (AKAZE)
        // 
        static JsGetSetDef jsopencv_${name}_getseters[] =
        // all setter/getter as an array
        static JsMethodDef jsopencv_${name}_methods[] =
        // all nethode methods as an array
        // saved in jsopencv_generated_types_content.h
        """
        all_classes = codegen.classes
        if self.ismap:
            return self.gen_map_code(codegen)

        getset_code = StringIO()
        getset_inits = StringIO()

        sorted_props = [(p.name, p) for p in self.props]
        sorted_props.sort()

        access_op = "->"
        if self.issimple:
            access_op = "."
        # ALL PROPERTIES
        for pname, p in sorted_props:
            if self.isalgorithm:
                getset_code.write(gen_template_get_prop_algo.substitute(name=self.name, cname=self.cname, member=pname, membertype=p.tp, access=access_op))
            else:
                getset_code.write(gen_template_get_prop.substitute(name=self.name, member=pname, membertype=p.tp, access=access_op))
            if p.readonly:
                getset_inits.write(gen_template_prop_init.substitute(name=self.name, member=pname, export_member_name=p.export_name))
            else:
                if self.isalgorithm:
                    getset_code.write(gen_template_set_prop_algo.substitute(name=self.name, cname=self.cname, member=pname, membertype=p.tp, access=access_op))
                else:
                    getset_code.write(gen_template_set_prop.substitute(name=self.name, member=pname, membertype=p.tp, access=access_op))
                getset_inits.write(gen_template_rw_prop_init.substitute(name=self.name, member=pname, export_member_name=p.export_name))

        methods_code = StringIO()
        methods_inits = StringIO()

        sorted_methods = list(self.methods.items())
        sorted_methods.sort()
        # CONSTRUCTOR
        if self.constructor is not None:
            methods_code.write(self.constructor.gen_code(codegen))
        # methods
        for mname, m in sorted_methods:
            m2: "FuncInfo" = cast("FuncInfo", m)
            methods_code.write(m2.gen_code(codegen))
            methods_inits.write(m2.get_tab_entry())

        code = gen_template_type_impl.substitute(name=self.name,
                                                 getset_code=getset_code.getvalue(),
                                                 getset_inits=getset_inits.getvalue(),
                                                 methods_code=methods_code.getvalue(),
                                                 methods_inits=methods_inits.getvalue())
        return code

    def gen_def(self, codegen: "NodejsWrapperGenerator") -> str:
        all_classes = codegen.classes
        baseptr = "NoBase"
        if self.base and self.base in all_classes:
            baseptr = all_classes[self.base].name

        constructor_name = "0"
        if self.constructor is not None:
            if not isinstance(self.constructor, ClassInfo):
                constructor_name = self.constructor.get_wrapper_name()
        # define CVJS_TYPE(EXPORT_NAME, CLASS_ID, STORAGE, SNAME, _1, _2, SCOPE)
        return 'CVJS_TYPE({}, {}, {}, {}, {}, {}, "{}");\n'.format(
            self.export_name,
            self.class_id,
            self.cname if self.issimple else "cv::Ptr<{}>".format(self.cname),
            self.original_name if self.issimple else "Ptr",
            baseptr,
            constructor_name,
            # Leading dot is required to provide correct class naming
            "." + self.scope_name if len(self.scope_name) > 0 else self.scope_name
        )


