#include <string>
#include <napi.h>
#include <cstdarg>

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
        case '[':
            {
                Napi::Array array = Napi::Array::New(env);
                size_t index = 0;
                while (*++format != ']')
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