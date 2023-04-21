from string import Template


gen_template_check_self = Template("""
    ${cname} * self1 = 0;
    if (!jsopencv_${name}_getp(&(info.This()), self1))
        return jsfailmsgp(env, "Incorrect type of self (must be '${name}' or its derivative)");
    ${pname} _self_ = ${cvt}(self1);
""")
# placement new
gen_template_call_constructor_prelude = Template("""Napi::Object *self = &info.This().As<Napi::Object>();
        Ptr<$cname> *data = (Ptr<$cname> *)self->Get("v").As<Napi::Buffer<char>>().Data();
        new (data) Ptr<$cname>(); // init Ptr with placement new
        if(data) """)

gen_template_call_constructor = Template("""data->reset(new ${cname}${py_args})""")

gen_template_simple_call_constructor_prelude = Template("""
 auto self = getInternalData<${cname}>(info.This());
 if (self) """)

# placement new
gen_template_simple_call_constructor = Template("""
new (getInternalData<void>(info.This())) ${cname}${py_args}""")

gen_template_parse_args = Template("""const char* keywords[] = { $kw_list, NULL };
    if (JsArg_ParseTupleAndKeywords(info, "$fmtspec", (char**)keywords, $parse_arglist)$code_cvt)""")

gen_template_func_body = Template("""$code_decl
    $code_parse
    {
        ${code_prelude}ERRWRAP2_NAPI(env, $code_fcall);
        $code_ret;
    }
""")

gen_template_func_body_int = Template("""$code_decl
    $code_parse
    {
        ${code_prelude}ERRWRAP2_NAPI_INT(env, $code_fcall);
        $code_ret;
    }
""")

gen_template_mappable = Template("""
    {
        ${mappable} _src;
        if (jsopencv_to_safe(src, _src, info))
        {
            return cv_mappable_to(_src, dst);
        }
    }
""")

gen_template_type_decl = Template("""
// Converter (${name})

template<>
struct JsOpenCV_Converter< ${cname} >
{
    static Napi::Value from(const Napi::Env &env, const ${cname}& r)
    {
        return jsopencv_${name}_Instance(env, r);
    }
    static bool to(Napi::Value* src, ${cname}& dst, const ArgInfo& info)
    {
        if(!src || src->IsNull() || src->IsUndefined())
            return true;
        ${cname} * dst_;
        if (jsopencv_${name}_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        ${mappable_code}
        jsfailmsg(src->Env(), "Expected ${cname} for argument '%s'", info.name);
        return false;
    }
};

""")

gen_template_map_type_cvt = Template("""
template<> bool jsopencv_to(const Napi::Value* src, ${cname}& dst, const ArgInfo& argInfo);

""")

gen_template_set_prop_from_map = Template("""
    if( JsMapping_HasKeyString(src, (char*)"$propname") )
    {
        tmp = JsMapping_GetItemString(src, (char*)"$propname");
        ok = tmp && jsopencv_to_safe(tmp, dst.$propname, ArgInfo("$propname", false));
        Js_DECREF(tmp);
        if(!ok) return false;
    }""")

gen_template_type_impl = Template("""
// GetSet (${name})

${getset_code}

// Methods (${name})

${methods_code}

// Tables (${name})

static JsGetSetDef jsopencv_${name}_getseters[] =
{${getset_inits}
    {NULL}  /* Sentinel */
};

static JsMethodDef jsopencv_${name}_methods[] =
{
${methods_inits}
    {NULL,          NULL}
};
""")


gen_template_get_prop = Template("""
static Napi::Value jsopencv_${name}_get_${member}(const Napi::Env &env, jsopencv_${name}_t* p, void *closure)
{
    return jsopencv_from(env, p->v${access}${member});
}
""")

gen_template_get_prop_algo = Template("""
static Napi::Value jsopencv_${name}_get_${member}const Napi::Env &env, (jsopencv_${name}_t* p, void *closure)
{
    $cname* _self_ = dynamic_cast<$cname*>(p->v.get());
    if (!_self_)
        return jsfailmsgp(info.Env(), "Incorrect type of object (must be '${name}' or its derivative)");
    return jsopencv_from(env, _self_${access}${member});
}
""")

gen_template_set_prop = Template("""
static int jsopencv_${name}_set_${member}(const Napi::Env &env, jsopencv_${name}_t* p, Napi::Value *value, void *closure)
{
    if (!value)
    {
        JsErr_SetString(env, "Cannot delete the ${member} attribute");
        return -1;
    }
    return jsopencv_to_safe(value, p->v${access}${member}, ArgInfo("value", false)) ? 0 : -1;
}
""")

gen_template_set_prop_algo = Template("""
static int jsopencv_${name}_set_${member}(const Napi::Env &env, jsopencv_${name}_t* p, Napi::Value *value, void *closure)
{
    if (!value)
    {
        JsErr_SetString(env, "Cannot delete the ${member} attribute");
        return -1;
    }
    $cname* _self_ = dynamic_cast<$cname*>(p->v.get());
    if (!_self_)
    {
        jsfailmsgp(env, "Incorrect type of object (must be '${name}' or its derivative)");
        return -1;
    }
    return jsopencv_to_safe(value, _self_${access}${member}, ArgInfo("value", false)) ? 0 : -1;
}
""")


gen_template_prop_init = Template("""
    {(char*)"${export_member_name}", (getter)jsopencv_${name}_get_${member}, NULL, (char*)"${export_member_name}", NULL},""")

gen_template_rw_prop_init = Template("""
    {(char*)"${export_member_name}", (getter)jsopencv_${name}_get_${member}, (setter)jsopencv_${name}_set_${member}, (char*)"${export_member_name}", NULL},""")

gen_template_overloaded_function_call = Template("""
    {
${variant}

        jsPopulateArgumentConversionErrors(info);
    }
""")

gen_ts_prop_typing = Template("""
${indent}class ${export_name}{
""")

gen_ts_class_typing = Template("""
${indent}class ${export_name}{
${indent}\tconstructor(${prop});
${indent}\t${methods}
${indent}}
""")

gen_ts_class_method = Template("""${static}${name}(${args}): ${return_type};""")