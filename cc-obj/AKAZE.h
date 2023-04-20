#ifndef __TEST_AKAZE__H__
#define __TEST_AKAZE__H__
#include <napi.h>

#include <opencv2/opencv.hpp>

class AKAZEWrapper : public Napi::ObjectWrap<AKAZEWrapper> {
   public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    AKAZEWrapper(const Napi::CallbackInfo &info);

    static Napi::FunctionReference constructor;

   private:
    cv::Ptr<cv::AKAZE> akaze_;

    // Wrapped methods
    Napi::Value getDefaultName(const Napi::CallbackInfo &info);
    Napi::Value getDescriptorSize(const Napi::CallbackInfo &info);
    Napi::Value getDescriptorType(const Napi::CallbackInfo &info);
    Napi::Value setDescriptorSize(const Napi::CallbackInfo &info);
    Napi::Value setDescriptorType(const Napi::CallbackInfo &info);
    Napi::Value setThreshold(const Napi::CallbackInfo &info);
    Napi::Value setNOctaves(const Napi::CallbackInfo &info);
    Napi::Value setNOctaveLayers(const Napi::CallbackInfo &info);
    Napi::Value setDescriptorChannels(const Napi::CallbackInfo &info);
    Napi::Value setDiffusivity(const Napi::CallbackInfo &info);
    Napi::Value getNOctaves(const Napi::CallbackInfo &info);
    Napi::Value getThreshold(const Napi::CallbackInfo &info);
    Napi::Value getDiffusivity(const Napi::CallbackInfo &info);
    Napi::Value getNOctaveLayers(const Napi::CallbackInfo &info);
    Napi::Value getDescriptorChannels(const Napi::CallbackInfo &info);
    
    // Static methods
    static Napi::Value CreateStatic(const Napi::CallbackInfo &info);
};

static bool jsopencv_AKAZE_getp(Napi::Value *self, cv::Ptr<cv::AKAZE> *&dst);
Napi::Object InitAKAZE(Napi::Env env, Napi::Object exports);

#endif