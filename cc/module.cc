#include <napi.h>
#include <opencv2/opencv.hpp>
#include "node/cv2_convert.hpp"

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
    return nodeopencv_from(info, *mat);
}

Napi::Value ReadImage(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    if (info.Length() < 1 || !info[0].IsString())
    {
        Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
        return env.Null();
    }

    std::string filename = info[0].As<Napi::String>().Utf8Value();
    cv::Mat img = cv::imread(filename);

    if (img.empty())
    {
        Napi::Error::New(env, "Failed to read image").ThrowAsJavaScriptException();
        return env.Null();
    }
    return nodeopencv_from(info, img);
}

// #define ERRWRAP2

// replace "static PyObject*" by Napi::Value
// replace "PyObject* , PyObject* py_args, PyObject* kw" by const Napi::CallbackInfo &info
// Napi::Value pyopencv_cv_imread(const Napi::CallbackInfo &info)
// {
//     // drop 
//     // using namespace cv;
// 
//     // PyObject* pyobj_filename = NULL;
//     std::string pyobj_filename = NULL;
// 
//     String filename;
//     PyObject* pyobj_flags = NULL;
//     int flags=IMREAD_COLOR;
//     Mat retval;
// 
//     const char* keywords[] = { "filename", "flags", NULL };
//     if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:imread", (char**)keywords, &pyobj_filename, &pyobj_flags) &&
//         pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 0)) &&
//         pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
//     {
//         ERRWRAP2(retval = cv::imread(filename, flags));
//         return pyopencv_from(retval);
//     }
// 
//     return NULL;
// }


Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "multiplyByTwo"), Napi::Function::New(env, MultiplyByTwo));
    exports.Set(Napi::String::New(env, "allocateMat"), Napi::Function::New(env, AllocateMat));
    exports.Set(Napi::String::New(env, "imread"), Napi::Function::New(env, ReadImage));
    return exports;
}

NODE_API_MODULE(addon, Init)