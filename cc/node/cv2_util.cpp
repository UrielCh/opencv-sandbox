#include "cv2_util.hpp"
#include <napi.h>
#include <opencv2/opencv.hpp>

/**
 * @brief Throws an exception exception-object
 */
int failmsg(const Napi::CallbackInfo& info, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    char message[1024];
    vsnprintf(message, sizeof(message), format, args);
    va_end(args);
    Napi::Error::New(info.Env(), message).ThrowAsJavaScriptException();
    return 0;
}

Napi::Value failmsgp(const Napi::CallbackInfo& info, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    char message[1024];
    vsnprintf(message, sizeof(message), format, args);
    va_end(args);
    Napi::Error::New(info.Env(), message).ThrowAsJavaScriptException();
    return info.Env().Null();

}

void pyRaiseCVOverloadException(const std::string& functionName) {}

void pyPopulateArgumentConversionErrors() {}
