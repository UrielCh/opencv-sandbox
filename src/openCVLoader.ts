import path from 'path'
import fs from 'fs'

/**
 * 
 * @returns copy from listFiles.mjs
 */
function getOpenCVRoot(): string {
    if (
      process.env["OPENCV_BUILD_ROOT"] &&
      fs.existsSync(process.env["OPENCV_BUILD_ROOT"])
    ) {
      const opencvRoot = process.env["OPENCV_BUILD_ROOT"];
      const candidate = fs.readdirSync(opencvRoot);
      if (candidate.includes("opencv-4.7.0-8b1ea")) {
        return `${opencvRoot}/opencv-4.7.0-8b1ea/build`;
      }
      if (candidate.includes("latest")) {
        return `${opencvRoot}/latest/build`;
      }
      throw Error("update listFiles to support your environment");
    }
    throw Error("OPENCV_BUILD_ROOT is not defined");
  }

export function getModulePath(): string {
    let opencvBinDir = '';
    if (process.env.OPENCV_BUILD_ROOT) {
        opencvBinDir = path.join(getOpenCVRoot(), 'bin', 'Release')
        if (!fs.existsSync(opencvBinDir))
            throw Error(`OPENCV_BUILD_ROOT is set but the path does not exist: ${opencvBinDir}`)
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

    // console.log({ impPath, path: process.env.path });
    if (!impPath) {
        console.error('module not found')
        process.exit(1);
    }
    return impPath;
}