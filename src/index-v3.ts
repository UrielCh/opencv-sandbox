import { getModulePath } from "./openCVLoader";

const impPath = getModulePath();

// @ts-ignore
// @deno-types="../types/cv2.d.ts"
//import * as cv2tmp from '../build/Release/cv2.node';
// import * as cv2tmp from impPath;// '../build/Debug/cv2.node';
const cvMatObject = require(impPath)
console.log('require cv2.node called');

// main.ts
// import cvMatObject = require('./cvMatObjectWrapper');

console.log(`the current module contains: ${Object.keys(cvMatObject)}`)

if (cvMatObject.allocateMat) {
    const tmp = cvMatObject.allocateMat(1,2);
    console.log(tmp);
}

// const mat = new cvMatObject(3, 4);
// 
// console.log('Rows:', mat.rows);
// console.log('Cols:', mat.cols);
// console.log('Type:', mat.type);
// 
// mat.release();