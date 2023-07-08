#ifndef __JSOPENCV_GENERATED_TYPES_H__
#define __JSOPENCV_GENERATED_TYPES_H__
#include "../cc-common/cv2_macro.hpp"
#include "../cc-common/js_as_py.h"
#include "./jsopencv_generated_include.h"

CVJS_TYPE(Algorithm, Algorithm, cv::Ptr<cv::Algorithm>, Ptr, NoBase, 0, "");
CVJS_TYPE(AsyncArray, AsyncArray, cv::Ptr<cv::AsyncArray>, Ptr, NoBase, jsopencv_cv_AsyncArray_AsyncArray, "");
CVJS_TYPE(ClassWithKeywordProperties, utils_ClassWithKeywordProperties, cv::utils::ClassWithKeywordProperties, ClassWithKeywordProperties, NoBase, jsopencv_cv_utils_utils_ClassWithKeywordProperties_ClassWithKeywordProperties, ".utils");
CVJS_TYPE(ExportClassName, utils_nested_OriginalClassName, cv::Ptr<cv::utils::nested::OriginalClassName>, Ptr, NoBase, 0, ".utils.nested");
CVJS_TYPE(Params, utils_nested_OriginalClassName_Params, cv::utils::nested::OriginalClassName::Params, Params, NoBase, jsopencv_cv_utils_nested_utils_nested_OriginalClassName_Params_OriginalClassName_Params, ".utils.nested.ExportClassName");
CVJS_TYPE(GpuMat, cuda_GpuMat, cv::Ptr<cv::cuda::GpuMat>, Ptr, NoBase, jsopencv_cv_cuda_cuda_GpuMat_GpuMat, ".cuda");
CVJS_TYPE(Allocator, cuda_GpuMat_Allocator, cv::Ptr<cv::cuda::GpuMat::Allocator>, Ptr, NoBase, 0, ".cuda.GpuMat");
CVJS_TYPE(GpuData, cuda_GpuData, cv::Ptr<cv::cuda::GpuData>, Ptr, NoBase, 0, ".cuda");
CVJS_TYPE(GpuMatND, cuda_GpuMatND, cv::Ptr<cv::cuda::GpuMatND>, Ptr, NoBase, 0, ".cuda");
CVJS_TYPE(BufferPool, cuda_BufferPool, cv::Ptr<cv::cuda::BufferPool>, Ptr, NoBase, jsopencv_cv_cuda_cuda_BufferPool_BufferPool, ".cuda");
CVJS_TYPE(HostMem, cuda_HostMem, cv::Ptr<cv::cuda::HostMem>, Ptr, NoBase, jsopencv_cv_cuda_cuda_HostMem_HostMem, ".cuda");
CVJS_TYPE(Stream, cuda_Stream, cv::Ptr<cv::cuda::Stream>, Ptr, NoBase, jsopencv_cv_cuda_cuda_Stream_Stream, ".cuda");
CVJS_TYPE(Event, cuda_Event, cv::Ptr<cv::cuda::Event>, Ptr, NoBase, jsopencv_cv_cuda_cuda_Event_Event, ".cuda");
CVJS_TYPE(TargetArchs, cuda_TargetArchs, cv::Ptr<cv::cuda::TargetArchs>, Ptr, NoBase, 0, ".cuda");
CVJS_TYPE(DeviceInfo, cuda_DeviceInfo, cv::Ptr<cv::cuda::DeviceInfo>, Ptr, NoBase, jsopencv_cv_cuda_cuda_DeviceInfo_DeviceInfo, ".cuda");
CVJS_TYPE(Device, ocl_Device, cv::ocl::Device, Device, NoBase, jsopencv_cv_ocl_ocl_Device_Device, ".ocl");
CVJS_TYPE(OpenCLExecutionContext, ocl_OpenCLExecutionContext, cv::Ptr<cv::ocl::OpenCLExecutionContext>, Ptr, NoBase, 0, ".ocl");
CVJS_TYPE(FileStorage, FileStorage, cv::Ptr<cv::FileStorage>, Ptr, NoBase, jsopencv_cv_FileStorage_FileStorage, "");
CVJS_TYPE(FileNode, FileNode, cv::FileNode, FileNode, NoBase, jsopencv_cv_FileNode_FileNode, "");
CVJS_TYPE(KeyPoint, KeyPoint, cv::KeyPoint, KeyPoint, NoBase, jsopencv_cv_KeyPoint_KeyPoint, "");
CVJS_TYPE(DMatch, DMatch, cv::DMatch, DMatch, NoBase, jsopencv_cv_DMatch_DMatch, "");
CVJS_TYPE(TickMeter, TickMeter, cv::Ptr<cv::TickMeter>, Ptr, NoBase, jsopencv_cv_TickMeter_TickMeter, "");
CVJS_TYPE(UMat, UMat, cv::Ptr<cv::UMat>, Ptr, NoBase, jsopencv_cv_UMat_UMat, "");
CVJS_TYPE(Index, flann_Index, cv::Ptr<cv::flann::Index>, Ptr, NoBase, jsopencv_cv_flann_flann_Index_Index, ".flann");
CVJS_TYPE(GeneralizedHough, GeneralizedHough, cv::Ptr<cv::GeneralizedHough>, Ptr, Algorithm, 0, "");
CVJS_TYPE(GeneralizedHoughBallard, GeneralizedHoughBallard, cv::Ptr<cv::GeneralizedHoughBallard>, Ptr, GeneralizedHough, 0, "");
CVJS_TYPE(GeneralizedHoughGuil, GeneralizedHoughGuil, cv::Ptr<cv::GeneralizedHoughGuil>, Ptr, GeneralizedHough, 0, "");
CVJS_TYPE(CLAHE, CLAHE, cv::Ptr<cv::CLAHE>, Ptr, Algorithm, 0, "");
CVJS_TYPE(Subdiv2D, Subdiv2D, cv::Ptr<cv::Subdiv2D>, Ptr, NoBase, jsopencv_cv_Subdiv2D_Subdiv2D, "");
CVJS_TYPE(LineSegmentDetector, LineSegmentDetector, cv::Ptr<cv::LineSegmentDetector>, Ptr, Algorithm, 0, "");
CVJS_TYPE(IntelligentScissorsMB, segmentation_IntelligentScissorsMB, cv::segmentation::IntelligentScissorsMB, IntelligentScissorsMB, NoBase, jsopencv_cv_segmentation_segmentation_IntelligentScissorsMB_IntelligentScissorsMB, ".segmentation");
CVJS_TYPE(ParamGrid, ml_ParamGrid, cv::Ptr<cv::ml::ParamGrid>, Ptr, NoBase, 0, ".ml");
CVJS_TYPE(TrainData, ml_TrainData, cv::Ptr<cv::ml::TrainData>, Ptr, NoBase, 0, ".ml");
CVJS_TYPE(StatModel, ml_StatModel, cv::Ptr<cv::ml::StatModel>, Ptr, Algorithm, 0, ".ml");
CVJS_TYPE(NormalBayesClassifier, ml_NormalBayesClassifier, cv::Ptr<cv::ml::NormalBayesClassifier>, Ptr, ml_StatModel, 0, ".ml");
CVJS_TYPE(KNearest, ml_KNearest, cv::Ptr<cv::ml::KNearest>, Ptr, ml_StatModel, 0, ".ml");
CVJS_TYPE(SVM, ml_SVM, cv::Ptr<cv::ml::SVM>, Ptr, ml_StatModel, 0, ".ml");
CVJS_TYPE(EM, ml_EM, cv::Ptr<cv::ml::EM>, Ptr, ml_StatModel, 0, ".ml");
CVJS_TYPE(DTrees, ml_DTrees, cv::Ptr<cv::ml::DTrees>, Ptr, ml_StatModel, 0, ".ml");
CVJS_TYPE(RTrees, ml_RTrees, cv::Ptr<cv::ml::RTrees>, Ptr, ml_DTrees, 0, ".ml");
CVJS_TYPE(Boost, ml_Boost, cv::Ptr<cv::ml::Boost>, Ptr, ml_DTrees, 0, ".ml");
CVJS_TYPE(ANN_MLP, ml_ANN_MLP, cv::Ptr<cv::ml::ANN_MLP>, Ptr, ml_StatModel, 0, ".ml");
CVJS_TYPE(LogisticRegression, ml_LogisticRegression, cv::Ptr<cv::ml::LogisticRegression>, Ptr, ml_StatModel, 0, ".ml");
CVJS_TYPE(SVMSGD, ml_SVMSGD, cv::Ptr<cv::ml::SVMSGD>, Ptr, ml_StatModel, 0, ".ml");
CVJS_TYPE(Tonemap, Tonemap, cv::Ptr<cv::Tonemap>, Ptr, Algorithm, 0, "");
CVJS_TYPE(TonemapDrago, TonemapDrago, cv::Ptr<cv::TonemapDrago>, Ptr, Tonemap, 0, "");
CVJS_TYPE(TonemapReinhard, TonemapReinhard, cv::Ptr<cv::TonemapReinhard>, Ptr, Tonemap, 0, "");
CVJS_TYPE(TonemapMantiuk, TonemapMantiuk, cv::Ptr<cv::TonemapMantiuk>, Ptr, Tonemap, 0, "");
CVJS_TYPE(AlignExposures, AlignExposures, cv::Ptr<cv::AlignExposures>, Ptr, Algorithm, 0, "");
CVJS_TYPE(AlignMTB, AlignMTB, cv::Ptr<cv::AlignMTB>, Ptr, AlignExposures, 0, "");
CVJS_TYPE(CalibrateCRF, CalibrateCRF, cv::Ptr<cv::CalibrateCRF>, Ptr, Algorithm, 0, "");
CVJS_TYPE(CalibrateDebevec, CalibrateDebevec, cv::Ptr<cv::CalibrateDebevec>, Ptr, CalibrateCRF, 0, "");
CVJS_TYPE(CalibrateRobertson, CalibrateRobertson, cv::Ptr<cv::CalibrateRobertson>, Ptr, CalibrateCRF, 0, "");
CVJS_TYPE(MergeExposures, MergeExposures, cv::Ptr<cv::MergeExposures>, Ptr, Algorithm, 0, "");
CVJS_TYPE(MergeDebevec, MergeDebevec, cv::Ptr<cv::MergeDebevec>, Ptr, MergeExposures, 0, "");
CVJS_TYPE(MergeMertens, MergeMertens, cv::Ptr<cv::MergeMertens>, Ptr, MergeExposures, 0, "");
CVJS_TYPE(MergeRobertson, MergeRobertson, cv::Ptr<cv::MergeRobertson>, Ptr, MergeExposures, 0, "");
CVJS_TYPE(Plot2d, plot_Plot2d, cv::Ptr<cv::plot::Plot2d>, Ptr, Algorithm, 0, ".plot");
CVJS_TYPE(QualityBase, quality_QualityBase, cv::Ptr<cv::quality::QualityBase>, Ptr, Algorithm, 0, ".quality");
CVJS_TYPE(QualityBRISQUE, quality_QualityBRISQUE, cv::Ptr<cv::quality::QualityBRISQUE>, Ptr, quality_QualityBase, 0, ".quality");
CVJS_TYPE(QualityGMSD, quality_QualityGMSD, cv::Ptr<cv::quality::QualityGMSD>, Ptr, quality_QualityBase, 0, ".quality");
CVJS_TYPE(QualityMSE, quality_QualityMSE, cv::Ptr<cv::quality::QualityMSE>, Ptr, quality_QualityBase, 0, ".quality");
CVJS_TYPE(QualityPSNR, quality_QualityPSNR, cv::Ptr<cv::quality::QualityPSNR>, Ptr, quality_QualityBase, 0, ".quality");
CVJS_TYPE(QualitySSIM, quality_QualitySSIM, cv::Ptr<cv::quality::QualitySSIM>, Ptr, quality_QualityBase, 0, ".quality");
CVJS_TYPE(DictValue, dnn_DictValue, cv::Ptr<cv::dnn::DictValue>, Ptr, NoBase, jsopencv_cv_dnn_dnn_DictValue_DictValue, ".dnn");
CVJS_TYPE(Layer, dnn_Layer, cv::Ptr<cv::dnn::Layer>, Ptr, Algorithm, 0, ".dnn");
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
CVJS_TYPE(DnnSuperResImpl, dnn_superres_DnnSuperResImpl, cv::Ptr<cv::dnn_superres::DnnSuperResImpl>, Ptr, NoBase, 0, ".dnn_superres");
CVJS_TYPE(Feature2D, Feature2D, cv::Ptr<cv::Feature2D>, Ptr, NoBase, 0, "");
CVJS_TYPE(AffineFeature, AffineFeature, cv::Ptr<cv::AffineFeature>, Ptr, Feature2D, 0, "");
CVJS_TYPE(SIFT, SIFT, cv::Ptr<cv::SIFT>, Ptr, Feature2D, 0, "");
CVJS_TYPE(BRISK, BRISK, cv::Ptr<cv::BRISK>, Ptr, Feature2D, 0, "");
CVJS_TYPE(ORB, ORB, cv::Ptr<cv::ORB>, Ptr, Feature2D, 0, "");
CVJS_TYPE(MSER, MSER, cv::Ptr<cv::MSER>, Ptr, Feature2D, 0, "");
CVJS_TYPE(FastFeatureDetector, FastFeatureDetector, cv::Ptr<cv::FastFeatureDetector>, Ptr, Feature2D, 0, "");
CVJS_TYPE(AgastFeatureDetector, AgastFeatureDetector, cv::Ptr<cv::AgastFeatureDetector>, Ptr, Feature2D, 0, "");
CVJS_TYPE(GFTTDetector, GFTTDetector, cv::Ptr<cv::GFTTDetector>, Ptr, Feature2D, 0, "");
CVJS_TYPE(SimpleBlobDetector, SimpleBlobDetector, cv::Ptr<cv::SimpleBlobDetector>, Ptr, Feature2D, 0, "");
CVJS_TYPE(Params, SimpleBlobDetector_Params, cv::SimpleBlobDetector::Params, Params, NoBase, jsopencv_cv_SimpleBlobDetector_Params_SimpleBlobDetector_Params, ".SimpleBlobDetector");
CVJS_TYPE(KAZE, KAZE, cv::Ptr<cv::KAZE>, Ptr, Feature2D, 0, "");
CVJS_TYPE(AKAZE, AKAZE, cv::Ptr<cv::AKAZE>, Ptr, Feature2D, 0, "");
CVJS_TYPE(DescriptorMatcher, DescriptorMatcher, cv::Ptr<cv::DescriptorMatcher>, Ptr, Algorithm, 0, "");
CVJS_TYPE(BFMatcher, BFMatcher, cv::Ptr<cv::BFMatcher>, Ptr, DescriptorMatcher, jsopencv_cv_BFMatcher_BFMatcher, "");
CVJS_TYPE(FlannBasedMatcher, FlannBasedMatcher, cv::Ptr<cv::FlannBasedMatcher>, Ptr, DescriptorMatcher, jsopencv_cv_FlannBasedMatcher_FlannBasedMatcher, "");
CVJS_TYPE(BOWTrainer, BOWTrainer, cv::Ptr<cv::BOWTrainer>, Ptr, NoBase, 0, "");
CVJS_TYPE(BOWKMeansTrainer, BOWKMeansTrainer, cv::Ptr<cv::BOWKMeansTrainer>, Ptr, BOWTrainer, jsopencv_cv_BOWKMeansTrainer_BOWKMeansTrainer, "");
CVJS_TYPE(BOWImgDescriptorExtractor, BOWImgDescriptorExtractor, cv::Ptr<cv::BOWImgDescriptorExtractor>, Ptr, NoBase, jsopencv_cv_BOWImgDescriptorExtractor_BOWImgDescriptorExtractor, "");
CVJS_TYPE(FreeType2, freetype_FreeType2, cv::Ptr<cv::freetype::FreeType2>, Ptr, Algorithm, 0, ".freetype");
CVJS_TYPE(ImgHashBase, img_hash_ImgHashBase, cv::Ptr<cv::img_hash::ImgHashBase>, Ptr, Algorithm, 0, ".img_hash");
CVJS_TYPE(AverageHash, img_hash_AverageHash, cv::Ptr<cv::img_hash::AverageHash>, Ptr, img_hash_ImgHashBase, 0, ".img_hash");
CVJS_TYPE(BlockMeanHash, img_hash_BlockMeanHash, cv::Ptr<cv::img_hash::BlockMeanHash>, Ptr, img_hash_ImgHashBase, 0, ".img_hash");
CVJS_TYPE(ColorMomentHash, img_hash_ColorMomentHash, cv::Ptr<cv::img_hash::ColorMomentHash>, Ptr, img_hash_ImgHashBase, 0, ".img_hash");
CVJS_TYPE(MarrHildrethHash, img_hash_MarrHildrethHash, cv::Ptr<cv::img_hash::MarrHildrethHash>, Ptr, img_hash_ImgHashBase, 0, ".img_hash");
CVJS_TYPE(PHash, img_hash_PHash, cv::Ptr<cv::img_hash::PHash>, Ptr, img_hash_ImgHashBase, 0, ".img_hash");
CVJS_TYPE(RadialVarianceHash, img_hash_RadialVarianceHash, cv::Ptr<cv::img_hash::RadialVarianceHash>, Ptr, img_hash_ImgHashBase, 0, ".img_hash");
CVJS_TYPE(ERFilter, text_ERFilter, cv::Ptr<cv::text::ERFilter>, Ptr, Algorithm, 0, ".text");
CVJS_TYPE(Callback, text_ERFilter_Callback, cv::Ptr<cv::text::ERFilter::Callback>, Ptr, NoBase, 0, ".text.ERFilter");
CVJS_TYPE(BaseOCR, text_BaseOCR, cv::Ptr<cv::text::BaseOCR>, Ptr, NoBase, 0, ".text");
CVJS_TYPE(OCRTesseract, text_OCRTesseract, cv::Ptr<cv::text::OCRTesseract>, Ptr, text_BaseOCR, 0, ".text");
CVJS_TYPE(OCRHMMDecoder, text_OCRHMMDecoder, cv::Ptr<cv::text::OCRHMMDecoder>, Ptr, text_BaseOCR, 0, ".text");
CVJS_TYPE(ClassifierCallback, text_OCRHMMDecoder_ClassifierCallback, cv::Ptr<cv::text::OCRHMMDecoder::ClassifierCallback>, Ptr, NoBase, 0, ".text.OCRHMMDecoder");
CVJS_TYPE(OCRBeamSearchDecoder, text_OCRBeamSearchDecoder, cv::Ptr<cv::text::OCRBeamSearchDecoder>, Ptr, text_BaseOCR, 0, ".text");
CVJS_TYPE(ClassifierCallback, text_OCRBeamSearchDecoder_ClassifierCallback, cv::Ptr<cv::text::OCRBeamSearchDecoder::ClassifierCallback>, Ptr, NoBase, 0, ".text.OCRBeamSearchDecoder");
CVJS_TYPE(TextDetector, text_TextDetector, cv::Ptr<cv::text::TextDetector>, Ptr, NoBase, 0, ".text");
CVJS_TYPE(TextDetectorCNN, text_TextDetectorCNN, cv::Ptr<cv::text::TextDetectorCNN>, Ptr, text_TextDetector, 0, ".text");
CVJS_TYPE(VideoCapture, VideoCapture, cv::Ptr<cv::VideoCapture>, Ptr, NoBase, jsopencv_cv_VideoCapture_VideoCapture, "");
CVJS_TYPE(VideoWriter, VideoWriter, cv::Ptr<cv::VideoWriter>, Ptr, NoBase, jsopencv_cv_VideoWriter_VideoWriter, "");
CVJS_TYPE(BarcodeDetector, barcode_BarcodeDetector, cv::Ptr<cv::barcode::BarcodeDetector>, Ptr, NoBase, jsopencv_cv_barcode_barcode_BarcodeDetector_BarcodeDetector, ".barcode");
CVJS_TYPE(UsacParams, UsacParams, cv::UsacParams, UsacParams, NoBase, jsopencv_cv_UsacParams_UsacParams, "");
CVJS_TYPE(CirclesGridFinderParameters, CirclesGridFinderParameters, cv::CirclesGridFinderParameters, CirclesGridFinderParameters, NoBase, jsopencv_cv_CirclesGridFinderParameters_CirclesGridFinderParameters, "");
CVJS_TYPE(StereoMatcher, StereoMatcher, cv::Ptr<cv::StereoMatcher>, Ptr, Algorithm, 0, "");
CVJS_TYPE(StereoBM, StereoBM, cv::Ptr<cv::StereoBM>, Ptr, StereoMatcher, 0, "");
CVJS_TYPE(StereoSGBM, StereoSGBM, cv::Ptr<cv::StereoSGBM>, Ptr, StereoMatcher, 0, "");
CVJS_TYPE(ColorCorrectionModel, ccm_ColorCorrectionModel, cv::Ptr<cv::ccm::ColorCorrectionModel>, Ptr, NoBase, jsopencv_cv_ccm_ccm_ColorCorrectionModel_ColorCorrectionModel, ".ccm");
CVJS_TYPE(DetectorParameters, mcc_DetectorParameters, cv::Ptr<cv::mcc::DetectorParameters>, Ptr, NoBase, 0, ".mcc");
CVJS_TYPE(CCheckerDetector, mcc_CCheckerDetector, cv::Ptr<cv::mcc::CCheckerDetector>, Ptr, Algorithm, 0, ".mcc");
CVJS_TYPE(CChecker, mcc_CChecker, cv::Ptr<cv::mcc::CChecker>, Ptr, NoBase, 0, ".mcc");
CVJS_TYPE(CCheckerDraw, mcc_CCheckerDraw, cv::Ptr<cv::mcc::CCheckerDraw>, Ptr, NoBase, 0, ".mcc");
CVJS_TYPE(BaseCascadeClassifier, BaseCascadeClassifier, cv::Ptr<cv::BaseCascadeClassifier>, Ptr, Algorithm, 0, "");
CVJS_TYPE(CascadeClassifier, CascadeClassifier, cv::Ptr<cv::CascadeClassifier>, Ptr, NoBase, jsopencv_cv_CascadeClassifier_CascadeClassifier, "");
CVJS_TYPE(HOGDescriptor, HOGDescriptor, cv::Ptr<cv::HOGDescriptor>, Ptr, NoBase, jsopencv_cv_HOGDescriptor_HOGDescriptor, "");
CVJS_TYPE(QRCodeEncoder, QRCodeEncoder, cv::Ptr<cv::QRCodeEncoder>, Ptr, NoBase, 0, "");
CVJS_TYPE(Params, QRCodeEncoder_Params, cv::QRCodeEncoder::Params, Params, NoBase, jsopencv_cv_QRCodeEncoder_Params_QRCodeEncoder_Params, ".QRCodeEncoder");
CVJS_TYPE(QRCodeDetector, QRCodeDetector, cv::Ptr<cv::QRCodeDetector>, Ptr, NoBase, jsopencv_cv_QRCodeDetector_QRCodeDetector, "");
CVJS_TYPE(Board, aruco_Board, cv::aruco::Board, Board, NoBase, jsopencv_cv_aruco_aruco_Board_Board, ".aruco");
CVJS_TYPE(GridBoard, aruco_GridBoard, cv::aruco::GridBoard, GridBoard, aruco_Board, jsopencv_cv_aruco_aruco_GridBoard_GridBoard, ".aruco");
CVJS_TYPE(CharucoBoard, aruco_CharucoBoard, cv::aruco::CharucoBoard, CharucoBoard, aruco_Board, jsopencv_cv_aruco_aruco_CharucoBoard_CharucoBoard, ".aruco");
CVJS_TYPE(DetectorParameters, aruco_DetectorParameters, cv::aruco::DetectorParameters, DetectorParameters, NoBase, jsopencv_cv_aruco_aruco_DetectorParameters_DetectorParameters, ".aruco");
CVJS_TYPE(RefineParameters, aruco_RefineParameters, cv::aruco::RefineParameters, RefineParameters, NoBase, jsopencv_cv_aruco_aruco_RefineParameters_RefineParameters, ".aruco");
CVJS_TYPE(ArucoDetector, aruco_ArucoDetector, cv::Ptr<cv::aruco::ArucoDetector>, Ptr, Algorithm, jsopencv_cv_aruco_aruco_ArucoDetector_ArucoDetector, ".aruco");
CVJS_TYPE(Dictionary, aruco_Dictionary, cv::aruco::Dictionary, Dictionary, NoBase, jsopencv_cv_aruco_aruco_Dictionary_Dictionary, ".aruco");
CVJS_TYPE(CharucoParameters, aruco_CharucoParameters, cv::aruco::CharucoParameters, CharucoParameters, NoBase, 0, ".aruco");
CVJS_TYPE(CharucoDetector, aruco_CharucoDetector, cv::Ptr<cv::aruco::CharucoDetector>, Ptr, Algorithm, jsopencv_cv_aruco_aruco_CharucoDetector_CharucoDetector, ".aruco");
CVJS_TYPE(FaceDetectorYN, FaceDetectorYN, cv::Ptr<cv::FaceDetectorYN>, Ptr, NoBase, 0, "");
CVJS_TYPE(FaceRecognizerSF, FaceRecognizerSF, cv::Ptr<cv::FaceRecognizerSF>, Ptr, NoBase, 0, "");
CVJS_TYPE(Tracker, rapid_Tracker, cv::Ptr<cv::rapid::Tracker>, Ptr, Algorithm, 0, ".rapid");
CVJS_TYPE(Rapid, rapid_Rapid, cv::Ptr<cv::rapid::Rapid>, Ptr, rapid_Tracker, 0, ".rapid");
CVJS_TYPE(OLSTracker, rapid_OLSTracker, cv::Ptr<cv::rapid::OLSTracker>, Ptr, rapid_Tracker, 0, ".rapid");
CVJS_TYPE(GOSTracker, rapid_GOSTracker, cv::Ptr<cv::rapid::GOSTracker>, Ptr, rapid_Tracker, 0, ".rapid");
CVJS_TYPE(BackgroundSubtractor, BackgroundSubtractor, cv::Ptr<cv::BackgroundSubtractor>, Ptr, Algorithm, 0, "");
CVJS_TYPE(BackgroundSubtractorMOG2, BackgroundSubtractorMOG2, cv::Ptr<cv::BackgroundSubtractorMOG2>, Ptr, BackgroundSubtractor, 0, "");
CVJS_TYPE(BackgroundSubtractorKNN, BackgroundSubtractorKNN, cv::Ptr<cv::BackgroundSubtractorKNN>, Ptr, BackgroundSubtractor, 0, "");
CVJS_TYPE(KalmanFilter, KalmanFilter, cv::Ptr<cv::KalmanFilter>, Ptr, NoBase, jsopencv_cv_KalmanFilter_KalmanFilter, "");
CVJS_TYPE(DenseOpticalFlow, DenseOpticalFlow, cv::Ptr<cv::DenseOpticalFlow>, Ptr, Algorithm, 0, "");
CVJS_TYPE(SparseOpticalFlow, SparseOpticalFlow, cv::Ptr<cv::SparseOpticalFlow>, Ptr, Algorithm, 0, "");
CVJS_TYPE(FarnebackOpticalFlow, FarnebackOpticalFlow, cv::Ptr<cv::FarnebackOpticalFlow>, Ptr, DenseOpticalFlow, 0, "");
CVJS_TYPE(VariationalRefinement, VariationalRefinement, cv::Ptr<cv::VariationalRefinement>, Ptr, DenseOpticalFlow, 0, "");
CVJS_TYPE(DISOpticalFlow, DISOpticalFlow, cv::Ptr<cv::DISOpticalFlow>, Ptr, DenseOpticalFlow, 0, "");
CVJS_TYPE(SparsePyrLKOpticalFlow, SparsePyrLKOpticalFlow, cv::Ptr<cv::SparsePyrLKOpticalFlow>, Ptr, SparseOpticalFlow, 0, "");
CVJS_TYPE(Tracker, Tracker, cv::Ptr<cv::Tracker>, Ptr, NoBase, 0, "");
CVJS_TYPE(TrackerMIL, TrackerMIL, cv::Ptr<cv::TrackerMIL>, Ptr, Tracker, 0, "");
CVJS_TYPE(Params, TrackerMIL_Params, cv::TrackerMIL::Params, Params, NoBase, jsopencv_cv_TrackerMIL_Params_TrackerMIL_Params, ".TrackerMIL");
CVJS_TYPE(TrackerGOTURN, TrackerGOTURN, cv::Ptr<cv::TrackerGOTURN>, Ptr, Tracker, 0, "");
CVJS_TYPE(Params, TrackerGOTURN_Params, cv::TrackerGOTURN::Params, Params, NoBase, jsopencv_cv_TrackerGOTURN_Params_TrackerGOTURN_Params, ".TrackerGOTURN");
CVJS_TYPE(TrackerDaSiamRPN, TrackerDaSiamRPN, cv::Ptr<cv::TrackerDaSiamRPN>, Ptr, Tracker, 0, "");
CVJS_TYPE(Params, TrackerDaSiamRPN_Params, cv::TrackerDaSiamRPN::Params, Params, NoBase, jsopencv_cv_TrackerDaSiamRPN_Params_TrackerDaSiamRPN_Params, ".TrackerDaSiamRPN");
CVJS_TYPE(TrackerNano, TrackerNano, cv::Ptr<cv::TrackerNano>, Ptr, Tracker, 0, "");
CVJS_TYPE(Params, TrackerNano_Params, cv::TrackerNano::Params, Params, NoBase, jsopencv_cv_TrackerNano_Params_TrackerNano_Params, ".TrackerNano");
CVJS_TYPE(FREAK, xfeatures2d_FREAK, cv::Ptr<cv::xfeatures2d::FREAK>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(StarDetector, xfeatures2d_StarDetector, cv::Ptr<cv::xfeatures2d::StarDetector>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(BriefDescriptorExtractor, xfeatures2d_BriefDescriptorExtractor, cv::Ptr<cv::xfeatures2d::BriefDescriptorExtractor>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(LUCID, xfeatures2d_LUCID, cv::Ptr<cv::xfeatures2d::LUCID>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(LATCH, xfeatures2d_LATCH, cv::Ptr<cv::xfeatures2d::LATCH>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(BEBLID, xfeatures2d_BEBLID, cv::Ptr<cv::xfeatures2d::BEBLID>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(TEBLID, xfeatures2d_TEBLID, cv::Ptr<cv::xfeatures2d::TEBLID>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(DAISY, xfeatures2d_DAISY, cv::Ptr<cv::xfeatures2d::DAISY>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(MSDDetector, xfeatures2d_MSDDetector, cv::Ptr<cv::xfeatures2d::MSDDetector>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(VGG, xfeatures2d_VGG, cv::Ptr<cv::xfeatures2d::VGG>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(BoostDesc, xfeatures2d_BoostDesc, cv::Ptr<cv::xfeatures2d::BoostDesc>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(PCTSignatures, xfeatures2d_PCTSignatures, cv::Ptr<cv::xfeatures2d::PCTSignatures>, Ptr, Algorithm, 0, ".xfeatures2d");
CVJS_TYPE(PCTSignaturesSQFD, xfeatures2d_PCTSignaturesSQFD, cv::Ptr<cv::xfeatures2d::PCTSignaturesSQFD>, Ptr, Algorithm, 0, ".xfeatures2d");
CVJS_TYPE(HarrisLaplaceFeatureDetector, xfeatures2d_HarrisLaplaceFeatureDetector, cv::Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(AffineFeature2D, xfeatures2d_AffineFeature2D, cv::Ptr<cv::xfeatures2d::AffineFeature2D>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(TBMR, xfeatures2d_TBMR, cv::Ptr<cv::xfeatures2d::TBMR>, Ptr, xfeatures2d_AffineFeature2D, 0, ".xfeatures2d");
CVJS_TYPE(SURF_CUDA, cuda_SURF_CUDA, cv::Ptr<cv::cuda::SURF_CUDA>, Ptr, NoBase, 0, ".cuda");
CVJS_TYPE(SURF, xfeatures2d_SURF, cv::Ptr<cv::xfeatures2d::SURF>, Ptr, Feature2D, 0, ".xfeatures2d");
CVJS_TYPE(DisparityFilter, ximgproc_DisparityFilter, cv::Ptr<cv::ximgproc::DisparityFilter>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(DisparityWLSFilter, ximgproc_DisparityWLSFilter, cv::Ptr<cv::ximgproc::DisparityWLSFilter>, Ptr, ximgproc_DisparityFilter, 0, ".ximgproc");
CVJS_TYPE(EdgeDrawing, ximgproc_EdgeDrawing, cv::Ptr<cv::ximgproc::EdgeDrawing>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(Params, ximgproc_EdgeDrawing_Params, cv::ximgproc::EdgeDrawing::Params, Params, NoBase, jsopencv_cv_ximgproc_ximgproc_EdgeDrawing_Params_EdgeDrawing_Params, ".ximgproc.EdgeDrawing");
CVJS_TYPE(DTFilter, ximgproc_DTFilter, cv::Ptr<cv::ximgproc::DTFilter>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(GuidedFilter, ximgproc_GuidedFilter, cv::Ptr<cv::ximgproc::GuidedFilter>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(AdaptiveManifoldFilter, ximgproc_AdaptiveManifoldFilter, cv::Ptr<cv::ximgproc::AdaptiveManifoldFilter>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(FastBilateralSolverFilter, ximgproc_FastBilateralSolverFilter, cv::Ptr<cv::ximgproc::FastBilateralSolverFilter>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(FastGlobalSmootherFilter, ximgproc_FastGlobalSmootherFilter, cv::Ptr<cv::ximgproc::FastGlobalSmootherFilter>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(EdgeBoxes, ximgproc_EdgeBoxes, cv::Ptr<cv::ximgproc::EdgeBoxes>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(FastLineDetector, ximgproc_FastLineDetector, cv::Ptr<cv::ximgproc::FastLineDetector>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(ContourFitting, ximgproc_ContourFitting, cv::Ptr<cv::ximgproc::ContourFitting>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(SuperpixelLSC, ximgproc_SuperpixelLSC, cv::Ptr<cv::ximgproc::SuperpixelLSC>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(RidgeDetectionFilter, ximgproc_RidgeDetectionFilter, cv::Ptr<cv::ximgproc::RidgeDetectionFilter>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(ScanSegment, ximgproc_ScanSegment, cv::Ptr<cv::ximgproc::ScanSegment>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(SuperpixelSEEDS, ximgproc_SuperpixelSEEDS, cv::Ptr<cv::ximgproc::SuperpixelSEEDS>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(GraphSegmentation, ximgproc_segmentation_GraphSegmentation, cv::Ptr<cv::ximgproc::segmentation::GraphSegmentation>, Ptr, Algorithm, 0, ".ximgproc.segmentation");
CVJS_TYPE(SelectiveSearchSegmentationStrategy, ximgproc_segmentation_SelectiveSearchSegmentationStrategy, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>, Ptr, Algorithm, 0, ".ximgproc.segmentation");
CVJS_TYPE(SelectiveSearchSegmentationStrategyColor, ximgproc_segmentation_SelectiveSearchSegmentationStrategyColor, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyColor>, Ptr, ximgproc_segmentation_SelectiveSearchSegmentationStrategy, 0, ".ximgproc.segmentation");
CVJS_TYPE(SelectiveSearchSegmentationStrategySize, ximgproc_segmentation_SelectiveSearchSegmentationStrategySize, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategySize>, Ptr, ximgproc_segmentation_SelectiveSearchSegmentationStrategy, 0, ".ximgproc.segmentation");
CVJS_TYPE(SelectiveSearchSegmentationStrategyTexture, ximgproc_segmentation_SelectiveSearchSegmentationStrategyTexture, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyTexture>, Ptr, ximgproc_segmentation_SelectiveSearchSegmentationStrategy, 0, ".ximgproc.segmentation");
CVJS_TYPE(SelectiveSearchSegmentationStrategyFill, ximgproc_segmentation_SelectiveSearchSegmentationStrategyFill, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyFill>, Ptr, ximgproc_segmentation_SelectiveSearchSegmentationStrategy, 0, ".ximgproc.segmentation");
CVJS_TYPE(SelectiveSearchSegmentationStrategyMultiple, ximgproc_segmentation_SelectiveSearchSegmentationStrategyMultiple, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>, Ptr, ximgproc_segmentation_SelectiveSearchSegmentationStrategy, 0, ".ximgproc.segmentation");
CVJS_TYPE(SelectiveSearchSegmentation, ximgproc_segmentation_SelectiveSearchSegmentation, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentation>, Ptr, Algorithm, 0, ".ximgproc.segmentation");
CVJS_TYPE(SuperpixelSLIC, ximgproc_SuperpixelSLIC, cv::Ptr<cv::ximgproc::SuperpixelSLIC>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(SparseMatchInterpolator, ximgproc_SparseMatchInterpolator, cv::Ptr<cv::ximgproc::SparseMatchInterpolator>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(EdgeAwareInterpolator, ximgproc_EdgeAwareInterpolator, cv::Ptr<cv::ximgproc::EdgeAwareInterpolator>, Ptr, ximgproc_SparseMatchInterpolator, 0, ".ximgproc");
CVJS_TYPE(RICInterpolator, ximgproc_RICInterpolator, cv::Ptr<cv::ximgproc::RICInterpolator>, Ptr, ximgproc_SparseMatchInterpolator, 0, ".ximgproc");
CVJS_TYPE(RFFeatureGetter, ximgproc_RFFeatureGetter, cv::Ptr<cv::ximgproc::RFFeatureGetter>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(StructuredEdgeDetection, ximgproc_StructuredEdgeDetection, cv::Ptr<cv::ximgproc::StructuredEdgeDetection>, Ptr, Algorithm, 0, ".ximgproc");
CVJS_TYPE(FaceRecognizer, face_FaceRecognizer, cv::Ptr<cv::face::FaceRecognizer>, Ptr, Algorithm, 0, ".face");
CVJS_TYPE(BIF, face_BIF, cv::Ptr<cv::face::BIF>, Ptr, Algorithm, 0, ".face");
CVJS_TYPE(Facemark, face_Facemark, cv::Ptr<cv::face::Facemark>, Ptr, Algorithm, 0, ".face");
CVJS_TYPE(FacemarkKazemi, face_FacemarkKazemi, cv::Ptr<cv::face::FacemarkKazemi>, Ptr, face_Facemark, 0, ".face");
CVJS_TYPE(FacemarkTrain, face_FacemarkTrain, cv::Ptr<cv::face::FacemarkTrain>, Ptr, face_Facemark, 0, ".face");
CVJS_TYPE(FacemarkAAM, face_FacemarkAAM, cv::Ptr<cv::face::FacemarkAAM>, Ptr, face_FacemarkTrain, 0, ".face");
CVJS_TYPE(FacemarkLBF, face_FacemarkLBF, cv::Ptr<cv::face::FacemarkLBF>, Ptr, face_FacemarkTrain, 0, ".face");
CVJS_TYPE(BasicFaceRecognizer, face_BasicFaceRecognizer, cv::Ptr<cv::face::BasicFaceRecognizer>, Ptr, face_FaceRecognizer, 0, ".face");
CVJS_TYPE(EigenFaceRecognizer, face_EigenFaceRecognizer, cv::Ptr<cv::face::EigenFaceRecognizer>, Ptr, face_BasicFaceRecognizer, 0, ".face");
CVJS_TYPE(FisherFaceRecognizer, face_FisherFaceRecognizer, cv::Ptr<cv::face::FisherFaceRecognizer>, Ptr, face_BasicFaceRecognizer, 0, ".face");
CVJS_TYPE(LBPHFaceRecognizer, face_LBPHFaceRecognizer, cv::Ptr<cv::face::LBPHFaceRecognizer>, Ptr, face_FaceRecognizer, 0, ".face");
CVJS_TYPE(MACE, face_MACE, cv::Ptr<cv::face::MACE>, Ptr, Algorithm, 0, ".face");
CVJS_TYPE(PredictCollector, face_PredictCollector, cv::Ptr<cv::face::PredictCollector>, Ptr, NoBase, 0, ".face");
CVJS_TYPE(StandardCollector, face_StandardCollector, cv::Ptr<cv::face::StandardCollector>, Ptr, face_PredictCollector, 0, ".face");
CVJS_TYPE(GArrayDesc, GArrayDesc, cv::GArrayDesc, GArrayDesc, NoBase, 0, "");
CVJS_TYPE(GComputation, GComputation, cv::Ptr<cv::GComputation>, Ptr, NoBase, jsopencv_cv_GComputation_GComputation, "");
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
CVJS_TYPE(GStreamerPipeline, gapi_wip_gst_GStreamerPipeline, cv::Ptr<cv::gapi::wip::gst::GStreamerPipeline>, Ptr, NoBase, jsopencv_cv_gapi_wip_gst_gapi_wip_gst_GStreamerPipeline_GStreamerPipeline, ".gapi.wip.gst");
CVJS_TYPE(GOpaqueT, GOpaqueT, cv::GOpaqueT, GOpaqueT, NoBase, jsopencv_cv_GOpaqueT_GOpaqueT, "");
CVJS_TYPE(GArrayT, GArrayT, cv::GArrayT, GArrayT, NoBase, jsopencv_cv_GArrayT_GArrayT, "");
CVJS_TYPE(GOutputs, gapi_wip_GOutputs, cv::gapi::wip::GOutputs, GOutputs, NoBase, 0, ".gapi.wip");
CVJS_TYPE(GCompileArg, GCompileArg, cv::GCompileArg, GCompileArg, NoBase, jsopencv_cv_GCompileArg_GCompileArg, "");
CVJS_TYPE(GInferInputs, GInferInputs, cv::GInferInputs, GInferInputs, NoBase, jsopencv_cv_GInferInputs_GInferInputs, "");
CVJS_TYPE(GInferListInputs, GInferListInputs, cv::GInferListInputs, GInferListInputs, NoBase, jsopencv_cv_GInferListInputs_GInferListInputs, "");
CVJS_TYPE(GInferOutputs, GInferOutputs, cv::GInferOutputs, GInferOutputs, NoBase, jsopencv_cv_GInferOutputs_GInferOutputs, "");
CVJS_TYPE(GInferListOutputs, GInferListOutputs, cv::GInferListOutputs, GInferListOutputs, NoBase, jsopencv_cv_GInferListOutputs_GInferListOutputs, "");
CVJS_TYPE(IStreamSource, gapi_wip_IStreamSource, cv::Ptr<cv::gapi::wip::IStreamSource>, Ptr, NoBase, 0, ".gapi.wip");
CVJS_TYPE(TrackerCSRT, TrackerCSRT, cv::Ptr<cv::TrackerCSRT>, Ptr, Tracker, 0, "");
CVJS_TYPE(Params, TrackerCSRT_Params, cv::TrackerCSRT::Params, Params, NoBase, jsopencv_cv_TrackerCSRT_Params_TrackerCSRT_Params, ".TrackerCSRT");
CVJS_TYPE(TrackerKCF, TrackerKCF, cv::Ptr<cv::TrackerKCF>, Ptr, Tracker, 0, "");
CVJS_TYPE(Params, TrackerKCF_Params, cv::TrackerKCF::Params, Params, NoBase, jsopencv_cv_TrackerKCF_Params_TrackerKCF_Params, ".TrackerKCF");
CVJS_TYPE(Tracker, legacy_Tracker, cv::Ptr<cv::legacy::Tracker>, Ptr, Algorithm, 0, ".legacy");
CVJS_TYPE(TrackerMIL, legacy_TrackerMIL, cv::Ptr<cv::legacy::TrackerMIL>, Ptr, legacy_Tracker, 0, ".legacy");
CVJS_TYPE(TrackerBoosting, legacy_TrackerBoosting, cv::Ptr<cv::legacy::TrackerBoosting>, Ptr, legacy_Tracker, 0, ".legacy");
CVJS_TYPE(TrackerMedianFlow, legacy_TrackerMedianFlow, cv::Ptr<cv::legacy::TrackerMedianFlow>, Ptr, legacy_Tracker, 0, ".legacy");
CVJS_TYPE(TrackerTLD, legacy_TrackerTLD, cv::Ptr<cv::legacy::TrackerTLD>, Ptr, legacy_Tracker, 0, ".legacy");
CVJS_TYPE(TrackerKCF, legacy_TrackerKCF, cv::Ptr<cv::legacy::TrackerKCF>, Ptr, legacy_Tracker, 0, ".legacy");
CVJS_TYPE(TrackerMOSSE, legacy_TrackerMOSSE, cv::Ptr<cv::legacy::TrackerMOSSE>, Ptr, legacy_Tracker, 0, ".legacy");
CVJS_TYPE(MultiTracker, legacy_MultiTracker, cv::Ptr<cv::legacy::MultiTracker>, Ptr, Algorithm, jsopencv_cv_legacy_legacy_MultiTracker_MultiTracker, ".legacy");
CVJS_TYPE(TrackerCSRT, legacy_TrackerCSRT, cv::Ptr<cv::legacy::TrackerCSRT>, Ptr, legacy_Tracker, 0, ".legacy");
#endif