{
    "targets": [{
        "target_name": "cv2",
        "sources": [
#            "cc-v3/js_as_py.cpp",
#            "cc-v3/module.cpp",
             # must be relative path on linux ! add -r for relatif path
             "<!@(node ./tools/listFiles.mjs -r cc-common cpp)",
             "<!@(node ./tools/listFiles.mjs -r cc-common cc)",
             "<!@(node ./tools/listFiles.mjs -r cc-obj cpp)",
             # "<!@(node ./tools/listFiles.mjs -r cc-v4 cpp)",
             # "cc-v4/cv_mat_object.cpp",
             # "cc-v4/module.cpp",
        ],
        'include_dirs': [
                "<!@(node -p \"require('node-addon-api').include\")",
                "<!@(node ./tools/listFiles.mjs include_dirs)",
        ],
        'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
        "defines": [
        ],
        "libraries": [
            # "<!@(node ./tools/compileLib.js)",
            "<!@(node ./tools/listFiles.mjs libraries)",
            #"$(OPENCV_BUILD_ROOT)/latest/build/lib/Release/opencv_ximgproc470.lib",
            #"$(OPENCV_BUILD_ROOT)/latest/build/lib/Release/opencv_imgcodecs470.lib",
        ],
        'cflags!': ['-fno-exceptions', '-fno-rtti'],
        'cflags_cc!': ['-fno-exceptions', '-fno-rtti'],
        'xcode_settings': {
            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
            "GCC_ENABLE_CPP_RTTI": "YES",
            'CLANG_CXX_LIBRARY': 'libc++',
            'MACOSX_DEPLOYMENT_TARGET': '10.7'
        },
        'msvs_settings': {
            'VCCLCompilerTool': {'ExceptionHandling': 1},
        }
    }]
}
