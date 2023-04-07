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
const std::string NEW(" (" + RED + "NEW" + RESET + ")");

bool jsopencv_to(const Napi::Value* obj, cv::String &value, const ArgInfo& Arginfo) {
    // std::cout << "jsopencv_to String start " << std::endl;
    if (!obj || obj->IsNull() || obj->IsUndefined()) {
        return true;
    }
    // std::cout << "jsopencv_to String obj 2 " << std::endl;
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
    // std::cout << "jsopencv_to value start int " << std::endl;
    if (!obj || obj->IsNull() || obj->IsUndefined())
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

/**
 * @brief 
 * 
 * @param info sizeof: 112
 * @return Napi::Value 
 */
static Napi::Value jsopencv_cv_imread(const Napi::CallbackInfo &info)
{
    using namespace cv;

    Napi::Value* jsobj_filename = NULL;
    String filename;
    Napi::Value* jsobj_flags = NULL;
    int flags=IMREAD_COLOR;
    Mat retval;

    const char* keywords[] = { "filename", "flags", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "O|O:imread", (char**)keywords, &jsobj_filename, &jsobj_flags) &&
        jsopencv_to_safe(jsobj_filename, filename, ArgInfo("filename", 0)) &&
        jsopencv_to_safe(jsobj_flags, flags, ArgInfo("flags", 0)))
    {
        ERRWRAP2_NAPI(info, retval = cv::imread(filename, flags));
        return jsopencv_from(info, retval);
    }

    return info.Env().Null();
}


// , ...
void test1b(const Napi::CallbackInfo* info, const char* format, char** keywords) {
    std::cout << "Test1 byPtr     &info is: " << MAGANTA << info << RESET << " &((*info)[0]) is: " << MAGANTA <<&((*info)[0]) << RESET << " &(info[0]) = " << MAGANTA<< &(info[0]) << RESET<< std::endl;
}

void test2b(const Napi::CallbackInfo* info, ...) {
    std::cout << "2args byPtr ... &info is: " << MAGANTA << info << RESET << " &((*info)[0]) is: " << MAGANTA << &((*info)[0]) << RESET << " &(info[0]) = " << MAGANTA<< &(info[0]) << RESET<< std::endl;
}

void test3b(const Napi::CallbackInfo* info, const char* format, char** keywords, ...) {
    std::cout << "3Args Byptr ... &info is: " << MAGANTA << info << RESET << " &((*info)[0]) is: " << MAGANTA << &((*info)[0]) << RESET << " &(info[0]) = " << MAGANTA<< &(info[0]) << RESET<< std::endl;
}

void test4b(const Napi::CallbackInfo& info, const char* format, char** keywords, ...) {
    std::cout << "Test4 byRef ... &info is: " << MAGANTA << &info << RESET << " &((*info)[0]) is: " << MAGANTA << &((info)[0]) << RESET << " &(info[0]) = " << MAGANTA<< &((&info)[0]) << RESET<< std::endl;
}

void test5b(const Napi::CallbackInfo& info, const char* format, char** keywords) {
    std::cout << "Test5 byRef     &info is: " << MAGANTA << &info << RESET << " &((*info)[0]) is: " << MAGANTA << &((info)[0]) << RESET << " &(info[0]) = " << MAGANTA<< &((&info)[0]) << RESET<< std::endl;
}

static Napi::Value test(const Napi::CallbackInfo &info)
{
    // const char* keywords[] = { "filename", "flags", NULL };
    // std::cout << "===========" << std::endl;
    // auto nfo2 = &info;
    // std::cout << "Test0 From     source is: " << MAGANTA << nfo2 << RESET << " &((*info)[0]) is: " << MAGANTA <<&((*nfo2)[0]) << RESET << " &(info[0]) = " << MAGANTA<< &(nfo2[0]) << RESET<< std::endl;
    // test1b(&info, "format",  (char**) keywords);
    // test2b(&info, "format",  (char**) keywords);
    // test3b(&info, "format",  (char**) keywords);
    // test4b(info, "format",  (char**) keywords);
    // test5b(info, "format",  (char**) keywords);
    // std::cout << "===========" << std::endl;
    return info.Env().Null();
}

Napi::Object cvmainInit(Napi::Env env, Napi::Object exports) {
    // std::cout << "imread is attached to export" << std::endl;
    exports.Set("imread", Napi::Function::New(env, jsopencv_cv_imread));
    exports.Set("test", Napi::Function::New(env, test));
    return exports;
}