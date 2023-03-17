#include <napi.h>
#include <parse.hh>
// #include <node_api.h>
#include <opencv2/opencv.hpp>
// 2nd test code

#include "node/cv2_convert.hpp"

static Napi::Value pyopencv_cv_imread(const Napi::CallbackInfo &info)
{
    using namespace cv;

    Napi::Value* pyobj_filename = NULL;
    String filename;

    Napi::Value* pyobj_flags = NULL;
    int flags=IMREAD_COLOR;

    Mat retval;

    const char* keywords[] = { "filename", "flags", NULL };
    if( NodeArg_ParseTupleAndKeywords(info, "O|O:imread", (char**)keywords, &pyobj_filename, &pyobj_flags) &&
        nodeopencv_to_safe(info, pyobj_filename, filename, ArgInfo("filename", 0)) &&
        nodeopencv_to_safe(info, pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        //ERRWRAP2(
        retval = cv::imread(filename, flags);
        // );
        return nodeopencv_from(info, retval);
    }

    return info.Env().Null();
}
