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
        std::cout << "cvMatAddon init called" << std::endl;
        DefineAddon(exports, {
                                 InstanceMethod("increment", &cvMatAddon::Increment),
                                 // InstanceAccessor("rows", &cvMatAddon::GetterRows, nullptr),
                                 // InstanceMethod("getRow", &cvMatAddon::getRow),
                                 // InstanceMethod("getCols", &cvMatAddon::getCols),
                                 // InstanceMethod("getType", &cvMatAddon::getType),
                             });
        std::cout << "cvMatAddon DefineAddon done" << std::endl;
    }

    Napi::Value getRow(const Napi::CallbackInfo &info)
    {
        return Napi::Number::New(info.Env(), mat.rows);
    }
    Napi::Value getCols(const Napi::CallbackInfo &info)
    {
        return Napi::Number::New(info.Env(), mat.cols);
    }
    Napi::Value getType(const Napi::CallbackInfo &info)
    {
        return Napi::Number::New(info.Env(), mat.type());
    }
    Napi::Value GetterRows(const Napi::CallbackInfo &info)
    {
        return Napi::Number::New(info.Env(), mat.rows);
    }
    Napi::Value Increment(const Napi::CallbackInfo &info)
    {
        return Napi::Number::New(info.Env(), ++value);
    }

    void Setter(const Napi::CallbackInfo &info, const Napi::Value &val)
    {
        // (void)info[0];
        // (void)val;
    }

private:
    cv::Mat mat;
    uint32_t value = 42;
};

// inline Napi::Object Napi::Addon<cvMatAddon>::Init(Napi::Env env, Napi::Object exports) {
//
// }
// NODE_API_ADDON(cvMatAddon)

static napi_value __napi_cvMatAddon(napi_env env, napi_value exports)
{
    std::cout << "Napi::RegisterModule" << std::endl;
    return Napi::RegisterModule(env, exports, &cvMatAddon::Init);
}
extern "C"
{
    static napi_module _module = {1, 0, __FILE__, __napi_cvMatAddon, "NODE_GYP_MODULE_NAME", 0, {0}};
    static void __cdecl _register_NODE_GYP_MODULE_NAME(void);
    namespace
    {
        struct _register_NODE_GYP_MODULE_NAME_
        {
            _register_NODE_GYP_MODULE_NAME_() { _register_NODE_GYP_MODULE_NAME(); }
        } _register_NODE_GYP_MODULE_NAME_v_;
    }
    static void __cdecl _register_NODE_GYP_MODULE_NAME(void) { napi_module_register(&_module); }
}

#endif