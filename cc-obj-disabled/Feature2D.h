
#ifndef __TEST_Feature2D__H__
#define __TEST_Feature2D__H__
#include <napi.h>

#include <opencv2/opencv.hpp>

class Feature2DWrapper : public Napi::ObjectWrap<Feature2DWrapper> {
   public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    Feature2DWrapper(const Napi::CallbackInfo &info);
    Feature2DWrapper(const Napi::CallbackInfo &info, const cv::Ptr<cv::Feature2D> &akaze);
    ~Feature2DWrapper();

    static Napi::FunctionReference constructor;

   cv::Ptr<cv::Feature2D> cvdata;
   // present in all warppers to check types
   static Napi::Symbol typeSymbol;

   private:

    // Wrapped methods
    Napi::Value compute(const Napi::CallbackInfo &info);
    Napi::Value defaultNorm(const Napi::CallbackInfo &info);
    Napi::Value descriptorSize(const Napi::CallbackInfo &info);
    Napi::Value descriptorType(const Napi::CallbackInfo &info);
    Napi::Value detect(const Napi::CallbackInfo &info);
    Napi::Value detectAndCompute(const Napi::CallbackInfo &info);
    Napi::Value empty(const Napi::CallbackInfo &info);
    Napi::Value getDefaultName(const Napi::CallbackInfo &info);
    Napi::Value read(const Napi::CallbackInfo &info);
    Napi::Value write(const Napi::CallbackInfo &info);


    // Static methods
    // static Napi::Value CreateStatic(const Napi::CallbackInfo &info);
};

#endif
