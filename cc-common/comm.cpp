
#include "comm.h"
#include <stdarg.h>
#include <iostream>

const std::string RED("\033[0;31m");
const std::string GREEN("\033[1;32m");
const std::string YELLOW("\033[1;33m");
const std::string CYAN("\033[0;36m");
const std::string MAGANTA("\033[0;35m");
const std::string RESET("\033[0m");
const std::string NEW(" (" + RED + "NEW" + RESET + ")");
/**
 * @brief Throws an exception exception-object
 */
int failmsg(const Napi::Env& env, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    char message[1024];
    vsnprintf(message, sizeof(message), format, args);
    va_end(args);
    Napi::Error::New(env, message).ThrowAsJavaScriptException();
    return 0;
}

Napi::Value failmsgp(const Napi::Env& env, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    char message[1024];
    vsnprintf(message, sizeof(message), format, args);
    va_end(args);
    Napi::Error::New(env, message).ThrowAsJavaScriptException();
    // Allocate memory for the Napi::Value
    // Napi::Value* result = new Napi::Value(env.Null());
    // return result;
    return env.Null();
}

/**
 * format is a c string like "OO|OOO:Name" or "O|OOO:Name" each O means a object
 * process this string as 3 parts:
 * 
 * 
 * , | means optional, :Name means function name
 */
bool JsArg_ParseTupleAndKeywordsOld(const Napi::CallbackInfo &info, const char *format, char **keywords, ...)
{
    size_t numKeywords = 0;
    // count arguments count from keywords
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

    for (size_t i = 0; i < numKeywords; i++)
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

/**
 * @brief act as PyArg_ParseTupleAndKeywords
 * 
 * @param info NApi CallbackInfo info object
 * @param format string like "OO|OOO:Name" or "O|OOO:Name" each O means a object
 * @param keywords named of all arguments, used onkly for optional ones
 * @param ... placeholder to store the arguments of types Napi::Value *
 * @return true 
 * @return false 
 */
bool JsArg_ParseTupleAndKeywords(const Napi::CallbackInfo& info, const char* format, char** keywords, ...) {
    // Prepare to handle variable arguments
    va_list args;
    va_start(args, keywords);

    // Initialize iterators for format string and keywords
    const char* fmt_iter = format;
    char** kw_iter = keywords;

    // Check if we reached the end of the format string
    bool is_optional = false;
    // std::cout << "JsArg_ParseTupleAndKeywords &info[0] = " << YELLOW << &info[0] << RESET << std::endl;

    size_t arg_position = 0;
    bool first_optional = true;
    Napi::Object optional_obj;

    while (*fmt_iter && *fmt_iter != ':') {
        // Switch to Optional arguments
        if (*fmt_iter == '|') {
            fmt_iter++;
            is_optional = true;
            if (!*fmt_iter) {
                // should throw error
                failmsg(info.Env(), "invalid format: '%s' in JsArg_ParseTupleAndKeywords unexpected end of format", format);
                continue;
            }
        }
        if (arg_position >= info.Length()) {
            if (is_optional) {
                // We've reached the end of the required arguments
                break;
            } else {
                // Not enough arguments provided
                va_end(args);
                failmsg(info.Env(),
                    "Not enough arguments provided for '%s' arg_position: %d is_optional: %s",
                    format,
                    arg_position,
                    is_optional ? "true" : "false"
                );
                return false;
            }
        }
        // Set the corresponding varg value
        // Napi::Value* arg = va_arg(args, Napi::Value*);
        // arg is now a const Napi::Value**
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
    const char* function_name = "??";//nullptr;
    while  ( *fmt_iter && *fmt_iter != ':') {
        fmt_iter++;
    }
    if (*fmt_iter == ':') {
        function_name = fmt_iter + 1;
    }
    va_end(args);
    return true;
}

Napi::Value Js_BuildValue(const Napi::CallbackInfo &info, const char *format, ...)
{
    Napi::Env env = info.Env();
    Napi::Value result;

    va_list args;
    va_start(args, format);

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
        case '(':
        case '[':
            {
                Napi::Array array = Napi::Array::New(env);
                size_t index = 0;
                while (*++format != ']' || *++format != ')')
                {
                    Napi::Value element = Js_BuildValue(info, format, args);
                    array.Set(index++, element);
                }
                result = array;
            }
            break;
        case '{':
            {
                Napi::Object object = Napi::Object::New(env);
                while (*++format != '}')
                {
                    if (*format == 's')
                    {
                        std::string key = va_arg(args, const char *);
                        ++format;
                        Napi::Value value = Js_BuildValue(info, format, args);
                        object.Set(key, value);
                    }
                }
                result = object;
            }
            break;
        default:
            result = env.Null();
            break;
        }
    }

    va_end(args);
    return result;
}