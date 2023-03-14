#include <napi.h>
// #include <node_api.h>
#include <opencv2/opencv.hpp>

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
    Napi::External<cv::Mat> external = Napi::External<cv::Mat>::New(env, mat, [](Napi::Env env, cv::Mat *data)
                                                                    { delete data; });

    // return
    Napi::Object result = Napi::Object::New(env);
    result.Set(Napi::String::New(env, "data"), external);
    result.Set(Napi::String::New(env, "rows"), rows);
    result.Set(Napi::String::New(env, "cols"), cols);
    result.Set(Napi::String::New(env, "type"), type);
    return result;
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

    size_t size = img.total() * img.elemSize();
    Napi::Buffer<uint8_t> buffer = Napi::Buffer<uint8_t>::New(env, img.data, size);
    Napi::Object obj = Napi::Object::New(env);
    obj.Set(Napi::String::New(env, "data"), buffer);
    obj.Set(Napi::String::New(env, "rows"), Napi::Number::New(env, img.rows));
    obj.Set(Napi::String::New(env, "cols"), Napi::Number::New(env, img.cols));
    obj.Set(Napi::String::New(env, "channels"), Napi::Number::New(env, img.channels()));

    return obj;
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "multiplyByTwo"), Napi::Function::New(env, MultiplyByTwo));
    exports.Set(Napi::String::New(env, "allocateMat"), Napi::Function::New(env, AllocateMat));
    exports.Set(Napi::String::New(env, "readImage"), Napi::Function::New(env, ReadImage));
    return exports;
}

NODE_API_MODULE(addon, Init)