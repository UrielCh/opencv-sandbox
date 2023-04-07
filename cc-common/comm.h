#ifndef __ARG_INFO__H__
#define __ARG_INFO__H__

#include <napi.h>

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

int failmsg(const Napi::Env& env, const char* format, ...);

template<typename _Tp> static
bool jsopencv_to_safe(const Napi::Value* obj, const _Tp& value, const ArgInfo& argInfo)
{
    try
    {
        return jsopencv_to(obj, value, argInfo);
    }
    catch (const std::exception &e)
    {
        failmsg(obj->Env(), "Conversion error: %s, what: %s", argInfo.name, e.what());
        return false;
    }
    catch (...)
    {
        failmsg(obj->Env(), "Conversion error: %s", argInfo.name);
        return false;
    }
}

bool JsArg_ParseTupleAndKeywords(const Napi::CallbackInfo& info, const char* format, char** keywords, ...);

Napi::Value failmsgp(const Napi::Env& env, const char *format, ...);

#define ERRWRAP2_NAPI(info, expr)  \
    try { expr; } \
    catch (const cv::Exception &e) \
    { \
        Napi::Error::New((info).Env(), e.what()).ThrowAsJavaScriptException(); \
        return (info).Env().Undefined(); \
    } catch (const std::exception &e) { \
        Napi::Error::New((info).Env(), e.what()).ThrowAsJavaScriptException(); \
        return (info).Env().Undefined(); \
    } catch (...) { \
        Napi::Error::New((info).Env(), "Unknown exception occurred").ThrowAsJavaScriptException(); \
        return (info).Env().Undefined();                                       \
    }

#endif // __ARG_INFO__H__
