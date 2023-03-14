// @ts-ignore
import * as cv2tmp from '../build/Release/cv2.node';
const cv2 = cv2tmp as typeof import('../types/cv2');
console.log(cv2.multiplyByTwo(10))
