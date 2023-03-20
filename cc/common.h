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
