#ifndef __COMMON_CV2__H__
#define __COMMON_CV2__H__
#include "js_as_py.h"
// #include "cv2.hpp"
#include <opencv2/core.hpp>
#include <opencv2/core/utils/tls.hpp>
#include "cv2_util.h"
/**
 * @brief common deps having deps to openCV
 * 
 */
// originaly contains in cv2.hpp
typedef std::vector<uchar> vector_uchar;
typedef std::vector<char> vector_char;
typedef std::vector<int> vector_int;
typedef std::vector<float> vector_float;
typedef std::vector<double> vector_double;
typedef std::vector<size_t> vector_size_t;
typedef std::vector<cv::Point> vector_Point;
typedef std::vector<cv::Point2f> vector_Point2f;
typedef std::vector<cv::Point3f> vector_Point3f;
typedef std::vector<cv::Size> vector_Size;
typedef std::vector<cv::Vec2f> vector_Vec2f;
typedef std::vector<cv::Vec3f> vector_Vec3f;
typedef std::vector<cv::Vec4f> vector_Vec4f;
typedef std::vector<cv::Vec6f> vector_Vec6f;
typedef std::vector<cv::Vec4i> vector_Vec4i;
typedef std::vector<cv::Rect> vector_Rect;
typedef std::vector<cv::Rect2d> vector_Rect2d;
typedef std::vector<cv::RotatedRect> vector_RotatedRect;
typedef std::vector<cv::KeyPoint> vector_KeyPoint;
typedef std::vector<cv::Mat> vector_Mat;
typedef std::vector<std::vector<cv::Mat> > vector_vector_Mat;
typedef std::vector<cv::UMat> vector_UMat;
typedef std::vector<cv::DMatch> vector_DMatch;
typedef std::vector<cv::String> vector_String;
typedef std::vector<std::string> vector_string;
typedef std::vector<cv::Scalar> vector_Scalar;

typedef std::vector<std::vector<char> > vector_vector_char;
typedef std::vector<std::vector<cv::Point> > vector_vector_Point;
typedef std::vector<std::vector<cv::Point2f> > vector_vector_Point2f;
typedef std::vector<std::vector<cv::Point3f> > vector_vector_Point3f;
typedef std::vector<std::vector<cv::DMatch> > vector_vector_DMatch;
typedef std::vector<std::vector<cv::KeyPoint> > vector_vector_KeyPoint;


#endif