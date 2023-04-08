#ifndef CV2_CONVERT_HPP2
#define CV2_CONVERT_HPP2

#include "common_cv2.h"
#include "js_as_py.h"
#include "cv2_numpy.h"
// #include "cv2_util.hpp"
// #include <vector>
// #include <string>
// #include <type_traits>  // std::enable_if













// import from bool pyopencv_to_safe(PyObject* obj, _Tp& value, const ArgInfo& info) in cv2_convert.hpp
template<typename _Tp> static
bool jsopencv_to_safe(const Napi::Value* obj, _Tp& value, const ArgInfo& argInfo)
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

template<typename T, class TEnable = void>  // TEnable is used for SFINAE checks
struct JsOpenCV_Converter
{
    static inline bool to(const Napi::Value* obj, T& p, const ArgInfo& info);
    static inline Napi::Value from(const Napi::CallbackInfo &info, const T& src);
};

// --- Generic

template <typename T>
bool jsopencv_to(const Napi::Value* obj, T& value, const ArgInfo& argInfo) { return JsOpenCV_Converter<T>::to(obj, value, argInfo); } 

template<typename T>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const T& src) { return JsOpenCV_Converter<T>::from(info, src); }

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
Napi::Value* jsopencv_from(const cv::Matx<_Tp, m, n>& matx)
{
    return jsopencv_from(cv::Mat(matx));
}

// --- bool
template<> bool jsopencv_to(const Napi::Value* obj, bool& value, const ArgInfo& argInfo);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const bool& value);

// --- Mat
template<> bool jsopencv_to(const Napi::Value* obj, cv::Mat& m, const ArgInfo& argInfo);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Mat& m);

// --- Ptr
template<typename T>
struct JsOpenCV_Converter< cv::Ptr<T> >
{
    static Napi::Value from(const Napi::CallbackInfo &info, const cv::Ptr<T>& p)
    {
        if (!p)
            return info.Env().Null(); // Py_RETURN_NONE;
        return pyopencv_from(*p);
    }
    static bool to(const Napi::Value *o, cv::Ptr<T>& p, const ArgInfo& argInfo)
    {
        if (!o || o->IsUndefined() || o->IsNull())
            return true;
        p = cv::makePtr<T>();
        return jsopencv_to(o, *p, argInfo);
    }
};

// --- ptr
template<> bool jsopencv_to(const Napi::Value* obj, void*& ptr, const ArgInfo& info);
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, void*& ptr);

// --- Scalar
template<> bool jsopencv_to(const Napi::Value* o, cv::Scalar& s, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Scalar& src);

// --- size_t
template<> bool jsopencv_to(const Napi::Value* obj, size_t& value, const ArgInfo& argInfo);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const size_t& value);

// --- int
template<> bool jsopencv_to(const Napi::Value* obj, int& value, const ArgInfo& Arginfo);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const int& value);

// --- int64
template<> bool jsopencv_to(const Napi::Value* obj, int64& value, const ArgInfo& Arginfo);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const int64& value);

// There is conflict between "size_t" and "unsigned int".
// They are the same type on some 32-bit platforms.
template<typename T>
struct JsOpenCV_Converter
    < T, typename std::enable_if< std::is_same<unsigned int, T>::value && !std::is_same<unsigned int, size_t>::value >::type >
{
    static inline Napi::Value from(const unsigned int& value)
    {
        return PyLong_FromUnsignedLong(value);
    }

    static inline bool to(const Napi::Value* obj, unsigned int& value, const ArgInfo& info)
    {
        CV_UNUSED(info);
         if (!obj || obj->IsUndefined() || obj->IsNull())
            return true;
        if(JsInt_Check(obj))
            value = (unsigned int)JsInt_AsLong(obj);
        else if(JSLong_Check(obj))
            value = (unsigned int)JsLong_AsLong(obj);
        else
            return false;
        return value != (unsigned int)-1 || !PyErr_Occurred();
    }
};

// --- uchar
template<> bool jsopencv_to(const Napi::Value* obj, uchar& value, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const uchar& value);

// --- char
template<> bool jsopencv_to(const Napi::Value* obj, char& value, const ArgInfo& info);

// --- double
template<> bool jsopencv_to(const Napi::Value* obj, double& value, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const double& value);

// --- float
template<> bool jsopencv_to(const Napi::Value* obj, float& value, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const float& value);

// --- string
template<> bool jsopencv_to(const Napi::Value* obj, cv::String &value, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::String& value);




// --- Size
template<> bool jsopencv_to(const Napi::Value* obj, cv::Size& sz, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Size& sz);
template<> bool jsopencv_to(const Napi::Value* obj, cv::Size_<float>& sz, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Size_<float>& sz);

// --- Rect
template<> bool jsopencv_to(const Napi::Value* obj, cv::Rect& r, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Rect& r);
template<> bool jsopencv_to(const Napi::Value* obj, cv::Rect2d& r, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Rect2d& r);

// --- RotatedRect
template<> bool jsopencv_to(const Napi::Value* obj, cv::RotatedRect& dst, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::RotatedRect& src);

// --- Range
template<> bool jsopencv_to(const Napi::Value* obj, cv::Range& r, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Range& r);

// --- Point
template<> bool jsopencv_to(const Napi::Value* obj, cv::Point& p, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Point& p);
template<> bool jsopencv_to(const Napi::Value* obj, cv::Point2f& p, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Point2f& p);
template<> bool jsopencv_to(const Napi::Value* obj, cv::Point2d& p, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Point2d& p);
template<> bool jsopencv_to(const Napi::Value* obj, cv::Point3f& p, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Point3f& p);
template<> bool jsopencv_to(const Napi::Value* obj, cv::Point3d& p, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Point3d& p);

// --- Vec
template<typename _Tp, int cn>
bool jsopencv_to(const Napi::Value* o, cv::Vec<_Tp, cn>& vec, const ArgInfo& info)
{
    return jsopencv_to(o, (cv::Matx<_Tp, cn, 1>&)vec, info);
}
bool jsopencv_to(const Napi::Value* obj, cv::Vec4d& v, ArgInfo& info);
Napi::Value pyopencv_from(const Napi::CallbackInfo &info, const cv::Vec4d& v);
bool jsopencv_to(const Napi::Value* obj, cv::Vec4f& v, ArgInfo& info);
Napi::Value pyopencv_from(const Napi::CallbackInfo &info, const cv::Vec4f& v);
bool jsopencv_to(const Napi::Value* obj, cv::Vec4i& v, ArgInfo& info);
Napi::Value pyopencv_from(const Napi::CallbackInfo &info, const cv::Vec4i& v);
bool jsopencv_to(const Napi::Value* obj, cv::Vec3d& v, ArgInfo& info);
Napi::Value pyopencv_from(const Napi::CallbackInfo &info, const cv::Vec3d& v);
bool jsopencv_to(const Napi::Value* obj, cv::Vec3f& v, ArgInfo& info);
Napi::Value pyopencv_from(const Napi::CallbackInfo &info, const cv::Vec3f& v);
bool jsopencv_to(const Napi::Value* obj, cv::Vec3i& v, ArgInfo& info);
Napi::Value pyopencv_from(const Napi::CallbackInfo &info, const cv::Vec3i& v);
bool jsopencv_to(const Napi::Value* obj, cv::Vec2d& v, ArgInfo& info);
Napi::Value pyopencv_from(const Napi::CallbackInfo &info, const cv::Vec2d& v);
bool jsopencv_to(const Napi::Value* obj, cv::Vec2f& v, ArgInfo& info);
Napi::Value pyopencv_from(const Napi::CallbackInfo &info, const cv::Vec2f& v);
bool jsopencv_to(const Napi::Value* obj, cv::Vec2i& v, ArgInfo& info);
Napi::Value pyopencv_from(const Napi::CallbackInfo &info, const cv::Vec2i& v);

// --- TermCriteria
template<> bool jsopencv_to(const Napi::Value* obj, cv::TermCriteria& dst, const ArgInfo& info);
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::TermCriteria& src);

// --- Moments
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Moments& m);

// --- pair
template<> Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const std::pair<int, double>& src);

// --- vector
template <typename Tp>
struct jsopencvVecConverter;

template <typename Tp>
bool jsopencv_to(const Napi::Value* obj, std::vector<Tp>& value, const ArgInfo& info)
{
    if (!obj || obj->IsNull() || obj->IsUndefined())
    {
        return true;
    }
    return jsopencvVecConverter<Tp>::to(obj, value, info);
}

template <typename Tp>
Napi::Value pyopencv_from(const Napi::CallbackInfo &info, const std::vector<Tp>& value)
{
    return jsopencvVecConverter<Tp>::from(info, value);
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
        failmsg(obj->Env(), "Can't parse '%s'. Input argument doesn't provide sequence protocol", info.name);
        return false;
    }
    const size_t n = static_cast<size_t>(JsSequence_Size(obj));
    value.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        SafeSeqItem item_wrap(obj, i);
        if (!pyopencv_to(item_wrap.item, value[i], info))
        {
            failmsg(obj->Env(), "Can't parse '%s'. Sequence item with index %lu has a wrong type", info.name, i);
            return false;
        }
    }
    return true;
}
// need numpy ?
// template<> inline bool jsopencv_to_generic_vec(const Napi::Value* obj, std::vector<bool>& value, const ArgInfo& info)
// {
//     if (!obj || obj->IsNull() || obj->IsUndefined())
//     {
//         return true;
//     }
//     if (!JsSequence_Check(obj))
//     {
//         failmsg("Can't parse '%s'. Input argument doesn't provide sequence protocol", info.name);
//         return false;
//     }
//     const size_t n = static_cast<size_t>(JsSequence_Size(obj));
//     value.resize(n);
//     for (size_t i = 0; i < n; i++)
//     {
//         SafeSeqItem item_wrap(obj, i);
//         bool elem{};
//         if (!jsopencv_to(item_wrap.item, elem, info))
//         {
//             failmsg(obj->Env(), "Can't parse '%s'. Sequence item with index %lu has a wrong type", info.name, i);
//             return false;
//         }
//         value[i] = elem;
//     }
//     return true;
// }

template <typename Tp>
static Napi::Value* pyopencv_from_generic_vec(const std::vector<Tp>& value)
{
    Py_ssize_t n = static_cast<Py_ssize_t>(value.size());
    PySafeObject seq(PyTuple_New(n));
    for (Py_ssize_t i = 0; i < n; i++)
    {
        PyObject* item = pyopencv_from(value[i]);
        // If item can't be assigned - PyTuple_SetItem raises exception and returns -1.
        if (!item || PyTuple_SetItem(seq, i, item) == -1)
        {
            return NULL;
        }
    }
    return seq.release();
}

// template<> inline Napi::Value* pyopencv_from_generic_vec(const std::vector<bool>& value)
// {
//     Py_ssize_t n = static_cast<Py_ssize_t>(value.size());
//     PySafeObject seq(PyTuple_New(n));
//     for (Py_ssize_t i = 0; i < n; i++)
//     {
//         bool elem = value[i];
//         PyObject* item = pyopencv_from(elem);
//         // If item can't be assigned - PyTuple_SetItem raises exception and returns -1.
//         if (!item || PyTuple_SetItem(seq, i, item) == -1)
//         {
//             return NULL;
//         }
//     }
//     return seq.release();
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

    static bool to(const Napi::Value* obj, std::vector<Tp>& value, const ArgInfo& info)
    {
        if (!JsArray_Check(obj))
        {
            return jsopencv_to_generic_vec(obj, value, info);
        }
        // If user passed an array it is possible to make faster conversions in several cases
        //PyArrayObject* array_obj = reinterpret_cast<PyArrayObject*>(obj);
        Napi::Array* array_obj =obj->As<Napi::Array>();
        const NPY_TYPES target_type = asNumpyType<Tp>();
        const NPY_TYPES source_type = static_cast<NPY_TYPES>(PyArray_TYPE(array_obj));
        if (target_type == NPY_OBJECT)
        {
            // Non-planar arrays representing objects (e.g. array of N Rect is an array of shape Nx4) have NPY_OBJECT
            // as their target type.
            return pyopencv_to_generic_vec(obj, value, info);
        }
        if (PyArray_NDIM(array_obj) > 1)
        {
            failmsg("Can't parse %dD array as '%s' vector argument", PyArray_NDIM(array_obj), info.name);
            return false;
        }
        if (target_type != source_type)
        {
            // Source type requires conversion
            // Allowed conversions for target type is handled in the corresponding pyopencv_to function
            return pyopencv_to_generic_vec(obj, value, info);
        }
        // For all other cases, all array data can be directly copied to std::vector data
        // Simple `memcpy` is not possible because NumPy array can reference a slice of the bigger array:
        // ```
        // arr = np.ones((8, 4, 5), dtype=np.int32)
        // convertible_to_vector_of_int = arr[:, 0, 1]
        // ```
        value.resize(static_cast<size_t>(PyArray_SIZE(array_obj)));
        const npy_intp item_step = PyArray_STRIDE(array_obj, 0) / PyArray_ITEMSIZE(array_obj);
        const Tp* data_ptr = static_cast<Tp*>(PyArray_DATA(array_obj));
        for (VecIt it = value.begin(); it != value.end(); ++it, data_ptr += item_step) {
            *it = *data_ptr;
        }
        return true;
    }

    static Napi::Value* from(const std::vector<Tp>& value)
    {
        if (value.empty())
        {
            return PyTuple_New(0);
        }
        return from(value, ::traits::IsRepresentableAsMatDataType<Tp>());
    }

private:
    static Napi::Value* from(const std::vector<Tp>& value, ::traits::FalseType)
    {
        // Underlying type is not representable as Mat Data Type
        return pyopencv_from_generic_vec(value);
    }

    static Napi::Value* from(const std::vector<Tp>& value, ::traits::TrueType)
    {
        // Underlying type is representable as Mat Data Type, so faster return type is available
        typedef cv::DataType<Tp> DType;
        typedef typename DType::channel_type UnderlyingArrayType;

        // If Mat is always exposed as NumPy array this code path can be reduced to the following snipped:
        //        Mat src(value);
        //        PyObject* array = pyopencv_from(src);
        //        return PyArray_Squeeze(reinterpret_cast<PyArrayObject*>(array));
        // This puts unnecessary restrictions on Mat object those might be avoided without losing the performance.
        // Moreover, this version is a bit faster, because it doesn't create temporary objects with reference counting.

        const NPY_TYPES target_type = asNumpyType<UnderlyingArrayType>();
        const int cols = DType::channels;
        Napi::Value* array = NULL;
        if (cols == 1)
        {
            npy_intp dims = static_cast<npy_intp>(value.size());
            array = PyArray_SimpleNew(1, &dims, target_type);
        }
        else
        {
            npy_intp dims[2] = {static_cast<npy_intp>(value.size()), cols};
            array = PyArray_SimpleNew(2, dims, target_type);
        }
        if(!array)
        {
            // NumPy arrays with shape (N, 1) and (N) are not equal, so correct error message should distinguish
            // them too.
            cv::String shape;
            if (cols > 1)
            {
                shape = cv::format("(%d x %d)", static_cast<int>(value.size()), cols);
            }
            else
            {
                shape = cv::format("(%d)", static_cast<int>(value.size()));
            }
            const cv::String error_message = cv::format("Can't allocate NumPy array for vector with dtype=%d and shape=%s",
                                                static_cast<int>(target_type), shape.c_str());
            emit_failmsg(PyExc_MemoryError, error_message.c_str());
            return array;
        }
        // Fill the array
        // PyArrayObject* array_obj = reinterpret_cast<PyArrayObject*>(array);
        Napi::Array* array_obj = reinterpret_cast<Napi::Array*>(array);
        UnderlyingArrayType* array_data = static_cast<UnderlyingArrayType*>(PyArray_DATA(array_obj));
        // if Tp is representable as Mat DataType, so the following cast is pretty safe...
        const UnderlyingArrayType* value_data = reinterpret_cast<const UnderlyingArrayType*>(value.data());
        memcpy(array_data, value_data, sizeof(UnderlyingArrayType) * value.size() * static_cast<size_t>(cols));
        return array;
    }
};

// --- tuple

#endif