#include "cv_main.h"
#include "cv_mat_object.h"
#include <iostream>

bool jsopencv_to(const Napi::Value* obj, cv::String &value) {
    if (obj->IsNull() || obj->IsUndefined()) {
        return true;
    }
    std::cout << "obj is defined" << std::endl;

    if (obj->IsString()) {
        value = obj->ToString().Utf8Value();
        return true;
    }
    std::cout << "obj is not a string" << std::endl;

    // failmsg(obj->Env(), "Argument is not convertable to string");
    return false;
}


Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Mat& m) {
    //auto sp1 = std::make_shared<cvMatObject>(info, m);
    return cvMatObject::NewInstance(info, m);
}

/**
 * @brief generated binding to read an image
 */
static Napi::Value jsopencv_cv_imread(const Napi::CallbackInfo &info)
{
    using namespace cv;

    std::cout << "jsopencv_cv_imread get called" << std::endl;

    const Napi::Value* pyobj_filename = NULL;
    String filename;
    const Napi::Value* pyobj_flags = NULL;
    int flags=IMREAD_COLOR;
    Mat retval;

    std::cout << "jsopencv_to" << std::endl;
    const char* keywords[] = { "filename", "flags", NULL };
    pyobj_filename = &info[0];
    if (jsopencv_to(pyobj_filename, filename))
    {
        std::cout << "cv::imread get called" << std::endl;
        info, retval = cv::imread(filename, flags);
        std::cout << "jsopencv_from get called" << std::endl;
        return jsopencv_from(info, retval);
    }

    return info.Env().Null();
}

Napi::Object cvmainInit(Napi::Env env, Napi::Object exports) {
    std::cout << "imread is attached to export" << std::endl;
    exports.Set("imread", Napi::Function::New(env, jsopencv_cv_imread));
    return exports;
}