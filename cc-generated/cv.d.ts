declare namespace cv {

	class AKAZE{
	   constructor();
	}

	class AffineFeature{
	   constructor();
	}

	class AgastFeatureDetector{
	   constructor();
	}

	class Algorithm{
	   constructor();
	}

	class AlignExposures{
	   constructor();
	}

	class AlignMTB{
	   constructor();
	}

	class AsyncArray{
	   constructor();
	}

	class BFMatcher{
	   constructor();
	}

	class BOWImgDescriptorExtractor{
	   constructor();
	}

	class BOWKMeansTrainer{
	   constructor();
	}

	class BOWTrainer{
	   constructor();
	}

	class BRISK{
	   constructor();
	}

	class BackgroundSubtractor{
	   constructor();
	}

	class BackgroundSubtractorKNN{
	   constructor();
	}

	class BackgroundSubtractorMOG2{
	   constructor();
	}

	class BaseCascadeClassifier{
	   constructor();
	}

	class CLAHE{
	   constructor();
	}

	class CalibrateCRF{
	   constructor();
	}

	class CalibrateDebevec{
	   constructor();
	}

	class CalibrateRobertson{
	   constructor();
	}

	class CascadeClassifier{
	   constructor();
	}

	class CirclesGridFinderParameters{
	   constructor(densityNeighborhoodSize:Size2f, minDensity:float, kmeansAttempts:int, minDistanceToAddKeypoint:int, keypointScale:int, minGraphConfidence:float, vertexGain:float, vertexPenalty:float, existingVertexGain:float, edgeGain:float, edgePenalty:float, convexHullFactor:float, minRNGEdgeSwitchDist:float, squareSize:float, maxRectifiedDistance:float);
	}

	class DISOpticalFlow{
	   constructor();
	}

	class DMatch{
	   constructor(queryIdx:int, trainIdx:int, imgIdx:int, distance:float);
	}

	class DenseOpticalFlow{
	   constructor();
	}

	class DescriptorMatcher{
	   constructor();
	}

	class FaceDetectorYN{
	   constructor();
	}

	class FaceRecognizerSF{
	   constructor();
	}

	class FarnebackOpticalFlow{
	   constructor();
	}

	class FastFeatureDetector{
	   constructor();
	}

	class Feature2D{
	   constructor();
	}

	class FileNode{
	   constructor();
	}

	class FileStorage{
	   constructor();
	}

	class FlannBasedMatcher{
	   constructor();
	}

	class GArrayDesc{
	   constructor();
	}

	class GArrayT{
	   constructor();
	}

	class GCompileArg{
	   constructor();
	}

	class GComputation{
	   constructor();
	}

	class GFTTDetector{
	   constructor();
	}

	class GFrame{
	   constructor();
	}

	class GInferInputs{
	   constructor();
	}

	class GInferListInputs{
	   constructor();
	}

	class GInferListOutputs{
	   constructor();
	}

	class GInferOutputs{
	   constructor();
	}

	class GKernelPackage{
	   constructor();
	}

	class GMat{
	   constructor();
	}

	class GMatDesc{
	   constructor(depth:int, chan:int, size:Size, planar:bool, dims:vector_int);
	}

	class GOpaqueDesc{
	   constructor();
	}

	class GOpaqueT{
	   constructor();
	}

	class GScalar{
	   constructor();
	}

	class GScalarDesc{
	   constructor();
	}

	class GStreamingCompiled{
	   constructor();
	}

	class GeneralizedHough{
	   constructor();
	}

	class GeneralizedHoughBallard{
	   constructor();
	}

	class GeneralizedHoughGuil{
	   constructor();
	}

	class HOGDescriptor{
	   constructor(winSize:Size, blockSize:Size, blockStride:Size, cellSize:Size, nbins:int, derivAperture:int, winSigma:double, histogramNormType:HOGDescriptor_HistogramNormType, L2HysThreshold:double, gammaCorrection:bool, svmDetector:vector_float, nlevels:int, signedGradient:bool);
	}

	class KAZE{
	   constructor();
	}

	class KalmanFilter{
	   constructor(statePre:Mat, statePost:Mat, transitionMatrix:Mat, controlMatrix:Mat, measurementMatrix:Mat, processNoiseCov:Mat, measurementNoiseCov:Mat, errorCovPre:Mat, gain:Mat, errorCovPost:Mat);
	}

	class KeyPoint{
	   constructor(pt:Point2f, size:float, angle:float, response:float, octave:int, class_id:int);
	}

	class LineSegmentDetector{
	   constructor();
	}

	class MSER{
	   constructor();
	}

	class MergeDebevec{
	   constructor();
	}

	class MergeExposures{
	   constructor();
	}

	class MergeMertens{
	   constructor();
	}

	class MergeRobertson{
	   constructor();
	}

	class Moments{
	   constructor(m00:double, m10:double, m01:double, m20:double, m11:double, m02:double, m30:double, m21:double, m12:double, m03:double, mu20:double, mu11:double, mu02:double, mu30:double, mu21:double, mu12:double, mu03:double, nu20:double, nu11:double, nu02:double, nu30:double, nu21:double, nu12:double, nu03:double);
	}

	class ORB{
	   constructor();
	}

	class QRCodeDetector{
	   constructor();
	}

	class QRCodeEncoder{
	   constructor();
	}
	namespace QRCodeEncoder {

		class Params{
		   constructor(version:int, correction_level:CorrectionLevel, mode:EncodeMode, structure_number:int);
		}
	}

	class SIFT{
	   constructor();
	}

	class SimpleBlobDetector{
	   constructor();
	}
	namespace SimpleBlobDetector {

		class Params{
		   constructor(thresholdStep:float, minThreshold:float, maxThreshold:float, minRepeatability:size_t, minDistBetweenBlobs:float, filterByColor:bool, blobColor:uchar, filterByArea:bool, minArea:float, maxArea:float, filterByCircularity:bool, minCircularity:float, maxCircularity:float, filterByInertia:bool, minInertiaRatio:float, maxInertiaRatio:float, filterByConvexity:bool, minConvexity:float, maxConvexity:float, collectContours:bool);
		}
	}

	class SparseOpticalFlow{
	   constructor();
	}

	class SparsePyrLKOpticalFlow{
	   constructor();
	}

	class StereoBM{
	   constructor();
	}

	class StereoMatcher{
	   constructor();
	}

	class StereoSGBM{
	   constructor();
	}

	class Subdiv2D{
	   constructor();
	}

	class TickMeter{
	   constructor();
	}

	class Tonemap{
	   constructor();
	}

	class TonemapDrago{
	   constructor();
	}

	class TonemapMantiuk{
	   constructor();
	}

	class TonemapReinhard{
	   constructor();
	}

	class Tracker{
	   constructor();
	}

	class TrackerCSRT{
	   constructor();
	}
	namespace TrackerCSRT {

		class Params{
		   constructor(use_hog:bool, use_color_names:bool, use_gray:bool, use_rgb:bool, use_channel_weights:bool, use_segmentation:bool, window_function:string, kaiser_alpha:float, cheb_attenuation:float, template_size:float, gsl_sigma:float, hog_orientations:float, hog_clip:float, padding:float, filter_lr:float, weights_lr:float, num_hog_channels_used:int, admm_iterations:int, histogram_bins:int, histogram_lr:float, background_ratio:int, number_of_scales:int, scale_sigma_factor:float, scale_model_max_area:float, scale_lr:float, scale_step:float, psr_threshold:float);
		}
	}

	class TrackerDaSiamRPN{
	   constructor();
	}
	namespace TrackerDaSiamRPN {

		class Params{
		   constructor(model:string, kernel_cls1:string, kernel_r1:string, backend:int, target:int);
		}
	}

	class TrackerGOTURN{
	   constructor();
	}
	namespace TrackerGOTURN {

		class Params{
		   constructor(modelTxt:string, modelBin:string);
		}
	}

	class TrackerKCF{
	   constructor();
	}
	namespace TrackerKCF {

		class Params{
		   constructor(detect_thresh:float, sigma:float, lambda:float, interp_factor:float, output_sigma_factor:float, pca_learning_rate:float, resize:bool, split_coeff:bool, wrap_kernel:bool, compress_feature:bool, max_patch_size:int, compressed_size:int, desc_pca:int, desc_npca:int);
		}
	}

	class TrackerMIL{
	   constructor();
	}
	namespace TrackerMIL {

		class Params{
		   constructor(samplerInitInRadius:float, samplerInitMaxNegNum:int, samplerSearchWinSize:float, samplerTrackInRadius:float, samplerTrackMaxPosNum:int, samplerTrackMaxNegNum:int, featureSetNumFeatures:int);
		}
	}

	class TrackerNano{
	   constructor();
	}
	namespace TrackerNano {

		class Params{
		   constructor(backbone:string, neckhead:string, backend:int, target:int);
		}
	}

	class UMat{
	   constructor(offset:size_t);
	}

	class UsacParams{
	   constructor(confidence:double, isParallel:bool, loIterations:int, loMethod:LocalOptimMethod, loSampleSize:int, maxIterations:int, neighborsSearch:NeighborSearchMethod, randomGeneratorState:int, sampler:SamplingMethod, score:ScoreMethod, threshold:double);
	}

	class VariationalRefinement{
	   constructor();
	}

	class VideoCapture{
	   constructor();
	}

	class VideoWriter{
	   constructor();
	}
	namespace aruco {

		class ArucoDetector{
		   constructor();
		}

		class Board{
		   constructor();
		}

		class CharucoBoard{
		   constructor();
		}

		class CharucoDetector{
		   constructor();
		}

		class CharucoParameters{
		   constructor(cameraMatrix:Mat, distCoeffs:Mat, minMarkers:int, tryRefineMarkers:bool);
		}

		class DetectorParameters{
		   constructor(adaptiveThreshWinSizeMin:int, adaptiveThreshWinSizeMax:int, adaptiveThreshWinSizeStep:int, adaptiveThreshConstant:double, minMarkerPerimeterRate:double, maxMarkerPerimeterRate:double, polygonalApproxAccuracyRate:double, minCornerDistanceRate:double, minDistanceToBorder:int, minMarkerDistanceRate:double, cornerRefinementMethod:CornerRefineMethod, cornerRefinementWinSize:int, cornerRefinementMaxIterations:int, cornerRefinementMinAccuracy:double, markerBorderBits:int, perspectiveRemovePixelPerCell:int, perspectiveRemoveIgnoredMarginPerCell:double, maxErroneousBitsInBorderRate:double, minOtsuStdDev:double, errorCorrectionRate:double, aprilTagQuadDecimate:float, aprilTagQuadSigma:float, aprilTagMinClusterPixels:int, aprilTagMaxNmaxima:int, aprilTagCriticalRad:float, aprilTagMaxLineFitMse:float, aprilTagMinWhiteBlackDiff:int, aprilTagDeglitch:int, detectInvertedMarker:bool, useAruco3Detection:bool, minSideLengthCanonicalImg:int, minMarkerLengthRatioOriginalImg:float);
		}

		class Dictionary{
		   constructor(bytesList:Mat, markerSize:int, maxCorrectionBits:int);
		}

		class GridBoard{
		   constructor();
		}

		class RefineParameters{
		   constructor(minRepDistance:float, errorCorrectionRate:float, checkAllOrders:bool);
		}
	}
	namespace barcode {

		class BarcodeDetector{
		   constructor();
		}
	}
	namespace ccm {

		class ColorCorrectionModel{
		   constructor();
		}
	}
	namespace cuda {

		class BufferPool{
		   constructor();
		}

		class DeviceInfo{
		   constructor();
		}

		class Event{
		   constructor();
		}

		class GpuData{
		   constructor();
		}

		class GpuMat{
		   constructor(step:size_t);
		}

		class GpuMatND{
		   constructor();
		}
		namespace GpuMat {

			class Allocator{
			   constructor();
			}

			class HostMem{
			   constructor(step:size_t);
			}

			class SURF_CUDA{
			   constructor(hessianThreshold:double, nOctaves:int, nOctaveLayers:int, extended:bool, upright:bool, keypointsRatio:float);
			}

			class Stream{
			   constructor();
			}

			class TargetArchs{
			   constructor();
			}
		}
	}
	namespace dnn {

		class ClassificationModel{
		   constructor();
		}

		class DetectionModel{
		   constructor();
		}

		class DictValue{
		   constructor();
		}

		class KeypointsModel{
		   constructor();
		}

		class Layer{
		   constructor(blobs:vector_Mat, name:String, type:String, preferableTarget:int);
		}

		class Model{
		   constructor();
		}

		class Net{
		   constructor();
		}

		class SegmentationModel{
		   constructor();
		}

		class TextDetectionModel{
		   constructor();
		}

		class TextDetectionModel_DB{
		   constructor();
		}

		class TextDetectionModel_EAST{
		   constructor();
		}

		class TextRecognitionModel{
		   constructor();
		}
	}
	namespace dnn_superres {

		class DnnSuperResImpl{
		   constructor();
		}
	}
	namespace face {

		class BIF{
		   constructor();
		}

		class BasicFaceRecognizer{
		   constructor();
		}

		class EigenFaceRecognizer{
		   constructor();
		}

		class FaceRecognizer{
		   constructor();
		}

		class Facemark{
		   constructor();
		}

		class FacemarkAAM{
		   constructor();
		}

		class FacemarkKazemi{
		   constructor();
		}

		class FacemarkLBF{
		   constructor();
		}

		class FacemarkTrain{
		   constructor();
		}

		class FisherFaceRecognizer{
		   constructor();
		}

		class LBPHFaceRecognizer{
		   constructor();
		}

		class MACE{
		   constructor();
		}

		class PredictCollector{
		   constructor();
		}

		class StandardCollector{
		   constructor();
		}
	}
	namespace flann {

		class Index{
		   constructor();
		}
	}
	namespace freetype {

		class FreeType2{
		   constructor();
		}
	}
	namespace gapi {

		class GNetPackage{
		   constructor();
		}

		class GNetParam{
		   constructor();
		}
		namespace ie {

			class PyParams{
			   constructor();
			}
		}
		namespace onnx {

			class PyParams{
			   constructor();
			}
		}
		namespace streaming {

			class queue_capacity{
			   constructor(capacity:size_t);
			}
		}
		namespace wip {

			class GOutputs{
			   constructor();
			}

			class IStreamSource{
			   constructor();
			}
			namespace draw {

				class Circle{
				   constructor(center:Point, radius:int, color:Scalar, thick:int, lt:int, shift:int);
				}

				class Image{
				   constructor(org:Point, img:Mat, alpha:Mat);
				}

				class Line{
				   constructor(pt1:Point, pt2:Point, color:Scalar, thick:int, lt:int, shift:int);
				}

				class Mosaic{
				   constructor(mos:Rect, cellSz:int, decim:int);
				}

				class Poly{
				   constructor(points:vector_Point, color:Scalar, thick:int, lt:int, shift:int);
				}

				class Rect{
				   constructor(rect:Rect, color:Scalar, thick:int, lt:int, shift:int);
				}

				class Text{
				   constructor(text:string, org:Point, ff:int, fs:double, color:Scalar, thick:int, lt:int, bottom_left_origin:bool);
				}
			}
			namespace gst {

				class GStreamerPipeline{
				   constructor();
				}
			}
		}
	}
	namespace img_hash {

		class AverageHash{
		   constructor();
		}

		class BlockMeanHash{
		   constructor();
		}

		class ColorMomentHash{
		   constructor();
		}

		class ImgHashBase{
		   constructor();
		}

		class MarrHildrethHash{
		   constructor();
		}

		class PHash{
		   constructor();
		}

		class RadialVarianceHash{
		   constructor();
		}
	}
	namespace legacy {

		class MultiTracker{
		   constructor();
		}

		class Tracker{
		   constructor();
		}

		class TrackerBoosting{
		   constructor();
		}

		class TrackerCSRT{
		   constructor();
		}

		class TrackerKCF{
		   constructor();
		}

		class TrackerMIL{
		   constructor();
		}

		class TrackerMOSSE{
		   constructor();
		}

		class TrackerMedianFlow{
		   constructor();
		}

		class TrackerTLD{
		   constructor();
		}
	}
	namespace mcc {

		class CChecker{
		   constructor();
		}

		class CCheckerDetector{
		   constructor();
		}

		class CCheckerDraw{
		   constructor();
		}

		class DetectorParameters{
		   constructor(adaptiveThreshWinSizeMin:int, adaptiveThreshWinSizeMax:int, adaptiveThreshWinSizeStep:int, adaptiveThreshConstant:double, minContoursAreaRate:double, minContoursArea:double, confidenceThreshold:double, minContourSolidity:double, findCandidatesApproxPolyDPEpsMultiplier:double, borderWidth:int, B0factor:float, maxError:float, minContourPointsAllowed:int, minContourLengthAllowed:int, minInterContourDistance:int, minInterCheckerDistance:int, minImageSize:int, minGroupSize:unsigned);
		}
	}
	namespace ml {

		class ANN_MLP{
		   constructor();
		}

		class Boost{
		   constructor();
		}

		class DTrees{
		   constructor();
		}

		class EM{
		   constructor();
		}

		class KNearest{
		   constructor();
		}

		class LogisticRegression{
		   constructor();
		}

		class NormalBayesClassifier{
		   constructor();
		}

		class ParamGrid{
		   constructor(minVal:double, maxVal:double, logStep:double);
		}

		class RTrees{
		   constructor();
		}

		class SVM{
		   constructor();
		}

		class SVMSGD{
		   constructor();
		}

		class StatModel{
		   constructor();
		}

		class TrainData{
		   constructor();
		}
	}
	namespace ocl {

		class Device{
		   constructor();
		}

		class OpenCLExecutionContext{
		   constructor();
		}
	}
	namespace plot {

		class Plot2d{
		   constructor();
		}
	}
	namespace quality {

		class QualityBRISQUE{
		   constructor();
		}

		class QualityBase{
		   constructor();
		}

		class QualityGMSD{
		   constructor();
		}

		class QualityMSE{
		   constructor();
		}

		class QualityPSNR{
		   constructor();
		}

		class QualitySSIM{
		   constructor();
		}
	}
	namespace rapid {

		class GOSTracker{
		   constructor();
		}

		class OLSTracker{
		   constructor();
		}

		class Rapid{
		   constructor();
		}

		class Tracker{
		   constructor();
		}
	}
	namespace segmentation {

		class IntelligentScissorsMB{
		   constructor();
		}
	}
	namespace text {

		class BaseOCR{
		   constructor();
		}

		class ERFilter{
		   constructor();
		}
		namespace ERFilter {

			class Callback{
			   constructor();
			}

			class OCRBeamSearchDecoder{
			   constructor();
			}
		}
		namespace OCRBeamSearchDecoder {

			class ClassifierCallback{
			   constructor();
			}

			class OCRHMMDecoder{
			   constructor();
			}
		}
		namespace OCRHMMDecoder {

			class ClassifierCallback{
			   constructor();
			}

			class OCRTesseract{
			   constructor();
			}

			class TextDetector{
			   constructor();
			}

			class TextDetectorCNN{
			   constructor();
			}
		}
	}
	namespace utils {

		class ClassWithKeywordProperties{
		   constructor(lambda:int, except:int);
		}
		namespace nested {

			class ExportClassName{
			   constructor();
			}
			namespace ExportClassName {

				class Params{
				   constructor(int_value:int, float_value:float);
				}
			}
		}
	}
	namespace xfeatures2d {

		class AffineFeature2D{
		   constructor();
		}

		class BEBLID{
		   constructor();
		}

		class BoostDesc{
		   constructor();
		}

		class BriefDescriptorExtractor{
		   constructor();
		}

		class DAISY{
		   constructor();
		}

		class FREAK{
		   constructor();
		}

		class HarrisLaplaceFeatureDetector{
		   constructor();
		}

		class LATCH{
		   constructor();
		}

		class LUCID{
		   constructor();
		}

		class MSDDetector{
		   constructor();
		}

		class PCTSignatures{
		   constructor();
		}

		class PCTSignaturesSQFD{
		   constructor();
		}

		class SURF{
		   constructor();
		}

		class StarDetector{
		   constructor();
		}

		class TBMR{
		   constructor();
		}

		class TEBLID{
		   constructor();
		}

		class VGG{
		   constructor();
		}
	}
	namespace ximgproc {

		class AdaptiveManifoldFilter{
		   constructor();
		}

		class ContourFitting{
		   constructor();
		}

		class DTFilter{
		   constructor();
		}

		class DisparityFilter{
		   constructor();
		}

		class DisparityWLSFilter{
		   constructor();
		}

		class EdgeAwareInterpolator{
		   constructor();
		}

		class EdgeBoxes{
		   constructor();
		}

		class EdgeDrawing{
		   constructor();
		}
		namespace EdgeDrawing {

			class Params{
			   constructor(PFmode:bool, EdgeDetectionOperator:int, GradientThresholdValue:int, AnchorThresholdValue:int, ScanInterval:int, MinPathLength:int, Sigma:float, SumFlag:bool, NFAValidation:bool, MinLineLength:int, MaxDistanceBetweenTwoLines:double, LineFitErrorThreshold:double, MaxErrorThreshold:double);
			}

			class FastBilateralSolverFilter{
			   constructor();
			}

			class FastGlobalSmootherFilter{
			   constructor();
			}

			class FastLineDetector{
			   constructor();
			}

			class GuidedFilter{
			   constructor();
			}

			class RFFeatureGetter{
			   constructor();
			}

			class RICInterpolator{
			   constructor();
			}

			class RidgeDetectionFilter{
			   constructor();
			}

			class ScanSegment{
			   constructor();
			}

			class SparseMatchInterpolator{
			   constructor();
			}

			class StructuredEdgeDetection{
			   constructor();
			}

			class SuperpixelLSC{
			   constructor();
			}

			class SuperpixelSEEDS{
			   constructor();
			}

			class SuperpixelSLIC{
			   constructor();
			}
		}
		namespace segmentation {

			class GraphSegmentation{
			   constructor();
			}

			class SelectiveSearchSegmentation{
			   constructor();
			}

			class SelectiveSearchSegmentationStrategy{
			   constructor();
			}

			class SelectiveSearchSegmentationStrategyColor{
			   constructor();
			}

			class SelectiveSearchSegmentationStrategyFill{
			   constructor();
			}

			class SelectiveSearchSegmentationStrategyMultiple{
			   constructor();
			}

			class SelectiveSearchSegmentationStrategySize{
			   constructor();
			}

			class SelectiveSearchSegmentationStrategyTexture{
			   constructor();
			}
		}
	}
}
