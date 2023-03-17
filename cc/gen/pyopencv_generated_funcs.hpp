#include "common.h"
#include <../parse.hh>
#include "../node/cv2_util.hpp"
#include "../node/cv2_convert.hpp"
#include <opencv2/opencv.hpp>

static Napi::Value pyopencv_cv_haveImageReader(const Napi::CallbackInfo &info)
{
    using namespace cv;

    Napi::Value* pyobj_filename = NULL;
    String filename;
    bool retval;

    const char* keywords[] = { "filename", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "O:haveImageReader", (char**)keywords, &pyobj_filename) &&
        nodeopencv_to_safe(info, pyobj_filename, filename, ArgInfo("filename", 0)) )
    {
        ERRWRAP2(retval = cv::haveImageReader(filename));
        return nodeopencv_from(info, retval);
    }

    return info.Env().Null();
}

static Napi::Value pyopencv_cv_haveImageWriter(const Napi::CallbackInfo &info)
{
    using namespace cv;

    Napi::Value* pyobj_filename = NULL;
    String filename;
    bool retval;

    const char* keywords[] = { "filename", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "O:haveImageWriter", (char**)keywords, &pyobj_filename) &&
        nodeopencv_to_safe(info, pyobj_filename, filename, ArgInfo("filename", 0)) )
    {
        ERRWRAP2(retval = cv::haveImageWriter(filename));
        return nodeopencv_from(info, retval);
    }

    return info.Env().Null();
}


static Napi::Value pyopencv_cv_imcount(const Napi::CallbackInfo &info)
{
    using namespace cv;

    Napi::Value* pyobj_filename = NULL;
    String filename;
    Napi::Value* pyobj_flags = NULL;
    int flags=IMREAD_ANYCOLOR;
    size_t retval;

    const char* keywords[] = { "filename", "flags", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "O|O:imcount", (char**)keywords, &pyobj_filename, &pyobj_flags) &&
        nodeopencv_to_safe(info, pyobj_filename, filename, ArgInfo("filename", 0)) &&
        nodeopencv_to_safe(info, pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imcount(filename, flags));
        return nodeopencv_from(info, retval);
    }

    return info.Env().Null();
}

static Napi::Value pyopencv_cv_imdecode(const Napi::CallbackInfo &info)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    Napi::Value* pyobj_buf = NULL;
    Mat buf;
    Napi::Value* pyobj_flags = NULL;
    int flags=0;
    Mat retval;

    const char* keywords[] = { "buf", "flags", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "OO:imdecode", (char**)keywords, &pyobj_buf, &pyobj_flags) &&
        nodeopencv_to_safe(info, pyobj_buf, buf, ArgInfo("buf", 0)) &&
        nodeopencv_to_safe(info, pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imdecode(buf, flags));
        return nodeopencv_from(info, retval);
    }
        pyPopulateArgumentConversionErrors();
    }
    

    {
    Napi::Value* pyobj_buf = NULL;
    UMat buf;
    Napi::Value* pyobj_flags = NULL;
    int flags=0;
    Mat retval;

    const char* keywords[] = { "buf", "flags", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "OO:imdecode", (char**)keywords, &pyobj_buf, &pyobj_flags) &&
        nodeopencv_to_safe(info, pyobj_buf, buf, ArgInfo("buf", 0)) &&
        nodeopencv_to_safe(info, pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imdecode(buf, flags));
        return nodeopencv_from(info, retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imdecode");

    return info.Env().Null();
}

static Napi::Value pyopencv_cv_imdecodemulti(const Napi::CallbackInfo &info)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    Napi::Value* pyobj_buf = NULL;
    Mat buf;
    Napi::Value* pyobj_flags = NULL;
    int flags=0;
    Napi::Value* pyobj_mats = NULL;
    vector_Mat mats;
    bool retval;

    const char* keywords[] = { "buf", "flags", "mats", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "OO|O:imdecodemulti", (char**)keywords, &pyobj_buf, &pyobj_flags, &pyobj_mats) &&
        nodeopencv_to_safe(info, pyobj_buf, buf, ArgInfo("buf", 0)) &&
        nodeopencv_to_safe(info, pyobj_flags, flags, ArgInfo("flags", 0)) &&
        nodeopencv_to_safe(info, pyobj_mats, mats, ArgInfo("mats", 1)) )
    {
        ERRWRAP2(retval = cv::imdecodemulti(buf, flags, mats));
        return Py_BuildValue("(NN)", nodeopencv_from(retval), nodeopencv_from(mats));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    Napi::Value* pyobj_buf = NULL;
    UMat buf;
    Napi::Value* pyobj_flags = NULL;
    int flags=0;
    Napi::Value* pyobj_mats = NULL;
    vector_Mat mats;
    bool retval;

    const char* keywords[] = { "buf", "flags", "mats", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "OO|O:imdecodemulti", (char**)keywords, &pyobj_buf, &pyobj_flags, &pyobj_mats) &&
        nodeopencv_to_safe(info, pyobj_buf, buf, ArgInfo("buf", 0)) &&
        nodeopencv_to_safe(info, pyobj_flags, flags, ArgInfo("flags", 0)) &&
        nodeopencv_to_safe(info, pyobj_mats, mats, ArgInfo("mats", 1)) )
    {
        ERRWRAP2(retval = cv::imdecodemulti(buf, flags, mats));
        return Py_BuildValue("(NN)", nodeopencv_from(retval), nodeopencv_from(mats));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imdecodemulti");

    return info.Env().Null();
}

static Napi::Value pyopencv_cv_imencode(const Napi::CallbackInfo &info)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    Napi::Value* pyobj_ext = NULL;
    String ext;
    Napi::Value* pyobj_img = NULL;
    Mat img;
    vector_uchar buf;
    Napi::Value* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "ext", "img", "params", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "OO|O:imencode", (char**)keywords, &pyobj_ext, &pyobj_img, &pyobj_params) &&
        nodeopencv_to_safe(info, pyobj_ext, ext, ArgInfo("ext", 0)) &&
        nodeopencv_to_safe(info, pyobj_img, img, ArgInfo("img", 0)) &&
        nodeopencv_to_safe(info, pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imencode(ext, img, buf, params));
        return Py_BuildValue("(NN)", nodeopencv_from(info, retval), nodeopencv_from(info, buf));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    Napi::Value* pyobj_ext = NULL;
    String ext;
    Napi::Value* pyobj_img = NULL;
    UMat img;
    vector_uchar buf;
    Napi::Value* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "ext", "img", "params", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "OO|O:imencode", (char**)keywords, &pyobj_ext, &pyobj_img, &pyobj_params) &&
        nodeopencv_to_safe(info, pyobj_ext, ext, ArgInfo("ext", 0)) &&
        nodeopencv_to_safe(info, pyobj_img, img, ArgInfo("img", 0)) &&
        nodeopencv_to_safe(info, pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imencode(ext, img, buf, params));
        return Py_BuildValue("(NN)", nodeopencv_from(info, retval), nodeopencv_from(info, buf));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imencode");

    return info.Env().Null();
}

static Napi::Value pyopencv_cv_imread(const Napi::CallbackInfo &info)
{
    using namespace cv;

    Napi::Value* pyobj_filename = NULL;
    String filename;
    Napi::Value* pyobj_flags = NULL;
    int flags=IMREAD_COLOR;
    Mat retval;

    const char* keywords[] = { "filename", "flags", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "O|O:imread", (char**)keywords, &pyobj_filename, &pyobj_flags) &&
        nodeopencv_to_safe(info, pyobj_filename, filename, ArgInfo("filename", 0)) &&
        nodeopencv_to_safe(info, pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imread(filename, flags));
        return nodeopencv_from(info, retval);
    }

    return info.Env().Null();
}

static Napi::Value pyopencv_cv_imreadmulti(const Napi::CallbackInfo &info)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    Napi::Value* pyobj_filename = NULL;
    String filename;
    Napi::Value* pyobj_mats = NULL;
    vector_Mat mats;
    Napi::Value* pyobj_flags = NULL;
    int flags=IMREAD_ANYCOLOR;
    bool retval;

    const char* keywords[] = { "filename", "mats", "flags", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "O|OO:imreadmulti", (char**)keywords, &pyobj_filename, &pyobj_mats, &pyobj_flags) &&
        nodeopencv_to_safe(info, pyobj_filename, filename, ArgInfo("filename", 0)) &&
        nodeopencv_to_safe(info, pyobj_mats, mats, ArgInfo("mats", 1)) &&
        nodeopencv_to_safe(info, pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imreadmulti(filename, mats, flags));
        return Py_BuildValue("(NN)", nodeopencv_from(retval), nodeopencv_from(mats));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    Napi::Value* pyobj_filename = NULL;
    String filename;
    Napi::Value* pyobj_mats = NULL;
    vector_Mat mats;
    Napi::Value* pyobj_start = NULL;
    int start=0;
    Napi::Value* pyobj_count = NULL;
    int count=0;
    Napi::Value* pyobj_flags = NULL;
    int flags=IMREAD_ANYCOLOR;
    bool retval;

    const char* keywords[] = { "filename", "start", "count", "mats", "flags", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "OOO|OO:imreadmulti", (char**)keywords, &pyobj_filename, &pyobj_start, &pyobj_count, &pyobj_mats, &pyobj_flags) &&
        nodeopencv_to_safe(info, pyobj_filename, filename, ArgInfo("filename", 0)) &&
        nodeopencv_to_safe(info, pyobj_mats, mats, ArgInfo("mats", 1)) &&
        nodeopencv_to_safe(info, pyobj_start, start, ArgInfo("start", 0)) &&
        nodeopencv_to_safe(info, pyobj_count, count, ArgInfo("count", 0)) &&
        nodeopencv_to_safe(info, pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imreadmulti(filename, mats, start, count, flags));
        return Py_BuildValue("(NN)", nodeopencv_from(info, retval), nodeopencv_from(info, mats));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imreadmulti");

    return info.Env().Null();
}

static Napi::Value pyopencv_cv_imshow(const Napi::CallbackInfo &info)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    Napi::Value* pyobj_winname = NULL;
    String winname;
    Napi::Value* pyobj_mat = NULL;
    Mat mat;

    const char* keywords[] = { "winname", "mat", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "OO:imshow", (char**)keywords, &pyobj_winname, &pyobj_mat) &&
        nodeopencv_to_safe(info, pyobj_winname, winname, ArgInfo("winname", 0)) &&
        nodeopencv_to_safe(info, pyobj_mat, mat, ArgInfo("mat", 0)) )
    {
        ERRWRAP2(cv::imshow(winname, mat));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    Napi::Value* pyobj_winname = NULL;
    String winname;
    Napi::Value* pyobj_mat = NULL;
    cuda::GpuMat mat;

    const char* keywords[] = { "winname", "mat", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "OO:imshow", (char**)keywords, &pyobj_winname, &pyobj_mat) &&
        nodeopencv_to_safe(info, pyobj_winname, winname, ArgInfo("winname", 0)) &&
        nodeopencv_to_safe(info, pyobj_mat, mat, ArgInfo("mat", 0)) )
    {
        ERRWRAP2(cv::imshow(winname, mat));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    Napi::Value* pyobj_winname = NULL;
    String winname;
    Napi::Value* pyobj_mat = NULL;
    UMat mat;

    const char* keywords[] = { "winname", "mat", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "OO:imshow", (char**)keywords, &pyobj_winname, &pyobj_mat) &&
        nodeopencv_to_safe(info, pyobj_winname, winname, ArgInfo("winname", 0)) &&
        nodeopencv_to_safe(info, pyobj_mat, mat, ArgInfo("mat", 0)) )
    {
        ERRWRAP2(cv::imshow(winname, mat));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imshow");

    return info.Env().Null();
}

static Napi::Value pyopencv_cv_imwrite(const Napi::CallbackInfo &info)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    Napi::Value* pyobj_filename = NULL;
    String filename;
    Napi::Value* pyobj_img = NULL;
    Mat img;
    Napi::Value* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "filename", "img", "params", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "OO|O:imwrite", (char**)keywords, &pyobj_filename, &pyobj_img, &pyobj_params) &&
        nodeopencv_to_safe(info, pyobj_filename, filename, ArgInfo("filename", 0)) &&
        nodeopencv_to_safe(info, pyobj_img, img, ArgInfo("img", 0)) &&
        nodeopencv_to_safe(info, pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imwrite(filename, img, params));
        return nodeopencv_from(info, retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    Napi::Value* pyobj_filename = NULL;
    String filename;
    Napi::Value* pyobj_img = NULL;
    UMat img;
    Napi::Value* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "filename", "img", "params", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "OO|O:imwrite", (char**)keywords, &pyobj_filename, &pyobj_img, &pyobj_params) &&
        nodeopencv_to_safe(info, pyobj_filename, filename, ArgInfo("filename", 0)) &&
        nodeopencv_to_safe(info, pyobj_img, img, ArgInfo("img", 0)) &&
        nodeopencv_to_safe(info, pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imwrite(filename, img, params));
        return nodeopencv_from(info, retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imwrite");

    return info.Env().Null();
}

static Napi::Value pyopencv_cv_imwritemulti(const Napi::CallbackInfo &info)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    Napi::Value* pyobj_filename = NULL;
    String filename;
    Napi::Value* pyobj_img = NULL;
    vector_Mat img;
    Napi::Value* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "filename", "img", "params", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "OO|O:imwritemulti", (char**)keywords, &pyobj_filename, &pyobj_img, &pyobj_params) &&
        nodeopencv_to_safe(info, pyobj_filename, filename, ArgInfo("filename", 0)) &&
        nodeopencv_to_safe(info, pyobj_img, img, ArgInfo("img", 0)) &&
        nodeopencv_to_safe(info, pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imwritemulti(filename, img, params));
        return nodeopencv_from(info, retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    Napi::Value* pyobj_filename = NULL;
    String filename;
    Napi::Value* pyobj_img = NULL;
    vector_UMat img;
    Napi::Value* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "filename", "img", "params", NULL };
    if(  NodeArg_ParseTupleAndKeywords(info, "OO|O:imwritemulti", (char**)keywords, &pyobj_filename, &pyobj_img, &pyobj_params) &&
        nodeopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 0)) &&
        nodeopencv_to_safe(pyobj_img, img, ArgInfo("img", 0)) &&
        nodeopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imwritemulti(filename, img, params));
        return nodeopencv_from(info, retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imwritemulti");

    return info.Env().Null();
}