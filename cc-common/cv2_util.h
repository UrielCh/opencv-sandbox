#ifndef CV2_UTILS_2_H_
#define CV2_UTILS_2_H_

#include <napi.h>
#include "opencv2/core.hpp"
#include "opencv2/core/utils/tls.hpp"

extern cv::TLSData<std::vector<std::string> > conversionErrorsTLS;

void jsRaiseCVOverloadException(const Napi::CallbackInfo &info, const std::string& functionName);

void jsPopulateArgumentConversionErrors(const Napi::CallbackInfo &info);

#endif