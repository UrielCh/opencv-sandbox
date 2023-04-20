// #include "../sandbox/sample.cpp"
#include "./AKAZE.h"

#include "../cc-common/cv2_convert.h"
#include "../cc-common/cv2_util.h"
#include "../cc-generated/jsopencv_generated_include.h"

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

struct jsopencv_AKAZE_t {
    cv::Ptr<cv::AKAZE> v;
};
static JsTypeObject jsopencv_AKAZE_TypeXXX = {
    "cv2.AKAZE",
    sizeof(jsopencv_AKAZE_t),
};

static JsTypeObject *jsopencv_AKAZE_TypePtr = &jsopencv_AKAZE_TypeXXX;

static bool jsopencv_AKAZE_getp(Napi::Value *self, cv::Ptr<cv::AKAZE> *&dst) {
    if (JsObject_TypeCheck(self, jsopencv_AKAZE_TypePtr)) {
        dst = getInternalData<cv::Ptr<cv::AKAZE>>(*self);
        return true;
    }
    return false;
}

static void jsopencv_AKAZE_dealloc(Napi::Value *self) { ((jsopencv_AKAZE_t *)self)->v.cv::Ptr<cv::AKAZE>::~Ptr(); }
static Napi::Value jsopencv_AKAZE_repr(Napi::Value *self) {
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
// Converter (AKAZE)

static Napi::Value jsopencv_AKAZE_Instance(const Napi::Env &env, const cv::Ptr<cv::AKAZE> &r) {
    Napi::Object newInstance = AKAZEWrapper::constructor.New({});
    // Napi::Object m = _JsObject_New(env, jsopencv_AKAZE_TypePtr);
    //  void *memoryBlockPtr = getInternalData<void>(m);
    //  new (memoryBlockPtr) cv::Ptr<cv::AKAZE>(r);
    std::cout << "jsopencv_AKAZE_Instance" << std::endl;
    newInstance.Set("DATA_TYPE", jsopencv_AKAZE_TypeXXX.type);

    // thisObj.Set(DATA_KEY, jsopencv_AKAZE_TypeXXX.type); //  Napi::External<AKAZE>::New(env, akaze)
    // newInstance.Set("DATA_KEY", Napi::External<AKAZE>::New(env, r));  //  Napi::External<AKAZE>::New(env, akaze)
    // newInstance.akaze_ = r;
    std::cout << "jsopencv_AKAZE_Instance done" << std::endl;
    return newInstance;
}

template <>
struct JsOpenCV_Converter<Ptr<cv::AKAZE>> {
    static Napi::Value from(const Napi::Env &env, const Ptr<cv::AKAZE> &r) {
        // std::cout << "AKAZE from JsOpenCV_Converter<Ptr<cv::AKAZE>> " << std::endl;
        return jsopencv_AKAZE_Instance(env, r);
    }
    static bool to(Napi::Value *src, Ptr<cv::AKAZE> &dst, const ArgInfo &info) {
        if (!src || src->IsNull() || src->IsUndefined())
            return true;
        Ptr<cv::AKAZE> *dst_;
        if (jsopencv_AKAZE_getp(src, dst_)) {
            dst = *dst_;
            return true;
        }

        jsfailmsg(src->Env(), "Expected Ptr<cv::AKAZE> for argument '%s'", info.name);
        return false;
    }
};

Napi::Value AKAZE_constructor(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    cv::Ptr<cv::AKAZE> akaze = cv::AKAZE::create();
    // use pointer or smart pointer ?
    Napi::Object thisObj = info.This().As<Napi::Object>();
    // thisObj.Set(DATA_TYPE, Napi::External<AKAZE>::New(env, akaze));
    thisObj.Set("DATA_TYPE", jsopencv_AKAZE_TypeXXX.type);

    // thisObj.Set(DATA_KEY, jsopencv_AKAZE_TypeXXX.type); //  Napi::External<AKAZE>::New(env, akaze)
    thisObj.Set("DATA_KEY", Napi::External<AKAZE>::New(env, akaze));  //  Napi::External<AKAZE>::New(env, akaze)
    // should use _JsObject_New via JsObject_NEW
    // via static Napi::Value jsopencv_##CLASS_ID##_Instance(const Napi::Env &env, const STORAGE &r)
    // via #define CVJS_TYPE_DECLARE(EXPORT_NAME, CLASS_ID, STORAGE, SNAME, SCOPE) \

    return info.This();
}

// Object wrapper

// class AKAZEWrapper : public Napi::ObjectWrap<AKAZEWrapper> {
// static Napi::Object AKAZEWrapper::Init(Napi::Env env, Napi::Object exports);
// AKAZEWrapper::AKAZEWrapper(const Napi::CallbackInfo &info);
// static Napi::FunctionReference AKAZEWrapper::constructor;

// AKAZE *akaze_;

// Wrapped methods
Napi::Value AKAZEWrapper::getDefaultName(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->akaze_;
    String retval;
    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty())) {
        ERRWRAP2_NAPI(env, retval = _self_->getDefaultName());
        return jsopencv_from(env, retval);
    }
    return env.Null();
}
Napi::Value AKAZEWrapper::getDescriptorSize(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Value *jsobj_dsize = NULL;
    Ptr<cv::AKAZE> _self_ = this->akaze_;
    int retval;
    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = _self_->getDescriptorSize());
        return jsopencv_from(env, retval);
    }
    return env.Null();
}
Napi::Value AKAZEWrapper::getDescriptorType(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->akaze_;
    // Ptr<cv::AKAZE> *self1 = 0;
    // if (!jsopencv_AKAZE_getp(&(info.This()), self1))
    //     return jsfailmsgp(env, "Incorrect type of self (must be 'AKAZE' or its derivative)");
    // Ptr<cv::AKAZE> _self_ = *(self1);
    AKAZE::DescriptorType retval;
    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty())) {
        ERRWRAP2_NAPI(env, retval = _self_->getDescriptorType());
        return jsopencv_from(env, retval);
    }
    return env.Null();
}
Napi::Value AKAZEWrapper::setDescriptorSize(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->akaze_;
    Napi::Value *jsobj_dtype = NULL;
    AKAZE_DescriptorType dtype = static_cast<AKAZE_DescriptorType>(0);
    const char *keywords[] = {"dtype", NULL};
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setDescriptorType", (char **)keywords, &jsobj_dtype) &&
        jsopencv_to_safe(jsobj_dtype, dtype, ArgInfo("dtype", 0))) {
        ERRWRAP2_NAPI(env, _self_->setDescriptorType(dtype));
        return env.Null();
    }
    return env.Null();
}
Napi::Value AKAZEWrapper::setDescriptorType(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->akaze_;
    Napi::Value *jsobj_dtype = NULL;
    AKAZE_DescriptorType dtype = static_cast<AKAZE_DescriptorType>(0);
    const char *keywords[] = {"dtype", NULL};
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setDescriptorType", (char **)keywords, &jsobj_dtype) &&
        jsopencv_to_safe(jsobj_dtype, dtype, ArgInfo("dtype", 0))) {
        ERRWRAP2_NAPI(env, _self_->setDescriptorType(dtype));
        return env.Null();
    }
    return env.Null();
}
Napi::Value AKAZEWrapper::setThreshold(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->akaze_;
    Napi::Value *jsobj_threshold = NULL;
    double threshold = 0;
    const char *keywords[] = {"threshold", NULL};
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setThreshold", (char **)keywords, &jsobj_threshold) &&
        jsopencv_to_safe(jsobj_threshold, threshold, ArgInfo("threshold", 0))) {
        ERRWRAP2_NAPI(env, _self_->setThreshold(threshold));
        return env.Null();
    }
    return env.Null();
}
Napi::Value AKAZEWrapper::setNOctaves(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->akaze_;
    Napi::Value *jsobj_octaves = NULL;
    int octaves = 0;
    const char *keywords[] = {"octaves", NULL};
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setNOctaves", (char **)keywords, &jsobj_octaves) &&
        jsopencv_to_safe(jsobj_octaves, octaves, ArgInfo("octaves", 0))) {
        ERRWRAP2_NAPI(env, _self_->setNOctaves(octaves));
        return env.Null();
    }
    return env.Null();
}
Napi::Value AKAZEWrapper::setNOctaveLayers(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->akaze_;
    Napi::Value *jsobj_octaveLayers = NULL;
    int octaveLayers = 0;
    const char *keywords[] = {"octaveLayers", NULL};
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setNOctaveLayers", (char **)keywords, &jsobj_octaveLayers) &&
        jsopencv_to_safe(jsobj_octaveLayers, octaveLayers, ArgInfo("octaveLayers", 0))) {
        ERRWRAP2_NAPI(env, _self_->setNOctaveLayers(octaveLayers));
        return env.Null();
    }
    return env.Null();
}
Napi::Value AKAZEWrapper::setDescriptorChannels(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->akaze_;
    Napi::Value *jsobj_dch = NULL;
    int dch = 0;
    const char *keywords[] = {"dch", NULL};
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setDescriptorChannels", (char **)keywords, &jsobj_dch) &&
        jsopencv_to_safe(jsobj_dch, dch, ArgInfo("dch", 0))) {
        ERRWRAP2_NAPI(env, _self_->setDescriptorChannels(dch));
        return env.Null();
    }
    return env.Null();
}
Napi::Value AKAZEWrapper::setDiffusivity(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->akaze_;
    Napi::Value *jsobj_diff = NULL;
    KAZE_DiffusivityType diff = static_cast<KAZE_DiffusivityType>(0);
    const char *keywords[] = {"diff", NULL};
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setDiffusivity", (char **)keywords, &jsobj_diff) &&
        jsopencv_to_safe(jsobj_diff, diff, ArgInfo("diff", 0))) {
        ERRWRAP2_NAPI(env, _self_->setDiffusivity(diff));
        return env.Null();
    }
    return env.Null();
}
Napi::Value AKAZEWrapper::getNOctaves(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->akaze_;
    int retval;
    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty())) {
        ERRWRAP2_NAPI(env, retval = _self_->getNOctaves());
        return jsopencv_from(env, retval);
    }
    return env.Null();
}
Napi::Value AKAZEWrapper::getThreshold(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->akaze_;
    double retval;
    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty())) {
        ERRWRAP2_NAPI(env, retval = _self_->getThreshold());
        return jsopencv_from(env, retval);
    }
    return env.Null();
}
Napi::Value AKAZEWrapper::getDiffusivity(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->akaze_;
    KAZE::DiffusivityType retval;
    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty())) {
        ERRWRAP2_NAPI(env, retval = _self_->getDiffusivity());
        return jsopencv_from(env, retval);
    }
    return env.Null();
}
Napi::Value AKAZEWrapper::getNOctaveLayers(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->akaze_;
    int retval;
    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty())) {
        ERRWRAP2_NAPI(env, retval = _self_->getNOctaveLayers());
        return jsopencv_from(env, retval);
    }
    return env.Null();
}
Napi::Value AKAZEWrapper::getDescriptorChannels(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->akaze_;
    int retval;
    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty())) {
        ERRWRAP2_NAPI(env, retval = _self_->getDescriptorChannels());
        return jsopencv_from(env, retval);
    }
    return env.Null();
}

std::vector<napi_value> CallbackInfoToVector(const Napi::CallbackInfo &info) {
  std::vector<napi_value> args;
  size_t numArgs = info.Length();
  for (size_t i = 0; i < numArgs; ++i) {
    args.push_back(info[i]);
  }
  return args;
}

// Static methods
Napi::Value AKAZEWrapper::CreateStatic(const Napi::CallbackInfo &info) {
    Napi::FunctionReference* constructor = info.Env().GetInstanceData<Napi::FunctionReference>();
    return constructor->New(CallbackInfoToVector(info));
}

Napi::FunctionReference AKAZEWrapper::constructor;

Napi::Object AKAZEWrapper::Init(Napi::Env env, Napi::Object exports) {
    Napi::HandleScope scope(env);
    napi_property_attributes atts = static_cast<napi_property_attributes>(napi_writable | napi_configurable);
    Napi::Function func = DefineClass(env, "AKAZE", {
                                                        InstanceMethod<&AKAZEWrapper::getDefaultName>("getDefaultName", atts),
                                                        InstanceMethod<&AKAZEWrapper::getDescriptorSize>("getDescriptorSize", atts),
                                                        InstanceMethod<&AKAZEWrapper::getDescriptorType>("getDescriptorType", atts),
                                                        InstanceMethod<&AKAZEWrapper::setDescriptorSize>("setDescriptorSize", atts),
                                                        InstanceMethod<&AKAZEWrapper::setDescriptorType>("setDescriptorType", atts),
                                                        InstanceMethod<&AKAZEWrapper::setThreshold>("setThreshold", atts),
                                                        InstanceMethod<&AKAZEWrapper::setNOctaves>("setNOctaves", atts),
                                                        InstanceMethod<&AKAZEWrapper::setNOctaveLayers>("setNOctaveLayers", atts),
                                                        InstanceMethod<&AKAZEWrapper::setDescriptorChannels>("setDescriptorChannels", atts),
                                                        InstanceMethod<&AKAZEWrapper::setDiffusivity>("setDiffusivity", atts),
                                                        InstanceMethod<&AKAZEWrapper::getNOctaves>("getNOctaves", atts),
                                                        InstanceMethod<&AKAZEWrapper::getThreshold>("getThreshold", atts),
                                                        InstanceMethod<&AKAZEWrapper::getDescriptorSize>("getDescriptorSize", atts),
                                                        InstanceMethod<&AKAZEWrapper::getDiffusivity>("getDiffusivity", atts),
                                                        InstanceMethod<&AKAZEWrapper::getNOctaveLayers>("getNOctaveLayers", atts),
                                                        InstanceMethod<&AKAZEWrapper::getDescriptorChannels>("getDescriptorChannels", atts),
                                                        StaticMethod<&AKAZEWrapper::CreateStatic>("create", atts),
                                                    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    env.SetInstanceData<Napi::FunctionReference>(&constructor);
    exports.Set("AKAZE", func);
    return exports;
}

AKAZEWrapper::~AKAZEWrapper() {
    this->akaze_.release();
}

// constructor
AKAZEWrapper::AKAZEWrapper(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<AKAZEWrapper>(info) {
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
    // std::cout << "Napi::Value AKAZEWrapper::CreateStatic(const Napi::CallbackInfo &info) {" << std::endl;
    const char *keywords[] = {"descriptor_type", "descriptor_size", "descriptor_channels", "threshold", "nOctaves", "nOctaveLayers", "diffusivity", NULL};
    if (JsArg_ParseTupleAndKeywords(info, "|OOOOOOO:AKAZE.create", (char **)keywords, &jsobj_descriptor_type, &jsobj_descriptor_size, &jsobj_descriptor_channels, &jsobj_threshold, &jsobj_nOctaves, &jsobj_nOctaveLayers, &jsobj_diffusivity) &&
        jsopencv_to_safe(jsobj_descriptor_type, descriptor_type, ArgInfo("descriptor_type", 0)) &&
        jsopencv_to_safe(jsobj_descriptor_size, descriptor_size, ArgInfo("descriptor_size", 0)) &&
        jsopencv_to_safe(jsobj_descriptor_channels, descriptor_channels, ArgInfo("descriptor_channels", 0)) &&
        jsopencv_to_safe(jsobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        jsopencv_to_safe(jsobj_nOctaves, nOctaves, ArgInfo("nOctaves", 0)) &&
        jsopencv_to_safe(jsobj_nOctaveLayers, nOctaveLayers, ArgInfo("nOctaveLayers", 0)) &&
        jsopencv_to_safe(jsobj_diffusivity, diffusivity, ArgInfo("diffusivity", 0))) {
        // std::cout << " JsArg_ParseTupleAndKeywords pass" << std::endl;
        ERRWRAP2_NAPI_VOID(env, retval = cv::AKAZE::create(descriptor_type, descriptor_size, descriptor_channels, threshold, nOctaves, nOctaveLayers, diffusivity));
        this->akaze_ = retval;
    }
}

Napi::Object InitAKAZE(Napi::Env env, Napi::Object exports) {
    exports = AKAZEWrapper::Init(env, exports);
    return exports;
}
