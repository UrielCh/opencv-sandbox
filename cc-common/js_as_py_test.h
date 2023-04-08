#ifndef JS_AS_PY_TEST_H
#define JS_AS_PY_TEST_H

#include <napi.h>

void Js_BuildValue_test(const Napi::CallbackInfo &info);
void JsArg_ParseTupleAndKeywords_test(const Napi::CallbackInfo &info_);

#endif // JS_AS_PY_TEST_H