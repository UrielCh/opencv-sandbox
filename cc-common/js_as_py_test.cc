#include "js_as_py.h"
#include <iostream>

const std::string RED("\033[0;31m");
const std::string GREEN("\033[1;32m");
const std::string YELLOW("\033[1;33m");
const std::string CYAN("\033[0;36m");
const std::string MAGANTA("\033[0;35m");
const std::string RESET("\033[0m");
const std::string NEW(" (" + RED + "NEW" + RESET + ")");


// cc file are used for test
// #define SECTION(Name) currentTest = Name; std::cout << "Test SECTION: " << currentTest << std::endl;
// #define REQUIRE(TEST) if (!(TEST)) { std::cout << "ERROR in Test: " << currentTest << std::endl; failmsg(env, "Test Failed %s", currentTest); return; }
// this try catch is not apply correctly, need to be fix or split in 2 macro
#define SECTION(name, ...)                                                                        \
    try                                                                                           \
    {                                                                                             \
        std::cout << "start SECTION:" << YELLOW << name << RESET << std::endl;                    \
        __VA_ARGS__                                                                               \
    }                                                                                             \
    catch (const std::exception &ex)                                                              \
    {                                                                                             \
        failmsg(env, "Error in section \"%s\" of test \"%s\": %s", name, currentTest, ex.what()); \
    }

#define REQUIRE(cond)                                            \
    if (!(cond))                                                 \
    {                                                            \
        throw std::runtime_error("Requirement not met: " #cond); \
    }

void Js_BuildValue_test(const Napi::CallbackInfo &info)
{
    auto currentTest = "Js_BuildValue_test";
    Napi::Env env = info.Env();
    SECTION("Integer")
    {
        Napi::Value value = Js_BuildValue(info, "i", 42);
        REQUIRE(value.IsNumber());
        REQUIRE(value.As<Napi::Number>().Int32Value() == 42);
    }

    SECTION("Floating-point")
    {
        Napi::Value value = Js_BuildValue(info, "f", 3.14);
        REQUIRE(value.IsNumber());
        REQUIRE(value.As<Napi::Number>().DoubleValue() == 3.14);
    }

    SECTION("String")
    {
        Napi::Value value = Js_BuildValue(info, "s", "hello");
        REQUIRE(value.IsString());
        REQUIRE(value.As<Napi::String>().Utf8Value() == "hello");
    }

    SECTION("Boolean")
    {
        Napi::Value value = Js_BuildValue(info, "b", true);
        REQUIRE(value.IsBoolean());
        REQUIRE(value.As<Napi::Boolean>().Value() == true);
    }

    SECTION("Array")
    {
        Napi::Value value = Js_BuildValue(info, "(ifsb)", 1, 2.0, "three", false);
        REQUIRE(value.IsArray());
        Napi::Array array = value.As<Napi::Array>();
        REQUIRE(array.Length() == 4);
        REQUIRE(array.Get((uint32_t)0).As<Napi::Number>().Int32Value() == 1);
        REQUIRE(array.Get(1).As<Napi::Number>().DoubleValue() == 2.0);
        REQUIRE(array.Get(2).As<Napi::String>().Utf8Value() == "three");
        REQUIRE(array.Get(3).As<Napi::Boolean>().Value() == false);
    }

    SECTION("Object")
    {
        Napi::Value value = Js_BuildValue(info, "{s:s,s:i,s:b}", "name", "Alice", "age", 42, "female", true);
        REQUIRE(value.IsObject());
        Napi::Object object = value.As<Napi::Object>();
        REQUIRE(object.Has("name"));
        REQUIRE(object.Get("name").As<Napi::String>().Utf8Value() == "Alice");
        REQUIRE(object.Has("age"));
        REQUIRE(object.Get("age").As<Napi::Number>().Int32Value() == 42);
        REQUIRE(object.Has("female"));
        REQUIRE(object.Get("female").As<Napi::Boolean>().Value() == true);
    }
}


void JsArg_ParseTupleAndKeywords_test(const Napi::CallbackInfo &info_)
{
    auto currentTest = "Js_BuildValue_test";
    Napi::Env env = info_.Env();

    Napi::Value arg1_i42 = Napi::Number::New(env, 42);
    Napi::Value arg5_i13 = Napi::Number::New(env, 13);
    Napi::Value arg2_sTest = Napi::String::New(env, "test");
    Napi::Value arg3_bool = Napi::Boolean::New(env, true);
    Napi::Object optional_obj = Napi::Object::New(env);
    optional_obj.Set("opt1", arg5_i13);
    optional_obj.Set("opt2", Napi::String::New(env, "optional"));
    Napi::Value arg4 = optional_obj;

    // FakeCallbackInfo info(info_, {arg1_i42, arg2_sTest, arg3_bool, arg4});

    SECTION("Basic test with required arguments")
    {
        FakeCallbackInfo info(info_, {arg1_i42, arg2_sTest, arg3_bool, arg4});
        const Napi::Value *a1, *a2;
        const char *keywords[] = {"ext", "img", NULL};
        bool result = JsArg_ParseTupleAndKeywords(info, "OO", (char **)keywords, &a1, &a2);
        REQUIRE(result == true);
        REQUIRE(a1->As<Napi::Number>().Int32Value() == 42);
        REQUIRE(a2->As<Napi::String>().Utf8Value() == "test");
    }

    SECTION("Basic test with optional arguments")
    {
        FakeCallbackInfo info(info_, {arg1_i42, arg2_sTest, arg5_i13, arg4});
        const Napi::Value *a1, *a2, *opt1, *opt2;
        const char *keywords[] = {"a1", "a2", "opt1", "opt2", nullptr};
        bool result = JsArg_ParseTupleAndKeywords(info, "OO|OO", (char **)keywords, &a1, &a2, &opt1, &opt2);
        REQUIRE(result == true);
        REQUIRE(a1->As<Napi::Number>().Int32Value() == 42);
        REQUIRE(a2->As<Napi::String>().Utf8Value() == "test");
        REQUIRE(opt1->As<Napi::Number>().Int32Value() == 13);
        REQUIRE(opt2->As<Napi::String>().Utf8Value() == "optional");
    }

    SECTION("Test with optional arguments and optional object")
    {
        FakeCallbackInfo info(info_, {arg1_i42, arg2_sTest, arg3_bool, arg4});
        const Napi::Value *a1, *a2, *opt1, *opt2;
        const char *keywords[] = {"a1", "opt1", "opt2", nullptr};
        bool result = JsArg_ParseTupleAndKeywords(info, "O|OO", (char **)keywords, &a1, &optional_obj);

        REQUIRE(result == true);
        REQUIRE(a1->As<Napi::Number>().Int32Value() == 42);
        // REQUIRE(opt1->As<Napi::Number>().Int32Value() == 13);
        // REQUIRE(opt2->As<Napi::String>().Utf8Value() == "optional"); // FIX ME
    }

    // SECTION("Test with invalid format string")
    // {
    //     FakeCallbackInfo info(info_, {arg1_i42, arg2_sTest, arg3_bool, arg4});
    //     const Napi::Value *a1, *a2, *opt1;
    //     const char *keywords[] = {"opt1", nullptr};
    //     bool result = JsArg_ParseTupleAndKeywords(info, "O||OO", (char **)keywords, &a1, &opt1, &a2);
// 
    //     // The function should return false when the format string is invalid
    //     REQUIRE(result == false);
    // }
// 
    // SECTION("Test with not enough required arguments provided")
    // {
    //     FakeCallbackInfo info(info_, {arg1_i42, arg2_sTest, arg3_bool, arg4});
    //     const Napi::Value *a1, *a2, *a3, *a4;
    //     const char *keywords[] = {nullptr};
    //     bool result = JsArg_ParseTupleAndKeywords(info, "OOOO", (char **)keywords, &a1, &a2, &a3, &a4);
// 
    //     REQUIRE(result == false);
    // }
// 
    // SECTION("Test with function name in format string")
    // {
    //     FakeCallbackInfo info(info_, {arg1_i42, arg2_sTest, arg3_bool, arg4});
    //     const Napi::Value *a1, *a2;
    //     const char *keywords[] = {nullptr};
    //     bool result = JsArg_ParseTupleAndKeywords(info, "OO:TestFunction", (char **)keywords, &a1, &a2);
// 
    //     REQUIRE(result == true);
    //     REQUIRE(a1->As<Napi::Number>().Int32Value() == 42);
    //     REQUIRE(a2->As<Napi::String>().Utf8Value() == "test");
    // }
}