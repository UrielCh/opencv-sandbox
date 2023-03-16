/**
 * CharGPT 3.5 based parser.
 */
#include <napi.h>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <stdarg.h>

template<typename T>
T parse_napi_value(const Napi::Env& env, const napi_value& value) {
    if (!value.IsNumber() && !value.IsBoolean()) {
        throw std::invalid_argument("Invalid argument type: expected number or boolean");
    }
    return static_cast<T>(Napi::Value(env, value).ToNumber());
}

void parse_napi_args_and_kwargs(const Napi::CallbackInfo& info,
                                std::vector<napi_value>& args,
                                std::unordered_map<std::string, napi_value>& kwargs) {
    napi_env env = info.Env();

    size_t argc = info.Length();

    // parse positional arguments
    for (size_t i = 0; i < argc; i++) {
        napi_value arg = info[i];
        Napi::Value arg_value(env, arg);
        if (arg_value.IsArray()) {
            // convert array to vector
            Napi::Array arg_array = arg_value.As<Napi::Array>();
            std::vector<napi_value> arg_vector;
            for (size_t j = 0; j < arg_array.Length(); j++) {
                napi_value element = arg_array.Get(j);
                arg_vector.push_back(element);
            }
            args.insert(args.end(), arg_vector.begin(), arg_vector.end());
        } else {
            args.push_back(arg);
        }
    }

    // parse keyword arguments
    if (argc > 0 && info[argc - 1].IsObject()) {
        Napi::Object kwargs_obj = info[argc - 1].As<Napi::Object>();
        std::vector<Napi::Value> keys = kwargs_obj.GetPropertyNames();

        for (const Napi::Value& key : keys) {
            std::string key_str = key.ToString().Utf8Value();
            kwargs[key_str] = kwargs_obj.Get(key);
        }
        args.resize(argc - 1); // remove the last argument from the positional arguments
    }
}

int NodeArg_ParseTupleAndKeywords(const Napi::CallbackInfo& info, const char *format, char **kwlist, ...) {
    // initialize the list of output parameters
    va_list args;
    va_start(args, kwlist);

    // parse the input arguments into a vector of napi_values
    std::vector<napi_value> args_list;
    std::unordered_map<std::string, napi_value> kwargs_map;
    parse_napi_args_and_kwargs(info, args_list, kwargs_map);

    // parse the format string and keyword list
    size_t num_args = args_list.size();
    size_t num_kwlist = sizeof(kwlist) / sizeof(kwlist[0]);
    size_t i = 0, j = 0;

    // iterate over the format string
    while (format[i] != '\0') {
        if (format[i] == '|') {
            // ignore vertical bars in format string
            i++;
        } else if (format[i] == ':') {
            // parse keyword arguments
            const char* kwname = kwlist[j++];
            if (kwargs_map.count(kwname) > 0) {
                // if keyword argument is present, parse it using the format specifier
                const napi_value& arg = kwargs_map[kwname];
                parse_napi_value(arg, format[i+1], args, args_list, j-1);
            } else {
                // if keyword argument is not present, set its value to NULL or default value
                const char* defvalue = kwlist[j++];
                if (defvalue == nullptr) {
                    va_arg(args, void*);
                } else {
                    parse_default_value(defvalue, format[i+1], args);
                }
            }
            i += 2;
        } else {
            // parse positional arguments
            if (i >= num_args) {
                // if there are not enough arguments, raise an error
                Napi::Error::New(info.Env(), "Not enough arguments").ThrowAsJavaScriptException();
                return 0;
            }
            const napi_value& arg = args_list[i++];
            parse_napi_value(arg, format[i], args, args_list, i-1);
            i++;
        }
    }

    va_end(args);
    return 1;
}
