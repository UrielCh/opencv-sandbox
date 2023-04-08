#include "js_as_py.h"
#include <iostream>
#include <iomanip>

const std::string RED("\033[0;31m");
const std::string GREEN("\033[1;32m");
const std::string YELLOW("\033[1;33m");
const std::string CYAN("\033[0;36m");
const std::string MAGANTA("\033[0;35m");
const std::string RESET("\033[0m");
const std::string NEW(" (" + RED + "NEW" + RESET + ")");


#define TEST_START(name) \
        std::cout << "NEXT TEST:" << MAGANTA << name << RESET << std::endl;

#define SECTION_START(name) \
    try {

#define SECTION_END(name)                                                                         \
        std::cout << "SECTION:" << YELLOW << std::left << std::setw(60) << name << RESET << GREEN << " PASS" << RESET << std::endl;  \
    }                                                                                             \
    catch (const std::exception &ex)                                                              \
    {                                                                                             \
        std::cout << "SECTION:" << YELLOW << std::left << std::setw(60) << name << RESET << RED << " FAIL" << RESET << std::endl;  \
        std::cout << RED << "Error: " << RESET << currentTest << std::endl;   \
        std::cout << ex.what() << std::endl;   \
        failmsg(env, "Error in section \"%s\" of test \"%s\": %s", name, currentTest, ex.what()); \
    }

#define REQUIRE(cond)                                            \
    if (!(cond))                                                 \
    {                                                            \
        throw std::runtime_error("Requirement not met: " #cond); \
    }

void Js_BuildValue_test(const Napi::CallbackInfo &info)
{
    TEST_START("Js_BuildValue")
    auto currentTest = "Js_BuildValue_test";
    Napi::Env env = info.Env();
    SECTION_START("Integer")
    {
        Napi::Value value = Js_BuildValue(info, "i", 42);
        REQUIRE(value.IsNumber());
        REQUIRE(value.As<Napi::Number>().Int32Value() == 42);
    }
    SECTION_END("Integer")

    SECTION_START("Floating-point")
    {
        Napi::Value value = Js_BuildValue(info, "f", 3.14);
        REQUIRE(value.IsNumber());
        REQUIRE(value.As<Napi::Number>().DoubleValue() == 3.14);
    }
    SECTION_END("Floating-point")

    SECTION_START("String")
    {
        Napi::Value value = Js_BuildValue(info, "s", "hello");
        REQUIRE(value.IsString());
        REQUIRE(value.As<Napi::String>().Utf8Value() == "hello");
    }
    SECTION_END("String")

    SECTION_START("Boolean")
    {
        Napi::Value value = Js_BuildValue(info, "b", true);
        REQUIRE(value.IsBoolean());
        REQUIRE(value.As<Napi::Boolean>().Value() == true);
    }
    SECTION_END("Boolean")

    SECTION_START("Array")
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
    SECTION_END("Array")

    SECTION_START("Object")
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
    SECTION_END("Object")
}

void JsArg_ParseTupleAndKeywords_test(const Napi::CallbackInfo &info_)
{
    TEST_START("JsArg_ParseTupleAndKeywords")
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

    SECTION_START("Basic test with required arguments")
    {
        FakeCallbackInfo info(info_, {arg1_i42, arg2_sTest, arg3_bool, arg4});
        const Napi::Value *a1, *a2;
        const char *keywords[] = {"ext", "img", NULL};
        bool result = JsArg_ParseTupleAndKeywords(info, "OO", (char **)keywords, &a1, &a2);
        REQUIRE(result == true);
        REQUIRE(a1->As<Napi::Number>().Int32Value() == 42);
        REQUIRE(a2->As<Napi::String>().Utf8Value() == "test");
    }
    SECTION_END("Basic test with required arguments")

    SECTION_START("Basic test with optional argumentss")
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
    SECTION_END("Basic test with optional arguments")

    SECTION_START("Test with optional arguments and optional object")
    {
        FakeCallbackInfo info(info_, {arg1_i42, arg2_sTest, arg3_bool, arg4});
        const Napi::Value *a1, *a2, *opt1, *opt2;
        const char *keywords[] = {"a1", "opt1", "opt2", nullptr};
        bool result = JsArg_ParseTupleAndKeywords(info, "O|OO", (char **)keywords, &a1, &optional_obj);

        REQUIRE(result == true);
        REQUIRE(a1->As<Napi::Number>().Int32Value() == 42);
        // std::cout << NEW << opt1->IsNumber() << std::endl;
        // std::cout << NEW << "Value: " << opt1->As<Napi::Number>().Int32Value() << std::endl;
        // REQUIRE(opt1->As<Napi::Number>().Int32Value() == 42); // FIXME
        // REQUIRE(opt2->As<Napi::String>().Utf8Value() == "optional"); // FIX ME
    }
    SECTION_END("Test with optional arguments and optional object")
    //
    //SECTION_START("Test with invalid format string")
    //{
    //    FakeCallbackInfo info(info_, {arg1_i42, arg2_sTest, arg3_bool, arg4});
    //    const Napi::Value *a1, *a2, *opt1;
    //    const char *keywords[] = {"opt1", nullptr};
    //    bool result = JsArg_ParseTupleAndKeywords(info, "O||OO", (char **)keywords, &a1, &opt1, &a2);
    //    // The function should return false when the format string is invalid
    //    REQUIRE(result == false);
    //}
    //SECTION_END("Test with invalid format string")
    //
    //SECTION_START("Test with not enough required arguments provided")
    //{
    //    FakeCallbackInfo info(info_, {arg1_i42, arg2_sTest, arg3_bool, arg4});
    //    const Napi::Value *a1, *a2, *a3, *a4;
    //    const char *keywords[] = {nullptr};
    //    bool result = JsArg_ParseTupleAndKeywords(info, "OOOO", (char **)keywords, &a1, &a2, &a3, &a4);
    //    REQUIRE(result == false);
    //}
    //SECTION_END("Test with not enough required arguments provided")
    //
    //SECTION_START("Test with function name in format string")
    //{
    //    FakeCallbackInfo info(info_, {arg1_i42, arg2_sTest, arg3_bool, arg4});
    //    const Napi::Value *a1, *a2;
    //    const char *keywords[] = {nullptr};
    //    bool result = JsArg_ParseTupleAndKeywords(info, "OO:TestFunction", (char **)keywords, &a1, &a2);
    //    REQUIRE(result == true);
    //    REQUIRE(a1->As<Napi::Number>().Int32Value() == 42);
    //    REQUIRE(a2->As<Napi::String>().Utf8Value() == "test");
    //}
    //SECTION_END("Test with function name in format string")
}
