#include <napi.h>
#include "../cc-generated/jsopencv_generated_include.h"
#include "../cc-common/cv2_macro.hpp"
#include "../cc-common/js_as_py.h"
#include "../cc-common/cv2_convert.h"


using namespace cv;


// CVJS_TYPE(Layer, dnn_Layer, cv::Ptr<cv::dnn::Layer>, Ptr, Algorithm, 0, ".dnn");

static Napi::Value jsopencv_cv_dnn_dnn_Layer_run(const Napi::CallbackInfo &info)
{
    using namespace cv::dnn;
    Napi::Env env = info.Env();


    Ptr<cv::dnn::Layer> * self1 = 0;
    // if (!jsopencv_dnn_Layer_getp(&(info.This()), self1))
    //     return jsfailmsgp(env, "Incorrect type of self (must be 'dnn_Layer' or its derivative)");
    Ptr<cv::dnn::Layer> _self_ = *(self1);
    Napi::Value* jsobj_inputs = NULL;
    vector_Mat inputs;
    Napi::Value* jsobj_outputs = NULL;
    vector_Mat outputs;
    Napi::Value* jsobj_internals = NULL;
    vector_Mat internals;

    const char* keywords[] = { "inputs", "internals", "outputs", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "OO|O:dnn_Layer.run", (char**)keywords, &jsobj_inputs, &jsobj_internals, &jsobj_outputs) &&
        jsopencv_to_safe(jsobj_inputs, inputs, ArgInfo("inputs", 0)) &&
        jsopencv_to_safe(jsobj_outputs, outputs, ArgInfo("outputs", 1)) &&
        jsopencv_to_safe(jsobj_internals, internals, ArgInfo("internals", 1)))
    {
        ERRWRAP2_NAPI(env, _self_->run(inputs, outputs, internals));
        return Js_BuildValue(env, "(NN)", jsopencv_from(env, outputs), jsopencv_from(env, internals));
    }

    return env.Null();
}
