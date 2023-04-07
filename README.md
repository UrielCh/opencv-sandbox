## openCV binding sandbox

### Install OpenCV

export `OPENCV_BUILD_ROOT` to a openCV source workdir.

build openCV and keep sources with:

`npm run build-opencv`

then duplicate and update your environement in `.vscode/c_cpp_properties.json` if needed,

in vscode choose the correct C/C++ configuration at the bootom rigth of your screen.

### Build NodeJs C++ bindings

`node-gyp rebuild; ts-node-cwd.CMD .\src\index.ts`

### Test the built module

`npm run test`

## Generator

### Install the python environment

doc: https://docs.conda.io/projects/conda/en/4.6.0/user-guide/tasks/manage-environments.html
```bash
# list availible env:
conda info --envs
# list package in the dedicate env:
conda create --name opencv-sandbox python=3.7
conda list -n opencv-sandbox
conda activate opencv-sandbox
```

### Install the python package locally

```bash
pip install -e .
```

### Prepare the headers

Headers should be present somewhere in your opencv install like : 

```bash
cp ${OPENCV_BUILD_ROOT}/latest/build/modules/python_bindings_generator/headers.txt data/headers.txt
```

```powershell
cp ${Env:OPENCV_BUILD_ROOT}/latest/build/modules/python_bindings_generator/headers.txt data/headers.txt
```

To generate only part of the bindings, you can remove line from `data/headers.txt`

The minimum `data/headers.txt` file is 
```txt
${OPENCV_BUILD_ROOT}/latest/build/modules/core/include/opencv2/core.hpp
${Env:OPENCV_BUILD_ROOT}/latest/build/modules/core/include/opencv2/core.hpp
%OPENCV_BUILD_ROOT%/latest/build/modules/core/include/opencv2/core.hpp
```

### run original generator:

```powershell
cd ${Env:OPENCV_BUILD_ROOT}/latest/opencv/modules/python/src2
conda activate opencv-sandbox
mkdir dst
python gen2.py dst
```

### Run the generator

Once the `headers.txt` is ready you can do

```bash
mkdir -p cc-generated
python nodejs_opencv_generator/gen2.py cc-generated data/headers.txt
```

The code whould be visible in `cc-generated`


### References

- [cpython](https://github.com/python/cpython) fo check the unbderlying implementation of python functions.
- [opencv](https://github.com/opencv/opencv) opencv source code
- [opencv build helper](https://github.com/UrielCh/npm-opencv-build)
- [cpp insights](https://cppinsights.io/) for better templates undetanding
- [issue node-addon-api](https://github.com/nodejs/node-addon-api/issues/1120)
- [node-sqlite3 use node-addon-api](https://github.com/TryGhost/node-sqlite3)
- [leveldown use N-API via napi-macros](https://github.com/Level/leveldown)


### N-API libbs:

- [node-addon-api](https://www.npmjs.com/package/node-addon-api)
- [napi-macros](https://www.npmjs.com/package/napi-macros)