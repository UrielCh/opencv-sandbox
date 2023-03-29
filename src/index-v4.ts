import { getModulePath } from "./openCVLoader";

const impPath = getModulePath();

const theModuleTmp = require(impPath);
console.log('require cv2.node called');


const theModule = theModuleTmp as typeof import('../types/cv-v4');

function allocationTest() {

    // const cv2 = cv2tmp as typeof import('../types/cv-v1');

    // main.ts
    // import cvMatObject = require('./cvMatObjectWrapper');

    console.log(`the current module contains ${Object.keys(theModule).length} exports:`)
    for (const key of Object.keys(theModule)) {
        console.log(`the ${key} of type: ${typeof ((theModule as any)[key])}`)
    }

    console.log(`\nAllocation Test:`)

    for (let i = 0; i < 3; i++) {
        if (theModule.cvMatObject) {
            const tmp = new theModule.cvMatObject(1, 2 + i);
            console.log(`a new Mat is available with size: ${tmp.rows} x ${tmp.cols} Type: ${tmp.type}`, );
        }
    }
    console.log(`\n`)
}
allocationTest();

setTimeout(() => console.log('\ntimeout all buffer should had been released'), 1000);

// const mat = new cvMatObject(3, 4);
//
// console.log('Rows:', mat.rows);
// console.log('Cols:', mat.cols);
// console.log('Type:', mat.type);
//
// mat.release();
// [].filter(a=>a.endsWith('.cpp')).map(f=>'cc-v4/'+f).join(' ')
//
// require('fs').readdirSync('./cc-v4').filter(a=>a.endsWith('.cpp')).map(f=>'cc-v4/'+f).join(' ')
// 