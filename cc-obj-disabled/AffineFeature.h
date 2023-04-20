
#ifndef __TEST_AFFINEFEATURE__H__
#define __TEST_AFFINEFEATURE__H__
#include <napi.h>

#include <opencv2/opencv.hpp>

class AffineFeatureWrapper : public Napi::ObjectWrap<AffineFeatureWrapper> {
   public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    AffineFeatureWrapper(const Napi::CallbackInfo &info);
    AffineFeatureWrapper(const Napi::CallbackInfo &info, const cv::Ptr<cv::AffineFeature> &akaze);
    ~AffineFeatureWrapper();

    static Napi::FunctionReference constructor;

   cv::Ptr<cv::AffineFeature> cvdata;
   // present in all warppers to check types
   static Napi::Symbol typeSymbol;

   private:

    // Wrapped methods
    Napi::Value getDefaultName(const Napi::CallbackInfo &info);
    Napi::Value getViewParams(const Napi::CallbackInfo &info);
    Napi::Value setViewParams(const Napi::CallbackInfo &info);
    
    // Static methods
    static Napi::Value CreateStatic(const Napi::CallbackInfo &info);
};

#endif
