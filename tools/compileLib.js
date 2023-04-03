"use strict";
exports.__esModule = true;
exports.resolvePath = void 0;
var opencv_build_1 = require("@u4/opencv-build");
var path = require("path");
var os_1 = require("os");
var log = require("npmlog");
var pc = require("picocolors");
// import * as log from 'npmlog'
// import { resolvePath } from '../lib/commons.js'
// import * as path from 'path'
// import { EOL } from 'os'
// import blob from '@u4/tiny-glob';
// import { getOpenCV } from '../lib/cvloader.js'
function resolvePath(filePath, file) {
    if (!filePath) {
        return '';
    }
    return (file ? path.resolve(filePath, file) : path.resolve(filePath)).replace(/\\/g, '/');
}
exports.resolvePath = resolvePath;
/**
 * convert lib list to existing parameter for the linker
 * @param env
 * @param libDir
 * @param libsFoundInDir
 * @returns
 */
function getOPENCV4NODEJS_LIBRARIES(env, libDir, libsFoundInDir) {
    var libs = env.isWin
        ? libsFoundInDir.map(function (lib) { return resolvePath(lib.libPath); })
        // dynamically link libs if not on windows
        : ['-L' + libDir]
            .concat(libsFoundInDir.map(function (lib) { return '-lopencv_' + lib.opencvModule; }))
            .concat('-Wl,-rpath,' + libDir);
    if (libs.length > 0) {
        var dir = path.dirname(libs[0]);
        var names = libs.map(function (lib) { return path.basename(lib); });
        log.info('libs', "".concat(os_1.EOL, "Setting lib from ").concat(pc.green(dir), " : ").concat(names.map(pc.yellow).join(', ')));
    }
    else {
        log.info('libs', "".concat(os_1.EOL, "no Libs available"));
    }
    return libs;
}
var defaultDir = '/usr/local';
var defaultLibDir = "".concat(defaultDir, "/lib");
/**
 * @returns return a path like /usr/local/lib
 */
function getDefaultLibDir(env) {
    log.info('install', 'OPENCV_LIB_DIR is not set, looking for default lib dir');
    if (env.isWin) {
        throw new Error('OPENCV_LIB_DIR has to be defined on windows when auto build is disabled');
    }
    return defaultLibDir;
}
/**
 * @returns a built lib directory
 */
function getLibDir(env) {
    if (env.isAutoBuildDisabled) {
        return resolvePath(process.env.OPENCV_LIB_DIR) || getDefaultLibDir(env);
    }
    else {
        var dir = resolvePath(env.opencvLibDir);
        if (!dir) {
            throw Error('failed to resolve opencvLibDir path');
        }
        return dir;
    }
}
try {
    var builder = new opencv_build_1.OpenCVBuilder({ prebuild: 'latestBuild' });
    var libDir = getLibDir(builder.env);
    var libsInDir = builder.getLibs.getLibs();
    var libsFoundInDir = libsInDir.filter(function (lib) { return lib.libPath; });
    var OPENCV4NODEJS_LIBRARIES = getOPENCV4NODEJS_LIBRARIES(builder.env, libDir, libsFoundInDir).join(';');
    var outputs = OPENCV4NODEJS_LIBRARIES.split(/[\n;]/);
    outputs.forEach(function (o) { return console.log(o); });
}
catch (_e) {
    // ignore
}
