#include "cv_mat_object.h"
#include <iostream>

int releaseCnt = 0;

// namespace cvMatObject

Napi::FunctionReference cvMatObject::constructor;

/**
 * @brief register the object with the node runtime
 * @return the incomming exports
 */
Napi::Object cvMatObject::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);

    Napi::Function func = DefineClass(env, "cvMatObject", {
        InstanceAccessor("rows", &cvMatObject::Rows, nullptr),
        InstanceAccessor("cols", &cvMatObject::Cols, nullptr),
        InstanceAccessor("type", &cvMatObject::Type, nullptr),
        // InstanceMethod<&cvMatObject::Release>("Release"),
        InstanceMethod("toString", &cvMatObject::ToString),
        // InstanceMethod("ownKeys", &cvMatObject::OwnKeys),
        InstanceMethod("GetPropertyNames", &cvMatObject::OwnKeys),
        // InstanceMethod("GetPropertyNames", Napi::Function::New(env, &cvMatObject::OwnKeys)),
        // InstanceMethod<&cvMatObject::ToString>("toString"), // alternative syntax
        });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    // Napi::Function toStringFunction = Napi::Function::New(env, ToString, "toString");
    // constructor.Value().As<Napi::Function>().Prototype().Set("toString", toStringFunction);

    exports.Set("cvMatObject", func);
    return exports;
}

Napi::Value cvMatObject::NewInstance(const Napi::CallbackInfo &info, const cv::Mat &m)
{
    Napi::Env env = info.Env();
    Napi::Value cvMatObj = constructor.New({});
    cvMatObject *cvMatInstance = Napi::ObjectWrap<cvMatObject>::Unwrap(cvMatObj.As<Napi::Object>());
    cvMatInstance->mat = m;
    return cvMatObj;
}

cvMatObject::cvMatObject(const Napi::CallbackInfo &info) : Napi::ObjectWrap<cvMatObject>(info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int length = info.Length();

    if (length == 0)
    {
        mat = cv::Mat();
        // std::cout << "allocating mat with default constructor" << std::endl;
    }
    else if (length == 2)
    {
        int rows = info[0].As<Napi::Number>().Int32Value();
        int cols = info[1].As<Napi::Number>().Int32Value();
        // std::cout << "allocating mat (" << rows << ", "<< cols << ")" << std::endl;
        mat = cv::Mat(rows, cols, CV_8UC1);
    }
    else
    {
        Napi::TypeError::New(env, "Invalid arguments, expected 0 or 2 arguments").ThrowAsJavaScriptException();
    }
}

cvMatObject::cvMatObject(const Napi::CallbackInfo &info, cv::Mat &matIn) : Napi::ObjectWrap<cvMatObject>(info)
{
    mat = matIn;
}

cvMatObject::~cvMatObject()
{
    releaseCnt++;
    if (releaseCnt == 1)
        std::cout << "first mat released called" << std::endl;
    if (releaseCnt == 2)
        std::cout << "Second mat released called following once will not be displayed" << std::endl;
    mat.release();
}

Napi::Value cvMatObject::Rows(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    return Napi::Number::New(env, mat.rows);
}

Napi::Value cvMatObject::Cols(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    return Napi::Number::New(env, mat.cols);
}

Napi::Value cvMatObject::Type(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    return Napi::Number::New(env, mat.type());
}

Napi::Value cvMatObject::ToString(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    std::string objectRepresentation = "Matrix: " + std::to_string(mat.rows) + "x" + std::to_string(mat.cols) + " type: " + std::to_string(mat.type()) + "";
    return Napi::String::New(env, objectRepresentation);
}

Napi::Value cvMatObject::OwnKeys(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
    Napi::Array keys = Napi::Array::New(env, 3);
    keys.Set((uint32_t)0, Napi::String::New(env, "rows"));
    keys.Set((uint32_t)1, Napi::String::New(env, "cols"));
    keys.Set((uint32_t)2, Napi::String::New(env, "type"));
    // arr.Set(0, Napi::String::New(env, "rows"));
    // keys[(uint32_t)0] = "rows";
    // keys[(uint32_t)1] = "cols";
    // keys[(uint32_t)2] = "type";
    return keys;
}

// Napi::Value cvMatObject::Release(const Napi::CallbackInfo& info) {
//     Napi::Env env = info.Env();
//     Napi::HandleScope scope(env);
//
//     mat.release();
//     // std::cout << "mat released" << std::endl;
//     return env.Undefined();
// }