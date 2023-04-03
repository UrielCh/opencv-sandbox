#include "cv_mat_object.h"
#include <iostream>

Napi::FunctionReference cvMatObject::constructor;

int releaseCnt = 0;

/**
 * @brief register the object with the node runtime
 */
Napi::Object cvMatObject::Init(Napi::Env env, Napi::Object exports) {
    Napi::HandleScope scope(env);

    Napi::Function func = DefineClass(env, "cvMatObject", {
        InstanceAccessor("rows", &cvMatObject::Rows, nullptr),
        InstanceAccessor("cols", &cvMatObject::Cols, nullptr),
        InstanceAccessor("type", &cvMatObject::Type, nullptr),
        // InstanceMethod<&cvMatObject::Release>("Release"),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    exports.Set("cvMatObject", func);
    return exports;
}

cvMatObject::cvMatObject(const Napi::CallbackInfo& info) : Napi::ObjectWrap<cvMatObject>(info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int length = info.Length();

    if (length == 0) {
        mat = cv::Mat();
        // std::cout << "allocating mat with default constructor" << std::endl;
    } else if (length == 2) {
        int rows = info[0].As<Napi::Number>().Int32Value();
        int cols = info[1].As<Napi::Number>().Int32Value();
        // std::cout << "allocating mat (" << rows << ", "<< cols << ")" << std::endl;
        mat = cv::Mat(rows, cols, CV_8UC1);
    } else {
        Napi::TypeError::New(env, "Invalid arguments, expected 0 or 2 arguments").ThrowAsJavaScriptException();
    }
}

cvMatObject::~cvMatObject() {
  releaseCnt++;
  if (releaseCnt == 1)
    std::cout << "first mat released called" << std::endl;
  if (releaseCnt == 2)
    std::cout << "Second mat released called following once will not be displayed" << std::endl;
  mat.release();
}

Napi::Value cvMatObject::Rows(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    return Napi::Number::New(env, mat.rows);
}

Napi::Value cvMatObject::Cols(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    return Napi::Number::New(env, mat.cols);
}

Napi::Value cvMatObject::Type(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    return Napi::Number::New(env, mat.type());
}

// Napi::Value cvMatObject::Release(const Napi::CallbackInfo& info) {
//     Napi::Env env = info.Env();
//     Napi::HandleScope scope(env);
// 
//     mat.release();
//     // std::cout << "mat released" << std::endl;
//     return env.Undefined();
// }