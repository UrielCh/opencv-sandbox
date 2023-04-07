// importer from mutiple files in openCV python folders

#ifdef HAVE_OPENCV_CORE

#include "opencv2/core/mat.hpp"

typedef std::vector<Range> vector_Range;

CV_PY_TO_CLASS(UMat);
CV_PY_FROM_CLASS(UMat);

static bool cv_mappable_to(const Ptr<Mat>& src, Ptr<UMat>& dst)
{
    //dst.reset(new UMat(src->getUMat(ACCESS_RW)));
    dst.reset(new UMat());
    src->copyTo(*dst);
    return true;
}

static void* cv_UMat_queue()
{
    return cv::ocl::Queue::getDefault().ptr();
}

static void* cv_UMat_context()
{
    return cv::ocl::Context::getDefault().ptr();
}

static Mat cv_UMat_get(const UMat* _self)
{
    Mat m;
    m.allocator = &g_numpyAllocator;
    _self->copyTo(m);
    return m;
}

#endif

#ifdef HAVE_OPENCV_VIDEOIO
typedef std::vector<VideoCaptureAPIs> vector_VideoCaptureAPIs;
typedef std::vector<VideoCapture> vector_VideoCapture;

template<> struct pyopencvVecConverter<cv::VideoCaptureAPIs>
{
    static bool to(PyObject* obj, std::vector<cv::VideoCaptureAPIs>& value, const ArgInfo& info)
    {
        return pyopencv_to_generic_vec(obj, value, info);
    }

    static PyObject* from(const std::vector<cv::VideoCaptureAPIs>& value)
    {
        return pyopencv_from_generic_vec(value);
    }
};

template<>
bool pyopencv_to(PyObject *o, std::vector<cv::VideoCaptureAPIs>& apis, const ArgInfo& info)
{
  return pyopencvVecConverter<cv::VideoCaptureAPIs>::to(o, apis, info);
}

template<> bool pyopencv_to(PyObject* obj, cv::VideoCapture& stream, const ArgInfo& info)
{
    Ptr<VideoCapture> * obj_getp = nullptr;
    if (!pyopencv_VideoCapture_getp(obj, obj_getp))
        return (failmsgp("Incorrect type of self (must be 'VideoCapture' or its derivative)") != nullptr);

    stream = **obj_getp;
    return true;
}

#endif // HAVE_OPENCV_VIDEOIO
