#ifndef __EXTRA_COMMON__H__
#define __EXTRA_COMMON__H__
#include <napi.h>

// this code is used by js_as_py.h and by cv2_util.h
// this code may be moved to js_as_py.h by the 2 following Napi::Symbol are define in cv2_utils.cpp
// or a js_as_py.cpp should be created.
extern Napi::Symbol DATA_KEY;
extern Napi::Symbol DATA_TYPE;

// MACRO version
// #define GET_INTERNAL_DATA(TYPE) info.This().As<Napi::Object>().Get(DATA_KEY).As<Napi::External<TYPE>>().Data();
// usage: AKAZE *akaze = GET_INTERNAL_DATA(AKAZE);

// inline version
template <typename TYPE>
inline TYPE *getInternalData(const Napi::Value &value) {
    return value.As<Napi::Object>().Get(DATA_KEY).As<Napi::External<TYPE>>().Data();
}
// usage: AKAZE *akaze = getInternalData<AKAZE>(info.This());

inline std::string getInternalType(const Napi::Value &value) {
    return value.As<Napi::Object>().Get(DATA_TYPE).As<Napi::String>().Utf8Value();
}

#endif