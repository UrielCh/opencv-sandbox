#include "./AKAZE.h"

#include "../cc-common/cv2_convert.h"
#include "../cc-common/cv2_util.h"
#include "../cc-generated/jsopencv_generated_include.h"


// GetSet (AKAZE)



// Methods (AKAZE)

Napi::Value AKAZEWrapper::CreateStatic(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();    Napi::Value *jsobj_descriptor_type = NULL;
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

    const char *keywords[] = { "descriptor_type", "descriptor_size", "descriptor_channels", "threshold", "nOctaves", "nOctaveLayers", "diffusivity", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "|OOOOOOO:AKAZE.create", (char**)keywords, &jsobj_descriptor_type, &jsobj_descriptor_size, &jsobj_descriptor_channels, &jsobj_threshold, &jsobj_nOctaves, &jsobj_nOctaveLayers, &jsobj_diffusivity) &&
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

Napi::Value AKAZEWrapper::getDefaultName(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->cvdata;
    String retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = _self_->getDefaultName());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

Napi::Value AKAZEWrapper::getDescriptorChannels(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->cvdata;
    int retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = _self_->getDescriptorChannels());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

Napi::Value AKAZEWrapper::getDescriptorSize(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->cvdata;
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
    Ptr<cv::AKAZE> _self_ = this->cvdata;
    AKAZE_DescriptorType retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = _self_->getDescriptorType());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

Napi::Value AKAZEWrapper::getDiffusivity(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->cvdata;
    KAZE_DiffusivityType retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = _self_->getDiffusivity());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

Napi::Value AKAZEWrapper::getNOctaveLayers(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->cvdata;
    int retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = _self_->getNOctaveLayers());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

Napi::Value AKAZEWrapper::getNOctaves(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->cvdata;
    int retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = _self_->getNOctaves());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

Napi::Value AKAZEWrapper::getThreshold(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->cvdata;
    double retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = _self_->getThreshold());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

Napi::Value AKAZEWrapper::setDescriptorChannels(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->cvdata;
    Napi::Value *jsobj_dch = NULL;
    int dch = 0;

    const char *keywords[] = { "dch", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setDescriptorChannels", (char**)keywords, &jsobj_dch) &&
        jsopencv_to_safe(jsobj_dch, dch, ArgInfo("dch", 0)))
    {
        ERRWRAP2_NAPI(env, _self_->setDescriptorChannels(dch));
        return env.Null();
    }

    return env.Null();
}

Napi::Value AKAZEWrapper::setDescriptorSize(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->cvdata;
    Napi::Value *jsobj_dsize = NULL;
    int dsize = 0;

    const char *keywords[] = { "dsize", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setDescriptorSize", (char**)keywords, &jsobj_dsize) &&
        jsopencv_to_safe(jsobj_dsize, dsize, ArgInfo("dsize", 0)))
    {
        ERRWRAP2_NAPI(env, _self_->setDescriptorSize(dsize));
        return env.Null();
    }

    return env.Null();
}

Napi::Value AKAZEWrapper::setDescriptorType(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->cvdata;
    Napi::Value *jsobj_dtype = NULL;
    AKAZE_DescriptorType dtype = static_cast<AKAZE_DescriptorType>(0);

    const char *keywords[] = { "dtype", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setDescriptorType", (char**)keywords, &jsobj_dtype) &&
        jsopencv_to_safe(jsobj_dtype, dtype, ArgInfo("dtype", 0)))
    {
        ERRWRAP2_NAPI(env, _self_->setDescriptorType(dtype));
        return env.Null();
    }

    return env.Null();
}

Napi::Value AKAZEWrapper::setDiffusivity(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->cvdata;
    Napi::Value *jsobj_diff = NULL;
    KAZE_DiffusivityType diff = static_cast<KAZE_DiffusivityType>(0);

    const char *keywords[] = { "diff", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setDiffusivity", (char**)keywords, &jsobj_diff) &&
        jsopencv_to_safe(jsobj_diff, diff, ArgInfo("diff", 0)))
    {
        ERRWRAP2_NAPI(env, _self_->setDiffusivity(diff));
        return env.Null();
    }

    return env.Null();
}

Napi::Value AKAZEWrapper::setNOctaveLayers(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->cvdata;
    Napi::Value *jsobj_octaveLayers = NULL;
    int octaveLayers = 0;

    const char *keywords[] = { "octaveLayers", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setNOctaveLayers", (char**)keywords, &jsobj_octaveLayers) &&
        jsopencv_to_safe(jsobj_octaveLayers, octaveLayers, ArgInfo("octaveLayers", 0)))
    {
        ERRWRAP2_NAPI(env, _self_->setNOctaveLayers(octaveLayers));
        return env.Null();
    }

    return env.Null();
}

Napi::Value AKAZEWrapper::setNOctaves(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->cvdata;
    Napi::Value *jsobj_octaves = NULL;
    int octaves = 0;

    const char *keywords[] = { "octaves", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setNOctaves", (char**)keywords, &jsobj_octaves) &&
        jsopencv_to_safe(jsobj_octaves, octaves, ArgInfo("octaves", 0)))
    {
        ERRWRAP2_NAPI(env, _self_->setNOctaves(octaves));
        return env.Null();
    }

    return env.Null();
}

Napi::Value AKAZEWrapper::setThreshold(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->cvdata;
    Napi::Value *jsobj_threshold = NULL;
    double threshold = 0;

    const char *keywords[] = { "threshold", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setThreshold", (char**)keywords, &jsobj_threshold) &&
        jsopencv_to_safe(jsobj_threshold, threshold, ArgInfo("threshold", 0)))
    {
        ERRWRAP2_NAPI(env, _self_->setThreshold(threshold));
        return env.Null();
    }

    return env.Null();
}

// Init (AKAZE)

Napi::Object AKAZEWrapper::Init(Napi::Env env, Napi::Object exports) {
    Napi::HandleScope scope(env);
    napi_property_attributes atts = static_cast<napi_property_attributes>(napi_writable | napi_configurable);
    // link definition to prototype
    Napi::Function func = DefineClass(env, "AKAZE", {
        // Methods
        StaticMethod<&AKAZEWrapper::CreateStatic>("create", atts),
        InstanceMethod<&AKAZEWrapper::getDefaultName>("getDefaultName", atts),
        InstanceMethod<&AKAZEWrapper::getDescriptorChannels>("getDescriptorChannels", atts),
        InstanceMethod<&AKAZEWrapper::getDescriptorSize>("getDescriptorSize", atts),
        InstanceMethod<&AKAZEWrapper::getDescriptorType>("getDescriptorType", atts),
        InstanceMethod<&AKAZEWrapper::getDiffusivity>("getDiffusivity", atts),
        InstanceMethod<&AKAZEWrapper::getNOctaveLayers>("getNOctaveLayers", atts),
        InstanceMethod<&AKAZEWrapper::getNOctaves>("getNOctaves", atts),
        InstanceMethod<&AKAZEWrapper::getThreshold>("getThreshold", atts),
        InstanceMethod<&AKAZEWrapper::setDescriptorChannels>("setDescriptorChannels", atts),
        InstanceMethod<&AKAZEWrapper::setDescriptorSize>("setDescriptorSize", atts),
        InstanceMethod<&AKAZEWrapper::setDescriptorType>("setDescriptorType", atts),
        InstanceMethod<&AKAZEWrapper::setDiffusivity>("setDiffusivity", atts),
        InstanceMethod<&AKAZEWrapper::setNOctaveLayers>("setNOctaveLayers", atts),
        InstanceMethod<&AKAZEWrapper::setNOctaves>("setNOctaves", atts),
        InstanceMethod<&AKAZEWrapper::setThreshold>("setThreshold", atts),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    // Add the symbol to the AKAZEWrapper prototype
    typeSymbol = Napi::Symbol::New(env, "cv.AKAZE");
    constructor.Value().Set(typeSymbol, Napi::Boolean::New(env, true));
    env.SetInstanceData<Napi::FunctionReference>(&constructor);
    exports.Set("AKAZE", func);
    return exports;
}

// Converter (AKAZE)

template<>
struct JsOpenCV_Converter< Ptr<cv::AKAZE> >
{
    static Napi::Value from(const Napi::Env &env, const Ptr<cv::AKAZE>& r)
    {
        return jsopencv_AKAZE_Instance(env, r);
    }
    static bool to(Napi::Value* src, Ptr<cv::AKAZE>& dst, const ArgInfo& info)
    {
        if(!src || src->IsNull() || src->IsUndefined())
            return true;
        Napi::Object obj = src->As<Napi::Object>();
        if (!obj.Has(AKAZEWrapper::typeSymbol)) {
            jsfailmsg(src->Env(), "Expected Ptr<cv::AKAZE> for argument '%s'", info.name);
        }
        AKAZEWrapper *wrapper = AKAZEWrapper::Unwrap(obj);
        dst = wrapper->cvdata;
        return false;
    }
};

Napi::FunctionReference AKAZEWrapper::constructor;
Napi::Symbol AKAZEWrapper::typeSymbol;
AKAZEWrapper::~AKAZEWrapper() {
    this->cvdata.release();
}

static Napi::Value jsopencv_AKAZE_Instance(const Napi::Env &env, const cv::Ptr<cv::AKAZE> &r) {
    Napi::Object newInstance = AKAZEWrapper::constructor.New({});
    AKAZEWrapper *wrapper = AKAZEWrapper::Unwrap(newInstance);
    wrapper->cvdata = r;
    return newInstance;
}

AKAZEWrapper::AKAZEWrapper(const Napi::CallbackInfo &info, const cv::Ptr<cv::AKAZE> &instance)
    : Napi::ObjectWrap<AKAZEWrapper>(info), cvdata(instance) {
}

