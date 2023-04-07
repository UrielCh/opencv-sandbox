#include <napi.h>
#include <./node/js_as_py.hpp>
#include <opencv2/opencv.hpp>

class ArgInfo {
public:
    const char* name;
    bool outputarg;
    // more fields may be added if necessary

    ArgInfo(const char* name_, bool outputarg_) : name(name_), outputarg(outputarg_) {}

private:
    ArgInfo(const ArgInfo&) = delete;
    ArgInfo& operator=(const ArgInfo&) = delete;
};

#define ERRWRAP2_NAPI(info, expr)  \
    try { expr; } \
    catch (const cv::Exception &e) \
    { \
        Napi::Error::New((info).Env(), e.what()).ThrowAsJavaScriptException(); \
        return (info).Env().Undefined(); \
    } catch (const std::exception &e) { \
        Napi::Error::New((info).Env(), e.what()).ThrowAsJavaScriptException(); \
        return (info).Env().Undefined(); \
    } catch (...) { \
        Napi::Error::New((info).Env(), "Unknown exception occurred").ThrowAsJavaScriptException(); \
        return (info).Env().Undefined();                                       \
    }

int failmsg(const Napi::Env& env, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    char message[1024];
    vsnprintf(message, sizeof(message), format, args);
    va_end(args);
    Napi::Error::New(env, message).ThrowAsJavaScriptException();
    return 0;
}


template <typename T>
bool jsopencv_to(const Napi::Value* obj, T& value, const ArgInfo& argInfo) {
    failmsg(obj->Env(), "not implemented yet");
//    return JsOpenCV_Converter<T>::to(obj, value, argInfo);
    return false;
} 

template<>
bool jsopencv_to(const Napi::Value* obj, cv::String &value, const ArgInfo& argInfo) {
    if (obj->IsNull() || obj->IsUndefined())
        return true;

    if (obj->IsString()) {
        value = obj->ToString().Utf8Value();
        return true;
    }
    failmsg(obj->Env(), "Argument '%s' is not convertable to string", argInfo.name);
    return false;
}



template<typename T>
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const T& src) { 
    failmsg(info, "jsopencv_from template resolved as unknownn type");
    return info.Env().Null();
} // JsOpenCV_Converter<T>::from(src);


template<> // L:239
Napi::Value jsopencv_from(const Napi::CallbackInfo &info, const cv::Mat& m) {
    Napi::Env env = info.Env();
    Napi::Object obj = Napi::Object::New(env);
    size_t size = m.total() * m.elemSize();
    Napi::Buffer<uint8_t> buffer = Napi::Buffer<uint8_t>::New(env, m.data, size);
    obj.Set(Napi::String::New(env, "data"), buffer);
    obj.Set(Napi::String::New(env, "dims"), Napi::Number::New(env, m.dims));
    obj.Set(Napi::String::New(env, "rows"), Napi::Number::New(env, m.rows));
    obj.Set(Napi::String::New(env, "cols"), Napi::Number::New(env, m.cols));
    // contains type, depth, channels 
    obj.Set(Napi::String::New(env, "flags"), Napi::Number::New(env, m.flags));
    // flags as exploded data view
    obj.Set(Napi::String::New(env, "channels"), Napi::Number::New(env, m.channels()));
    obj.Set(Napi::String::New(env, "depth"), Napi::Number::New(env, m.depth()));
    obj.Set(Napi::String::New(env, "type"), Napi::Number::New(env, m.type()));
    return obj;
}

template<typename _Tp> static
bool jsopencv_to_safe(const Napi::Value* obj, const _Tp& value, const ArgInfo& argInfo)
{
    try
    {
        return jsopencv_to(obj, value, argInfo);
    }
    catch (const std::exception &e)
    {
        failmsg(obj->Env(), "Conversion error: %s, what: %s", argInfo.name, e.what());
        return false;
    }
    catch (...)
    {
        failmsg(obj->Env(), "Conversion error: %s", argInfo.name);
        return false;
    }
}

// template<> static
// bool jsopencv_to_safe(const Napi::Value *,const cv::String &,const ArgInfo &);
// 
// 
// template<> static
// bool jsopencv_to_safe(const Napi::Value *,const int &,const ArgInfo &);


/**
 * @brief hand writen function to allocate a Mat
 */
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

/**
 * @brief generated binding to read an image
 */
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

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "allocateMat"), Napi::Function::New(env, AllocateMat));
    exports.Set(Napi::String::New(env, "imread"), Napi::Function::New(env, jsopencv_cv_imread));
    return exports;
}

NODE_API_MODULE(addon, Init)