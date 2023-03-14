#include <node_api.h>

napi_value Init(napi_env env, napi_value exports) {
    // Module initialization code goes here
    napi_status status;
    napi_value fn;

    // Arguments 2 and 3 are function name and length respectively
    // We will leave them as empty for this example
    // status = napi_create_function(env, NULL, 0, MyFunction, NULL, &fn);
    // if (status != napi_ok) {
    //     napi_throw_error(env, NULL, "Unable to wrap native function");
    // }
// 
    // status = napi_set_named_property(env, exports, "my_function", fn);
    // if (status != napi_ok) {
    //     napi_throw_error(env, NULL, "Unable to populate exports");
    // }
    return exports;
}


// napi_value MyFunction(napi_env env, napi_callback_info info) {
//     napi_status status;
// }

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)