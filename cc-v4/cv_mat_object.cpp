#include "cv_mat_object.h"
#include <iostream>

int releaseCnt = 0;

Napi::FunctionReference cvMatObject::constructor;
// Napi::FunctionReference* constructor = new Napi::FunctionReference();

/**
 * @brief register the object with the node runtime
 * @return the incoming exports
 */
Napi::Object cvMatObject::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    // napi_property_attributes napi_default_method = static_cast<napi_property_attributes>(napi_writable | napi_configurable | napi_enumerable);
    napi_property_attributes napi_default_Field = static_cast<napi_property_attributes>(napi_enumerable | napi_configurable);
    
    Napi::Function func = DefineClass(env, "cvMatObject", {
        // InstanceAccessor("rows", &cvMatObject::Rows, &cvMatObject::ReadOnlySetter, napi_default_Field),
        cvMatObject::InstanceAccessor<&cvMatObject::Rows, &cvMatObject::ReadOnlySetter>("rows", napi_default_Field),

        InstanceAccessor("cols", &cvMatObject::Cols, &cvMatObject::ReadOnlySetter, napi_default_Field),
        InstanceAccessor("type", &cvMatObject::Type, &cvMatObject::ReadOnlySetter, napi_default_Field),
        InstanceAccessor("depth", &cvMatObject::Depth, &cvMatObject::ReadOnlySetter, napi_default_Field),
        InstanceAccessor("channels", &cvMatObject::Channels, &cvMatObject::ReadOnlySetter, napi_default_Field),

        InstanceAccessor("isContinuous", &cvMatObject::IsContinuous, &cvMatObject::ReadOnlySetter),
        InstanceAccessor("isSubmatrix", &cvMatObject::IsSubmatrix, &cvMatObject::ReadOnlySetter),
        InstanceAccessor("elemSize", &cvMatObject::ElemSize, &cvMatObject::ReadOnlySetter),
        InstanceAccessor("elemSize1", &cvMatObject::ElemSize1, &cvMatObject::ReadOnlySetter),

        // InstanceMethod<&cvMatObject::Release>("Release"),
        InstanceMethod("toString", &cvMatObject::ToString),
        // InstanceMethod("ownKeys", &cvMatObject::OwnKeys),
        // InstanceMethod("GetPropertyNames", &cvMatObject::OwnKeys),
        // InstanceMethod("GetPropertyNames", Napi::Function::New(env, &cvMatObject::OwnKeys)),
        // InstanceMethod<&cvMatObject::ToString>("toString"), // alternative syntax
        });


    // Napi::FunctionReference* constructor = new Napi::FunctionReference();
    // *constructor = Napi::Persistent(func);
    // env.SetInstanceData(constructor);

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    // Napi::Function toStringFunction = Napi::Function::New(env, ToString, "toString");
    // constructor.Value().As<Napi::Function>().Prototype().Set("toString", toStringFunction);

    exports.Set("cvMatObject", func);
    return exports;
}

Napi::Value cvMatObject::NewInstance(const Napi::CallbackInfo &info, const cv::Mat &m)
{
    // Napi::Env env = info.Env();
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
    // if (releaseCnt == 1)
    //     std::cout << "first mat released called" << std::endl;
    // if (releaseCnt == 2)
    //     std::cout << "Second mat released called following once will not be displayed" << std::endl;
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

Napi::Value cvMatObject::Depth(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
    return Napi::Number::New(env, mat.depth());
}

Napi::Value cvMatObject::Channels(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
    return Napi::Number::New(env, mat.channels());
}

Napi::Value cvMatObject::IsContinuous(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
    return Napi::Boolean::New(env, mat.isContinuous());
}

Napi::Value cvMatObject::IsSubmatrix(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
    return Napi::Boolean::New(env, mat.isSubmatrix());
}
Napi::Value cvMatObject::ElemSize(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
    return Napi::Number::New(env, mat.elemSize());

}
Napi::Value cvMatObject::ElemSize1(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
    return Napi::Number::New(env, mat.elemSize1());
}

Napi::Value cvMatObject::ToString(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    std::string objectRepresentation = "Matrix: " + std::to_string(mat.rows) + "x" + std::to_string(mat.cols) + " type:" + std::to_string(mat.type()) + " Channels:" + std::to_string(mat.channels()) + " ElemSize:" + std::to_string(mat.elemSize()) + " ElemSize1:" + std::to_string(mat.elemSize1());
    return Napi::String::New(env, objectRepresentation);
}


void cvMatObject::ReadOnlySetter(const Napi::CallbackInfo& info, const Napi::Value& value) {
    Napi::Env env = info.Env();
    Napi::Error::New(env, "Readonly Props").ThrowAsJavaScriptException();
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