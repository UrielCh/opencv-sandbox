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

bool JsArg_ParseTupleAndKeywords(const Napi::CallbackInfo& info, const char* format, char** keywords, ...);

Napi::Value failmsgp(const Napi::Env& env, const char *format, ...);

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
