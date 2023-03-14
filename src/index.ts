// @ts-ignore
import * as cv2tmp from '../build/Release/cv2.node';
const cv2 = cv2tmp as typeof import('../types/cv2');
console.log(cv2.multiplyByTwo(10))

console.log(cv2);

// const mat = cv2.allocateMat(100, 100);
// console.log(mat);
