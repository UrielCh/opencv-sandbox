#include "opencv2/core.hpp"
#include "opencv2/core/async.hpp"
#include "opencv2/core/base.hpp"
#include "opencv2/core/bindings_utils.hpp"
#include "opencv2/core/check.hpp"
#include "opencv2/core/cuda.hpp"
#include "opencv2/core/mat.hpp"
#include "opencv2/core/ocl.hpp"
#include "opencv2/core/opengl.hpp"
#include "opencv2/core/optim.hpp"
#include "opencv2/core/ovx.hpp"
#include "opencv2/core/parallel/parallel_backend.hpp"
#include "opencv2/core/persistence.hpp"
#include "opencv2/core/quaternion.hpp"
#include "opencv2/core/types.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/flann/miniflann.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgproc/bindings.hpp"
#include "opencv2/imgproc/segmentation.hpp"
#include "opencv2/intensity_transform.hpp"
#include "opencv2/ml.hpp"
#include "opencv2/photo.hpp"
#include "opencv2/photo/cuda.hpp"
#include "opencv2/plot.hpp"
#include "opencv2/quality/qualitybase.hpp"
#include "opencv2/quality/qualitybrisque.hpp"
#include "opencv2/quality/qualitygmsd.hpp"
#include "opencv2/quality/qualitymse.hpp"
#include "opencv2/quality/qualitypsnr.hpp"
#include "opencv2/quality/qualityssim.hpp"
#include "opencv2/alphamat.hpp"
#include "opencv2/dnn/dict.hpp"
#include "opencv2/dnn/dnn.hpp"
#include "opencv2/dnn_superres.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/freetype.hpp"
#include "opencv2/img_hash/average_hash.hpp"
#include "opencv2/img_hash/block_mean_hash.hpp"
#include "opencv2/img_hash/color_moment_hash.hpp"
#include "opencv2/img_hash/img_hash_base.hpp"
#include "opencv2/img_hash/marr_hildreth_hash.hpp"
#include "opencv2/img_hash/phash.hpp"
#include "opencv2/img_hash/radial_variance_hash.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/text/erfilter.hpp"
#include "opencv2/text/ocr.hpp"
#include "opencv2/text/swt_text_detection.hpp"
#include "opencv2/text/textDetector.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/videoio/registry.hpp"
#include "opencv2/barcode.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/mcc/ccm.hpp"
#include "opencv2/mcc/checker_detector.hpp"
#include "opencv2/mcc/checker_model.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/objdetect/aruco_board.hpp"
#include "opencv2/objdetect/aruco_detector.hpp"
#include "opencv2/objdetect/aruco_dictionary.hpp"
#include "opencv2/objdetect/charuco_detector.hpp"
#include "opencv2/objdetect/face.hpp"
#include "opencv2/rapid.hpp"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/video/detail/tracking.detail.hpp"
#include "opencv2/video/tracking.hpp"
#include "opencv2/videostab/motion_core.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/xfeatures2d/cuda.hpp"
#include "opencv2/xfeatures2d/nonfree.hpp"
#include "opencv2/ximgproc.hpp"
#include "opencv2/ximgproc/color_match.hpp"
#include "opencv2/ximgproc/deriche_filter.hpp"
#include "opencv2/ximgproc/disparity_filter.hpp"
#include "opencv2/ximgproc/edge_drawing.hpp"
#include "opencv2/ximgproc/edge_filter.hpp"
#include "opencv2/ximgproc/edgeboxes.hpp"
#include "opencv2/ximgproc/edgepreserving_filter.hpp"
#include "opencv2/ximgproc/estimated_covariance.hpp"
#include "opencv2/ximgproc/fast_hough_transform.hpp"
#include "opencv2/ximgproc/fast_line_detector.hpp"
#include "opencv2/ximgproc/find_ellipses.hpp"
#include "opencv2/ximgproc/fourier_descriptors.hpp"
#include "opencv2/ximgproc/lsc.hpp"
#include "opencv2/ximgproc/peilin.hpp"
#include "opencv2/ximgproc/radon_transform.hpp"
#include "opencv2/ximgproc/ridgefilter.hpp"
#include "opencv2/ximgproc/scansegment.hpp"
#include "opencv2/ximgproc/seeds.hpp"
#include "opencv2/ximgproc/segmentation.hpp"
#include "opencv2/ximgproc/slic.hpp"
#include "opencv2/ximgproc/sparse_match_interpolator.hpp"
#include "opencv2/ximgproc/structured_edge_detection.hpp"
#include "opencv2/ximgproc/weighted_median_filter.hpp"
#include "opencv2/face.hpp"
#include "opencv2/face/bif.hpp"
#include "opencv2/face/face_alignment.hpp"
#include "opencv2/face/facemark.hpp"
#include "opencv2/face/facemarkAAM.hpp"
#include "opencv2/face/facemarkLBF.hpp"
#include "opencv2/face/facemark_train.hpp"
#include "opencv2/face/facerec.hpp"
#include "opencv2/face/mace.hpp"
#include "opencv2/face/predict_collector.hpp"
#include "opencv2/gapi/core.hpp"
#include "opencv2/gapi/cpu/core.hpp"
#include "opencv2/gapi/fluid/core.hpp"
#include "opencv2/gapi/fluid/gfluidkernel.hpp"
#include "opencv2/gapi/garray.hpp"
#include "opencv2/gapi/gcommon.hpp"
#include "opencv2/gapi/gcomputation.hpp"
#include "opencv2/gapi/gframe.hpp"
#include "opencv2/gapi/gkernel.hpp"
#include "opencv2/gapi/gmat.hpp"
#include "opencv2/gapi/gopaque.hpp"
#include "opencv2/gapi/gscalar.hpp"
#include "opencv2/gapi/gstreaming.hpp"
#include "opencv2/gapi/gtype_traits.hpp"
#include "opencv2/gapi/imgproc.hpp"
#include "opencv2/gapi/infer.hpp"
#include "opencv2/gapi/infer/bindings_ie.hpp"
#include "opencv2/gapi/infer/bindings_onnx.hpp"
#include "opencv2/gapi/infer/ie.hpp"
#include "opencv2/gapi/infer/onnx.hpp"
#include "opencv2/gapi/infer/parsers.hpp"
#include "opencv2/gapi/media.hpp"
#include "opencv2/gapi/oak/oak.hpp"
#include "opencv2/gapi/ocl/core.hpp"
#include "opencv2/gapi/own/mat.hpp"
#include "opencv2/gapi/render/render.hpp"
#include "opencv2/gapi/render/render_types.hpp"
#include "opencv2/gapi/rmat.hpp"
#include "opencv2/gapi/stereo.hpp"
#include "opencv2/gapi/streaming/cap.hpp"
#include "opencv2/gapi/streaming/format.hpp"
#include "opencv2/gapi/streaming/gstreamer/gstreamerpipeline.hpp"
#include "opencv2/gapi/streaming/gstreamer/gstreamersource.hpp"
#include "opencv2/gapi/streaming/onevpl/accel_types.hpp"
#include "opencv2/gapi/streaming/sync.hpp"
#include "opencv2/gapi/video.hpp"
#include "/Users/pierre/opencv/opencv-4.7.0-dc627/opencv/modules/gapi/misc/python/python_bridge.hpp"
#include "opencv2/tracking.hpp"
#include "opencv2/tracking/feature.hpp"
#include "opencv2/tracking/tracking_internals.hpp"
#include "opencv2/tracking/tracking_legacy.hpp"