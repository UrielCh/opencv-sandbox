#include <napi.h>
#include "js_as_py.h"
#include <vector>
#include <unordered_map>
#include <cstring>
#include <stdarg.h>
#include <napi.h>
#include "comm.h"

// see doc: https://github.com/nodejs/node-addon-api/blob/main/doc/value.md

// napi_value is onky a void*, Napi::Value is a C++ wrapper adding type safety

template<typename T>
T parse_napi_value(const Napi::Env& env, const Napi::Value& value) {
    if (!value.IsNumber() && !value.IsBoolean()) {
        throw std::invalid_argument("Invalid argument type: expected number or boolean");
    }
    return static_cast<T>(Napi::Value(env, value).ToNumber());
}

void JsErr_SetString(const Napi::Env &env, const std::string &message)
{
    Napi::Error::New(env, message).ThrowAsJavaScriptException();
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

bool JsSequence_Check(const Napi::Value* obj)
{
    // Check if the object is an array
    if (!obj->IsArray()) {
        return false;
    }

    // Check if the object has a valid length property
    Napi::Object objWrapper = obj->As<Napi::Object>();
    Napi::Value lengthProp = objWrapper.Get("length");
    if (!lengthProp.IsNumber()) {
        return false;
    }

    // Check if the object has integer keys starting from 0 up to length-1
    uint32_t length = lengthProp.As<Napi::Number>().Uint32Value();
    for (uint32_t i = 0; i < length; i++) {
        if (!objWrapper.Has(i)) {
            return false;
        }
    }

    return true;
}

size_t JsSequence_Size(const Napi::Value* obj)
{
    // Check if the object is an array
    if (!obj->IsArray()) {
        return 0;
    }

    // Get the length of the array
    Napi::Object objWrapper = obj->As<Napi::Object>();
    Napi::Value lengthProp = objWrapper.Get("length");
    if (!lengthProp.IsNumber()) {
        return 0;
    }
    uint32_t length = lengthProp.As<Napi::Number>().Uint32Value();

    return length;
}

Napi::Value* JsSequence_GetItem(const Napi::Value* obj, size_t index) {
  Napi::Env env = obj->Env();

  if (!obj->IsArray()) {
    // Throw an error if obj is not an array
    failmsg(env, "Expected an array");
    return nullptr;
  }

  Napi::Array arr = obj->As<Napi::Array>();

  if (index >= arr.Length()) {
    // Throw an error if index is out of bounds
    failmsg(env, "Index out of bounds");
    return nullptr;
  }

  return new Napi::Value(arr[index]);
}