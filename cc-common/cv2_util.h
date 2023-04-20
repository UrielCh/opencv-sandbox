#ifndef CV2_UTILS_2_H_
#define CV2_UTILS_2_H_

#include <napi.h>
#include "opencv2/core.hpp"
#include "opencv2/core/utils/tls.hpp"
#include "./extra_common.h"




bool isNodeBindingsDebugEnabled();
void emit_jsfailmsg(const Napi::Env& env, const char *msg);
int jsfailmsg(const Napi::Env& env, const char *fmt, ...);
Napi::Value jsfailmsgp(const Napi::Env& env, const char *fmt, ...);

//======================================================================================================================

// class PyAllowThreads ...




































































//======================================================================================================================
extern Napi::Value* opencv_error; // global Error object
#define ERRWRAP2_NAPI(env, expr)  \
    try { expr; } \
    catch (const cv::Exception &e) { \
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException(); \
        return env.Undefined(); \
    } catch (const std::exception &e) { \
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException(); \
        return env.Undefined(); \
    } catch (...) { \
        Napi::Error::New(env, "Unknown exception occurred").ThrowAsJavaScriptException(); \
        return env.Undefined();                                       \
    }
// same as ERRWRAP2_NAPI but returns 0 instead of env.Undefined()
#define ERRWRAP2_NAPI_INT(env, expr)  \
    try { expr; } \
    catch (const cv::Exception &e) { \
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException(); \
        return 0; \
    } catch (const std::exception &e) { \
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException(); \
        return 0; \
    } catch (...) { \
        Napi::Error::New(env, "Unknown exception occurred").ThrowAsJavaScriptException(); \
        return 0;                                          \
    }


#define ERRWRAP2_NAPI_VOID(env, expr)  \
    try { expr; } \
    catch (const cv::Exception &e) { \
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException(); \
        return ; \
    } catch (const std::exception &e) { \
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException(); \
        return ; \
    } catch (...) { \
        Napi::Error::New(env, "Unknown exception occurred").ThrowAsJavaScriptException(); \
        return ;                                          \
    }

//======================================================================================================================

extern cv::TLSData<std::vector<std::string> > conversionErrorsTLS;

inline void jsPrepareArgumentConversionErrorsStorage(std::size_t size)
{
    std::vector<std::string>& conversionErrors = conversionErrorsTLS.getRef();
    conversionErrors.clear();
    conversionErrors.reserve(size);
}

void jsRaiseCVOverloadException(const Napi::CallbackInfo &info, const std::string& functionName);
void jsPopulateArgumentConversionErrors(const Napi::CallbackInfo &info);

//======================================================================================================================

Napi::Value jscvRedirectError(const Napi::CallbackInfo& info);

#endif // CV2_UTILS_2_H_