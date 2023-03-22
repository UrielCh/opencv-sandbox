#include <napi.h>
#include "./js_as_py.hpp";
#include <vector>
#include <unordered_map>
#include <cstring>
#include <stdarg.h>

// see doc: https://github.com/nodejs/node-addon-api/blob/main/doc/value.md

// napi_value is onky a void*, Napi::Value is a C++ wrapper adding type safety

template<typename T>
T parse_napi_value(const Napi::Env& env, const Napi::Value& value) {
    if (!value.IsNumber() && !value.IsBoolean()) {
        throw std::invalid_argument("Invalid argument type: expected number or boolean");
    }
    return static_cast<T>(Napi::Value(env, value).ToNumber());
}

bool JsArg_ParseTupleAndKeywords(const Napi::CallbackInfo &info, const char *format, char **keywords, ...)
{
    int numKeywords = 0;
    while (keywords[numKeywords] != NULL)
    {
        numKeywords++;
    }

    if (info.Length() < numKeywords)
    {
        Napi::TypeError::New(info.Env(), "Not enough arguments provided").ThrowAsJavaScriptException();
        return false;
    }

    va_list args;
    va_start(args, keywords);

    for (int i = 0; i < numKeywords; i++)
    {
        Napi::Value *arg = va_arg(args, Napi::Value *);
        if (!arg || !info[i].IsObject())
        {
            va_end(args);
            Napi::TypeError::New(info.Env(), "Expected object for argument").ThrowAsJavaScriptException();
            return false;
        }

        Napi::Object obj = info[i].As<Napi::Object>();
        Napi::String key = Napi::String::New(info.Env(), keywords[i]);
        if (!obj.HasOwnProperty(key))
        {
            va_end(args);
            Napi::TypeError::New(info.Env(), "Missing required keyword argument").ThrowAsJavaScriptException();
            return false;
        }

        *arg = obj.Get(key);
    }

    va_end(args);
    return true;
}
