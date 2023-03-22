#include "cv2.hpp"

#include "cv2_util.hpp"
#include "cv2_convert.hpp"

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

#include "./cv2_macro.hpp"
// #include "pyopencv_generated_types.h"
// #undef CVPY_TYPE
// #include "pyopencv_custom_headers.h"
// #include "pyopencv_generated_types_content.h"
// #include "pyopencv_generated_funcs.h"



// from cv2.cpp L:471
#define CVJS_MODULE(NAMESTR, NAME) \
    if (!init_submodule(m, MODULESTR NAMESTR, methods_##NAME, consts_##NAME)) \
    { \
        return false; \
    }
    #include "pyopencv_generated_modules.h"
#undef CVPY_MODULE