#include <napi.h>
#include "cv_mat_object.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    cvMatObject::Init(env, exports);
    return exports;
}

NODE_API_MODULE(addon, InitAll)
