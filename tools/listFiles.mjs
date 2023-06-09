import fs from "fs";
import path from "path";
// import pc from "picocolors";

/**
 * @returns {boolean}
 */
function isRelative() {
  return process.argv.includes('-r') || process.argv.includes('--relative')
}

function replaceEnvVars(input) {
  const envVarPattern = /\${(\w+)}/g;
  return input.replace(envVarPattern, (match, varName) => {
    if (process.env[varName] !== undefined) {
      return process.env[varName];
    } else {
      console.warn(`Environment variable ${varName} not found.`);
      return match;
    }
  });
}
/**
 * @param {string} dir
 * @param {string} extStr
 * @returns {string[]}
 */
function listFiles(dir, extStr) {
  const exts = extStr.split(/[,\.]+/g).map((ext) => `.${ext}`);
  let list = [];
  try {
    list = fs.readdirSync(dir);
  } catch (e) {
    console.error(`Can not read directory ${dir}:`);
    console.error(e);
    return [];
  }
  let files = list.filter((file) => {
    for (const ext of exts) {
      if (file.endsWith(ext)) {
        return true;
      }
    }
    return false;
  });
  files = files
    .map((file) => path.join(dir, file));
  if (!isRelative())
    files = files.map((file) => path.resolve(file));
  return files;
}

/**
 * @param {string} directory
 * @param {string} extention
 */
function dumpFile(directory, extention) {
  directory = replaceEnvVars(directory);
  const files = listFiles(directory, extention);
  for (const file of files) {
    // console.log(file.replace(/\\/g, '\\\\'));
    console.log(file.replace(/\\/g, "/"));
  }
}

function getOpenCVRoot() {
  if (process.env["GITHUB_WORKSPACE"]) {
    const opencvRoot = path.resolve(process.env["GITHUB_WORKSPACE"], '..');
    const candidate = fs.readdirSync(opencvRoot);
    if (candidate.includes("build")) {
      return `${opencvRoot}/build`;
    }
    // throw Error("update listFiles to support your environment");
  }
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

const len = process.argv.length;
let src = process.argv[len - 2];

if ("include_dirs" === process.argv[len - 1]) {
  const opencvRoot = getOpenCVRoot();
  console.log(`${opencvRoot}`.replace(/\\/g, "/"));
  console.log(`${opencvRoot}/include`.replace(/\\/g, "/"));
  console.log(`${opencvRoot}/include/opencv4`.replace(/\\/g, "/"));
  // add opencv src Root include
  console.log(path.resolve(opencvRoot, '..', 'opencv', 'include').replace(/\\/g, "/"));
  // extra import should be include via openCVMakeFile
  // TODO Remove that after for the final version
  for (const mod of ['core', 'imgcodecs', 'imgproc', 'highgui', 'video', 'ml', 'flann', 'dnn', 'calib3d', 'videoio', 'videoio', 'gapi']) {
    let extraInc = path.resolve(opencvRoot, '..', 'opencv', 'modules', mod, 'include');
    console.log(extraInc.replace(/\\/g, "/"));
  }

} else if ("libraries" === process.argv[len - 1]) {
  const opencvRoot = getOpenCVRoot();
  let candidates = [`${opencvRoot}/lib/Release/`, `${opencvRoot}/lib/`]
  if (fs.existsSync(candidates[0]))
    dumpFile(candidates[0], "lib,so");
  else
    dumpFile(candidates[1], "lib,so");
} else {
  dumpFile(src, process.argv[len - 1]);
}