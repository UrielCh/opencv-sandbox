#ifndef CV2_UTIL_HPP
#define CV2_UTIL_HPP

#include "cv2.hpp"
#include "opencv2/core.hpp"
#include "opencv2/core/utils/tls.hpp"

int failmsg(const Napi::CallbackInfo& info, const char* format, ...);
Napi::Value failmsgp(const Napi::CallbackInfo& info, const char *format, ...);

void pyRaiseCVOverloadException(const std::string& functionName);

void pyPopulateArgumentConversionErrors();


#define ERRWRAP2_NAPI(info, expr)                                              \
    try                                                                         \
    {                                                                           \
        expr;                                                                   \
    }                                                                           \
    catch (const cv::Exception &e)                                              \
    {                                                                           \
        Napi::Error::New((info).Env(), e.what()).ThrowAsJavaScriptException(); \
        return (info).Env().Undefined();                                       \
    }                                                                           \
    catch (const std::exception &e)                                             \
    {                                                                           \
        Napi::Error::New((info).Env(), e.what()).ThrowAsJavaScriptException(); \
        return (info).Env().Undefined();                                       \
    }                                                                           \
    catch (...)                                                                 \
    {                                                                           \
        Napi::Error::New((info).Env(), "Unknown exception occurred").ThrowAsJavaScriptException(); \
        return (info).Env().Undefined();                                       \
    }


#endif // CV2_UTIL_HPP
