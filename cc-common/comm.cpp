
#include "comm.h"
#include <stdarg.h>
#include <iostream>

const std::string RED("\033[0;31m");
const std::string GREEN("\033[1;32m");
const std::string YELLOW("\033[1;33m");
const std::string CYAN("\033[0;36m");
const std::string MAGANTA("\033[0;35m");
const std::string RESET("\033[0m");

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
    int numKeywords = 0;
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

bool JsArg_ParseTupleAndKeywords(const Napi::CallbackInfo& info, const char* format, char** keywords, ...) {
    // Prepare to handle variable arguments
    va_list args;
    va_start(args, keywords);

    // Initialize iterators for format string and keywords
    const char* fmt_iter = format;
    char** kw_iter = keywords;

    // Find the format string's first ':' or '|' character
    const char* optional_start = std::strpbrk(format, ":|");

    // Check if we reached the end of the format string
    bool is_optional = false;
    bool finished = false;
    if (optional_start == nullptr || *optional_start == ':') {
        finished = true;
    } //else if (*optional_start == '|') {
        //is_optional = true;
    // }

    std::cout << "JsArg_ParseTupleAndKeywords &info[0] = " << YELLOW << &info[0] << RESET << std::endl;

    int arg_position = 0;
    bool first_optional = true;
    Napi::Object optional_obj;

    // std::cout << "JsArg_ParseTupleAndKeywords start is_optional:"<< is_optional << std::endl;
    while (*fmt_iter && *fmt_iter != ':') {
        // Switch to Optional arguments
        // std::cout << "JsArg_ParseTupleAndKeywords while loop " << std::endl;
        if (fmt_iter == optional_start) {
            // std::cout << "1. JsArg_ParseTupleAndKeywords fmt_iter == optional_start is_optional:" << is_optional << std::endl;
            fmt_iter++;
            is_optional = !is_optional;
            // std::cout << "2. JsArg_ParseTupleAndKeywords fmt_iter == optional_start is_optional:" << is_optional << std::endl;
            finished = !finished;
            if (!*fmt_iter) {
                // should throw error
                failmsg(info.Env(), "invalid format: '%s' in JsArg_ParseTupleAndKeywords", format);
                continue;
            }
        }

        if (arg_position >= info.Length()) {
            // std::cout << "JsArg_ParseTupleAndKeywords(arg_position >= info.Length()) is_optional:" << is_optional << std::endl;
            if (is_optional) {
                std::cout << "JsArg_ParseTupleAndKeywords is_optional BREAK" << std::endl;
                // We've reached the end of the required arguments
                break;
            } else {
                // std::cout << "JsArg_ParseTupleAndKeywords is_optional NO__________BREAK" << std::endl;
                // Not enough arguments provided
                // should throw error
                va_end(args);
                failmsg(info.Env(),
                    "Not enough arguments provided for '%s' arg_position:%d is_optional:%s",
                    format,
                    arg_position,
                    is_optional ? "true" : "false"
                );
                return false;
            }
        }

        // Set the corresponding varg value
        const Napi::Value* arg = va_arg(args, Napi::Value*);
        std::cout << "JsArg_ParseTupleAndKeywords pick arg from VA_Arg " << RED << arg << RESET << std::endl;

        if (is_optional && first_optional) {
            // Handle the first optional argument as a Record<string, any> object
            optional_obj = info[arg_position].As<Napi::Object>();
            first_optional = false;
        } else if (is_optional) {
            // Get the following optional argument by name from the optional_obj
            std::string keyword = *kw_iter;
            if (optional_obj.Has(keyword)) {
                // ???
                // *arg = optional_obj.Get(keyword);
            } else {
                // *arg = Napi::Value();
                // ???
            }
        } else {
            std::cout << "JsArg_ParseTupleAndKeywords In buggy ! " << RED <<  &info[arg_position] << RESET << std::endl;
            arg = &info[arg_position];
        }

        arg_position++;
        fmt_iter++;
        kw_iter++; // Increment kw_iter for each argument
    }

    std::cout << "JsArg_ParseTupleAndKeywords Done" << std::endl;

    // Find the function name
    const char* function_name = nullptr;
    if (*fmt_iter == ':') {
        function_name = fmt_iter + 1;
    }

    va_end(args);
    return true;
}
