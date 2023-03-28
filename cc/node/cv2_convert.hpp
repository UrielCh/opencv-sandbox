#ifndef CV2_CONVERT_HPP2
#define CV2_CONVERT_HPP2

#include "cv2.hpp"
#include "cv2_util.hpp"
// #include <vector>
// #include <string>
// #include <type_traits>  // std::enable_if



// --- Generic

template <typename T>
bool jsopencv_to(const Napi::Value* obj, T& value, const ArgInfo& argInfo) {
    return JsOpenCV_Converter<T>::to(obj, value, argInfo);
} 

template<typename T>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const T& src) { 
    failmsg(info, "jsopencv_from template resolved as unknownn type");
    return info.Env().Null();
} // JsOpenCV_Converter<T>::from(src);

// --- Matx
// ported from pyopencv_to L:62
template<typename _Tp, int m, int n>
bool jsopencv_to(const Napi::Value* obj, cv::Matx<_Tp, m, n>& mx, const ArgInfo& argInfo) {
    /// /////
    return true;
}

// ported from jsopencv_to L:78
// template<typename _Tp, int m, int n>
// bool jsopencv_from(const cv::Matx<_Tp, m, n>& matx)
// {
//     return jsopencv_from(cv::Mat(matx));
// }


// see cv2_convert.cpp L 259
// bool jsopencv_to(JsObject* obj, bool& value, const ArgInfo& info)
// FINAL VERSION
// template<>
// bool jsopencv_to(const Napi::Value* obj, bool& value, const ArgInfo& argInfo)
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
// bool jsopencv_from(const Napi::CallbackInfo &info, Napi::Value* obj, const bool& value)
// {
//     
//     return JsBool_FromLong(info, value);
// }



// template<>
// bool jsopencv_to(const Napi::Value* obj, size_t& value, const ArgInfo& argInfo) {
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
// bool jsopencv_to(const Napi::Value* obj, int& value, const ArgInfo& argInfo) {
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
// bool jsopencv_to(const Napi::Value* obj, int64_t& value, const ArgInfo& argInfo) {
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
template<> bool jsopencv_to(const Napi::Value* obj, bool& value, const ArgInfo& argInfo);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const bool& value);

// --- Mat
// template<> bool jsopencv_to(const Napi::Value* obj, Mat& m, const ArgInfo& argInfo);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Mat& m);

// --- Ptr


// --- Ptr

// --- Scalar
// template<> bool jsopencv_to(JsObject *o, cv::Scalar& s, const ArgInfo& info);
// template<> JsObject* jsopencv_from(const cv::Scalar& src);

// --- size_t
template<> bool jsopencv_to(const Napi::Value* obj, size_t& value, const ArgInfo& argInfo);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const size_t& value);

// --- int
template<> bool jsopencv_to(const Napi::Value* obj, int& value, const ArgInfo& Arginfo);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const int& value);

// --- int64
template<> bool jsopencv_to(const Napi::Value* obj, int64& value, const ArgInfo& Arginfo);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const int64& value);


// template <>
// bool jsopencv_to(const Napi::Value *dst, AKAZE_DescriptorType &src, const ArgInfo &argInfo)
// {
//     if (dst->IsNull() || dst->IsUndefined())
//         return true;
//     int underlying = 0;
//     if (!jsopencv_to(dst, underlying, argInfo))
//         return false;
//     src = static_cast<AKAZE_DescriptorType>(underlying);
//     return true;
// }


//======================================================================================================================


// exception-safe jsopencv_to
template<typename _Tp> static
bool jsopencv_to_safe(const Napi::Value* obj, const _Tp& value, const ArgInfo& argInfo)
{
    try
    {
        return jsopencv_to(obj, value, argInfo);
    }
    catch (const std::exception &e)
    {
        failmsg(obj->Env(), "Conversion error: %s, what: %s", argInfo.name, e.what());
        return false;
    }
    catch (...)
    {
        failmsg(obj->Env(), "Conversion error: %s", argInfo.name);
        return false;
    }
}

//======================================================================================================================



#endif