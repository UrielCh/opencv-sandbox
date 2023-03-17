#ifndef CV2_CONVERT_HPP
#define CV2_CONVERT_HPP

#include "cv2.hpp"
#include "cv2_util.hpp"
// #include <vector>
// #include <string>
// #include <type_traits>  // std::enable_if











//======================================================================================================================


// exception-safe jsopencv_to
template<typename _Tp> static
bool nodeopencv_to_safe(const Napi::CallbackInfo &info, Napi::Value* obj, _Tp& value, const ArgInfo& argInfo)
{
    try
    {
        return nodeopencv_to(info, obj, value, info);
    }
    catch (const std::exception &e)
    {
        failmsg(info, "Conversion error: %s, what: %s", argInfo.name, e.what());
        return false;
    }
    catch (...)
    {
        failmsg(info, "Conversion error: %s", argInfo.name);
        return false;
    }
}

//======================================================================================================================








// --- Generic

template <typename T>
bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, T& value, const ArgInfo& argInfo) { return false; } //  return JsOpenCV_Converter<T>::to(obj, p, info);

template<typename T>
Napi::Value nodeopencv_from(const Napi::CallbackInfo &info, const T& src) { 
    failmsg(info, "nodeopencv_from template resolved as unknownn type");
    return info.Env().Null();
} // JsOpenCV_Converter<T>::from(src);

// --- Matx
// ported from jsopencv_to L:62
template<typename _Tp, int m, int n>
bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, cv::Matx<_Tp, m, n>& mx, const ArgInfo& argInfo) {
    /// /////
    return true;
}

// ported from jsopencv_to L:78
// template<typename _Tp, int m, int n>
// bool nodeopencv_from(const cv::Matx<_Tp, m, n>& matx)
// {
//     return jsopencv_from(cv::Mat(matx));
// }


// see cv2_convert.cpp L 259
// bool jsopencv_to(JsObject* obj, bool& value, const ArgInfo& info)
// FINAL VERSION
// template<>
// bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, bool& value, const ArgInfo& argInfo)
// {
//     // if (!obj || obj == NULL)
//     if (obj->IsNull() || obj->IsUndefined())
//     {
//         return true;
//     }
//     if (obj->IsBoolean()) //  || JsArray_IsIntegerScalar(obj)
//     {
//         return obj->ToBoolean();
//     }
//     // Napi::TypeError::New(env, "Failed to parse boolean value").ThrowAsJavaScriptException();
//     // return false;
//     failmsg(info, "Argument '%s' is not convertable to bool", argInfo.name);
//     //return false;
// }

// template<>
// bool nodeopencv_from(const Napi::CallbackInfo &info, Napi::Value* obj, const bool& value)
// {
//     
//     return JsBool_FromLong(info, value);
// }



// template<>
// bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, size_t& value, const ArgInfo& argInfo) {
//     if (obj->IsNull() || obj->IsUndefined()) {
//         return true;
//     }
//     if (obj->IsBoolean()) {
//         failmsg(info, "Argument '%s' must be integer type, not bool", argInfo.name);
//         return false;
//     }
//     if (obj->IsNumber()) {
//         Napi::Number num = obj->ToNumber();
//         // value = obj->ToNumber();
//         // value = static_cast<size_t>(num);
//         value = static_cast<size_t>(static_cast<int64_t>(num));
//     } else {
//         failmsg(info, "Argument '%s' is required to be an integer", argInfo.name);
//         return false;
//     }
//     return true;
// }



// template<>
// bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, int& value, const ArgInfo& argInfo) {
//     if (obj->IsNull() || obj->IsUndefined()) {
//         return true;
//     }
//     if (obj->IsBoolean()) {
//         failmsg(info, "Argument '%s' must be integer type, not bool", argInfo.name);
//         return false;
//     }
//     if (obj->IsNumber()) {
//         Napi::Number num = obj->ToNumber();
//         value = static_cast<int>(num);
//     } else {
//         failmsg(info, "Argument '%s' is required to be an integer", argInfo.name);
//         return false;
//     }
//     return true;
// }




// template<>
// bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, int64_t& value, const ArgInfo& argInfo) {
//     if (obj->IsNull() || obj->IsUndefined()) {
//         return true;
//     }
//     if (obj->IsBoolean()) {
//         failmsg(info, "Argument '%s' must be integer type, not bool", argInfo.name);
//         return false;
//     }
//     if (obj->IsNumber()) {
//         Napi::Number num = obj->ToNumber();
//         value = static_cast<int64_t>(num);
//     } else {
//         failmsg(info, "Argument '%s' is required to be an integer", argInfo.name);
//         return false;
//     }
//     return true;
// }


// --- bool
template<> bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, bool& value, const ArgInfo& argInfo);
template<> Napi::Value nodeopencv_from(const Napi::CallbackInfo &info, const bool& value);

// --- Mat
// template<> bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, Mat& m, const ArgInfo& argInfo);
template<> Napi::Value nodeopencv_from(const Napi::CallbackInfo &info, const cv::Mat& m);

// --- Ptr


// --- Ptr

// --- Scalar
// template<> bool jsopencv_to(JsObject *o, cv::Scalar& s, const ArgInfo& info);
// template<> JsObject* jsopencv_from(const cv::Scalar& src);

// --- size_t
template<> bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, size_t& value, const ArgInfo& argInfo);
template<> Napi::Value nodeopencv_from(const Napi::CallbackInfo &info, const size_t& value);

// --- int
template<> bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, int& value, const ArgInfo& Arginfo);
template<> Napi::Value nodeopencv_from(const Napi::CallbackInfo &info, const int& value);

// --- int64
template<> bool nodeopencv_to(const Napi::CallbackInfo &info, Napi::Value* obj, int64& value, const ArgInfo& Arginfo);
template<> Napi::Value nodeopencv_from(const Napi::CallbackInfo &info, const int64& value);




#endif