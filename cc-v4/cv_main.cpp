#include "cv_main.h"
#include "cv_mat_object.h"
#include "../cc-common/comm.h"
// #include <iostream>

bool jsopencv_to(const Napi::Value* obj, cv::String &value) {
    if (obj->IsNull() || obj->IsUndefined()) {
        return true;
    }
    // std::cout << "obj is defined" << std::endl;

    if (obj->IsString()) {
        value = obj->ToString().Utf8Value();
        return true;
    }
    //  std::cout << "obj is not a string" << std::endl;

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
static Napi::Value jsopencv_cv_imread0(const Napi::CallbackInfo &info)
{
    using namespace cv;
    const Napi::Value* pyobj_filename = NULL;
    String filename;
    const Napi::Value* pyobj_flags = NULL;
    int flags=IMREAD_COLOR;
    Mat retval;

    const char* keywords[] = { "filename", "flags", NULL };
    pyobj_filename = &info[0];
    if (jsopencv_to(pyobj_filename, filename))
    {
        // std::cout << "cv::imread get called" << std::endl;
        info, retval = cv::imread(filename, flags);
        // std::cout << "jsopencv_from get called" << std::endl;
        return jsopencv_from(info, retval);
    }

    return info.Env().Null();
}

static Napi::Value jsopencv_cv_imread(const Napi::CallbackInfo &info)
{
    using namespace cv;

    Napi::Value* pyobj_filename = NULL;
    String filename;
    Napi::Value* pyobj_flags = NULL;
    int flags=IMREAD_COLOR;
    Mat retval;

    const char* keywords[] = { "filename", "flags", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "O|O:imread", (char**)keywords, &pyobj_filename, &pyobj_flags) &&
        jsopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 0)) &&
        jsopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)))
    {
        ERRWRAP2_NAPI(info, retval = cv::imread(filename, flags));
        return jsopencv_from(info, retval);
    }

    return info.Env().Null();
}



Napi::Object cvmainInit(Napi::Env env, Napi::Object exports) {
    // std::cout << "imread is attached to export" << std::endl;
    exports.Set("imread", Napi::Function::New(env, jsopencv_cv_imread));
    return exports;
}