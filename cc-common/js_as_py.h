#ifndef __JS_AS_PY_HPP__
#define __JS_AS_PY_HPP__

#include <napi.h>

// #define JsAPI_FUNC(RTYPE) RTYPE
// #define JsAPI_DATA(RTYPE) extern RTYPE
// #define JsMODINIT_FUNC void
// #define Js_ssize_t int
// #define JsVarObject_HEAD_INIT(type, size) JsObject_HEAD_INIT(type) size,
// #define JsObject_HEAD_INIT(type) _JsObject_HEAD_INIT(type, 0)
// #define _JsObject_HEAD_INIT(type, size) 0, type, size,
// #define JsTypeObject JsTypeObject
// #define JsVarObject JsVarObject
// original implemented in cv2.cpp
class ArgInfo
{
public:
    const char* name;
    bool outputarg;
    // more fields may be added if necessary

    ArgInfo(const char* name_, bool outputarg_) : name(name_), outputarg(outputarg_) {}

private:
    ArgInfo(const ArgInfo&) = delete;
    ArgInfo& operator=(const ArgInfo&) = delete;
};


class FakeCallbackInfo {
public:
    FakeCallbackInfo(const Napi::CallbackInfo& original_info, const std::vector<Napi::Value>& new_args);

    size_t Length() const;
    Napi::Value operator[](size_t index) const;
    Napi::Env Env() const;

private:
    Napi::Env env;
    std::vector<Napi::Value> new_args;
};

// template<class T=Napi::CallbackInfo>
bool JsArg_ParseTupleAndKeywords(const Napi::CallbackInfo& info, const char* format, char** keywords, ...);
bool JsArg_ParseTupleAndKeywords(const FakeCallbackInfo& info, const char* format, char** keywords, ...);

typedef void (*JsObject)(void);

/**
 * @brief 
 * 
 * @param The first argument (JsObject*) is a pointer to the Nodejs object that represents the module or instance that the function is being called on. For module-level functions, this argument will be NULL.
 * @param The second argument (JsObject*) is a pointer to the Nodejs tuple that contains the arguments passed to the function.
 * 
 * The JsCFunction type is a function pointer type that is used as the function signature for C functions that are intended to be called from Nodejs. The JsCFunction signature is a standard interface used by the Nodejs interpreter to call C functions. A C function that conforms to this signature can be registered as a Nodejs function using the JsMethodDef structure and made available to Nodejs code as part of a Nodejs extension module.
 * 
 * The return value of a JsCFunction is a new reference to a Nodejs object that represents the return value of the function. If the function encounters an error, it should set an appropriate exception and return NULL.
 */
// typedef JsObject *(*JsCFunction)(JsObject *, JsObject *);

// 
// convert from PythonC code base
//

// PyCFunction(PyObject *self, PyObject *args);
typedef Napi::Value (*JsCFunction)(const Napi::CallbackInfo &info);
// PyCFunctionWithKeywords(PyObject *self, PyObject *args, PyObject *kwargs);
typedef Napi::Value (*JsCFunctionWithKeywords)(const Napi::CallbackInfo &info);

#define Js_RETURN_NONE return info.Env().Null()

#define JsExc_TypeError "error"

void JsErr_SetString(const Napi::Env &env, const std::string &message);

/**
 * Build a Napi::Value object from a format string and a variable number of arguments.
 *
 * @param info A Napi::CallbackInfo object that contains information about the current JavaScript function call.
 * @param format A format string that specifies the types of the arguments.
 * @param ... A variable number of arguments that correspond to the format string.
 *
 * @return A Napi::Value object that contains the values specified by the format string and the variable arguments.
 */
Napi::Value Js_BuildValue(const Napi::CallbackInfo &info, const char *format, ...);

/**
 * @brief structs are typically organized into arrays that are passed to the JsModule_Create function to create a new Nodejs module. When a Nodejs module is loaded, the module's methods and functions are made available to Nodejs code, and can be called like any other Nodejs function.
 * In C, JsMethodDef is a struct defined in the Nodejs C API that represents a single method in a Nodejs module or extension module. The struct is used to define the name, arguments, and implementation of a Nodejs function that can be called from Nodejs code.
 * @see https://docs.python.org/3/c-api/structures.html#c.PyMethodDef
 */
struct JsMethodDef {
    const char  *ml_name;   /* The name of the built-in function/method */
    JsCFunction ml_meth;    /* The C function that implements it */
    // using JsCFunction = Napi::Value (*)(const Napi::CallbackInfo &info);   /* The C function that implements it */
    int         ml_flags;   /* Combination of METH_xxx flags, which mostly
                               describe the args expected by the C func */
    const char  *ml_doc;    /* The __doc__ attribute, or NULL */
};

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

static inline JsTypeObject Js_TYPE(Napi::Value *value) {
  if (!value->IsObject()) {
    return value->Env().Null();
  }
  Napi::Object object = value->As<Napi::Object>();
  Napi::Value prototype_val = object.Get(Napi::String::New(object.Env(), "__proto__"));
  if (!prototype_val.IsObject()) {
    return value->Env().Null();
  }
  Napi::Object prototype = prototype_val.As<Napi::Object>();
  return prototype;
}

static inline int Js_IS_TYPE(Napi::Value *ob, JsTypeObject *type) {
    return false; // don't check type for now
    // return Js_TYPE(ob) == type;
}
// static inline int PyObject_TypeCheck(PyObject *ob, PyTypeObject *type) {
//     return Py_IS_TYPE(ob, type) || PyType_IsSubtype(Py_TYPE(ob), type);
// }
static inline int JsObject_TypeCheck(Napi::Value *ob, JsTypeObject *type) {
    return false; // don't check type for now
    // return Js_IS_TYPE(ob, type);//  || PyType_IsSubtype(Py_TYPE(ob), type);
}

// naive version:
// inline Napi::String JsString_FromString(const Napi::Env& env, const char* str) {
//     return Napi::String::New(env, str);
// }

// use std::shared_ptr
// inline std::shared_ptr<Napi::String> JsString_FromString(const Napi::Env& env, const char* str) {
//     if (str == nullptr) {
//         throw std::invalid_argument("Input string is null");
//     }
// 
//     // Create a new Napi::String and wrap it with a shared_ptr
//     auto result = std::make_shared<Napi::String>(Napi::String::New(env, str));
//     return result;
// }

Napi::Value* JsString_FromString(const Napi::Env& env, const char* str);

// PyObject *PyCFunction_NewEx(PyMethodDef *ml, PyObject *self, PyObject *module)
Napi::Value * JsCFunction_NewEx(JsMethodDef *ml, Napi::Value *self, Napi::Object *module);

// const char * PyModule_GetName(PyObject *m)
const std::string JsModule_GetName(Napi::Object *module);

int JsDict_SetItemString(Napi::Object* v, const char* key, Napi::Value* item);

Napi::Number JsLong_FromLongLong(const Napi::Env& env, long long value);
Napi::Number JsLong_FromUnsignedLong(const Napi::Env& env, long long value);

bool JsSequence_Check(const Napi::Value* obj);
size_t JsSequence_Size(const Napi::Value* obj);

Napi::Value *JsSequence_GetItem(const Napi::Value* obj, size_t index);

typedef Napi::Object *(*getter)(Napi::Object *, void *);
typedef int (*setter)(Napi::Object *, Napi::Object *, void *);

struct JsGetSetDef {
    const char *name;
    getter get;
    setter set;
    const char *doc;
    void *closure;
};


// bool JsArray_Check(const Napi::Value& value) {
//     return value.IsArray();
// }

// bool JsArray_Check(const Napi::Value* value) {
//     return value->IsArray();
// }

#endif