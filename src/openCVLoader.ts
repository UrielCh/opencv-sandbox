import path from 'path'
import fs from 'fs'


export function getModulePath(): string {
    let opencvBinDir = '';
    if (process.env.OPENCV_BUILD_ROOT) {
        opencvBinDir = path.join(process.env.OPENCV_BUILD_ROOT, 'opencv-4.7.0-8b1ea', 'build', 'bin', 'Release')
    }
    if (opencvBinDir && process.env.path && !process.env.path.includes(opencvBinDir)) {
        console.log(`Adding opencvBinDir: ${opencvBinDir} to path`)
        process.env.path = `${process.env.path};${opencvBinDir};`;
    } else {
        console.error('no opencvBinDir added to path');
    }
    // console.log(process.env.path);


    let impPath = '';
    main: for (const type of ['Release', 'Debug']) {
        for (const pt of [`../build/${type}/cv2.node`, `./build/${type}/cv2.node`]) {
            if (fs.existsSync(pt)) {
                impPath = path.resolve(pt);
                break main;
            }
        }
    }

    console.log({ impPath });
    if (!impPath) {
        console.error('module not found')
        process.exit(1);
    }
    return impPath;
}