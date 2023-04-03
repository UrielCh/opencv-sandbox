import { getModulePath } from "./openCVLoader";

const impPath = getModulePath();
const theModuleTmp = require(impPath);
console.log('require cv2.node called');

const theModule = theModuleTmp as typeof import('../types/cv-v4');


/**
 * rebuild with node-gyp rebuild
 */

async function allocationTest(pass: number) {
    // const cv2 = cv2tmp as typeof import('../types/cv-v1');
    // main.ts
    // import cvMatObject = require('./cvMatObjectWrapper');
    let cnt = { alloc: 0, release: 0};
    console.log(`the current module contains ${Object.keys(theModule).length} exports:`)
    for (const key of Object.keys(theModule)) {
        console.log(`the ${key} of type: ${typeof ((theModule as any)[key])}`)
    }

    console.log(`\nAllocation Test:`)
    let errorOnce = false;
    for (let i = 0; i < pass; i++) {
        if (theModule.cvMatObject) {
            const tmp = new theModule.cvMatObject(50000, 2000 + (i % 100));
            cnt.alloc++;
            // console.log(`a new Mat is available with size: ${tmp.rows} x ${tmp.cols} Type: ${tmp.type}`,);
            if ('Release' in tmp && typeof(tmp.Release) === 'function') {
                // tmp.Release();
                cnt.release++;
            }
        }
        if (i % 200 === 0) {
            // await new Promise((r) => setTimeout(r, 100));
            const mem = process.memoryUsage();
            const heapUsedInMB = (mem.heapUsed / (1024 * 1024)).toFixed(2);
            const heapTotalInMB = (mem.heapTotal / (1024 * 1024)).toFixed(2);
            console.log(`Memory usage (heap): ${heapUsedInMB} MB / ${heapTotalInMB} MB`, cnt);

            if (global.gc) {
                // This requires the --expose-gc flag.
                //const v8 = require('v8');
                //const beforeGC = v8.serializeHeap();
                global.gc();
                //const afterGC = v8.serializeHeap();
                //const allocatedObjects = afterGC.node_count - beforeGC.node_count;
                // console.log(`Number of allocated objects: ${allocatedObjects}`);
            } else {
                if (!errorOnce) {
                    console.warn('Number of allocated objects is not available. Run Node.js with --expose-gc flag to enable this feature.');
                    errorOnce = true;
                }
            }
        }
    }
    setTimeout(() => console.log('\ntimeout all buffer should had been released'), 200);
    console.log(`\n`)
    // if (global)
    //     (global as any).gc();
}


async function main() {
    console.log('main called 1');
    allocationTest(100);
    await new Promise((r) => setTimeout(r, 500));
    console.log('main called 2');
    allocationTest(100);
    await new Promise((r) => setTimeout(r, 500));
    console.log('main called 3');
    allocationTest(100);
    await new Promise((r) => setTimeout(r, 500));

}

main();

// setTimeout(() => console.log('\ntimeout all buffer should had been released'), 5000);

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