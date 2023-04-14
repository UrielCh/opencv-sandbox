#include "cv2_convert.h"










//======================================================================================================================

using namespace cv;

//======================================================================================================================

// --- Mat

// special case, when the converter needs full ArgInfo structure
template <>
bool jsopencv_to(const Napi::Value *obj_value, cv::Mat &m, const ArgInfo &argInfo)
{
    if (obj_value->IsNull() || obj_value->IsUndefined())
    {
        return true;
    }
    if (obj_value->IsObject())
    {
        Napi::Object jsMat = obj_value->ToObject();
        Napi::Value dimsValue = jsMat.Get("dims");
        Napi::Value sizesValue = jsMat.Get("sizes");
        Napi::Value typeValue = jsMat.Get("type");
        Napi::Value dataValue = jsMat.Get("data");

        if (!dimsValue.IsNumber() || !sizesValue.IsArray() || !typeValue.IsNumber() || !dataValue.IsBuffer())
        {
            jsfailmsg(obj_value->Env(), "Argument '%s' is not a valid Mat object", argInfo.name);
            return false;
        }

        int dims = dimsValue.ToNumber().Int32Value();
        Napi::Array sizesArray = sizesValue.As<Napi::Array>();
        std::vector<int> sizes;
        for (uint32_t i = 0; i < sizesArray.Length(); ++i)
        {
            sizes.push_back(sizesArray.Get(i).ToNumber().Int32Value());
        }

        int type = typeValue.ToNumber().Int32Value();
        Napi::Buffer<uint8_t> data = dataValue.As<Napi::Buffer<uint8_t>>();

        m = cv::Mat(dims, sizes.data(), type, data.Data());
        return true;
    }

    jsfailmsg(obj_value->Env(), "Argument '%s' is not convertable to cv::Mat", argInfo.name);
    return false;
}






const char * getTypeString(const Napi::Value *obj) {
    auto type = "";
    switch (obj->Type())
    {
        case napi_undefined: type = "undefined"; break;
        case napi_null: type = "null"; break;
        case napi_boolean: type = "boolean"; break;
        case napi_number: type = "number"; break;
        case napi_string: type = "string"; break;
        case napi_symbol: type = "symbol"; break;
        case napi_object: type = "object"; break;
        case napi_function: type = "function"; break;
        case napi_external: type = "external"; break;
        case napi_bigint: type = "napi_bigint"; break;
        default: type = "unknown"; break;
    }
    return type;
}
















































































































































template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Mat &m)
{
    Napi::Env env = info.Env();
    Napi::Object jsMat = Napi::Object::New(env);

    jsMat.Set("dims", Napi::Number::New(env, m.dims));

    Napi::Array sizesArray = Napi::Array::New(env, m.dims);
    for (int i = 0; i < m.dims; ++i)
    {
        sizesArray.Set(i, Napi::Number::New(env, m.size[i]));
    }
    jsMat.Set("sizes", sizesArray);

    jsMat.Set("type", Napi::Number::New(env, m.type()));
    jsMat.Set("data", Napi::Buffer<uint8_t>::Copy(env, m.data, m.total() * m.elemSize()));
    // Debug only TODO REmove later
    jsMat.Set("rows", Napi::Number::New(env, m.rows));
    jsMat.Set("cols", Napi::Number::New(env, m.cols));
    jsMat.Set("channels", Napi::Number::New(env, m.channels()));

    return jsMat;
}



// --- bool

template<>
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
    jsfailmsg(obj->Env(), "Argument '%s' is not convertable to bool", argInfo.name);
    return false;
}



template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const bool &value)
{
    return Napi::Boolean::New(info.Env(), value);
}

// --- ptr

template<>
bool jsopencv_to(const Napi::Value* obj, void*& ptr, const ArgInfo& info)
{
    CV_UNUSED(info);
    if (!obj || obj->IsNull() || obj->IsUndefined())
        return true;
    if (!obj->IsNumber())
        return false;
    int64_t num = obj->As<Napi::Number>().Int64Value();
    ptr = reinterpret_cast<void*>(num);
    return ptr != nullptr;
}
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, void*& ptr)
{
    int64_t num = reinterpret_cast<int64_t>(ptr);
    return Napi::Number::New(info.Env(), num);
}

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
            jsfailmsg(obj->Env(), "Argument '%s' is not a valid size", argInfo.name);
            return false;
        }
        for (int i = 0; i < 4; i++)
        {
            Napi::Value v = arr.Get(i);
            if (!v.IsNumber())
            {
                jsfailmsg(obj->Env(), "Argument '%s' is not a valid size", argInfo.name);
                return false;
            }
            s[i] = v.As<Napi::Number>().DoubleValue();
        }
        return true;
    }
    jsfailmsg(obj->Env(), "Argument '%s' is not a valid size", argInfo.name);
    return false;
}

template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const Scalar &src)
{   // return  {x: Number, y: Number, z: Number, w: Number}
    Napi::Env env = info.Env(); Napi::Array arr = Napi::Array::New(env, 4);
    arr.Set((uint32_t)0, Napi::Number::New(env, src[0]));
    arr.Set(1, Napi::Number::New(env, src[2]));
    arr.Set(2, Napi::Number::New(env, src[3]));
    arr.Set(3, Napi::Number::New(env, src[4]));
    return arr; // return Js_BuildValue("(iiii)", sz.width, sz.height);
}
// --- size_t
template <>
bool jsopencv_to(const Napi::Value *obj, size_t &value, const ArgInfo &argInfo)
{
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsNumber())
    {
        value = obj->ToNumber().Uint32Value();
        // value = static_cast<size_t>(static_cast<int64_t>(num));
        return true;
    }
    jsfailmsg(obj->Env(), "Argument '%s' is not convertable to size_t", argInfo.name);
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
    jsfailmsg(obj->Env(), "Argument '%s' is not convertable to int", Arginfo.name);
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
    jsfailmsg(obj->Env(), "Argument '%s' is not convertable to int64", argInfo.name);
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
    if (obj->IsNull() || obj->IsUndefined()) return true;

    if (obj->IsNumber()) {
        value = obj->ToNumber().Uint32Value();
        return true;
    }
    jsfailmsg(obj->Env(), "Argument '%s' is not convertable to uchar", argInfo.name);
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
    jsfailmsg(obj->Env(), "Argument '%s' is not convertable to char", argInfo.name);
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
    jsfailmsg(obj->Env(), "Argument '%s' is not convertable to double", argInfo.name);
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
    jsfailmsg(obj->Env(), "Argument '%s' is not convertable to float", argInfo.name);
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
    jsfailmsg(obj->Env(), "Argument '%s' is not convertable to string", argInfo.name);
    return false;
















}

template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::String &value)
{
    if (value.empty())
        return Napi::String::New(info.Env(), "");
    return Napi::String::New(info.Env(), value);// return Napi::String::New(value.empty() ? emptyString : value);
}
//  cv::String === std::string






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
            jsfailmsg(obj->Env(), "Argument '%s' is not a valid size, width is missing", argInfo.name);
            return false;
        }
        sz.width = v.As<Napi::Number>().Int32Value();

        Napi::Value v2 = arr.Get("height");
        if (!v2.IsNumber())
        {
            jsfailmsg(obj->Env(), "Argument '%s' is not a valid size, height is missing", argInfo.name);
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
            jsfailmsg(obj->Env(), "Argument '%s' is not a valid size", argInfo.name);
            return false;
        }
        for (int i = 0; i < 2; i++)
        {
            Napi::Value v = arr.Get(i);
            if (!v.IsNumber())
            {
                jsfailmsg(obj->Env(), "Argument '%s' is not a valid size", argInfo.name);
                return false;
            }
            if (i == 0)
                sz.width = v.As<Napi::Number>().Int32Value();
            else
                sz.height = v.As<Napi::Number>().Int32Value();
        }
        return true;
    }
    jsfailmsg(obj->Env(), "Argument '%s' is not a valid size", argInfo.name);
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
template<>
bool jsopencv_to(const Napi::Value *obj, cv::RotatedRect &dst, const ArgInfo &argInfo)
{
    if (obj->IsNull() || obj->IsUndefined())
    {
        return true;
    }
    if (!obj->IsObject())
    {
        jsfailmsg(obj->Env(), "Can't parse '%s' as RotatedRect. Input argument is not an object", argInfo.name);
        return false;
    }

    Napi::Object rotatedRectObj = obj->As<Napi::Object>();
    Napi::Value centerValue = rotatedRectObj.Get("center");
    Napi::Value sizeValue = rotatedRectObj.Get("size");
    Napi::Value angleValue = rotatedRectObj.Get("angle");

    if (!centerValue.IsObject() || !sizeValue.IsObject() || !angleValue.IsNumber())
    {
        jsfailmsg(obj->Env(), "Can't parse '%s' as RotatedRect. Invalid object structure", argInfo.name);
        return false;
    }

    cv::Point2f center;
    cv::Size2f size;
    float angle;

    {
        const ArgInfo centerArgInfo("center", false);
        if (!jsopencv_to(&centerValue, center, centerArgInfo))
        {
            return false;
        }
    }
    {
        const ArgInfo sizeArgInfo("size", false);
        if (!jsopencv_to(&sizeValue, size, sizeArgInfo))
        {
            return false;
        }
    }

    angle = angleValue.ToNumber().FloatValue();
    dst = cv::RotatedRect(center, size, angle);
    return true;
}

template<>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::RotatedRect &src)
{
    Napi::Env env = info.Env();
    Napi::Object rotatedRectObj = Napi::Object::New(env);

    Napi::Object centerObj = Napi::Object::New(env);
    centerObj.Set("x", Napi::Number::New(env, src.center.x));
    centerObj.Set("y", Napi::Number::New(env, src.center.y));

    Napi::Object sizeObj = Napi::Object::New(env);
    sizeObj.Set("width", Napi::Number::New(env, src.size.width));
    sizeObj.Set("height", Napi::Number::New(env, src.size.height));

    rotatedRectObj.Set("center", centerObj);
    rotatedRectObj.Set("size", sizeObj);
    rotatedRectObj.Set("angle", Napi::Number::New(env, src.angle));

    return rotatedRectObj;
}

// --- Range
template<>
bool jsopencv_to(const Napi::Value *obj, cv::Range &r, const ArgInfo &argInfo)
{
    if (obj->IsNull() || obj->IsUndefined())
    {
        return true;
    }
    
    Napi::Env env = obj->Env();
    if (!obj->IsArray())
    {
        jsfailmsg(env, "Can't parse '%s' as Range. Input argument is not an array", argInfo.name);
        return false;
    }

    Napi::Array rangeArray = obj->As<Napi::Array>();
    if (rangeArray.Length() == 0)
    {
        r = cv::Range::all();
        return true;
    }
    else if (rangeArray.Length() == 2)
    {
        r.start = rangeArray.Get((uint32_t)0).ToNumber().Int32Value();
        r.end = rangeArray.Get((uint32_t)1).ToNumber().Int32Value();
        return true;
    }
    else
    {
        jsfailmsg(env, "Can't parse '%s' as Range. Expected array of length 0 or 2", argInfo.name);
        return false;
    }
}

// --- Point
template<>
bool jsopencv_to(const Napi::Value *obj_value, cv::Point &p, const ArgInfo &argInfo)
{
    Napi::Object obj = obj_value->As<Napi::Object>();
    if (obj.Has("x") && obj.Has("y"))
    {
        p.x = obj.Get("x").As<Napi::Number>().Int32Value();
        p.y = obj.Get("y").As<Napi::Number>().Int32Value();
        return true;
    }
    return false;
}

template<>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Point &p)
{
    Napi::Object obj = Napi::Object::New(info.Env());
    obj.Set("x", p.x);
    obj.Set("y", p.y);
    return obj;
}

// --- Point2f
template<>
bool jsopencv_to(const Napi::Value *obj_value, cv::Point2f &p, const ArgInfo &argInfo)
{
    Napi::Object obj = obj_value->As<Napi::Object>();
    if (obj.Has("x") && obj.Has("y"))
    {
        p.x = obj.Get("x").As<Napi::Number>().FloatValue();
        p.y = obj.Get("y").As<Napi::Number>().FloatValue();
        return true;
    }
    return false;
}

template<>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Point2f &p)
{
    Napi::Object obj = Napi::Object::New(info.Env());
    obj.Set("x", p.x);
    obj.Set("y", p.y);
    return obj;
}

// --- Point2d
template<>
bool jsopencv_to(const Napi::Value *obj_value, cv::Point2d &p, const ArgInfo &argInfo)
{
    Napi::Object obj = obj_value->As<Napi::Object>();
    if (obj.Has("x") && obj.Has("y"))
    {
        p.x = obj.Get("x").As<Napi::Number>().DoubleValue();
        p.y = obj.Get("y").As<Napi::Number>().DoubleValue();
        return true;
    }
    return false;
}

template<>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Point2d &p)
{
    Napi::Object obj = Napi::Object::New(info.Env());
    obj.Set("x", p.x);
    obj.Set("y", p.y);
    return obj;
}

// --- Point3f
template<>
bool jsopencv_to(const Napi::Value *obj_value, cv::Point3f &p, const ArgInfo &argInfo)
{
    Napi::Object obj = obj_value->As<Napi::Object>();
    if (obj.Has("x") && obj.Has("y") && obj.Has("z"))
    {
        p.x = obj.Get("x").As<Napi::Number>().FloatValue();
        p.y = obj.Get("y").As<Napi::Number>().FloatValue();
        p.z = obj.Get("z").As<Napi::Number>().FloatValue();
        return true;
    }
    return false;
}

template<>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Point3f &p)
{
    Napi::Object obj = Napi::Object::New(info.Env());
    obj.Set("x", p.x);
    obj.Set("y", p.y);
    obj.Set("z", p.z);
    return obj;
}

// --- Point3d
template<>
bool jsopencv_to(const Napi::Value *obj_value, cv::Point3d &p, const ArgInfo &argInfo)
{
    Napi::Object obj = obj_value->As<Napi::Object>();
    if (obj.Has("x") && obj.Has("y") && obj.Has("z"))
    {
        p.x = obj.Get("x").As<Napi::Number>().DoubleValue();
        p.y = obj.Get("y").As<Napi::Number>().DoubleValue();
        p.z = obj.Get("z").As<Napi::Number>().DoubleValue();
        return true;
    }
    return false;
}

template<>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Point3d &p)
{
    Napi::Object obj = Napi::Object::New(info.Env());
    obj.Set("x", p.x);
    obj.Set("y", p.y);
    obj.Set("z", p.z);
    return obj;
}
// --- Vec4d
template<>
bool jsopencv_to(const Napi::Value *obj, cv::Vec4d &v, const ArgInfo &argInfo)
{
    if (!obj->IsArray())
    {
        jsfailmsg(obj->Env(), "Expected an array for argument '%s'", argInfo.name);
        return false;
    }

    Napi::Array arr = obj->As<Napi::Array>();
    if (arr.Length() < 4)
    {
        jsfailmsg(obj->Env(), "Expected an array of length 4 for argument '%s'", argInfo.name);
        return false;
    }

    for (size_t i = 0; i < 4; ++i)
    {
        Napi::Value val = arr.Get(i);
        if (!val.IsNumber())
        {
            jsfailmsg(obj->Env(), "Array element at index %zu is not a number for argument '%s'", i, argInfo.name);
            return false;
        }
        v[i] = val.As<Napi::Number>().DoubleValue();
    }

    return true;
}

template<>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Vec4d &v)
{
    Napi::Array arr = Napi::Array::New(info.Env(), 4);
    for (size_t i = 0; i < 4; ++i)
    {
        arr.Set(i, Napi::Number::New(info.Env(), v[i]));
    }
    return arr;
}
// --- Vec4f
template <>
bool jsopencv_to(const Napi::Value *obj, cv::Vec4f &v, const ArgInfo &argInfo)
{
    if (!obj->IsArray())
    {
        jsfailmsg(obj->Env(), "Expected an array for argument '%s'", argInfo.name);
        return false;
    }

    Napi::Array arr = obj->As<Napi::Array>();
    if (arr.Length() < 4)
    {
        jsfailmsg(obj->Env(), "Expected an array of length 4 for argument '%s'", argInfo.name);
        return false;
    }

    for (size_t i = 0; i < 4; ++i)
    {
        Napi::Value val = arr.Get(i);
        if (!val.IsNumber())
        {
            jsfailmsg(obj->Env(), "Array element at index %zu is not a number for argument '%s'", i, argInfo.name);
            return false;
        }
        v[i] = val.As<Napi::Number>().FloatValue();
    }

    return true;
}

template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Vec4f &v)
{
    Napi::Array arr = Napi::Array::New(info.Env(), 4);
    for (size_t i = 0; i < 4; ++i)
    {
        arr.Set(i, Napi::Number::New(info.Env(), v[i]));
    }
    return arr;
}
// --- Vec4i
template <>
bool jsopencv_to(const Napi::Value *obj_value, cv::Vec4i &v, const ArgInfo &argInfo)
{
    if (obj_value->IsNull() || obj_value->IsUndefined()) {
        return true;
    }

    if (!obj_value->IsArray()) {
        // Add error handling with argInfo
        return false;
    }

    Napi::Array arr = obj_value->As<Napi::Array>();

    if (arr.Length() < 4) {
        // Add error handling with argInfo
        return false;
    }

    for (uint32_t i = 0; i < 4; ++i) {
        Napi::Value item = arr.Get(i);
        if (!item.IsNumber()) {
            // Add error handling with argInfo
            return false;
        }
        v[i] = item.As<Napi::Number>().Int32Value();
    }

    return true;
}

template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Vec4i &v)
{
    Napi::Env env = info.Env();
    Napi::Array arr = Napi::Array::New(env, 4);

    for (uint32_t i = 0; i < 4; ++i) {
        arr.Set(i, Napi::Number::New(env, v[i]));
    }

    return arr;
}

// --- Vec3d
template <>
bool jsopencv_to(const Napi::Value *obj_value, cv::Vec3d &v, const ArgInfo &argInfo)
{
    if (obj_value->IsNull() || obj_value->IsUndefined()) {
        return true;
    }

    if (!obj_value->IsArray()) {
        // Add error handling with argInfo
        return false;
    }

    Napi::Array arr = obj_value->As<Napi::Array>();

    if (arr.Length() < 3) {
        // Add error handling with argInfo
        return false;
    }

    for (uint32_t i = 0; i < 3; ++i) {
        Napi::Value item = arr.Get(i);
        if (!item.IsNumber()) {
            // Add error handling with argInfo
            return false;
        }
        v[i] = item.As<Napi::Number>().DoubleValue();
    }

    return true;
}

template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Vec3d &v)
{
    Napi::Env env = info.Env();
    Napi::Array arr = Napi::Array::New(env, 3);

    for (uint32_t i = 0; i < 3; ++i) {
        arr.Set(i, Napi::Number::New(env, v[i]));
    }

    return arr;
}

// --- Vec3f
template<>
bool jsopencv_to(const Napi::Value *obj_value, cv::Vec3f &v, const ArgInfo &argInfo)
{
    if (obj_value->IsNull() || obj_value->IsUndefined()) {
        return true;
    }

    if (!obj_value->IsArray()) {
        // Add error handling with argInfo
        return false;
    }

    Napi::Array arr = obj_value->As<Napi::Array>();

    if (arr.Length() < 3) {
        // Add error handling with argInfo
        return false;
    }

    for (uint32_t i = 0; i < 3; ++i) {
        Napi::Value item = arr.Get(i);
        if (!item.IsNumber()) {
            // Add error handling with argInfo
            return false;
        }
        v[i] = item.As<Napi::Number>().Int32Value();
    }

    return true;
}

template<>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Vec3f &v)
{
    Napi::Env env = info.Env();
    Napi::Array arr = Napi::Array::New(env, 3);

    for (uint32_t i = 0; i < 3; ++i) {
        arr.Set(i, Napi::Number::New(env, v[i]));
    }

    return arr;
}
// --- Vec3i
template <>
bool jsopencv_to(const Napi::Value *obj_value, cv::Vec3i &v, const ArgInfo &argInfo)
{
    if (obj_value->IsNull() || obj_value->IsUndefined()) {
        return true;
    }

    if (!obj_value->IsArray()) {
        // Add error handling with argInfo
        return false;
    }

    Napi::Array arr = obj_value->As<Napi::Array>();

    if (arr.Length() < 3) {
        // Add error handling with argInfo
        return false;
    }

    for (uint32_t i = 0; i < 3; ++i) {
        Napi::Value item = arr.Get(i);
        if (!item.IsNumber()) {
            // Add error handling with argInfo
            return false;
        }
        v[i] = item.As<Napi::Number>().Int32Value();
    }

    return true;
}

template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Vec3i &v)
{
    Napi::Env env = info.Env();
    Napi::Array arr = Napi::Array::New(env, 3);

    for (uint32_t i = 0; i < 3; ++i) {
        arr.Set(i, Napi::Number::New(env, v[i]));
    }

    return arr;
}

// --- Vec2d
template <>
bool jsopencv_to(const Napi::Value *obj_value, cv::Vec2d &v, const ArgInfo &argInfo)
{
    if (!obj_value || obj_value->IsNull() || !obj_value->IsArray())
    {
        return false;
    }
    Napi::Array arr = obj_value->As<Napi::Array>();

    if (arr.Length() < 2)
    {
        return false;
    }

    for (uint32_t i = 0; i < 2; ++i)
    {
        Napi::Value item = arr.Get(i);
        if (!item.IsNumber())
        {
            return false;
        }
        v[i] = item.As<Napi::Number>().DoubleValue();
    }

    return true;
}

template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Vec2d &v)
{
    Napi::Env env = info.Env();
    Napi::Array arr = Napi::Array::New(env, 2);

    for (uint32_t i = 0; i < 2; ++i)
    {
        arr.Set(i, Napi::Number::New(env, v[i]));
    }

    return arr;
}

// --- Vec2i
template <>
bool jsopencv_to(const Napi::Value *obj_value, cv::Vec2i &v, const ArgInfo &argInfo)
{
    if (!obj_value || obj_value->IsNull() || !obj_value->IsArray())
    {
        return false;
    }
    Napi::Array arr = obj_value->As<Napi::Array>();

    if (arr.Length() < 2)
    {
        return false;
    }

    for (uint32_t i = 0; i < 2; ++i)
    {
        Napi::Value item = arr.Get(i);
        if (!item.IsNumber())
        {
            return false;
        }
        v[i] = item.As<Napi::Number>().Int32Value();
    }

    return true;
}

template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Vec2i &v)
{
    Napi::Env env = info.Env();
    Napi::Array arr = Napi::Array::New(env, 2);

    for (uint32_t i = 0; i < 2; ++i)
    {
        arr.Set(i, Napi::Number::New(env, v[i]));
    }

    return arr;
}

// --- TermCriteria
template <>
bool jsopencv_to(const Napi::Value *obj_value, cv::TermCriteria &dst, const ArgInfo &info)
{
    if (!obj_value || obj_value->IsNull() || !obj_value->IsArray())
    {
        return true;
    }

    Napi::Array arr = obj_value->As<Napi::Array>();

    if (arr.Length() != 3)
    {
        return false;
    }

    {
        Napi::Value type_item = arr.Get(uint32_t(0));
        if (!type_item.IsNumber())
        {
            return false;
        }
        dst.type = type_item.As<Napi::Number>().Int32Value();
    }

    {
        Napi::Value max_count_item = arr.Get(uint32_t(1));
        if (!max_count_item.IsNumber())
        {
            return false;
        }
        dst.maxCount = max_count_item.As<Napi::Number>().Int32Value();
    }

    {
        Napi::Value epsilon_item = arr.Get(uint32_t(2));
        if (!epsilon_item.IsNumber())
        {
            return false;
        }
        dst.epsilon = epsilon_item.As<Napi::Number>().DoubleValue();
    }

    return true;
}

template <>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::TermCriteria &src)
{
    Napi::Env env = info.Env();
    Napi::Array arr = Napi::Array::New(env, 3);

    arr.Set(uint32_t(0), Napi::Number::New(env, src.type));
    arr.Set(uint32_t(1), Napi::Number::New(env, src.maxCount));
    arr.Set(uint32_t(2), Napi::Number::New(env, src.epsilon));

    return arr;
}

// --- Moments
template<>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Moments &m)
{
    Napi::Env env = info.Env();
    Napi::Object obj = Napi::Object::New(env);

    obj.Set("m00", Napi::Number::New(env, m.m00));
    obj.Set("m10", Napi::Number::New(env, m.m10));
    obj.Set("m01", Napi::Number::New(env, m.m01));
    obj.Set("m20", Napi::Number::New(env, m.m20));
    obj.Set("m11", Napi::Number::New(env, m.m11));
    obj.Set("m02", Napi::Number::New(env, m.m02));
    obj.Set("m30", Napi::Number::New(env, m.m30));
    obj.Set("m21", Napi::Number::New(env, m.m21));
    obj.Set("m12", Napi::Number::New(env, m.m12));
    obj.Set("m03", Napi::Number::New(env, m.m03));
    obj.Set("mu20", Napi::Number::New(env, m.mu20));
    obj.Set("mu11", Napi::Number::New(env, m.mu11));
    obj.Set("mu02", Napi::Number::New(env, m.mu02));
    obj.Set("mu30", Napi::Number::New(env, m.mu30));
    obj.Set("mu21", Napi::Number::New(env, m.mu21));
    obj.Set("mu12", Napi::Number::New(env, m.mu12));
    obj.Set("mu03", Napi::Number::New(env, m.mu03));
    obj.Set("nu20", Napi::Number::New(env, m.nu20));
    obj.Set("nu11", Napi::Number::New(env, m.nu11));
    obj.Set("nu02", Napi::Number::New(env, m.nu02));
    obj.Set("nu30", Napi::Number::New(env, m.nu30));
    obj.Set("nu21", Napi::Number::New(env, m.nu21));
    obj.Set("nu12", Napi::Number::New(env, m.nu12));
    obj.Set("nu03", Napi::Number::New(env, m.nu03));

    return obj;
}
// --- pair
template<>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const std::pair<int, double> &src)
{
    Napi::Env env = info.Env();
    Napi::Array arr = Napi::Array::New(env, 2);

    arr.Set(uint32_t(0), Napi::Number::New(env, src.first));
    arr.Set(uint32_t(1), Napi::Number::New(env, src.second));

    return arr;
}
