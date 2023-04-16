#include "cv_main.h"
#include "cv_mat_object.h"
#include "../cc-common/cv2_convert.h"
#include "../cc-common/js_as_py.h"
#include <iostream>
#include <opencv2/opencv.hpp>

// #define NEXRT_BUILD 1

bool jsopencv_to_safe(const Napi::Value* obj, cv::UMat img, const ArgInfo& argInfo)
{
    jsfailmsg(obj->Env(), "Conversion UMat Not implemented");
    return false;
}
// <cv::UMat>
Napi::Value jsopencv_from(const Napi::Env &env, const cv::UMat & src) {
    jsfailmsg(env, "jsopencv_from<UMat> Not implemented");
    return env.Null();
}

// this file is a subset of jsopencv_generated_funcs.h
#include "./gen-extract.hh"

Napi::Object cvmainInit(Napi::Env env, Napi::Object exports)
{

    exports.Set("idft", Napi::Function::New(env, jsopencv_cv_idft));
    #ifdef HAVE_OPENCV_PHOTO
    exports.Set("illuminationChange", Napi::Function::New(env, jsopencv_cv_illuminationChange));
    #endif
    exports.Set("imcount", Napi::Function::New(env, jsopencv_cv_imcount));
    exports.Set("imdecode", Napi::Function::New(env, jsopencv_cv_imdecode));
    exports.Set("imdecodemulti", Napi::Function::New(env, jsopencv_cv_imdecodemulti));
    exports.Set("imencode", Napi::Function::New(env, jsopencv_cv_imencode));
    exports.Set("imread", Napi::Function::New(env, jsopencv_cv_imread));
    exports.Set("imreadmulti", Napi::Function::New(env, jsopencv_cv_imreadmulti));
    exports.Set("imshow", Napi::Function::New(env, jsopencv_cv_imshow));
    exports.Set("imwrite", Napi::Function::New(env, jsopencv_cv_imwrite));
    exports.Set("imwritemulti", Napi::Function::New(env, jsopencv_cv_imwritemulti));
    exports.Set("inRange", Napi::Function::New(env, jsopencv_cv_inRange));
    #ifdef HAVE_OPENCV_CALIB3D
    exports.Set("initCameraMatrix2D", Napi::Function::New(env, jsopencv_cv_initCameraMatrix2D));
    #endif

    // exports.Set("resize", Napi::Function::New(env, jsopencv_cv_resize));
    exports.Set("getVersionMajor", Napi::Function::New(env, jsopencv_cv_getVersionMajor));
    exports.Set("getVersionMinor", Napi::Function::New(env, jsopencv_cv_getVersionMinor));
    exports.Set("getVersionRevision", Napi::Function::New(env, jsopencv_cv_getVersionRevision));

    return exports;
}
