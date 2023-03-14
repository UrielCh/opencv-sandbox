import path from 'path'

let opencvBinDir  = '';
if (process.env.OPENCV_BUILD_ROOT) {
    opencvBinDir = path.join(process.env.OPENCV_BUILD_ROOT, 'opencv-4.7.0-8b1ea', 'build', 'bin', 'Release')
}
if (opencvBinDir && process.env.path && !process.env.path.includes(opencvBinDir)) {
    process.env.path = `${process.env.path};${opencvBinDir};`;
}
// console.log(process.env.path);

// @ts-ignore
import * as cv2tmp from '../build/Release/cv2.node';
import { CV_8UC1, CV_8UC3 } from './utils';

const cv2 = cv2tmp as typeof import('../types/cv2');
console.log(cv2.multiplyByTwo(10))

// CV_8UC3
console.log(CV_8UC3)
const mat1px = cv2.allocateMat(1, 1, CV_8UC1)
console.log(`mat 1x1 size is ${mat1px} Type: CV_8UC1`)
console.log(typeof Object.keys(mat1px.data))
 
const mat2px = cv2.allocateMat(2, 1)
console.log(`mat 2x1 size is ${mat2px}`)

const mat3px = cv2.allocateMat(3, 1)
console.log(`mat 3x1 size is ${mat3px}`)

const mat4px = cv2.allocateMat(2, 2)
console.log(`mat 2x2 size is ${mat4px}`)

const logo = cv2.imread('./data/logo.png')
console.log(`logo:`, logo)


// const mat = cv2.allocateMat(100, 100);
// console.log(mat);
 