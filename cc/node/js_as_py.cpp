#include <napi.h>
#include "./js_as_py.hpp";
#include <vector>
#include <unordered_map>
#include <cstring>
#include <stdarg.h>
#include <napi.h>

// see doc: https://github.com/nodejs/node-addon-api/blob/main/doc/value.md

// napi_value is onky a void*, Napi::Value is a C++ wrapper adding type safety

