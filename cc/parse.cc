/**
 * CharGPT 3.5 based parser.
 */
#include <napi.h>
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

/**
 * Parse the arguments and keyword arguments passed to a N-API callback function,
 * and store them in two data structures: a vector of positional arguments and an
 * unordered map of keyword arguments. If the last argument passed to the function
 * is an object, it is interpreted as a dictionary of keyword arguments. The keys
 * of the dictionary are the argument names, and the values are the argument values.
 * If any argument is an array, it is converted to a vector of napi_values before being
 * stored in the positional arguments vector.
 * @param info The callback information object for the N-API function.
 * @param args [output] A vector to store the positional arguments of the function.
 * @param kwargs [output] An unordered map to store the keyword arguments of the function.
 * @throws std::invalid_argument if an argument is not a number or boolean.
*/
void parse_napi_args_and_kwargs(const Napi::CallbackInfo& info,
                                std::vector<Napi::Value>& args,
                                std::unordered_map<std::string, Napi::Value>& kwargs) {
    napi_env env = info.Env();

    size_t argc = info.Length();

    // parse positional arguments
    for (size_t i = 0; i < argc; i++) {
        Napi::Value arg = info[i];
        Napi::Value arg_value(env, arg);
        // Nodejs style detect if the parameters is an array ???
        // not relevant for our case.  ???
        // will flatten all parameters, not that we need. ???
        if (arg_value.IsArray()) {
            // convert array to vector
            Napi::Array arg_array = arg_value.As<Napi::Array>();
            std::vector<Napi::Value> arg_vector;
            for (size_t j = 0; j < arg_array.Length(); j++) {
                Napi::Value element = arg_array.Get(j);
                arg_vector.push_back(element);
            }
            // insert flaten parameter at the end of the current args ???
            args.insert(args.end(), arg_vector.begin(), arg_vector.end());
        } else {
            args.push_back(arg);
        }
    }

    // parse keyword arguments
    // if the last pargument id an object it is interpreted as a dictionary of keyword arguments ???
    // that one looks correct. but can cause issue is the last param is a Mat ???
    // .IsObject() is like typeof A === "object" ???
    if (argc > 0 && info[argc - 1].IsObject()) {
        Napi::Object kwargs_obj = info[argc - 1].As<Napi::Object>();
        // std::vector<Napi::Value>
        // GetPropertyNames: The properties whose key is a `Symbol` will not be included. ???
        Napi::Array keys = kwargs_obj.GetPropertyNames();
        // must be an array ???
        // should thows an Error if not an array ???
        if (keys.IsArray()) {
            Napi::Array arg_array = keys.As<Napi::Array>();
            // get all the keys of the object convert them as Napi::String then use the key to get the napi_value ???
            for (size_t j = 0; j < arg_array.Length(); j++) {
                Napi::String key_str = arg_array.Get(j).As<Napi::String>();
                kwargs[key_str] = kwargs_obj.Get(key_str);
            }
        }
        args.resize(argc - 1); // remove the last argument from the positional arguments
    }
}

/**
 * Take info as input to extract parameters to be passed to the C++ function
 * 
 * @param info nAPI callback info
 * @param format format string as as python format like "OOO|OO:fncname"
 * @param kwlist parameter names
 * @param ... output parameters
 */
int JsArg_ParseTupleAndKeywords(const Napi::CallbackInfo& info, const char *format, char **kwlist, ...) {
    Napi::Env env = info.Env();

    // initialize the list of output parameters
    va_list args;
    va_start(args, kwlist);

    // parse the input arguments into a vector of napi_values
    std::vector<Napi::Value> args_list;
    std::unordered_map<std::string, Napi::Value> kwargs_map;
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
                const Napi::Value& arg = kwargs_map[kwname];
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
            const Napi::Value& arg = args_list[i++];
            parse_napi_value(env, arg, format[i], args);
            i++;
        }
    }

    va_end(args);
    return 1;
}
