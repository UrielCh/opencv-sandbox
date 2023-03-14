import { type OpencvModule, OpenCVBuilder, OpenCVBuildEnv, type OpenCVBuildEnvParams, args2Option, genHelp } from '@u4/opencv-build'
import * as path from 'path'
import { EOL } from 'os'
import * as log from 'npmlog'
import * as pc from 'picocolors'

// import * as log from 'npmlog'
// import { resolvePath } from '../lib/commons.js'
// import * as path from 'path'
// import { EOL } from 'os'
// import blob from '@u4/tiny-glob';
// import { getOpenCV } from '../lib/cvloader.js'

export function resolvePath(filePath?: string, file?: string): string {
    if (!filePath) {
      return ''
    }
    return (file ? path.resolve(filePath, file) : path.resolve(filePath)).replace(/\\/g, '/')
  }
  

/**
 * convert lib list to existing parameter for the linker
 * @param env 
 * @param libDir 
 * @param libsFoundInDir 
 * @returns 
 */
function getOPENCV4NODEJS_LIBRARIES(env: OpenCVBuildEnv, libDir: string, libsFoundInDir: OpencvModule[]): string[] {
    const libs = env.isWin
        ? libsFoundInDir.map(lib => resolvePath(lib.libPath))
        // dynamically link libs if not on windows
        : ['-L' + libDir]
            .concat(libsFoundInDir.map(lib => '-lopencv_' + lib.opencvModule))
            .concat('-Wl,-rpath,' + libDir)

    if (libs.length > 0) {
        const dir = path.dirname(libs[0]);
        const names = libs.map(lib => path.basename(lib))
        log.info('libs', `${EOL}Setting lib from ${pc.green(dir)} : ${names.map(pc.yellow).join(', ')}`)
    } else {
        log.info('libs', `${EOL}no Libs available`)
    }
    return libs;
}

const defaultDir = '/usr/local'
const defaultLibDir = `${defaultDir}/lib`

/**
 * @returns return a path like /usr/local/lib
 */
function getDefaultLibDir(env: OpenCVBuildEnv) {
    log.info('install', 'OPENCV_LIB_DIR is not set, looking for default lib dir')
    if (env.isWin) {
        throw new Error('OPENCV_LIB_DIR has to be defined on windows when auto build is disabled')
    }
    return defaultLibDir
}

/**
 * @returns a built lib directory
 */
function getLibDir(env: OpenCVBuildEnv): string {
    if (env.isAutoBuildDisabled) {
        return resolvePath(process.env.OPENCV_LIB_DIR) || getDefaultLibDir(env);
    } else {
        const dir = resolvePath(env.opencvLibDir);
        if (!dir) {
            throw Error('failed to resolve opencvLibDir path');
        }
        return dir;
    }
}

try {
    const builder = new OpenCVBuilder({ prebuild: 'latestBuild' });
    const libDir: string = getLibDir(builder.env);
    const libsInDir: OpencvModule[] = builder.getLibs.getLibs();
    const libsFoundInDir: OpencvModule[] = libsInDir.filter(lib => lib.libPath);
    const OPENCV4NODEJS_LIBRARIES = getOPENCV4NODEJS_LIBRARIES(builder.env, libDir, libsFoundInDir).join(';');
    const outputs = OPENCV4NODEJS_LIBRARIES.split(/[\n;]/);
    outputs.forEach(o => console.log(o));
} catch (_e) {
    // ignore
}

