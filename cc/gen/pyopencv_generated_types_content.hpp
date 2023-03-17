
#include "common.h"

//================================================================================
// UMat (Generic)
//================================================================================

// GetSet (UMat)


static JsObject* jsopencv_UMat_get_offset(jsopencv_UMat_t* p, void *closure)
{
    return jsopencv_from(p->v->offset);
}

static int jsopencv_UMat_set_offset(jsopencv_UMat_t* p, JsObject *value, void *closure)
{
    if (!value)
    {
        JsErr_SetString(JsExc_TypeError, "Cannot delete the offset attribute");
        return -1;
    }
    return jsopencv_to_safe(value, p->v->offset, ArgInfo("value", false)) ? 0 : -1;
}


// Methods (UMat)

static int jsopencv_cv_UMat_UMat(jsopencv_UMat_t* self, JsObject* js_args, JsObject* kw)
{
    using namespace cv;

    jsPrepareArgumentConversionErrorsStorage(9);

    {
    JsObject* jsobj_usageFlags = NULL;
    UMatUsageFlags usageFlags=USAGE_DEFAULT;

    const char* keywords[] = { "usageFlags", NULL };
    if( JsArg_ParseTupleAndKeywords(js_args, kw, "|O:UMat", (char**)keywords, &jsobj_usageFlags) &&
        jsopencv_to_safe(jsobj_usageFlags, usageFlags, ArgInfo("usageFlags", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(usageFlags)));
        return 0;
    }


        jsPopulateArgumentConversionErrors();
    }
    

    {
    JsObject* jsobj_rows = NULL;
    int rows=0;
    JsObject* jsobj_cols = NULL;
    int cols=0;
    JsObject* jsobj_type = NULL;
    int type=0;
    JsObject* jsobj_usageFlags = NULL;
    UMatUsageFlags usageFlags=USAGE_DEFAULT;

    const char* keywords[] = { "rows", "cols", "type", "usageFlags", NULL };
    if( JsArg_ParseTupleAndKeywords(js_args, kw, "OOO|O:UMat", (char**)keywords, &jsobj_rows, &jsobj_cols, &jsobj_type, &jsobj_usageFlags) &&
        jsopencv_to_safe(jsobj_rows, rows, ArgInfo("rows", 0)) &&
        jsopencv_to_safe(jsobj_cols, cols, ArgInfo("cols", 0)) &&
        jsopencv_to_safe(jsobj_type, type, ArgInfo("type", 0)) &&
        jsopencv_to_safe(jsobj_usageFlags, usageFlags, ArgInfo("usageFlags", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(rows, cols, type, usageFlags)));
        return 0;
    }


        jsPopulateArgumentConversionErrors();
    }
    

    {
    JsObject* jsobj_size = NULL;
    Size size;
    JsObject* jsobj_type = NULL;
    int type=0;
    JsObject* jsobj_usageFlags = NULL;
    UMatUsageFlags usageFlags=USAGE_DEFAULT;

    const char* keywords[] = { "size", "type", "usageFlags", NULL };
    if( JsArg_ParseTupleAndKeywords(js_args, kw, "OO|O:UMat", (char**)keywords, &jsobj_size, &jsobj_type, &jsobj_usageFlags) &&
        jsopencv_to_safe(jsobj_size, size, ArgInfo("size", 0)) &&
        jsopencv_to_safe(jsobj_type, type, ArgInfo("type", 0)) &&
        jsopencv_to_safe(jsobj_usageFlags, usageFlags, ArgInfo("usageFlags", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(size, type, usageFlags)));
        return 0;
    }


        jsPopulateArgumentConversionErrors();
    }
    

    {
    JsObject* jsobj_rows = NULL;
    int rows=0;
    JsObject* jsobj_cols = NULL;
    int cols=0;
    JsObject* jsobj_type = NULL;
    int type=0;
    JsObject* jsobj_s = NULL;
    Scalar s;
    JsObject* jsobj_usageFlags = NULL;
    UMatUsageFlags usageFlags=USAGE_DEFAULT;

    const char* keywords[] = { "rows", "cols", "type", "s", "usageFlags", NULL };
    if( JsArg_ParseTupleAndKeywords(js_args, kw, "OOOO|O:UMat", (char**)keywords, &jsobj_rows, &jsobj_cols, &jsobj_type, &jsobj_s, &jsobj_usageFlags) &&
        jsopencv_to_safe(jsobj_rows, rows, ArgInfo("rows", 0)) &&
        jsopencv_to_safe(jsobj_cols, cols, ArgInfo("cols", 0)) &&
        jsopencv_to_safe(jsobj_type, type, ArgInfo("type", 0)) &&
        jsopencv_to_safe(jsobj_s, s, ArgInfo("s", 0)) &&
        jsopencv_to_safe(jsobj_usageFlags, usageFlags, ArgInfo("usageFlags", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(rows, cols, type, s, usageFlags)));
        return 0;
    }


        jsPopulateArgumentConversionErrors();
    }
    

    {
    JsObject* jsobj_size = NULL;
    Size size;
    JsObject* jsobj_type = NULL;
    int type=0;
    JsObject* jsobj_s = NULL;
    Scalar s;
    JsObject* jsobj_usageFlags = NULL;
    UMatUsageFlags usageFlags=USAGE_DEFAULT;

    const char* keywords[] = { "size", "type", "s", "usageFlags", NULL };
    if( JsArg_ParseTupleAndKeywords(js_args, kw, "OOO|O:UMat", (char**)keywords, &jsobj_size, &jsobj_type, &jsobj_s, &jsobj_usageFlags) &&
        jsopencv_to_safe(jsobj_size, size, ArgInfo("size", 0)) &&
        jsopencv_to_safe(jsobj_type, type, ArgInfo("type", 0)) &&
        jsopencv_to_safe(jsobj_s, s, ArgInfo("s", 0)) &&
        jsopencv_to_safe(jsobj_usageFlags, usageFlags, ArgInfo("usageFlags", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(size, type, s, usageFlags)));
        return 0;
    }


        jsPopulateArgumentConversionErrors();
    }
    

    {
    JsObject* jsobj_m = NULL;
    UMat m;

    const char* keywords[] = { "m", NULL };
    if( JsArg_ParseTupleAndKeywords(js_args, kw, "O:UMat", (char**)keywords, &jsobj_m) &&
        jsopencv_to_safe(jsobj_m, m, ArgInfo("m", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(m)));
        return 0;
    }


        jsPopulateArgumentConversionErrors();
    }
    

    {
    JsObject* jsobj_m = NULL;
    UMat m;
    JsObject* jsobj_rowRange = NULL;
    Range rowRange;
    JsObject* jsobj_colRange = NULL;
    Range colRange=Range::all();

    const char* keywords[] = { "m", "rowRange", "colRange", NULL };
    if( JsArg_ParseTupleAndKeywords(js_args, kw, "OO|O:UMat", (char**)keywords, &jsobj_m, &jsobj_rowRange, &jsobj_colRange) &&
        jsopencv_to_safe(jsobj_m, m, ArgInfo("m", 0)) &&
        jsopencv_to_safe(jsobj_rowRange, rowRange, ArgInfo("rowRange", 0)) &&
        jsopencv_to_safe(jsobj_colRange, colRange, ArgInfo("colRange", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(m, rowRange, colRange)));
        return 0;
    }


        jsPopulateArgumentConversionErrors();
    }
    

    {
    JsObject* jsobj_m = NULL;
    UMat m;
    JsObject* jsobj_roi = NULL;
    Rect roi;

    const char* keywords[] = { "m", "roi", NULL };
    if( JsArg_ParseTupleAndKeywords(js_args, kw, "OO:UMat", (char**)keywords, &jsobj_m, &jsobj_roi) &&
        jsopencv_to_safe(jsobj_m, m, ArgInfo("m", 0)) &&
        jsopencv_to_safe(jsobj_roi, roi, ArgInfo("roi", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(m, roi)));
        return 0;
    }


        jsPopulateArgumentConversionErrors();
    }
    

    {
    JsObject* jsobj_m = NULL;
    UMat m;
    JsObject* jsobj_ranges = NULL;
    vector_Range ranges;

    const char* keywords[] = { "m", "ranges", NULL };
    if( JsArg_ParseTupleAndKeywords(js_args, kw, "OO:UMat", (char**)keywords, &jsobj_m, &jsobj_ranges) &&
        jsopencv_to_safe(jsobj_m, m, ArgInfo("m", 0)) &&
        jsopencv_to_safe(jsobj_ranges, ranges, ArgInfo("ranges", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(m, ranges)));
        return 0;
    }


        jsPopulateArgumentConversionErrors();
    }
    jsRaiseCVOverloadException("UMat");

    return -1;
}

static JsObject* jsopencv_cv_UMat_context_static(JsObject* self, JsObject* js_args, JsObject* kw)
{
    using namespace cv;

    void* retval;

    if(JsObject_Size(js_args) == 0 && (!kw || JsObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv_UMat_context());
        return jsopencv_from(retval);
    }

    return NULL;
}

static JsObject* jsopencv_cv_UMat_get(JsObject* self, JsObject* js_args, JsObject* kw)
{
    using namespace cv;


    Ptr<cv::UMat> * self1 = 0;
    if (!jsopencv_UMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'UMat' or its derivative)");
    Ptr<cv::UMat> _self_ = *(self1);
    Mat retval;

    if(JsObject_Size(js_args) == 0 && (!kw || JsObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv_UMat_get(_self_));
        return jsopencv_from(retval);
    }

    return NULL;
}

static JsObject* jsopencv_cv_UMat_handle(JsObject* self, JsObject* js_args, JsObject* kw)
{
    using namespace cv;


    Ptr<cv::UMat> * self1 = 0;
    if (!jsopencv_UMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'UMat' or its derivative)");
    Ptr<cv::UMat> _self_ = *(self1);
    JsObject* jsobj_accessFlags = NULL;
    AccessFlag accessFlags=static_cast<AccessFlag>(0);
    void* retval;

    const char* keywords[] = { "accessFlags", NULL };
    if( JsArg_ParseTupleAndKeywords(js_args, kw, "O:UMat.handle", (char**)keywords, &jsobj_accessFlags) &&
        jsopencv_to_safe(jsobj_accessFlags, accessFlags, ArgInfo("accessFlags", 0)) )
    {
        ERRWRAP2(retval = _self_->handle(accessFlags));
        return jsopencv_from(retval);
    }

    return NULL;
}

static JsObject* jsopencv_cv_UMat_isContinuous(JsObject* self, JsObject* js_args, JsObject* kw)
{
    using namespace cv;


    Ptr<cv::UMat> * self1 = 0;
    if (!jsopencv_UMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'UMat' or its derivative)");
    Ptr<cv::UMat> _self_ = *(self1);
    bool retval;

    if(JsObject_Size(js_args) == 0 && (!kw || JsObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isContinuous());
        return jsopencv_from(retval);
    }

    return NULL;
}

static JsObject* jsopencv_cv_UMat_isSubmatrix(JsObject* self, JsObject* js_args, JsObject* kw)
{
    using namespace cv;


    Ptr<cv::UMat> * self1 = 0;
    if (!jsopencv_UMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'UMat' or its derivative)");
    Ptr<cv::UMat> _self_ = *(self1);
    bool retval;

    if(JsObject_Size(js_args) == 0 && (!kw || JsObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isSubmatrix());
        return jsopencv_from(retval);
    }

    return NULL;
}

static JsObject* jsopencv_cv_UMat_queue_static(JsObject* self, JsObject* js_args, JsObject* kw)
{
    using namespace cv;

    void* retval;

    if(JsObject_Size(js_args) == 0 && (!kw || JsObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv_UMat_queue());
        return jsopencv_from(retval);
    }

    return NULL;
}



// Tables (UMat)

static JsGetSetDef jsopencv_UMat_getseters[] =
{
    {(char*)"offset", (getter)jsopencv_UMat_get_offset, (setter)jsopencv_UMat_set_offset, (char*)"offset", NULL},
    {NULL}  /* Sentinel */
};

static JsMethodDef jsopencv_UMat_methods[] =
{
    {"context", CV_JS_FN_WITH_KW_(jsopencv_cv_UMat_context_static, METH_STATIC), "context() -> retval\n."},
    {"get", CV_JS_FN_WITH_KW_(jsopencv_cv_UMat_get, 0), "get() -> retval\n."},
    {"handle", CV_JS_FN_WITH_KW_(jsopencv_cv_UMat_handle, 0), "handle(accessFlags) -> retval\n."},
    {"isContinuous", CV_JS_FN_WITH_KW_(jsopencv_cv_UMat_isContinuous, 0), "isContinuous() -> retval\n."},
    {"isSubmatrix", CV_JS_FN_WITH_KW_(jsopencv_cv_UMat_isSubmatrix, 0), "isSubmatrix() -> retval\n."},
    {"queue", CV_JS_FN_WITH_KW_(jsopencv_cv_UMat_queue_static, METH_STATIC), "queue() -> retval\n."},

    {NULL,          NULL}
};

// Converter (UMat)

template<>
struct JsOpenCV_Converter< Ptr<cv::UMat> >
{
    static JsObject* from(const Ptr<cv::UMat>& r)
    {
        return jsopencv_UMat_Instance(r);
    }
    static bool to(JsObject* src, Ptr<cv::UMat>& dst, const ArgInfo& info)
    {
        if(!src || src == Js_None)
            return true;
        Ptr<cv::UMat> * dst_;
        if (jsopencv_UMat_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
    {
        Ptr<Mat> _src;
        if (jsopencv_to_safe(src, _src, info))
        {
            return cv_mappable_to(_src, dst);
        }
    }

        failmsg("Expected Ptr<cv::UMat> for argument '%s'", info.name);
        return false;
    }
};