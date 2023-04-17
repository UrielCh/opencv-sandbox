#include <napi.h>
#include <opencv2/opencv.hpp>
#include "../cc-common/js_as_py.h"
#include "../cc-common/cv2_convert.h"
// #include "./jsopencv_generated_enums.h"
// #include "../cc-common/cv2_macro.hpp"


// #include "../cc-generated/jsopencv_generated_include.h"
 
 // L 15404
static Napi::Value jsopencv_cv_idft(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

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
        ERRWRAP2_NAPI(env, cv::idft(src, dst, flags, nonzeroRows));
        return jsopencv_from(env, dst);
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
        ERRWRAP2_NAPI(env, cv::idft(src, dst, flags, nonzeroRows));
        return jsopencv_from(env, dst);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "idft");

    return env.Null();
}

#ifdef HAVE_OPENCV_PHOTO
static Napi::Value jsopencv_cv_illuminationChange(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

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
        ERRWRAP2_NAPI(env, cv::illuminationChange(src, mask, dst, alpha, beta));
        return jsopencv_from(env, dst);
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
        ERRWRAP2_NAPI(env, cv::illuminationChange(src, mask, dst, alpha, beta));
        return jsopencv_from(env, dst);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "illuminationChange");

    return env.Null();
}
#endif

static Napi::Value jsopencv_cv_imcount(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

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
        ERRWRAP2_NAPI(env, retval = cv::imcount(filename, flags));
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

static Napi::Value jsopencv_cv_imdecode(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

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
        ERRWRAP2_NAPI(env, retval = cv::imdecode(buf, flags));
        return jsopencv_from(env, retval);
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
        ERRWRAP2_NAPI(env, retval = cv::imdecode(buf, flags));
        return jsopencv_from(env, retval);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "imdecode");

    return env.Null();
}

static Napi::Value jsopencv_cv_imdecodemulti(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

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
        ERRWRAP2_NAPI(env, retval = cv::imdecodemulti(buf, flags, mats));
        return Js_BuildValue(env, "(NN)", jsopencv_from(env, retval), jsopencv_from(env, mats));
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
        ERRWRAP2_NAPI(env, retval = cv::imdecodemulti(buf, flags, mats));
        return Js_BuildValue(env, "(NN)", jsopencv_from(env, retval), jsopencv_from(env, mats));
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "imdecodemulti");

    return env.Null();
}

static Napi::Value jsopencv_cv_imencode(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

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
        ERRWRAP2_NAPI(env, retval = cv::imencode(ext, img, buf, params));
        return Js_BuildValue(env, "(NN)", jsopencv_from(env, retval), jsopencv_from(env, buf));
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
        ERRWRAP2_NAPI(env, retval = cv::imencode(ext, img, buf, params));
        return Js_BuildValue(env, "(NN)", jsopencv_from(env, retval), jsopencv_from(env, buf));
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "imencode");

    return env.Null();
}

static Napi::Value jsopencv_cv_imread(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

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
        ERRWRAP2_NAPI(env, retval = cv::imread(filename, flags));
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

static Napi::Value jsopencv_cv_imreadmulti(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

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
        ERRWRAP2_NAPI(env, retval = cv::imreadmulti(filename, mats, flags));
        return Js_BuildValue(env, "(NN)", jsopencv_from(env, retval), jsopencv_from(env, mats));
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
        ERRWRAP2_NAPI(env, retval = cv::imreadmulti(filename, mats, start, count, flags));
        return Js_BuildValue(env, "(NN)", jsopencv_from(env, retval), jsopencv_from(env, mats));
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "imreadmulti");

    return env.Null();
}

static Napi::Value jsopencv_cv_imshow(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

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
        ERRWRAP2_NAPI(env, cv::imshow(winname, mat));
        return env.Null();
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
    //     ERRWRAP2_NAPI(env, cv::imshow(winname, mat));
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
        ERRWRAP2_NAPI(env, cv::imshow(winname, mat));
        return info.Env().Null();;
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "imshow");

    return env.Null();
}

static Napi::Value jsopencv_cv_imwrite(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

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
        ERRWRAP2_NAPI(env, retval = cv::imwrite(filename, img, params));
        return jsopencv_from(env, retval);
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
        ERRWRAP2_NAPI(env, retval = cv::imwrite(filename, img, params));
        return jsopencv_from(env, retval);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "imwrite");

    return env.Null();
}

static Napi::Value jsopencv_cv_imwritemulti(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

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
        ERRWRAP2_NAPI(env, retval = cv::imwritemulti(filename, img, params));
        return jsopencv_from(env, retval);
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
        ERRWRAP2_NAPI(env, retval = cv::imwritemulti(filename, img, params));
        return jsopencv_from(env, retval);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "imwritemulti");

    return env.Null();
}

static Napi::Value jsopencv_cv_inRange(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

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
        ERRWRAP2_NAPI(env, cv::inRange(src, lowerb, upperb, dst));
        return jsopencv_from(env, dst);
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
        ERRWRAP2_NAPI(env, cv::inRange(src, lowerb, upperb, dst));
        return jsopencv_from(env, dst);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "inRange");

    return env.Null();
}

#ifdef HAVE_OPENCV_CALIB3D
static Napi::Value jsopencv_cv_initCameraMatrix2D(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

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
        ERRWRAP2_NAPI(env, retval = cv::initCameraMatrix2D(objectPoints, imagePoints, imageSize, aspectRatio));
        return jsopencv_from(env, retval);
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
        ERRWRAP2_NAPI(env, retval = cv::initCameraMatrix2D(objectPoints, imagePoints, imageSize, aspectRatio));
        return jsopencv_from(env, retval);
    }


        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "initCameraMatrix2D");

    return env.Null();
}
#endif

// L 14760
static Napi::Value jsopencv_cv_getVersionMajor(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

    int retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = cv::getVersionMajor());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

static Napi::Value jsopencv_cv_getVersionMinor(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

    int retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = cv::getVersionMinor());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

static Napi::Value jsopencv_cv_getVersionRevision(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

    int retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = cv::getVersionRevision());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}
