#include <napi.h>
#include <./node/js_as_py.hpp>
#include <opencv2/opencv.hpp>
// 2nd test code

#include "node/cv2_convert.hpp"

static Napi::Value jsopencv_cv_imread(const Napi::CallbackInfo &info)
{
    using namespace cv;

    Napi::Value* jsobj_filename = NULL;
    String filename;

    Napi::Value* jsobj_flags = NULL;
    int flags=IMREAD_COLOR;

    Mat retval;

    const char* keywords[] = { "filename", "flags", NULL };
    if( JsArg_ParseTupleAndKeywords(info, "O|O:imread", (char**)keywords, &jsobj_filename, &jsobj_flags) &&
        jsopencv_to_safe(info, jsobj_filename, filename, ArgInfo("filename", 0)) &&
        jsopencv_to_safe(info, jsobj_flags, flags, ArgInfo("flags", 0)) )
    {
        //ERRWRAP2(
        retval = cv::imread(filename, flags);
        // );
        return jsopencv_from(info, retval);
    }

    return info.Env().Null();
}