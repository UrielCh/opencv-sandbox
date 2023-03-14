#include "common.h"

static PyObject* pyopencv_cv_haveImageReader(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_filename = NULL;
    String filename;
    bool retval;

    const char* keywords[] = { "filename", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:haveImageReader", (char**)keywords, &pyobj_filename) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 0)) )
    {
        ERRWRAP2(retval = cv::haveImageReader(filename));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_haveImageWriter(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_filename = NULL;
    String filename;
    bool retval;

    const char* keywords[] = { "filename", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:haveImageWriter", (char**)keywords, &pyobj_filename) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 0)) )
    {
        ERRWRAP2(retval = cv::haveImageWriter(filename));
        return pyopencv_from(retval);
    }

    return NULL;
}


static PyObject* pyopencv_cv_imcount(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_flags = NULL;
    int flags=IMREAD_ANYCOLOR;
    size_t retval;

    const char* keywords[] = { "filename", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:imcount", (char**)keywords, &pyobj_filename, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imcount(filename, flags));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_imdecode(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_buf = NULL;
    Mat buf;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    Mat retval;

    const char* keywords[] = { "buf", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:imdecode", (char**)keywords, &pyobj_buf, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_buf, buf, ArgInfo("buf", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imdecode(buf, flags));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_buf = NULL;
    UMat buf;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    Mat retval;

    const char* keywords[] = { "buf", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:imdecode", (char**)keywords, &pyobj_buf, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_buf, buf, ArgInfo("buf", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imdecode(buf, flags));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imdecode");

    return NULL;
}

static PyObject* pyopencv_cv_imdecodemulti(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_buf = NULL;
    Mat buf;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_mats = NULL;
    vector_Mat mats;
    bool retval;

    const char* keywords[] = { "buf", "flags", "mats", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:imdecodemulti", (char**)keywords, &pyobj_buf, &pyobj_flags, &pyobj_mats) &&
        pyopencv_to_safe(pyobj_buf, buf, ArgInfo("buf", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_mats, mats, ArgInfo("mats", 1)) )
    {
        ERRWRAP2(retval = cv::imdecodemulti(buf, flags, mats));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mats));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_buf = NULL;
    UMat buf;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_mats = NULL;
    vector_Mat mats;
    bool retval;

    const char* keywords[] = { "buf", "flags", "mats", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:imdecodemulti", (char**)keywords, &pyobj_buf, &pyobj_flags, &pyobj_mats) &&
        pyopencv_to_safe(pyobj_buf, buf, ArgInfo("buf", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_mats, mats, ArgInfo("mats", 1)) )
    {
        ERRWRAP2(retval = cv::imdecodemulti(buf, flags, mats));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mats));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imdecodemulti");

    return NULL;
}

static PyObject* pyopencv_cv_imencode(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_ext = NULL;
    String ext;
    PyObject* pyobj_img = NULL;
    Mat img;
    vector_uchar buf;
    PyObject* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "ext", "img", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:imencode", (char**)keywords, &pyobj_ext, &pyobj_img, &pyobj_params) &&
        pyopencv_to_safe(pyobj_ext, ext, ArgInfo("ext", 0)) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imencode(ext, img, buf, params));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(buf));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_ext = NULL;
    String ext;
    PyObject* pyobj_img = NULL;
    UMat img;
    vector_uchar buf;
    PyObject* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "ext", "img", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:imencode", (char**)keywords, &pyobj_ext, &pyobj_img, &pyobj_params) &&
        pyopencv_to_safe(pyobj_ext, ext, ArgInfo("ext", 0)) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imencode(ext, img, buf, params));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(buf));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imencode");

    return NULL;
}

static PyObject* pyopencv_cv_imread(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_flags = NULL;
    int flags=IMREAD_COLOR;
    Mat retval;

    const char* keywords[] = { "filename", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:imread", (char**)keywords, &pyobj_filename, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imread(filename, flags));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_imreadmulti(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_mats = NULL;
    vector_Mat mats;
    PyObject* pyobj_flags = NULL;
    int flags=IMREAD_ANYCOLOR;
    bool retval;

    const char* keywords[] = { "filename", "mats", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:imreadmulti", (char**)keywords, &pyobj_filename, &pyobj_mats, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 0)) &&
        pyopencv_to_safe(pyobj_mats, mats, ArgInfo("mats", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imreadmulti(filename, mats, flags));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mats));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_mats = NULL;
    vector_Mat mats;
    PyObject* pyobj_start = NULL;
    int start=0;
    PyObject* pyobj_count = NULL;
    int count=0;
    PyObject* pyobj_flags = NULL;
    int flags=IMREAD_ANYCOLOR;
    bool retval;

    const char* keywords[] = { "filename", "start", "count", "mats", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:imreadmulti", (char**)keywords, &pyobj_filename, &pyobj_start, &pyobj_count, &pyobj_mats, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 0)) &&
        pyopencv_to_safe(pyobj_mats, mats, ArgInfo("mats", 1)) &&
        pyopencv_to_safe(pyobj_start, start, ArgInfo("start", 0)) &&
        pyopencv_to_safe(pyobj_count, count, ArgInfo("count", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imreadmulti(filename, mats, start, count, flags));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mats));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imreadmulti");

    return NULL;
}

static PyObject* pyopencv_cv_imshow(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_winname = NULL;
    String winname;
    PyObject* pyobj_mat = NULL;
    Mat mat;

    const char* keywords[] = { "winname", "mat", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:imshow", (char**)keywords, &pyobj_winname, &pyobj_mat) &&
        pyopencv_to_safe(pyobj_winname, winname, ArgInfo("winname", 0)) &&
        pyopencv_to_safe(pyobj_mat, mat, ArgInfo("mat", 0)) )
    {
        ERRWRAP2(cv::imshow(winname, mat));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_winname = NULL;
    String winname;
    PyObject* pyobj_mat = NULL;
    cuda::GpuMat mat;

    const char* keywords[] = { "winname", "mat", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:imshow", (char**)keywords, &pyobj_winname, &pyobj_mat) &&
        pyopencv_to_safe(pyobj_winname, winname, ArgInfo("winname", 0)) &&
        pyopencv_to_safe(pyobj_mat, mat, ArgInfo("mat", 0)) )
    {
        ERRWRAP2(cv::imshow(winname, mat));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_winname = NULL;
    String winname;
    PyObject* pyobj_mat = NULL;
    UMat mat;

    const char* keywords[] = { "winname", "mat", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:imshow", (char**)keywords, &pyobj_winname, &pyobj_mat) &&
        pyopencv_to_safe(pyobj_winname, winname, ArgInfo("winname", 0)) &&
        pyopencv_to_safe(pyobj_mat, mat, ArgInfo("mat", 0)) )
    {
        ERRWRAP2(cv::imshow(winname, mat));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imshow");

    return NULL;
}

static PyObject* pyopencv_cv_imwrite(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "filename", "img", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:imwrite", (char**)keywords, &pyobj_filename, &pyobj_img, &pyobj_params) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 0)) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imwrite(filename, img, params));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "filename", "img", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:imwrite", (char**)keywords, &pyobj_filename, &pyobj_img, &pyobj_params) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 0)) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imwrite(filename, img, params));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imwrite");

    return NULL;
}

static PyObject* pyopencv_cv_imwritemulti(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_img = NULL;
    vector_Mat img;
    PyObject* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "filename", "img", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:imwritemulti", (char**)keywords, &pyobj_filename, &pyobj_img, &pyobj_params) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 0)) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imwritemulti(filename, img, params));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_img = NULL;
    vector_UMat img;
    PyObject* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "filename", "img", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:imwritemulti", (char**)keywords, &pyobj_filename, &pyobj_img, &pyobj_params) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 0)) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imwritemulti(filename, img, params));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imwritemulti");

    return NULL;
}