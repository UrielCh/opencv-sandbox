#include <napi.h>
#include "../cc-generated/jsopencv_generated_include.h"

class AKAZE
{
public:
    AKAZE() = default;
    ~AKAZE() = default;

    void setThreshold(double threshold) {}
    void setDescriptorSize(int descriptorSize) {}
    void setDescriptorChannels(int descriptorChannels) {}
    void setDescriptorType(int descriptorType) {}

    static AKAZE getDefault()
    {
        AKAZE akaze;
        return akaze;
    }
};

Napi::Symbol AKAZE_KEY;

void jsopencv_cv_AKAZE_setThreshold(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    double threshold = info[0].As<Napi::Number>().DoubleValue();
    AKAZE *akaze = info.This().As<Napi::Object>().Get(AKAZE_KEY).As<Napi::External<AKAZE>>().Data();
    akaze->setThreshold(threshold);
}

void jsopencv_cv_AKAZE_setDescriptorSize(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int descriptorSize = info[0].As<Napi::Number>().Int32Value();
    AKAZE *akaze = info.This().As<Napi::Object>().Get(AKAZE_KEY).As<Napi::External<AKAZE>>().Data();
    akaze->setDescriptorSize(descriptorSize);
}

void jsopencv_cv_AKAZE_setDescriptorChannels(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int descriptorChannels = info[0].As<Napi::Number>().Int32Value();
    AKAZE *akaze = info.This().As<Napi::Object>().Get(AKAZE_KEY).As<Napi::External<AKAZE>>().Data();
    akaze->setDescriptorChannels(descriptorChannels);
}

void jsopencv_cv_AKAZE_setDescriptorType(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int descriptorType = info[0].As<Napi::Number>().Int32Value();
    AKAZE *akaze = info.This().As<Napi::Object>().Get(AKAZE_KEY).As<Napi::External<AKAZE>>().Data();
    akaze->setDescriptorType(descriptorType);
}

Napi::Object AKAZE_getDefault(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    AKAZE akaze = AKAZE::getDefault();
    Napi::Object obj = Napi::Object::New(env);
    obj.Set(AKAZE_KEY, Napi::External<AKAZE>::New(env, new AKAZE(akaze)));
    return obj;
}

Napi::Value AKAZE_constructor(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    AKAZE *akaze = new AKAZE();
    info.This().As<Napi::Object>().Set(AKAZE_KEY, Napi::External<AKAZE>::New(env, akaze));
    return info.This();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    Napi::HandleScope scope(env);
    AKAZE_KEY = Napi::Symbol::New(env);
    Napi::Function akazeConstructor = Napi::Function::New(env, AKAZE_constructor);
    Napi::Function setThreshold = Napi::Function::New(env, jsopencv_cv_AKAZE_setThreshold);
    Napi::Function setDescriptorSize = Napi::Function::New(env, jsopencv_cv_AKAZE_setDescriptorSize);
    Napi::Function setDescriptorChannels = Napi::Function::New(env, jsopencv_cv_AKAZE_setDescriptorChannels);
    Napi::Function setDescriptorType = Napi::Function::New(env, jsopencv_cv_AKAZE_setDescriptorType);
    akazeConstructor["getDefault"] = Napi::Function::New(env, AKAZE_getDefault);
    akazeConstructor.As<Napi::Object>().DefineProperties({
        Napi::PropertyDescriptor::Function(env, akazeConstructor, "setThreshold", setThreshold),
        Napi::PropertyDescriptor::Function(env, akazeConstructor, "setDescriptorSize", setDescriptorSize),
        Napi::PropertyDescriptor::Function(env, akazeConstructor, "setDescriptorChannels", setDescriptorChannels),
        Napi::PropertyDescriptor::Function(env, akazeConstructor, "setDescriptorType", setDescriptorType)
    });
    exports.Set("AKAZE", akazeConstructor);
    return exports;
}