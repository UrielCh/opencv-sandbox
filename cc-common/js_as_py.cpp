#include <napi.h>
#include "js_as_py.h"
#include <vector>
#include <unordered_map>
#include <cstring>
#include <stdarg.h>
#include <iostream>
#include <napi.h>
#include "js_as_py.h"

// see doc: https://github.com/nodejs/node-addon-api/blob/main/doc/value.md

// napi_value is onky a void*, Napi::Value is a C++ wrapper adding type safety

const std::string RED("\033[0;31m");
const std::string GREEN("\033[1;32m");
const std::string YELLOW("\033[1;33m");
const std::string CYAN("\033[0;36m");
const std::string MAGANTA("\033[0;35m");
const std::string RESET("\033[0m");
const std::string NEW(" (" + RED + "NEW" + RESET + ")");


// like int failmsg(const Napi::Env& env, const char *fmt, ...); // defined in cv2_utils.cpp
// but used in Python emulation code.
void throwErrorWithFormat(const char* format, ...)
{
    char errorMessage[1024];

    va_list args;
    va_start(args, format);
    std::vsnprintf(errorMessage, sizeof(errorMessage), format, args);
    va_end(args);

    throw std::runtime_error(errorMessage);
}

/**
 * 
 * @brief act as PyArg_ParseTupleAndKeywords
 * 
 * @param info NApi CallbackInfo info object
 * @param format string like "OO|OOO:Name" or "O|OOO:Name" each O means a object
 * @param keywords named of all arguments, used onkly for optional ones
 * @param ... placeholder to store the arguments of types Napi::Value *
 * @return true 
 * @return false 
 */
// template<class T>
// bool JsArg_ParseTupleAndKeywords(const T& info, const char* format, char** keywords, ...) {
bool JsArg_ParseTupleAndKeywords(const Napi::CallbackInfo& info, const char* format, char** keywords, ...) {
    // Prepare to handle variable arguments
    va_list args;
    va_start(args, keywords);

    // Initialize iterators for format string and keywords
    const char* fmt_iter = format;
    char** kw_iter = keywords;

    // Check if we reached the end of the format string
    bool is_optional = false;

    size_t arg_position = 0;
    bool first_optional = true;
    Napi::Object optional_obj;

    while (*fmt_iter && *fmt_iter != ':') {
         // std::cout << "LOOP JsArg_ParseTupleAndKeywords arg_position = " << YELLOW << arg_position << RESET << " current kw_iter:"
         // << *kw_iter << " KW position: " << YELLOW << (kw_iter - keywords) << RESET << NEW << std::endl;

        if (!*kw_iter) {
            throwErrorWithFormat("missing some keywords passed to JsArg_ParseTupleAndKeyword format:%s", format);
            return false;
        }
        // Switch to Optional arguments
        if (*fmt_iter == '|') {
            fmt_iter++;
            is_optional = true;
            if (!*fmt_iter) {
                // should throw error
                throwErrorWithFormat("invalid format: '%s' in JsArg_ParseTupleAndKeywords unexpected end of format", format);
                continue;
            }
        }
        if (arg_position >= info.Length()) {
            if (is_optional) {
                if (!optional_obj) {
                    // std::cout << "We've reached the end of the required arguments:"<< is_optional << std::endl;
                    // We've reached the end of the required arguments
                    break;
                }
            } else {
                // Not enough arguments provided
                va_end(args);
                throwErrorWithFormat(
                    "Not enough arguments provided for '%s' arg_position: %d is_optional: %s",
                    format,
                    arg_position,
                    is_optional ? "true" : "false"
                );
                return false;
            }
        }
        // Set the corresponding varg value
        const Napi::Value** arg = va_arg(args, const Napi::Value**);
        if (is_optional) {
            // if first optional eand last param and is object, then it is the optional object
            if (first_optional && info.Length() == (arg_position+1)) {
                if ((info)[arg_position].IsObject()) {
                    optional_obj = info[arg_position].As<Napi::Object>();
                }
                first_optional = false;
            }
            if (!optional_obj) {
                // we do not have optional object source
                *arg = new Napi::Value(info.Env(), info[arg_position]);
            } else if (optional_obj.Has(*kw_iter)) {
                *arg = new Napi::Value(info.Env(), optional_obj.Get(*kw_iter));
            } else {
                // leave it as null the optional value had not be provided
            }
        } else {
            *arg = new Napi::Value(info.Env(), info[arg_position]);
        }
        arg_position++;
        fmt_iter++;
        kw_iter++; // Increment kw_iter for each argument
    }
    // look for the : to find the function name
    // const char* function_name = "??";//nullptr;
    // while  ( *fmt_iter && *fmt_iter != ':') {
    //     fmt_iter++;
    // }
    // if (*fmt_iter == ':') {
    //     function_name = fmt_iter + 1;
    // }
    va_end(args);
    return true;
}





bool JsArg_ParseTupleAndKeywords(const FakeCallbackInfo& info, const char* format, char** keywords, ...) {
    // Prepare to handle variable arguments
    va_list args;
    va_start(args, keywords);

    // Initialize iterators for format string and keywords
    const char* fmt_iter = format;
    char** kw_iter = keywords;

    // Check if we reached the end of the format string
    bool is_optional = false;

    size_t arg_position = 0;
    bool first_optional = true;
    Napi::Object optional_obj;

    while (*fmt_iter && *fmt_iter != ':') {
         // std::cout << "LOOP JsArg_ParseTupleAndKeywords arg_position = " << YELLOW << arg_position << RESET << " current kw_iter:"
         // << *kw_iter << " KW position: " << YELLOW << (kw_iter - keywords) << RESET << NEW << std::endl;

        if (!*kw_iter) {
            throwErrorWithFormat("missing some keywords passed to JsArg_ParseTupleAndKeyword format:%s", format);
            return false;
        }
        // Switch to Optional arguments
        if (*fmt_iter == '|') {
            fmt_iter++;
            is_optional = true;
            if (!*fmt_iter) {
                // should throw error
                throwErrorWithFormat("invalid format: '%s' in JsArg_ParseTupleAndKeywords unexpected end of format", format);
                continue;
            }
        }
        if (arg_position >= info.Length()) {
            if (is_optional) {
                if (!optional_obj) {
                    // std::cout << "We've reached the end of the required arguments:"<< is_optional << std::endl;
                    // We've reached the end of the required arguments
                    break;
                }
            } else {
                // Not enough arguments provided
                va_end(args);
                throwErrorWithFormat(
                    "Not enough arguments provided for '%s' arg_position: %d is_optional: %s",
                    format,
                    arg_position,
                    is_optional ? "true" : "false"
                );
                return false;
            }
        }
        // Set the corresponding varg value
        const Napi::Value** arg = va_arg(args, const Napi::Value**);
        if (is_optional) {
            // if first optional eand last param and is object, then it is the optional object
            if (first_optional && info.Length() == (arg_position+1)) {
                if ((info)[arg_position].IsObject()) {
                    optional_obj = info[arg_position].As<Napi::Object>();
                }
                first_optional = false;
            }
            if (!optional_obj) {
                // we do not have optional object source
                *arg = new Napi::Value(info.Env(), info[arg_position]);
            } else if (optional_obj.Has(*kw_iter)) {
                *arg = new Napi::Value(info.Env(), optional_obj.Get(*kw_iter));
            } else {
                // leave it as null the optional value had not be provided
            }
        } else {
            *arg = new Napi::Value(info.Env(), info[arg_position]);
        }
        arg_position++;
        fmt_iter++;
        kw_iter++; // Increment kw_iter for each argument
    }
    // look for the : to find the function name
    // const char* function_name = "??";//nullptr;
    // while  ( *fmt_iter && *fmt_iter != ':') {
    //     fmt_iter++;
    // }
    // if (*fmt_iter == ':') {
    //     function_name = fmt_iter + 1;
    // }
    va_end(args);
    return true;
}

// template bool JsArg_ParseTupleAndKeywords(const Napi::CallbackInfo& info, const char* format, char** keywords, ...);
// template bool JsArg_ParseTupleAndKeywords(const FakeCallbackInfo& info, const char* format, char** keywords, ...);


FakeCallbackInfo::FakeCallbackInfo(const Napi::CallbackInfo& original_info, const std::vector<Napi::Value>& new_args)
    : env(original_info.Env()), new_args(new_args) {}

size_t FakeCallbackInfo::Length() const {
    return new_args.size();
}

Napi::Value FakeCallbackInfo::operator[](size_t index) const {
    if (index < new_args.size()) {
        return new_args[index];
    }
    return Napi::Value();
}

Napi::Env FakeCallbackInfo::Env() const {
    return env;
}

Napi::Value Js_BuildValue_Helper(const Napi::CallbackInfo &info, const char *format, va_list &args)
{
    Napi::Env env = info.Env();
    Napi::Value result;
    if (!format || *format == '\0')
    {
        result = env.Null();
    }
    else
    {
        switch (*format)
        {
        case 'i':
            result = Napi::Number::New(env, va_arg(args, int));
            break;
        case 'f':
            result = Napi::Number::New(env, va_arg(args, double));
            break;
        case 's':
            result = Napi::String::New(env, va_arg(args, const char *));
            break;
        case 'b':
            result = Napi::Boolean::New(env, va_arg(args, int) != 0);
            break;
        case 'N':
            result = va_arg(args, Napi::Value);
            break;
        case '(':
        case '[':
            {
                Napi::Array array = Napi::Array::New(env);
                size_t index = 0;
                for (format++; *format && *format != ']' && *format != ')'; format++)
                {
                    Napi::Value element = Js_BuildValue_Helper(info, format, args);
                    array.Set(index++, element);
                }
                result = array;
            }
            break;
        case '{':
            {
                Napi::Object object = Napi::Object::New(env);
                for (format++; *format && *format != '}'; format++)
                {
                    Napi::Value key;
                    if (*format == 's')
                    {
                        std::string str = va_arg(args, const char *);
                        key = Napi::String::New(env, str);
                    }
                    else if (*format == 'i')
                    {
                        uint32_t i32 = va_arg(args, uint32_t);
                        key = Napi::Number::New(env, i32);
                    } else {
                        throwErrorWithFormat("invalid format: '%s' in Js_BuildValue_Helper object keys must be type s or i", format);
                        return env.Null();
                    }
                    ++format;
                    if (*format != ':') {
                        throwErrorWithFormat( "invalid format: '%s' in Js_BuildValue_Helper Each object key must be followd by a comma", format);
                        return env.Null();
                    }
                    // skip the colon
                    format++;
                    if (*format == '}' || *format == '\0') {
                        throwErrorWithFormat("invalid format: '%s' in Js_BuildValue_Helper expected value type for the last key", format);
                        return env.Null();
                    }
                    Napi::Value value = Js_BuildValue_Helper(info, format, args);
                    format++;
                    object.Set(key, value);
                }
                result = object;
            }
            break;
        default:
            result = env.Null();
            break;
        }
    }

    return result;
}

Napi::Value Js_BuildValue(const Napi::CallbackInfo &info, const char *format, ...)
{
    Napi::Env env = info.Env();

    va_list args;
    va_start(args, format);

    Napi::Value result = Js_BuildValue_Helper(info, format, args);

    va_end(args);
    return result;
}


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

Napi::Value * JsCFunction_NewEx(JsMethodDef *ml, Napi::Value *self, Napi::Object *module) {
    const Napi::Env env = module->Env();
    module->Set(Napi::String::New(env, ml->ml_name), Napi::Function::New(env, ml->ml_meth));
    return module;
}


const std::string JsModule_GetName(Napi::Object *module) {
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

int JsDict_SetItemString(Napi::Object* v, const char* key, Napi::Value* item) {
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

Napi::Value* JsString_FromString(const Napi::Env& env, const char* str) {
    if (str == nullptr) {
        throw std::invalid_argument("Input string is null");
    }

    // Create a new Napi::String and allocate it on the heap
    Napi::Value* result = new Napi::String(Napi::String::New(env, str));
    return result;
}

Napi::Number JsLong_FromLongLong(const Napi::Env& env, long long value) {
    return Napi::Number::New(env, static_cast<double>(value));
}
// not shure
Napi::Number JsLong_FromUnsignedLong(const Napi::Env& env, long long value) {
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
    throwErrorWithFormat("Expected an array");
    return nullptr;
  }

  Napi::Array arr = obj->As<Napi::Array>();

  if (index >= arr.Length()) {
    // Throw an error if index is out of bounds
    throwErrorWithFormat("Index out of bounds");
    return nullptr;
  }

  return new Napi::Value(arr[index]);
}