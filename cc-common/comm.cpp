
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

    std::cout << "cv::imreXX info[0]        = " << GREEN << &info[0] << RESET << std::endl;

    std::cout << "info ADDR &info is: " << MAGANTA << &info << RESET << " &info[0] is: " << MAGANTA << &info[0] << RESET << std::endl;
    // Prepare to handle variable arguments
    va_list args;
    va_start(args, keywords);

    // Initialize iterators for format string and keywords
    const char* fmt_iter = format;
    char** kw_iter = keywords;

    // Check if we reached the end of the format string
    bool is_optional = false;
    // std::cout << "JsArg_ParseTupleAndKeywords &info[0] = " << YELLOW << &info[0] << RESET << std::endl;

    int arg_position = 0;
    bool first_optional = true;
    Napi::Object optional_obj;

    while (*fmt_iter && *fmt_iter != ':') {
        // std::cout << "JsArg_ParseTupleAndKeywords pos = " << (fmt_iter - format) << std::endl;
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
        // std::cout << "JsArg_ParseTupleAndKeywords pick arg from VA_Arg " << RED << arg << RESET << std::endl;
        if (is_optional) {
            // if first optional eand last param and is object, then it is the optional object
            if (first_optional && info.Length() == (arg_position-1)) {
                if (info[arg_position].IsObject())
                    optional_obj = info[arg_position].As<Napi::Object>();
                first_optional = false;
            }
            if (!optional_obj) {
                // we do not have optional object source
                // *arg = info[arg_position];
                // prev obj must not be read as an optional povider.
            } else if (optional_obj.Has(*kw_iter)) {
                // *arg = optional_obj.Get(*kw_iter);
            } else {
                // leave it as null the optional value had not be provided
            }
        } else {
            // std::cout << "JsArg_ParseTupleAndKeywords Mandatory Object: &info[" << arg_position << "] = " << RED <<  &info[arg_position] << RESET << std::endl;
            // std::cout << "JsArg_ParseTupleAndKeywords Mandatory Object: &info[" << arg_position << "] = " << RED <<  &info[arg_position] << RESET << std::endl;
            // std::cout << "JsArg_ParseTupleAndKeywords Mandatory Object: &info[" << arg_position << "] = " << RED <<  info[arg_position] << RESET << std::endl;
            // std::cout << "JsArg_ParseTupleAndKeywords Mandatory Object: &info[" << arg_position << "] = " << RED <<  info[arg_position] << RESET << std::endl;
            // auto argX = &info[arg_position];
            *arg = &info[arg_position];
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
    // std::cout << "JsArg_ParseTupleAndKeywords called by " << RED << function_name << RESET << " Done and return true" << std::endl;
    return true;
}
