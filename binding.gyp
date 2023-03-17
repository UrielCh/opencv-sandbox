{
    "targets": [{
        "target_name": "cv2",
        "sources": [
            "./cc/module.cc",
            "./cc/node/cv2_util.cpp",
        ],
        'include_dirs': [
                "<!@(node -p \"require('node-addon-api').include\")",
                "C:/0/opencv/latest/build/include",
                "cc",
                ],
        'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],

        "defines": [
            "<!@(node ./install/parseEnv.js OPENCV4NODEJS_DEFINES)",
        ],
        "libraries": [
            "<!@(node ./install/compileLib.js)",
        ],
        'cflags!': ['-fno-exceptions'],
        'cflags_cc!': ['-fno-exceptions'],
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
