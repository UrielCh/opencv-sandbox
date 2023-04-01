import fs from 'fs';
import path from 'path';

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
  
const listFiles = (dir, extStr) => {
    const exts = extStr.split(/[,\.]+/g).map(ext => `.${ext}`);
    let list = [];
    try {
    list = fs.readdirSync(dir);
    } catch (e) {
        console.error(`can not read directory ${dir}: ${e}`);
        return [];
    }
    const files = list.filter(file => {
        for (const ext of exts) {
            if (file.endsWith(ext)) {
                return true;
            }
        }
        return false;
    });
    return files.map(file => path.join(dir, file)).map(file => path.resolve(file));
}

const len = process.argv.length;
let src = process.argv[len - 2];
// console.log('input: ' + src);
src = replaceEnvVars(src);
const files = listFiles(src, process.argv[len - 1]);
for (const file of files) {
    // console.log(file.replace(/\\/g, '\\\\'));
    console.log(file.replace(/\\/g, '/'));
}
