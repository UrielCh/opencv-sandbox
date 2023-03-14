#include <node_api.h>
#include <opencv2/opencv.hpp>

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

/**
 * @brief Allocate a CV_8UC3 cv:Mat
 *
 * @param env
 * @param info
 * @return napi_value
 */
napi_value AllocateMat(napi_env env, napi_callback_info info)
{
    napi_status status;
    size_t argc = 2;
    napi_value argv[2];
    status = napi_get_cb_info(env, info, &argc, argv, NULL, NULL);
    if (status != napi_ok || argc < 2)
    {
        napi_throw_error(env, NULL, "Invalid arguments");
        return NULL;
    }

    // Get the dimensions and type of the new Mat object
    int rows, cols, type;
    status = napi_get_value_int32(env, argv[0], &rows);
    if (status != napi_ok)
    {
        napi_throw_error(env, NULL, "Invalid rows argument");
        return NULL;
    }
    status = napi_get_value_int32(env, argv[1], &cols);
    if (status != napi_ok)
    {
        napi_throw_error(env, NULL, "Invalid cols argument");
        return NULL;
    }
    type = CV_8UC3; // or any other type you need

    // Allocate a new Mat object
    cv::Mat *mat = new cv::Mat(rows, cols, type);

    // Create a N-API buffer object to wrap the Mat object
    napi_value buffer;
    status = napi_create_external_buffer(
        env, rows * cols * 3, mat,
        [](napi_env env, void *data, void *hint)
        {
            cv::Mat *mat = static_cast<cv::Mat *>(data);
            delete mat;
        },
        NULL, &buffer);
    if (status != napi_ok)
    {
        napi_throw_error(env, NULL, "Failed to create buffer object");
        return NULL;
    }

    return buffer;
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


    // create and attache AllocateMat function
    status = napi_create_function(env, NULL, NAPI_AUTO_LENGTH, AllocateMat, NULL, &fn);
    if (status != napi_ok)
    {
        napi_throw_error(env, NULL, "Failed to create function");
        return NULL;
    }

    status = napi_set_named_property(env, exports, "allocateMat", fn);
    if (status != napi_ok)
    {
        napi_throw_error(env, NULL, "Failed to set function");
        return NULL;
    }




    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)