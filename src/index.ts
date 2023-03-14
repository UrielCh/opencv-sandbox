const opencvBinDir = 'c:\\0\\opencv\\opencv-4.7.0-794c6\\build\\bin\\Release';
if (process.env.path && !process.env.path.includes(opencvBinDir)) {
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
console.log(`mat 1x1 size is ${mat1px.length} Type: CV_8UC1`)
 
const mat2px = cv2.allocateMat(2, 1)
console.log(`mat 2x1 size is ${mat2px.length}`)

const mat3px = cv2.allocateMat(3, 1)
console.log(`mat 3x1 size is ${mat3px.length}`)

const mat4px = cv2.allocateMat(2, 2)
console.log(`mat 2x2 size is ${mat4px.length}`)

// const mat = cv2.allocateMat(100, 100);
// console.log(mat);
 