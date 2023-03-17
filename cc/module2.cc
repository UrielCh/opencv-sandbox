#include <napi.h>
#include <parse.hh>
// #include <node_api.h>
#include <opencv2/opencv.hpp>
// 2nd test code
class ArgInfo
{
public:
    const char* name;
    bool outputarg;
    // more fields may be added if necessary

    ArgInfo(const char* name_, bool outputarg_) : name(name_), outputarg(outputarg_) {}

private:
    ArgInfo(const ArgInfo&) = delete;
    ArgInfo& operator=(const ArgInfo&) = delete;
};



// parted from pyopencv_to_safe
template<typename _Tp> static
bool nodeopencv_to_safe(Napi::Value* obj, _Tp& value, const ArgInfo& info)
{
    try
    {
        return nodeopencv_to(obj, value, info);
    }
    catch (const std::exception &e)
    {
        PyErr_SetString(opencv_error, cv::format("Conversion error: %s, what: %s", info.name, e.what()).c_str());
        return false;
    }
    catch (...)
    {
        PyErr_SetString(opencv_error, cv::format("Conversion error: %s", info.name).c_str());
        return false;
    }
}


static Napi::Value pyopencv_cv_imread(const Napi::CallbackInfo &info)
{
    using namespace cv;

    Napi::Value* pyobj_filename = NULL;
    String filename;

    Napi::Value* pyobj_flags = NULL;
    int flags=IMREAD_COLOR;

    Mat retval;

    const char* keywords[] = { "filename", "flags", NULL };
    if( NodeArg_ParseTupleAndKeywords(info, "O|O:imread", (char**)keywords, &pyobj_filename, &pyobj_flags) &&
        nodeopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 0)) &&
        nodeopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imread(filename, flags));
        return pyopencv_from(retval);
    }

    return NULL;
}
