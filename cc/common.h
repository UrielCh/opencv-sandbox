#ifndef Js_LIMITED_API
#define Js_LIMITED_API

#include <vector>

// #define JsAPI_FUNC(RTYPE) RTYPE
// #define JsAPI_DATA(RTYPE) extern RTYPE
// #define JsMODINIT_FUNC void
// #define Js_ssize_t int
// #define JsVarObject_HEAD_INIT(type, size) JsObject_HEAD_INIT(type) size,
// #define JsObject_HEAD_INIT(type) _JsObject_HEAD_INIT(type, 0)
// #define _JsObject_HEAD_INIT(type, size) 0, type, size,
// #define JsTypeObject JsTypeObject
// #define JsVarObject JsVarObject

typedef void (*JsObject)(void);

/**
 * @brief Parse arguments in a tuple and keywords dictionary and convert them to C values.
 * 
 * @param args A JsObject* pointing to a Nodejs tuple containing the positional arguments to be parsed. If there are no positional arguments, this should be NULL.
 * @param keywords A JsObject* pointing to a Nodejs dictionary containing the keyword arguments to be parsed. If there are no keyword arguments, this should be NULL.
 * @param format A const char* specifying the format string that describes the expected types of the arguments.
 * @param kwlist pointing to an array of char* strings representing the names of the keyword arguments.
 * @param ... A variable number of pointers to C variables, where the parsed arguments will be stored. The number of pointers must match the number of items expected by the format string.
 * @return int The return value of JsArg_ParseTupleAndKeywords is an integer that indicates success (1) or failure (0). If parsing fails, a Nodejs exception is set and the function returns 0. If parsing succeeds, the function returns 1 and the parsed values are stored in the C variables passed as arguments.
 * 
 * Note that JsArg_ParseTupleAndKeywords can raise a TypeError or a ValueError exception if the format string is incorrect or the types of the arguments do not match the format string.
 */
bool JsArg_ParseTupleAndKeywords(const Napi::CallbackInfo &info, const char *format, char **keywords, ...);


class ArgInfo
{
public:
    const char* name;
    bool outputarg;
    // more fields may be added if necessary

    ArgInfo(const char* name_, bool outputarg_) : name(name_), outputarg(outputarg_) {}

private:
    ArgInfo(const ArgInfo&) = delete;
    ArgInfo& operator=(const ArgInfo&) = delete;
};


// exception-safe jsopencv_to
template<typename _Tp> static
bool jsopencv_to_safe(JsObject* obj, _Tp& value, const ArgInfo& info)
{
    return false;
    // try
    // {
    //     return jsopencv_to(obj, value, info);
    // }
    // catch (const std::exception &e)
    // {
    //     JsErr_SetString(opencv_error, cv::format("Conversion error: %s, what: %s", info.name, e.what()).c_str());
    //     return false;
    // }
    // catch (...)
    // {
    //     JsErr_SetString(opencv_error, cv::format("Conversion error: %s", info.name).c_str());
    //     return false;
    // }
}


// template <typename Tp>
// JsObject* jsopencv_from(const std::vector<Tp>& value)
// {
//     return jsopencvVecConverter<Tp>::from(value);
// }

#define CV_JS_FROM_ENUM(TYPE)                                                                         \
template<>                                                                                            \
JsObject* jsopencv_from(const TYPE& src)                                                              \
{                                                                                                     \
    return jsopencv_from(static_cast<int>(src));                         \
}

template<typename... Ts>
JsObject* jsopencv_from(const std::tuple<Ts...>& cpp_tuple)
{
    size_t size = sizeof...(Ts);
    JsObject* js_tuple = JsTuple_New(size);
    convert_to_nodejs_tuple(cpp_tuple, js_tuple);
    size_t actual_size = JsTuple_Size(js_tuple);

    if (actual_size < size)
    {
        Js_DECREF(js_tuple);
        return NULL;
    }

    return js_tuple;
}

// enum TYPE
// {
//     TYPE_GENERAL = 0,   // OpenCV API function, e.g. exported function
//     TYPE_MARKER,        // Information marker
//     TYPE_WRAPPER,       // Wrapper function for implementation
//     TYPE_FUN,           // Simple function call
// };
// 
// template<>                                                                                            \
// JsObject* jsopencv_from(const TYPE& src)                                                              \
// {                                                                                                     \
//     return jsopencv_from(static_cast<int>(src));                         \
// }

/**
 * @brief Set the error indicator to a new exception instance.
 * 
 * @param type A JsObject* pointing to a Nodejs exception type object, such as JsExc_TypeError or JsExc_ValueError. This is the type of the exception that will be raised.
 * @param message A const char* representing the error message to be associated with the exception. This message will be displayed in the traceback when the exception is raised.
 * 
 * JsErr_SetString sets the current Nodejs exception to an instance of the exception type passed as the first argument, with the error message passed as the second argument. If an exception is already set, JsErr_SetString will not overwrite it. Instead, it will print a warning message to the console and leave the existing exception unchanged.
 */
void JsErr_SetString(JsObject *type, const char *message) {
    return;
}

/**
 * @brief 
 * 
 * @param format A const char* representing the format string that describes the Nodejs object(s) to be constructed. This string specifies the types and arrangement of the elements in the tuple or dictionary to be constructed. The format string is similar to the format string used by the printf function in C, with each format specifier corresponding to a different type of Nodejs object. For example, "s" corresponds to a C string, "i" to an integer, and "f" to a floating-point number.
 * @param ... A variable number of C values representing the elements to be included in the tuple or dictionary. The number and types of these arguments must match the format string.
 * @return JsObject* 
 * 
 * Js_BuildValue creates a new Nodejs object from the values passed as arguments, according to the format string specified in the first argument. The function returns a JsObject* pointer to the new object. If the format string specifies a tuple, Js_BuildValue returns a tuple object. If the format string specifies a dictionary, Js_BuildValue returns a dictionary object.
 * 
 * If an error occurs during object creation, Js_BuildValue returns NULL and sets an appropriate Nodejs exception.
 */
JsObject* Js_BuildValue(const char* format, ...) {
    return NULL;
}

/**
 * @brief 
 * 
 * @param The first argument (JsObject*) is a pointer to the Nodejs object that represents the module or instance that the function is being called on. For module-level functions, this argument will be NULL.
 * @param The second argument (JsObject*) is a pointer to the Nodejs tuple that contains the arguments passed to the function.
 * 
 * The JsCFunction type is a function pointer type that is used as the function signature for C functions that are intended to be called from Nodejs. The JsCFunction signature is a standard interface used by the Nodejs interpreter to call C functions. A C function that conforms to this signature can be registered as a Nodejs function using the JsMethodDef structure and made available to Nodejs code as part of a Nodejs extension module.
 * 
 * The return value of a JsCFunction is a new reference to a Nodejs object that represents the return value of the function. If the function encounters an error, it should set an appropriate exception and return NULL.
 */
typedef JsObject *(*JsCFunction)(JsObject *, JsObject *);

/**
 * @brief structs are typically organized into arrays that are passed to the JsModule_Create function to create a new Nodejs module. When a Nodejs module is loaded, the module's methods and functions are made available to Nodejs code, and can be called like any other Nodejs function.
 * In C, JsMethodDef is a struct defined in the Nodejs C API that represents a single method in a Nodejs module or extension module. The struct is used to define the name, arguments, and implementation of a Nodejs function that can be called from Nodejs code.
 * 
 */
typedef struct JsMethodDef {
    // A const char* representing the name of the method.
    const char *ml_name; /* Method name */
    // A JsCFunction function pointer representing the implementation of the method.
    JsCFunction ml_meth; /* Method implementation */
    // An integer representing the method flags. These flags indicate how the method should be called and can be a combination of the following constants:
    // METH_VARARGS: The method takes a variable number of arguments.
    // METH_KEYWORDS: The method takes keyword arguments.
    // METH_NOARGS: The method takes no arguments.
    // METH_O: The method takes a single object argument.
    // METH_STATIC: The method is a static method and does not take a self argument.
    // METH_CLASS: The method is a class method and takes the class as the first argument.
    int ml_flags; /* Flags indicating how the method should be called */
    // A const char* representing the documentation string for the method.
    const char *ml_doc; /* Method documentation string */
} JsMethodDef;


#define JsExc_TypeError "error"

#define Js_RETURN_NONE return Js_BuildValue("")

#endif
