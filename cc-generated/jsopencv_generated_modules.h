// This code will be import within the function:
// init_body(Napi::Env env, Napi::Object exports) function in cv2.cpp
// an Napi::Env env, and a Napi::Object exports will be provided
// CVJS_MODULE macro will invoque init_submodule

CVJS_MODULE("", cv);
CVJS_MODULE(".Error", Error);
CVJS_MODULE(".aruco", aruco);
CVJS_MODULE(".barcode", barcode);
CVJS_MODULE(".ccm", ccm);
CVJS_MODULE(".cuda", cuda);
CVJS_MODULE(".detail", detail);
CVJS_MODULE(".dnn", dnn);
CVJS_MODULE(".dnn_superres", dnn_superres);
CVJS_MODULE(".face", face);
CVJS_MODULE(".fisheye", fisheye);
CVJS_MODULE(".flann", flann);
CVJS_MODULE(".freetype", freetype);
CVJS_MODULE(".gapi", gapi);
CVJS_MODULE(".gapi.core.cpu", gapi_core_cpu);
CVJS_MODULE(".gapi.core.fluid", gapi_core_fluid);
CVJS_MODULE(".gapi.core.ocl", gapi_core_ocl);
CVJS_MODULE(".gapi.ie", gapi_ie);
CVJS_MODULE(".gapi.ie.detail", gapi_ie_detail);
CVJS_MODULE(".gapi.oak", gapi_oak);
CVJS_MODULE(".gapi.onnx", gapi_onnx);
CVJS_MODULE(".gapi.own.detail", gapi_own_detail);
CVJS_MODULE(".gapi.render.ocv", gapi_render_ocv);
CVJS_MODULE(".gapi.streaming", gapi_streaming);
CVJS_MODULE(".gapi.video", gapi_video);
CVJS_MODULE(".gapi.wip", gapi_wip);
CVJS_MODULE(".gapi.wip.draw", gapi_wip_draw);
CVJS_MODULE(".gapi.wip.gst", gapi_wip_gst);
CVJS_MODULE(".gapi.wip.onevpl", gapi_wip_onevpl);
CVJS_MODULE(".img_hash", img_hash);
CVJS_MODULE(".intensity_transform", intensity_transform);
CVJS_MODULE(".ipp", ipp);
CVJS_MODULE(".legacy", legacy);
CVJS_MODULE(".mcc", mcc);
CVJS_MODULE(".ml", ml);
CVJS_MODULE(".ocl", ocl);
CVJS_MODULE(".ogl", ogl);
CVJS_MODULE(".parallel", parallel);
CVJS_MODULE(".plot", plot);
CVJS_MODULE(".quality", quality);
CVJS_MODULE(".rapid", rapid);
CVJS_MODULE(".samples", samples);
CVJS_MODULE(".segmentation", segmentation);
CVJS_MODULE(".text", text);
CVJS_MODULE(".utils", utils);
CVJS_MODULE(".utils.fs", utils_fs);
CVJS_MODULE(".utils.nested", utils_nested);
CVJS_MODULE(".videoio_registry", videoio_registry);
CVJS_MODULE(".videostab", videostab);
CVJS_MODULE(".xfeatures2d", xfeatures2d);
CVJS_MODULE(".ximgproc", ximgproc);
CVJS_MODULE(".ximgproc.segmentation", ximgproc_segmentation);
