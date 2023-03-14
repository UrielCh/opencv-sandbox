# openCV binding sandbox

to make works this sandbox:

export `OPENCV_BUILD_ROOT` to a openCV source workdir.

build openCV and keep sources with:

`npx @u4/opencv-build --keepsources --version=4.7.0 --flags=-DBUILD_LIST=core,imgcodecs,calib3d,python3,python_bindings_generator --git-cache`

then duplicate and update your environement in `.vscode/c_cpp_properties.json`,

in vscode choose the correct C/C++ configuration at the bootom rigth of your screen.