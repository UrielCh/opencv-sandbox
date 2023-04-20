// #include "../sandbox/sample.cpp"
#include "./AffineFeature.h"
#include "../cc-common/cv2_convert.h"
#include "../cc-common/cv2_util.h"
#include "../cc-generated/jsopencv_generated_include.h"

#include "./Feature2D.h"

using namespace cv;

static Napi::Value jsopencv_AffineFeature_Instance(const Napi::Env &env, const cv::Ptr<cv::AffineFeature> &r) {
    Napi::Object newInstance = AffineFeatureWrapper::constructor.New({});
    AffineFeatureWrapper *wrapper = AffineFeatureWrapper::Unwrap(newInstance);
    wrapper->cvdata = r;
    return newInstance;
}

template <>
struct JsOpenCV_Converter<Ptr<cv::AffineFeature>> {
    static Napi::Value from(const Napi::Env &env, const Ptr<cv::AffineFeature> &r) {
        // std::cout << "AKAZE from JsOpenCV_Converter<Ptr<cv::AKAZE>> " << std::endl;
        return jsopencv_AffineFeature_Instance(env, r);
    }
    static bool to(Napi::Value *src, Ptr<cv::AffineFeature> &dst, const ArgInfo &info) {
        if (!src || src->IsNull() || src->IsUndefined())
            return true;

        Napi::Object obj = src->As<Napi::Object>();       // Convert Napi::Value to Napi::Object
        if (!obj.Has(AffineFeatureWrapper::typeSymbol)) {  //  || !obj.Get(AKAZEWrapper::typeSymbol).As<Napi::Boolean>().Value())
            jsfailmsg(src->Env(), "Expected Ptr<cv::AKAZE> for argument '%s'", info.name);
        }
        AffineFeatureWrapper *wrapper = AffineFeatureWrapper::Unwrap(obj);  // Unwrap the Napi::Object to get AKAZEWrapper instance
        dst = wrapper->cvdata;                              // Access the cvdata member
        return false;
    }
};


Napi::Value AffineFeatureWrapper::getDefaultName(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AffineFeature> _self_ = this->cvdata;

       String retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = _self_->getDefaultName());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

Napi::Value AffineFeatureWrapper::getViewParams(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AffineFeature> _self_ = this->cvdata;
    Napi::Value* jsobj_tilts = NULL;
    vector_float tilts;
    Napi::Value* jsobj_rolls = NULL;
    vector_float rolls;

    const char* keywords[] = { "tilts", "rolls", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OO:AffineFeature.getViewParams", (char**)keywords, &jsobj_tilts, &jsobj_rolls) &&
        jsopencv_to_safe(jsobj_tilts, tilts, ArgInfo("tilts", 0)) &&
        jsopencv_to_safe(jsobj_rolls, rolls, ArgInfo("rolls", 0)))
    {
        ERRWRAP2_NAPI(env, _self_->getViewParams(tilts, rolls));
        return env.Null();
    }

    return env.Null();


}
Napi::Value AffineFeatureWrapper::setViewParams(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AffineFeature> _self_ = this->cvdata;

    Napi::Value* jsobj_tilts = NULL;
    vector_float tilts;
    Napi::Value* jsobj_rolls = NULL;
    vector_float rolls;

    const char* keywords[] = { "tilts", "rolls", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OO:AffineFeature.setViewParams", (char**)keywords, &jsobj_tilts, &jsobj_rolls) &&
        jsopencv_to_safe(jsobj_tilts, tilts, ArgInfo("tilts", 0)) &&
        jsopencv_to_safe(jsobj_rolls, rolls, ArgInfo("rolls", 0)))
    {
        ERRWRAP2_NAPI(env, _self_->setViewParams(tilts, rolls));
        return env.Null();
    }

    return env.Null();

}

// Static methods
Napi::Value AffineFeatureWrapper::CreateStatic(const Napi::CallbackInfo &info) {
    Napi::FunctionReference *constructor = info.Env().GetInstanceData<Napi::FunctionReference>();
    return constructor->New(CallbackInfoToVector(info));
}

Napi::FunctionReference AffineFeatureWrapper::constructor;


Napi::Object AffineFeatureWrapper::Init(Napi::Env env, Napi::Object exports) {
    Napi::HandleScope scope(env);
    typeSymbol = Napi::Symbol::New(env, "cv2.AffineFeature"); // or "AKAZEWrapperInstance" m can be use for class debugging
    napi_property_attributes atts = static_cast<napi_property_attributes>(napi_writable | napi_configurable);
    Napi::Function func = DefineClass(env, "AffineFeature", {
                                                        InstanceMethod<&AffineFeatureWrapper::getDefaultName>("getDefaultName", atts),
                                                        InstanceMethod<&AffineFeatureWrapper::getViewParams>("getViewParams", atts),
                                                        InstanceMethod<&AffineFeatureWrapper::setViewParams>("setViewParams", atts),
                                                        StaticMethod<&AffineFeatureWrapper::CreateStatic>("create", atts),
                                                    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    // Add the symbol to the AKAZEWrapper prototype
    constructor.Value().Set(typeSymbol, Napi::Boolean::New(env, true));

    env.SetInstanceData<Napi::FunctionReference>(&constructor);
    exports.Set("AKAZE", func);
    return exports;
}

AffineFeatureWrapper::~AffineFeatureWrapper() {
    this->cvdata.release();
}

Napi::Symbol AffineFeatureWrapper::typeSymbol;

// constructor
AffineFeatureWrapper::AffineFeatureWrapper(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<AffineFeatureWrapper>(info) {
    Napi::Env env = info.Env();


    Napi::Value* jsobj_backend = NULL;
    Ptr<Feature2D> backend;
    Napi::Value* jsobj_maxTilt = NULL;
    int maxTilt=5;
    Napi::Value* jsobj_minTilt = NULL;
    int minTilt=0;
    Napi::Value* jsobj_tiltStep = NULL;
    float tiltStep=1.4142135623730951f;
    Napi::Value* jsobj_rotateStepBase = NULL;
    float rotateStepBase=72;
    Ptr<AffineFeature> retval;

    const char* keywords[] = { "backend", "maxTilt", "minTilt", "tiltStep", "rotateStepBase", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "O|OOOO:AffineFeature.create", (char**)keywords, &jsobj_backend, &jsobj_maxTilt, &jsobj_minTilt, &jsobj_tiltStep, &jsobj_rotateStepBase) &&
        jsopencv_to_safe(jsobj_backend, backend, ArgInfo("backend", 0)) &&
        jsopencv_to_safe(jsobj_maxTilt, maxTilt, ArgInfo("maxTilt", 0)) &&
        jsopencv_to_safe(jsobj_minTilt, minTilt, ArgInfo("minTilt", 0)) &&
        jsopencv_to_safe(jsobj_tiltStep, tiltStep, ArgInfo("tiltStep", 0)) &&
        jsopencv_to_safe(jsobj_rotateStepBase, rotateStepBase, ArgInfo("rotateStepBase", 0)))
    {
        ERRWRAP2_NAPI_VOID(env, retval = cv::AffineFeature::create(backend, maxTilt, minTilt, tiltStep, rotateStepBase));
        this->cvdata = retval;
    }
}
