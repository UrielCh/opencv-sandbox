#ifndef Py_LIMITED_API
#define Py_LIMITED_API

#include <vector>

// #define PyAPI_FUNC(RTYPE) RTYPE
// #define PyAPI_DATA(RTYPE) extern RTYPE
// #define PyMODINIT_FUNC void
// #define Py_ssize_t int
// #define PyVarObject_HEAD_INIT(type, size) PyObject_HEAD_INIT(type) size,
// #define PyObject_HEAD_INIT(type) _PyObject_HEAD_INIT(type, 0)
// #define _PyObject_HEAD_INIT(type, size) 0, type, size,
// #define PyTypeObject PyTypeObject
// #define PyVarObject PyVarObject

typedef void (*PyObject)(void);

/**
 * @brief Parse arguments in a tuple and keywords dictionary and convert them to C values.
 * 
 * @param args A PyObject* pointing to a Python tuple containing the positional arguments to be parsed. If there are no positional arguments, this should be NULL.
 * @param keywords A PyObject* pointing to a Python dictionary containing the keyword arguments to be parsed. If there are no keyword arguments, this should be NULL.
 * @param format A const char* specifying the format string that describes the expected types of the arguments.
 * @param kwlist pointing to an array of char* strings representing the names of the keyword arguments.
 * @param ... A variable number of pointers to C variables, where the parsed arguments will be stored. The number of pointers must match the number of items expected by the format string.
 * @return int The return value of PyArg_ParseTupleAndKeywords is an integer that indicates success (1) or failure (0). If parsing fails, a Python exception is set and the function returns 0. If parsing succeeds, the function returns 1 and the parsed values are stored in the C variables passed as arguments.
 * 
 * Note that PyArg_ParseTupleAndKeywords can raise a TypeError or a ValueError exception if the format string is incorrect or the types of the arguments do not match the format string.
 */
int PyArg_ParseTupleAndKeywords(PyObject *args, PyObject *keywords, const char *format, char **kwlist, ...) {
    return 0;
}


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


// exception-safe pyopencv_to
template<typename _Tp> static
bool pyopencv_to_safe(PyObject* obj, _Tp& value, const ArgInfo& info)
{
    return false;
    // try
    // {
    //     return pyopencv_to(obj, value, info);
    // }
    // catch (const std::exception &e)
    // {
    //     PyErr_SetString(opencv_error, cv::format("Conversion error: %s, what: %s", info.name, e.what()).c_str());
    //     return false;
    // }
    // catch (...)
    // {
    //     PyErr_SetString(opencv_error, cv::format("Conversion error: %s", info.name).c_str());
    //     return false;
    // }
}


// template <typename Tp>
// PyObject* pyopencv_from(const std::vector<Tp>& value)
// {
//     return pyopencvVecConverter<Tp>::from(value);
// }

#define CV_PY_FROM_ENUM(TYPE)                                                                         \
template<>                                                                                            \
PyObject* pyopencv_from(const TYPE& src)                                                              \
{                                                                                                     \
    return pyopencv_from(static_cast<int>(src));                         \
}

template<typename... Ts>
PyObject* pyopencv_from(const std::tuple<Ts...>& cpp_tuple)
{
    size_t size = sizeof...(Ts);
    PyObject* py_tuple = PyTuple_New(size);
    convert_to_python_tuple(cpp_tuple, py_tuple);
    size_t actual_size = PyTuple_Size(py_tuple);

    if (actual_size < size)
    {
        Py_DECREF(py_tuple);
        return NULL;
    }

    return py_tuple;
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
// PyObject* pyopencv_from(const TYPE& src)                                                              \
// {                                                                                                     \
//     return pyopencv_from(static_cast<int>(src));                         \
// }

/**
 * @brief Set the error indicator to a new exception instance.
 * 
 * @param type A PyObject* pointing to a Python exception type object, such as PyExc_TypeError or PyExc_ValueError. This is the type of the exception that will be raised.
 * @param message A const char* representing the error message to be associated with the exception. This message will be displayed in the traceback when the exception is raised.
 * 
 * PyErr_SetString sets the current Python exception to an instance of the exception type passed as the first argument, with the error message passed as the second argument. If an exception is already set, PyErr_SetString will not overwrite it. Instead, it will print a warning message to the console and leave the existing exception unchanged.
 */
void PyErr_SetString(PyObject *type, const char *message) {
    return;
}

/**
 * @brief 
 * 
 * @param format A const char* representing the format string that describes the Python object(s) to be constructed. This string specifies the types and arrangement of the elements in the tuple or dictionary to be constructed. The format string is similar to the format string used by the printf function in C, with each format specifier corresponding to a different type of Python object. For example, "s" corresponds to a C string, "i" to an integer, and "f" to a floating-point number.
 * @param ... A variable number of C values representing the elements to be included in the tuple or dictionary. The number and types of these arguments must match the format string.
 * @return PyObject* 
 * 
 * Py_BuildValue creates a new Python object from the values passed as arguments, according to the format string specified in the first argument. The function returns a PyObject* pointer to the new object. If the format string specifies a tuple, Py_BuildValue returns a tuple object. If the format string specifies a dictionary, Py_BuildValue returns a dictionary object.
 * 
 * If an error occurs during object creation, Py_BuildValue returns NULL and sets an appropriate Python exception.
 */
PyObject* Py_BuildValue(const char* format, ...) {
    return NULL;
}

/**
 * @brief 
 * 
 * @param The first argument (PyObject*) is a pointer to the Python object that represents the module or instance that the function is being called on. For module-level functions, this argument will be NULL.
 * @param The second argument (PyObject*) is a pointer to the Python tuple that contains the arguments passed to the function.
 * 
 * The PyCFunction type is a function pointer type that is used as the function signature for C functions that are intended to be called from Python. The PyCFunction signature is a standard interface used by the Python interpreter to call C functions. A C function that conforms to this signature can be registered as a Python function using the PyMethodDef structure and made available to Python code as part of a Python extension module.
 * 
 * The return value of a PyCFunction is a new reference to a Python object that represents the return value of the function. If the function encounters an error, it should set an appropriate exception and return NULL.
 */
typedef PyObject *(*PyCFunction)(PyObject *, PyObject *);

/**
 * @brief structs are typically organized into arrays that are passed to the PyModule_Create function to create a new Python module. When a Python module is loaded, the module's methods and functions are made available to Python code, and can be called like any other Python function.
 * In C, PyMethodDef is a struct defined in the Python C API that represents a single method in a Python module or extension module. The struct is used to define the name, arguments, and implementation of a Python function that can be called from Python code.
 * 
 */
typedef struct PyMethodDef {
    // A const char* representing the name of the method.
    const char *ml_name; /* Method name */
    // A PyCFunction function pointer representing the implementation of the method.
    PyCFunction ml_meth; /* Method implementation */
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
} PyMethodDef;


#define PyExc_TypeError "error"

#define Py_RETURN_NONE return Py_BuildValue("")

#endif
