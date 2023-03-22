#include "cv2.hpp"

#include "opencv2/opencv_modules.hpp"
#include "opencv2/core.hpp"
#include "opencv2/core/utils/logger.hpp"

#include "jsopencv_generated_include.h"
#include "opencv2/core/types_c.h"

#include "./cv2_util.hpp"
// #include "cv2_numpy.hpp"
#include "./cv2_convert.hpp"
// #include "cv2_highgui.hpp"

using namespace cv;

typedef std::vector<uchar> vector_uchar;
typedef std::vector<char> vector_char;
typedef std::vector<int> vector_int;
typedef std::vector<float> vector_float;
typedef std::vector<double> vector_double;
typedef std::vector<size_t> vector_size_t;
typedef std::vector<Point> vector_Point;
typedef std::vector<Point2f> vector_Point2f;
typedef std::vector<Point3f> vector_Point3f;
typedef std::vector<Size> vector_Size;
typedef std::vector<Vec2f> vector_Vec2f;
typedef std::vector<Vec3f> vector_Vec3f;
typedef std::vector<Vec4f> vector_Vec4f;
typedef std::vector<Vec6f> vector_Vec6f;
typedef std::vector<Vec4i> vector_Vec4i;
typedef std::vector<Rect> vector_Rect;
typedef std::vector<Rect2d> vector_Rect2d;
typedef std::vector<RotatedRect> vector_RotatedRect;
typedef std::vector<KeyPoint> vector_KeyPoint;
typedef std::vector<Mat> vector_Mat;
typedef std::vector<std::vector<Mat> > vector_vector_Mat;
typedef std::vector<UMat> vector_UMat;
typedef std::vector<DMatch> vector_DMatch;
typedef std::vector<String> vector_String;
typedef std::vector<std::string> vector_string;
typedef std::vector<Scalar> vector_Scalar;

typedef std::vector<std::vector<char> > vector_vector_char;
typedef std::vector<std::vector<Point> > vector_vector_Point;
typedef std::vector<std::vector<Point2f> > vector_vector_Point2f;
typedef std::vector<std::vector<Point3f> > vector_vector_Point3f;
typedef std::vector<std::vector<DMatch> > vector_vector_DMatch;
typedef std::vector<std::vector<KeyPoint> > vector_vector_KeyPoint;

///////////////////////////////////////////////////////////////////////////////////////

// static int convert_to_char(PyObject *o, char *dst, const ArgInfo& info)
// {
//     std::string str;
//     if (getUnicodeString(o, str))
//     {
//         *dst = str[0];
//         return 1;
//     }
//     (*dst) = 0;
//     return failmsg("Expected single character string for argument '%s'", info.name);
// }
// 
// #ifdef __GNUC__
// #  pragma GCC diagnostic ignored "-Wunused-parameter"
// #  pragma GCC diagnostic ignored "-Wmissing-field-initializers"
// #endif
// ./cv2_macro.hpp define CVJS_TYPE
#include "./cv2_macro.hpp"
// #include "pyopencv_generated_types.h"
// #undef CVPY_TYPE
// #include "pyopencv_custom_headers.h"
#include "jsopencv_generated_types_content.h"
#include "jsopencv_generated_funcs.h"




/**
 * \brief Creates a submodule of the `root`. Missing parents submodules
 * are created as needed. If name equals to parent module name than
 * borrowed reference to parent module is returned (no reference counting
 * are done).
 * Submodule lifetime is managed by the parent module.
 * If nested submodules are created than the lifetime is managed by the
 * predecessor submodule in a list.
 *
 * \param parent_module Parent module object.
 * \param name Submodule name.
 * \return borrowed reference to the created submodule.
 *         If any of submodules can't be created than NULL is returned.
 */
// PyObject * parent_module => Napi::Env env
/*
static PyObject* createSubmodule(Napi::Env env, const std::string& name)
{
    if (!parent_module)
    {
        return PyErr_Format(PyExc_ImportError,
            "Bindings generation error. "
            "Parent module is NULL during the submodule '%s' creation",
            name.c_str()
        );
    }
    if (strEndsWith(name, '.'))
    {
        return PyErr_Format(PyExc_ImportError,
            "Bindings generation error. "
            "Submodule can't end with a dot. Got: %s", name.c_str()
        );
    }

    const std::string parent_name = PyModule_GetName(parent_module);

    /// Special case handling when caller tries to register a submodule of the parent module with
    /// the same name
    if (name == parent_name) {
        return parent_module;
    }

    if (!strStartsWith(name, parent_name))
    {
        return PyErr_Format(PyExc_ImportError,
            "Bindings generation error. "
            "Submodule name should always start with a parent module name. "
            "Parent name: %s. Submodule name: %s", parent_name.c_str(),
            name.c_str()
        );
    }

    size_t submodule_name_end = name.find('.', parent_name.size() + 1);
    /// There is no intermediate submodules in the provided name
    if (submodule_name_end == std::string::npos)
    {
        submodule_name_end = name.size();
    }

    PyObject* submodule = parent_module;

    for (size_t submodule_name_start = parent_name.size() + 1;
         submodule_name_start < name.size(); )
    {
        const std::string submodule_name = name.substr(submodule_name_start,
                                                       submodule_name_end - submodule_name_start);

        const std::string full_submodule_name = name.substr(0, submodule_name_end);


        PyObject* parent_module_dict = Napi::Object::New(submodule);
        /// If submodule already exists it can be found in the parent module dictionary,
        /// otherwise it should be added to it.
        submodule = PyDict_GetItemString(parent_module_dict,
                                         submodule_name.c_str());
        if (!submodule)
        {
            /// Populates global modules dictionary and returns borrowed reference to it
            submodule = PyImport_AddModule(full_submodule_name.c_str());
            if (!submodule)
            {
                /// Return `PyImport_AddModule` NULL with an exception set on failure.
                return NULL;
            }
            /// Populates parent module dictionary. Submodule lifetime should be managed
            /// by the global modules dictionary and parent module dictionary, so Py_DECREF after
            /// successfull call to the `PyDict_SetItemString` is redundant.
            if (PyDict_SetItemString(parent_module_dict, submodule_name.c_str(), submodule) < 0) {
                return PyErr_Format(PyExc_ImportError,
                    "Can't register a submodule '%s' (full name: '%s')",
                    submodule_name.c_str(), full_submodule_name.c_str()
                );
            }
        }

        submodule_name_start = submodule_name_end + 1;

        submodule_name_end = name.find('.', submodule_name_start);
        if (submodule_name_end == std::string::npos) {
            submodule_name_end = name.size();
        }
    }
    return submodule;
}
*/
// PyObject * root => Napi::Env env
static bool init_submodule(Napi::Env env, const char * name, PyMethodDef * methods, ConstDef * consts)
{
    // traverse and create nested submodules
    Napi::Value submodule = createSubmodule(env, name);
    if (!submodule)
    {
        return false;
    }
    // populate module's dict
    Napi::Object d = Napi::Object::New(env); // submodule
    for (PyMethodDef * m = methods; m->ml_name != NULL; ++m)
    {
        PyObject * method_obj = PyCFunction_NewEx(m, NULL, NULL);
        if (PyDict_SetItemString(d, m->ml_name, method_obj) < 0)
        {
            PyErr_Format(PyExc_ImportError,
                "Can't register function %s in module: %s", m->ml_name, name
            );
            Py_CLEAR(method_obj);
            return false;
        }
        // Py_DECREF(method_obj);
    }
    for (ConstDef * c = consts; c->name != NULL; ++c)
    {
        PyObject* const_obj = PyLong_FromLongLong(c->val);
        if (PyDict_SetItemString(d, c->name, const_obj) < 0)
        {
            PyErr_Format(PyExc_ImportError,
                "Can't register constant %s in module %s", c->name, name
            );
            // Py_CLEAR(const_obj);
            return false;
        }
        // Py_DECREF(const_obj);
    }
    return true;
}

// PyObject * m
static bool init_body(Napi::Env env, Napi::Object exports) {
// from cv2.cpp L:471
//#define CVJS_MODULE(NAMESTR, NAME) \
//    if (!init_submodule(m, MODULESTR NAMESTR, methods_##NAME, consts_##NAME)) \
//    { \
//        return false; \
//    }
//    #include "jsopencv_generated_modules.h"
//#undef CVPY_MODULE
//
// #define CVPY_TYPE(EXPORT_NAME, CLASS_ID, _1, _2, BASE, CONSTRUCTOR, SCOPE) CVPY_TYPE_INIT_STATIC(EXPORT_NAME, CLASS_ID, return false, BASE, CONSTRUCTOR, SCOPE)
//     PyTypeObject * pyopencv_NoBase_TypePtr = NULL;
// #endif
//     #include "pyopencv_generated_types.h"
// #undef CVPY_TYPE

    // PyObject* d = PyModule_GetDict(m);
    Napi::Object d = Napi::Object::New(env);
    auto version_obj = Napi::String::New(env, CV_VERSION);
    if (!d.Set("__version__", version_obj)) {
        Napi::TypeError::New(env, "Can't update module version").ThrowAsJavaScriptException();
        // Py_CLEAR(version_obj);
        return false;
    }
    Py_DECREF(version_obj);

    Napi::Object opencv_error_dict = Napi::Object::New(env);
    opencv_error_dict.Set("file", env.Undefined());
    opencv_error_dict.Set("func", env.Undefined());
    opencv_error_dict.Set("line", env.Undefined());
    opencv_error_dict.Set("code", env.Undefined());
    opencv_error_dict.Set("msg", env.Undefined());
    opencv_error_dict.Set("err", env.Undefined());
    // opencv_error = PyErr_NewException((char*)MODULESTR".error", NULL, opencv_error_dict);
    // Py_DECREF(opencv_error_dict);
    d.Set("error", opencv_error);


#define PUBLISH_(I, var_name, type_obj) \
    if (!d.Set(var_name, Napi::Number::New(env, I))) \
    { \
        Napi::TypeError::New(env, "Can't register var_name constant").ThrowAsJavaScriptException(); \
        return false; \
    }

#define PUBLISH(I) PUBLISH_(I, #I, I ## _obj)

    PUBLISH(CV_8U);
    PUBLISH(CV_8UC1);
    PUBLISH(CV_8UC2);
    PUBLISH(CV_8UC3);
    PUBLISH(CV_8UC4);
    PUBLISH(CV_8S);
    PUBLISH(CV_8SC1);
    PUBLISH(CV_8SC2);
    PUBLISH(CV_8SC3);
    PUBLISH(CV_8SC4);
    PUBLISH(CV_16U);
    PUBLISH(CV_16UC1);
    PUBLISH(CV_16UC2);
    PUBLISH(CV_16UC3);
    PUBLISH(CV_16UC4);
    PUBLISH(CV_16S);
    PUBLISH(CV_16SC1);
    PUBLISH(CV_16SC2);
    PUBLISH(CV_16SC3);
    PUBLISH(CV_16SC4);
    PUBLISH(CV_32S);
    PUBLISH(CV_32SC1);
    PUBLISH(CV_32SC2);
    PUBLISH(CV_32SC3);
    PUBLISH(CV_32SC4);
    PUBLISH(CV_32F);
    PUBLISH(CV_32FC1);
    PUBLISH(CV_32FC2);
    PUBLISH(CV_32FC3);
    PUBLISH(CV_32FC4);
    PUBLISH(CV_64F);
    PUBLISH(CV_64FC1);
    PUBLISH(CV_64FC2);
    PUBLISH(CV_64FC3);
    PUBLISH(CV_64FC4);
#undef PUBLISH_
#undef PUBLISH

    return true;
}