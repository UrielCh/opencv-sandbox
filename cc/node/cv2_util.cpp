#include "cv2_util.hpp"
#include <napi.h>
#include <opencv2/opencv.hpp>

// global Error object
Napi::Value* opencv_error = NULL;

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
            conversionErrorsTLS.getRef().push_back(message);
        }
        catch (const Napi::Error &e)
        {
            // Do nothing if an error occurs while getting the pending exception
        }
    }
}