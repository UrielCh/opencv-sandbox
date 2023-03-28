#ifndef __JSOPENCV_GENERATED_TYPES_H__
#define __JSOPENCV_GENERATED_TYPES_H__
#include "../node/cv2_macro.hpp"
#include "../node/js_as_py.hpp"

#include <napi.h>
#include <../node/js_as_py.hpp>
#include <../node/cv2_convert.hpp>
#include <node/cv2.hpp>
#include <node/cv2_util.hpp>

template <typename _Tp>
using Ptr = std::shared_ptr<_Tp>; // In ideal world it should look like this, but we need some compatibility workarounds below



///////////////////

struct jsopencv_Algorithm_t
{
    Napi::Value ob_base;
    Ptr<cv::Algorithm> v;
};
static Napi::Value jsopencv_Algorithm_TypeXXX = {
    PyVarObject_HEAD_INIT(&PyType_Type) 0,
    "cv2.Algorithm",
    sizeof(jsopencv_Algorithm_t),
};
static Napi::Value *jsopencv_Algorithm_TypePtr = &jsopencv_Algorithm_TypeXXX;
static bool jsopencv_Algorithm_getp(Napi::Value *self, Ptr<cv::Algorithm> *&dst)
{
    if (JsObject_TypeCheck(self, jsopencv_Algorithm_TypePtr))
    {
        dst = &(((jsopencv_Algorithm_t *)self)->v);
        return true;
    }
    return false;
}
static Napi::Value *jsopencv_Algorithm_Instance(const Ptr<cv::Algorithm> &r)
{
    jsopencv_Algorithm_t *m = PyObject_NEW(jsopencv_Algorithm_t, jsopencv_Algorithm_TypePtr);
    new (&(m->v)) Ptr<cv::Algorithm>(r);
    return (Napi::Value *)m;
}
static void jsopencv_Algorithm_dealloc(Napi::Value *self)
{
    ((jsopencv_Algorithm_t *)self)->v.Ptr<cv::Algorithm>::~Ptr();
    PyObject_Del(self);
}
static Napi::Value *jsopencv_Algorithm_repr(Napi::Value *self)
{
    char str[1000];
    snprintf(str, sizeof(str), "< cv2.Algorithm %p>",
             self);
    return JsString_FromString(self->Env(), str);
}


///////////////////

struct jsopencv_AsyncArray_t
{
    Napi::Value ob_base;
    Ptr<cv::AsyncArray> v;
};
static Napi::Value jsopencv_AsyncArray_TypeXXX = {
    JsVarObject_HEAD_INIT(&PyType_Type) 0,
    "cv2.AsyncArray",
    sizeof(jsopencv_AsyncArray_t),
};
static Napi::Value *jsopencv_AsyncArray_TypePtr = &jsopencv_AsyncArray_TypeXXX;
// Getter
static bool jsopencv_AsyncArray_getp(Napi::Value *self, Ptr<cv::AsyncArray> *&dst)
{
    if (JsObject_TypeCheck(self, jsopencv_AsyncArray_TypePtr))
    {
        dst = &(((jsopencv_AsyncArray_t *)self)->v);
        return true;
    }
    return false;
}
// allocate
static Napi::Value *jsopencv_AsyncArray_Instance(const Ptr<cv::AsyncArray> &r)
{
    jsopencv_AsyncArray_t *m = PyObject_NEW(jsopencv_AsyncArray_t, jsopencv_AsyncArray_TypePtr);
    new (&(m->v)) Ptr<cv::AsyncArray>(r);
    return (Napi::Value *)m;
}
static void jsopencv_AsyncArray_dealloc(Napi::Value *self)
{
    ((jsopencv_AsyncArray_t *)self)->v.Ptr<cv::AsyncArray>::~Ptr();
    PyObject_Del(self);
}
// implement toString()
static Napi::Value *jsopencv_AsyncArray_repr(Napi::Value *self)
{
    char str[1000];
    snprintf(str, sizeof(str), "< cv2.AsyncArray %p>", self);
    return JsString_FromString(self->Env(), str);
}


///////////////////


CVJS_TYPE(ClassWithKeywordProperties, utils_ClassWithKeywordProperties, cv::utils::ClassWithKeywordProperties, ClassWithKeywordProperties, NoBase, jsopencv_cv_utils_utils_ClassWithKeywordProperties_ClassWithKeywordProperties, ".utils");
CVJS_TYPE(ExportClassName, utils_nested_OriginalClassName, Ptr<cv::utils::nested::OriginalClassName>, Ptr, NoBase, 0, ".utils.nested");
CVJS_TYPE(Params, utils_nested_OriginalClassName_Params, cv::utils::nested::OriginalClassName::Params, Params, NoBase, jsopencv_cv_utils_nested_utils_nested_OriginalClassName_Params_OriginalClassName_Params, ".utils.nested.ExportClassName");
CVJS_TYPE(GpuMat, cuda_GpuMat, Ptr<cv::cuda::GpuMat>, Ptr, NoBase, jsopencv_cv_cuda_cuda_GpuMat_GpuMat, ".cuda");
CVJS_TYPE(Allocator, cuda_GpuMat_Allocator, Ptr<cv::cuda::GpuMat::Allocator>, Ptr, NoBase, 0, ".cuda.GpuMat");
CVJS_TYPE(GpuData, cuda_GpuData, Ptr<cv::cuda::GpuData>, Ptr, NoBase, 0, ".cuda");
CVJS_TYPE(GpuMatND, cuda_GpuMatND, Ptr<cv::cuda::GpuMatND>, Ptr, NoBase, 0, ".cuda");
CVJS_TYPE(BufferPool, cuda_BufferPool, Ptr<cv::cuda::BufferPool>, Ptr, NoBase, jsopencv_cv_cuda_cuda_BufferPool_BufferPool, ".cuda");
CVJS_TYPE(HostMem, cuda_HostMem, Ptr<cv::cuda::HostMem>, Ptr, NoBase, jsopencv_cv_cuda_cuda_HostMem_HostMem, ".cuda");
CVJS_TYPE(Stream, cuda_Stream, Ptr<cv::cuda::Stream>, Ptr, NoBase, jsopencv_cv_cuda_cuda_Stream_Stream, ".cuda");
CVJS_TYPE(Event, cuda_Event, Ptr<cv::cuda::Event>, Ptr, NoBase, jsopencv_cv_cuda_cuda_Event_Event, ".cuda");
CVJS_TYPE(TargetArchs, cuda_TargetArchs, Ptr<cv::cuda::TargetArchs>, Ptr, NoBase, 0, ".cuda");
CVJS_TYPE(DeviceInfo, cuda_DeviceInfo, Ptr<cv::cuda::DeviceInfo>, Ptr, NoBase, jsopencv_cv_cuda_cuda_DeviceInfo_DeviceInfo, ".cuda");
CVJS_TYPE(Device, ocl_Device, cv::ocl::Device, Device, NoBase, jsopencv_cv_ocl_ocl_Device_Device, ".ocl");
CVJS_TYPE(OpenCLExecutionContext, ocl_OpenCLExecutionContext, Ptr<cv::ocl::OpenCLExecutionContext>, Ptr, NoBase, 0, ".ocl");
CVJS_TYPE(FileStorage, FileStorage, Ptr<cv::FileStorage>, Ptr, NoBase, jsopencv_cv_FileStorage_FileStorage, "");
CVJS_TYPE(FileNode, FileNode, cv::FileNode, FileNode, NoBase, jsopencv_cv_FileNode_FileNode, "");
CVJS_TYPE(KeyPoint, KeyPoint, cv::KeyPoint, KeyPoint, NoBase, jsopencv_cv_KeyPoint_KeyPoint, "");
CVJS_TYPE(DMatch, DMatch, cv::DMatch, DMatch, NoBase, jsopencv_cv_DMatch_DMatch, "");
CVJS_TYPE(TickMeter, TickMeter, Ptr<cv::TickMeter>, Ptr, NoBase, jsopencv_cv_TickMeter_TickMeter, "");
CVJS_TYPE(UMat, UMat, Ptr<cv::UMat>, Ptr, NoBase, jsopencv_cv_UMat_UMat, "");
CVJS_TYPE(Index, flann_Index, Ptr<cv::flann::Index>, Ptr, NoBase, jsopencv_cv_flann_flann_Index_Index, ".flann");
CVJS_TYPE(GeneralizedHough, GeneralizedHough, Ptr<cv::GeneralizedHough>, Ptr, Algorithm, 0, "");
CVJS_TYPE(GeneralizedHoughBallard, GeneralizedHoughBallard, Ptr<cv::GeneralizedHoughBallard>, Ptr, GeneralizedHough, 0, "");
CVJS_TYPE(GeneralizedHoughGuil, GeneralizedHoughGuil, Ptr<cv::GeneralizedHoughGuil>, Ptr, GeneralizedHough, 0, "");
CVJS_TYPE(CLAHE, CLAHE, Ptr<cv::CLAHE>, Ptr, Algorithm, 0, "");
CVJS_TYPE(Subdiv2D, Subdiv2D, Ptr<cv::Subdiv2D>, Ptr, NoBase, jsopencv_cv_Subdiv2D_Subdiv2D, "");
CVJS_TYPE(LineSegmentDetector, LineSegmentDetector, Ptr<cv::LineSegmentDetector>, Ptr, Algorithm, 0, "");
CVJS_TYPE(IntelligentScissorsMB, segmentation_IntelligentScissorsMB, cv::segmentation::IntelligentScissorsMB, IntelligentScissorsMB, NoBase, jsopencv_cv_segmentation_segmentation_IntelligentScissorsMB_IntelligentScissorsMB, ".segmentation");
CVJS_TYPE(ParamGrid, ml_ParamGrid, Ptr<cv::ml::ParamGrid>, Ptr, NoBase, 0, ".ml");
CVJS_TYPE(TrainData, ml_TrainData, Ptr<cv::ml::TrainData>, Ptr, NoBase, 0, ".ml");
CVJS_TYPE(StatModel, ml_StatModel, Ptr<cv::ml::StatModel>, Ptr, Algorithm, 0, ".ml");
CVJS_TYPE(NormalBayesClassifier, ml_NormalBayesClassifier, Ptr<cv::ml::NormalBayesClassifier>, Ptr, ml_StatModel, 0, ".ml");
CVJS_TYPE(KNearest, ml_KNearest, Ptr<cv::ml::KNearest>, Ptr, ml_StatModel, 0, ".ml");
CVJS_TYPE(SVM, ml_SVM, Ptr<cv::ml::SVM>, Ptr, ml_StatModel, 0, ".ml");
CVJS_TYPE(EM, ml_EM, Ptr<cv::ml::EM>, Ptr, ml_StatModel, 0, ".ml");
CVJS_TYPE(DTrees, ml_DTrees, Ptr<cv::ml::DTrees>, Ptr, ml_StatModel, 0, ".ml");
CVJS_TYPE(RTrees, ml_RTrees, Ptr<cv::ml::RTrees>, Ptr, ml_DTrees, 0, ".ml");
CVJS_TYPE(Boost, ml_Boost, Ptr<cv::ml::Boost>, Ptr, ml_DTrees, 0, ".ml");
CVJS_TYPE(ANN_MLP, ml_ANN_MLP, Ptr<cv::ml::ANN_MLP>, Ptr, ml_StatModel, 0, ".ml");
CVJS_TYPE(LogisticRegression, ml_LogisticRegression, Ptr<cv::ml::LogisticRegression>, Ptr, ml_StatModel, 0, ".ml");
CVJS_TYPE(SVMSGD, ml_SVMSGD, Ptr<cv::ml::SVMSGD>, Ptr, ml_StatModel, 0, ".ml");
CVJS_TYPE(Tonemap, Tonemap, Ptr<cv::Tonemap>, Ptr, Algorithm, 0, "");
CVJS_TYPE(TonemapDrago, TonemapDrago, Ptr<cv::TonemapDrago>, Ptr, Tonemap, 0, "");
CVJS_TYPE(TonemapReinhard, TonemapReinhard, Ptr<cv::TonemapReinhard>, Ptr, Tonemap, 0, "");
CVJS_TYPE(TonemapMantiuk, TonemapMantiuk, Ptr<cv::TonemapMantiuk>, Ptr, Tonemap, 0, "");
CVJS_TYPE(AlignExposures, AlignExposures, Ptr<cv::AlignExposures>, Ptr, Algorithm, 0, "");
CVJS_TYPE(AlignMTB, AlignMTB, Ptr<cv::AlignMTB>, Ptr, AlignExposures, 0, "");
CVJS_TYPE(CalibrateCRF, CalibrateCRF, Ptr<cv::CalibrateCRF>, Ptr, Algorithm, 0, "");
CVJS_TYPE(CalibrateDebevec, CalibrateDebevec, Ptr<cv::CalibrateDebevec>, Ptr, CalibrateCRF, 0, "");
CVJS_TYPE(CalibrateRobertson, CalibrateRobertson, Ptr<cv::CalibrateRobertson>, Ptr, CalibrateCRF, 0, "");
CVJS_TYPE(MergeExposures, MergeExposures, Ptr<cv::MergeExposures>, Ptr, Algorithm, 0, "");
CVJS_TYPE(MergeDebevec, MergeDebevec, Ptr<cv::MergeDebevec>, Ptr, MergeExposures, 0, "");
CVJS_TYPE(MergeMertens, MergeMertens, Ptr<cv::MergeMertens>, Ptr, MergeExposures, 0, "");
CVJS_TYPE(MergeRobertson, MergeRobertson, Ptr<cv::MergeRobertson>, Ptr, MergeExposures, 0, "");
CVJS_TYPE(Plot2d, plot_Plot2d, Ptr<cv::plot::Plot2d>, Ptr, Algorithm, 0, ".plot");
CVJS_TYPE(QualityBase, quality_QualityBase, Ptr<cv::quality::QualityBase>, Ptr, Algorithm, 0, ".quality");
CVJS_TYPE(QualityBRISQUE, quality_QualityBRISQUE, Ptr<cv::quality::QualityBRISQUE>, Ptr, quality_QualityBase, 0, ".quality");
CVJS_TYPE(QualityGMSD, quality_QualityGMSD, Ptr<cv::quality::QualityGMSD>, Ptr, quality_QualityBase, 0, ".quality");
CVJS_TYPE(QualityMSE, quality_QualityMSE, Ptr<cv::quality::QualityMSE>, Ptr, quality_QualityBase, 0, ".quality");
CVJS_TYPE(QualityPSNR, quality_QualityPSNR, Ptr<cv::quality::QualityPSNR>, Ptr, quality_QualityBase, 0, ".quality");
CVJS_TYPE(QualitySSIM, quality_QualitySSIM, Ptr<cv::quality::QualitySSIM>, Ptr, quality_QualityBase, 0, ".quality");
CVJS_TYPE(DictValue, dnn_DictValue, Ptr<cv::dnn::DictValue>, Ptr, NoBase, jsopencv_cv_dnn_dnn_DictValue_DictValue, ".dnn");
CVJS_TYPE(Layer, dnn_Layer, Ptr<cv::dnn::Layer>, Ptr, Algorithm, 0, ".dnn");
CVJS_TYPE(Net, dnn_Net, cv::dnn::Net, Net, NoBase, jsopencv_cv_dnn_dnn_Net_Net, ".dnn");
CVJS_TYPE(Model, dnn_Model, cv::dnn::Model, Model, NoBase, jsopencv_cv_dnn_dnn_Model_Model, ".dnn");
CVJS_TYPE(ClassificationModel, dnn_ClassificationModel, cv::dnn::ClassificationModel, ClassificationModel, dnn_Model, jsopencv_cv_dnn_dnn_ClassificationModel_ClassificationModel, ".dnn");
CVJS_TYPE(KeypointsModel, dnn_KeypointsModel, cv::dnn::KeypointsModel, KeypointsModel, dnn_Model, jsopencv_cv_dnn_dnn_KeypointsModel_KeypointsModel, ".dnn");
CVJS_TYPE(SegmentationModel, dnn_SegmentationModel, cv::dnn::SegmentationModel, SegmentationModel, dnn_Model, jsopencv_cv_dnn_dnn_SegmentationModel_SegmentationModel, ".dnn");
CVJS_TYPE(DetectionModel, dnn_DetectionModel, cv::dnn::DetectionModel, DetectionModel, dnn_Model, jsopencv_cv_dnn_dnn_DetectionModel_DetectionModel, ".dnn");
CVJS_TYPE(TextRecognitionModel, dnn_TextRecognitionModel, cv::dnn::TextRecognitionModel, TextRecognitionModel, dnn_Model, jsopencv_cv_dnn_dnn_TextRecognitionModel_TextRecognitionModel, ".dnn");
CVJS_TYPE(TextDetectionModel, dnn_TextDetectionModel, cv::dnn::TextDetectionModel, TextDetectionModel, dnn_Model, 0, ".dnn");
CVJS_TYPE(TextDetectionModel_EAST, dnn_TextDetectionModel_EAST, cv::dnn::TextDetectionModel_EAST, TextDetectionModel_EAST, dnn_TextDetectionModel, jsopencv_cv_dnn_dnn_TextDetectionModel_EAST_TextDetectionModel_EAST, ".dnn");
CVJS_TYPE(TextDetectionModel_DB, dnn_TextDetectionModel_DB, cv::dnn::TextDetectionModel_DB, TextDetectionModel_DB, dnn_TextDetectionModel, jsopencv_cv_dnn_dnn_TextDetectionModel_DB_TextDetectionModel_DB, ".dnn");
CVJS_TYPE(DnnSuperResImpl, dnn_superres_DnnSuperResImpl, Ptr<cv::dnn_superres::DnnSuperResImpl>, Ptr, NoBase, 0, ".dnn_superres");
CVJS_TYPE(Feature2D, Feature2D, Ptr<cv::Feature2D>, Ptr, NoBase, 0, "");
CVJS_TYPE(AffineFeature, AffineFeature, Ptr<cv::AffineFeature>, Ptr, Feature2D, 0, "");
CVJS_TYPE(SIFT, SIFT, Ptr<cv::SIFT>, Ptr, Feature2D, 0, "");
CVJS_TYPE(BRISK, BRISK, Ptr<cv::BRISK>, Ptr, Feature2D, 0, "");
CVJS_TYPE(ORB, ORB, Ptr<cv::ORB>, Ptr, Feature2D, 0, "");
CVJS_TYPE(MSER, MSER, Ptr<cv::MSER>, Ptr, Feature2D, 0, "");
CVJS_TYPE(FastFeatureDetector, FastFeatureDetector, Ptr<cv::FastFeatureDetector>, Ptr, Feature2D, 0, "");
CVJS_TYPE(AgastFeatureDetector, AgastFeatureDetector, Ptr<cv::AgastFeatureDetector>, Ptr, Feature2D, 0, "");
CVJS_TYPE(GFTTDetector, GFTTDetector, Ptr<cv::GFTTDetector>, Ptr, Feature2D, 0, "");
CVJS_TYPE(SimpleBlobDetector, SimpleBlobDetector, Ptr<cv::SimpleBlobDetector>, Ptr, Feature2D, 0, "");
CVJS_TYPE(Params, SimpleBlobDetector_Params, cv::SimpleBlobDetector::Params, Params, NoBase, jsopencv_cv_SimpleBlobDetector_Params_SimpleBlobDetector_Params, ".SimpleBlobDetector");
CVJS_TYPE(KAZE, KAZE, Ptr<cv::KAZE>, Ptr, Feature2D, 0, "");
CVJS_TYPE(AKAZE, AKAZE, Ptr<cv::AKAZE>, Ptr, Feature2D, 0, "");
CVJS_TYPE(DescriptorMatcher, DescriptorMatcher, Ptr<cv::DescriptorMatcher>, Ptr, Algorithm, 0, "");
CVJS_TYPE(BFMatcher, BFMatcher, Ptr<cv::BFMatcher>, Ptr, DescriptorMatcher, jsopencv_cv_BFMatcher_BFMatcher, "");
CVJS_TYPE(FlannBasedMatcher, FlannBasedMatcher, Ptr<cv::FlannBasedMatcher>, Ptr, DescriptorMatcher, jsopencv_cv_FlannBasedMatcher_FlannBasedMatcher, "");
CVJS_TYPE(BOWTrainer, BOWTrainer, Ptr<cv::BOWTrainer>, Ptr, NoBase, 0, "");
CVJS_TYPE(BOWKMeansTrainer, BOWKMeansTrainer, Ptr<cv::BOWKMeansTrainer>, Ptr, BOWTrainer, jsopencv_cv_BOWKMeansTrainer_BOWKMeansTrainer, "");
CVJS_TYPE(BOWImgDescriptorExtractor, BOWImgDescriptorExtractor, Ptr<cv::BOWImgDescriptorExtractor>, Ptr, NoBase, jsopencv_cv_BOWImgDescriptorExtractor_BOWImgDescriptorExtractor, "");
CVJS_TYPE(ImgHashBase, img_hash_ImgHashBase, Ptr<cv::img_hash::ImgHashBase>, Ptr, Algorithm, 0, ".img_hash");
CVJS_TYPE(AverageHash, img_hash_AverageHash, Ptr<cv::img_hash::AverageHash>, Ptr, img_hash_ImgHashBase, 0, ".img_hash");
CVJS_TYPE(BlockMeanHash, img_hash_BlockMeanHash, Ptr<cv::img_hash::BlockMeanHash>, Ptr, img_hash_ImgHashBase, 0, ".img_hash");
CVJS_TYPE(ColorMomentHash, img_hash_ColorMomentHash, Ptr<cv::img_hash::ColorMomentHash>, Ptr, img_hash_ImgHashBase, 0, ".img_hash");
CVJS_TYPE(MarrHildrethHash, img_hash_MarrHildrethHash, Ptr<cv::img_hash::MarrHildrethHash>, Ptr, img_hash_ImgHashBase, 0, ".img_hash");
CVJS_TYPE(PHash, img_hash_PHash, Ptr<cv::img_hash::PHash>, Ptr, img_hash_ImgHashBase, 0, ".img_hash");
CVJS_TYPE(RadialVarianceHash, img_hash_RadialVarianceHash, Ptr<cv::img_hash::RadialVarianceHash>, Ptr, img_hash_ImgHashBase, 0, ".img_hash");
CVJS_TYPE(ERFilter, text_ERFilter, Ptr<cv::text::ERFilter>, Ptr, Algorithm, 0, ".text");
CVJS_TYPE(Callback, text_ERFilter_Callback, Ptr<cv::text::ERFilter::Callback>, Ptr, NoBase, 0, ".text.ERFilter");
CVJS_TYPE(BaseOCR, text_BaseOCR, Ptr<cv::text::BaseOCR>, Ptr, NoBase, 0, ".text");
CVJS_TYPE(OCRTesseract, text_OCRTesseract, Ptr<cv::text::OCRTesseract>, Ptr, text_BaseOCR, 0, ".text");
CVJS_TYPE(OCRHMMDecoder, text_OCRHMMDecoder, Ptr<cv::text::OCRHMMDecoder>, Ptr, text_BaseOCR, 0, ".text");
CVJS_TYPE(ClassifierCallback, text_OCRHMMDecoder_ClassifierCallback, Ptr<cv::text::OCRHMMDecoder::ClassifierCallback>, Ptr, NoBase, 0, ".text.OCRHMMDecoder");
CVJS_TYPE(OCRBeamSearchDecoder, text_OCRBeamSearchDecoder, Ptr<cv::text::OCRBeamSearchDecoder>, Ptr, text_BaseOCR, 0, ".text");
CVJS_TYPE(ClassifierCallback, text_OCRBeamSearchDecoder_ClassifierCallback, Ptr<cv::text::OCRBeamSearchDecoder::ClassifierCallback>, Ptr, NoBase, 0, ".text.OCRBeamSearchDecoder");
CVJS_TYPE(TextDetector, text_TextDetector, Ptr<cv::text::TextDetector>, Ptr, NoBase, 0, ".text");
CVJS_TYPE(TextDetectorCNN, text_TextDetectorCNN, Ptr<cv::text::TextDetectorCNN>, Ptr, text_TextDetector, 0, ".text");
CVJS_TYPE(VideoCapture, VideoCapture, Ptr<cv::VideoCapture>, Ptr, NoBase, jsopencv_cv_VideoCapture_VideoCapture, "");
CVJS_TYPE(VideoWriter, VideoWriter, Ptr<cv::VideoWriter>, Ptr, NoBase, jsopencv_cv_VideoWriter_VideoWriter, "");
CVJS_TYPE(BarcodeDetector, barcode_BarcodeDetector, Ptr<cv::barcode::BarcodeDetector>, Ptr, NoBase, jsopencv_cv_barcode_barcode_BarcodeDetector_BarcodeDetector, ".barcode");
CVJS_TYPE(UsacParams, UsacParams, cv::UsacParams, UsacParams, NoBase, jsopencv_cv_UsacParams_UsacParams, "");
CVJS_TYPE(CirclesGridFinderParameters, CirclesGridFinderParameters, cv::CirclesGridFinderParameters, CirclesGridFinderParameters, NoBase, jsopencv_cv_CirclesGridFinderParameters_CirclesGridFinderParameters, "");
CVJS_TYPE(StereoMatcher, StereoMatcher, Ptr<cv::StereoMatcher>, Ptr, Algorithm, 0, "");
CVJS_TYPE(StereoBM, StereoBM, Ptr<cv::StereoBM>, Ptr, StereoMatcher, 0, "");
CVJS_TYPE(StereoSGBM, StereoSGBM, Ptr<cv::StereoSGBM>, Ptr, StereoMatcher, 0, "");
CVJS_TYPE(ColorCorrectionModel, ccm_ColorCorrectionModel, Ptr<cv::ccm::ColorCorrectionModel>, Ptr, NoBase, jsopencv_cv_ccm_ccm_ColorCorrectionModel_ColorCorrectionModel, ".ccm");
CVJS_TYPE(DetectorParameters, mcc_DetectorParameters, Ptr<cv::mcc::DetectorParameters>, Ptr, NoBase, 0, ".mcc");
CVJS_TYPE(CCheckerDetector, mcc_CCheckerDetector, Ptr<cv::mcc::CCheckerDetector>, Ptr, Algorithm, 0, ".mcc");
CVJS_TYPE(CChecker, mcc_CChecker, Ptr<cv::mcc::CChecker>, Ptr, NoBase, 0, ".mcc");
CVJS_TYPE(CCheckerDraw, mcc_CCheckerDraw, Ptr<cv::mcc::CCheckerDraw>, Ptr, NoBase, 0, ".mcc");
CVJS_TYPE(BaseCascadeClassifier, BaseCascadeClassifier, Ptr<cv::BaseCascadeClassifier>, Ptr, Algorithm, 0, "");
CVJS_TYPE(CascadeClassifier, CascadeClassifier, Ptr<cv::CascadeClassifier>, Ptr, NoBase, jsopencv_cv_CascadeClassifier_CascadeClassifier, "");
CVJS_TYPE(HOGDescriptor, HOGDescriptor, Ptr<cv::HOGDescriptor>, Ptr, NoBase, jsopencv_cv_HOGDescriptor_HOGDescriptor, "");
CVJS_TYPE(QRCodeEncoder, QRCodeEncoder, Ptr<cv::QRCodeEncoder>, Ptr, NoBase, 0, "");
CVJS_TYPE(Params, QRCodeEncoder_Params, cv::QRCodeEncoder::Params, Params, NoBase, jsopencv_cv_QRCodeEncoder_Params_QRCodeEncoder_Params, ".QRCodeEncoder");
CVJS_TYPE(QRCodeDetector, QRCodeDetector, Ptr<cv::QRCodeDetector>, Ptr, NoBase, jsopencv_cv_QRCodeDetector_QRCodeDetector, "");
CVJS_TYPE(Board, aruco_Board, cv::aruco::Board, Board, NoBase, jsopencv_cv_aruco_aruco_Board_Board, ".aruco");
CVJS_TYPE(GridBoard, aruco_GridBoard, cv::aruco::GridBoard, GridBoard, aruco_Board, jsopencv_cv_aruco_aruco_GridBoard_GridBoard, ".aruco");
CVJS_TYPE(CharucoBoard, aruco_CharucoBoard, cv::aruco::CharucoBoard, CharucoBoard, aruco_Board, jsopencv_cv_aruco_aruco_CharucoBoard_CharucoBoard, ".aruco");
CVJS_TYPE(DetectorParameters, aruco_DetectorParameters, cv::aruco::DetectorParameters, DetectorParameters, NoBase, jsopencv_cv_aruco_aruco_DetectorParameters_DetectorParameters, ".aruco");
CVJS_TYPE(RefineParameters, aruco_RefineParameters, cv::aruco::RefineParameters, RefineParameters, NoBase, jsopencv_cv_aruco_aruco_RefineParameters_RefineParameters, ".aruco");
CVJS_TYPE(ArucoDetector, aruco_ArucoDetector, Ptr<cv::aruco::ArucoDetector>, Ptr, Algorithm, jsopencv_cv_aruco_aruco_ArucoDetector_ArucoDetector, ".aruco");
CVJS_TYPE(Dictionary, aruco_Dictionary, cv::aruco::Dictionary, Dictionary, NoBase, jsopencv_cv_aruco_aruco_Dictionary_Dictionary, ".aruco");
CVJS_TYPE(CharucoParameters, aruco_CharucoParameters, cv::aruco::CharucoParameters, CharucoParameters, NoBase, 0, ".aruco");
CVJS_TYPE(CharucoDetector, aruco_CharucoDetector, Ptr<cv::aruco::CharucoDetector>, Ptr, Algorithm, jsopencv_cv_aruco_aruco_CharucoDetector_CharucoDetector, ".aruco");
CVJS_TYPE(FaceDetectorYN, FaceDetectorYN, Ptr<cv::FaceDetectorYN>, Ptr, NoBase, 0, "");
CVJS_TYPE(FaceRecognizerSF, FaceRecognizerSF, Ptr<cv::FaceRecognizerSF>, Ptr, NoBase, 0, "");
CVJS_TYPE(Tracker, rapid_Tracker, Ptr<cv::rapid::Tracker>, Ptr, Algorithm, 0, ".rapid");
CVJS_TYPE(Rapid, rapid_Rapid, Ptr<cv::rapid::Rapid>, Ptr, rapid_Tracker, 0, ".rapid");
CVJS_TYPE(OLSTracker, rapid_OLSTracker, Ptr<cv::rapid::OLSTracker>, Ptr, rapid_Tracker, 0, ".rapid");
CVJS_TYPE(GOSTracker, rapid_GOSTracker, Ptr<cv::rapid::GOSTracker>, Ptr, rapid_Tracker, 0, ".rapid");
CVJS_TYPE(BackgroundSubtractor, BackgroundSubtractor, Ptr<cv::BackgroundSubtractor>, Ptr, Algorithm, 0, "");
CVJS_TYPE(BackgroundSubtractorMOG2, BackgroundSubtractorMOG2, Ptr<cv::BackgroundSubtractorMOG2>, Ptr, BackgroundSubtractor, 0, "");
CVJS_TYPE(BackgroundSubtractorKNN, BackgroundSubtractorKNN, Ptr<cv::BackgroundSubtractorKNN>, Ptr, BackgroundSubtractor, 0, "");
CVJS_TYPE(KalmanFilter, KalmanFilter, Ptr<cv::KalmanFilter>, Ptr, NoBase, jsopencv_cv_KalmanFilter_KalmanFilter, "");
CVJS_TYPE(DenseOpticalFlow, DenseOpticalFlow, Ptr<cv::DenseOpticalFlow>, Ptr, Algorithm, 0, "");
CVJS_TYPE(SparseOpticalFlow, SparseOpticalFlow, Ptr<cv::SparseOpticalFlow>, Ptr, Algorithm, 0, "");
CVJS_TYPE(FarnebackOpticalFlow, FarnebackOpticalFlow, Ptr<cv::FarnebackOpticalFlow>, Ptr, DenseOpticalFlow, 0, "");
CVJS_TYPE(VariationalRefinement, VariationalRefinement, Ptr<cv::VariationalRefinement>, Ptr, DenseOpticalFlow, 0, "");
CVJS_TYPE(DISOpticalFlow, DISOpticalFlow, Ptr<cv::DISOpticalFlow>, Ptr, DenseOpticalFlow, 0, "");
CVJS_TYPE(SparsePyrLKOpticalFlow, SparsePyrLKOpticalFlow, Ptr<cv::SparsePyrLKOpticalFlow>, Ptr, SparseOpticalFlow, 0, "");
CVJS_TYPE(Tracker, Tracker, Ptr<cv::Tracker>, Ptr, NoBase, 0, "");
CVJS_TYPE(TrackerMIL, TrackerMIL, Ptr<cv::TrackerMIL>, Ptr, Tracker, 0, "");
CVJS_TYPE(Params, TrackerMIL_Params, cv::TrackerMIL::Params, Params, NoBase, jsopencv_cv_TrackerMIL_Params_TrackerMIL_Params, ".TrackerMIL");
CVJS_TYPE(TrackerGOTURN, TrackerGOTURN, Ptr<cv::TrackerGOTURN>, Ptr, Tracker, 0, "");
CVJS_TYPE(Params, TrackerGOTURN_Params, cv::TrackerGOTURN::Params, Params, NoBase, jsopencv_cv_TrackerGOTURN_Params_TrackerGOTURN_Params, ".TrackerGOTURN");
CVJS_TYPE(TrackerDaSiamRPN, TrackerDaSiamRPN, Ptr<cv::TrackerDaSiamRPN>, Ptr, Tracker, 0, "");
CVJS_TYPE(Params, TrackerDaSiamRPN_Params, cv::TrackerDaSiamRPN::Params, Params, NoBase, jsopencv_cv_TrackerDaSiamRPN_Params_TrackerDaSiamRPN_Params, ".TrackerDaSiamRPN");
CVJS_TYPE(TrackerNano, TrackerNano, Ptr<cv::TrackerNano>, Ptr, Tracker, 0, "");
CVJS_TYPE(Params, TrackerNano_Params, cv::TrackerNano::Params, Params, NoBase, jsopencv_cv_TrackerNano_Params_TrackerNano_Params, ".TrackerNano");
CVJS_TYPE(FREAK, xfeatures2d_FREAK, Ptr<cv::xfeatures2d::FREAK>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(StarDetector, xfeatures2d_StarDetector, Ptr<cv::xfeatures2d::StarDetector>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(BriefDescriptorExtractor, xfeatures2d_BriefDescriptorExtractor, Ptr<cv::xfeatures2d::BriefDescriptorExtractor>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(LUCID, xfeatures2d_LUCID, Ptr<cv::xfeatures2d::LUCID>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(LATCH, xfeatures2d_LATCH, Ptr<cv::xfeatures2d::LATCH>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(BEBLID, xfeatures2d_BEBLID, Ptr<cv::xfeatures2d::BEBLID>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(TEBLID, xfeatures2d_TEBLID, Ptr<cv::xfeatures2d::TEBLID>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(DAISY, xfeatures2d_DAISY, Ptr<cv::xfeatures2d::DAISY>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(MSDDetector, xfeatures2d_MSDDetector, Ptr<cv::xfeatures2d::MSDDetector>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(VGG, xfeatures2d_VGG, Ptr<cv::xfeatures2d::VGG>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(BoostDesc, xfeatures2d_BoostDesc, Ptr<cv::xfeatures2d::BoostDesc>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(PCTSignatures, xfeatures2d_PCTSignatures, Ptr<cv::xfeatures2d::PCTSignatures>, Ptr, Algorithm, 0, ".xfeatures2d");
CVJS_TYPE(PCTSignaturesSQFD, xfeatures2d_PCTSignaturesSQFD, Ptr<cv::xfeatures2d::PCTSignaturesSQFD>, Ptr, Algorithm, 0, ".xfeatures2d");
CVJS_TYPE(HarrisLaplaceFeatureDetector, xfeatures2d_HarrisLaplaceFeatureDetector, Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(AffineFeature2D, xfeatures2d_AffineFeature2D, Ptr<cv::xfeatures2d::AffineFeature2D>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(TBMR, xfeatures2d_TBMR, Ptr<cv::xfeatures2d::TBMR>, Ptr, xfeatures2d_AffineFeature2D, 0, ".xfeatures2d");
CVJS_TYPE(SURF_CUDA, cuda_SURF_CUDA, Ptr<cv::cuda::SURF_CUDA>, Ptr, NoBase, 0, ".cuda");
CVJS_TYPE(SURF, xfeatures2d_SURF, Ptr<cv::xfeatures2d::SURF>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(DisparityFilter, ximgproc_DisparityFilter, Ptr<cv::ximgproc::DisparityFilter>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(DisparityWLSFilter, ximgproc_DisparityWLSFilter, Ptr<cv::ximgproc::DisparityWLSFilter>, Ptr, ximgproc_DisparityFilter, 0, ".ximgproc");
CVJS_TYPE(EdgeDrawing, ximgproc_EdgeDrawing, Ptr<cv::ximgproc::EdgeDrawing>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(Params, ximgproc_EdgeDrawing_Params, cv::ximgproc::EdgeDrawing::Params, Params, NoBase, jsopencv_cv_ximgproc_ximgproc_EdgeDrawing_Params_EdgeDrawing_Params, ".ximgproc.EdgeDrawing");
CVJS_TYPE(DTFilter, ximgproc_DTFilter, Ptr<cv::ximgproc::DTFilter>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(GuidedFilter, ximgproc_GuidedFilter, Ptr<cv::ximgproc::GuidedFilter>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(AdaptiveManifoldFilter, ximgproc_AdaptiveManifoldFilter, Ptr<cv::ximgproc::AdaptiveManifoldFilter>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(FastBilateralSolverFilter, ximgproc_FastBilateralSolverFilter, Ptr<cv::ximgproc::FastBilateralSolverFilter>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(FastGlobalSmootherFilter, ximgproc_FastGlobalSmootherFilter, Ptr<cv::ximgproc::FastGlobalSmootherFilter>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(EdgeBoxes, ximgproc_EdgeBoxes, Ptr<cv::ximgproc::EdgeBoxes>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(FastLineDetector, ximgproc_FastLineDetector, Ptr<cv::ximgproc::FastLineDetector>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(ContourFitting, ximgproc_ContourFitting, Ptr<cv::ximgproc::ContourFitting>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(SuperpixelLSC, ximgproc_SuperpixelLSC, Ptr<cv::ximgproc::SuperpixelLSC>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(RidgeDetectionFilter, ximgproc_RidgeDetectionFilter, Ptr<cv::ximgproc::RidgeDetectionFilter>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(ScanSegment, ximgproc_ScanSegment, Ptr<cv::ximgproc::ScanSegment>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(SuperpixelSEEDS, ximgproc_SuperpixelSEEDS, Ptr<cv::ximgproc::SuperpixelSEEDS>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(GraphSegmentation, ximgproc_segmentation_GraphSegmentation, Ptr<cv::ximgproc::segmentation::GraphSegmentation>, Ptr, Algorithm, 0, ".ximgproc.segmentation");
CVJS_TYPE(SelectiveSearchSegmentationStrategy, ximgproc_segmentation_SelectiveSearchSegmentationStrategy, Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>, Ptr, Algorithm, 0, ".ximgproc.segmentation");
CVJS_TYPE(SelectiveSearchSegmentationStrategyColor, ximgproc_segmentation_SelectiveSearchSegmentationStrategyColor, Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyColor>, Ptr, ximgproc_segmentation_SelectiveSearchSegmentationStrategy, 0, ".ximgproc.segmentation");
CVJS_TYPE(SelectiveSearchSegmentationStrategySize, ximgproc_segmentation_SelectiveSearchSegmentationStrategySize, Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategySize>, Ptr, ximgproc_segmentation_SelectiveSearchSegmentationStrategy, 0, ".ximgproc.segmentation");
CVJS_TYPE(SelectiveSearchSegmentationStrategyTexture, ximgproc_segmentation_SelectiveSearchSegmentationStrategyTexture, Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyTexture>, Ptr, ximgproc_segmentation_SelectiveSearchSegmentationStrategy, 0, ".ximgproc.segmentation");
CVJS_TYPE(SelectiveSearchSegmentationStrategyFill, ximgproc_segmentation_SelectiveSearchSegmentationStrategyFill, Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyFill>, Ptr, ximgproc_segmentation_SelectiveSearchSegmentationStrategy, 0, ".ximgproc.segmentation");
CVJS_TYPE(SelectiveSearchSegmentationStrategyMultiple, ximgproc_segmentation_SelectiveSearchSegmentationStrategyMultiple, Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>, Ptr, ximgproc_segmentation_SelectiveSearchSegmentationStrategy, 0, ".ximgproc.segmentation");
CVJS_TYPE(SelectiveSearchSegmentation, ximgproc_segmentation_SelectiveSearchSegmentation, Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentation>, Ptr, Algorithm, 0, ".ximgproc.segmentation");
CVJS_TYPE(SuperpixelSLIC, ximgproc_SuperpixelSLIC, Ptr<cv::ximgproc::SuperpixelSLIC>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(SparseMatchInterpolator, ximgproc_SparseMatchInterpolator, Ptr<cv::ximgproc::SparseMatchInterpolator>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(EdgeAwareInterpolator, ximgproc_EdgeAwareInterpolator, Ptr<cv::ximgproc::EdgeAwareInterpolator>, Ptr, ximgproc_SparseMatchInterpolator, 0, ".ximgproc");
CVJS_TYPE(RICInterpolator, ximgproc_RICInterpolator, Ptr<cv::ximgproc::RICInterpolator>, Ptr, ximgproc_SparseMatchInterpolator, 0, ".ximgproc");
CVJS_TYPE(RFFeatureGetter, ximgproc_RFFeatureGetter, Ptr<cv::ximgproc::RFFeatureGetter>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(StructuredEdgeDetection, ximgproc_StructuredEdgeDetection, Ptr<cv::ximgproc::StructuredEdgeDetection>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(FaceRecognizer, face_FaceRecognizer, Ptr<cv::face::FaceRecognizer>, Ptr, Algorithm, 0, ".face");
CVJS_TYPE(BIF, face_BIF, Ptr<cv::face::BIF>, Ptr, Algorithm, 0, ".face");
CVJS_TYPE(Facemark, face_Facemark, Ptr<cv::face::Facemark>, Ptr, Algorithm, 0, ".face");
CVJS_TYPE(FacemarkKazemi, face_FacemarkKazemi, Ptr<cv::face::FacemarkKazemi>, Ptr, face_Facemark, 0, ".face");
CVJS_TYPE(FacemarkTrain, face_FacemarkTrain, Ptr<cv::face::FacemarkTrain>, Ptr, face_Facemark, 0, ".face");
CVJS_TYPE(FacemarkAAM, face_FacemarkAAM, Ptr<cv::face::FacemarkAAM>, Ptr, face_FacemarkTrain, 0, ".face");
CVJS_TYPE(FacemarkLBF, face_FacemarkLBF, Ptr<cv::face::FacemarkLBF>, Ptr, face_FacemarkTrain, 0, ".face");
CVJS_TYPE(BasicFaceRecognizer, face_BasicFaceRecognizer, Ptr<cv::face::BasicFaceRecognizer>, Ptr, face_FaceRecognizer, 0, ".face");
CVJS_TYPE(EigenFaceRecognizer, face_EigenFaceRecognizer, Ptr<cv::face::EigenFaceRecognizer>, Ptr, face_BasicFaceRecognizer, 0, ".face");
CVJS_TYPE(FisherFaceRecognizer, face_FisherFaceRecognizer, Ptr<cv::face::FisherFaceRecognizer>, Ptr, face_BasicFaceRecognizer, 0, ".face");
CVJS_TYPE(LBPHFaceRecognizer, face_LBPHFaceRecognizer, Ptr<cv::face::LBPHFaceRecognizer>, Ptr, face_FaceRecognizer, 0, ".face");
CVJS_TYPE(MACE, face_MACE, Ptr<cv::face::MACE>, Ptr, Algorithm, 0, ".face");
CVJS_TYPE(PredictCollector, face_PredictCollector, Ptr<cv::face::PredictCollector>, Ptr, NoBase, 0, ".face");
CVJS_TYPE(StandardCollector, face_StandardCollector, Ptr<cv::face::StandardCollector>, Ptr, face_PredictCollector, 0, ".face");
CVJS_TYPE(GArrayDesc, GArrayDesc, cv::GArrayDesc, GArrayDesc, NoBase, 0, "");
CVJS_TYPE(GComputation, GComputation, Ptr<cv::GComputation>, Ptr, NoBase, jsopencv_cv_GComputation_GComputation, "");
CVJS_TYPE(GFrame, GFrame, cv::GFrame, GFrame, NoBase, jsopencv_cv_GFrame_GFrame, "");
CVJS_TYPE(GKernelPackage, GKernelPackage, cv::GKernelPackage, GKernelPackage, NoBase, 0, "");
CVJS_TYPE(GMat, GMat, cv::GMat, GMat, NoBase, jsopencv_cv_GMat_GMat, "");
CVJS_TYPE(GMatDesc, GMatDesc, cv::GMatDesc, GMatDesc, NoBase, jsopencv_cv_GMatDesc_GMatDesc, "");
CVJS_TYPE(GOpaqueDesc, GOpaqueDesc, cv::GOpaqueDesc, GOpaqueDesc, NoBase, 0, "");
CVJS_TYPE(GScalar, GScalar, cv::GScalar, GScalar, NoBase, jsopencv_cv_GScalar_GScalar, "");
CVJS_TYPE(GScalarDesc, GScalarDesc, cv::GScalarDesc, GScalarDesc, NoBase, 0, "");
CVJS_TYPE(GStreamingCompiled, GStreamingCompiled, cv::GStreamingCompiled, GStreamingCompiled, NoBase, jsopencv_cv_GStreamingCompiled_GStreamingCompiled, "");
CVJS_TYPE(queue_capacity, gapi_streaming_queue_capacity, cv::gapi::streaming::queue_capacity, queue_capacity, NoBase, jsopencv_cv_gapi_streaming_gapi_streaming_queue_capacity_queue_capacity, ".gapi.streaming");
CVJS_TYPE(GNetParam, gapi_GNetParam, cv::gapi::GNetParam, GNetParam, NoBase, 0, ".gapi");
CVJS_TYPE(GNetPackage, gapi_GNetPackage, cv::gapi::GNetPackage, GNetPackage, NoBase, jsopencv_cv_gapi_gapi_GNetPackage_GNetPackage, ".gapi");
CVJS_TYPE(PyParams, gapi_ie_PyParams, cv::gapi::ie::PyParams, PyParams, NoBase, jsopencv_cv_gapi_ie_gapi_ie_PyParams_PyParams, ".gapi.ie");
CVJS_TYPE(PyParams, gapi_onnx_PyParams, cv::gapi::onnx::PyParams, PyParams, NoBase, jsopencv_cv_gapi_onnx_gapi_onnx_PyParams_PyParams, ".gapi.onnx");
CVJS_TYPE(Text, gapi_wip_draw_Text, cv::gapi::wip::draw::Text, Text, NoBase, jsopencv_cv_gapi_wip_draw_gapi_wip_draw_Text_Text, ".gapi.wip.draw");
CVJS_TYPE(Rect, gapi_wip_draw_Rect, cv::gapi::wip::draw::Rect, Rect, NoBase, jsopencv_cv_gapi_wip_draw_gapi_wip_draw_Rect_Rect, ".gapi.wip.draw");
CVJS_TYPE(Circle, gapi_wip_draw_Circle, cv::gapi::wip::draw::Circle, Circle, NoBase, jsopencv_cv_gapi_wip_draw_gapi_wip_draw_Circle_Circle, ".gapi.wip.draw");
CVJS_TYPE(Line, gapi_wip_draw_Line, cv::gapi::wip::draw::Line, Line, NoBase, jsopencv_cv_gapi_wip_draw_gapi_wip_draw_Line_Line, ".gapi.wip.draw");
CVJS_TYPE(Mosaic, gapi_wip_draw_Mosaic, cv::gapi::wip::draw::Mosaic, Mosaic, NoBase, jsopencv_cv_gapi_wip_draw_gapi_wip_draw_Mosaic_Mosaic, ".gapi.wip.draw");
CVJS_TYPE(Image, gapi_wip_draw_Image, cv::gapi::wip::draw::Image, Image, NoBase, jsopencv_cv_gapi_wip_draw_gapi_wip_draw_Image_Image, ".gapi.wip.draw");
CVJS_TYPE(Poly, gapi_wip_draw_Poly, cv::gapi::wip::draw::Poly, Poly, NoBase, jsopencv_cv_gapi_wip_draw_gapi_wip_draw_Poly_Poly, ".gapi.wip.draw");
CVJS_TYPE(GStreamerPipeline, gapi_wip_gst_GStreamerPipeline, Ptr<cv::gapi::wip::gst::GStreamerPipeline>, Ptr, NoBase, jsopencv_cv_gapi_wip_gst_gapi_wip_gst_GStreamerPipeline_GStreamerPipeline, ".gapi.wip.gst");
CVJS_TYPE(GOpaqueT, GOpaqueT, cv::GOpaqueT, GOpaqueT, NoBase, jsopencv_cv_GOpaqueT_GOpaqueT, "");
CVJS_TYPE(GArrayT, GArrayT, cv::GArrayT, GArrayT, NoBase, jsopencv_cv_GArrayT_GArrayT, "");
CVJS_TYPE(GOutputs, gapi_wip_GOutputs, cv::gapi::wip::GOutputs, GOutputs, NoBase, 0, ".gapi.wip");
CVJS_TYPE(GCompileArg, GCompileArg, cv::GCompileArg, GCompileArg, NoBase, jsopencv_cv_GCompileArg_GCompileArg, "");
CVJS_TYPE(GInferInputs, GInferInputs, cv::GInferInputs, GInferInputs, NoBase, jsopencv_cv_GInferInputs_GInferInputs, "");
CVJS_TYPE(GInferListInputs, GInferListInputs, cv::GInferListInputs, GInferListInputs, NoBase, jsopencv_cv_GInferListInputs_GInferListInputs, "");
CVJS_TYPE(GInferOutputs, GInferOutputs, cv::GInferOutputs, GInferOutputs, NoBase, jsopencv_cv_GInferOutputs_GInferOutputs, "");
CVJS_TYPE(GInferListOutputs, GInferListOutputs, cv::GInferListOutputs, GInferListOutputs, NoBase, jsopencv_cv_GInferListOutputs_GInferListOutputs, "");
CVJS_TYPE(IStreamSource, gapi_wip_IStreamSource, Ptr<cv::gapi::wip::IStreamSource>, Ptr, NoBase, 0, ".gapi.wip");
CVJS_TYPE(TrackerCSRT, TrackerCSRT, Ptr<cv::TrackerCSRT>, Ptr, Tracker, 0, "");
CVJS_TYPE(Params, TrackerCSRT_Params, cv::TrackerCSRT::Params, Params, NoBase, jsopencv_cv_TrackerCSRT_Params_TrackerCSRT_Params, ".TrackerCSRT");
CVJS_TYPE(TrackerKCF, TrackerKCF, Ptr<cv::TrackerKCF>, Ptr, Tracker, 0, "");
CVJS_TYPE(Params, TrackerKCF_Params, cv::TrackerKCF::Params, Params, NoBase, jsopencv_cv_TrackerKCF_Params_TrackerKCF_Params, ".TrackerKCF");
CVJS_TYPE(Tracker, legacy_Tracker, Ptr<cv::legacy::Tracker>, Ptr, Algorithm, 0, ".legacy");
CVJS_TYPE(TrackerMIL, legacy_TrackerMIL, Ptr<cv::legacy::TrackerMIL>, Ptr, legacy_Tracker, 0, ".legacy");
CVJS_TYPE(TrackerBoosting, legacy_TrackerBoosting, Ptr<cv::legacy::TrackerBoosting>, Ptr, legacy_Tracker, 0, ".legacy");
CVJS_TYPE(TrackerMedianFlow, legacy_TrackerMedianFlow, Ptr<cv::legacy::TrackerMedianFlow>, Ptr, legacy_Tracker, 0, ".legacy");
CVJS_TYPE(TrackerTLD, legacy_TrackerTLD, Ptr<cv::legacy::TrackerTLD>, Ptr, legacy_Tracker, 0, ".legacy");
CVJS_TYPE(TrackerKCF, legacy_TrackerKCF, Ptr<cv::legacy::TrackerKCF>, Ptr, legacy_Tracker, 0, ".legacy");
CVJS_TYPE(TrackerMOSSE, legacy_TrackerMOSSE, Ptr<cv::legacy::TrackerMOSSE>, Ptr, legacy_Tracker, 0, ".legacy");
CVJS_TYPE(MultiTracker, legacy_MultiTracker, Ptr<cv::legacy::MultiTracker>, Ptr, Algorithm, jsopencv_cv_legacy_legacy_MultiTracker_MultiTracker, ".legacy");
CVJS_TYPE(TrackerCSRT, legacy_TrackerCSRT, Ptr<cv::legacy::TrackerCSRT>, Ptr, legacy_Tracker, 0, ".legacy");
#endif
