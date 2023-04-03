#ifndef CV_MAIN_H
#define CV_MAIN_H

#include <napi.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

Napi::Object cvmainInit(Napi::Env env, Napi::Object exports);

#endif