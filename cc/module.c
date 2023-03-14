#include <node_api.h>
// #include <opencv2/opencv.hpp>

/**
 * @brief sample function to multiply a number by two
 */
napi_value MultiplyByTwo(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value argv[1];
    napi_value result;
    int num;

    // Get the arguments passed to the function
    napi_status status = napi_get_cb_info(env, info, &argc, argv, NULL, NULL);
    if (status != napi_ok)
    {
        napi_throw_error(env, NULL, "Failed to parse arguments");
        return NULL;
    }

    // Check that the argument is a number
    status = napi_get_value_int32(env, argv[0], &num);
    if (status != napi_ok)
    {
        napi_throw_error(env, NULL, "Invalid argument");
        return NULL;
    }

    // Multiply the number by two
    int result_num = num * 2;

    // Create a new number value to hold the result
    status = napi_create_int32(env, result_num, &result);
    if (status != napi_ok)
    {
        napi_throw_error(env, NULL, "Failed to create result value");
        return NULL;
    }
    return result;
}




napi_value Init(napi_env env, napi_value exports)
{
    // Module initialization code goes here
    napi_status status;
    napi_value fn;

    // Create a new function object
    status = napi_create_function(env, NULL, 0, MultiplyByTwo, NULL, &fn);
    if (status != napi_ok)
    {
        napi_throw_error(env, NULL, "Failed to create function");
        return NULL;
    }

    // Export the function object
    status = napi_set_named_property(env, exports, "multiplyByTwo", fn);
    if (status != napi_ok)
    {
        napi_throw_error(env, NULL, "Failed to export function");
        return NULL;
    }

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)