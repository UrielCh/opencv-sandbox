#include <napi.h>
#include <opencv2/opencv.hpp>
#include "node/cv2_convert.hpp"
#include <parse.hh>


/**
 * @brief sample function to multiply a number by two
 */
Napi::Number MultiplyByTwo(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    if (info.Length() < 1 || !info[0].IsNumber())
    {
        Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
        return Napi::Number::New(env, 0);
    }

    double value = info[0].As<Napi::Number>().DoubleValue();
    double result = value * 2;

    return Napi::Number::New(env, result);
}

Napi::Value AllocateMat(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber())
    {
        // Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
        Napi::TypeError::New(env, "Invalid arguments, expected (width: number, height: number)").ThrowAsJavaScriptException();
        return env.Null();
    }

    int rows = info[0].As<Napi::Number>().Int32Value();
    int cols = info[1].As<Napi::Number>().Int32Value();
    int type = CV_8UC3;

    if (info.Length() > 2 && info[2].IsNumber())
    {
        type = info[2].As<Napi::Number>().Int32Value();
    }

    cv::Mat *mat = new cv::Mat(rows, cols, type);
    return jsopencv_from(info, *mat);
}

// Napi::Value ReadImage(const Napi::CallbackInfo &info)
// {
//     Napi::Env env = info.Env();

//     if (info.Length() < 1 || !info[0].IsString())
//     {
//         Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
//         return env.Null();
//     }

//     std::string filename = info[0].As<Napi::String>().Utf8Value();
//     cv::Mat img = cv::imread(filename);

//     if (img.empty())
//     {

//         // Napi::Error::New(env, "img is empty, Failed to read image").ThrowAsJavaScriptException();
//         failmsg(info, "img is empty, Failed to read image \"%s\"", filename.c_str());
//         return env.Null();
//     }

//     return jsopencv_from(info, img);
// }

// #define ERRWRAP2

static Napi::Value jsopencv_cv_imread(const Napi::CallbackInfo &info)
{
    using namespace cv;

    Napi::Value* jsobj_filename = NULL;
    String filename;

    Napi::Value* jsobj_flags = NULL;
    int flags=IMREAD_COLOR;

    Mat retval;

    const char* keywords[] = { "filename", "flags", NULL };
    if( JsArg_ParseTupleAndKeywords(info, "O|O:imread", (char**)keywords, &jsobj_filename, &jsobj_flags) &&
        jsopencv_to_safe(info, jsobj_filename, filename, ArgInfo("filename", 0)) &&
        jsopencv_to_safe(info, jsobj_flags, flags, ArgInfo("flags", 0)) )
    {
        //ERRWRAP2(
        retval = cv::imread(filename, flags);
        // );
        return jsopencv_from(info, retval);
    }

    return info.Env().Null();
}


Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "multiplyByTwo"), Napi::Function::New(env, MultiplyByTwo));
    exports.Set(Napi::String::New(env, "allocateMat"), Napi::Function::New(env, AllocateMat));
    exports.Set(Napi::String::New(env, "imread"), Napi::Function::New(env, jsopencv_cv_imread));
    return exports;
}

NODE_API_MODULE(addon, Init)