#ifndef __JSCOMPAT_HPP__
#define __JSCOMPAT_HPP__
#include <string>
#include <napi.h>

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

#define CV_JS_TO_CLASS(TYPE) \
template<> \
bool jsopencv_to(const Napi::CallbackInfo &info, const Napi::Value &dst, TYPE& src) \
{\
    if (dst.IsNull() || dst.IsUndefined()) \
        return true; \
    cv::Ptr<TYPE> ptr; \
\
    if (!jsopencv_to(info, dst, ptr)) return false; \
    src = *ptr; \
    return true; \
}

#define CV_JS_FROM_CLASS(TYPE) \
template<> \
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const TYPE &src) \
{ \
    cv::Ptr<TYPE> ptr(new TYPE()); \
\
    *ptr = src; \
    return jsopencv_from<TYPE>(info, ptr); \
}

#define CV_JS_TO_CLASS_PTR(TYPE)  \
template<> \
bool jsopencv_to(const Napi::CallbackInfo &info, const Napi::Value &dst, TYPE*& src) \
{ \
    if (dst.IsNull() || dst.IsUndefined()) \
        return true; \
    cv::Ptr<TYPE> ptr; \
\
    if (!jsopencv_to(info, dst, ptr)) return false; \
    src = ptr; \
    return true; \
}

#define CV_JS_FROM_CLASS_PTR(TYPE)\
static Napi::Value jsopencv_from(const Napi::CallbackInfo &info, TYPE*& src) \
{ \
    return jsopencv_from(info, cv::Ptr<TYPE>(src)); \
}

#define CV_JS_TO_ENUM(TYPE)  \
template<> \
bool jsopencv_to(const Napi::CallbackInfo &info, const Napi::Value &dst, TYPE& src) \
{ \
    if (dst.IsNull() || dst.IsUndefined()) \
        return true; \
    int underlying = 0;  \
\
    if (!jsopencv_to(info, dst, underlying)) return false; \
    src = static_cast<TYPE>(underlying); \
    return true; \
}

#define CV_JS_FROM_ENUM(TYPE) \
template<> \
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const TYPE& src) \
{ \
    return Napi::Number::New(info.Env(), static_cast<int>(src)); \
}


// convert from PythonC code base

#define Js_RETURN_NONE return info.Env().Null()


void JsErr_SetString(const Napi::Env &env, const std::string &message)
{
    Napi::Error::New(env, message).ThrowAsJavaScriptException();
}


Napi::Value Js_BuildValue(const Napi::CallbackInfo &info, const char *format, ...);

#endif // END HEADER GUARD
