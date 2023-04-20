#include "../cc-common/cv2_convert.h"
#include "../cc-common/cv2_util.h"
#include "../cc-generated/jsopencv_generated_include.h"

#include "./AKAZE.h"

// extract from jsopencv_generated_enums.h
using namespace cv;

typedef cv::AKAZE::DescriptorType AKAZE_DescriptorType;
CV_JS_FROM_ENUM(AKAZE_DescriptorType);
CV_JS_TO_ENUM(AKAZE_DescriptorType);

typedef cv::KAZE::DiffusivityType KAZE_DiffusivityType;
CV_JS_FROM_ENUM(KAZE_DiffusivityType);
CV_JS_TO_ENUM(KAZE_DiffusivityType);

// extract from jsopencv_generated_types.h

// CVJS_TYPE(AKAZE, AKAZE, cv::Ptr<cv::AKAZE>, Ptr, Feature2D, 0, "");

struct jsopencv_AKAZE_t
{
    cv::Ptr<cv::AKAZE> v;
};
static JsTypeObject jsopencv_AKAZE_TypeXXX = {
    "cv2.AKAZE",
    sizeof(jsopencv_AKAZE_t),
};

static JsTypeObject *jsopencv_AKAZE_TypePtr = &jsopencv_AKAZE_TypeXXX;

static bool jsopencv_AKAZE_getp(Napi::Value *self, cv::Ptr<cv::AKAZE> *&dst)
{
    if (JsObject_TypeCheck(self, jsopencv_AKAZE_TypePtr))
    {
        dst = getInternalData<cv::Ptr<cv::AKAZE>>(*self);
        return true;
    }
    return false;
}
static Napi::Value jsopencv_AKAZE_Instance(const Napi::Env &env, const cv::Ptr<cv::AKAZE> &r)
{
    Napi::Object m = _JsObject_New(env, jsopencv_AKAZE_TypePtr);
    void *memoryBlockPtr = getInternalData<char>(m);
    new (memoryBlockPtr) cv::Ptr<cv::AKAZE>(r);
    return m;
}
static void jsopencv_AKAZE_dealloc(Napi::Value *self) { ((jsopencv_AKAZE_t *)self)->v.cv::Ptr<cv::AKAZE>::~Ptr(); }
static Napi::Value jsopencv_AKAZE_repr(Napi::Value *self)
{
    char str[1000];
    snprintf(str, sizeof(str), "< cv2.AKAZE %p>", self);
    return JsString_FromString(self->Env(), str);
}

// extract from jsopencv_generated_types_content.h

//================================================================================
// AKAZE (Generic)
//================================================================================

// GetSet (AKAZE)

// Methods (AKAZE)

static Napi::Value jsopencv_cv_AKAZE_create_static(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

    Napi::Value *jsobj_descriptor_type = NULL;
    AKAZE_DescriptorType descriptor_type = AKAZE::DESCRIPTOR_MLDB;
    Napi::Value *jsobj_descriptor_size = NULL;
    int descriptor_size = 0;
    Napi::Value *jsobj_descriptor_channels = NULL;
    int descriptor_channels = 3;
    Napi::Value *jsobj_threshold = NULL;
    float threshold = 0.001f;
    Napi::Value *jsobj_nOctaves = NULL;
    int nOctaves = 4;
    Napi::Value *jsobj_nOctaveLayers = NULL;
    int nOctaveLayers = 4;
    Napi::Value *jsobj_diffusivity = NULL;
    KAZE_DiffusivityType diffusivity = KAZE::DIFF_PM_G2;
    Ptr<AKAZE> retval;

    const char *keywords[] = {"descriptor_type", "descriptor_size", "descriptor_channels", "threshold", "nOctaves", "nOctaveLayers", "diffusivity", NULL};
    if (JsArg_ParseTupleAndKeywords(info, "|OOOOOOO:AKAZE.create", (char **)keywords, &jsobj_descriptor_type, &jsobj_descriptor_size, &jsobj_descriptor_channels, &jsobj_threshold, &jsobj_nOctaves, &jsobj_nOctaveLayers, &jsobj_diffusivity) &&
        jsopencv_to_safe(jsobj_descriptor_type, descriptor_type, ArgInfo("descriptor_type", 0)) &&
        jsopencv_to_safe(jsobj_descriptor_size, descriptor_size, ArgInfo("descriptor_size", 0)) &&
        jsopencv_to_safe(jsobj_descriptor_channels, descriptor_channels, ArgInfo("descriptor_channels", 0)) &&
        jsopencv_to_safe(jsobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        jsopencv_to_safe(jsobj_nOctaves, nOctaves, ArgInfo("nOctaves", 0)) &&
        jsopencv_to_safe(jsobj_nOctaveLayers, nOctaveLayers, ArgInfo("nOctaveLayers", 0)) &&
        jsopencv_to_safe(jsobj_diffusivity, diffusivity, ArgInfo("diffusivity", 0)))
    {
        ERRWRAP2_NAPI(env, retval = cv::AKAZE::create(descriptor_type, descriptor_size, descriptor_channels, threshold, nOctaves, nOctaveLayers, diffusivity));
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

static Napi::Value jsopencv_cv_AKAZE_getDefaultName(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

    Ptr<cv::AKAZE> *self1 = 0;
    if (!jsopencv_AKAZE_getp(&(info.This()), self1))
        return jsfailmsgp(env, "Incorrect type of self (must be 'AKAZE' or its derivative)");
    Ptr<cv::AKAZE> _self_ = *(self1);
    String retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = _self_->getDefaultName());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

static Napi::Value jsopencv_cv_AKAZE_getDescriptorChannels(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

    Ptr<cv::AKAZE> *self1 = 0;
    if (!jsopencv_AKAZE_getp(&(info.This()), self1))
        return jsfailmsgp(env, "Incorrect type of self (must be 'AKAZE' or its derivative)");
    Ptr<cv::AKAZE> _self_ = *(self1);
    int retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = _self_->getDescriptorChannels());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

static Napi::Value jsopencv_cv_AKAZE_getDescriptorSize(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

    Ptr<cv::AKAZE> *self1 = 0;
    if (!jsopencv_AKAZE_getp(&(info.This()), self1))
        return jsfailmsgp(env, "Incorrect type of self (must be 'AKAZE' or its derivative)");
    Ptr<cv::AKAZE> _self_ = *(self1);
    int retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = _self_->getDescriptorSize());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

static Napi::Value jsopencv_cv_AKAZE_getDescriptorType(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

    Ptr<cv::AKAZE> *self1 = 0;
    if (!jsopencv_AKAZE_getp(&(info.This()), self1))
        return jsfailmsgp(env, "Incorrect type of self (must be 'AKAZE' or its derivative)");
    Ptr<cv::AKAZE> _self_ = *(self1);
    AKAZE::DescriptorType retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = _self_->getDescriptorType());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

static Napi::Value jsopencv_cv_AKAZE_getDiffusivity(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

    Ptr<cv::AKAZE> *self1 = 0;
    if (!jsopencv_AKAZE_getp(&(info.This()), self1))
        return jsfailmsgp(env, "Incorrect type of self (must be 'AKAZE' or its derivative)");
    Ptr<cv::AKAZE> _self_ = *(self1);
    KAZE::DiffusivityType retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = _self_->getDiffusivity());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

static Napi::Value jsopencv_cv_AKAZE_getNOctaveLayers(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

    Ptr<cv::AKAZE> *self1 = 0;
    if (!jsopencv_AKAZE_getp(&(info.This()), self1))
        return jsfailmsgp(env, "Incorrect type of self (must be 'AKAZE' or its derivative)");
    Ptr<cv::AKAZE> _self_ = *(self1);
    int retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = _self_->getNOctaveLayers());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

static Napi::Value jsopencv_cv_AKAZE_getNOctaves(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

    Ptr<cv::AKAZE> *self1 = 0;
    if (!jsopencv_AKAZE_getp(&(info.This()), self1))
        return jsfailmsgp(env, "Incorrect type of self (must be 'AKAZE' or its derivative)");
    Ptr<cv::AKAZE> _self_ = *(self1);
    int retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = _self_->getNOctaves());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

static Napi::Value jsopencv_cv_AKAZE_getThreshold(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

    Ptr<cv::AKAZE> *self1 = 0;
    if (!jsopencv_AKAZE_getp(&(info.This()), self1))
        return jsfailmsgp(env, "Incorrect type of self (must be 'AKAZE' or its derivative)");
    Ptr<cv::AKAZE> _self_ = *(self1);
    double retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = _self_->getThreshold());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

static Napi::Value jsopencv_cv_AKAZE_setDescriptorChannels(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

    Ptr<cv::AKAZE> *self1 = 0;
    if (!jsopencv_AKAZE_getp(&(info.This()), self1))
        return jsfailmsgp(env, "Incorrect type of self (must be 'AKAZE' or its derivative)");
    Ptr<cv::AKAZE> _self_ = *(self1);
    Napi::Value *jsobj_dch = NULL;
    int dch = 0;

    const char *keywords[] = {"dch", NULL};
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setDescriptorChannels", (char **)keywords, &jsobj_dch) &&
        jsopencv_to_safe(jsobj_dch, dch, ArgInfo("dch", 0)))
    {
        ERRWRAP2_NAPI(env, _self_->setDescriptorChannels(dch));
        return env.Null();
        ;
    }

    return env.Null();
}

static Napi::Value jsopencv_cv_AKAZE_setDescriptorSize(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

    Ptr<cv::AKAZE> *self1 = 0;
    if (!jsopencv_AKAZE_getp(&(info.This()), self1))
        return jsfailmsgp(env, "Incorrect type of self (must be 'AKAZE' or its derivative)");
    Ptr<cv::AKAZE> _self_ = *(self1);
    Napi::Value *jsobj_dsize = NULL;
    int dsize = 0;

    const char *keywords[] = {"dsize", NULL};
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setDescriptorSize", (char **)keywords, &jsobj_dsize) &&
        jsopencv_to_safe(jsobj_dsize, dsize, ArgInfo("dsize", 0)))
    {
        ERRWRAP2_NAPI(env, _self_->setDescriptorSize(dsize));
        return env.Null();
        ;
    }

    return env.Null();
}

static Napi::Value jsopencv_cv_AKAZE_setDescriptorType(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

    Ptr<cv::AKAZE> *self1 = 0;
    if (!jsopencv_AKAZE_getp(&(info.This()), self1))
        return jsfailmsgp(env, "Incorrect type of self (must be 'AKAZE' or its derivative)");
    Ptr<cv::AKAZE> _self_ = *(self1);
    Napi::Value *jsobj_dtype = NULL;
    AKAZE_DescriptorType dtype = static_cast<AKAZE_DescriptorType>(0);

    const char *keywords[] = {"dtype", NULL};
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setDescriptorType", (char **)keywords, &jsobj_dtype) &&
        jsopencv_to_safe(jsobj_dtype, dtype, ArgInfo("dtype", 0)))
    {
        ERRWRAP2_NAPI(env, _self_->setDescriptorType(dtype));
        return env.Null();
        ;
    }

    return env.Null();
}

static Napi::Value jsopencv_cv_AKAZE_setDiffusivity(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

    Ptr<cv::AKAZE> *self1 = 0;
    if (!jsopencv_AKAZE_getp(&(info.This()), self1))
        return jsfailmsgp(env, "Incorrect type of self (must be 'AKAZE' or its derivative)");
    Ptr<cv::AKAZE> _self_ = *(self1);
    Napi::Value *jsobj_diff = NULL;
    KAZE_DiffusivityType diff = static_cast<KAZE_DiffusivityType>(0);

    const char *keywords[] = {"diff", NULL};
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setDiffusivity", (char **)keywords, &jsobj_diff) &&
        jsopencv_to_safe(jsobj_diff, diff, ArgInfo("diff", 0)))
    {
        ERRWRAP2_NAPI(env, _self_->setDiffusivity(diff));
        return env.Null();
        ;
    }

    return env.Null();
}

static Napi::Value jsopencv_cv_AKAZE_setNOctaveLayers(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

    Ptr<cv::AKAZE> *self1 = 0;
    if (!jsopencv_AKAZE_getp(&(info.This()), self1))
        return jsfailmsgp(env, "Incorrect type of self (must be 'AKAZE' or its derivative)");
    Ptr<cv::AKAZE> _self_ = *(self1);
    Napi::Value *jsobj_octaveLayers = NULL;
    int octaveLayers = 0;

    const char *keywords[] = {"octaveLayers", NULL};
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setNOctaveLayers", (char **)keywords, &jsobj_octaveLayers) &&
        jsopencv_to_safe(jsobj_octaveLayers, octaveLayers, ArgInfo("octaveLayers", 0)))
    {
        ERRWRAP2_NAPI(env, _self_->setNOctaveLayers(octaveLayers));
        return env.Null();
        ;
    }

    return env.Null();
}

static Napi::Value jsopencv_cv_AKAZE_setNOctaves(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

    Ptr<cv::AKAZE> *self1 = 0;
    if (!jsopencv_AKAZE_getp(&(info.This()), self1))
        return jsfailmsgp(env, "Incorrect type of self (must be 'AKAZE' or its derivative)");
    Ptr<cv::AKAZE> _self_ = *(self1);
    Napi::Value *jsobj_octaves = NULL;
    int octaves = 0;

    const char *keywords[] = {"octaves", NULL};
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setNOctaves", (char **)keywords, &jsobj_octaves) &&
        jsopencv_to_safe(jsobj_octaves, octaves, ArgInfo("octaves", 0)))
    {
        ERRWRAP2_NAPI(env, _self_->setNOctaves(octaves));
        return env.Null();
        ;
    }

    return env.Null();
}

static Napi::Value jsopencv_cv_AKAZE_setThreshold(const Napi::CallbackInfo &info)
{
    using namespace cv;
    Napi::Env env = info.Env();

    Ptr<cv::AKAZE> *self1 = 0;
    if (!jsopencv_AKAZE_getp(&(info.This()), self1))
        return jsfailmsgp(env, "Incorrect type of self (must be 'AKAZE' or its derivative)");
    Ptr<cv::AKAZE> _self_ = *(self1);
    Napi::Value *jsobj_threshold = NULL;
    double threshold = 0;

    const char *keywords[] = {"threshold", NULL};
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setThreshold", (char **)keywords, &jsobj_threshold) &&
        jsopencv_to_safe(jsobj_threshold, threshold, ArgInfo("threshold", 0)))
    {
        ERRWRAP2_NAPI(env, _self_->setThreshold(threshold));
        return env.Null();
        ;
    }

    return env.Null();
}

// init_body define CVPY_MODULE
// #include "pyopencv_generated_modules.h"
// define CVPY_TYPE as CVPY_TYPE_INIT_DYNAMIC or CVPY_TYPE_INIT_STATIC
// #include "pyopencv_generated_types.h"
//
// call PUBLISH CV_XXUXX

// Tables (AKAZE)
// used by macro: CVJS_TYPE_INIT_DYNAMIC
//
//
static JsGetSetDef jsopencv_AKAZE_getseters[] =
    {
        {NULL} /* Sentinel */
};

static JsMethodDef jsopencv_AKAZE_methods[] =
    {
        // {"create", CV_JS_FN_WITH_KW_(jsopencv_cv_AKAZE_create_static, METH_STATIC), "create([, descriptor_type[, descriptor_size[, descriptor_channels[, threshold[, nOctaves[, nOctaveLayers[, diffusivity]]]]]]]) -> retval\n.   @brief The AKAZE constructor\n.   \n.       @param descriptor_type Type of the extracted descriptor: DESCRIPTOR_KAZE,\n.       DESCRIPTOR_KAZE_UPRIGHT, DESCRIPTOR_MLDB or DESCRIPTOR_MLDB_UPRIGHT.\n.       @param descriptor_size Size of the descriptor in bits. 0 -\\> Full size\n.       @param descriptor_channels Number of channels in the descriptor (1, 2, 3)\n.       @param threshold Detector response threshold to accept point\n.       @param nOctaves Maximum octave evolution of the image\n.       @param nOctaveLayers Default number of sublevels per scale level\n.       @param diffusivity Diffusivity type. DIFF_PM_G1, DIFF_PM_G2, DIFF_WEICKERT or\n.       DIFF_CHARBONNIER"},
        {"create", jsopencv_cv_AKAZE_create_static, METH_STATIC, "create([, descriptor_type[, descriptor_size[, descriptor_channels[, threshold[, nOctaves[, nOctaveLayers[, diffusivity]]]]]]]) -> retval\n.   @brief The AKAZE constructor\n.   \n.       @param descriptor_type Type of the extracted descriptor: DESCRIPTOR_KAZE,\n.       DESCRIPTOR_KAZE_UPRIGHT, DESCRIPTOR_MLDB or DESCRIPTOR_MLDB_UPRIGHT.\n.       @param descriptor_size Size of the descriptor in bits. 0 -\\> Full size\n.       @param descriptor_channels Number of channels in the descriptor (1, 2, 3)\n.       @param threshold Detector response threshold to accept point\n.       @param nOctaves Maximum octave evolution of the image\n.       @param nOctaveLayers Default number of sublevels per scale level\n.       @param diffusivity Diffusivity type. DIFF_PM_G1, DIFF_PM_G2, DIFF_WEICKERT or\n.       DIFF_CHARBONNIER"},
        {"getDefaultName", jsopencv_cv_AKAZE_getDefaultName, 0, "getDefaultName() -> retval\n."},
        {"getDescriptorChannels", jsopencv_cv_AKAZE_getDescriptorChannels, 0, "getDescriptorChannels() -> retval\n."},
        {"getDescriptorSize", jsopencv_cv_AKAZE_getDescriptorSize, 0, "getDescriptorSize() -> retval\n."},
        {"getDescriptorType", jsopencv_cv_AKAZE_getDescriptorType, 0, "getDescriptorType() -> retval\n."},
        {"getDiffusivity", jsopencv_cv_AKAZE_getDiffusivity, 0, "getDiffusivity() -> retval\n."},
        {"getNOctaveLayers", jsopencv_cv_AKAZE_getNOctaveLayers, 0, "getNOctaveLayers() -> retval\n."},
        {"getNOctaves", jsopencv_cv_AKAZE_getNOctaves, 0, "getNOctaves() -> retval\n."},
        {"getThreshold", jsopencv_cv_AKAZE_getThreshold, 0, "getThreshold() -> retval\n."},
        {"setDescriptorChannels", jsopencv_cv_AKAZE_setDescriptorChannels, 0, "setDescriptorChannels(dch) -> None\n."},
        {"setDescriptorSize", jsopencv_cv_AKAZE_setDescriptorSize, 0, "setDescriptorSize(dsize) -> None\n."},
        {"setDescriptorType", jsopencv_cv_AKAZE_setDescriptorType, 0, "setDescriptorType(dtype) -> None\n."},
        {"setDiffusivity", jsopencv_cv_AKAZE_setDiffusivity, 0, "setDiffusivity(diff) -> None\n."},
        {"setNOctaveLayers", jsopencv_cv_AKAZE_setNOctaveLayers, 0, "setNOctaveLayers(octaveLayers) -> None\n."},
        {"setNOctaves", jsopencv_cv_AKAZE_setNOctaves, 0, "setNOctaves(octaves) -> None\n."},
        {"setThreshold", jsopencv_cv_AKAZE_setThreshold, 0, "setThreshold(threshold) -> None\n."},
        {NULL, NULL}};

// Converter (AKAZE)

template <>
struct JsOpenCV_Converter<Ptr<cv::AKAZE>>
{
    static Napi::Value from(const Napi::Env &env, const Ptr<cv::AKAZE> &r)
    {
        return jsopencv_AKAZE_Instance(env, r);
    }
    static bool to(Napi::Value *src, Ptr<cv::AKAZE> &dst, const ArgInfo &info)
    {
        if (!src || src->IsNull() || src->IsUndefined())
            return true;
        Ptr<cv::AKAZE> *dst_;
        if (jsopencv_AKAZE_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }

        jsfailmsg(src->Env(), "Expected Ptr<cv::AKAZE> for argument '%s'", info.name);
        return false;
    }
};

Napi::Value AKAZE_constructor(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    cv::Ptr<cv::AKAZE> akaze = cv::AKAZE::create();
    // use pointer or smart pointer ?
    Napi::Object thisObj = info.This().As<Napi::Object>();
    thisObj.Set(DATA_TYPE, Napi::External<AKAZE>::New(env, akaze));
    thisObj.Set(DATA_KEY, Napi::External<AKAZE>::New(env, akaze));
    // should use _JsObject_New via JsObject_NEW
    // via static Napi::Value jsopencv_##CLASS_ID##_Instance(const Napi::Env &env, const STORAGE &r)
    // via #define CVJS_TYPE_DECLARE(EXPORT_NAME, CLASS_ID, STORAGE, SNAME, SCOPE) \

    return info.This();
}


Napi::Value jsopencv_cv_AKAZE_setDescriptorSize2(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int descriptorSize = info[0].As<Napi::Number>().Int32Value();
    AKAZE *akaze = info.This().As<Napi::Object>().Get(DATA_KEY).As<Napi::External<AKAZE>>().Data();
    akaze->setDescriptorSize(descriptorSize);
    return env.Null();   
}


Napi::Object InitAKAZE(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    DATA_KEY = Napi::Symbol::New(env);
    Napi::Function akazeConstructor = Napi::Function::New(env, AKAZE_constructor);

    std::vector<Napi::PropertyDescriptor> list;
    for (const auto &method : jsopencv_AKAZE_methods)
    {
        // desc = Napi::PropertyDescriptor::Function(env, akazeConstructor, "setDescriptorSize", Napi::Function::New(env, jsopencv_cv_AKAZE_setDescriptorSize));

        // Napi::Value (*fncPtr)(const Napi::CallbackInfo &info) = jsopencv_cv_AKAZE_setDescriptorSize2; // method.ml_meth;
        // Napi::Function napiFnc = Napi::Function::New(env, fncPtr);
        // if (method.ml_flags == 0)
        // {
        //     Napi::PropertyDescriptor desc = Napi::PropertyDescriptor::Function(
        //         env,
        //         (Napi::Object)akazeConstructor,
        //         method.ml_name,
        //         napiFnc);
        //     list.push_back(desc);
        // }
        // else if (method.ml_flags == METH_STATIC)
        // {
        //     akazeConstructor[method.ml_name] = napiFnc; // Napi::Function::New(env, method.ml_meth);
        // }
    }
    // akazeConstructor.As<Napi::Object>().DefineProperties(list);

    exports.Set("AKAZE", akazeConstructor);
    return exports;
}