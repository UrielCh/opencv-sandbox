#ifndef __TEST_FileNode__H__
#define __TEST_FileNode__H__
#include <napi.h>

#include <opencv2/opencv.hpp>

class FileNodeWrapper : public Napi::ObjectWrap<FileNodeWrapper> {
   public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    FileNodeWrapper(const Napi::CallbackInfo &info);
    FileNodeWrapper(const Napi::CallbackInfo &info, const cv::Ptr<cv::FileNode> &akaze);
    ~FileNodeWrapper();

    static Napi::FunctionReference constructor;

   cv::Ptr<cv::FileNode> cvdata;
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
