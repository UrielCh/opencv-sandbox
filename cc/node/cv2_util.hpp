#ifndef CV2_UTIL_HPP
#define CV2_UTIL_HPP

#include "cv2.hpp"
#include "opencv2/core.hpp"
#include "opencv2/core/utils/tls.hpp"

int failmsg(const Napi::CallbackInfo& info, const char* format, ...);
Napi::Value failmsgp(const Napi::CallbackInfo& info, const char *format, ...);

void pyRaiseCVOverloadException(const std::string& functionName);

void pyPopulateArgumentConversionErrors();

#endif // CV2_UTIL_HPP
