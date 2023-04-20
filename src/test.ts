import test from 'ava';
import { cvMatObject } from "../types/cv-v4";
import { getModulePath } from "./openCVLoader";

type TopenCV = typeof import('../types/cv-v4');


let theModule: TopenCV = undefined as unknown as TopenCV;
//test.before(() => {
// console.log('before test');
const impPath = getModulePath();
const theModuleTmp = require(impPath);
theModule = theModuleTmp as TopenCV;
// })


async function getOPpenCVModule(): Promise<TopenCV> {
    return theModule;
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


test.serial('get openCV Version', async t => {
    const major = theModule.getVersionMajor();
    t.true(major >= 4);
    const minor = theModule.getVersionMinor();
    t.true(Number.isInteger(minor));
});

test.serial('imread logo.png default', async t => {
    let logo: cvMatObject;
    // load with default params
    logo = theModule.imread('./data/logo.png');
    t.is(logo.cols, 100);
    t.is(logo.rows, 132);
    t.is(logo.channels, 3);
    t.is(logo.type, 16);
});

test.serial('imread logo.png empty optional object', async t => {
    let logo: cvMatObject;
    // load with default params
    logo = theModule.imread('./data/logo.png', {});
    t.is(logo.cols, 100);
    t.is(logo.rows, 132);
    t.is(logo.channels, 3);
    t.is(logo.type, 16);
});

test.serial('imread logo.png inline flags IMREAD_REDUCED_GRAYSCALE_4', async t => {
    let logo: cvMatObject;
    // load with default params
    logo = theModule.imread('./data/logo.png', IMREAD_REDUCED_GRAYSCALE_4);
    // logo = theModule.imread('./data/logo.png', { });
    t.is(logo.cols, 25);
    t.is(logo.rows, 33);
    // t.is(logo.channels, 1);
    t.is(logo.type, 0);
});

test.serial('imread logo.png { flags: IMREAD_REDUCED_GRAYSCALE_4 }', async t => {
    let logo: cvMatObject;
    // load with default params
    logo = theModule.imread('./data/logo.png', { flags: IMREAD_REDUCED_GRAYSCALE_4 });
    // logo = theModule.imread('./data/logo.png', { });
    t.is(logo.cols, 25);
    t.is(logo.rows, 33);
    // t.is(logo.channels, 1);
    t.is(logo.type, 0);
});
 
test.serial('imencode logo as PNG has correct Magic number', async t => {
    let logo: cvMatObject;
    // load with default params
    logo = theModule.imread('./data/logo.png', { flags: IMREAD_REDUCED_GRAYSCALE_4 });
    t.is(logo.cols, 25);
    t.is(logo.rows, 33);
    t.is(logo.channels, 1);
    // t.is(logo.toString(), "Matrix: 33x25 type:0 Channels:1 ElemSize:1 ElemSize1:1");
    // console.log('flags:',  logo.flags);
    // console.log('data:',  logo.data);
    t.truthy(theModule.imencode)
    const out = theModule.imencode(".png", logo);
    t.true(Array.isArray(out));
    t.true(out[0])
    const buffer = out[1];
    const pngSignature = [137, 80, 78, 71, 13, 10, 26, 10];
  
    if (buffer.length < pngSignature.length) {
      return false;
    }
    for (let i = 0; i < pngSignature.length; i++) {
        t.is(buffer[i],  pngSignature[i]);
      }
});



test.serial('create AKAZE using new constructor', async t => {
    if (theModule.AKAZE) {
        t.deepEqual(Object.keys(theModule.AKAZE), ["create"], 'AKAZE class should contains a singler static method');
        console.log(typeof(theModule.AKAZE));
        console.log(theModule.AKAZE);
        console.log(Object.keys(theModule.AKAZE));
        const obj = new theModule.AKAZE()
        console.log(obj);
    } else {
        console.log(`AKAZE is Not present No test`);
        t.pass()
    }
});

test.serial('create AKAZE using static AKAZE.create()', async t => {
    try {
    if (theModule.AKAZE) {
        console.log('allocating AKAZE using AKAZE.create');
        const descriptor_size = 120;
        const obj = theModule.AKAZE.create({descriptor_size, diffusivity: 300});
        console.log('AKAZE:', obj);
        console.log('AKAZE.getDescriptorSize:', obj.getDescriptorSize());
        t.is(obj.getDescriptorSize(), descriptor_size, 'AKAZE.getDescriptorSize should return the value passed to AKAZE.create');
    } else {
        console.log(`AKAZE is Not present No test`);
        t.pass()
    }
    } catch (e) { 
        t.fail((e as Error).message)
    }
});

/**
 * register tests
 */
if (theModule.runAvaTest)
    theModule.runAvaTest(test);

// test.serial('C++ Test', async t => {
//     const theModule = await getOPpenCVModule();
//     t.truthy(theModule.test, `C++ test not availible`);
//     if (theModule.test) {
//         const result = theModule.test(test);
//         t.is(result.fail, 0, `${result.fail} native test failed`);
//         t.true(result.pass > 0, "no native test passed");
//     }
// });

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