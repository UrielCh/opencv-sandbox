// importer from mutiple files in openCV python folders

// #include <opencv2/opencv_modules.hpp>
#include <opencv2/opencv.hpp>

#ifdef HAVE_OPENCV_CORE

#include "opencv2/core/mat.hpp"
using namespace cv;

typedef std::vector<Range> vector_Range;

CV_JS_TO_CLASS(UMat);
CV_JS_FROM_CLASS(UMat);

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

template<> struct jsopencvVecConverter<cv::VideoCaptureAPIs>
{
    static bool to(Napi::Value* obj, std::vector<cv::VideoCaptureAPIs>& value, const ArgInfo& info)
    {
        return jsopencv_to_generic_vec(obj, value, info);
    }

    static Napi::Value from(const std::vector<cv::VideoCaptureAPIs>& value)
    {
        return jsopencv_from_generic_vec(value);
    }
};

template<>
bool jsopencv_to(PyObject *o, std::vector<cv::VideoCaptureAPIs>& apis, const ArgInfo& info)
{
  return pyopencvVecConverter<cv::VideoCaptureAPIs>::to(o, apis, info);
}

template<> bool pyopencv_to(Napi::Value* obj, cv::VideoCapture& stream, const ArgInfo& info)
{
    Ptr<VideoCapture> * obj_getp = nullptr;
    if (!pyopencv_VideoCapture_getp(obj, obj_getp))
        return (failmsgp("Incorrect type of self (must be 'VideoCapture' or its derivative)") != nullptr);

    stream = **obj_getp;
    return true;
}

#endif // HAVE_OPENCV_VIDEOIO
