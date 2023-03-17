
#include "common.h"

//================================================================================
// UMat (Generic)
//================================================================================

// GetSet (UMat)


static PyObject* pyopencv_UMat_get_offset(pyopencv_UMat_t* p, void *closure)
{
    return pyopencv_from(p->v->offset);
}

static int pyopencv_UMat_set_offset(pyopencv_UMat_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the offset attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v->offset, ArgInfo("value", false)) ? 0 : -1;
}


// Methods (UMat)

static int pyopencv_cv_UMat_UMat(pyopencv_UMat_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(9);

    {
    PyObject* pyobj_usageFlags = NULL;
    UMatUsageFlags usageFlags=USAGE_DEFAULT;

    const char* keywords[] = { "usageFlags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:UMat", (char**)keywords, &pyobj_usageFlags) &&
        pyopencv_to_safe(pyobj_usageFlags, usageFlags, ArgInfo("usageFlags", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(usageFlags)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_rows = NULL;
    int rows=0;
    PyObject* pyobj_cols = NULL;
    int cols=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_usageFlags = NULL;
    UMatUsageFlags usageFlags=USAGE_DEFAULT;

    const char* keywords[] = { "rows", "cols", "type", "usageFlags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:UMat", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_usageFlags) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to_safe(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_usageFlags, usageFlags, ArgInfo("usageFlags", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(rows, cols, type, usageFlags)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_usageFlags = NULL;
    UMatUsageFlags usageFlags=USAGE_DEFAULT;

    const char* keywords[] = { "size", "type", "usageFlags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:UMat", (char**)keywords, &pyobj_size, &pyobj_type, &pyobj_usageFlags) &&
        pyopencv_to_safe(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_usageFlags, usageFlags, ArgInfo("usageFlags", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(size, type, usageFlags)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_rows = NULL;
    int rows=0;
    PyObject* pyobj_cols = NULL;
    int cols=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_s = NULL;
    Scalar s;
    PyObject* pyobj_usageFlags = NULL;
    UMatUsageFlags usageFlags=USAGE_DEFAULT;

    const char* keywords[] = { "rows", "cols", "type", "s", "usageFlags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:UMat", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_s, &pyobj_usageFlags) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to_safe(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_s, s, ArgInfo("s", 0)) &&
        pyopencv_to_safe(pyobj_usageFlags, usageFlags, ArgInfo("usageFlags", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(rows, cols, type, s, usageFlags)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_s = NULL;
    Scalar s;
    PyObject* pyobj_usageFlags = NULL;
    UMatUsageFlags usageFlags=USAGE_DEFAULT;

    const char* keywords[] = { "size", "type", "s", "usageFlags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:UMat", (char**)keywords, &pyobj_size, &pyobj_type, &pyobj_s, &pyobj_usageFlags) &&
        pyopencv_to_safe(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_s, s, ArgInfo("s", 0)) &&
        pyopencv_to_safe(pyobj_usageFlags, usageFlags, ArgInfo("usageFlags", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(size, type, s, usageFlags)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_m = NULL;
    UMat m;

    const char* keywords[] = { "m", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:UMat", (char**)keywords, &pyobj_m) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(m)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_m = NULL;
    UMat m;
    PyObject* pyobj_rowRange = NULL;
    Range rowRange;
    PyObject* pyobj_colRange = NULL;
    Range colRange=Range::all();

    const char* keywords[] = { "m", "rowRange", "colRange", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:UMat", (char**)keywords, &pyobj_m, &pyobj_rowRange, &pyobj_colRange) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) &&
        pyopencv_to_safe(pyobj_rowRange, rowRange, ArgInfo("rowRange", 0)) &&
        pyopencv_to_safe(pyobj_colRange, colRange, ArgInfo("colRange", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(m, rowRange, colRange)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_m = NULL;
    UMat m;
    PyObject* pyobj_roi = NULL;
    Rect roi;

    const char* keywords[] = { "m", "roi", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:UMat", (char**)keywords, &pyobj_m, &pyobj_roi) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) &&
        pyopencv_to_safe(pyobj_roi, roi, ArgInfo("roi", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(m, roi)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_m = NULL;
    UMat m;
    PyObject* pyobj_ranges = NULL;
    vector_Range ranges;

    const char* keywords[] = { "m", "ranges", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:UMat", (char**)keywords, &pyobj_m, &pyobj_ranges) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) &&
        pyopencv_to_safe(pyobj_ranges, ranges, ArgInfo("ranges", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(m, ranges)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("UMat");

    return -1;
}

static PyObject* pyopencv_cv_UMat_context_static(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    void* retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv_UMat_context());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_UMat_get(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::UMat> * self1 = 0;
    if (!pyopencv_UMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'UMat' or its derivative)");
    Ptr<cv::UMat> _self_ = *(self1);
    Mat retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv_UMat_get(_self_));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_UMat_handle(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::UMat> * self1 = 0;
    if (!pyopencv_UMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'UMat' or its derivative)");
    Ptr<cv::UMat> _self_ = *(self1);
    PyObject* pyobj_accessFlags = NULL;
    AccessFlag accessFlags=static_cast<AccessFlag>(0);
    void* retval;

    const char* keywords[] = { "accessFlags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:UMat.handle", (char**)keywords, &pyobj_accessFlags) &&
        pyopencv_to_safe(pyobj_accessFlags, accessFlags, ArgInfo("accessFlags", 0)) )
    {
        ERRWRAP2(retval = _self_->handle(accessFlags));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_UMat_isContinuous(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::UMat> * self1 = 0;
    if (!pyopencv_UMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'UMat' or its derivative)");
    Ptr<cv::UMat> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isContinuous());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_UMat_isSubmatrix(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::UMat> * self1 = 0;
    if (!pyopencv_UMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'UMat' or its derivative)");
    Ptr<cv::UMat> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isSubmatrix());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_UMat_queue_static(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    void* retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv_UMat_queue());
        return pyopencv_from(retval);
    }

    return NULL;
}



// Tables (UMat)

static PyGetSetDef pyopencv_UMat_getseters[] =
{
    {(char*)"offset", (getter)pyopencv_UMat_get_offset, (setter)pyopencv_UMat_set_offset, (char*)"offset", NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_UMat_methods[] =
{
    {"context", CV_PY_FN_WITH_KW_(pyopencv_cv_UMat_context_static, METH_STATIC), "context() -> retval\n."},
    {"get", CV_PY_FN_WITH_KW_(pyopencv_cv_UMat_get, 0), "get() -> retval\n."},
    {"handle", CV_PY_FN_WITH_KW_(pyopencv_cv_UMat_handle, 0), "handle(accessFlags) -> retval\n."},
    {"isContinuous", CV_PY_FN_WITH_KW_(pyopencv_cv_UMat_isContinuous, 0), "isContinuous() -> retval\n."},
    {"isSubmatrix", CV_PY_FN_WITH_KW_(pyopencv_cv_UMat_isSubmatrix, 0), "isSubmatrix() -> retval\n."},
    {"queue", CV_PY_FN_WITH_KW_(pyopencv_cv_UMat_queue_static, METH_STATIC), "queue() -> retval\n."},

    {NULL,          NULL}
};

// Converter (UMat)

template<>
struct PyOpenCV_Converter< Ptr<cv::UMat> >
{
    static PyObject* from(const Ptr<cv::UMat>& r)
    {
        return pyopencv_UMat_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::UMat>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::UMat> * dst_;
        if (pyopencv_UMat_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
    {
        Ptr<Mat> _src;
        if (pyopencv_to_safe(src, _src, info))
        {
            return cv_mappable_to(_src, dst);
        }
    }

        failmsg("Expected Ptr<cv::UMat> for argument '%s'", info.name);
        return false;
    }
};