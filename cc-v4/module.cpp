#include <napi.h>
#include "cv_mat_object.h"
#include "cv_main.h"
#include "../cc-common/js_as_py_test.h"
#include "../cc-common/cv2_util.h"

#include "./AKAZE.h";

static Napi::Value runAvaTest(const Napi::CallbackInfo &info)
{
    try
    {
        Js_BuildValue_test(info);
        JsArg_ParseTupleAndKeywords_test(info);
        // std::cout << "ALL tests done" << std::endl;
    }
    catch (const std::exception &ex)
    {
        jsfailmsg(info.Env(), "A Test Throws un non catched Exception: %s", ex.what());
    }
    return info.Env().Null();
}

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
    exports.Set("runAvaTest", Napi::Function::New(env, runAvaTest));

    cvmainInit(env, exports);
    InitAKAZE(env, exports);

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