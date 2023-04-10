#ifndef JS_AS_PY_TEST_H
#define JS_AS_PY_TEST_H

#include <napi.h>

bool Js_BuildValue_test(const Napi::CallbackInfo &info);
bool JsArg_ParseTupleAndKeywords_test(const Napi::CallbackInfo &info);

#endif // JS_AS_PY_TEST_H