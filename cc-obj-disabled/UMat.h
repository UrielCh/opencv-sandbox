
#ifndef __TEST_UMat__H__
#define __TEST_UMat__H__
#include <napi.h>

#include <opencv2/opencv.hpp>

class UMatWrapper : public Napi::ObjectWrap<UMatWrapper> {
   public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    UMatWrapper(const Napi::CallbackInfo &info);
    UMatWrapper(const Napi::CallbackInfo &info, const cv::Ptr<cv::UMat> &akaze);
    ~UMatWrapper();

    static Napi::FunctionReference constructor;

   cv::Ptr<cv::UMat> cvdata;
   // present in all warppers to check types
   static Napi::Symbol typeSymbol;

   private:
    // import from Tables (UMat) black in jsopencv_generated_types_content.h
    // Wrapped getters
    Napi::Value get_offset(const Napi::CallbackInfo &info);

    // Wrapped methods
    Napi::Value get(const Napi::CallbackInfo &info);
    Napi::Value handle(const Napi::CallbackInfo &info);
    Napi::Value isContinuous(const Napi::CallbackInfo &info);
    Napi::Value isSubmatrix(const Napi::CallbackInfo &info);

    // Static methods
    // static Napi::Value CreateStatic(const Napi::CallbackInfo &info);
    static Napi::Value context(const Napi::CallbackInfo &info);
    static Napi::Value queue(const Napi::CallbackInfo &info);
};

#endif
