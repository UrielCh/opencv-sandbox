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

bool jsopencv_to(const Napi::Value *obj, cv::String &value, const ArgInfo &Arginfo)
{
    // std::cout << "jsopencv_to String start " << std::endl;
    if (!obj || obj->IsNull() || obj->IsUndefined())
    {
        return true;
    }
    // std::cout << "jsopencv_to String obj 2 " << std::endl;
    // std::cout << "obj is defined" << std::endl;

    if (obj->IsString())
    {
        value = obj->ToString().Utf8Value();
        return true;
    }
    //  std::cout << "obj is not a string" << std::endl;
    failmsg(obj->Env(), "Argument is not convertable to string");
    return false;
}

// --- int

// template<>
bool jsopencv_to(const Napi::Value *obj, int &value, const ArgInfo &Arginfo)
{
    // std::cout << "jsopencv_to value start int " << std::endl;
    if (!obj || obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsNumber())
    {
        value = obj->ToNumber().Int32Value();
        return true;
    }
    failmsg(obj->Env(), "Argument '%s' is not convertable to int", Arginfo.name);
    return false;
}

Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Mat &m)
{
    // auto sp1 = std::make_shared<cvMatObject>(info, m);
    return cvMatObject::NewInstance(info, m);
}
#ifdef NEXRT_BUILD
static Napi::Value jsopencv_cv_imencode(const Napi::CallbackInfo &info)
{
    using namespace cv;
    std::cout << "jsopencv_cv_imencode Called with " << MAGANTA << info.Length() << RESET << " params" << std::endl;

    jsPrepareArgumentConversionErrorsStorage(2);
    std::cout << "jsPrepareArgumentConversionErrorsStorage Called" << std::endl;

    {
        Napi::Value *jsobj_ext = NULL;
        String ext;
        Napi::Value *jsobj_img = NULL;
        Mat img;
        vector_uchar buf;
        Napi::Value *jsobj_params = NULL;
        vector_int params = std::vector<int>();
        bool retval;

        const char *keywords[] = {"ext", "img", "params", NULL};
        std::cout << "JsArg_ParseTupleAndKeywords OO|O:imencode Once" << std::endl;
        if (JsArg_ParseTupleAndKeywords(info, "OO|O:imencode", (char **)keywords, &jsobj_ext, &jsobj_img, &jsobj_params) &&
            jsopencv_to_safe(jsobj_ext, ext, ArgInfo("ext", 0)) &&
            jsopencv_to_safe(jsobj_img, img, ArgInfo("img", 0)) &&
            jsopencv_to_safe(jsobj_params, params, ArgInfo("params", 0)))
        {
            ERRWRAP2_NAPI(info, retval = cv::imencode(ext, img, buf, params));
            Napi::Value p1 = jsopencv_from(info, retval);
            Napi::Value p2 = jsopencv_from(info, buf);
            return Js_BuildValue(info, "(NN)", p1, p2);
        }
        jsPopulateArgumentConversionErrors(info);
    }

    {
        Napi::Value *jsobj_ext = NULL;
        String ext;
        Napi::Value *jsobj_img = NULL;
        UMat img;
        vector_uchar buf;
        Napi::Value *jsobj_params = NULL;
        vector_int params = std::vector<int>();
        bool retval;

        const char *keywords[] = {"ext", "img", "params", NULL};
        std::cout << "JsArg_ParseTupleAndKeywords OO|O:imencode twice" << std::endl;
        if (JsArg_ParseTupleAndKeywords(info, "OO|O:imencode", (char **)keywords, &jsobj_ext, &jsobj_img, &jsobj_params) &&
            jsopencv_to_safe(jsobj_ext, ext, ArgInfo("ext", 0)) &&
            jsopencv_to_safe(jsobj_img, img, ArgInfo("img", 0)) &&
            jsopencv_to_safe(jsobj_params, params, ArgInfo("params", 0)))
        {
            ERRWRAP2_NAPI(info, retval = cv::imencode(ext, img, buf, params));
            return Js_BuildValue(info, "(NN)", jsopencv_from(info, retval), jsopencv_from(info, buf));
        }
        jsPopulateArgumentConversionErrors(info);
    }
    jsRaiseCVOverloadException(info, "imencode");
    return info.Env().Null();
}
#endif

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
    try
    {
        std::cout << "Calling Test: " << MAGANTA << "Js_BuildValue_test" << RESET << std::endl;
        Js_BuildValue_test(info);
        std::cout << "Calling Test: " << MAGANTA << "JsArg_ParseTupleAndKeywords_test" << RESET << std::endl;
        JsArg_ParseTupleAndKeywords_test(info);
        std::cout << "ALL done" << std::endl;
    }
    catch (const std::exception &ex)
    {
        failmsg(info.Env(), "A Test Throws un non catched Exception: %s", ex.what());
    }
    return info.Env().Null();
}

Napi::Object cvmainInit(Napi::Env env, Napi::Object exports)
{
    // std::cout << "imread is attached to export" << std::endl;
    exports.Set("imread", Napi::Function::New(env, jsopencv_cv_imread));
#ifdef NEXRT_BUILD
    exports.Set("imencode", Napi::Function::New(env, jsopencv_cv_imencode));
#endif
    exports.Set("test", Napi::Function::New(env, test));
    return exports;
}