#ifndef __JS_AS_PY_HPP__
#define __JS_AS_PY_HPP__

#include <napi.h>

// 
// convert from PythonC code base
//

// PyCFunction(PyObject *self, PyObject *args);
typedef Napi::Value (*JsCFunction)(const Napi::CallbackInfo &info);
// PyCFunctionWithKeywords(PyObject *self, PyObject *args, PyObject *kwargs);
typedef Napi::Value (*JsCFunctionWithKeywords)(const Napi::CallbackInfo &info);

#define Js_RETURN_NONE return info.Env().Null()

void JsErr_SetString(const Napi::Env &env, const std::string &message)
{
    Napi::Error::New(env, message).ThrowAsJavaScriptException();
}

Napi::Value Js_BuildValue(const Napi::CallbackInfo &info, const char *format, ...);

struct JsMethodDef {
    const char  *ml_name;   /* The name of the built-in function/method */
    JsCFunction ml_meth;    /* The C function that implements it */
    // using JsCFunction = Napi::Value (*)(const Napi::CallbackInfo &info);   /* The C function that implements it */
    int         ml_flags;   /* Combination of METH_xxx flags, which mostly
                               describe the args expected by the C func */
    const char  *ml_doc;    /* The __doc__ attribute, or NULL */
};

bool JsArg_ParseTupleAndKeywords(const Napi::CallbackInfo &info, const char *format, char **keywords, ...);

#endif