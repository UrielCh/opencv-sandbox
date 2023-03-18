## openCV binding sandbox

### Install OpenCV

export `OPENCV_BUILD_ROOT` to a openCV source workdir.

build openCV and keep sources with:

`npx @u4/opencv-build --keepsources --version=4.7.0 --git-cache`
or
`npm run build-opencv`

then duplicate and update your environement in `.vscode/c_cpp_properties.json` if needed,

in vscode choose the correct C/C++ configuration at the bootom rigth of your screen.

### Build NodeJs C++ bindings

`node-gyp rebuild; ts-node-cwd.CMD .\src\index.ts`

### Test the built module

`npm run test`

## Generator

### Install the python environment

```bash
conda create --file environment.yml python=3.7
conda activate opencv-sandbox
```

### Install the python package locally

```bash
pip install .
```

### Prepare the headers

Headers should be present somewhere in your opencv install like : 

```bash
cp ${OPENCV_BUILD_ROOT}/latest/build/modules/python_bindings_generator/headers.txt data/headers.txt
```

To generate only part of the bindings, you can remove line from `data/headers.txt`

The minimum `data/headers.txt` file is 
```txt
/<opencv source location>/modules/core/include/opencv2/core.hpp
```

### Run the generator

Once the `headers.txt` is ready you can do

```bash
mkdir -p cc-generated
python nodejs_opencv_generator/gen2.py cc-generated data/headers.txt
```

The code whould be visible in `cc-generated`