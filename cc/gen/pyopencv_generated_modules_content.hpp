#include <opencv2/opencv.hpp>
#include "jscompat.hpp"
#include "common.h"

#define METH_VARARGS  0x0001
#define METH_KEYWORDS 0x0002

#define CV_JS_FN_WITH_KW_(fn, flags) (JsCFunction)(void*)(JsCFunctionWithKeywords)(fn), (flags) | METH_VARARGS | METH_KEYWORDS
#define CV_JS_FN_NOARGS_(fn, flags) (JsCFunction)(fn), (flags) | METH_NOARGS

#define CV_JS_FN_WITH_KW(fn) CV_JS_FN_WITH_KW_(fn, 0)
#define CV_JS_FN_NOARGS(fn) CV_JS_FN_NOARGS_(fn, 0)

static JsMethodDef methods_cv[] = {
    {"haveImageReader", CV_JS_FN_WITH_KW_(jsopencv_cv_haveImageReader, 0), "haveImageReader(filename) -> retval\n.   @brief Returns true if the specified image can be decoded by OpenCV\n.   \n.   @param filename File name of the image"},
    {"haveImageWriter", CV_JS_FN_WITH_KW_(jsopencv_cv_haveImageWriter, 0), "haveImageWriter(filename) -> retval\n.   @brief Returns true if an image with the specified filename can be encoded by OpenCV\n.   \n.    @param filename File name of the image"},
    {"imcount", CV_JS_FN_WITH_KW_(jsopencv_cv_imcount, 0), "imcount(filename[, flags]) -> retval\n.   @brief Returns the number of images inside the give file\n.   \n.   The function imcount will return the number of pages in a multi-page image, or 1 for single-page images\n.   @param filename Name of file to be loaded.\n.   @param flags Flag that can take values of cv::ImreadModes, default with cv::IMREAD_ANYCOLOR."},
    {"imdecode", CV_JS_FN_WITH_KW_(jsopencv_cv_imdecode, 0), "imdecode(buf, flags) -> retval\n.   @brief Reads an image from a buffer in memory.\n.   \n.   The function imdecode reads an image from the specified buffer in the memory. If the buffer is too short or\n.   contains invalid data, the function returns an empty matrix ( Mat::data==NULL ).\n.   \n.   See cv::imread for the list of supported formats and flags description.\n.   \n.   @note In the case of color images, the decoded images will have the channels stored in **B G R** order.\n.   @param buf Input array or vector of bytes.\n.   @param flags The same flags as in cv::imread, see cv::ImreadModes."},
    {"imdecodemulti", CV_JS_FN_WITH_KW_(jsopencv_cv_imdecodemulti, 0), "imdecodemulti(buf, flags[, mats]) -> retval, mats\n.   @brief Reads a multi-page image from a buffer in memory.\n.   \n.   The function imdecodemulti reads a multi-page image from the specified buffer in the memory. If the buffer is too short or\n.   contains invalid data, the function returns false.\n.   \n.   See cv::imreadmulti for the list of supported formats and flags description.\n.   \n.   @note In the case of color images, the decoded images will have the channels stored in **B G R** order.\n.   @param buf Input array or vector of bytes.\n.   @param flags The same flags as in cv::imread, see cv::ImreadModes.\n.   @param mats A vector of Mat objects holding each page, if more than one."},
    {"imencode", CV_JS_FN_WITH_KW_(jsopencv_cv_imencode, 0), "imencode(ext, img[, params]) -> retval, buf\n.   @brief Encodes an image into a memory buffer.\n.   \n.   The function imencode compresses the image and stores it in the memory buffer that is resized to fit the\n.   result. See cv::imwrite for the list of supported formats and flags description.\n.   \n.   @param ext File extension that defines the output format. Must include a leading period.\n.   @param img Image to be written.\n.   @param buf Output buffer resized to fit the compressed image.\n.   @param params Format-specific parameters. See cv::imwrite and cv::ImwriteFlags."},
    {"imread", CV_JS_FN_WITH_KW_(jsopencv_cv_imread, 0), "imread(filename[, flags]) -> retval\n.   @brief Loads an image from a file.\n.   \n.   @anchor imread\n.   \n.   The function imread loads an image from the specified file and returns it. If the image cannot be\n.   read (because of missing file, improper permissions, unsupported or invalid format), the function\n.   returns an empty matrix ( Mat::data==NULL ).\n.   \n.   Currently, the following file formats are supported:\n.   \n.   -   Windows bitmaps - \\*.bmp, \\*.dib (always supported)\n.   -   JPEG files - \\*.jpeg, \\*.jpg, \\*.jpe (see the *Note* section)\n.   -   JPEG 2000 files - \\*.jp2 (see the *Note* section)\n.   -   Portable Network Graphics - \\*.png (see the *Note* section)\n.   -   WebP - \\*.webp (see the *Note* section)\n.   -   Portable image format - \\*.pbm, \\*.pgm, \\*.ppm \\*.pxm, \\*.pnm (always supported)\n.   -   PFM files - \\*.pfm (see the *Note* section)\n.   -   Sun rasters - \\*.sr, \\*.ras (always supported)\n.   -   TIFF files - \\*.tiff, \\*.tif (see the *Note* section)\n.   -   OpenEXR Image files - \\*.exr (see the *Note* section)\n.   -   Radiance HDR - \\*.hdr, \\*.pic (always supported)\n.   -   Raster and Vector geospatial data supported by GDAL (see the *Note* section)\n.   \n.   @note\n.   -   The function determines the type of an image by the content, not by the file extension.\n.   -   In the case of color images, the decoded images will have the channels stored in **B G R** order.\n.   -   When using IMREAD_GRAYSCALE, the codec's internal grayscale conversion will be used, if available.\n.       Results may differ to the output of cvtColor()\n.   -   On Microsoft Windows\\* OS and MacOSX\\*, the codecs shipped with an OpenCV image (libjpeg,\n.       libpng, libtiff, and libjasper) are used by default. So, OpenCV can always read JPEGs, PNGs,\n.       and TIFFs. On MacOSX, there is also an option to use native MacOSX image readers. But beware\n.       that currently these native image loaders give images with different pixel values because of\n.       the color management embedded into MacOSX.\n.   -   On Linux\\*, BSD flavors and other Unix-like open-source operating systems, OpenCV looks for\n.       codecs supplied with an OS image. Install the relevant packages (do not forget the development\n.       files, for example, \"libjpeg-dev\", in Debian\\* and Ubuntu\\*) to get the codec support or turn\n.       on the OPENCV_BUILD_3RDPARTY_LIBS flag in CMake.\n.   -   In the case you set *WITH_GDAL* flag to true in CMake and @ref IMREAD_LOAD_GDAL to load the image,\n.       then the [GDAL](http://www.gdal.org) driver will be used in order to decode the image, supporting\n.       the following formats: [Raster](http://www.gdal.org/formats_list.html),\n.       [Vector](http://www.gdal.org/ogr_formats.html).\n.   -   If EXIF information is embedded in the image file, the EXIF orientation will be taken into account\n.       and thus the image will be rotated accordingly except if the flags @ref IMREAD_IGNORE_ORIENTATION\n.       or @ref IMREAD_UNCHANGED are passed.\n.   -   Use the IMREAD_UNCHANGED flag to keep the floating point values from PFM image.\n.   -   By default number of pixels must be less than 2^30. Limit can be set using system\n.       variable OPENCV_IO_MAX_IMAGE_PIXELS\n.   \n.   @param filename Name of file to be loaded.\n.   @param flags Flag that can take values of cv::ImreadModes"},
    {"imreadmulti", CV_JS_FN_WITH_KW_(jsopencv_cv_imreadmulti, 0), "imreadmulti(filename[, mats[, flags]]) -> retval, mats\n.   @brief Loads a multi-page image from a file.\n.   \n.   The function imreadmulti loads a multi-page image from the specified file into a vector of Mat objects.\n.   @param filename Name of file to be loaded.\n.   @param mats A vector of Mat objects holding each page.\n.   @param flags Flag that can take values of cv::ImreadModes, default with cv::IMREAD_ANYCOLOR.\n.   @sa cv::imread\n\n\n\nimreadmulti(filename, start, count[, mats[, flags]]) -> retval, mats\n.   @brief Loads a of images of a multi-page image from a file.\n.   \n.   The function imreadmulti loads a specified range from a multi-page image from the specified file into a vector of Mat objects.\n.   @param filename Name of file to be loaded.\n.   @param mats A vector of Mat objects holding each page.\n.   @param start Start index of the image to load\n.   @param count Count number of images to load\n.   @param flags Flag that can take values of cv::ImreadModes, default with cv::IMREAD_ANYCOLOR.\n.   @sa cv::imread"},
    {"imshow", CV_JS_FN_WITH_KW_(jsopencv_cv_imshow, 0), "imshow(winname, mat) -> None\n.   @brief Displays an image in the specified window.\n.   \n.   The function imshow displays an image in the specified window. If the window was created with the\n.   cv::WINDOW_AUTOSIZE flag, the image is shown with its original size, however it is still limited by the screen resolution.\n.   Otherwise, the image is scaled to fit the window. The function may scale the image, depending on its depth:\n.   \n.   -   If the image is 8-bit unsigned, it is displayed as is.\n.   -   If the image is 16-bit unsigned, the pixels are divided by 256. That is, the\n.       value range [0,255\\*256] is mapped to [0,255].\n.   -   If the image is 32-bit or 64-bit floating-point, the pixel values are multiplied by 255. That is, the\n.       value range [0,1] is mapped to [0,255].\n.   -   32-bit integer images are not processed anymore due to ambiguouty of required transform.\n.       Convert to 8-bit unsigned matrix using a custom preprocessing specific to image's context.\n.   \n.   If window was created with OpenGL support, cv::imshow also support ogl::Buffer , ogl::Texture2D and\n.   cuda::GpuMat as input.\n.   \n.   If the window was not created before this function, it is assumed creating a window with cv::WINDOW_AUTOSIZE.\n.   \n.   If you need to show an image that is bigger than the screen resolution, you will need to call namedWindow(\"\", WINDOW_NORMAL) before the imshow.\n.   \n.   @note This function should be followed by a call to cv::waitKey or cv::pollKey to perform GUI\n.   housekeeping tasks that are necessary to actually show the given image and make the window respond\n.   to mouse and keyboard events. Otherwise, it won't display the image and the window might lock up.\n.   For example, **waitKey(0)** will display the window infinitely until any keypress (it is suitable\n.   for image display). **waitKey(25)** will display a frame and wait approximately 25 ms for a key\n.   press (suitable for displaying a video frame-by-frame). To remove the window, use cv::destroyWindow.\n.   \n.   @note\n.   \n.   [__Windows Backend Only__] Pressing Ctrl+C will copy the image to the clipboard.\n.   \n.   [__Windows Backend Only__] Pressing Ctrl+S will show a dialog to save the image.\n.   \n.   @param winname Name of the window.\n.   @param mat Image to be shown."},
    {"imwrite", CV_JS_FN_WITH_KW_(jsopencv_cv_imwrite, 0), "imwrite(filename, img[, params]) -> retval\n.   @brief Saves an image to a specified file.\n.   \n.   The function imwrite saves the image to the specified file. The image format is chosen based on the\n.   filename extension (see cv::imread for the list of extensions). In general, only 8-bit\n.   single-channel or 3-channel (with 'BGR' channel order) images\n.   can be saved using this function, with these exceptions:\n.   \n.   - 16-bit unsigned (CV_16U) images can be saved in the case of PNG, JPEG 2000, and TIFF formats\n.   - 32-bit float (CV_32F) images can be saved in PFM, TIFF, OpenEXR, and Radiance HDR formats;\n.     3-channel (CV_32FC3) TIFF images will be saved using the LogLuv high dynamic range encoding\n.     (4 bytes per pixel)\n.   - PNG images with an alpha channel can be saved using this function. To do this, create\n.   8-bit (or 16-bit) 4-channel image BGRA, where the alpha channel goes last. Fully transparent pixels\n.   should have alpha set to 0, fully opaque pixels should have alpha set to 255/65535 (see the code sample below).\n.   - Multiple images (vector of Mat) can be saved in TIFF format (see the code sample below).\n.   \n.   If the image format is not supported, the image will be converted to 8-bit unsigned (CV_8U) and saved that way.\n.   \n.   If the format, depth or channel order is different, use\n.   Mat::convertTo and cv::cvtColor to convert it before saving. Or, use the universal FileStorage I/O\n.   functions to save the image to XML or YAML format.\n.   \n.   The sample below shows how to create a BGRA image, how to set custom compression parameters and save it to a PNG file.\n.   It also demonstrates how to save multiple images in a TIFF file:\n.   @include snippets/imgcodecs_imwrite.cpp\n.   @param filename Name of the file.\n.   @param img (Mat or vector of Mat) Image or Images to be saved.\n.   @param params Format-specific parameters encoded as pairs (paramId_1, paramValue_1, paramId_2, paramValue_2, ... .) see cv::ImwriteFlags"},
    {"imwritemulti", CV_JS_FN_WITH_KW_(jsopencv_cv_imwritemulti, 0), "imwritemulti(filename, img[, params]) -> retval\n."},
    {"IMREAD_ANYCOLOR", static_cast<long>(cv::IMREAD_ANYCOLOR)},
    {"IMREAD_ANYDEPTH", static_cast<long>(cv::IMREAD_ANYDEPTH)},
    {"IMREAD_COLOR", static_cast<long>(cv::IMREAD_COLOR)},
    {"IMREAD_GRAYSCALE", static_cast<long>(cv::IMREAD_GRAYSCALE)},
    {"IMREAD_IGNORE_ORIENTATION", static_cast<long>(cv::IMREAD_IGNORE_ORIENTATION)},
    {"IMREAD_LOAD_GDAL", static_cast<long>(cv::IMREAD_LOAD_GDAL)},
    {"IMREAD_REDUCED_COLOR_2", static_cast<long>(cv::IMREAD_REDUCED_COLOR_2)},
    {"IMREAD_REDUCED_COLOR_4", static_cast<long>(cv::IMREAD_REDUCED_COLOR_4)},
    {"IMREAD_REDUCED_COLOR_8", static_cast<long>(cv::IMREAD_REDUCED_COLOR_8)},
    {"IMREAD_REDUCED_GRAYSCALE_2", static_cast<long>(cv::IMREAD_REDUCED_GRAYSCALE_2)},
    {"IMREAD_REDUCED_GRAYSCALE_4", static_cast<long>(cv::IMREAD_REDUCED_GRAYSCALE_4)},
    {"IMREAD_REDUCED_GRAYSCALE_8", static_cast<long>(cv::IMREAD_REDUCED_GRAYSCALE_8)},
    {"IMREAD_UNCHANGED", static_cast<long>(cv::IMREAD_UNCHANGED)},
    {"IMWRITE_EXR_COMPRESSION", static_cast<long>(cv::IMWRITE_EXR_COMPRESSION)},
    {"IMWRITE_EXR_COMPRESSION_B44", static_cast<long>(cv::IMWRITE_EXR_COMPRESSION_B44)},
    {"IMWRITE_EXR_COMPRESSION_B44A", static_cast<long>(cv::IMWRITE_EXR_COMPRESSION_B44A)},
    {"IMWRITE_EXR_COMPRESSION_DWAA", static_cast<long>(cv::IMWRITE_EXR_COMPRESSION_DWAA)},
    {"IMWRITE_EXR_COMPRESSION_DWAB", static_cast<long>(cv::IMWRITE_EXR_COMPRESSION_DWAB)},
    {"IMWRITE_EXR_COMPRESSION_NO", static_cast<long>(cv::IMWRITE_EXR_COMPRESSION_NO)},
    {"IMWRITE_EXR_COMPRESSION_PIZ", static_cast<long>(cv::IMWRITE_EXR_COMPRESSION_PIZ)},
    {"IMWRITE_EXR_COMPRESSION_PXR24", static_cast<long>(cv::IMWRITE_EXR_COMPRESSION_PXR24)},
    {"IMWRITE_EXR_COMPRESSION_RLE", static_cast<long>(cv::IMWRITE_EXR_COMPRESSION_RLE)},
    {"IMWRITE_EXR_COMPRESSION_ZIP", static_cast<long>(cv::IMWRITE_EXR_COMPRESSION_ZIP)},
    {"IMWRITE_EXR_COMPRESSION_ZIPS", static_cast<long>(cv::IMWRITE_EXR_COMPRESSION_ZIPS)},
    {"IMWRITE_EXR_DWA_COMPRESSION_LEVEL", static_cast<long>(cv::IMWRITE_EXR_DWA_COMPRESSION_LEVEL)},
    {"IMWRITE_EXR_TYPE", static_cast<long>(cv::IMWRITE_EXR_TYPE)},
    {"IMWRITE_EXR_TYPE_FLOAT", static_cast<long>(cv::IMWRITE_EXR_TYPE_FLOAT)},
    {"IMWRITE_EXR_TYPE_HALF", static_cast<long>(cv::IMWRITE_EXR_TYPE_HALF)},
    {"IMWRITE_HDR_COMPRESSION", static_cast<long>(cv::IMWRITE_HDR_COMPRESSION)},
    {"IMWRITE_HDR_COMPRESSION_NONE", static_cast<long>(cv::IMWRITE_HDR_COMPRESSION_NONE)},
    {"IMWRITE_HDR_COMPRESSION_RLE", static_cast<long>(cv::IMWRITE_HDR_COMPRESSION_RLE)},
    {"IMWRITE_JPEG2000_COMPRESSION_X1000", static_cast<long>(cv::IMWRITE_JPEG2000_COMPRESSION_X1000)},
    {"IMWRITE_JPEG_CHROMA_QUALITY", static_cast<long>(cv::IMWRITE_JPEG_CHROMA_QUALITY)},
    {"IMWRITE_JPEG_LUMA_QUALITY", static_cast<long>(cv::IMWRITE_JPEG_LUMA_QUALITY)},
    {"IMWRITE_JPEG_OPTIMIZE", static_cast<long>(cv::IMWRITE_JPEG_OPTIMIZE)},
    {"IMWRITE_JPEG_PROGRESSIVE", static_cast<long>(cv::IMWRITE_JPEG_PROGRESSIVE)},
    {"IMWRITE_JPEG_QUALITY", static_cast<long>(cv::IMWRITE_JPEG_QUALITY)},
    {"IMWRITE_JPEG_RST_INTERVAL", static_cast<long>(cv::IMWRITE_JPEG_RST_INTERVAL)},
    {"IMWRITE_JPEG_SAMPLING_FACTOR", static_cast<long>(cv::IMWRITE_JPEG_SAMPLING_FACTOR)},
    {"IMWRITE_JPEG_SAMPLING_FACTOR_411", static_cast<long>(cv::IMWRITE_JPEG_SAMPLING_FACTOR_411)},
    {"IMWRITE_JPEG_SAMPLING_FACTOR_420", static_cast<long>(cv::IMWRITE_JPEG_SAMPLING_FACTOR_420)},
    {"IMWRITE_JPEG_SAMPLING_FACTOR_422", static_cast<long>(cv::IMWRITE_JPEG_SAMPLING_FACTOR_422)},
    {"IMWRITE_JPEG_SAMPLING_FACTOR_440", static_cast<long>(cv::IMWRITE_JPEG_SAMPLING_FACTOR_440)},
    {"IMWRITE_JPEG_SAMPLING_FACTOR_444", static_cast<long>(cv::IMWRITE_JPEG_SAMPLING_FACTOR_444)},
    {"IMWRITE_PAM_FORMAT_BLACKANDWHITE", static_cast<long>(cv::IMWRITE_PAM_FORMAT_BLACKANDWHITE)},
    {"IMWRITE_PAM_FORMAT_GRAYSCALE", static_cast<long>(cv::IMWRITE_PAM_FORMAT_GRAYSCALE)},
    {"IMWRITE_PAM_FORMAT_GRAYSCALE_ALPHA", static_cast<long>(cv::IMWRITE_PAM_FORMAT_GRAYSCALE_ALPHA)},
    {"IMWRITE_PAM_FORMAT_NULL", static_cast<long>(cv::IMWRITE_PAM_FORMAT_NULL)},
    {"IMWRITE_PAM_FORMAT_RGB", static_cast<long>(cv::IMWRITE_PAM_FORMAT_RGB)},
    {"IMWRITE_PAM_FORMAT_RGB_ALPHA", static_cast<long>(cv::IMWRITE_PAM_FORMAT_RGB_ALPHA)},
    {"IMWRITE_PAM_TUPLETYPE", static_cast<long>(cv::IMWRITE_PAM_TUPLETYPE)},
    {"IMWRITE_PNG_BILEVEL", static_cast<long>(cv::IMWRITE_PNG_BILEVEL)},
    {"IMWRITE_PNG_COMPRESSION", static_cast<long>(cv::IMWRITE_PNG_COMPRESSION)},
    {"IMWRITE_PNG_STRATEGY", static_cast<long>(cv::IMWRITE_PNG_STRATEGY)},
    {"IMWRITE_PNG_STRATEGY_DEFAULT", static_cast<long>(cv::IMWRITE_PNG_STRATEGY_DEFAULT)},
    {"IMWRITE_PNG_STRATEGY_FILTERED", static_cast<long>(cv::IMWRITE_PNG_STRATEGY_FILTERED)},
    {"IMWRITE_PNG_STRATEGY_FIXED", static_cast<long>(cv::IMWRITE_PNG_STRATEGY_FIXED)},
    {"IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY", static_cast<long>(cv::IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY)},
    {"IMWRITE_PNG_STRATEGY_RLE", static_cast<long>(cv::IMWRITE_PNG_STRATEGY_RLE)},
    {"IMWRITE_PXM_BINARY", static_cast<long>(cv::IMWRITE_PXM_BINARY)},
    {"IMWRITE_TIFF_COMPRESSION", static_cast<long>(cv::IMWRITE_TIFF_COMPRESSION)},
    {"IMWRITE_TIFF_RESUNIT", static_cast<long>(cv::IMWRITE_TIFF_RESUNIT)},
    {"IMWRITE_TIFF_XDPI", static_cast<long>(cv::IMWRITE_TIFF_XDPI)},
    {"IMWRITE_TIFF_YDPI", static_cast<long>(cv::IMWRITE_TIFF_YDPI)},
    {"IMWRITE_WEBP_QUALITY", static_cast<long>(cv::IMWRITE_WEBP_QUALITY)}
};