#include "cv_main.h"
#include "cv_mat_object.h"
#include "../cc-common/comm.h"
#include <iostream>

const std::string RED("\033[0;31m");
const std::string GREEN("\033[1;32m");
const std::string YELLOW("\033[1;33m");
const std::string CYAN("\033[0;36m");
const std::string MAGANTA("\033[0;35m");
const std::string RESET("\033[0m");

bool jsopencv_to(const Napi::Value* obj, cv::String &value, const ArgInfo& Arginfo) {
    std::cout << "jsopencv_to String start " << std::endl;
    if (obj->IsNull() || obj->IsUndefined()) {
        return true;
    }
    std::cout << "jsopencv_to String obj 2 " << std::endl;
    // std::cout << "obj is defined" << std::endl;

    if (obj->IsString()) {
        value = obj->ToString().Utf8Value();
        return true;
    }
    //  std::cout << "obj is not a string" << std::endl;
    failmsg(obj->Env(), "Argument is not convertable to string");
    return false;
}

// --- int

// template<>
bool jsopencv_to(const Napi::Value* obj, int& value, const ArgInfo& Arginfo) {
    std::cout << "jsopencv_to value start " << std::endl;
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsNumber()) {
        value = obj->ToNumber().Int32Value();
        return true;
    }
    failmsg(obj->Env(), "Argument '%s' is not convertable to int", Arginfo.name);
    return false;
}



Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Mat& m) {
    //auto sp1 = std::make_shared<cvMatObject>(info, m);
    return cvMatObject::NewInstance(info, m);
}

/**
 * @brief generated binding to read an image
 */
// static Napi::Value jsopencv_cv_imread0(const Napi::CallbackInfo &info)
// {
//     using namespace cv;
//     const Napi::Value* pyobj_filename = NULL;
//     String filename;
//     const Napi::Value* pyobj_flags = NULL;
//     int flags=IMREAD_COLOR;
//     Mat retval;
// 
//     const char* keywords[] = { "filename", "flags", NULL };
//     pyobj_filename = &info[0];
//     if (jsopencv_to(pyobj_filename, filename))
//     {
//         // std::cout << "cv::imread get called" << std::endl;
//         info, retval = cv::imread(filename, flags);
//         // std::cout << "jsopencv_from get called" << std::endl;
//         return jsopencv_from(info, retval);
//     }
// 
//     return info.Env().Null();
// }

static Napi::Value jsopencv_cv_imread(const Napi::CallbackInfo &info)
{
    using namespace cv;

    const Napi::Value* pyobj_filename = NULL;
    String filename;
    const Napi::Value* pyobj_flags = NULL;
    int flags=IMREAD_COLOR;
    Mat retval;
    std::cout << "cv::imread get called" << std::endl;
    const char* keywords[] = { "filename", "flags", NULL };

    // to DEBUG.
    std::cout << "jsopencv_cv_imread         &info[0] = " << YELLOW << &info[0] << RESET << std::endl;

    std::cout << "cv::imread pyobj_filename = " << GREEN << pyobj_filename << RESET << " start value " << std::endl;
    bool firstTest = JsArg_ParseTupleAndKeywords(info, "O|O:imread", (char**)keywords, &pyobj_filename, &pyobj_flags);
    // std::cout << "cv::imread JsArg_ParseTupleAndKeywords ret " << firstTest << std::endl;

    // std::cout << "JsArg_ParseTupleAndKeywords va arg 1 value is  = " << MAGANTA <<  &pyobj_filename << RESET << std::endl;

    std::cout << "cv::imread info[0]        = " << GREEN << &info[0] << RESET << std::endl;
    std::cout << "cv::imread pyobj_filename = " << GREEN << pyobj_filename << RESET << std::endl;
    std::cout << "cv::imread pyobj_filename is stored at " << CYAN << &pyobj_filename << RESET << std::endl;
    // pyobj_filename should be = &info[0]
    //
    // fix value by hand.
    if (pyobj_filename != &info[0]) {
        failmsg(info.Env(), "Error in code internal pyobj_filename(%p) soulbd be eq &info[0](%p)", pyobj_filename, &info[0]);
        return info.Env().Null();
    }
    //

    jsopencv_to(pyobj_filename, filename, ArgInfo("filename", 0));
    std::cout << "cv::imread pyobj_filename = " << filename << std::endl;
    std::cout << "cv::imread pyobj_flags = " << flags << std::endl;
    
    if (firstTest &&
        jsopencv_to(pyobj_filename, filename, ArgInfo("filename", 0)) &&
        jsopencv_to(pyobj_flags, flags, ArgInfo("flags", 0)))
    {
        std::cout << "cv::imread ERRWRAP2_NAPI called " << firstTest << std::endl;
        ERRWRAP2_NAPI(info, retval = cv::imread(filename, flags));
        std::cout << "cv::imread jsopencv_from called " << firstTest << std::endl;
        return jsopencv_from(info, retval);
    }

    return info.Env().Null();
}



Napi::Object cvmainInit(Napi::Env env, Napi::Object exports) {
    // std::cout << "imread is attached to export" << std::endl;
    exports.Set("imread", Napi::Function::New(env, jsopencv_cv_imread));
    return exports;
}