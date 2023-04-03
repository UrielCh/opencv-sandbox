
#include "comm.h"
#include <stdarg.h>

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
    } else if (*optional_start == '|') {
        is_optional = true;
    }

    int arg_position = 0;
    bool first_optional = true;
    Napi::Object optional_obj;
    while (*fmt_iter && *fmt_iter != ':') {
        // Switch to Optional arguments
        if (fmt_iter == optional_start) {
            fmt_iter++;
            is_optional = !is_optional;
            finished = !finished;
            if (!*fmt_iter) {
                // should throw error
                continue;
            }
        }

        if (arg_position >= info.Length()) {
            if (is_optional) {
                // We've reached the end of the required arguments
                break;
            } else {
                // Not enough arguments provided
                // should throw error
                va_end(args);
                return false;
            }
        }

        // Set the corresponding varg value
        Napi::Value* arg = va_arg(args, Napi::Value*);

        if (is_optional && first_optional) {
            // Handle the first optional argument as a Record<string, any> object
            optional_obj = info[arg_position].As<Napi::Object>();
            first_optional = false;
        } else if (is_optional) {
            // Get the following optional argument by name from the optional_obj
            std::string keyword = *kw_iter;
            if (optional_obj.Has(keyword)) {
                *arg = optional_obj.Get(keyword);
            } else {
                *arg = Napi::Value();
            }
            kw_iter++;
        } else {
            *arg = info[arg_position];
        }

        arg_position++;
        fmt_iter++;
    }

    // Find the function name
    const char* function_name = nullptr;
    if (*fmt_iter == ':') {
        function_name = fmt_iter + 1;
    }

    va_end(args);
    return true;
}