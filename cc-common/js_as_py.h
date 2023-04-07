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

void JsErr_SetString(const Napi::Env &env, const std::string &message);

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

// typedef struct _object PyObject;

#define JsObject                        Napi::Value
// #define PyObject_HEAD                PyObject ob_base;
#define JsObject_HEAD                   JsObject ob_base;
// 
// If this structure is modified, Doc/includes/typestruct.h should be updated
// as well.
// struct _typeobject {
#define JsTypeObject                    Napi::Value

#define JsObject     Napi::Value

static inline JsTypeObject* Js_TYPE(Napi::Value *value) {
  if (!value->IsObject()) {
    return nullptr;
  }

  Napi::Object object = value->As<Napi::Object>();
  Napi::Value prototype_val = object.Get(Napi::String::New(object.Env(), "__proto__"));

  if (!prototype_val.IsObject()) {
    return nullptr;
  }

  Napi::Object prototype = prototype_val.As<Napi::Object>();
  return &prototype;
}

static inline int Js_IS_TYPE(Napi::Value *ob, JsTypeObject *type) {
    return Js_TYPE(ob) == type;
}
// static inline int PyObject_TypeCheck(PyObject *ob, PyTypeObject *type) {
//     return Py_IS_TYPE(ob, type) || PyType_IsSubtype(Py_TYPE(ob), type);
// }
static inline int JsObject_TypeCheck(Napi::Value *ob, JsTypeObject *type) {
    return Js_IS_TYPE(ob, type);//  || PyType_IsSubtype(Py_TYPE(ob), type);
}

// naive version:
// static inline Napi::String JsString_FromString(const Napi::Env& env, const char* str) {
//     return Napi::String::New(env, str);
// }

// use std::shared_ptr
// static inline std::shared_ptr<Napi::String> JsString_FromString(const Napi::Env& env, const char* str) {
//     if (str == nullptr) {
//         throw std::invalid_argument("Input string is null");
//     }
// 
//     // Create a new Napi::String and wrap it with a shared_ptr
//     auto result = std::make_shared<Napi::String>(Napi::String::New(env, str));
//     return result;
// }

static Napi::Value* JsString_FromString(const Napi::Env& env, const char* str) {
    if (str == nullptr) {
        throw std::invalid_argument("Input string is null");
    }

    // Create a new Napi::String and allocate it on the heap
    Napi::Value* result = new Napi::String(Napi::String::New(env, str));
    return result;
}

// PyObject *PyCFunction_NewEx(PyMethodDef *ml, PyObject *self, PyObject *module)
static Napi::Value * JsCFunction_NewEx(JsMethodDef *ml, Napi::Value *self, Napi::Object *module);

// const char * PyModule_GetName(PyObject *m)
static const std::string JsModule_GetName(Napi::Object *module);

static int JsDict_SetItemString(Napi::Object* v, const char* key, Napi::Value* item);

static Napi::Number JsLong_FromLongLong(const Napi::Env& env, long long value);

bool JsSequence_Check(const Napi::Value* obj);
size_t JsSequence_Size(const Napi::Value* obj);

#endif