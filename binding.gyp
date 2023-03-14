{
    "targets": [{
        "target_name": "cv2",
        "include_dirs": [
            "C:/0/opencv/latest/build/include",
            "cc",
        ],
        "defines": [
            "<!@(node ./install/parseEnv.js OPENCV4NODEJS_DEFINES)",
        ],
        "libraries": [
			"C:/0/opencv/latest/build/lib/Release/opencv_core470",
		],
		"cflags" : [
			"-std=c++14"
		],
		"cflags!" : [
			"-fno-exceptions"
		],
		"cflags_cc!": [
			"-fno-rtti",
			"-fno-exceptions"
		],
		"ldflags" : [
			"-Wl,-rpath,'$$ORIGIN'"
		],
	
        "sources": ["./cc/module.cc"]
    }]
}
