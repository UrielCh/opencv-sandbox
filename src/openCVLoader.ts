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
      if (candidate.includes("build")) {
        return `${opencvRoot}/build`;
      }
      throw Error("update listFiles to support your environment");
    }
    throw Error("OPENCV_BUILD_ROOT is not defined");
  }

export function getModulePath(): string {
    let opencvBinDir = '';
    if (process.env.OPENCV_BUILD_ROOT) {
        // for windows
        opencvBinDir = path.join(getOpenCVRoot(), 'bin', 'Release')
        let error = `OPENCV_BUILD_ROOT is set but the path does not exist: ${opencvBinDir}`;
        if (!fs.existsSync(opencvBinDir)) {
          opencvBinDir = path.join(getOpenCVRoot(), 'lib')
          if (!fs.existsSync(opencvBinDir)) {
            throw Error(error + ` or ${opencvBinDir}`);
          }
        }
        // /home/uriel/opencv/latest/build/lib/libopencv_core.so
    }

    if (!process.env.PATH) {
      console.error(`PATH env value is not visible, I can not append opencvBinDir(${opencvBinDir}) to your PATH`);
    } else if (opencvBinDir && !process.env.PATH.includes(opencvBinDir)) {
        console.log(`Adding ${opencvBinDir} to PATH`)
        process.env.PATH = `${process.env.PATH}${path.delimiter}${opencvBinDir}`;
        // process.env.LD_LIBRARY_PATH = `${process.env.LD_LIBRARY_PATH}${path.delimiter}${opencvBinDir}`;
        // console.log(`process.env.PATH: ${process.env.PATH}`)
        // console.log(`process.env.LD_LIBRARY_PATH: ${process.env.LD_LIBRARY_PATH}`)
      } else {
        console.error(`no opencvBinDir(${opencvBinDir}) added to PATH`, process.env.PATH);
    }


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
    // impPath = pathToFileURL(path.resolve(impPath)).href;
    return impPath;
}