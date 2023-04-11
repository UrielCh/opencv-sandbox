#include "cv_main.h"
#include "cv_mat_object.h"
#include "../cc-common/cv2_convert.h"
#include "../cc-common/js_as_py.h"
#include "../cc-common/js_as_py_test.h"
#include <iostream>

// #define NEXRT_BUILD 1

const std::string RED("\033[0;31m");
const std::string GREEN("\033[1;32m");
const std::string YELLOW("\033[1;33m");
const std::string CYAN("\033[0;36m");
const std::string MAGANTA("\033[0;35m");
const std::string RESET("\033[0m");
const std::string NEW(" (" + RED + "NEW" + RESET + ")");

Napi::Value jsopencv_fromVec(const Napi::CallbackInfo &info, const std::vector<uchar>& src) {
    Napi::Env env = info.Env();
    size_t size = src.size();
    Napi::Buffer<uchar> buffer = Napi::Buffer<uchar>::New(env, size);

    std::copy(src.begin(), src.end(), buffer.Data());

    return buffer;
}


static Napi::Value jsopencv_cv_imencode(const Napi::CallbackInfo &info)
{
    using namespace cv;
    // std::cout << "jsopencv_cv_imencode Called with " << MAGANTA << info.Length() << RESET << " params" << std::endl;

    jsPrepareArgumentConversionErrorsStorage(2);
    // std::cout << "jsPrepareArgumentConversionErrorsStorage Called" << std::endl;
    Napi::Value *jsobj_ext = NULL;
    String ext;
    Napi::Value *jsobj_img = NULL;
    Mat img;
    vector_uchar buf;
    Napi::Value *jsobj_params = NULL;
    vector_int params = std::vector<int>();
    bool retval;
    const char *keywords[] = {"ext", "img", "params", NULL};
    if (JsArg_ParseTupleAndKeywords(info, "OO|O:imencode", (char **)keywords, &jsobj_ext, &jsobj_img, &jsobj_params)
        && jsopencv_to_safe(jsobj_ext, ext, ArgInfo("ext", 0))
        && jsopencv_to_safe(jsobj_img, img, ArgInfo("img", 0))
        && jsopencv_to_safe(jsobj_params, params, ArgInfo("params", 0))
    ) {
        ERRWRAP2_NAPI(info, retval = cv::imencode(ext, img, buf, params));
        return Js_BuildValue(info, "(NN)", jsopencv_from(info, retval), jsopencv_fromVec(info, buf));
    }
    jsRaiseCVOverloadException(info, "imencode");

    return info.Env().Null();
}


static Napi::Value jsopencv_cv_getVersionMajor(const Napi::CallbackInfo &info)
{
    using namespace cv;

    int retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(info, retval = cv::getVersionMajor());
        return jsopencv_from(info, retval);
    }

    return info.Env().Null();
}

static Napi::Value jsopencv_cv_getVersionMinor(const Napi::CallbackInfo &info)
{
    using namespace cv;

    int retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(info, retval = cv::getVersionMinor());
        return jsopencv_from(info, retval);
    }

    return info.Env().Null();
}

static Napi::Value jsopencv_cv_getVersionRevision(const Napi::CallbackInfo &info)
{
    using namespace cv;

    int retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(info, retval = cv::getVersionRevision());
        return jsopencv_from(info, retval);
    }

    return info.Env().Null();
}


/**
 * @brief
 *
 * @param info sizeof: 112
 * @return Napi::Value
 */
static Napi::Value jsopencv_cv_imread(const Napi::CallbackInfo &info)
{
    using namespace cv;

    Napi::Value *jsobj_filename = NULL;
    String filename;
    Napi::Value *jsobj_flags = NULL;
    int flags = IMREAD_COLOR;
    Mat retval;

    const char *keywords[] = {"filename", "flags", NULL};
    if (JsArg_ParseTupleAndKeywords(info, "O|O:imread", (char **)keywords, &jsobj_filename, &jsobj_flags) &&
        jsopencv_to_safe(jsobj_filename, filename, ArgInfo("filename", 0)) &&
        jsopencv_to_safe(jsobj_flags, flags, ArgInfo("flags", 0)))
    {
        ERRWRAP2_NAPI(info, retval = cv::imread(filename, flags));
        return jsopencv_from(info, retval);
    }

    return info.Env().Null();
}

static Napi::Value test(const Napi::CallbackInfo &info)
{
    int pass = 0;
    int fail = 0;
    try
    {
        Js_BuildValue_test(info);
        JsArg_ParseTupleAndKeywords_test(info);
        // std::cout << "ALL tests done" << std::endl;
    }
    catch (const std::exception &ex)
    {
        failmsg(info.Env(), "A Test Throws un non catched Exception: %s", ex.what());
    }
    Napi::Object obj = Napi::Object::New(info.Env());
    obj.Set("pass", Napi::Number::New(info.Env(), pass));
    obj.Set("fail", Napi::Number::New(info.Env(), fail));
    return obj;
}

Napi::Object cvmainInit(Napi::Env env, Napi::Object exports)
{
    // std::cout << "imread is attached to export" << std::endl;
    exports.Set("imread", Napi::Function::New(env, jsopencv_cv_imread));
    exports.Set("imencode", Napi::Function::New(env, jsopencv_cv_imencode));
    exports.Set("test", Napi::Function::New(env, test));

    exports.Set("getVersionMajor", Napi::Function::New(env, jsopencv_cv_getVersionMajor));
    exports.Set("getVersionMinor", Napi::Function::New(env, jsopencv_cv_getVersionMinor));
    exports.Set("getVersionRevision", Napi::Function::New(env, jsopencv_cv_getVersionRevision));

    return exports;
}
