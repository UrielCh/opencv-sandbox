#ifndef CV_MAT_OBJECT_ADDON_H
#define CV_MAT_OBJECT_ADDON_H

#include <napi.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

class cvMatAddon : public Napi::Addon<cvMatAddon>
{
public:
    cvMatAddon(Napi::Env env, Napi::Object exports)
    {
        DefineAddon(exports, {
                                 // InstanceAccessor("rows", &cvMatObject::Rows, nullptr)
                                 InstanceMethod("getRow", &cvMatAddon::getRow),
                                 InstanceMethod("getCols", &cvMatAddon::getCols),
                                 InstanceMethod("getType", &cvMatAddon::getType),
                             });
    }

    Napi::Value getRow(const Napi::CallbackInfo& info) {
        return Napi::Number::New(info.Env(), mat.rows);
    }
    Napi::Value getCols(const Napi::CallbackInfo& info) {
        return Napi::Number::New(info.Env(), mat.cols);
    }
    Napi::Value getType(const Napi::CallbackInfo& info) {
        return Napi::Number::New(info.Env(), mat.type());
    }
private:
    cv::Mat mat;
};

// std::cout << "calling NODE_API_ADDON(cvMatAddon)" << std::endl;
// std::cout << "calling NODE_API_ADDON(cvMatAddon)" << std::endl;

NODE_API_ADDON(cvMatAddon)

#endif