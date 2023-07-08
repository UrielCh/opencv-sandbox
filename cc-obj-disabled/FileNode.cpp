// #include "../sandbox/sample.cpp"
#include "./FileNode.h"

#include "../cc-common/cv2_convert.h"
#include "../cc-common/cv2_util.h"
#include "../cc-generated/jsopencv_generated_include.h"

using namespace cv;

static Napi::Value jsopencv_FileNode_Instance(const Napi::Env& env, const cv::Ptr<cv::FileNode>& r) {
    Napi::Object newInstance = FileNodeWrapper::constructor.New({});
    FileNodeWrapper* wrapper = FileNodeWrapper::Unwrap(newInstance);
    wrapper->cvdata = r;
    return newInstance;
}

template <>
struct JsOpenCV_Converter<Ptr<cv::FileNode>> {
    static Napi::Value from(const Napi::Env& env, const Ptr<cv::FileNode>& r) {
        return jsopencv_FileNode_Instance(env, r);
    }
    static bool to(Napi::Value* src, Ptr<cv::FileNode>& dst, const ArgInfo& info) {
        if (!src || src->IsNull() || src->IsUndefined())
            return true;

        Napi::Object obj = src->As<Napi::Object>();    // Convert Napi::Value to Napi::Object
        if (!obj.Has(FileNodeWrapper::typeSymbol)) {  //  || !obj.Get(AKAZEWrapper::typeSymbol).As<Napi::Boolean>().Value())
            jsfailmsg(src->Env(), "Expected Ptr<cv::FileNode> for argument '%s'", info.name);
        }
        FileNodeWrapper* wrapper = FileNodeWrapper::Unwrap(obj);  // Unwrap the Napi::Object to get AKAZEWrapper instance
        dst = wrapper->cvdata;                                      // Access the cvdata member
        return false;
    }
};

// functions