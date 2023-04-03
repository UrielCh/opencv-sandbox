#ifndef CV_MAT_OBJECT_H
#define CV_MAT_OBJECT_H

#include <napi.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

class cvMatObject : public Napi::ObjectWrap<cvMatObject> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    cvMatObject(const Napi::CallbackInfo& info);
    cvMatObject(const Napi::CallbackInfo& info, cv::Mat& mat);
    ~cvMatObject();

    static Napi::Value NewInstance(const Napi::CallbackInfo &info, const cv::Mat& m);

private:
    static Napi::FunctionReference constructor;
    cv::Mat mat;

    Napi::Value Rows(const Napi::CallbackInfo& info);
    Napi::Value Cols(const Napi::CallbackInfo& info);
    Napi::Value Type(const Napi::CallbackInfo& info);
    // Napi::Value Release(const Napi::CallbackInfo& info);
};

#endif