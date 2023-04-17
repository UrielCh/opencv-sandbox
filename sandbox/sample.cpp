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

void jsopencv_cv_AKAZE_setThreshold(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    double threshold = info[0].As<Napi::Number>().DoubleValue();
    AKAZE *akaze = info.This().As<Napi::Object>().GetInternalField(0).As<Napi::External<AKAZE>>().Data();
    akaze->setThreshold(threshold);
}

void jsopencv_cv_AKAZE_setDescriptorSize(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int descriptorSize = info[0].As<Napi::Number>().Int32Value();
    AKAZE *akaze = info.This().As<Napi::Object>().GetInternalField(0).As<Napi::External<AKAZE>>().Data();
    akaze->setDescriptorSize(descriptorSize);
}

void jsopencv_cv_AKAZE_setDescriptorChannels(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int descriptorChannels = info[0].As<Napi::Number>().Int32Value();
    AKAZE *akaze = info.This().As<Napi::Object>().GetInternalField(0).As<Napi::External<AKAZE>>().Data();
    akaze->setDescriptorChannels(descriptorChannels);
}

void jsopencv_cv_AKAZE_setDescriptorType(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int descriptorType = info[0].As<Napi::Number>().Int32Value();
    AKAZE *akaze = info.This().As<Napi::Object>().GetInternalField(0).As<Napi::External<AKAZE>>().Data();
    akaze->setDescriptorType(descriptorType);
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);

    Napi::Function akazeConstructor = Napi::Function::New(env, [](const Napi::CallbackInfo &info)
                                                          {
        Napi::Env env = info.Env();
        AKAZE *akaze = new AKAZE();
        info.This().As<Napi::Object>().SetInternalField(0, Napi::External<AKAZE>::New(env, akaze));
        return info.This(); });

    Napi::Function setThreshold = Napi::Function::New(env, jsopencv_cv_AKAZE_setThreshold);
    Napi::Function setDescriptorSize = Napi::Function::New(env, jsopencv_cv_AKAZE_setDescriptorSize);
    Napi::Function setDescriptorChannels = Napi::Function::New(env, jsopencv_cv_AKAZE_setDescriptorChannels);
    Napi::Function setDescriptorType = Napi::Function::New(env, jsopencv_cv_AKAZE_setDescriptorType);

    Napi::Function getDefault = Napi::Function::New(env, [](const Napi::CallbackInfo &info)
                                                    {
        Napi::Env env = info.Env();
        AKAZE akaze = AKAZE::getDefault();
        Napi::Object obj = Napi::Object::New(env);
        obj.SetInternalField(0, Napi::External<AKAZE>::New(env, new AKAZE(akaze)));
        return obj; });
    akazeConstructor["getDefault"] = getDefault;
    akazeConstructor.As<Napi::Object>().DefineOwnProperty(env, Napi::String::New(env, "setThreshold"), setThreshold);
    akazeConstructor.As<Napi::Object>().DefineOwnProperty(env, Napi::String::New(env, "setDescriptorSize"), setDescriptorSize);
    akazeConstructor.As<Napi::Object>().DefineOwnProperty(env, Napi::String::New(env, "setDescriptorChannels"), setDescriptorChannels);
    akazeConstructor.As<Napi::Object>().DefineOwnProperty(env, Napi::String::New(env, "setDescriptorType"), setDescriptorType);

    exports.Set("AKAZE", akazeConstructor);

    return exports;
}