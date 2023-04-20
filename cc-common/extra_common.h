#ifndef __EXTRA_COMMON__H__
#define __EXTRA_COMMON__H__
#include <napi.h>
#include <iostream>

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
    if (!value.IsObject())
        throw Napi::Error::New(value.Env(), "call getInternalData on a non Object");
    auto data_key = value.As<Napi::Object>().Get("DATA_KEY");
    if (data_key.IsUndefined())
        throw Napi::Error::New(value.Env(), "DATA_KEY is undefined");
    if (!data_key.IsExternal()) {
        std::cout << "getInternalData<" << typeid(TYPE).name() <<  ">(value) DATA_KEY should be anExternal data current Type: " << data_key.Type() << std::endl;
        if (data_key.IsString())
            std::cout << "getInternalData<" << typeid(TYPE).name() <<  ">(value) DATA_KEY should be anExternal data current Value: " << data_key.As<Napi::String>().Utf8Value() << std::endl;
        throw Napi::Error::New(value.Env(), "DATA_KEY should be an External data");
    }
    return data_key.As<Napi::External<TYPE>>().Data();
}
// usage: AKAZE *akaze = getInternalData<AKAZE>(info.This());

inline std::string getInternalType(const Napi::Value &value) {
    if (!value.IsObject())
        throw Napi::Error::New(value.Env(), "call getInternalType on a non Object");
    auto type_key = value.As<Napi::Object>().Get("DATA_TYPE");
    if (type_key.IsUndefined())
        throw Napi::Error::New(value.Env(), "DATA_TYPE is undefined in the current object");
    if (!type_key.IsString())
        throw Napi::Error::New(value.Env(), "DATA_TYPE should be an string");
    return type_key.As<Napi::String>().Utf8Value();
}

#endif