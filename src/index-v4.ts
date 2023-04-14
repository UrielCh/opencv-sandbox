import { assert } from "console";
import { cvMatObject } from "../types/cv-v4";
import { getModulePath } from "./openCVLoader";

type TopenCV = typeof import('../types/cv-v4');

const impPath = getModulePath();
const theModuleTmp = require(impPath);
const theModule = theModuleTmp as TopenCV;

async function getOPpenCVModule(): Promise<TopenCV>{
    return theModule;
}

// let __cached_TopenCV: TopenCV | undefined = undefined;
// async function getOPpenCVModule(): Promise<TopenCV>{
//     if (__cached_TopenCV)
//         return __cached_TopenCV;
//     const impPath = getModulePath();
//     let urlPath = pathToFileURL(resolve(impPath)).href;
//     // urlPath = urlPath.replace('node', 'bin')
//     urlPath = 'file:///C:/project/opencv/opencv-sandbox/build/Release/cv2.bin';
//     const module = await import(urlPath);
//     __cached_TopenCV = module;
//     console.log('require cv2.node called');
//     return module;
// }

/**
 * rebuild with node-gyp rebuild
 */

async function allocationTest(pass: number) {
    const theModule = await getOPpenCVModule();
    // const cv2 = cv2tmp as typeof import('../types/cv-v1');
    // main.ts
    // import cvMatObject = require('./cvMatObjectWrapper');
    let cnt = { alloc: 0, release: 0 };
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
            if ('Release' in tmp && typeof ((tmp as any).Release) === 'function') {
                // tmp.Release();
                (tmp as any).release++;
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


async function main2() {
    const theModule = await getOPpenCVModule();
    // console.log("main2", theModule.imread)
    // const tmp = new theModule.cvMatObject(50000, 2000);
    try {
        const logo = theModule.imread('./data/logo.png')
        console.log("logo cols:", logo.cols, " rows:", logo.rows, " type:", logo.type)
        console.log("-----------")
        console.log("logo:", logo)
        console.log("Object.keys(logo) return:", Object.keys(logo))
        console.log("logo:", logo.toString())

        try {
            // @ts-expect-error write a readonly property
            logo.rows = 1;
        } catch (e) {
            console.log("logo.rows is readonly Throw Ok");
        }
    } catch (e) {
        console.log((e as Error).message);
    }
}


const IMREAD_UNCHANGED = -1; //!< If set, return the loaded image as is (with alpha channel, otherwise it gets cropped). Ignore EXIF orientation.
const IMREAD_GRAYSCALE = 0;  //!< If set, always convert image to the single channel grayscale image (codec internal conversion).
const IMREAD_COLOR = 1;  //!< If set, always convert image to the 3 channel BGR color image.
const IMREAD_ANYDEPTH = 2;  //!< If set, return 16-bit/32-bit image when the input has the corresponding depth, otherwise convert it to 8-bit.
const IMREAD_ANYCOLOR = 4;  //!< If set, the image is read in any possible color format.
const IMREAD_LOAD_GDAL = 8;  //!< If set, use the gdal driver for loading the image.
const IMREAD_REDUCED_GRAYSCALE_2 = 16; //!< If set, always convert image to the single channel grayscale image and the image size reduced 1/2.
const IMREAD_REDUCED_COLOR_2 = 17; //!< If set, always convert image to the 3 channel BGR color image and the image size reduced 1/2.
const IMREAD_REDUCED_GRAYSCALE_4 = 32; //!< If set, always convert image to the single channel grayscale image and the image size reduced 1/4.
const IMREAD_REDUCED_COLOR_4 = 33; //!< If set, always convert image to the 3 channel BGR color image and the image size reduced 1/4.
const IMREAD_REDUCED_GRAYSCALE_8 = 64; //!< If set, always convert image to the single channel grayscale image and the image size reduced 1/8.
const IMREAD_REDUCED_COLOR_8 = 65; //!< If set, always convert image to the 3 channel BGR color image and the image size reduced 1/8.
const IMREAD_IGNORE_ORIENTATION = 128; //!< If set, do not rotate the image according to EXIF's orientation flag.


async function testLoad() {
    try {
        const theModule = await getOPpenCVModule();
        let logo: cvMatObject;
        // load with default params
        logo = theModule.imread('./data/logo.png')
        console.log("logo load default:\n", logo.toString())
        logo = theModule.imread('./data/logo.png', IMREAD_REDUCED_GRAYSCALE_2)
        console.log("logo load IMREAD_REDUCED_GRAYSCALE_2 as arg 2:\n", logo.toString())
        logo = theModule.imread('./data/logo.png', { flags: IMREAD_REDUCED_GRAYSCALE_4 });
        console.log("logo load {flag: IMREAD_REDUCED_GRAYSCALE_4} as opts:\n", logo.toString())
        logo = theModule.imread('./data/logo.png', {})
        console.log("logo load {} as opts:\n", logo.toString())
    } catch (e) {
        console.log((e as Error).message);
    }
}


async function testimEncode() {
    try {
        const theModule = await getOPpenCVModule();

        let logo: cvMatObject;
        // load with default params
        logo = theModule.imread('./data/logo.png', { flags: IMREAD_REDUCED_GRAYSCALE_4 });
        assert(logo.rows === 33, "logo.rows === 33");
        assert(logo.cols === 25, "logo.cols === 25");
        console.log("logo load {flag: IMREAD_REDUCED_GRAYSCALE_4} as opts:\n", logo.toString())

        if (theModule.imencode) {
            const out = theModule.imencode(".png", logo);
            console.log(out);
        }
    } catch (e) {
        console.log((e as Error).message);
    }
}

testimEncode();

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
