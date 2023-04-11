#ifndef __JS_AS_PY_HPP__
#define __JS_AS_PY_HPP__

#include <napi.h>

// 
// convert from PythonC code base
//

bool JsArg_ParseTupleAndKeywords(const Napi::CallbackInfo &info, const char *format, char **keywords, ...);

// typedef struct _object PyObject;

#define JsObject                        Napi::Value
// #define PyObject_HEAD                PyObject ob_base;
#define JsObject_HEAD                   JsObject ob_base;


#endif