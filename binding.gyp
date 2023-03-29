{
    "targets": [{
        "target_name": "cv2",
        "sources": [
#            "cc-v3/js_as_py.cpp",
#            "cc-v3/module.cpp",
            "<!@(node -p \"require('fs').readdirSync('./cc-v4').filter(a=>a.endsWith('.cpp')).map(f=>'cc-v4/'+f).join(' ')\")"
        ],
        'include_dirs': [
                "<!@(node -p \"require('node-addon-api').include\")",
                "$(OPENCV_BUILD_ROOT)/latest/build/include",
                "$(OPENCV_BUILD_ROOT)/latest/build/include/opencv4",
                "cc",
                ],
        'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],

        "defines": [
            "<!@(node ./install/parseEnv.js OPENCV4NODEJS_DEFINES)",
        ],
        "libraries": [
            "<!@(node ./install/compileLib.js)",
            "<!@(node -p \"require('fs').readdirSync(`${process.env.OPENCV_BUILD_ROOT}/latest/build/lib/Release/`).filter(a=>a.endsWith('.lib')).map(f=>`${process.env.OPENCV_BUILD_ROOT}/latest/build/lib/Release/${f}`).join(' ')\")"
            #"$(OPENCV_BUILD_ROOT)/latest/build/lib/Release/opencv_ximgproc470.lib",
            #"$(OPENCV_BUILD_ROOT)/latest/build/lib/Release/opencv_core470.lib",
            #"$(OPENCV_BUILD_ROOT)/latest/build/lib/Release/opencv_ximgproc470.lib",
            #"$(OPENCV_BUILD_ROOT)/latest/build/lib/Release/opencv_imgcodecs470.lib",
        ],
        'cflags!': ['-fno-exceptions', '-fno-rtti'],
        'cflags_cc!': ['-fno-exceptions', '-fno-rtti'],
        'xcode_settings': {
            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
            'CLANG_CXX_LIBRARY': 'libc++',
            'MACOSX_DEPLOYMENT_TARGET': '10.7'
        },
        'msvs_settings': {
            'VCCLCompilerTool': {'ExceptionHandling': 1},
        }
    }]
}
