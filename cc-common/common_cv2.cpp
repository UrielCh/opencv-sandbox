#include "common_cv2.h"

#pragma warning(push)
#pragma warning(disable : 4101) // disable warning C4101

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

#pragma warning(pop) // restore the previous warning state