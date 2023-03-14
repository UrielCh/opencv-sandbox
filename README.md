# openCV binding sandbox

to make works this sandbox:

export `OPENCV_BUILD_ROOT` to a openCV source workdir.

build openCV and keep sources with:

`npx @u4/opencv-build --keepsources --version=4.7.0 --git-cache`
or
`npm run build-opencv`

then duplicate and update your environement in `.vscode/c_cpp_properties.json` if needed,

in vscode choose the correct C/C++ configuration at the bootom rigth of your screen.

`node-gyp rebuild; ts-node-cwd.CMD .\src\index.ts`