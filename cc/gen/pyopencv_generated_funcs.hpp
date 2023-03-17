#include "common.h"
#include <../parse.hh>
#include "../node/cv2_util.hpp"
#include "../node/cv2_convert.hpp"
#include <opencv2/opencv.hpp>

static Napi::Value jsopencv_cv_haveImageReader(const Napi::CallbackInfo &info)
{
    using namespace cv;

    Napi::Value* jsobj_filename = NULL;
    String filename;
    bool retval;

    const char* keywords[] = { "filename", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "O:haveImageReader", (char**)keywords, &jsobj_filename) &&
        nodeopencv_to_safe(info, jsobj_filename, filename, ArgInfo("filename", 0)) )
    {
        ERRWRAP2(retval = cv::haveImageReader(filename));
        return nodeopencv_from(info, retval);
    }

    return info.Env().Null();
}

static Napi::Value jsopencv_cv_haveImageWriter(const Napi::CallbackInfo &info)
{
    using namespace cv;

    Napi::Value* jsobj_filename = NULL;
    String filename;
    bool retval;

    const char* keywords[] = { "filename", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "O:haveImageWriter", (char**)keywords, &jsobj_filename) &&
        nodeopencv_to_safe(info, jsobj_filename, filename, ArgInfo("filename", 0)) )
    {
        ERRWRAP2(retval = cv::haveImageWriter(filename));
        return nodeopencv_from(info, retval);
    }

    return info.Env().Null();
}


static Napi::Value jsopencv_cv_imcount(const Napi::CallbackInfo &info)
{
    using namespace cv;

    Napi::Value* jsobj_filename = NULL;
    String filename;
    Napi::Value* jsobj_flags = NULL;
    int flags=IMREAD_ANYCOLOR;
    size_t retval;

    const char* keywords[] = { "filename", "flags", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "O|O:imcount", (char**)keywords, &jsobj_filename, &jsobj_flags) &&
        nodeopencv_to_safe(info, jsobj_filename, filename, ArgInfo("filename", 0)) &&
        nodeopencv_to_safe(info, jsobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imcount(filename, flags));
        return nodeopencv_from(info, retval);
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
    if(  NodeArg_ParseTupleAndKeywords(info, "OO:imdecode", (char**)keywords, &jsobj_buf, &jsobj_flags) &&
        nodeopencv_to_safe(info, jsobj_buf, buf, ArgInfo("buf", 0)) &&
        nodeopencv_to_safe(info, jsobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imdecode(buf, flags));
        return nodeopencv_from(info, retval);
    }
        jsPopulateArgumentConversionErrors();
    }
    

    {
    Napi::Value* jsobj_buf = NULL;
    UMat buf;
    Napi::Value* jsobj_flags = NULL;
    int flags=0;
    Mat retval;

    const char* keywords[] = { "buf", "flags", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "OO:imdecode", (char**)keywords, &jsobj_buf, &jsobj_flags) &&
        nodeopencv_to_safe(info, jsobj_buf, buf, ArgInfo("buf", 0)) &&
        nodeopencv_to_safe(info, jsobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imdecode(buf, flags));
        return nodeopencv_from(info, retval);
    }


        jsPopulateArgumentConversionErrors();
    }
    jsRaiseCVOverloadException("imdecode");

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
    if(  NodeArg_ParseTupleAndKeywords(info, "OO|O:imdecodemulti", (char**)keywords, &jsobj_buf, &jsobj_flags, &jsobj_mats) &&
        nodeopencv_to_safe(info, jsobj_buf, buf, ArgInfo("buf", 0)) &&
        nodeopencv_to_safe(info, jsobj_flags, flags, ArgInfo("flags", 0)) &&
        nodeopencv_to_safe(info, jsobj_mats, mats, ArgInfo("mats", 1)) )
    {
        ERRWRAP2(retval = cv::imdecodemulti(buf, flags, mats));
        return Py_BuildValue("(NN)", nodeopencv_from(retval), nodeopencv_from(mats));
    }


        jsPopulateArgumentConversionErrors();
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
    if(  NodeArg_ParseTupleAndKeywords(info, "OO|O:imdecodemulti", (char**)keywords, &jsobj_buf, &jsobj_flags, &jsobj_mats) &&
        nodeopencv_to_safe(info, jsobj_buf, buf, ArgInfo("buf", 0)) &&
        nodeopencv_to_safe(info, jsobj_flags, flags, ArgInfo("flags", 0)) &&
        nodeopencv_to_safe(info, jsobj_mats, mats, ArgInfo("mats", 1)) )
    {
        ERRWRAP2(retval = cv::imdecodemulti(buf, flags, mats));
        return Py_BuildValue("(NN)", nodeopencv_from(retval), nodeopencv_from(mats));
    }


        jsPopulateArgumentConversionErrors();
    }
    jsRaiseCVOverloadException("imdecodemulti");

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
    if(  NodeArg_ParseTupleAndKeywords(info, "OO|O:imencode", (char**)keywords, &jsobj_ext, &jsobj_img, &jsobj_params) &&
        nodeopencv_to_safe(info, jsobj_ext, ext, ArgInfo("ext", 0)) &&
        nodeopencv_to_safe(info, jsobj_img, img, ArgInfo("img", 0)) &&
        nodeopencv_to_safe(info, jsobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imencode(ext, img, buf, params));
        return Py_BuildValue("(NN)", nodeopencv_from(info, retval), nodeopencv_from(info, buf));
    }


        jsPopulateArgumentConversionErrors();
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
    if(  NodeArg_ParseTupleAndKeywords(info, "OO|O:imencode", (char**)keywords, &jsobj_ext, &jsobj_img, &jsobj_params) &&
        nodeopencv_to_safe(info, jsobj_ext, ext, ArgInfo("ext", 0)) &&
        nodeopencv_to_safe(info, jsobj_img, img, ArgInfo("img", 0)) &&
        nodeopencv_to_safe(info, jsobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imencode(ext, img, buf, params));
        return Py_BuildValue("(NN)", nodeopencv_from(info, retval), nodeopencv_from(info, buf));
    }


        jsPopulateArgumentConversionErrors();
    }
    jsRaiseCVOverloadException("imencode");

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
    if(  NodeArg_ParseTupleAndKeywords(info, "O|O:imread", (char**)keywords, &jsobj_filename, &jsobj_flags) &&
        nodeopencv_to_safe(info, jsobj_filename, filename, ArgInfo("filename", 0)) &&
        nodeopencv_to_safe(info, jsobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imread(filename, flags));
        return nodeopencv_from(info, retval);
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
    if(  NodeArg_ParseTupleAndKeywords(info, "O|OO:imreadmulti", (char**)keywords, &jsobj_filename, &jsobj_mats, &jsobj_flags) &&
        nodeopencv_to_safe(info, jsobj_filename, filename, ArgInfo("filename", 0)) &&
        nodeopencv_to_safe(info, jsobj_mats, mats, ArgInfo("mats", 1)) &&
        nodeopencv_to_safe(info, jsobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imreadmulti(filename, mats, flags));
        return Py_BuildValue("(NN)", nodeopencv_from(retval), nodeopencv_from(mats));
    }


        jsPopulateArgumentConversionErrors();
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
    if(  NodeArg_ParseTupleAndKeywords(info, "OOO|OO:imreadmulti", (char**)keywords, &jsobj_filename, &jsobj_start, &jsobj_count, &jsobj_mats, &jsobj_flags) &&
        nodeopencv_to_safe(info, jsobj_filename, filename, ArgInfo("filename", 0)) &&
        nodeopencv_to_safe(info, jsobj_mats, mats, ArgInfo("mats", 1)) &&
        nodeopencv_to_safe(info, jsobj_start, start, ArgInfo("start", 0)) &&
        nodeopencv_to_safe(info, jsobj_count, count, ArgInfo("count", 0)) &&
        nodeopencv_to_safe(info, jsobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imreadmulti(filename, mats, start, count, flags));
        return Py_BuildValue("(NN)", nodeopencv_from(info, retval), nodeopencv_from(info, mats));
    }


        jsPopulateArgumentConversionErrors();
    }
    jsRaiseCVOverloadException("imreadmulti");

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
    if(  NodeArg_ParseTupleAndKeywords(info, "OO:imshow", (char**)keywords, &jsobj_winname, &jsobj_mat) &&
        nodeopencv_to_safe(info, jsobj_winname, winname, ArgInfo("winname", 0)) &&
        nodeopencv_to_safe(info, jsobj_mat, mat, ArgInfo("mat", 0)) )
    {
        ERRWRAP2(cv::imshow(winname, mat));
        Py_RETURN_NONE;
    }


        jsPopulateArgumentConversionErrors();
    }
    

    {
    Napi::Value* jsobj_winname = NULL;
    String winname;
    Napi::Value* jsobj_mat = NULL;
    cuda::GpuMat mat;

    const char* keywords[] = { "winname", "mat", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "OO:imshow", (char**)keywords, &jsobj_winname, &jsobj_mat) &&
        nodeopencv_to_safe(info, jsobj_winname, winname, ArgInfo("winname", 0)) &&
        nodeopencv_to_safe(info, jsobj_mat, mat, ArgInfo("mat", 0)) )
    {
        ERRWRAP2(cv::imshow(winname, mat));
        Py_RETURN_NONE;
    }


        jsPopulateArgumentConversionErrors();
    }
    

    {
    Napi::Value* jsobj_winname = NULL;
    String winname;
    Napi::Value* jsobj_mat = NULL;
    UMat mat;

    const char* keywords[] = { "winname", "mat", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "OO:imshow", (char**)keywords, &jsobj_winname, &jsobj_mat) &&
        nodeopencv_to_safe(info, jsobj_winname, winname, ArgInfo("winname", 0)) &&
        nodeopencv_to_safe(info, jsobj_mat, mat, ArgInfo("mat", 0)) )
    {
        ERRWRAP2(cv::imshow(winname, mat));
        Py_RETURN_NONE;
    }


        jsPopulateArgumentConversionErrors();
    }
    jsRaiseCVOverloadException("imshow");

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
    if(  NodeArg_ParseTupleAndKeywords(info, "OO|O:imwrite", (char**)keywords, &jsobj_filename, &jsobj_img, &jsobj_params) &&
        nodeopencv_to_safe(info, jsobj_filename, filename, ArgInfo("filename", 0)) &&
        nodeopencv_to_safe(info, jsobj_img, img, ArgInfo("img", 0)) &&
        nodeopencv_to_safe(info, jsobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imwrite(filename, img, params));
        return nodeopencv_from(info, retval);
    }


        jsPopulateArgumentConversionErrors();
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
    if(  NodeArg_ParseTupleAndKeywords(info, "OO|O:imwrite", (char**)keywords, &jsobj_filename, &jsobj_img, &jsobj_params) &&
        nodeopencv_to_safe(info, jsobj_filename, filename, ArgInfo("filename", 0)) &&
        nodeopencv_to_safe(info, jsobj_img, img, ArgInfo("img", 0)) &&
        nodeopencv_to_safe(info, jsobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imwrite(filename, img, params));
        return nodeopencv_from(info, retval);
    }


        jsPopulateArgumentConversionErrors();
    }
    jsRaiseCVOverloadException("imwrite");

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
    if(  NodeArg_ParseTupleAndKeywords(info, "OO|O:imwritemulti", (char**)keywords, &jsobj_filename, &jsobj_img, &jsobj_params) &&
        nodeopencv_to_safe(info, jsobj_filename, filename, ArgInfo("filename", 0)) &&
        nodeopencv_to_safe(info, jsobj_img, img, ArgInfo("img", 0)) &&
        nodeopencv_to_safe(info, jsobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imwritemulti(filename, img, params));
        return nodeopencv_from(info, retval);
    }


        jsPopulateArgumentConversionErrors();
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
    if(  NodeArg_ParseTupleAndKeywords(info, "OO|O:imwritemulti", (char**)keywords, &jsobj_filename, &jsobj_img, &jsobj_params) &&
        nodeopencv_to_safe(jsobj_filename, filename, ArgInfo("filename", 0)) &&
        nodeopencv_to_safe(jsobj_img, img, ArgInfo("img", 0)) &&
        nodeopencv_to_safe(jsobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imwritemulti(filename, img, params));
        return nodeopencv_from(info, retval);
    }


        jsPopulateArgumentConversionErrors();
    }
    jsRaiseCVOverloadException("imwritemulti");

    return info.Env().Null();
}