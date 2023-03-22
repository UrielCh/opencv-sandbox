#include <napi.h>
#include <../parse.hh>
#include <../node/cv2_convert.hpp>
#include <../node/jscompat.hpp>

typedef cv::AKAZE::DescriptorType AKAZE_DescriptorType;
CV_JS_FROM_ENUM(AKAZE_DescriptorType);
CV_JS_TO_ENUM(AKAZE_DescriptorType);

CV_JS_FROM_ENUM(AccessFlag);
CV_JS_TO_ENUM(AccessFlag);

CV_JS_FROM_ENUM(AdaptiveThresholdTypes);
CV_JS_TO_ENUM(AdaptiveThresholdTypes);

typedef cv::AgastFeatureDetector::DetectorType AgastFeatureDetector_DetectorType;
CV_JS_FROM_ENUM(AgastFeatureDetector_DetectorType);
CV_JS_TO_ENUM(AgastFeatureDetector_DetectorType);

CV_JS_FROM_ENUM(BorderTypes);
CV_JS_TO_ENUM(BorderTypes);

typedef cv::CirclesGridFinderParameters::GridType CirclesGridFinderParameters_GridType;
CV_JS_FROM_ENUM(CirclesGridFinderParameters_GridType);
CV_JS_TO_ENUM(CirclesGridFinderParameters_GridType);

CV_JS_FROM_ENUM(CmpTypes);
CV_JS_TO_ENUM(CmpTypes);

CV_JS_FROM_ENUM(ColorConversionCodes);
CV_JS_TO_ENUM(ColorConversionCodes);

CV_JS_FROM_ENUM(ColormapTypes);
CV_JS_TO_ENUM(ColormapTypes);

CV_JS_FROM_ENUM(ConnectedComponentsAlgorithmsTypes);
CV_JS_TO_ENUM(ConnectedComponentsAlgorithmsTypes);

CV_JS_FROM_ENUM(ConnectedComponentsTypes);
CV_JS_TO_ENUM(ConnectedComponentsTypes);

CV_JS_FROM_ENUM(ContourApproximationModes);
CV_JS_TO_ENUM(ContourApproximationModes);

CV_JS_FROM_ENUM(CovarFlags);
CV_JS_TO_ENUM(CovarFlags);

CV_JS_FROM_ENUM(DecompTypes);
CV_JS_TO_ENUM(DecompTypes);

typedef cv::DescriptorMatcher::MatcherType DescriptorMatcher_MatcherType;
CV_JS_FROM_ENUM(DescriptorMatcher_MatcherType);
CV_JS_TO_ENUM(DescriptorMatcher_MatcherType);

CV_JS_FROM_ENUM(DftFlags);
CV_JS_TO_ENUM(DftFlags);

CV_JS_FROM_ENUM(DistanceTransformLabelTypes);
CV_JS_TO_ENUM(DistanceTransformLabelTypes);

CV_JS_FROM_ENUM(DistanceTransformMasks);
CV_JS_TO_ENUM(DistanceTransformMasks);

CV_JS_FROM_ENUM(DistanceTypes);
CV_JS_TO_ENUM(DistanceTypes);

CV_JS_FROM_ENUM(DrawMatchesFlags);
CV_JS_TO_ENUM(DrawMatchesFlags);

typedef cv::Error::Code Error_Code;
CV_JS_FROM_ENUM(Error_Code);
CV_JS_TO_ENUM(Error_Code);

typedef cv::FaceRecognizerSF::DisType FaceRecognizerSF_DisType;
CV_JS_FROM_ENUM(FaceRecognizerSF_DisType);
CV_JS_TO_ENUM(FaceRecognizerSF_DisType);

typedef cv::FastFeatureDetector::DetectorType FastFeatureDetector_DetectorType;
CV_JS_FROM_ENUM(FastFeatureDetector_DetectorType);
CV_JS_TO_ENUM(FastFeatureDetector_DetectorType);

typedef cv::FileStorage::Mode FileStorage_Mode;
CV_JS_FROM_ENUM(FileStorage_Mode);
CV_JS_TO_ENUM(FileStorage_Mode);

typedef cv::FileStorage::State FileStorage_State;
CV_JS_FROM_ENUM(FileStorage_State);
CV_JS_TO_ENUM(FileStorage_State);

CV_JS_FROM_ENUM(FloodFillFlags);
CV_JS_TO_ENUM(FloodFillFlags);

typedef cv::Formatter::FormatType Formatter_FormatType;
CV_JS_FROM_ENUM(Formatter_FormatType);
CV_JS_TO_ENUM(Formatter_FormatType);

typedef cv::GFluidKernel::Kind GFluidKernel_Kind;
CV_JS_FROM_ENUM(GFluidKernel_Kind);
CV_JS_TO_ENUM(GFluidKernel_Kind);

CV_JS_FROM_ENUM(GShape);
CV_JS_TO_ENUM(GShape);

CV_JS_FROM_ENUM(GemmFlags);
CV_JS_TO_ENUM(GemmFlags);

CV_JS_FROM_ENUM(GrabCutClasses);
CV_JS_TO_ENUM(GrabCutClasses);

CV_JS_FROM_ENUM(GrabCutModes);
CV_JS_TO_ENUM(GrabCutModes);

typedef cv::HOGDescriptor::DescriptorStorageFormat HOGDescriptor_DescriptorStorageFormat;
CV_JS_FROM_ENUM(HOGDescriptor_DescriptorStorageFormat);
CV_JS_TO_ENUM(HOGDescriptor_DescriptorStorageFormat);

typedef cv::HOGDescriptor::HistogramNormType HOGDescriptor_HistogramNormType;
CV_JS_FROM_ENUM(HOGDescriptor_HistogramNormType);
CV_JS_TO_ENUM(HOGDescriptor_HistogramNormType);

CV_JS_FROM_ENUM(HandEyeCalibrationMethod);
CV_JS_TO_ENUM(HandEyeCalibrationMethod);

CV_JS_FROM_ENUM(HersheyFonts);
CV_JS_TO_ENUM(HersheyFonts);

CV_JS_FROM_ENUM(HistCompMethods);
CV_JS_TO_ENUM(HistCompMethods);

CV_JS_FROM_ENUM(HoughModes);
CV_JS_TO_ENUM(HoughModes);

CV_JS_FROM_ENUM(ImreadModes);
CV_JS_TO_ENUM(ImreadModes);

CV_JS_FROM_ENUM(ImwriteEXRCompressionFlags);
CV_JS_TO_ENUM(ImwriteEXRCompressionFlags);

CV_JS_FROM_ENUM(ImwriteEXRTypeFlags);
CV_JS_TO_ENUM(ImwriteEXRTypeFlags);

CV_JS_FROM_ENUM(ImwriteFlags);
CV_JS_TO_ENUM(ImwriteFlags);

CV_JS_FROM_ENUM(ImwriteHDRCompressionFlags);
CV_JS_TO_ENUM(ImwriteHDRCompressionFlags);

CV_JS_FROM_ENUM(ImwriteJPEGSamplingFactorParams);
CV_JS_TO_ENUM(ImwriteJPEGSamplingFactorParams);

CV_JS_FROM_ENUM(ImwritePAMFlags);
CV_JS_TO_ENUM(ImwritePAMFlags);

CV_JS_FROM_ENUM(ImwritePNGFlags);
CV_JS_TO_ENUM(ImwritePNGFlags);

CV_JS_FROM_ENUM(InterpolationFlags);
CV_JS_TO_ENUM(InterpolationFlags);

CV_JS_FROM_ENUM(InterpolationMasks);
CV_JS_TO_ENUM(InterpolationMasks);

typedef cv::KAZE::DiffusivityType KAZE_DiffusivityType;
CV_JS_FROM_ENUM(KAZE_DiffusivityType);
CV_JS_TO_ENUM(KAZE_DiffusivityType);

CV_JS_FROM_ENUM(KmeansFlags);
CV_JS_TO_ENUM(KmeansFlags);

CV_JS_FROM_ENUM(LineSegmentDetectorModes);
CV_JS_TO_ENUM(LineSegmentDetectorModes);

CV_JS_FROM_ENUM(LineTypes);
CV_JS_TO_ENUM(LineTypes);

CV_JS_FROM_ENUM(LocalOptimMethod);
CV_JS_TO_ENUM(LocalOptimMethod);

CV_JS_FROM_ENUM(MarkerTypes);
CV_JS_TO_ENUM(MarkerTypes);

CV_JS_FROM_ENUM(MediaFormat);
CV_JS_TO_ENUM(MediaFormat);

typedef cv::MediaFrame::Access MediaFrame_Access;
CV_JS_FROM_ENUM(MediaFrame_Access);
CV_JS_TO_ENUM(MediaFrame_Access);

CV_JS_FROM_ENUM(MorphShapes);
CV_JS_TO_ENUM(MorphShapes);

CV_JS_FROM_ENUM(MorphTypes);
CV_JS_TO_ENUM(MorphTypes);

CV_JS_FROM_ENUM(MouseEventFlags);
CV_JS_TO_ENUM(MouseEventFlags);

CV_JS_FROM_ENUM(MouseEventTypes);
CV_JS_TO_ENUM(MouseEventTypes);

CV_JS_FROM_ENUM(NeighborSearchMethod);
CV_JS_TO_ENUM(NeighborSearchMethod);

CV_JS_FROM_ENUM(NormTypes);
CV_JS_TO_ENUM(NormTypes);

typedef cv::ORB::ScoreType ORB_ScoreType;
CV_JS_FROM_ENUM(ORB_ScoreType);
CV_JS_TO_ENUM(ORB_ScoreType);

typedef cv::PCA::Flags PCA_Flags;
CV_JS_FROM_ENUM(PCA_Flags);
CV_JS_TO_ENUM(PCA_Flags);

CV_JS_FROM_ENUM(Param);
CV_JS_TO_ENUM(Param);

typedef cv::QRCodeEncoder::CorrectionLevel QRCodeEncoder_CorrectionLevel;
CV_JS_FROM_ENUM(QRCodeEncoder_CorrectionLevel);
CV_JS_TO_ENUM(QRCodeEncoder_CorrectionLevel);

typedef cv::QRCodeEncoder::ECIEncodings QRCodeEncoder_ECIEncodings;
CV_JS_FROM_ENUM(QRCodeEncoder_ECIEncodings);
CV_JS_TO_ENUM(QRCodeEncoder_ECIEncodings);

typedef cv::QRCodeEncoder::EncodeMode QRCodeEncoder_EncodeMode;
CV_JS_FROM_ENUM(QRCodeEncoder_EncodeMode);
CV_JS_TO_ENUM(QRCodeEncoder_EncodeMode);

CV_JS_FROM_ENUM(QtButtonTypes);
CV_JS_TO_ENUM(QtButtonTypes);

CV_JS_FROM_ENUM(QtFontStyles);
CV_JS_TO_ENUM(QtFontStyles);

CV_JS_FROM_ENUM(QtFontWeights);
CV_JS_TO_ENUM(QtFontWeights);

CV_JS_FROM_ENUM(QuatAssumeType);
CV_JS_TO_ENUM(QuatAssumeType);

typedef cv::QuatEnum::EulerAnglesType QuatEnum_EulerAnglesType;
CV_JS_FROM_ENUM(QuatEnum_EulerAnglesType);
CV_JS_TO_ENUM(QuatEnum_EulerAnglesType);

typedef cv::RMat::Access RMat_Access;
CV_JS_FROM_ENUM(RMat_Access);
CV_JS_TO_ENUM(RMat_Access);

CV_JS_FROM_ENUM(RectanglesIntersectTypes);
CV_JS_TO_ENUM(RectanglesIntersectTypes);

CV_JS_FROM_ENUM(ReduceTypes);
CV_JS_TO_ENUM(ReduceTypes);

CV_JS_FROM_ENUM(RetrievalModes);
CV_JS_TO_ENUM(RetrievalModes);

CV_JS_FROM_ENUM(RobotWorldHandEyeCalibrationMethod);
CV_JS_TO_ENUM(RobotWorldHandEyeCalibrationMethod);

CV_JS_FROM_ENUM(RotateFlags);
CV_JS_TO_ENUM(RotateFlags);

typedef cv::SVD::Flags SVD_Flags;
CV_JS_FROM_ENUM(SVD_Flags);
CV_JS_TO_ENUM(SVD_Flags);

CV_JS_FROM_ENUM(SamplingMethod);
CV_JS_TO_ENUM(SamplingMethod);

CV_JS_FROM_ENUM(ScoreMethod);
CV_JS_TO_ENUM(ScoreMethod);

CV_JS_FROM_ENUM(ShapeMatchModes);
CV_JS_TO_ENUM(ShapeMatchModes);

CV_JS_FROM_ENUM(SolveLPResult);
CV_JS_TO_ENUM(SolveLPResult);

CV_JS_FROM_ENUM(SolvePnPMethod);
CV_JS_TO_ENUM(SolvePnPMethod);

CV_JS_FROM_ENUM(SortFlags);
CV_JS_TO_ENUM(SortFlags);

CV_JS_FROM_ENUM(SpecialFilter);
CV_JS_TO_ENUM(SpecialFilter);

CV_JS_FROM_ENUM(TemplateMatchModes);
CV_JS_TO_ENUM(TemplateMatchModes);

typedef cv::TermCriteria::Type TermCriteria_Type;
CV_JS_FROM_ENUM(TermCriteria_Type);
CV_JS_TO_ENUM(TermCriteria_Type);

CV_JS_FROM_ENUM(ThresholdTypes);
CV_JS_TO_ENUM(ThresholdTypes);

typedef cv::TrackerKCF::MODE TrackerKCF_MODE;
CV_JS_FROM_ENUM(TrackerKCF_MODE);
CV_JS_TO_ENUM(TrackerKCF_MODE);

typedef cv::UMatData::MemoryFlag UMatData_MemoryFlag;
CV_JS_FROM_ENUM(UMatData_MemoryFlag);
CV_JS_TO_ENUM(UMatData_MemoryFlag);

CV_JS_FROM_ENUM(UMatUsageFlags);
CV_JS_TO_ENUM(UMatUsageFlags);

CV_JS_FROM_ENUM(UndistortTypes);
CV_JS_TO_ENUM(UndistortTypes);

CV_JS_FROM_ENUM(VideoAccelerationType);
CV_JS_TO_ENUM(VideoAccelerationType);

CV_JS_FROM_ENUM(VideoCaptureAPIs);
CV_JS_TO_ENUM(VideoCaptureAPIs);

CV_JS_FROM_ENUM(VideoCaptureOBSensorDataType);
CV_JS_TO_ENUM(VideoCaptureOBSensorDataType);

CV_JS_FROM_ENUM(VideoCaptureOBSensorGenerators);
CV_JS_TO_ENUM(VideoCaptureOBSensorGenerators);

CV_JS_FROM_ENUM(VideoCaptureOBSensorProperties);
CV_JS_TO_ENUM(VideoCaptureOBSensorProperties);

CV_JS_FROM_ENUM(VideoCaptureProperties);
CV_JS_TO_ENUM(VideoCaptureProperties);

CV_JS_FROM_ENUM(VideoWriterProperties);
CV_JS_TO_ENUM(VideoWriterProperties);

CV_JS_FROM_ENUM(WarpPolarMode);
CV_JS_TO_ENUM(WarpPolarMode);

CV_JS_FROM_ENUM(WindowFlags);
CV_JS_TO_ENUM(WindowFlags);

CV_JS_FROM_ENUM(WindowPropertyFlags);
CV_JS_TO_ENUM(WindowPropertyFlags);

typedef cv::_InputArray::KindFlag _InputArray_KindFlag;
CV_JS_FROM_ENUM(_InputArray_KindFlag);
CV_JS_TO_ENUM(_InputArray_KindFlag);

typedef cv::_OutputArray::DepthMask _OutputArray_DepthMask;
CV_JS_FROM_ENUM(_OutputArray_DepthMask);
CV_JS_TO_ENUM(_OutputArray_DepthMask);

typedef cv::aruco::CornerRefineMethod aruco_CornerRefineMethod;
CV_JS_FROM_ENUM(aruco_CornerRefineMethod);
CV_JS_TO_ENUM(aruco_CornerRefineMethod);

typedef cv::aruco::PredefinedDictionaryType aruco_PredefinedDictionaryType;
CV_JS_FROM_ENUM(aruco_PredefinedDictionaryType);
CV_JS_TO_ENUM(aruco_PredefinedDictionaryType);

typedef cv::barcode::BarcodeType barcode_BarcodeType;
CV_JS_FROM_ENUM(barcode_BarcodeType);
CV_JS_TO_ENUM(barcode_BarcodeType);

typedef cv::ccm::CCM_TYPE ccm_CCM_TYPE;
CV_JS_FROM_ENUM(ccm_CCM_TYPE);
CV_JS_TO_ENUM(ccm_CCM_TYPE);

typedef cv::ccm::COLOR_SPACE ccm_COLOR_SPACE;
CV_JS_FROM_ENUM(ccm_COLOR_SPACE);
CV_JS_TO_ENUM(ccm_COLOR_SPACE);

typedef cv::ccm::CONST_COLOR ccm_CONST_COLOR;
CV_JS_FROM_ENUM(ccm_CONST_COLOR);
CV_JS_TO_ENUM(ccm_CONST_COLOR);

typedef cv::ccm::DISTANCE_TYPE ccm_DISTANCE_TYPE;
CV_JS_FROM_ENUM(ccm_DISTANCE_TYPE);
CV_JS_TO_ENUM(ccm_DISTANCE_TYPE);

typedef cv::ccm::INITIAL_METHOD_TYPE ccm_INITIAL_METHOD_TYPE;
CV_JS_FROM_ENUM(ccm_INITIAL_METHOD_TYPE);
CV_JS_TO_ENUM(ccm_INITIAL_METHOD_TYPE);

typedef cv::ccm::LINEAR_TYPE ccm_LINEAR_TYPE;
CV_JS_FROM_ENUM(ccm_LINEAR_TYPE);
CV_JS_TO_ENUM(ccm_LINEAR_TYPE);

typedef cv::cuda::DeviceInfo::ComputeMode cuda_DeviceInfo_ComputeMode;
CV_JS_FROM_ENUM(cuda_DeviceInfo_ComputeMode);
CV_JS_TO_ENUM(cuda_DeviceInfo_ComputeMode);

typedef cv::cuda::Event::CreateFlags cuda_Event_CreateFlags;
CV_JS_FROM_ENUM(cuda_Event_CreateFlags);
CV_JS_TO_ENUM(cuda_Event_CreateFlags);

typedef cv::cuda::FeatureSet cuda_FeatureSet;
CV_JS_FROM_ENUM(cuda_FeatureSet);
CV_JS_TO_ENUM(cuda_FeatureSet);

typedef cv::cuda::HostMem::AllocType cuda_HostMem_AllocType;
CV_JS_FROM_ENUM(cuda_HostMem_AllocType);
CV_JS_TO_ENUM(cuda_HostMem_AllocType);

typedef cv::cuda::SURF_CUDA::KeypointLayout cuda_SURF_CUDA_KeypointLayout;
CV_JS_FROM_ENUM(cuda_SURF_CUDA_KeypointLayout);
CV_JS_TO_ENUM(cuda_SURF_CUDA_KeypointLayout);

typedef cv::detail::ArgKind detail_ArgKind;
CV_JS_FROM_ENUM(detail_ArgKind);
CV_JS_TO_ENUM(detail_ArgKind);

typedef cv::detail::CvFeatureParams::FeatureType detail_CvFeatureParams_FeatureType;
CV_JS_FROM_ENUM(detail_CvFeatureParams_FeatureType);
CV_JS_TO_ENUM(detail_CvFeatureParams_FeatureType);

typedef cv::detail::OpaqueKind detail_OpaqueKind;
CV_JS_FROM_ENUM(detail_OpaqueKind);
CV_JS_TO_ENUM(detail_OpaqueKind);

typedef cv::detail::TestOp detail_TestOp;
CV_JS_FROM_ENUM(detail_TestOp);
CV_JS_TO_ENUM(detail_TestOp);

typedef cv::detail::TrackerSamplerCSC::MODE detail_TrackerSamplerCSC_MODE;
CV_JS_FROM_ENUM(detail_TrackerSamplerCSC_MODE);
CV_JS_TO_ENUM(detail_TrackerSamplerCSC_MODE);

typedef cv::dnn::Backend dnn_Backend;
CV_JS_FROM_ENUM(dnn_Backend);
CV_JS_TO_ENUM(dnn_Backend);

typedef cv::dnn::SoftNMSMethod dnn_SoftNMSMethod;
CV_JS_FROM_ENUM(dnn_SoftNMSMethod);
CV_JS_TO_ENUM(dnn_SoftNMSMethod);

typedef cv::dnn::Target dnn_Target;
CV_JS_FROM_ENUM(dnn_Target);
CV_JS_TO_ENUM(dnn_Target);

typedef cv::flann::FlannIndexType flann_FlannIndexType;
CV_JS_FROM_ENUM(flann_FlannIndexType);
CV_JS_TO_ENUM(flann_FlannIndexType);

typedef cv::gapi::ArgType gapi_ArgType;
CV_JS_FROM_ENUM(gapi_ArgType);
CV_JS_TO_ENUM(gapi_ArgType);

typedef cv::gapi::StereoOutputFormat gapi_StereoOutputFormat;
CV_JS_FROM_ENUM(gapi_StereoOutputFormat);
CV_JS_TO_ENUM(gapi_StereoOutputFormat);

typedef cv::gapi::ie::InferMode gapi_ie_InferMode;
CV_JS_FROM_ENUM(gapi_ie_InferMode);
CV_JS_TO_ENUM(gapi_ie_InferMode);

typedef cv::gapi::ie::TraitAs gapi_ie_TraitAs;
CV_JS_FROM_ENUM(gapi_ie_TraitAs);
CV_JS_TO_ENUM(gapi_ie_TraitAs);

typedef cv::gapi::ie::detail::ParamDesc::Kind gapi_ie_detail_ParamDesc_Kind;
CV_JS_FROM_ENUM(gapi_ie_detail_ParamDesc_Kind);
CV_JS_TO_ENUM(gapi_ie_detail_ParamDesc_Kind);

typedef cv::gapi::oak::ColorCameraParams::BoardSocket gapi_oak_ColorCameraParams_BoardSocket;
CV_JS_FROM_ENUM(gapi_oak_ColorCameraParams_BoardSocket);
CV_JS_TO_ENUM(gapi_oak_ColorCameraParams_BoardSocket);

typedef cv::gapi::oak::ColorCameraParams::Resolution gapi_oak_ColorCameraParams_Resolution;
CV_JS_FROM_ENUM(gapi_oak_ColorCameraParams_Resolution);
CV_JS_TO_ENUM(gapi_oak_ColorCameraParams_Resolution);

typedef cv::gapi::oak::EncoderConfig::Profile gapi_oak_EncoderConfig_Profile;
CV_JS_FROM_ENUM(gapi_oak_EncoderConfig_Profile);
CV_JS_TO_ENUM(gapi_oak_EncoderConfig_Profile);

typedef cv::gapi::oak::EncoderConfig::RateControlMode gapi_oak_EncoderConfig_RateControlMode;
CV_JS_FROM_ENUM(gapi_oak_EncoderConfig_RateControlMode);
CV_JS_TO_ENUM(gapi_oak_EncoderConfig_RateControlMode);

typedef cv::gapi::onnx::TraitAs gapi_onnx_TraitAs;
CV_JS_FROM_ENUM(gapi_onnx_TraitAs);
CV_JS_TO_ENUM(gapi_onnx_TraitAs);

typedef cv::gapi::streaming::sync_policy gapi_streaming_sync_policy;
CV_JS_FROM_ENUM(gapi_streaming_sync_policy);
CV_JS_TO_ENUM(gapi_streaming_sync_policy);

typedef cv::gapi::video::BackgroundSubtractorType gapi_video_BackgroundSubtractorType;
CV_JS_FROM_ENUM(gapi_video_BackgroundSubtractorType);
CV_JS_TO_ENUM(gapi_video_BackgroundSubtractorType);

typedef cv::gapi::wip::gst::GStreamerSource::OutputType gapi_wip_gst_GStreamerSource_OutputType;
CV_JS_FROM_ENUM(gapi_wip_gst_GStreamerSource_OutputType);
CV_JS_TO_ENUM(gapi_wip_gst_GStreamerSource_OutputType);

typedef cv::gapi::wip::onevpl::AccelType gapi_wip_onevpl_AccelType;
CV_JS_FROM_ENUM(gapi_wip_onevpl_AccelType);
CV_JS_TO_ENUM(gapi_wip_onevpl_AccelType);

typedef cv::img_hash::BlockMeanHashMode img_hash_BlockMeanHashMode;
CV_JS_FROM_ENUM(img_hash_BlockMeanHashMode);
CV_JS_TO_ENUM(img_hash_BlockMeanHashMode);

typedef cv::mcc::TYPECHART mcc_TYPECHART;
CV_JS_FROM_ENUM(mcc_TYPECHART);
CV_JS_TO_ENUM(mcc_TYPECHART);

typedef cv::ml::ANN_MLP::ActivationFunctions ml_ANN_MLP_ActivationFunctions;
CV_JS_FROM_ENUM(ml_ANN_MLP_ActivationFunctions);
CV_JS_TO_ENUM(ml_ANN_MLP_ActivationFunctions);

typedef cv::ml::ANN_MLP::TrainFlags ml_ANN_MLP_TrainFlags;
CV_JS_FROM_ENUM(ml_ANN_MLP_TrainFlags);
CV_JS_TO_ENUM(ml_ANN_MLP_TrainFlags);

typedef cv::ml::ANN_MLP::TrainingMethods ml_ANN_MLP_TrainingMethods;
CV_JS_FROM_ENUM(ml_ANN_MLP_TrainingMethods);
CV_JS_TO_ENUM(ml_ANN_MLP_TrainingMethods);

typedef cv::ml::Boost::Types ml_Boost_Types;
CV_JS_FROM_ENUM(ml_Boost_Types);
CV_JS_TO_ENUM(ml_Boost_Types);

typedef cv::ml::DTrees::Flags ml_DTrees_Flags;
CV_JS_FROM_ENUM(ml_DTrees_Flags);
CV_JS_TO_ENUM(ml_DTrees_Flags);

typedef cv::ml::EM::Types ml_EM_Types;
CV_JS_FROM_ENUM(ml_EM_Types);
CV_JS_TO_ENUM(ml_EM_Types);

typedef cv::ml::ErrorTypes ml_ErrorTypes;
CV_JS_FROM_ENUM(ml_ErrorTypes);
CV_JS_TO_ENUM(ml_ErrorTypes);

typedef cv::ml::KNearest::Types ml_KNearest_Types;
CV_JS_FROM_ENUM(ml_KNearest_Types);
CV_JS_TO_ENUM(ml_KNearest_Types);

typedef cv::ml::LogisticRegression::Methods ml_LogisticRegression_Methods;
CV_JS_FROM_ENUM(ml_LogisticRegression_Methods);
CV_JS_TO_ENUM(ml_LogisticRegression_Methods);

typedef cv::ml::LogisticRegression::RegKinds ml_LogisticRegression_RegKinds;
CV_JS_FROM_ENUM(ml_LogisticRegression_RegKinds);
CV_JS_TO_ENUM(ml_LogisticRegression_RegKinds);

typedef cv::ml::SVM::KernelTypes ml_SVM_KernelTypes;
CV_JS_FROM_ENUM(ml_SVM_KernelTypes);
CV_JS_TO_ENUM(ml_SVM_KernelTypes);

typedef cv::ml::SVM::ParamTypes ml_SVM_ParamTypes;
CV_JS_FROM_ENUM(ml_SVM_ParamTypes);
CV_JS_TO_ENUM(ml_SVM_ParamTypes);

typedef cv::ml::SVM::Types ml_SVM_Types;
CV_JS_FROM_ENUM(ml_SVM_Types);
CV_JS_TO_ENUM(ml_SVM_Types);

typedef cv::ml::SVMSGD::MarginType ml_SVMSGD_MarginType;
CV_JS_FROM_ENUM(ml_SVMSGD_MarginType);
CV_JS_TO_ENUM(ml_SVMSGD_MarginType);

typedef cv::ml::SVMSGD::SvmsgdType ml_SVMSGD_SvmsgdType;
CV_JS_FROM_ENUM(ml_SVMSGD_SvmsgdType);
CV_JS_TO_ENUM(ml_SVMSGD_SvmsgdType);

typedef cv::ml::SampleTypes ml_SampleTypes;
CV_JS_FROM_ENUM(ml_SampleTypes);
CV_JS_TO_ENUM(ml_SampleTypes);

typedef cv::ml::StatModel::Flags ml_StatModel_Flags;
CV_JS_FROM_ENUM(ml_StatModel_Flags);
CV_JS_TO_ENUM(ml_StatModel_Flags);

typedef cv::ml::VariableTypes ml_VariableTypes;
CV_JS_FROM_ENUM(ml_VariableTypes);
CV_JS_TO_ENUM(ml_VariableTypes);

typedef cv::ocl::OclVectorStrategy ocl_OclVectorStrategy;
CV_JS_FROM_ENUM(ocl_OclVectorStrategy);
CV_JS_TO_ENUM(ocl_OclVectorStrategy);

typedef cv::ogl::Buffer::Access ogl_Buffer_Access;
CV_JS_FROM_ENUM(ogl_Buffer_Access);
CV_JS_TO_ENUM(ogl_Buffer_Access);

typedef cv::ogl::Buffer::Target ogl_Buffer_Target;
CV_JS_FROM_ENUM(ogl_Buffer_Target);
CV_JS_TO_ENUM(ogl_Buffer_Target);

typedef cv::ogl::RenderModes ogl_RenderModes;
CV_JS_FROM_ENUM(ogl_RenderModes);
CV_JS_TO_ENUM(ogl_RenderModes);

typedef cv::ogl::Texture2D::Format ogl_Texture2D_Format;
CV_JS_FROM_ENUM(ogl_Texture2D_Format);
CV_JS_TO_ENUM(ogl_Texture2D_Format);

typedef cv::text::classifier_type text_classifier_type;
CV_JS_FROM_ENUM(text_classifier_type);
CV_JS_TO_ENUM(text_classifier_type);

typedef cv::text::decoder_mode text_decoder_mode;
CV_JS_FROM_ENUM(text_decoder_mode);
CV_JS_TO_ENUM(text_decoder_mode);

typedef cv::text::erGrouping_Modes text_erGrouping_Modes;
CV_JS_FROM_ENUM(text_erGrouping_Modes);
CV_JS_TO_ENUM(text_erGrouping_Modes);

typedef cv::text::ocr_engine_mode text_ocr_engine_mode;
CV_JS_FROM_ENUM(text_ocr_engine_mode);
CV_JS_TO_ENUM(text_ocr_engine_mode);

typedef cv::text::page_seg_mode text_page_seg_mode;
CV_JS_FROM_ENUM(text_page_seg_mode);
CV_JS_TO_ENUM(text_page_seg_mode);

typedef cv::videostab::MotionModel videostab_MotionModel;
CV_JS_FROM_ENUM(videostab_MotionModel);
CV_JS_TO_ENUM(videostab_MotionModel);

typedef cv::xfeatures2d::BEBLID::BeblidSize xfeatures2d_BEBLID_BeblidSize;
CV_JS_FROM_ENUM(xfeatures2d_BEBLID_BeblidSize);
CV_JS_TO_ENUM(xfeatures2d_BEBLID_BeblidSize);

typedef cv::xfeatures2d::DAISY::NormalizationType xfeatures2d_DAISY_NormalizationType;
CV_JS_FROM_ENUM(xfeatures2d_DAISY_NormalizationType);
CV_JS_TO_ENUM(xfeatures2d_DAISY_NormalizationType);

typedef cv::xfeatures2d::PCTSignatures::DistanceFunction xfeatures2d_PCTSignatures_DistanceFunction;
CV_JS_FROM_ENUM(xfeatures2d_PCTSignatures_DistanceFunction);
CV_JS_TO_ENUM(xfeatures2d_PCTSignatures_DistanceFunction);

typedef cv::xfeatures2d::PCTSignatures::PointDistribution xfeatures2d_PCTSignatures_PointDistribution;
CV_JS_FROM_ENUM(xfeatures2d_PCTSignatures_PointDistribution);
CV_JS_TO_ENUM(xfeatures2d_PCTSignatures_PointDistribution);

typedef cv::xfeatures2d::PCTSignatures::SimilarityFunction xfeatures2d_PCTSignatures_SimilarityFunction;
CV_JS_FROM_ENUM(xfeatures2d_PCTSignatures_SimilarityFunction);
CV_JS_TO_ENUM(xfeatures2d_PCTSignatures_SimilarityFunction);

typedef cv::xfeatures2d::TEBLID::TeblidSize xfeatures2d_TEBLID_TeblidSize;
CV_JS_FROM_ENUM(xfeatures2d_TEBLID_TeblidSize);
CV_JS_TO_ENUM(xfeatures2d_TEBLID_TeblidSize);

typedef cv::ximgproc::AngleRangeOption ximgproc_AngleRangeOption;
CV_JS_FROM_ENUM(ximgproc_AngleRangeOption);
CV_JS_TO_ENUM(ximgproc_AngleRangeOption);

typedef cv::ximgproc::EdgeAwareFiltersList ximgproc_EdgeAwareFiltersList;
CV_JS_FROM_ENUM(ximgproc_EdgeAwareFiltersList);
CV_JS_TO_ENUM(ximgproc_EdgeAwareFiltersList);

typedef cv::ximgproc::EdgeDrawing::GradientOperator ximgproc_EdgeDrawing_GradientOperator;
CV_JS_FROM_ENUM(ximgproc_EdgeDrawing_GradientOperator);
CV_JS_TO_ENUM(ximgproc_EdgeDrawing_GradientOperator);

typedef cv::ximgproc::HoughDeskewOption ximgproc_HoughDeskewOption;
CV_JS_FROM_ENUM(ximgproc_HoughDeskewOption);
CV_JS_TO_ENUM(ximgproc_HoughDeskewOption);

typedef cv::ximgproc::HoughOp ximgproc_HoughOp;
CV_JS_FROM_ENUM(ximgproc_HoughOp);
CV_JS_TO_ENUM(ximgproc_HoughOp);

typedef cv::ximgproc::LocalBinarizationMethods ximgproc_LocalBinarizationMethods;
CV_JS_FROM_ENUM(ximgproc_LocalBinarizationMethods);
CV_JS_TO_ENUM(ximgproc_LocalBinarizationMethods);

typedef cv::ximgproc::SLICType ximgproc_SLICType;
CV_JS_FROM_ENUM(ximgproc_SLICType);
CV_JS_TO_ENUM(ximgproc_SLICType);

typedef cv::ximgproc::ThinningTypes ximgproc_ThinningTypes;
CV_JS_FROM_ENUM(ximgproc_ThinningTypes);
CV_JS_TO_ENUM(ximgproc_ThinningTypes);

typedef cv::ximgproc::WMFWeightType ximgproc_WMFWeightType;
CV_JS_FROM_ENUM(ximgproc_WMFWeightType);
CV_JS_TO_ENUM(ximgproc_WMFWeightType);

