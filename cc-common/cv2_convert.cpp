

#include "cv2_convert.h"

//======================================================================================================================

using namespace cv;

//======================================================================================================================

// --- Mat

// special case, when the converter needs full ArgInfo structure
template <>
bool jsopencv_to(const Napi::Value *obj, Mat &m, const ArgInfo &argInfo) {
    if (obj == nullptr || obj->IsNull() || obj->IsUndefined()) {
        // if (!m.data) m.allocator = &g_numpyAllocator;
        return true;
    }

    if (obj->IsNumber())
    {
        double v[] = {static_cast<double>(obj->ToNumber().DoubleValue()), 0., 0., 0.};
        m = Mat(4, 1, CV_64F, v).clone();
        return true;
    }

    if (obj->IsArray())
    { // PyTuple_Check
        Napi::Array arr = obj->As<Napi::Array>();
        int sz = arr.Length();
        m = Mat(sz, 1, CV_64F);
        for (int i = 0; i < sz; i++)
        {
            Napi::Value item = arr.Get(i);
            if (item.IsNumber())
            {
                m.at<double>(i) = item.ToNumber().DoubleValue();
            }
            else
            {
                failmsg(obj->Env(), "%s is not a numerical array", argInfo.name);
                m.release();
                return false;
            }
        }
        return true;
    }

    if (!obj->IsTypedArray())
    {
        failmsg(obj->Env(), "%s is not a typed array or scalar", argInfo.name);
        return false;
    }
    // Napi::TypedArray arr = obj->As<Napi::TypedArray>();
    // bool needcopy = false, needcast = false;
    // int typenum = -1, new_typenum = typenum;
    // int type = -1;
    // switch (arr.TypedArrayType())
    // {
    // case napi_uint8_array: typenum = NPY_UBYTE; type = CV_8U; break;
    // case napi_int8_array:  typenum = NPY_BYTE;  type = CV_8S; break;
    // case napi_uint16_array:typenum = NPY_USHORT;type = CV_16U;break;
    // case napi_int16_array: typenum = NPY_SHORT; type = CV_16S;break;
    // case napi_int32_array: typenum = NPY_INT;   type = CV_32S;break;
    // case napi_float32_array:typenum = NPY_FLOAT;type = CV_32F;break;
    // case napi_float64_array:typenum = NPY_DOUBLE;type = CV_64F;break;
    // default:
    //     failmsg(obj->Env(), "%s data type is not supported", argInfo.name);
    //     return false;
    // }
    // TypedArrayContents<double> arr = obj->As<TypedArray>().As<DoubleArray>();
    // size_t sz = arr.ByteLength() / sizeof(double);
    //
    // m = Mat(sz, 1, CV_64F);
    // double* data = m.ptr<double>(0);
    // for (size_t i = 0; i < sz; i++) {
    //     data[i] = arr[i];
    // }
    //
    // if (!obj->IsExternal()) {
    //     m.u = g_numpyAllocator.allocate(obj, 1, &sz, CV_64F, NULL);
    // }
    // m.addref();
    // m.allocator = &g_numpyAllocator;
    return false;
}







template <> // L:239
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Mat &m)
{
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
template <> // L:257
bool jsopencv_to(const Napi::Value *obj, bool &value, const ArgInfo &argInfo)
{
    // if (!obj || obj == NULL)
    if (obj->IsNull() || obj->IsUndefined())
    {
        return true;
    }
    if (obj->IsBoolean()) //  || JsArray_IsIntegerScalar(obj)
    {

        return obj->ToBoolean();
    }
    // Napi::TypeError::New(env, "Failed to parse boolean value").ThrowAsJavaScriptException();
    // return false;
    failmsg(obj->Env(), "Argument '%s' is not convertable to bool", argInfo.name);
    return false;
}

template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const bool &value)
{
    return Napi::Boolean::New(info.Env(), value);
}

// --- ptr

// template<>
// bool jsopencv_to(const Napi::Value* obj, void*& ptr, const ArgInfo& argInfo)
// {
//     CV_UNUSED(info);
//     if (obj->IsNull() || obj->IsUndefined())
//         return true;
//
//     if (!JsLong_Check(obj))
//         return false;
//     ptr = JsLong_AsVoidPtr(obj);
//     return ptr != NULL && !JsErr_Occurred();
// }
//
// Napi::Value jsopencv_from(const Napi::CallbackInfo &info, void*& ptr)
// {
//     return JsLong_FromVoidPtr(ptr);
// }

// -- Scalar

template <>
bool jsopencv_to(const Napi::Value *obj, Scalar &s, const ArgInfo &argInfo)
{
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsArray())
    {
        Napi::Array arr = obj->As<Napi::Array>();
        if (arr.Length() != 4)
        {
            failmsg(obj->Env(), "Argument '%s' is not a valid size", argInfo.name);
            return false;
        }
        for (int i = 0; i < 4; i++)
        {
            Napi::Value v = arr.Get(i);
            if (!v.IsNumber())
            {
                failmsg(obj->Env(), "Argument '%s' is not a valid size", argInfo.name);
                return false;
            }
            s[i] = v.As<Napi::Number>().DoubleValue();
        }
        return true;
    }
    failmsg(obj->Env(), "Argument '%s' is not a valid size", argInfo.name);
    return false;
}

template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const Scalar &src)
{
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
    // return Js_BuildValue("(ii)", sz.width, sz.height);
}

// --- size_t

template <>
bool jsopencv_to(const Napi::Value *obj, size_t &value, const ArgInfo &argInfo)
{
    if (!obj || obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsNumber())
    {
        value = obj->ToNumber().Uint32Value();
        // value = static_cast<size_t>(static_cast<int64_t>(num));
        return true;
    }
    failmsg(obj->Env(), "Argument '%s' is not convertable to size_t", argInfo.name);
    return false;
}

template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const size_t &value)
{
    return Napi::Number::New(info.Env(), value);
}

// --- int

template <>
bool jsopencv_to(const Napi::Value *obj, int &value, const ArgInfo &Arginfo)
{
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsNumber())
    {
        value = obj->ToNumber().Int32Value();
        return true;
    }
    failmsg(obj->Env(), "Argument '%s' is not convertable to int", Arginfo.name);
    return false;
}

template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const int &value)
{
    return Napi::Number::New(info.Env(), value);
}

// --- int64

template <>
bool jsopencv_to(const Napi::Value *obj, int64 &value, const ArgInfo &argInfo)
{
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsNumber())
    {
        value = obj->ToNumber().Int64Value();
        return true;
    }
    failmsg(obj->Env(), "Argument '%s' is not convertable to int64", argInfo.name);
    return false;
}

template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const int64 &value)
{
    return Napi::BigInt::New(info.Env(), value); // Number or bigint ??
}

// --- uchar

template <>
bool jsopencv_to(const Napi::Value *obj, uchar &value, const ArgInfo &argInfo)
{
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsNumber())
    {
        value = obj->ToNumber().Uint32Value();
        return true;
    }
    failmsg(obj->Env(), "Argument '%s' is not convertable to uchar", argInfo.name);
    return false;
}
template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const uchar &value)
{
    return Napi::Number::New(info.Env(), value);
}
// --- char
template <>
bool jsopencv_to(const Napi::Value *obj, char &value, const ArgInfo &argInfo)
{
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsNumber())
    {
        value = obj->ToNumber().Int32Value();
        return true;
    }
    failmsg(obj->Env(), "Argument '%s' is not convertable to char", argInfo.name);
    return false;
}

// --- double

template <>
bool jsopencv_to(const Napi::Value *obj, double &value, const ArgInfo &argInfo)
{
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsNumber())
    {
        value = obj->ToNumber().DoubleValue();
        return true;
    }
    failmsg(obj->Env(), "Argument '%s' is not convertable to double", argInfo.name);
    return false;
}

template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const double &value)
{
    return Napi::Number::New(info.Env(), value);
}

// --- float

template <>
bool jsopencv_to(const Napi::Value *obj, float &value, const ArgInfo &argInfo)
{
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsNumber())
    {
        value = obj->ToNumber().FloatValue();
        return true;
    }
    failmsg(obj->Env(), "Argument '%s' is not convertable to float", argInfo.name);
    return false;
}

template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const float &value)
{
    return Napi::Number::New(info.Env(), value);
}

// --- string

template <>
bool jsopencv_to(const Napi::Value *obj, String &value, const ArgInfo &argInfo)
{
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsString())
    {
        value = obj->ToString().Utf8Value();
        return true;
    }
    failmsg(obj->Env(), "Argument '%s' is not convertable to string", argInfo.name);
    return false;
}

template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const String &value)
{
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
template <>
bool jsopencv_to(const Napi::Value *obj, Size &sz, const ArgInfo &argInfo)
{
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsObject())
    {
        Napi::Object arr = obj->As<Napi::Array>();
        Napi::Value v = arr.Get("width");
        if (!v.IsNumber())
        {
            failmsg(obj->Env(), "Argument '%s' is not a valid size, width is missing", argInfo.name);
            return false;
        }
        sz.width = v.As<Napi::Number>().Int32Value();

        Napi::Value v2 = arr.Get("height");
        if (!v2.IsNumber())
        {
            failmsg(obj->Env(), "Argument '%s' is not a valid size, height is missing", argInfo.name);
            return false;
        }
        sz.height = v2.As<Napi::Number>().Int32Value();
        return true;
    }
    else if (obj->IsArray())
    {
        Napi::Array arr = obj->As<Napi::Array>();
        if (arr.Length() != 2)
        {
            failmsg(obj->Env(), "Argument '%s' is not a valid size", argInfo.name);
            return false;
        }
        for (int i = 0; i < 2; i++)
        {
            Napi::Value v = arr.Get(i);
            if (!v.IsNumber())
            {
                failmsg(obj->Env(), "Argument '%s' is not a valid size", argInfo.name);
                return false;
            }
            if (i == 0)
                sz.width = v.As<Napi::Number>().Int32Value();
            else
                sz.height = v.As<Napi::Number>().Int32Value();
        }
        return true;
    }
    failmsg(obj->Env(), "Argument '%s' is not a valid size", argInfo.name);
    return false;
}

/**
 * @brief convert a cv::Size to a Napi::Array
 * 
 * Python style size return a tuple (width, height)
 * We may prefer to return a {width: Number, height: Number} object
 */
template<>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const Size &sz)
{
    // Napi::Env env = info.Env();
    // Napi::Object obj = Napi::Object::New(env);
    // obj.Set(Napi::String::New(env, "width"), Napi::Number::New(env, sz.width));
    // obj.Set(Napi::String::New(env, "height"), Napi::Number::New(env, sz.height));
    // return obj;
    return Js_BuildValue(info, "(ii)", sz.width, sz.height);
}
// --- float
template<>
bool jsopencv_to(const Napi::Value* obj, Size_<float>& sz, const ArgInfo& info)
{
    RefWrapper<float> values[] = {RefWrapper<float>(sz.width),
                                  RefWrapper<float>(sz.height)};
    return JsParseSequence(obj, values, info);
}

template<>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const Size_<float>& sz)
{
    return Js_BuildValue(info, "(ff)", sz.width, sz.height);
}

// --- Rect

template<>
bool jsopencv_to(const Napi::Value* obj, Rect& r, const ArgInfo& info)
{
    RefWrapper<int> values[] = {RefWrapper<int>(r.x), RefWrapper<int>(r.y),
                                RefWrapper<int>(r.width),
                                RefWrapper<int>(r.height)};
    return JsParseSequence(obj, values, info);
}

template<>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const Rect& r)
{
    return Js_BuildValue(info, "(iiii)", r.x, r.y, r.width, r.height);
}

template<>
bool jsopencv_to(const Napi::Value* obj, Rect2d& r, const ArgInfo& info)
{
    RefWrapper<double> values[] = {
        RefWrapper<double>(r.x), RefWrapper<double>(r.y),
        RefWrapper<double>(r.width), RefWrapper<double>(r.height)};
    return JsParseSequence(obj, values, info);
}

template<>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const Rect2d& r)
{
    return Js_BuildValue(info, "(dddd)", r.x, r.y, r.width, r.height);
}

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
