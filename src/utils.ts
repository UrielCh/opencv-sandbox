export const CV_8U = 0;
export const CV_8S = 1;
export const CV_16U = 2;
export const CV_16S = 3;
export const CV_32S = 4;
export const CV_32F = 5;
export const CV_64F = 6;
export const CV_16F = 7;

export const CV_CN_SHIFT = 3;
export const CV_DEPTH_MAX = 1 << CV_CN_SHIFT;

export const CV_MAT_DEPTH_MASK = (CV_DEPTH_MAX - 1)
export const CV_MAT_DEPTH = (flags: number) => ((flags) & CV_MAT_DEPTH_MASK)

export const CV_MAKETYPE = (depth: number, cn: number) => (CV_MAT_DEPTH(depth) + (((cn) - 1) << CV_CN_SHIFT))
export const CV_MAKE_TYPE = CV_MAKETYPE;

export const CV_8UC1 = CV_MAKETYPE(CV_8U, 1)
export const CV_8UC2 = CV_MAKETYPE(CV_8U, 2)
export const CV_8UC3 = CV_MAKETYPE(CV_8U, 3)
export const CV_8UC4 = CV_MAKETYPE(CV_8U, 4)
export const CV_8UC = (n: number) => CV_MAKETYPE(CV_8U, n)

export const CV_8SC1 = CV_MAKETYPE(CV_8S, 1)
export const CV_8SC2 = CV_MAKETYPE(CV_8S, 2)
export const CV_8SC3 = CV_MAKETYPE(CV_8S, 3)
export const CV_8SC4 = CV_MAKETYPE(CV_8S, 4)
export const CV_8SC = (n: number) => CV_MAKETYPE(CV_8S, (n))

export const CV_16UC1 = CV_MAKETYPE(CV_16U, 1)
export const CV_16UC2 = CV_MAKETYPE(CV_16U, 2)
export const CV_16UC3 = CV_MAKETYPE(CV_16U, 3)
export const CV_16UC4 = CV_MAKETYPE(CV_16U, 4)
export const CV_16UC  = (n: number) => CV_MAKETYPE(CV_16U, (n))

export const CV_16SC1 = CV_MAKETYPE(CV_16S, 1)
export const CV_16SC2 = CV_MAKETYPE(CV_16S, 2)
export const CV_16SC3 = CV_MAKETYPE(CV_16S, 3)
export const CV_16SC4 = CV_MAKETYPE(CV_16S, 4)
export const CV_16SC  = (n: number) => CV_MAKETYPE(CV_16S, (n))

export const CV_32SC1 = CV_MAKETYPE(CV_32S, 1)
export const CV_32SC2 = CV_MAKETYPE(CV_32S, 2)
export const CV_32SC3 = CV_MAKETYPE(CV_32S, 3)
export const CV_32SC4 = CV_MAKETYPE(CV_32S, 4)
export const CV_32SC  = (n: number) => CV_MAKETYPE(CV_32S, (n))

export const CV_32FC1 = CV_MAKETYPE(CV_32F, 1)
export const CV_32FC2 = CV_MAKETYPE(CV_32F, 2)
export const CV_32FC3 = CV_MAKETYPE(CV_32F, 3)
export const CV_32FC4 = CV_MAKETYPE(CV_32F, 4)
export const CV_32FC  = (n: number) => CV_MAKETYPE(CV_32F, (n))

export const CV_64FC1 = CV_MAKETYPE(CV_64F, 1)
export const CV_64FC2 = CV_MAKETYPE(CV_64F, 2)
export const CV_64FC3 = CV_MAKETYPE(CV_64F, 3)
export const CV_64FC4 = CV_MAKETYPE(CV_64F, 4)
export const CV_64FC  = (n: number) => CV_MAKETYPE(CV_64F, (n))

export const CV_16FC1 = CV_MAKETYPE(CV_16F, 1)
export const CV_16FC2 = CV_MAKETYPE(CV_16F, 2)
export const CV_16FC3 = CV_MAKETYPE(CV_16F, 3)
export const CV_16FC4 = CV_MAKETYPE(CV_16F, 4)
export const CV_16FC  = (n: number) => CV_MAKETYPE(CV_16F, (n))
