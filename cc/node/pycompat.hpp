// implement same function as pycompat.hpp
#include <napi.h>
#include <../parse.hh>
#include <../node/cv2_convert.hpp>


static inline bool getUnicodeString(Napi::Value* obj, std::string &str) {
  if (!obj->IsString()) {
    return false;
  }
  
  Napi::String utf16Str = obj->As<Napi::String>();
  std::u16string utf16 = utf16Str.Utf16Value();

  str.clear();
  str.reserve(utf16.size());

  for (const char16_t c : utf16) {
    str.push_back(static_cast<char>(c & 0xFF));
  }
  *obj = utf16Str;
  return true;
}

// static inline
// std::string getJsObjectNameAttr(Napi::Env env, Napi::Value* obj)
// {
//   if (!obj || !obj->IsObject()) {
//     return "";
//   }
// 
//   // Napi::Object jsObj = obj->As<Napi::Object>();
//   // Napi::Object proto = jsObj.Get(Napi::Symbol::GetPrototypeOf()).As<Napi::Object>();
//   // std::string objName = proto.Get("constructor").As<Napi::Function>().Name();
//   // Napi::Object jsObj = obj->As<Napi::Object>();
//   // Napi::Object proto = jsObj.Get(Napi::Env::Default().Global().Get("Object").As<Napi::Object>().Get("prototype")).As<Napi::Object>();
//   // std::string objName = proto.Get("constructor").As<Napi::Function>().Name();
// 
// 
//   // Napi::Object jsObj = obj->As<Napi::Object>();
//   // // Napi::Value proto;
//   // napi_value proto;
//   // // Napi::Object::proto
//   // napi_get_prototype(env, jsObj, &proto);
//   // Napi::Object protoObj = proto.As<Napi::Object>();
//   // std::string objName = protoObj.Get("constructor").As<Napi::Function>().Name();
// 
//   return objName;
// }

// like PyCFunction
Napi::Value JsCFunction(const Napi::CallbackInfo &info);


#define CV_JS_FN_WITH_KW_(fn, flags) (JsCFunction)(void*)(PyCFunctionWitheKywords)(fn), (flags) | METH_VARARGS | METH_KEYWORDS
#define CV_JS_FN_NOARGS_(fn, flags) (JsCFunction)(fn), (flags) | METH_NOARGS

#define CV_JS_FN_WITH_KW(fn) CV_PY_FN_WITH_KW_(fn, 0)
#define CV_JS_FN_NOARGS(fn) CV_PY_FN_NOARGS_(fn, 0)
