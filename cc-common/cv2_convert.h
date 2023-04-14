#ifndef CV2_CONVERT_HPP2
#define CV2_CONVERT_HPP2

#include "common_cv2.h"
#include "cv2_util.h"
#include "js_as_py.h"
#include "cv2_numpy.h"
// #include "cv2_util.hpp"
// #include <vector>
// #include <string>
// #include <type_traits>  // std::enable_if
// extern PyTypeObject* pyopencv_Mat_TypePtr;



// inline bool isBool(const Napi::Value* obj) CV_NOEXCEPT



//======================================================================================================================

// import from bool pyopencv_to_safe(PyObject* obj, _Tp& value, const ArgInfo& info) in cv2_convert.hpp
// exception-safe pyopencv_to
template<typename _Tp> static
bool jsopencv_to_safe(const Napi::Value* obj, _Tp& value, const ArgInfo& argInfo)
{
    if (!obj) return true; // no shure yet, bypass all null source
    try
    {
        return jsopencv_to(obj, value, argInfo);
    }
    catch (const std::exception &e)
    {
        jsfailmsg(obj->Env(), "Conversion error: %s, what: %s", argInfo.name, e.what());
        return false;
    }
    catch (...)
    {
        jsfailmsg(obj->Env(), "Conversion error: %s", argInfo.name);
        return false;
    }
}
//======================================================================================================================

template<typename T, class TEnable = void>  // TEnable is used for SFINAE checks
struct JsOpenCV_Converter
{
    // static inline bool to(const Napi::Value* obj, T& p, const ArgInfo& info);
    // static inline Napi::Value from(const Napi::CallbackInfo &info, const T& src);
};

// --- Generic

template <typename T>
bool jsopencv_to(const Napi::Value* obj, T& value, const ArgInfo& argInfo) { return JsOpenCV_Converter<T>::to(obj, value, argInfo); } 

template<typename T>
Napi::Value jsopencv_from(const Napi::Env &env, const T& src) { return JsOpenCV_Converter<T>::from(info, src); }

// --- Matx
// ported from pyopencv_to L:62
template<typename _Tp, int m, int n>
bool jsopencv_to(const Napi::Value* obj, cv::Matx<_Tp, m, n>& mx, const ArgInfo& argInfo) {
    if (!obj || obj->IsUndefined() || obj->IsNull()) {
        return true;
    }

    cv::Mat tmp;
    if (!jsopencv_to(obj, tmp, argInfo)) {
        return false;
    }

    tmp.copyTo(mx);
    return true;
}


template<typename _Tp, int m, int n>
Napi::Value jsopencv_from(const Napi::Env &env, const cv::Matx<_Tp, m, n>& matx)
{
    return jsopencv_from(env, cv::Mat(matx));
}

// --- bool
template<> bool jsopencv_to(const Napi::Value* obj, bool& value, const ArgInfo& argInfo);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const bool& value);

// --- Mat
template<> bool jsopencv_to(const Napi::Value* obj, cv::Mat& m, const ArgInfo& argInfo);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const cv::Mat& m);

// --- Ptr
template<typename T>
struct JsOpenCV_Converter< cv::Ptr<T> >
{
    static Napi::Value from(const Napi::CallbackInfo &info, const cv::Ptr<T>& p)
    {
        if (!p)
            return info.Env().Null(); // Py_RETURN_NONE;
        return jsopencv_from(*p);
    }
    static bool to(const Napi::Value *value, cv::Ptr<T>& p, const ArgInfo& argInfo)
    {
        if (!value || value->IsUndefined() || value->IsNull())
            return true;
        p = cv::makePtr<T>();
        return jsopencv_to(value, *p, argInfo);
    }
};

// --- ptr
template<> bool jsopencv_to(const Napi::Value* obj, void*& ptr, const ArgInfo& info);
Napi::Value jsopencv_from(const Napi::Env &env, void*& ptr);

// --- Scalar
template<> bool jsopencv_to(const Napi::Value* o, cv::Scalar& s, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const cv::Scalar& src);

// --- size_t
template<> bool jsopencv_to(const Napi::Value* obj, size_t& value, const ArgInfo& argInfo);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const size_t& value);

// --- int
template<> bool jsopencv_to(const Napi::Value* obj, int& value, const ArgInfo& Arginfo);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const int& value);

// --- int64
template<> bool jsopencv_to(const Napi::Value* obj, int64& value, const ArgInfo& Arginfo);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const int64& value);

// There is conflict between "size_t" and "unsigned int".
// They are the same type on some 32-bit platforms.
template<typename T>
struct JsOpenCV_Converter
    < T, typename std::enable_if< std::is_same<unsigned int, T>::value && !std::is_same<unsigned int, size_t>::value >::type >
{
    static inline Napi::Value from(const Napi::CallbackInfo &info, const unsigned int& value)
    {
        return JsLong_FromUnsignedLong(info.Env(), value);
    }

    static inline bool to(const Napi::Value* obj, unsigned int& value, const ArgInfo& info)
    {
        CV_UNUSED(info);
         if (!obj || obj->IsUndefined() || obj->IsNull())
            return true;
        if (obj->IsNumber()) // not implemented yet
            value = obj->As<Napi::Number>().Uint32Value();
            // (unsigned int)JsInt_AsLong(obj);
        // else if(JSLong_Check(obj))
        //     value = (unsigned int)JsLong_AsLong(obj);
        else
            return false;
        return value != (unsigned int)-1; // || !JsErr_Occurred(); 
    }
};

// --- uchar
template<> bool jsopencv_to(const Napi::Value* obj, uchar& value, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const uchar& value);

// --- char
template<> bool jsopencv_to(const Napi::Value* obj, char& value, const ArgInfo& info);

// --- double
template<> bool jsopencv_to(const Napi::Value* obj, double& value, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const double& value);

// --- float
template<> bool jsopencv_to(const Napi::Value* obj, float& value, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const float& value);

// --- string
template<> bool jsopencv_to(const Napi::Value* obj, cv::String &value, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const cv::String& value);
//  cv::String === std::string
// template<> Napi::Value jsopencv_from(const Napi::Env &env, const std::string& value);


// --- Size
template<> bool jsopencv_to(const Napi::Value* obj, cv::Size& sz, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const cv::Size& sz);
template<> bool jsopencv_to(const Napi::Value* obj, cv::Size_<float>& sz, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const cv::Size_<float>& sz);

// --- Rect
template<> bool jsopencv_to(const Napi::Value* obj, cv::Rect& r, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const cv::Rect& r);
template<> bool jsopencv_to(const Napi::Value* obj, cv::Rect2d& r, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const cv::Rect2d& r);

// --- RotatedRect
template<> bool jsopencv_to(const Napi::Value* obj, cv::RotatedRect& dst, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const cv::RotatedRect& src);

// --- Range
template<> bool jsopencv_to(const Napi::Value* obj, cv::Range& r, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const cv::Range& r);

// --- Point
template<> bool jsopencv_to(const Napi::Value* obj, cv::Point& p, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const cv::Point& p);
template<> bool jsopencv_to(const Napi::Value* obj, cv::Point2f& p, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const cv::Point2f& p);
template<> bool jsopencv_to(const Napi::Value* obj, cv::Point2d& p, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const cv::Point2d& p);
template<> bool jsopencv_to(const Napi::Value* obj, cv::Point3f& p, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const cv::Point3f& p);
template<> bool jsopencv_to(const Napi::Value* obj, cv::Point3d& p, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const cv::Point3d& p);

// --- Vec
template<typename _Tp, int cn>
bool jsopencv_to(const Napi::Value* obj, cv::Vec<_Tp, cn>& vec, const ArgInfo& info)
{
    return jsopencv_to(obj, (cv::Matx<_Tp, cn, 1>&)vec, info);
}
bool jsopencv_to(const Napi::Value* obj, cv::Vec4d& v, ArgInfo& info);
Napi::Value jsopencv_from(const Napi::Env &env, const cv::Vec4d& v);
bool jsopencv_to(const Napi::Value* obj, cv::Vec4f& v, ArgInfo& info);
Napi::Value jsopencv_from(const Napi::Env &env, const cv::Vec4f& v);
bool jsopencv_to(const Napi::Value* obj, cv::Vec4i& v, ArgInfo& info);
Napi::Value jsopencv_from(const Napi::Env &env, const cv::Vec4i& v);
bool jsopencv_to(const Napi::Value* obj, cv::Vec3d& v, ArgInfo& info);
Napi::Value jsopencv_from(const Napi::Env &env, const cv::Vec3d& v);
bool jsopencv_to(const Napi::Value* obj, cv::Vec3f& v, ArgInfo& info);
Napi::Value jsopencv_from(const Napi::Env &env, const cv::Vec3f& v);
bool jsopencv_to(const Napi::Value* obj, cv::Vec3i& v, ArgInfo& info);
Napi::Value jsopencv_from(const Napi::Env &env, const cv::Vec3i& v);
bool jsopencv_to(const Napi::Value* obj, cv::Vec2d& v, ArgInfo& info);
Napi::Value jsopencv_from(const Napi::Env &env, const cv::Vec2d& v);
bool jsopencv_to(const Napi::Value* obj, cv::Vec2f& v, ArgInfo& info);
Napi::Value jsopencv_from(const Napi::Env &env, const cv::Vec2f& v);
bool jsopencv_to(const Napi::Value* obj, cv::Vec2i& v, ArgInfo& info);
Napi::Value jsopencv_from(const Napi::Env &env, const cv::Vec2i& v);

// --- TermCriteria
template<> bool jsopencv_to(const Napi::Value* obj, cv::TermCriteria& dst, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::Env &env, const cv::TermCriteria& src);

// --- Moments
template<> Napi::Value jsopencv_from(const Napi::Env &env, const cv::Moments& m);

// --- pair
template<> Napi::Value jsopencv_from(const Napi::Env &env, const std::pair<int, double>& src);

// --- vector
template <typename Tp>
struct jsopencvVecConverter;

template <typename Tp>
bool jsopencv_to(const Napi::Value* obj, std::vector<Tp>& value, const ArgInfo& info)
{
    if (obj->IsNull() || obj->IsUndefined())
    {
        return true;
    }
    return jsopencvVecConverter<Tp>::to(obj, value, info);
}

template <typename Tp>
Napi::Value jsopencv_from(const Napi::Env &env, const std::vector<Tp>& value)
{
    return jsopencvVecConverter<Tp>::from(env, value);
}

template <typename Tp>
static bool jsopencv_to_generic_vec(const Napi::Value* obj, std::vector<Tp>& value, const ArgInfo& info)
{
    if (!obj || obj->IsNull() || obj->IsUndefined())
    {
        return true;
    }
    if (!JsSequence_Check(obj))
    {
        jsfailmsg(obj->Env(), "Can't parse '%s'. Input argument doesn't provide sequence protocol", info.name);
        return false;
    }
    const size_t n = static_cast<size_t>(JsSequence_Size(obj));
    value.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        JsSafeSeqItem item_wrap(obj, i);
        if (!jsopencv_to(item_wrap.item, value[i], info))
        {
            jsfailmsg(obj->Env(), "Can't parse '%s'. Sequence item with index %lu has a wrong type", info.name, i);
            return false;
        }
    }
    return true;
}
template<>
inline bool jsopencv_to_generic_vec(const Napi::Value* obj, std::vector<bool>& value, const ArgInfo& info)
{
    if (!obj || obj->IsNull() || obj->IsUndefined())
    {
        return true;
    }
    if (!obj->IsArray())
    {
        jsfailmsg(obj->Env(), "Can't parse '%s'. Input argument doesn't provide sequence protocol", info.name);
        return false;
    }
    Napi::Array array = obj->As<Napi::Array>();
    const size_t n = array.Length();
    value.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        Napi::Value item = array.Get(i);
        bool elem{};
        if (!jsopencv_to(&item, elem, info))
        {
            jsfailmsg(obj->Env(), "Can't parse '%s'. Sequence item with index %lu has a wrong type", info.name, i);
            return false;
        }
        value[i] = elem;
    }
    return true;
}
// template <typename Tp>
// static Napi::Value* jsopencv_from_generic_vec(const Napi::Env& env, const std::vector<Tp>& value)
// {
//     Py_ssize_t n = static_cast<Py_ssize_t>(value.size());
//     PySafeObject seq(PyTuple_New(n));
//     for (Py_ssize_t i = 0; i < n; i++)
//     {
//         PyObject* item = jsopencv_from(value[i]);
//         // If item can't be assigned - PyTuple_SetItem raises exception and returns -1.
//         if (!item || PyTuple_SetItem(seq, i, item) == -1)
//         {
//             return NULL;
//         }
//     }
//     return seq.release();
// }
// 
// template<>
// inline Napi::Value jsopencv_from_generic_vec(const Napi::Env& env, const std::vector<bool>& value)
// {
//     Napi::Array array = Napi::Array::New(env, value.size());
//     for (size_t i = 0; i < value.size(); i++)
//     {
//         bool elem = value[i];
//         Napi::Value item = jsopencv_from(env, elem);
//         if (item.IsEmpty())
//         {
//             return env.Null();
//         }
//         array.Set(i, item);
//     }
//     return array;
// }

namespace traits {

template <bool Value>
struct BooleanConstant
{
    static const bool value = Value;
    typedef BooleanConstant<Value> type;
};

typedef BooleanConstant<true> TrueType;
typedef BooleanConstant<false> FalseType;

template <class T>
struct VoidType {
    typedef void type;
};

template <class T, class DType = void>
struct IsRepresentableAsMatDataType : FalseType
{
};

template <class T>
struct IsRepresentableAsMatDataType<T, typename VoidType<typename cv::DataType<T>::channel_type>::type> : TrueType
{
};

// https://github.com/opencv/opencv/issues/20930
template <> struct IsRepresentableAsMatDataType<cv::RotatedRect, void> : FalseType {};

} // namespace traits

template <typename Tp>
struct jsopencvVecConverter
{
    typedef typename std::vector<Tp>::iterator VecIt;

    static bool to(const Napi::Value* value, std::vector<Tp>& vec, const ArgInfo& info)
    {
        if (!value->IsBuffer())
        {
            return false;
        }

        Napi::Buffer<Tp> buffer = value->As<Napi::Buffer<Tp>>();
        size_t length = buffer.Length();

        vec.resize(length);
        std::memcpy(vec.data(), buffer.Data(), length * sizeof(Tp));

        return true;
    }

    static Napi::Value from(const Napi::Env& env, const std::vector<Tp>& vec)
    {
        size_t length = vec.size();
        Napi::Buffer<Tp> buffer = Napi::Buffer<Tp>::New(env, length);

        std::memcpy(buffer.Data(), vec.data(), length * sizeof(Tp));

        return buffer;
    }


























private:


























































};

// --- tuple

template<std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I == sizeof...(Tp), void>::type
convert_to_js_array_tuple(const std::tuple<Tp...>&, Napi::Array&) {  }

template<std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I < sizeof...(Tp), void>::type
convert_to_js_array_tuple(const std::tuple<Tp...>& cpp_tuple, Napi::Array& js_array)
{
    Napi::Env env = js_array.Env();
    Napi::Value item = jsopencv_from(env, std::get<I>(cpp_tuple));
    js_array.Set(I, item);
    convert_to_js_array_tuple<I + 1, Tp...>(cpp_tuple, js_array);
}

template<typename... Ts>
Napi::Value jsopencv_from(const Napi::Env& env, const std::tuple<Ts...>& cpp_tuple)
{
    size_t size = sizeof...(Ts);
    Napi::Array js_array = Napi::Array::New(env, size);
    convert_to_js_array_tuple(cpp_tuple, js_array);
    return js_array;
}

#endif
