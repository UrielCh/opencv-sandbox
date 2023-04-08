#include "js_as_py.h"
#include <iostream>

// cc file are used for test
// #define SECTION(Name) currentTest = Name; std::cout << "Test SECTION: " << currentTest << std::endl;
// #define REQUIRE(TEST) if (!(TEST)) { std::cout << "ERROR in Test: " << currentTest << std::endl; failmsg(env, "Test Failed %s", currentTest); return; }

#define SECTION(name, ...)                                                                        \
    try                                                                                           \
    {                                                                                             \
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

