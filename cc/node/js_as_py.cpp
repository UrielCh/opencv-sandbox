#include <napi.h>
#include "./js_as_py.hpp";
#include <vector>
#include <unordered_map>
#include <cstring>
#include <stdarg.h>
#include <napi.h>

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

static Napi::Value * JsCFunction_NewEx(JsMethodDef *ml, Napi::Value *self, Napi::Object *module) {
    const Napi::Env env = module->Env();
    module->Set(Napi::String::New(env, ml->ml_name), Napi::Function::New(env, ml->ml_meth));
}


static const std::string JsModule_GetName(Napi::Object *module) {
    if (module == nullptr) {
        throw std::invalid_argument("Input module is null");
    }

    Napi::Env env = module->Env();

    // Check if the module object has a "name" property
    if (!module->Has("name")) {
        throw std::runtime_error("Module object does not have a 'name' property");
    }

    // Get the "name" property from the module object
    Napi::Value nameValue = module->Get("name");

    // Ensure the "name" property is a string
    if (!nameValue.IsString()) {
        throw std::runtime_error("Module 'name' property is not a string");
    }

    // convert as char *
    // char* result = new char[nameStr.length() + 1];
    // std::copy(nameStr.begin(), nameStr.end(), result);
    // result[nameStr.length()] = '\0';

    // Convert the Napi::String to a std::string and return it
    return nameValue.As<Napi::String>().Utf8Value();
}

static int JsDict_SetItemString(Napi::Object* v, const char* key, Napi::Value* item) {
    if (v == nullptr || key == nullptr || item == nullptr) {
        return -1;  // Return an error code if any input is null
    }
    try {
        v->Set(key, *item);
    } catch (...) {
        return -1;  // Return an error code if an exception occurs
    }
    return 0;  // Return success code
}

Napi::Number JsLong_FromLongLong(const Napi::Env& env, long long value) {
    return Napi::Number::New(env, static_cast<double>(value));
}