import test from 'ava';
import { cvMatObject } from "../types/cv-v4";
import { getModulePath } from "./openCVLoader";

type TopenCV = typeof import('../types/cv-v4');


let theModule: TopenCV = undefined as unknown as TopenCV;
test.before(() => {
    console.log('before test');
    const impPath = getModulePath();
    const theModuleTmp = require(impPath);
    theModule = theModuleTmp as TopenCV;

})


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

test.serial('main test', async t => {
    const theModule = await getOPpenCVModule();
    let logo: cvMatObject;
    // load with default params
    logo = theModule.imread('./data/logo.png', { flags: IMREAD_REDUCED_GRAYSCALE_4 });
    t.is(logo.cols, 25);
    t.is(logo.rows, 33);
    t.is(logo.toString(), "Matrix: 33x25 type:0 Channels:1 ElemSize:1 ElemSize1:1");

    if (theModule.imencode) {
        const out = theModule.imencode(".png", logo);
        console.log(out);
    }
    if (theModule.test) {
        theModule.test();
    }
});


// testimEncode();

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