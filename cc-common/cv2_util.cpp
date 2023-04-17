#include "js_as_py.h"
#include "cv2_util.h"
#include <stdarg.h>
#include "opencv2/core.hpp"
#include <opencv2/core/utils/configuration.private.hpp>
#include "opencv2/core/utils/logger.hpp"
Napi::Value* opencv_error = NULL; // global Error object
cv::TLSData<std::vector<std::string> > conversionErrorsTLS;
using namespace cv;
// will be used to store all internal data initilized in init function
Napi::Symbol DATA_KEY;
Napi::Symbol DATA_TYPE;
//======================================================================================================================
bool isNodeBindingsDebugEnabled()
{   // Original code use variable "OPENCV_PYTHON_DEBUG" we are using "OPENCV_NODE_DEBUG"
    static bool param_debug = cv::utils::getConfigurationParameterBool("OPENCV_NODE_DEBUG", false);
    return param_debug;
}

void emit_jsfailmsg(const Napi::Env& env, const char *msg)
{
    static bool param_debug = isNodeBindingsDebugEnabled();
    if (param_debug)
    {
        CV_LOG_WARNING(NULL, "Bindings conversion failed: " << msg);
    }
    Napi::Error::New(env, msg).ThrowAsJavaScriptException();
}

int jsfailmsg(const Napi::Env& env, const char *fmt, ...)
{
    char str[1000];

    va_list ap;
    va_start(ap, fmt);
    vsnprintf(str, sizeof(str), fmt, ap);
    va_end(ap);

    emit_jsfailmsg(env, str);
    return 0;
}

Napi::Value jsfailmsgp(const Napi::Env& env, const char *fmt, ...)
{
    char str[1000];

    va_list ap;
    va_start(ap, fmt);
    vsnprintf(str, sizeof(str), fmt, ap);
    va_end(ap);

    emit_jsfailmsg(env, str);
    return env.Null();
}

void jsRaiseCVException(const Napi::Env& env, const cv::Exception &e)
{
    Napi::Object opencv_error = Napi::Object::New(env);
    opencv_error.Set("file", Napi::String::New(env, e.file.c_str()));
    opencv_error.Set("func", Napi::String::New(env, e.func.c_str()));
    opencv_error.Set("line", Napi::Number::New(env, e.line));
    opencv_error.Set("code", Napi::Number::New(env, e.code));
    opencv_error.Set("msg", Napi::String::New(env, e.msg.c_str()));
    opencv_error.Set("err", Napi::String::New(env, e.err.c_str()));
    Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
}
//======================================================================================================================

void jsRaiseCVOverloadException(const Napi::CallbackInfo &info, const std::string& functionName)
{
    const std::vector<std::string>& conversionErrors = conversionErrorsTLS.getRef();
    const std::size_t conversionErrorsCount = conversionErrors.size();
    if (conversionErrorsCount > 0)
    {
        const std::string bullet = "\n - ";

        std::size_t requiredBufferSize = bullet.size() * conversionErrorsCount;
        for (std::size_t i = 0; i < conversionErrorsCount; ++i)
        {
            requiredBufferSize += conversionErrors[i].size();
        }

        std::string errorMessage("Overload resolution failed:");
        errorMessage.reserve(errorMessage.size() + requiredBufferSize);
        for (std::size_t i = 0; i < conversionErrorsCount; ++i)
        {
            errorMessage += bullet;
            errorMessage += conversionErrors[i];
        }
        cv::Exception exception(cv::Error::StsBadArg, errorMessage, functionName, "", -1);
        Napi::Error::New(info.Env(), exception.what()).ThrowAsJavaScriptException();
    }
    else
    {
        cv::Exception exception(cv::Error::StsInternal, "Overload resolution failed, but no errors reported",
                                functionName, "", -1);
        Napi::Error::New(info.Env(), exception.what()).ThrowAsJavaScriptException();
    }
}
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4101) // disable warning C4101
#endif
void jsPopulateArgumentConversionErrors(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (env.IsExceptionPending())
    {
        try
        {
            // Get the pending exception and clear it
            Napi::Error error = env.GetAndClearPendingException();
            std::string message = error.Message();
#ifdef CV_CXX11
            conversionErrorsTLS.getRef().push_back(std::move(message));
#else
            conversionErrorsTLS.getRef().push_back(message);
#endif
        }
        catch (const Napi::Error &e)
        {
            // Do nothing if an error occurs while getting the pending exception
        }
    }
}
#ifdef _MSC_VER
#pragma warning(pop) // restore the previous warning state
#endif
//======================================================================================================================
static int OnError(int status, const char *func_name, const char *err_msg, const char *file_name, int line, void *userdata)
{
    Napi::Env* env = static_cast<Napi::Env*>(userdata);

    Napi::Function on_error = env->Global().Get("onError").As<Napi::Function>();
    std::vector<napi_value> args = {
        Napi::Number::New(*env, status),
        Napi::String::New(*env, func_name),
        Napi::String::New(*env, err_msg),
        Napi::String::New(*env, file_name),
        Napi::Number::New(*env, line)
    };

    try {
        on_error.Call(args);
    } catch (const Napi::Error& e) {
        e.ThrowAsJavaScriptException();
    }
    return 0; // The return value isn't used
}

Napi::Value jscvRedirectError(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::Function on_error = info[0].As<Napi::Function>();




    if (!on_error.IsFunction()) {
        Napi::TypeError::New(env, "on_error must be callable").ThrowAsJavaScriptException();
        return env.Null();
    }

    // Keep track of the previous handler parameter, so we can reset it when no longer used
    static Napi::FunctionReference last_on_error;
    if (!on_error.IsUndefined() && !on_error.IsNull()) {
        last_on_error.Reset(on_error, 1);
        ERRWRAP2_NAPI(env, redirectError(OnError, &env));
    } else {
        last_on_error.Reset();
        ERRWRAP2_NAPI(env, redirectError(NULL));
    }





    return env.Undefined();
}
