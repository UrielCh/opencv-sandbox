#ifndef CV2_UTILS_2_H_
#define CV2_UTILS_2_H_

#include <napi.h>
#include "opencv2/core.hpp"
#include "opencv2/core/utils/tls.hpp"





bool isNodeBindingsDebugEnabled();
void emit_jsfailmsg(const Napi::Env& env, const char *msg);
int jsfailmsg(const Napi::Env& env, const char *fmt, ...);
Napi::Value jsfailmsgp(const Napi::Env& env, const char *fmt, ...);

//======================================================================================================================

// class PyAllowThreads ...




































































//======================================================================================================================

extern Napi::Value* opencv_error; // global Error object



#define ERRWRAP2_NAPI(info, expr)  \
    try { \
      expr; \
    } \
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