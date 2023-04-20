// #include "../sandbox/sample.cpp"
#include "./Feature2D.h"

#include "../cc-common/cv2_convert.h"
#include "../cc-common/cv2_util.h"
#include "../cc-generated/jsopencv_generated_include.h"

using namespace cv;

static Napi::Value jsopencv_Feature2D_Instance(const Napi::Env& env, const cv::Ptr<cv::Feature2D>& r) {
    Napi::Object newInstance = Feature2DWrapper::constructor.New({});
    Feature2DWrapper* wrapper = Feature2DWrapper::Unwrap(newInstance);
    wrapper->cvdata = r;
    return newInstance;
}

template <>
struct JsOpenCV_Converter<Ptr<cv::Feature2D>> {
    static Napi::Value from(const Napi::Env& env, const Ptr<cv::Feature2D>& r) {
        // std::cout << "AKAZE from JsOpenCV_Converter<Ptr<cv::AKAZE>> " << std::endl;
        return jsopencv_Feature2D_Instance(env, r);
    }
    static bool to(Napi::Value* src, Ptr<cv::Feature2D>& dst, const ArgInfo& info) {
        if (!src || src->IsNull() || src->IsUndefined())
            return true;

        Napi::Object obj = src->As<Napi::Object>();    // Convert Napi::Value to Napi::Object
        if (!obj.Has(Feature2DWrapper::typeSymbol)) {  //  || !obj.Get(AKAZEWrapper::typeSymbol).As<Napi::Boolean>().Value())
            jsfailmsg(src->Env(), "Expected Ptr<cv::AKAZE> for argument '%s'", info.name);
        }
        Feature2DWrapper* wrapper = Feature2DWrapper::Unwrap(obj);  // Unwrap the Napi::Object to get AKAZEWrapper instance
        dst = wrapper->cvdata;                                      // Access the cvdata member
        return false;
    }
};

Napi::Value Feature2DWrapper::compute(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Ptr<cv::Feature2D> _self_ = this->cvdata;

    jsPrepareArgumentConversionErrorsStorage(4);

    {
        Napi::Value* jsobj_image = NULL;
        Mat image;
        Napi::Value* jsobj_keypoints = NULL;
        vector_KeyPoint keypoints;
        Napi::Value* jsobj_descriptors = NULL;
        Mat descriptors;

        const char* keywords[] = {"image", "keypoints", "descriptors", NULL};
        if (JsArg_ParseTupleAndKeywords(info, "OO|O:Feature2D.compute", (char**)keywords, &jsobj_image, &jsobj_keypoints, &jsobj_descriptors) &&
            jsopencv_to_safe(jsobj_image, image, ArgInfo("image", 0)) &&
            jsopencv_to_safe(jsobj_keypoints, keypoints, ArgInfo("keypoints", 1)) &&
            jsopencv_to_safe(jsobj_descriptors, descriptors, ArgInfo("descriptors", 1))) {
            ERRWRAP2_NAPI(env, _self_->compute(image, keypoints, descriptors));
            return Js_BuildValue(env, "(NN)", jsopencv_from(env, keypoints), jsopencv_from(env, descriptors));
        }

        jsPopulateArgumentConversionErrors(info);
    }

    {
        Napi::Value* jsobj_image = NULL;
        UMat image;
        Napi::Value* jsobj_keypoints = NULL;
        vector_KeyPoint keypoints;
        Napi::Value* jsobj_descriptors = NULL;
        UMat descriptors;

        const char* keywords[] = {"image", "keypoints", "descriptors", NULL};
        if (JsArg_ParseTupleAndKeywords(info, "OO|O:Feature2D.compute", (char**)keywords, &jsobj_image, &jsobj_keypoints, &jsobj_descriptors) &&
            jsopencv_to_safe(jsobj_image, image, ArgInfo("image", 0)) &&
            jsopencv_to_safe(jsobj_keypoints, keypoints, ArgInfo("keypoints", 1)) &&
            jsopencv_to_safe(jsobj_descriptors, descriptors, ArgInfo("descriptors", 1))) {
            ERRWRAP2_NAPI(env, _self_->compute(image, keypoints, descriptors));
            return Js_BuildValue(env, "(NN)", jsopencv_from(env, keypoints), jsopencv_from(env, descriptors));
        }

        jsPopulateArgumentConversionErrors(info);
    }

    {
        Napi::Value* jsobj_images = NULL;
        vector_Mat images;
        Napi::Value* jsobj_keypoints = NULL;
        vector_vector_KeyPoint keypoints;
        Napi::Value* jsobj_descriptors = NULL;
        vector_Mat descriptors;

        const char* keywords[] = {"images", "keypoints", "descriptors", NULL};
        if (JsArg_ParseTupleAndKeywords(info, "OO|O:Feature2D.compute", (char**)keywords, &jsobj_images, &jsobj_keypoints, &jsobj_descriptors) &&
            jsopencv_to_safe(jsobj_images, images, ArgInfo("images", 0)) &&
            jsopencv_to_safe(jsobj_keypoints, keypoints, ArgInfo("keypoints", 1)) &&
            jsopencv_to_safe(jsobj_descriptors, descriptors, ArgInfo("descriptors", 1))) {
            ERRWRAP2_NAPI(env, _self_->compute(images, keypoints, descriptors));
            return Js_BuildValue(env, "(NN)", jsopencv_from(env, keypoints), jsopencv_from(env, descriptors));
        }

        jsPopulateArgumentConversionErrors(info);
    }

    {
        Napi::Value* jsobj_images = NULL;
        vector_UMat images;
        Napi::Value* jsobj_keypoints = NULL;
        vector_vector_KeyPoint keypoints;
        Napi::Value* jsobj_descriptors = NULL;
        vector_UMat descriptors;

        const char* keywords[] = {"images", "keypoints", "descriptors", NULL};
        if (JsArg_ParseTupleAndKeywords(info, "OO|O:Feature2D.compute", (char**)keywords, &jsobj_images, &jsobj_keypoints, &jsobj_descriptors) &&
            jsopencv_to_safe(jsobj_images, images, ArgInfo("images", 0)) &&
            jsopencv_to_safe(jsobj_keypoints, keypoints, ArgInfo("keypoints", 1)) &&
            jsopencv_to_safe(jsobj_descriptors, descriptors, ArgInfo("descriptors", 1))) {
            ERRWRAP2_NAPI(env, _self_->compute(images, keypoints, descriptors));
            return Js_BuildValue(env, "(NN)", jsopencv_from(env, keypoints), jsopencv_from(env, descriptors));
        }

        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "compute");

    return env.Null();
}
Napi::Value Feature2DWrapper::defaultNorm(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Ptr<cv::Feature2D> _self_ = this->cvdata;
    int retval;
    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty())) {
        ERRWRAP2_NAPI(env, retval = _self_->defaultNorm());
        return jsopencv_from(env, retval);
    }
    return env.Null();
}
Napi::Value Feature2DWrapper::descriptorSize(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Ptr<cv::Feature2D> _self_ = this->cvdata;
    int retval;
    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty())) {
        ERRWRAP2_NAPI(env, retval = _self_->descriptorSize());
        return jsopencv_from(env, retval);
    }
    return env.Null();
}
Napi::Value Feature2DWrapper::descriptorType(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Ptr<cv::Feature2D> _self_ = this->cvdata;
    int retval;
    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty())) {
        ERRWRAP2_NAPI(env, retval = _self_->descriptorType());
        return jsopencv_from(env, retval);
    }
    return env.Null();
}
Napi::Value Feature2DWrapper::detect(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Ptr<cv::Feature2D> _self_ = this->cvdata;
    jsPrepareArgumentConversionErrorsStorage(4);

    {
        Napi::Value* jsobj_image = NULL;
        Mat image;
        vector_KeyPoint keypoints;
        Napi::Value* jsobj_mask = NULL;
        Mat mask;
        const char* keywords[] = {"image", "mask", NULL};
        if (JsArg_ParseTupleAndKeywords(info, "O|O:Feature2D.detect", (char**)keywords, &jsobj_image, &jsobj_mask) &&
            jsopencv_to_safe(jsobj_image, image, ArgInfo("image", 0)) &&
            jsopencv_to_safe(jsobj_mask, mask, ArgInfo("mask", 0))) {
            ERRWRAP2_NAPI(env, _self_->detect(image, keypoints, mask));
            return jsopencv_from(env, keypoints);
        }
        jsPopulateArgumentConversionErrors(info);
    }
    {
        Napi::Value* jsobj_image = NULL;
        UMat image;
        vector_KeyPoint keypoints;
        Napi::Value* jsobj_mask = NULL;
        UMat mask;
        const char* keywords[] = {"image", "mask", NULL};
        if (JsArg_ParseTupleAndKeywords(info, "O|O:Feature2D.detect", (char**)keywords, &jsobj_image, &jsobj_mask) &&
            jsopencv_to_safe(jsobj_image, image, ArgInfo("image", 0)) &&
            jsopencv_to_safe(jsobj_mask, mask, ArgInfo("mask", 0))) {
            ERRWRAP2_NAPI(env, _self_->detect(image, keypoints, mask));
            return jsopencv_from(env, keypoints);
        }
        jsPopulateArgumentConversionErrors(info);
    }

    {
        Napi::Value* jsobj_images = NULL;
        vector_Mat images;
        vector_vector_KeyPoint keypoints;
        Napi::Value* jsobj_masks = NULL;
        vector_Mat masks;
        const char* keywords[] = {"images", "masks", NULL};
        if (JsArg_ParseTupleAndKeywords(info, "O|O:Feature2D.detect", (char**)keywords, &jsobj_images, &jsobj_masks) &&
            jsopencv_to_safe(jsobj_images, images, ArgInfo("images", 0)) &&
            jsopencv_to_safe(jsobj_masks, masks, ArgInfo("masks", 0))) {
            ERRWRAP2_NAPI(env, _self_->detect(images, keypoints, masks));
            return jsopencv_from(env, keypoints);
        }
        jsPopulateArgumentConversionErrors(info);
    }

    {
        Napi::Value* jsobj_images = NULL;
        vector_UMat images;
        vector_vector_KeyPoint keypoints;
        Napi::Value* jsobj_masks = NULL;
        vector_UMat masks;
        const char* keywords[] = {"images", "masks", NULL};
        if (JsArg_ParseTupleAndKeywords(info, "O|O:Feature2D.detect", (char**)keywords, &jsobj_images, &jsobj_masks) &&
            jsopencv_to_safe(jsobj_images, images, ArgInfo("images", 0)) &&
            jsopencv_to_safe(jsobj_masks, masks, ArgInfo("masks", 0))) {
            ERRWRAP2_NAPI(env, _self_->detect(images, keypoints, masks));
            return jsopencv_from(env, keypoints);
        }
        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "detect");
    return env.Null();
}

Napi::Value Feature2DWrapper::detectAndCompute(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Ptr<cv::Feature2D> _self_ = this->cvdata;
    jsPrepareArgumentConversionErrorsStorage(2);

    {
        Napi::Value* jsobj_image = NULL;
        Mat image;
        Napi::Value* jsobj_mask = NULL;
        Mat mask;
        vector_KeyPoint keypoints;
        Napi::Value* jsobj_descriptors = NULL;
        Mat descriptors;
        Napi::Value* jsobj_useProvidedKeypoints = NULL;
        bool useProvidedKeypoints = false;

        const char* keywords[] = {"image", "mask", "descriptors", "useProvidedKeypoints", NULL};
        if (JsArg_ParseTupleAndKeywords(info, "OO|OO:Feature2D.detectAndCompute", (char**)keywords, &jsobj_image, &jsobj_mask, &jsobj_descriptors, &jsobj_useProvidedKeypoints) &&
            jsopencv_to_safe(jsobj_image, image, ArgInfo("image", 0)) &&
            jsopencv_to_safe(jsobj_mask, mask, ArgInfo("mask", 0)) &&
            jsopencv_to_safe(jsobj_descriptors, descriptors, ArgInfo("descriptors", 1)) &&
            jsopencv_to_safe(jsobj_useProvidedKeypoints, useProvidedKeypoints, ArgInfo("useProvidedKeypoints", 0))) {
            ERRWRAP2_NAPI(env, _self_->detectAndCompute(image, mask, keypoints, descriptors, useProvidedKeypoints));
            return Js_BuildValue(env, "(NN)", jsopencv_from(env, keypoints), jsopencv_from(env, descriptors));
        }
        jsPopulateArgumentConversionErrors(info);
    }
    {
        Napi::Value* jsobj_image = NULL;
        UMat image;
        Napi::Value* jsobj_mask = NULL;
        UMat mask;
        vector_KeyPoint keypoints;
        Napi::Value* jsobj_descriptors = NULL;
        UMat descriptors;
        Napi::Value* jsobj_useProvidedKeypoints = NULL;
        bool useProvidedKeypoints = false;
        const char* keywords[] = {"image", "mask", "descriptors", "useProvidedKeypoints", NULL};
        if (JsArg_ParseTupleAndKeywords(info, "OO|OO:Feature2D.detectAndCompute", (char**)keywords, &jsobj_image, &jsobj_mask, &jsobj_descriptors, &jsobj_useProvidedKeypoints) &&
            jsopencv_to_safe(jsobj_image, image, ArgInfo("image", 0)) &&
            jsopencv_to_safe(jsobj_mask, mask, ArgInfo("mask", 0)) &&
            jsopencv_to_safe(jsobj_descriptors, descriptors, ArgInfo("descriptors", 1)) &&
            jsopencv_to_safe(jsobj_useProvidedKeypoints, useProvidedKeypoints, ArgInfo("useProvidedKeypoints", 0))) {
            ERRWRAP2_NAPI(env, _self_->detectAndCompute(image, mask, keypoints, descriptors, useProvidedKeypoints));
            return Js_BuildValue(env, "(NN)", jsopencv_from(env, keypoints), jsopencv_from(env, descriptors));
        }
        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "detectAndCompute");
    return env.Null();
}

Napi::Value Feature2DWrapper::empty(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Ptr<cv::Feature2D> _self_ = this->cvdata;
    bool retval;
    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty())) {
        ERRWRAP2_NAPI(env, retval = _self_->empty());
        return jsopencv_from(env, retval);
    }
    return env.Null();
}
Napi::Value Feature2DWrapper::getDefaultName(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Ptr<cv::Feature2D> _self_ = this->cvdata;
    String retval;
    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty())) {
        ERRWRAP2_NAPI(env, retval = _self_->getDefaultName());
        return jsopencv_from(env, retval);
    }
    return env.Null();
}

Napi::Value Feature2DWrapper::read(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Ptr<cv::Feature2D> _self_ = this->cvdata;
    jsPrepareArgumentConversionErrorsStorage(2);

    {
        Napi::Value* jsobj_fileName = NULL;
        String fileName;

        const char* keywords[] = {"fileName", NULL};
        if (JsArg_ParseTupleAndKeywords(info, "O:Feature2D.read", (char**)keywords, &jsobj_fileName) &&
            jsopencv_to_safe(jsobj_fileName, fileName, ArgInfo("fileName", 0))) {
            ERRWRAP2_NAPI(env, _self_->read(fileName));
            return env.Null();
            ;
        }
        jsPopulateArgumentConversionErrors(info);
    }

    {
        Napi::Value* jsobj_arg1 = NULL;
        cv::FileNode arg1;

        const char* keywords[] = {"arg1", NULL};
        if (JsArg_ParseTupleAndKeywords(info, "O:Feature2D.read", (char**)keywords, &jsobj_arg1) &&
            jsopencv_to_safe(jsobj_arg1, arg1, ArgInfo("arg1", 0))) {
            ERRWRAP2_NAPI(env, _self_->read(arg1));
            return env.Null();
            ;
        }

        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "read");
    return env.Null();
}

Napi::Value Feature2DWrapper::write(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Ptr<cv::Feature2D> _self_ = this->cvdata;
    jsPrepareArgumentConversionErrorsStorage(2);

    {
        Napi::Value* jsobj_fileName = NULL;
        String fileName;
        const char* keywords[] = {"fileName", NULL};
        if (JsArg_ParseTupleAndKeywords(info, "O:Feature2D.write", (char**)keywords, &jsobj_fileName) &&
            jsopencv_to_safe(jsobj_fileName, fileName, ArgInfo("fileName", 0))) {
            ERRWRAP2_NAPI(env, _self_->write(fileName));
            return env.Null();
            ;
        }
        jsPopulateArgumentConversionErrors(info);
    }
    {
        Napi::Value* jsobj_fs = NULL;
        Ptr<cv::FileStorage> fs;
        Napi::Value* jsobj_name = NULL;
        String name;
        const char* keywords[] = {"fs", "name", NULL};
        if (JsArg_ParseTupleAndKeywords(info, "OO:Feature2D.write", (char**)keywords, &jsobj_fs, &jsobj_name) &&
            jsopencv_to_safe(jsobj_fs, fs, ArgInfo("fs", 0)) &&
            jsopencv_to_safe(jsobj_name, name, ArgInfo("name", 0))) {
            ERRWRAP2_NAPI(env, _self_->write(*fs, name));
            return env.Null();
            ;
        }
        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "write");
    return env.Null();
}

// Static methods
// Napi::Value Feature2DWrapper::CreateStatic(const Napi::CallbackInfo& info) {
//     Napi::FunctionReference* constructor = info.Env().GetInstanceData<Napi::FunctionReference>();
//     return constructor->New(CallbackInfoToVector(info));
// }

Napi::FunctionReference Feature2DWrapper::constructor;

Napi::Object Feature2DWrapper::Init(Napi::Env env, Napi::Object exports) {
    Napi::HandleScope scope(env);
    typeSymbol = Napi::Symbol::New(env, "cv2.Feature2D");  // or "AKAZEWrapperInstance" m can be use for class debugging
    napi_property_attributes atts = static_cast<napi_property_attributes>(napi_writable | napi_configurable);
    Napi::Function func = DefineClass(env, "Feature2D", {
                                                                InstanceMethod<&Feature2DWrapper::compute>("compute", atts),
                                                                InstanceMethod<&Feature2DWrapper::defaultNorm>("defaultNorm", atts),
                                                                InstanceMethod<&Feature2DWrapper::descriptorSize>("descriptorSize", atts),
                                                                InstanceMethod<&Feature2DWrapper::descriptorType>("descriptorType", atts),
                                                                InstanceMethod<&Feature2DWrapper::detect>("detect", atts),
                                                                InstanceMethod<&Feature2DWrapper::detectAndCompute>("detectAndCompute", atts),
                                                                InstanceMethod<&Feature2DWrapper::empty>("empty", atts),
                                                                InstanceMethod<&Feature2DWrapper::getDefaultName>("getDefaultName", atts),
                                                                InstanceMethod<&Feature2DWrapper::read>("read", atts),
                                                                InstanceMethod<&Feature2DWrapper::write>("write", atts),
                                                                // StaticMethod<&Feature2DWrapper::CreateStatic>("create", atts),
                                                            });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    // Add the symbol to the AKAZEWrapper prototype
    constructor.Value().Set(typeSymbol, Napi::Boolean::New(env, true));

    env.SetInstanceData<Napi::FunctionReference>(&constructor);
    exports.Set("Feature2D", func);
    return exports;
}

Feature2DWrapper::~Feature2DWrapper() {
    this->cvdata.release();
}

Napi::Symbol Feature2DWrapper::typeSymbol;

// constructor
Feature2DWrapper::Feature2DWrapper(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<Feature2DWrapper>(info) {
    Napi::Env env = info.Env();

    Napi::Value* jsobj_backend = NULL;
    Ptr<Feature2D> backend;
    Napi::Value* jsobj_maxTilt = NULL;
    int maxTilt = 5;
    Napi::Value* jsobj_minTilt = NULL;
    int minTilt = 0;
    Napi::Value* jsobj_tiltStep = NULL;
    float tiltStep = 1.4142135623730951f;
    Napi::Value* jsobj_rotateStepBase = NULL;
    float rotateStepBase = 72;
    Ptr<AffineFeature> retval;

    const char* keywords[] = {"backend", "maxTilt", "minTilt", "tiltStep", "rotateStepBase", NULL};
    if (JsArg_ParseTupleAndKeywords(info, "O|OOOO:AffineFeature.create", (char**)keywords, &jsobj_backend, &jsobj_maxTilt, &jsobj_minTilt, &jsobj_tiltStep, &jsobj_rotateStepBase) &&
        jsopencv_to_safe(jsobj_backend, backend, ArgInfo("backend", 0)) &&
        jsopencv_to_safe(jsobj_maxTilt, maxTilt, ArgInfo("maxTilt", 0)) &&
        jsopencv_to_safe(jsobj_minTilt, minTilt, ArgInfo("minTilt", 0)) &&
        jsopencv_to_safe(jsobj_tiltStep, tiltStep, ArgInfo("tiltStep", 0)) &&
        jsopencv_to_safe(jsobj_rotateStepBase, rotateStepBase, ArgInfo("rotateStepBase", 0))) {
        ERRWRAP2_NAPI_VOID(env, retval = cv::AffineFeature::create(backend, maxTilt, minTilt, tiltStep, rotateStepBase));
        this->cvdata = retval;
    }
}
