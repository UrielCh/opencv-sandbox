export class cvMatObject {
  constructor();
  constructor(rows: number, cols: number);

  readonly rows: number;
  readonly cols: number;
  readonly type: number;
  readonly depth: number;
  readonly isContinuous: boolean;
  readonly isSubmatrix: boolean;
  readonly elemSize: number;
  readonly elemSize1: number;

  // not exported
  // release(): void;
}

export function imread(filename: string, flags?: number): cvMatObject;
export function imread(filename: string, options?: {flags?: number}): cvMatObject;


enum ImwriteFlags {
  IMWRITE_JPEG_QUALITY        = 1,  //!< For JPEG, it can be a quality from 0 to 100 (the higher is the better). Default value is 95.
  IMWRITE_JPEG_PROGRESSIVE    = 2,  //!< Enable JPEG features, 0 or 1, default is False.
  IMWRITE_JPEG_OPTIMIZE       = 3,  //!< Enable JPEG features, 0 or 1, default is False.
  IMWRITE_JPEG_RST_INTERVAL   = 4,  //!< JPEG restart interval, 0 - 65535, default is 0 - no restart.
  IMWRITE_JPEG_LUMA_QUALITY   = 5,  //!< Separate luma quality level, 0 - 100, default is -1 - don't use.
  IMWRITE_JPEG_CHROMA_QUALITY = 6,  //!< Separate chroma quality level, 0 - 100, default is -1 - don't use.
  IMWRITE_JPEG_SAMPLING_FACTOR = 7, //!< For JPEG, set sampling factor. See cv::ImwriteJPEGSamplingFactorParams.
  IMWRITE_PNG_COMPRESSION     = 16, //!< For PNG, it can be the compression level from 0 to 9. A higher value means a smaller size and longer compression time. If specified, strategy is changed to IMWRITE_PNG_STRATEGY_DEFAULT (Z_DEFAULT_STRATEGY). Default value is 1 (best speed setting).
  IMWRITE_PNG_STRATEGY        = 17, //!< One of cv::ImwritePNGFlags, default is IMWRITE_PNG_STRATEGY_RLE.
  IMWRITE_PNG_BILEVEL         = 18, //!< Binary level PNG, 0 or 1, default is 0.
  IMWRITE_PXM_BINARY          = 32, //!< For PPM, PGM, or PBM, it can be a binary format flag, 0 or 1. Default value is 1.
  IMWRITE_EXR_TYPE            = (3 << 4) + 0, /* 48 */ //!< override EXR storage type (FLOAT (FP32) is default)
  IMWRITE_EXR_COMPRESSION     = (3 << 4) + 1, /* 49 */ //!< override EXR compression type (ZIP_COMPRESSION = 3 is default)
  IMWRITE_EXR_DWA_COMPRESSION_LEVEL = (3 << 4) + 2, /* 50 */ //!< override EXR DWA compression level (45 is default)
  IMWRITE_WEBP_QUALITY        = 64, //!< For WEBP, it can be a quality from 1 to 100 (the higher is the better). By default (without any parameter) and for quality above 100 the lossless compression is used.
  IMWRITE_HDR_COMPRESSION     = (5 << 4) + 0, /* 80 */ //!< specify HDR compression
  IMWRITE_PAM_TUPLETYPE       = 128,//!< For PAM, sets the TUPLETYPE field to the corresponding string value that is defined for the format
  IMWRITE_TIFF_RESUNIT        = 256,//!< For TIFF, use to specify which DPI resolution unit to set; see libtiff documentation for valid values
  IMWRITE_TIFF_XDPI           = 257,//!< For TIFF, use to specify the X direction DPI
  IMWRITE_TIFF_YDPI           = 258,//!< For TIFF, use to specify the Y direction DPI
  IMWRITE_TIFF_COMPRESSION    = 259,//!< For TIFF, use to specify the image compression scheme. See libtiff for integer constants corresponding to compression formats. Note, for images whose depth is CV_32F, only libtiff's SGILOG compression scheme is used. For other supported depths, the compression scheme can be specified by this flag; LZW compression is the default.
  IMWRITE_JPEG2000_COMPRESSION_X1000 = 272 //!< For JPEG2000, use to specify the target compression rate (multiplied by 1000). The value can be from 0 to 1000. Default is 1000.
};

/**
 * 
 * @param ext File extension that defines the output format. Must include a leading period.
 * @param img 
 * @param param2   ImwriteFlags
 */
export function imencode(ext: `.${string}`, img: cvMatObject, params?: number): [boolean, Buffer];
export function imencode(ext: `.${string}`, img: cvMatObject, options?: {params: number}): [boolean, Buffer];

export function test(ava: any): {pass:number, fail:number};
// export function runTests(ava: any): undefined;