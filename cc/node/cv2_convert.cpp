




#include "cv2_convert.hpp"





//======================================================================================================================

using namespace cv;












//======================================================================================================================

// --- Mat

// special case, when the converter needs full ArgInfo structure
template<> // L:32
bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, bool& value, const ArgInfo& argInfo)
{







































































































































































































    return true;
}


template<> // L:239
Napi::Value nodeopencv_from(const Napi::CallbackInfo &info, const cv::Mat& m) {
    Napi::Env env = info.Env();
    Napi::Object obj = Napi::Object::New(env);
    size_t size = m.total() * m.elemSize();
    Napi::Buffer<uint8_t> buffer = Napi::Buffer<uint8_t>::New(env, m.data, size);
    obj.Set(Napi::String::New(env, "data"), buffer);
    obj.Set(Napi::String::New(env, "dims"), Napi::Number::New(env, m.dims));
    obj.Set(Napi::String::New(env, "rows"), Napi::Number::New(env, m.rows));
    obj.Set(Napi::String::New(env, "cols"), Napi::Number::New(env, m.cols));
    // contains type, depth, channels 
    obj.Set(Napi::String::New(env, "flags"), Napi::Number::New(env, m.flags));
    // flags as exploded data view
    obj.Set(Napi::String::New(env, "channels"), Napi::Number::New(env, m.channels()));
    obj.Set(Napi::String::New(env, "depth"), Napi::Number::New(env, m.depth()));
    obj.Set(Napi::String::New(env, "type"), Napi::Number::New(env, m.type()));
    return obj;
}
// --- bool // L:255
template<> // L:257
bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, bool& value, const ArgInfo& argInfo)
{
    // if (!obj || obj == NULL)
    if (obj->IsNull() || obj->IsUndefined())
    {
        return true;
    }
    if (obj->IsBoolean()) //  || PyArray_IsIntegerScalar(obj)
    {


        return obj->ToBoolean();

    }
    // Napi::TypeError::New(env, "Failed to parse boolean value").ThrowAsJavaScriptException();
    // return false;
    failmsg(info, "Argument '%s' is not convertable to bool", argInfo.name);
    return false;
}

template<>
Napi::Value nodeopencv_from(const Napi::CallbackInfo &info, const bool& value)
{
    return Napi::Boolean::New(info.Env(), value);
}

// --- ptr

// template<>
// bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, void*& ptr, const ArgInfo& argInfo)
// {
//     CV_UNUSED(info);
//     if (obj->IsNull() || obj->IsUndefined())
//         return true;
// 
//     if (!PyLong_Check(obj))
//         return false;
//     ptr = PyLong_AsVoidPtr(obj);
//     return ptr != NULL && !PyErr_Occurred();
// }
// 
// Napi::Value nodeopencv_from(const Napi::CallbackInfo &info, void*& ptr)
// {
//     return PyLong_FromVoidPtr(ptr);
// }

// -- Scalar

template<>
bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value *obj, Scalar& s, const ArgInfo& argInfo) {
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsArray()) {
        Napi::Array arr = obj->As<Napi::Array>();
        if (arr.Length() != 4) {
            failmsg(info, "Argument '%s' is not a valid size", argInfo.name);
            return false;
        }
        for (int i = 0; i < 4; i++) {
            Napi::Value v = arr.Get(i);
            if (!v.IsNumber()) {
                failmsg(info, "Argument '%s' is not a valid size", argInfo.name);
                return false;
            }
            s[i] = v.As<Napi::Number>().DoubleValue();
        }
        return true;
    }
    failmsg(info, "Argument '%s' is not a valid size", argInfo.name);
    return false;
}

template<>
Napi::Value nodeopencv_from(const Napi::CallbackInfo &info, const Scalar& src) {
    // return  {x: Number, y: Number, z: Number, w: Number}
    Napi::Env env = info.Env();
    // Napi::Object obj = Napi::Object::New(env);
    // obj.Set("x", Napi::Number::New(env, src[0]));
    // obj.Set("y", Napi::Number::New(env, src[1]));
    // obj.Set("z", Napi::Number::New(env, src[2]));
    // obj.Set("w", Napi::Number::New(env, src[3]));
    // as array of numbers
    Napi::Array arr = Napi::Array::New(env, 4);
    arr.Set((uint32_t)0, Napi::Number::New(env, src[0]));
    arr.Set(1, Napi::Number::New(env, src[2]));
    arr.Set(2, Napi::Number::New(env, src[3]));
    arr.Set(3, Napi::Number::New(env, src[4]));
    return arr;
    // return Py_BuildValue("(ii)", sz.width, sz.height);
}

// --- size_t

template<>
bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, size_t& value, const ArgInfo& argInfo) {
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsNumber()) {
        value = obj->ToNumber().Uint32Value();
        return true;
    }
    failmsg(info, "Argument '%s' is not convertable to size_t", argInfo.name);
    return false;
















































}

template<>
Napi::Value nodeopencv_from(const Napi::CallbackInfo &info, const size_t& value)
{
    return Napi::Number::New(info.Env(), value);
}

// --- int

template<>
bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, int& value, const ArgInfo& Arginfo) {
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsNumber()) {
        value = obj->ToNumber().Int32Value();
        return true;
    }
    failmsg(info, "Argument '%s' is not convertable to int", Arginfo.name);
    return false;
}












template<>
Napi::Value nodeopencv_from(const Napi::CallbackInfo &info, const int& value)
{
    return Napi::Number::New(info.Env(), value);
}

// --- int64

template<>
bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, int64& value, const ArgInfo& argInfo) {
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsNumber()) {
        value = obj->ToNumber().Int64Value();
        return true;
    }
    failmsg(info, "Argument '%s' is not convertable to int64", argInfo.name);
    return false;
}












template<>
Napi::Value nodeopencv_from(const Napi::CallbackInfo &info, const int64& value)
{
    return Napi::BigInt::New(info.Env(), value); // Number or bigint ??
}


// --- uchar

template<>
bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, uchar& value, const ArgInfo& argInfo) {
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsNumber()) {
        value = obj->ToNumber().Uint32Value();
        return true;
    }
    failmsg(info, "Argument '%s' is not convertable to uchar", argInfo.name);
    return false;
}
template<>
Napi::Value nodeopencv_from(const Napi::CallbackInfo &info, const uchar& value)
{
    return Napi::Number::New(info.Env(), value);
}
// --- char
template<>
bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, char& value, const ArgInfo& argInfo) {
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsNumber()) {
        value = obj->ToNumber().Int32Value();
        return true;
    }
    failmsg(info, "Argument '%s' is not convertable to char", argInfo.name);
    return false;
}













// --- double

template<>
bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, double& value, const ArgInfo& argInfo)
{
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsNumber()) {
        value = obj->ToNumber().DoubleValue();
        return true;
    }
    failmsg(info, "Argument '%s' is not convertable to double", argInfo.name);
    return false;
}

template<>
Napi::Value nodeopencv_from(const Napi::CallbackInfo &info, const double& value)
{
    return Napi::Number::New(info.Env(), value);
}

// --- float

template<>
bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, float& value, const ArgInfo& argInfo) {
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsNumber()) {
        value = obj->ToNumber().FloatValue();
        return true;
    }
    failmsg(info, "Argument '%s' is not convertable to float", argInfo.name);
    return false;
}

template<>
Napi::Value nodeopencv_from(const Napi::CallbackInfo &info, const float& value)
{
    return Napi::Number::New(info.Env(), value);
}

// --- string

template<>
bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, String &value, const ArgInfo& argInfo) {
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsString()) {
        value = obj->ToString().Utf8Value();
        return true;
    }
    failmsg(info, "Argument '%s' is not convertable to string", argInfo.name);
    return false;
}

template<>
Napi::Value nodeopencv_from(const Napi::CallbackInfo &info, const String& value) {
    if (value.empty())
        return Napi::String::New(info.Env(), "");
    return Napi::String::New(info.Env(), value);
    // return Napi::String::New(value.empty() ? emptyString : value);
}

// --- Size
/**
 * @brief read a Size from a Napi::Value
 * the size can be format as [Number, Number] or a {width: Number, height: Number}
 */
template<>
bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, Size& sz, const ArgInfo& argInfo) {
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsObject()) {
        Napi::Object arr = obj->As<Napi::Array>();
        auto v = arr.Get("width");
        if (!v.IsNumber()) {
            failmsg(info, "Argument '%s' is not a valid size, width is missing", argInfo.name);
            return false;
        }
        sz.width = v.As<Napi::Number>().Int32Value();

        auto v = arr.Get("height");
        if (!v.IsNumber()) {
            failmsg(info, "Argument '%s' is not a valid size, height is missing", argInfo.name);
            return false;
        }
        sz.height = v.As<Napi::Number>().Int32Value();
        return true;
    } else if (obj->IsArray()) {
        Napi::Array arr = obj->As<Napi::Array>();
        if (arr.Length() != 2) {
            failmsg(info, "Argument '%s' is not a valid size", argInfo.name);
            return false;
        }
        for (int i = 0; i < 2; i++) {
            Napi::Value v = arr.Get(i);
            if (!v.IsNumber()) {
                failmsg(info, "Argument '%s' is not a valid size", argInfo.name);
                return false;
            }
            if (i == 0)
                sz.width = v.As<Napi::Number>().Int32Value();
            else
                sz.height = v.As<Napi::Number>().Int32Value();
        }
        return true;
    }
    failmsg(info, "Argument '%s' is not a valid size", argInfo.name);
    return false;
}

template<>
Napi::Value nodeopencv_from(const Napi::CallbackInfo &info, const Size& sz) { // should I return an [Number, Number] or a {width: Number, height: Number}
    // return  {width: Number, height: Number}
    Napi::Env env = info.Env();
    Napi::Object obj = Napi::Object::New(env);
    obj.Set(Napi::String::New(env, "width"), Napi::Number::New(env, sz.width));
    obj.Set(Napi::String::New(env, "height"), Napi::Number::New(env, sz.height));
    return obj;
    // return Py_BuildValue("(ii)", sz.width, sz.height);
}

// --- float
// --- Rect
// --- Rect2d
// --- RotatedRect
// --- Range
// --- Point
// --- Point2f
// --- Point2d
// --- Point3f
// --- Point3d
// --- Vec4d
// --- Vec4f
// --- Vec4i
// --- Vec3d
// --- Vec3f
// --- Vec3i
// --- Vec2d
// --- Vec2i
// --- TermCriteria
// --- Moments
// --- pair
