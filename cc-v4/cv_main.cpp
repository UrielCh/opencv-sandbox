#include "cv_main.h"
#include "cv_mat_object.h"
#include "../cc-common/cv2_convert.h"
#include "../cc-common/js_as_py.h"
#include <iostream>
#include <opencv2/opencv.hpp>

// #define NEXRT_BUILD 1

bool jsopencv_to_safe(const Napi::Value* obj, cv::UMat img, const ArgInfo& argInfo)
{
    jsfailmsg(obj->Env(), "Conversion UMat Not implemented");
    return false;
}
// <cv::UMat>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::UMat & src) {
    jsfailmsg(info.Env(), "jsopencv_from<UMat> Not implemented");
    return info.Env().Null();
}

const std::string RED("\033[0;31m");
const std::string GREEN("\033[1;32m");
const std::string YELLOW("\033[1;33m");
const std::string CYAN("\033[0;36m");
const std::string MAGANTA("\033[0;35m");
const std::string RESET("\033[0m");
const std::string NEW(" (" + RED + "NEW" + RESET + ")");
 // L 15404
static Napi::Value jsopencv_cv_idft(const Napi::CallbackInfo &info)
{
    using namespace cv;

    jsPrepareArgumentConversionErrorsStorage(2);

    {
    Napi::Value* jsobj_src = NULL;
    Mat src;
    Napi::Value* jsobj_dst = NULL;
    Mat dst;
    Napi::Value* jsobj_flags = NULL;
    int flags=0;
    Napi::Value* jsobj_nonzeroRows = NULL;
    int nonzeroRows=0;

    const char* keywords[] = { "src", "dst", "flags", "nonzeroRows", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "O|OOO:idft", (char**)keywords, &jsobj_src, &jsobj_dst, &jsobj_flags, &jsobj_nonzeroRows) &&
        jsopencv_to_safe(jsobj_src, src, ArgInfo("src", 0)) &&
        jsopencv_to_safe(jsobj_dst, dst, ArgInfo("dst", 1)) &&
        jsopencv_to_safe(jsobj_flags, flags, ArgInfo("flags", 0)) &&
        jsopencv_to_safe(jsobj_nonzeroRows, nonzeroRows, ArgInfo("nonzeroRows", 0)))
    {
        ERRWRAP2_NAPI(info, cv::idft(src, dst, flags, nonzeroRows));
        return jsopencv_from(info, dst);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    

    {
    Napi::Value* jsobj_src = NULL;
    UMat src;
    Napi::Value* jsobj_dst = NULL;
    UMat dst;
    Napi::Value* jsobj_flags = NULL;
    int flags=0;
    Napi::Value* jsobj_nonzeroRows = NULL;
    int nonzeroRows=0;

    const char* keywords[] = { "src", "dst", "flags", "nonzeroRows", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "O|OOO:idft", (char**)keywords, &jsobj_src, &jsobj_dst, &jsobj_flags, &jsobj_nonzeroRows) &&
        jsopencv_to_safe(jsobj_src, src, ArgInfo("src", 0)) &&
        jsopencv_to_safe(jsobj_dst, dst, ArgInfo("dst", 1)) &&
        jsopencv_to_safe(jsobj_flags, flags, ArgInfo("flags", 0)) &&
        jsopencv_to_safe(jsobj_nonzeroRows, nonzeroRows, ArgInfo("nonzeroRows", 0)))
    {
        ERRWRAP2_NAPI(info, cv::idft(src, dst, flags, nonzeroRows));
        return jsopencv_from(info, dst);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "idft");

    return info.Env().Null();
}

#ifdef HAVE_OPENCV_PHOTO
static Napi::Value jsopencv_cv_illuminationChange(const Napi::CallbackInfo &info)
{
    using namespace cv;

    jsPrepareArgumentConversionErrorsStorage(2);

    {
    Napi::Value* jsobj_src = NULL;
    Mat src;
    Napi::Value* jsobj_mask = NULL;
    Mat mask;
    Napi::Value* jsobj_dst = NULL;
    Mat dst;
    Napi::Value* jsobj_alpha = NULL;
    float alpha=0.2f;
    Napi::Value* jsobj_beta = NULL;
    float beta=0.4f;

    const char* keywords[] = { "src", "mask", "dst", "alpha", "beta", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OO|OOO:illuminationChange", (char**)keywords, &jsobj_src, &jsobj_mask, &jsobj_dst, &jsobj_alpha, &jsobj_beta) &&
        jsopencv_to_safe(jsobj_src, src, ArgInfo("src", 0)) &&
        jsopencv_to_safe(jsobj_mask, mask, ArgInfo("mask", 0)) &&
        jsopencv_to_safe(jsobj_dst, dst, ArgInfo("dst", 1)) &&
        jsopencv_to_safe(jsobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        jsopencv_to_safe(jsobj_beta, beta, ArgInfo("beta", 0)))
    {
        ERRWRAP2_NAPI(info, cv::illuminationChange(src, mask, dst, alpha, beta));
        return jsopencv_from(info, dst);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    

    {
    Napi::Value* jsobj_src = NULL;
    UMat src;
    Napi::Value* jsobj_mask = NULL;
    UMat mask;
    Napi::Value* jsobj_dst = NULL;
    UMat dst;
    Napi::Value* jsobj_alpha = NULL;
    float alpha=0.2f;
    Napi::Value* jsobj_beta = NULL;
    float beta=0.4f;

    const char* keywords[] = { "src", "mask", "dst", "alpha", "beta", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OO|OOO:illuminationChange", (char**)keywords, &jsobj_src, &jsobj_mask, &jsobj_dst, &jsobj_alpha, &jsobj_beta) &&
        jsopencv_to_safe(jsobj_src, src, ArgInfo("src", 0)) &&
        jsopencv_to_safe(jsobj_mask, mask, ArgInfo("mask", 0)) &&
        jsopencv_to_safe(jsobj_dst, dst, ArgInfo("dst", 1)) &&
        jsopencv_to_safe(jsobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        jsopencv_to_safe(jsobj_beta, beta, ArgInfo("beta", 0)))
    {
        ERRWRAP2_NAPI(info, cv::illuminationChange(src, mask, dst, alpha, beta));
        return jsopencv_from(info, dst);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "illuminationChange");

    return info.Env().Null();
}
#endif

static Napi::Value jsopencv_cv_imcount(const Napi::CallbackInfo &info)
{
    using namespace cv;

    Napi::Value* jsobj_filename = NULL;
    String filename;
    Napi::Value* jsobj_flags = NULL;
    int flags=IMREAD_ANYCOLOR;
    size_t retval;

    const char* keywords[] = { "filename", "flags", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "O|O:imcount", (char**)keywords, &jsobj_filename, &jsobj_flags) &&
        jsopencv_to_safe(jsobj_filename, filename, ArgInfo("filename", 0)) &&
        jsopencv_to_safe(jsobj_flags, flags, ArgInfo("flags", 0)))
    {
        ERRWRAP2_NAPI(info, retval = cv::imcount(filename, flags));
        return jsopencv_from(info, retval);
    }

    return info.Env().Null();
}

static Napi::Value jsopencv_cv_imdecode(const Napi::CallbackInfo &info)
{
    using namespace cv;

    jsPrepareArgumentConversionErrorsStorage(2);

    {
    Napi::Value* jsobj_buf = NULL;
    Mat buf;
    Napi::Value* jsobj_flags = NULL;
    int flags=0;
    Mat retval;

    const char* keywords[] = { "buf", "flags", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OO:imdecode", (char**)keywords, &jsobj_buf, &jsobj_flags) &&
        jsopencv_to_safe(jsobj_buf, buf, ArgInfo("buf", 0)) &&
        jsopencv_to_safe(jsobj_flags, flags, ArgInfo("flags", 0)))
    {
        ERRWRAP2_NAPI(info, retval = cv::imdecode(buf, flags));
        return jsopencv_from(info, retval);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    

    {
    Napi::Value* jsobj_buf = NULL;
    UMat buf;
    Napi::Value* jsobj_flags = NULL;
    int flags=0;
    Mat retval;

    const char* keywords[] = { "buf", "flags", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OO:imdecode", (char**)keywords, &jsobj_buf, &jsobj_flags) &&
        jsopencv_to_safe(jsobj_buf, buf, ArgInfo("buf", 0)) &&
        jsopencv_to_safe(jsobj_flags, flags, ArgInfo("flags", 0)))
    {
        ERRWRAP2_NAPI(info, retval = cv::imdecode(buf, flags));
        return jsopencv_from(info, retval);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "imdecode");

    return info.Env().Null();
}

static Napi::Value jsopencv_cv_imdecodemulti(const Napi::CallbackInfo &info)
{
    using namespace cv;

    jsPrepareArgumentConversionErrorsStorage(2);

    {
    Napi::Value* jsobj_buf = NULL;
    Mat buf;
    Napi::Value* jsobj_flags = NULL;
    int flags=0;
    Napi::Value* jsobj_mats = NULL;
    vector_Mat mats;
    bool retval;

    const char* keywords[] = { "buf", "flags", "mats", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OO|O:imdecodemulti", (char**)keywords, &jsobj_buf, &jsobj_flags, &jsobj_mats) &&
        jsopencv_to_safe(jsobj_buf, buf, ArgInfo("buf", 0)) &&
        jsopencv_to_safe(jsobj_flags, flags, ArgInfo("flags", 0)) &&
        jsopencv_to_safe(jsobj_mats, mats, ArgInfo("mats", 1)))
    {
        ERRWRAP2_NAPI(info, retval = cv::imdecodemulti(buf, flags, mats));
        return Js_BuildValue(info, "(NN)", jsopencv_from(info, retval), jsopencv_from(info, mats));
    }


        jsPopulateArgumentConversionErrors(info);
    }
    

    {
    Napi::Value* jsobj_buf = NULL;
    UMat buf;
    Napi::Value* jsobj_flags = NULL;
    int flags=0;
    Napi::Value* jsobj_mats = NULL;
    vector_Mat mats;
    bool retval;

    const char* keywords[] = { "buf", "flags", "mats", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OO|O:imdecodemulti", (char**)keywords, &jsobj_buf, &jsobj_flags, &jsobj_mats) &&
        jsopencv_to_safe(jsobj_buf, buf, ArgInfo("buf", 0)) &&
        jsopencv_to_safe(jsobj_flags, flags, ArgInfo("flags", 0)) &&
        jsopencv_to_safe(jsobj_mats, mats, ArgInfo("mats", 1)))
    {
        ERRWRAP2_NAPI(info, retval = cv::imdecodemulti(buf, flags, mats));
        return Js_BuildValue(info, "(NN)", jsopencv_from(info, retval), jsopencv_from(info, mats));
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "imdecodemulti");

    return info.Env().Null();
}

static Napi::Value jsopencv_cv_imencode(const Napi::CallbackInfo &info)
{
    using namespace cv;

    jsPrepareArgumentConversionErrorsStorage(2);

    {
    Napi::Value* jsobj_ext = NULL;
    String ext;
    Napi::Value* jsobj_img = NULL;
    Mat img;
    vector_uchar buf;
    Napi::Value* jsobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "ext", "img", "params", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OO|O:imencode", (char**)keywords, &jsobj_ext, &jsobj_img, &jsobj_params) &&
        jsopencv_to_safe(jsobj_ext, ext, ArgInfo("ext", 0)) &&
        jsopencv_to_safe(jsobj_img, img, ArgInfo("img", 0)) &&
        jsopencv_to_safe(jsobj_params, params, ArgInfo("params", 0)))
    {
        ERRWRAP2_NAPI(info, retval = cv::imencode(ext, img, buf, params));
        return Js_BuildValue(info, "(NN)", jsopencv_from(info, retval), jsopencv_from(info, buf));
    }


        jsPopulateArgumentConversionErrors(info);
    }
    

    {
    Napi::Value* jsobj_ext = NULL;
    String ext;
    Napi::Value* jsobj_img = NULL;
    UMat img;
    vector_uchar buf;
    Napi::Value* jsobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "ext", "img", "params", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OO|O:imencode", (char**)keywords, &jsobj_ext, &jsobj_img, &jsobj_params) &&
        jsopencv_to_safe(jsobj_ext, ext, ArgInfo("ext", 0)) &&
        jsopencv_to_safe(jsobj_img, img, ArgInfo("img", 0)) &&
        jsopencv_to_safe(jsobj_params, params, ArgInfo("params", 0)))
    {
        ERRWRAP2_NAPI(info, retval = cv::imencode(ext, img, buf, params));
        return Js_BuildValue(info, "(NN)", jsopencv_from(info, retval), jsopencv_from(info, buf));
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "imencode");

    return info.Env().Null();
}

static Napi::Value jsopencv_cv_imread(const Napi::CallbackInfo &info)
{
    using namespace cv;

    Napi::Value* jsobj_filename = NULL;
    String filename;
    Napi::Value* jsobj_flags = NULL;
    int flags=IMREAD_COLOR;
    Mat retval;

    const char* keywords[] = { "filename", "flags", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "O|O:imread", (char**)keywords, &jsobj_filename, &jsobj_flags) &&
        jsopencv_to_safe(jsobj_filename, filename, ArgInfo("filename", 0)) &&
        jsopencv_to_safe(jsobj_flags, flags, ArgInfo("flags", 0)))
    {
        ERRWRAP2_NAPI(info, retval = cv::imread(filename, flags));
        return jsopencv_from(info, retval);
    }

    return info.Env().Null();
}

static Napi::Value jsopencv_cv_imreadmulti(const Napi::CallbackInfo &info)
{
    using namespace cv;

    jsPrepareArgumentConversionErrorsStorage(2);

    {
    Napi::Value* jsobj_filename = NULL;
    String filename;
    Napi::Value* jsobj_mats = NULL;
    vector_Mat mats;
    Napi::Value* jsobj_flags = NULL;
    int flags=IMREAD_ANYCOLOR;
    bool retval;

    const char* keywords[] = { "filename", "mats", "flags", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "O|OO:imreadmulti", (char**)keywords, &jsobj_filename, &jsobj_mats, &jsobj_flags) &&
        jsopencv_to_safe(jsobj_filename, filename, ArgInfo("filename", 0)) &&
        jsopencv_to_safe(jsobj_mats, mats, ArgInfo("mats", 1)) &&
        jsopencv_to_safe(jsobj_flags, flags, ArgInfo("flags", 0)))
    {
        ERRWRAP2_NAPI(info, retval = cv::imreadmulti(filename, mats, flags));
        return Js_BuildValue(info, "(NN)", jsopencv_from(info, retval), jsopencv_from(info, mats));
    }


        jsPopulateArgumentConversionErrors(info);
    }
    

    {
    Napi::Value* jsobj_filename = NULL;
    String filename;
    Napi::Value* jsobj_mats = NULL;
    vector_Mat mats;
    Napi::Value* jsobj_start = NULL;
    int start=0;
    Napi::Value* jsobj_count = NULL;
    int count=0;
    Napi::Value* jsobj_flags = NULL;
    int flags=IMREAD_ANYCOLOR;
    bool retval;

    const char* keywords[] = { "filename", "start", "count", "mats", "flags", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OOO|OO:imreadmulti", (char**)keywords, &jsobj_filename, &jsobj_start, &jsobj_count, &jsobj_mats, &jsobj_flags) &&
        jsopencv_to_safe(jsobj_filename, filename, ArgInfo("filename", 0)) &&
        jsopencv_to_safe(jsobj_mats, mats, ArgInfo("mats", 1)) &&
        jsopencv_to_safe(jsobj_start, start, ArgInfo("start", 0)) &&
        jsopencv_to_safe(jsobj_count, count, ArgInfo("count", 0)) &&
        jsopencv_to_safe(jsobj_flags, flags, ArgInfo("flags", 0)))
    {
        ERRWRAP2_NAPI(info, retval = cv::imreadmulti(filename, mats, start, count, flags));
        return Js_BuildValue(info, "(NN)", jsopencv_from(info, retval), jsopencv_from(info, mats));
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "imreadmulti");

    return info.Env().Null();
}

static Napi::Value jsopencv_cv_imshow(const Napi::CallbackInfo &info)
{
    using namespace cv;

    jsPrepareArgumentConversionErrorsStorage(3);

    {
    Napi::Value* jsobj_winname = NULL;
    String winname;
    Napi::Value* jsobj_mat = NULL;
    Mat mat;

    const char* keywords[] = { "winname", "mat", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OO:imshow", (char**)keywords, &jsobj_winname, &jsobj_mat) &&
        jsopencv_to_safe(jsobj_winname, winname, ArgInfo("winname", 0)) &&
        jsopencv_to_safe(jsobj_mat, mat, ArgInfo("mat", 0)))
    {
        ERRWRAP2_NAPI(info, cv::imshow(winname, mat));
        return info.Env().Null();;
    }


        jsPopulateArgumentConversionErrors(info);
    }
    

    // {
    // Napi::Value* jsobj_winname = NULL;
    // String winname;
    // Napi::Value* jsobj_mat = NULL;
    // cuda::GpuMat mat;
// 
    // const char* keywords[] = { "winname", "mat", NULL };
    // if (JsArg_ParseTupleAndKeywords(info, "OO:imshow", (char**)keywords, &jsobj_winname, &jsobj_mat) &&
    //     jsopencv_to_safe(jsobj_winname, winname, ArgInfo("winname", 0)) &&
    //     jsopencv_to_safe(jsobj_mat, mat, ArgInfo("mat", 0)))
    // {
    //     ERRWRAP2_NAPI(info, cv::imshow(winname, mat));
    //     return info.Env().Null();;
    // }
// 
// 
    //     jsPopulateArgumentConversionErrors(info);
    // }
    

    {
    Napi::Value* jsobj_winname = NULL;
    String winname;
    Napi::Value* jsobj_mat = NULL;
    UMat mat;

    const char* keywords[] = { "winname", "mat", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OO:imshow", (char**)keywords, &jsobj_winname, &jsobj_mat) &&
        jsopencv_to_safe(jsobj_winname, winname, ArgInfo("winname", 0)) &&
        jsopencv_to_safe(jsobj_mat, mat, ArgInfo("mat", 0)))
    {
        ERRWRAP2_NAPI(info, cv::imshow(winname, mat));
        return info.Env().Null();;
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "imshow");

    return info.Env().Null();
}

static Napi::Value jsopencv_cv_imwrite(const Napi::CallbackInfo &info)
{
    using namespace cv;

    jsPrepareArgumentConversionErrorsStorage(2);

    {
    Napi::Value* jsobj_filename = NULL;
    String filename;
    Napi::Value* jsobj_img = NULL;
    Mat img;
    Napi::Value* jsobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "filename", "img", "params", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OO|O:imwrite", (char**)keywords, &jsobj_filename, &jsobj_img, &jsobj_params) &&
        jsopencv_to_safe(jsobj_filename, filename, ArgInfo("filename", 0)) &&
        jsopencv_to_safe(jsobj_img, img, ArgInfo("img", 0)) &&
        jsopencv_to_safe(jsobj_params, params, ArgInfo("params", 0)))
    {
        ERRWRAP2_NAPI(info, retval = cv::imwrite(filename, img, params));
        return jsopencv_from(info, retval);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    

    {
    Napi::Value* jsobj_filename = NULL;
    String filename;
    Napi::Value* jsobj_img = NULL;
    UMat img;
    Napi::Value* jsobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "filename", "img", "params", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OO|O:imwrite", (char**)keywords, &jsobj_filename, &jsobj_img, &jsobj_params) &&
        jsopencv_to_safe(jsobj_filename, filename, ArgInfo("filename", 0)) &&
        jsopencv_to_safe(jsobj_img, img, ArgInfo("img", 0)) &&
        jsopencv_to_safe(jsobj_params, params, ArgInfo("params", 0)))
    {
        ERRWRAP2_NAPI(info, retval = cv::imwrite(filename, img, params));
        return jsopencv_from(info, retval);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "imwrite");

    return info.Env().Null();
}

static Napi::Value jsopencv_cv_imwritemulti(const Napi::CallbackInfo &info)
{
    using namespace cv;

    jsPrepareArgumentConversionErrorsStorage(2);

    {
    Napi::Value* jsobj_filename = NULL;
    String filename;
    Napi::Value* jsobj_img = NULL;
    vector_Mat img;
    Napi::Value* jsobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "filename", "img", "params", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OO|O:imwritemulti", (char**)keywords, &jsobj_filename, &jsobj_img, &jsobj_params) &&
        jsopencv_to_safe(jsobj_filename, filename, ArgInfo("filename", 0)) &&
        jsopencv_to_safe(jsobj_img, img, ArgInfo("img", 0)) &&
        jsopencv_to_safe(jsobj_params, params, ArgInfo("params", 0)))
    {
        ERRWRAP2_NAPI(info, retval = cv::imwritemulti(filename, img, params));
        return jsopencv_from(info, retval);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    

    {
    Napi::Value* jsobj_filename = NULL;
    String filename;
    Napi::Value* jsobj_img = NULL;
    vector_UMat img;
    Napi::Value* jsobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "filename", "img", "params", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OO|O:imwritemulti", (char**)keywords, &jsobj_filename, &jsobj_img, &jsobj_params) &&
        jsopencv_to_safe(jsobj_filename, filename, ArgInfo("filename", 0)) &&
        jsopencv_to_safe(jsobj_img, img, ArgInfo("img", 0)) &&
        jsopencv_to_safe(jsobj_params, params, ArgInfo("params", 0)))
    {
        ERRWRAP2_NAPI(info, retval = cv::imwritemulti(filename, img, params));
        return jsopencv_from(info, retval);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "imwritemulti");

    return info.Env().Null();
}

static Napi::Value jsopencv_cv_inRange(const Napi::CallbackInfo &info)
{
    using namespace cv;

    jsPrepareArgumentConversionErrorsStorage(2);

    {
    Napi::Value* jsobj_src = NULL;
    Mat src;
    Napi::Value* jsobj_lowerb = NULL;
    Mat lowerb;
    Napi::Value* jsobj_upperb = NULL;
    Mat upperb;
    Napi::Value* jsobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "lowerb", "upperb", "dst", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OOO|O:inRange", (char**)keywords, &jsobj_src, &jsobj_lowerb, &jsobj_upperb, &jsobj_dst) &&
        jsopencv_to_safe(jsobj_src, src, ArgInfo("src", 0)) &&
        jsopencv_to_safe(jsobj_lowerb, lowerb, ArgInfo("lowerb", 0)) &&
        jsopencv_to_safe(jsobj_upperb, upperb, ArgInfo("upperb", 0)) &&
        jsopencv_to_safe(jsobj_dst, dst, ArgInfo("dst", 1)))
    {
        ERRWRAP2_NAPI(info, cv::inRange(src, lowerb, upperb, dst));
        return jsopencv_from(info, dst);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    

    {
    Napi::Value* jsobj_src = NULL;
    UMat src;
    Napi::Value* jsobj_lowerb = NULL;
    UMat lowerb;
    Napi::Value* jsobj_upperb = NULL;
    UMat upperb;
    Napi::Value* jsobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "lowerb", "upperb", "dst", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OOO|O:inRange", (char**)keywords, &jsobj_src, &jsobj_lowerb, &jsobj_upperb, &jsobj_dst) &&
        jsopencv_to_safe(jsobj_src, src, ArgInfo("src", 0)) &&
        jsopencv_to_safe(jsobj_lowerb, lowerb, ArgInfo("lowerb", 0)) &&
        jsopencv_to_safe(jsobj_upperb, upperb, ArgInfo("upperb", 0)) &&
        jsopencv_to_safe(jsobj_dst, dst, ArgInfo("dst", 1)))
    {
        ERRWRAP2_NAPI(info, cv::inRange(src, lowerb, upperb, dst));
        return jsopencv_from(info, dst);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "inRange");

    return info.Env().Null();
}

#ifdef HAVE_OPENCV_CALIB3D
static Napi::Value jsopencv_cv_initCameraMatrix2D(const Napi::CallbackInfo &info)
{
    using namespace cv;

    jsPrepareArgumentConversionErrorsStorage(2);

    {
    Napi::Value* jsobj_objectPoints = NULL;
    vector_Mat objectPoints;
    Napi::Value* jsobj_imagePoints = NULL;
    vector_Mat imagePoints;
    Napi::Value* jsobj_imageSize = NULL;
    Size imageSize;
    Napi::Value* jsobj_aspectRatio = NULL;
    double aspectRatio=1.0;
    Mat retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "imageSize", "aspectRatio", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OOO|O:initCameraMatrix2D", (char**)keywords, &jsobj_objectPoints, &jsobj_imagePoints, &jsobj_imageSize, &jsobj_aspectRatio) &&
        jsopencv_to_safe(jsobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        jsopencv_to_safe(jsobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        jsopencv_to_safe(jsobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        jsopencv_to_safe(jsobj_aspectRatio, aspectRatio, ArgInfo("aspectRatio", 0)))
    {
        ERRWRAP2_NAPI(info, retval = cv::initCameraMatrix2D(objectPoints, imagePoints, imageSize, aspectRatio));
        return jsopencv_from(info, retval);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    

    {
    Napi::Value* jsobj_objectPoints = NULL;
    vector_UMat objectPoints;
    Napi::Value* jsobj_imagePoints = NULL;
    vector_UMat imagePoints;
    Napi::Value* jsobj_imageSize = NULL;
    Size imageSize;
    Napi::Value* jsobj_aspectRatio = NULL;
    double aspectRatio=1.0;
    Mat retval;

    const char* keywords[] = { "objectPoints", "imagePoints", "imageSize", "aspectRatio", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OOO|O:initCameraMatrix2D", (char**)keywords, &jsobj_objectPoints, &jsobj_imagePoints, &jsobj_imageSize, &jsobj_aspectRatio) &&
        jsopencv_to_safe(jsobj_objectPoints, objectPoints, ArgInfo("objectPoints", 0)) &&
        jsopencv_to_safe(jsobj_imagePoints, imagePoints, ArgInfo("imagePoints", 0)) &&
        jsopencv_to_safe(jsobj_imageSize, imageSize, ArgInfo("imageSize", 0)) &&
        jsopencv_to_safe(jsobj_aspectRatio, aspectRatio, ArgInfo("aspectRatio", 0)))
    {
        ERRWRAP2_NAPI(info, retval = cv::initCameraMatrix2D(objectPoints, imagePoints, imageSize, aspectRatio));
        return jsopencv_from(info, retval);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "initCameraMatrix2D");

    return info.Env().Null();
}
#endif

// L 14760
static Napi::Value jsopencv_cv_getVersionMajor(const Napi::CallbackInfo &info)
{
    using namespace cv;

    int retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(info, retval = cv::getVersionMajor());
        return jsopencv_from(info, retval);
    }

    return info.Env().Null();
}

static Napi::Value jsopencv_cv_getVersionMinor(const Napi::CallbackInfo &info)
{
    using namespace cv;

    int retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(info, retval = cv::getVersionMinor());
        return jsopencv_from(info, retval);
    }

    return info.Env().Null();
}

static Napi::Value jsopencv_cv_getVersionRevision(const Napi::CallbackInfo &info)
{
    using namespace cv;

    int retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(info, retval = cv::getVersionRevision());
        return jsopencv_from(info, retval);
    }

    return info.Env().Null();
}



Napi::Object cvmainInit(Napi::Env env, Napi::Object exports)
{

    exports.Set("idft", Napi::Function::New(env, jsopencv_cv_idft));
    #ifdef HAVE_OPENCV_PHOTO
    exports.Set("illuminationChange", Napi::Function::New(env, jsopencv_cv_illuminationChange));
    #endif
    exports.Set("imcount", Napi::Function::New(env, jsopencv_cv_imcount));
    exports.Set("imdecode", Napi::Function::New(env, jsopencv_cv_imdecode));
    exports.Set("imdecodemulti", Napi::Function::New(env, jsopencv_cv_imdecodemulti));
    exports.Set("imencode", Napi::Function::New(env, jsopencv_cv_imencode));
    exports.Set("imread", Napi::Function::New(env, jsopencv_cv_imread));
    exports.Set("imreadmulti", Napi::Function::New(env, jsopencv_cv_imreadmulti));
    exports.Set("imshow", Napi::Function::New(env, jsopencv_cv_imshow));
    exports.Set("imwrite", Napi::Function::New(env, jsopencv_cv_imwrite));
    exports.Set("imwritemulti", Napi::Function::New(env, jsopencv_cv_imwritemulti));
    exports.Set("inRange", Napi::Function::New(env, jsopencv_cv_inRange));
    #ifdef HAVE_OPENCV_CALIB3D
    exports.Set("initCameraMatrix2D", Napi::Function::New(env, jsopencv_cv_initCameraMatrix2D));
    #endif

    // exports.Set("resize", Napi::Function::New(env, jsopencv_cv_resize));
    exports.Set("getVersionMajor", Napi::Function::New(env, jsopencv_cv_getVersionMajor));
    exports.Set("getVersionMinor", Napi::Function::New(env, jsopencv_cv_getVersionMinor));
    exports.Set("getVersionRevision", Napi::Function::New(env, jsopencv_cv_getVersionRevision));

    return exports;
}
