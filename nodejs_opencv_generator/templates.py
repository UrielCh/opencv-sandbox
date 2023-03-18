from string import Template


gen_template_check_self = Template("""
    ${cname} * self1 = 0;
    if (!pyopencv_${name}_getp(self, self1))
        return failmsgp("Incorrect type of self (must be '${name}' or its derivative)");
    ${pname} _self_ = ${cvt}(self1);
""")
gen_template_call_constructor_prelude = Template("""new (&(self->v)) Ptr<$cname>(); // init Ptr with placement new
        if(self) """)

gen_template_call_constructor = Template("""self->v.reset(new ${cname}${py_args})""")

gen_template_simple_call_constructor_prelude = Template("""if(self) """)

gen_template_simple_call_constructor = Template("""new (&(self->v)) ${cname}${py_args}""")

gen_template_parse_args = Template("""const char* keywords[] = { $kw_list, NULL };
    if (JsArg_ParseTupleAndKeywords(py_args, kw, "$fmtspec", (char**)keywords, $parse_arglist)$code_cvt)""")

gen_template_func_body = Template("""$code_decl
    $code_parse
    {
        ${code_prelude}ERRWRAP2($code_fcall);
        $code_ret;
    }
""")

gen_template_mappable = Template("""
    {
        ${mappable} _src;
        if (pyopencv_to_safe(src, _src, info))
        {
            return cv_mappable_to(_src, dst);
        }
    }
""")

gen_template_type_decl = Template("""
// Converter (${name})

template<>
struct PyOpenCV_Converter< ${cname} >
{
    static PyObject* from(const ${cname}& r)
    {
        return pyopencv_${name}_Instance(r);
    }
    static bool to(PyObject* src, ${cname}& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        ${cname} * dst_;
        if (pyopencv_${name}_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        ${mappable_code}
        failmsg("Expected ${cname} for argument '%s'", info.name);
        return false;
    }
};

""")

gen_template_map_type_cvt = Template("""
template<> bool pyopencv_to(PyObject* src, ${cname}& dst, const ArgInfo& info);

""")

gen_template_set_prop_from_map = Template("""
    if( PyMapping_HasKeyString(src, (char*)"$propname") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"$propname");
        ok = tmp && pyopencv_to_safe(tmp, dst.$propname, ArgInfo("$propname", false));
        Py_DECREF(tmp);
        if(!ok) return false;
    }""")

gen_template_type_impl = Template("""
// GetSet (${name})

${getset_code}

// Methods (${name})

${methods_code}

// Tables (${name})

static PyGetSetDef pyopencv_${name}_getseters[] =
{${getset_inits}
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_${name}_methods[] =
{
${methods_inits}
    {NULL,          NULL}
};
""")


gen_template_get_prop = Template("""
static PyObject* pyopencv_${name}_get_${member}(pyopencv_${name}_t* p, void *closure)
{
    return jsopencv_from(p->v${access}${member});
}
""")

gen_template_get_prop_algo = Template("""
static PyObject* pyopencv_${name}_get_${member}(pyopencv_${name}_t* p, void *closure)
{
    $cname* _self_ = dynamic_cast<$cname*>(p->v.get());
    if (!_self_)
        return failmsgp("Incorrect type of object (must be '${name}' or its derivative)");
    return jsopencv_from(_self_${access}${member});
}
""")

gen_template_set_prop = Template("""
static int pyopencv_${name}_set_${member}(pyopencv_${name}_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the ${member} attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v${access}${member}, ArgInfo("value", false)) ? 0 : -1;
}
""")

gen_template_set_prop_algo = Template("""
static int pyopencv_${name}_set_${member}(pyopencv_${name}_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the ${member} attribute");
        return -1;
    }
    $cname* _self_ = dynamic_cast<$cname*>(p->v.get());
    if (!_self_)
    {
        failmsgp("Incorrect type of object (must be '${name}' or its derivative)");
        return -1;
    }
    return pyopencv_to_safe(value, _self_${access}${member}, ArgInfo("value", false)) ? 0 : -1;
}
""")


gen_template_prop_init = Template("""
    {(char*)"${export_member_name}", (getter)pyopencv_${name}_get_${member}, NULL, (char*)"${export_member_name}", NULL},""")

gen_template_rw_prop_init = Template("""
    {(char*)"${export_member_name}", (getter)pyopencv_${name}_get_${member}, (setter)pyopencv_${name}_set_${member}, (char*)"${export_member_name}", NULL},""")

gen_template_overloaded_function_call = Template("""
    {
${variant}

        pyPopulateArgumentConversionErrors();
    }
""")