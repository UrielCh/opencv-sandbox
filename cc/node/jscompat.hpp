/////////////////////////////////
// TODO ADD License Agreement
//

#ifndef __JSCOMPAT_HPP__
#define __JSCOMPAT_HPP__
#include <string>
#include <napi.h>
#include "./js_as_py.hpp";

static inline bool getUnicodeString(Napi::Value obj, std::string &str) {
    bool res = false;
    if (obj.IsString())
    {
        std::string s = obj.As<Napi::String>();
        str = s;
        res = true;
    }
    return res;
}

static inline std::string getJsObjectNameAttr(Napi::Value obj) {
    std::string obj_name;
    Napi::Object js_obj = obj.As<Napi::Object>();
    Napi::Value cls_name_obj = js_obj.Get("__name__");
    
    if (!getUnicodeString(cls_name_obj, obj_name)) {
        obj_name.clear();
    }

    if (obj_name.empty()) {
        obj_name = "<UNAVAILABLE>";
    }
    
    return obj_name;
}

// the colloing cod contains macro:
// CV_JS_JS_WITH_KW_  CV_JS_FN_NOARGS_
// CV_JS_JS_WITH_KW   CV_JS_FN_NOARGS
// CV_JS_TO_CLASS     CV_JS_FROM_CLASS
// CV_JS_TO_CLASS_PTR CV_JS_FROM_CLASS_PTR
// CV_JS_TO_ENUM      CV_JS_FROM_ENUM
// CVJS_TYPE_HEAD     CVJS_TYPE_INCREF



// #define CV_JS_FN_WITH_KW_(fn, flags) (JsCFunction)(void*)(JsCFunctionWithKeywords)(fn), (flags) | METH_VARARGS | METH_KEYWORDS


// CV_PY_FN_WITH_KW_ and CV_PY_FN_NOARGS_
#define CV_JS_FN_WITH_KW_(fn, flags) (JsCFunction)(void*)(JsCFunctionWithKeywords)(fn), (flags)

// #define CV_JS_FN_NOARGS_(fn, flags) (JsCFunction)(fn), (flags) | METH_NOARGS
#define CV_JS_FN_NOARGS_(fn, flags) (JsCFunction)(fn), (flags)
// CV_PY_FN_WITH_KW and CV_PY_FN_NOARGS
#define CV_JS_FN_WITH_KW(fn) CV_JS_FN_WITH_KW_(fn, 0)
#define CV_JS_FN_NOARGS(fn) CV_JS_FN_NOARGS_(fn, 0)


//      CV_PY_TO_CLASS
#define CV_JS_TO_CLASS(TYPE)                                               \
template<>                                                                 \
bool jsopencv_to(const Napi::CallbackInfo &info, const Napi::Value &dst, TYPE& src, const ArgInfo& argInfo) \
{                                                                          \
    if (dst.IsNull() || dst.IsUndefined())                                 \
        return true;                                                       \
    cv::Ptr<TYPE> ptr;                                                     \
                                                                           \
    if (!jsopencv_to(info, dst, ptr, argInfo)) return false;               \
    src = *ptr;                                                            \
    return true;                                                           \
}
// from CV_PY_FROM_CLASS
#define CV_JS_FROM_CLASS(TYPE)                                             \
template<>                                                                 \
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const TYPE &src) \
{                                                                          \
    cv::Ptr<TYPE> ptr(new TYPE());                                         \
                                                                           \
    *ptr = src;                                                            \
    return jsopencv_from<TYPE>(info, ptr);                                 \
}
//      CV_PY_TO_CLASS_PTR
#define CV_JS_TO_CLASS_PTR(TYPE)                                           \
template<>                                                                 \
bool jsopencv_to(const Napi::CallbackInfo &info, const Napi::Value &dst, TYPE*& src, const ArgInfo& argInfo) \
{                                                                          \
    if (dst.IsNull() || dst.IsUndefined())                                 \
        return true;                                                       \
    cv::Ptr<TYPE> ptr;                                                     \
                                                                           \
    if (!jsopencv_to(info, dst, ptr, argInfo)) return false;               \
    src = ptr;                                                             \
    return true;                                                           \
}
//      CV_PY_FROM_CLASS_PTR
#define CV_JS_FROM_CLASS_PTR(TYPE)                                         \
static Napi::Value jsopencv_from(const Napi::CallbackInfo &info, TYPE*& src) \
{                                                                          \
    return jsopencv_from(info, cv::Ptr<TYPE>(src));                        \
}
//      CV_PY_TO_ENUM
#define CV_JS_TO_ENUM(TYPE)                                                \
template<>                                                                 \
bool jsopencv_to(const Napi::CallbackInfo &info, const Napi::Value* dst, TYPE& src, const ArgInfo& argInfo) \
{                                                                          \
    if (dst.IsNull() || dst.IsUndefined())                                 \
        return true;                                                       \
    int underlying = 0;                                                    \
                                                                           \
    if (!jsopencv_to(info, dst, underlying, argInfo)) return false;        \
    src = static_cast<TYPE>(underlying);                                   \
    return true;                                                           \
}
//      CV_PY_FROM_ENUM Enum are just int value
#define CV_JS_FROM_ENUM(TYPE) \
template<> \
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const TYPE& src) \
{                                                                          \
    return Napi::Number::New(info.Env(), static_cast<int>(src));           \
}
// may be writen as return jsopencv_from(static_cast<int>(src));


// CVPY_TYPE_HEAD
#define CVJS_TYPE_HEAD PyVarObject_HEAD_INIT(&PyType_Type, 0)
// CVPY_TYPE_INCREF
#define CVJS_TYPE_INCREF(T) Py_INCREF(T)

#define CVJS_TYPE_DECLARE(EXPORT_NAME, CLASS_ID, STORAGE, SNAME, SCOPE) \
    struct jsopencv_##CLASS_ID##_t \
    { \
        JsObject_HEAD \
        STORAGE v; \
    }; \
    static JsTypeObject jsopencv_##CLASS_ID##_TypeXXX = \
    { \
        CVJS_TYPE_HEAD \
        MODULESTR SCOPE"."#EXPORT_NAME, \
        sizeof(jsopencv_##CLASS_ID##_t), \
    }; \
    static JsTypeObject * jsopencv_##CLASS_ID##_TypePtr = &jsopencv_##CLASS_ID##_TypeXXX; \
    static bool jsopencv_##CLASS_ID##_getp(Napi::Value * self, STORAGE * & dst) \
    { \
        if (PyObject_TypeCheck(self, jsopencv_##CLASS_ID##_TypePtr)) \
        { \
            dst = &(((jsopencv_##CLASS_ID##_t*)self)->v); \
            return true; \
        } \
        return false; \
    } \
    static Napi::Value * jsopencv_##CLASS_ID##_Instance(const STORAGE &r) \
    { \
        jsopencv_##CLASS_ID##_t *m = PyObject_NEW(jsopencv_##CLASS_ID##_t, jsopencv_##CLASS_ID##_TypePtr); \
        new (&(m->v)) STORAGE(r); \
        return (Napi::Value*)m; \
    } \
    static void jsopencv_##CLASS_ID##_dealloc(Napi::Value* self) \
    { \
        ((jsopencv_##CLASS_ID##_t*)self)->v.STORAGE::~SNAME(); \
        PyObject_Del(self); \
    } \
    static Napi::Value* jsopencv_##CLASS_ID##_repr(Napi::Value* self) \
    { \
        char str[1000]; \
        snprintf(str, sizeof(str), "< " MODULESTR SCOPE"."#EXPORT_NAME" %p>", self); \
        return PyString_FromString(str); \
    }


#define CVJS_TYPE_INIT_STATIC(EXPORT_NAME, CLASS_ID, ERROR_HANDLER, BASE, CONSTRUCTOR, SCOPE) \
    { \
        jsopencv_##CLASS_ID##_TypePtr->tp_base = jsopencv_##BASE##_TypePtr; \
        jsopencv_##CLASS_ID##_TypePtr->tp_dealloc = jsopencv_##CLASS_ID##_dealloc; \
        jsopencv_##CLASS_ID##_TypePtr->tp_repr = jsopencv_##CLASS_ID##_repr; \
        jsopencv_##CLASS_ID##_TypePtr->tp_getset = jsopencv_##CLASS_ID##_getseters; \
        jsopencv_##CLASS_ID##_TypePtr->tp_init = (initproc) CONSTRUCTOR; \
        jsopencv_##CLASS_ID##_TypePtr->tp_methods = jsopencv_##CLASS_ID##_methods; \
        jsopencv_##CLASS_ID##_TypePtr->tp_alloc = PyType_GenericAlloc; \
        jsopencv_##CLASS_ID##_TypePtr->tp_new = PyType_GenericNew; \
        jsopencv_##CLASS_ID##_TypePtr->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE; \
        if (PyType_Ready(jsopencv_##CLASS_ID##_TypePtr) != 0) \
        { \
            ERROR_HANDLER; \
        } \
        CVJS_TYPE_INCREF(jsopencv_##CLASS_ID##_TypePtr); \
        if (!registerNewType(m, #EXPORT_NAME, (Napi::Value*)jsopencv_##CLASS_ID##_TypePtr, SCOPE)) \
        { \
            printf("Failed to register a new type: " #EXPORT_NAME  ", base (" #BASE ") in " SCOPE " \n"); \
            ERROR_HANDLER; \
        } \
    }

//==================================================================================================

#define CVJS_TYPE_DECLARE_DYNAMIC(EXPORT_NAME, CLASS_ID, STORAGE, SNAME, SCOPE) \
    struct jsopencv_##CLASS_ID##_t \
    { \
        JsObject_HEAD \
        STORAGE v; \
    }; \
    static PyObject * jsopencv_##CLASS_ID##_TypePtr = 0; \
    static bool jsopencv_##CLASS_ID##_getp(Napi::Value * self, STORAGE * & dst) \
    { \
        if (PyObject_TypeCheck(self, (JsTypeObject*)jsopencv_##CLASS_ID##_TypePtr)) \
        { \
            dst = &(((jsopencv_##CLASS_ID##_t*)self)->v); \
            return true; \
        } \
        return false; \
    } \
    static Napi::Value * jsopencv_##CLASS_ID##_Instance(const STORAGE &r) \
    { \
        jsopencv_##CLASS_ID##_t *m = PyObject_New(jsopencv_##CLASS_ID##_t, (JsTypeObject*)jsopencv_##CLASS_ID##_TypePtr); \
        new (&(m->v)) STORAGE(r); \
        return (Napi::Value*)m; \
    } \
    static void jsopencv_##CLASS_ID##_dealloc(Napi::Value* self) \
    { \
        ((jsopencv_##CLASS_ID##_t*)self)->v.STORAGE::~SNAME(); \
        PyObject_Del(self); \
    } \
    static Napi::Value* jsopencv_##CLASS_ID##_repr(Napi::Value* self) \
    { \
        char str[1000]; \
        snprintf(str, sizeof(str), "< " MODULESTR SCOPE"."#EXPORT_NAME" %p>", self); \
        return PyString_FromString(str); \
    } \
    static PyType_Slot jsopencv_##CLASS_ID##_Slots[] =  \
    { \
        {Py_tp_dealloc, 0}, \
        {Py_tp_repr, 0}, \
        {Py_tp_getset, 0}, \
        {Py_tp_init, 0}, \
        {Py_tp_methods, 0}, \
        {Py_tp_alloc, 0}, \
        {Py_tp_new, 0}, \
        {0, 0} \
    }; \
    static PyType_Spec jsopencv_##CLASS_ID##_Spec = \
    { \
        MODULESTR SCOPE"."#EXPORT_NAME, \
        sizeof(jsopencv_##CLASS_ID##_t), \
        0, \
        Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, \
        jsopencv_##CLASS_ID##_Slots  \
    };

#define CVJS_TYPE_INIT_DYNAMIC(EXPORT_NAME, CLASS_ID, ERROR_HANDLER, BASE, CONSTRUCTOR, SCOPE) \
    { \
        jsopencv_##CLASS_ID##_Slots[0].pfunc /*tp_dealloc*/ = (void*)jsopencv_##CLASS_ID##_dealloc; \
        jsopencv_##CLASS_ID##_Slots[1].pfunc /*tp_repr*/    = (void*)jsopencv_##CLASS_ID##_repr; \
        jsopencv_##CLASS_ID##_Slots[2].pfunc /*tp_getset*/  = (void*)jsopencv_##CLASS_ID##_getseters; \
        jsopencv_##CLASS_ID##_Slots[3].pfunc /*tp_init*/    = (void*) CONSTRUCTOR; \
        jsopencv_##CLASS_ID##_Slots[4].pfunc /*tp_methods*/ = jsopencv_##CLASS_ID##_methods; \
        jsopencv_##CLASS_ID##_Slots[5].pfunc /*tp_alloc*/   = (void*)PyType_GenericAlloc; \
        jsopencv_##CLASS_ID##_Slots[6].pfunc /*tp_new*/     = (void*)PyType_GenericNew; \
        Napi::Value * bases = 0; \
        if (jsopencv_##BASE##_TypePtr) \
            bases = PyTuple_Pack(1, jsopencv_##BASE##_TypePtr); \
        jsopencv_##CLASS_ID##_TypePtr = PyType_FromSpecWithBases(&jsopencv_##CLASS_ID##_Spec, bases); \
        if (!jsopencv_##CLASS_ID##_TypePtr) \
        { \
            printf("Failed to create type from spec: " #CLASS_ID ", base (" #BASE ")\n"); \
            ERROR_HANDLER; \
        } \
        if (!registerNewType(m, #EXPORT_NAME, (Napi::Value*)jsopencv_##CLASS_ID##_TypePtr, SCOPE)) \
        { \
            printf("Failed to register a new type: " #EXPORT_NAME  ", base (" #BASE ") in " SCOPE " \n"); \
            ERROR_HANDLER; \
        } \
    }

#endif // END HEADER GUARD
