#include <napi.h>
#include "cv_mat_object.h"
#include "cv_main.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
    cvmainInit(env, exports);
    cvMatObject::Init(env, exports);
    return exports;
}

NODE_API_MODULE(jscv, InitAll)

// static napi_value __napi_InitAll(napi_env env, napi_value exports) { return Napi::RegisterModule(env, exports, InitAll); }
// extern "C"
// {
//     static napi_module _module = {
//         1,
//         0,
//         __FILE__,
//         __napi_InitAll,
//         "addon",
//         0,
//         {0},
//     };
//     static void __cdecl _register_addon(void);
//     namespace
//     {
//         struct _register_addon_
//         {
//             _register_addon_() { _register_addon(); }
//         } _register_addon_v_;
//     }
//     static void __cdecl _register_addon(void) { napi_module_register(&_module); }
// }