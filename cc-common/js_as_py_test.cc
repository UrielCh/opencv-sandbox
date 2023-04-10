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
    try                     \
    {

#define SECTION_END(name)                                                                                                         \
    std::cout << "SECTION:" << YELLOW << std::left << std::setw(60) << name << RESET << GREEN << " PASS" << RESET << std::endl;   \
    }                                                                                                                             \
    catch (const std::exception &ex)                                                                                              \
    {                                                                                                                             \
        std::cout << "SECTION:" << YELLOW << std::left << std::setw(60) << name << RESET << RED << " FAIL" << RESET << std::endl; \
        std::cout << RED << "Error: " << RESET << currentTest << std::endl;                                                       \
        std::cout << ex.what() << std::endl;                                                                                      \
        failmsg(env, "Error in section \"%s\" of test \"%s\": %s", name, currentTest, ex.what());                                 \
    }
//
// #define REQUIRE(cond)                                                       \
//     if (!(cond))                                                            \
//     {                                                                       \
//         std::cerr << "test failed: " << RED << #cond << RESET << std::endl; \
//     }                                                                       \
//     else                                                                    \
//     {                                                                       \
//     }
// //  throw std::runtime_error("Requirement not met: " #cond); \


#define REQUIRE(cond) \
    if (!(cond))      \
        return std::string("Failed: " #cond " at " __FILE__ ":" + std::to_string(__LINE__));

// Napi::Value RunTest(const Napi::CallbackInfo& info, const std::string& testName, bool(*testFunc)(const Napi::CallbackInfo &info)) {
//     Napi::Env env = info.Env();
//     Napi::Function testFunction = info[0].As<Napi::Function>();
//
//     Napi::String testNameJS = Napi::String::New(env, testName);
//     Napi::Function testImpl = Napi::Function::New(env, [testFunc](const Napi::CallbackInfo& info) {
//         Napi::Env env = info.Env();
//         Napi::Object t = info[0].As<Napi::Object>();
//         bool result = testFunc(info);
//         Napi::Function trueMethod = t.Get("true").As<Napi::Function>();
//         trueMethod.Call(t, {Napi::Boolean::New(env, result)});
//     });
//
//     return testFunction.Call({testNameJS, testImpl});
// }

using NapiStringCallback = const std::function<std::string(const Napi::CallbackInfo &)>;

Napi::Value RunTest(const Napi::CallbackInfo &info, const std::string &testName, NapiStringCallback &testFunc)
{
    Napi::Env env = info.Env();
    Napi::Function testFunction = info[0].As<Napi::Function>();

    Napi::String testNameJS = Napi::String::New(env, testName);
    Napi::Function testImpl = Napi::Function::New(env, [testFunc](const Napi::CallbackInfo &info)
                                                  {
                                                      Napi::Env env = info.Env();
                                                      Napi::Object t = info[0].As<Napi::Object>();
                                                      std::string error = testFunc(info);
                                                      if (error.length() == 0)
                                                      {
                                                          Napi::Function trueMethod = t.Get("true").As<Napi::Function>();
                                                          trueMethod.Call(t, {Napi::Boolean::New(env, true)});
                                                      }
                                                      else
                                                      {
                                                          Napi::Function falseMethod = t.Get("true").As<Napi::Function>();
                                                          falseMethod.Call(t, {
                                                                                  Napi::Boolean::New(env, false),
                                                                                  Napi::String::New(env, error),
                                                                              });
                                                      }
                                                      // Napi::Function trueMethod = t.Get("true").As<Napi::Function>();
                                                      // trueMethod.Call(t, {Napi::Boolean::New(env, result)});
                                                  });

    return testFunction.Call({testNameJS, testImpl});
}

// , int& pass, int& fail
bool Js_BuildValue_test(const Napi::CallbackInfo &info)
{
    std::string PREFIX = std::string("Js_BuildValue > ");

    {
        NapiStringCallback lambda = [](const Napi::CallbackInfo &info)
        {
            Napi::Value value = Js_BuildValue(info, "i", 42);
            REQUIRE(value.IsNumber());
            REQUIRE(value.As<Napi::Number>().Int32Value() == 42);
            return std::string("");
        };
        RunTest(info, PREFIX + "Integer", lambda);
    }

    {
        NapiStringCallback lambda = [](const Napi::CallbackInfo &info)
        {
            Napi::Value value = Js_BuildValue(info, "f", 3.14);
            REQUIRE(value.IsNumber());
            REQUIRE(value.As<Napi::Number>().DoubleValue() == 3.14);
            return std::string("");
        };
        RunTest(info, PREFIX + "Floating-point", lambda);
    }
    {
        NapiStringCallback lambda = [](const Napi::CallbackInfo &info)
        {
            Napi::Value value = Js_BuildValue(info, "s", "hello");
            REQUIRE(value.IsString());
            REQUIRE(value.As<Napi::String>().Utf8Value() == "hello");
            return std::string("");
        };
        RunTest(info, PREFIX + "String", lambda);
    }

    {
        NapiStringCallback lambda = [](const Napi::CallbackInfo &info)
        {
            Napi::Value value = Js_BuildValue(info, "b", true);
            REQUIRE(value.IsBoolean());
            REQUIRE(value.As<Napi::Boolean>().Value() == true);
            return std::string("");
        };
        RunTest(info, PREFIX + "Boolean", lambda);
    }

    {
        NapiStringCallback lambda = [](const Napi::CallbackInfo &info)
        {
            Napi::Value value = Js_BuildValue(info, "(ifsb)", 1, 2.0, "three", false);
            REQUIRE(value.IsArray());
            Napi::Array array = value.As<Napi::Array>();
            REQUIRE(array.Length() == 4);
            REQUIRE(array.Get((uint32_t)0).As<Napi::Number>().Int32Value() == 1);
            REQUIRE(array.Get(1).As<Napi::Number>().DoubleValue() == 2.0);
            REQUIRE(array.Get(2).As<Napi::String>().Utf8Value() == "three");
            REQUIRE(array.Get(3).As<Napi::Boolean>().Value() == false);
            return std::string("");
        };
        RunTest(info, PREFIX + "Array", lambda);
    }

    {
        NapiStringCallback lambda = [](const Napi::CallbackInfo &info)
        {
            Napi::Value value1 = Napi::Value::From(info.Env(), 42);
            Napi::Value value2 = Napi::Value::From(info.Env(), 13);

            Napi::Value value = Js_BuildValue(info, "(NN)", value1, value2);
            REQUIRE(value.IsArray());
            Napi::Array array = value.As<Napi::Array>();
            REQUIRE(array.Length() == 2);
            REQUIRE(array.Get((uint32_t)0).IsNumber());
            REQUIRE(array.Get((uint32_t)0).As<Napi::Number>().Int32Value() == 42);
            REQUIRE(array.Get((uint32_t)1).IsNumber());
            REQUIRE(array.Get((uint32_t)1).As<Napi::Number>().Int32Value() == 13);
            return std::string("");
        };
        RunTest(info, PREFIX + "Array with N", lambda);
    }

    {
        NapiStringCallback lambda = [](const Napi::CallbackInfo &info)
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
            return std::string("");
        };
        RunTest(info, PREFIX + "Object", lambda);
    }

    return true;
}

bool JsArg_ParseTupleAndKeywords_test(const Napi::CallbackInfo &info)
{
    std::string PREFIX = std::string("JsArg_ParseTupleAndKeywords > ");
    {
        NapiStringCallback lambda = [](const Napi::CallbackInfo &info_)
        {
            Napi::Env env = info_.Env();
            FakeCallbackInfo info(info_, {Napi::Number::New(env, 42), Napi::String::New(env, "test")});
            const Napi::Value *a1 = NULL;
            const Napi::Value *a2 = NULL;
            const char *keywords[] = {"ext", "img", NULL};
            bool result = JsArg_ParseTupleAndKeywords(info, "OO", (char **)keywords, &a1, &a2);
            REQUIRE(result == true);
            REQUIRE(a1->As<Napi::Number>().Int32Value() == 42);
            REQUIRE(a2->As<Napi::String>().Utf8Value() == "test");
            return std::string("");
        };
        RunTest(info, PREFIX + "Basic test with required arguments", lambda);
    }
    {
        NapiStringCallback lambda = [](const Napi::CallbackInfo &info_)
        {
            Napi::Env env = info_.Env();
            FakeCallbackInfo info(info_, {Napi::Number::New(env, 42), Napi::String::New(env, "test")});
            const Napi::Value *a1 = NULL;
            const Napi::Value *a2 = NULL;
            const Napi::Value *a3 = NULL;
            const char *keywords[] = {"ext", "img", "opt", NULL};
            bool result = JsArg_ParseTupleAndKeywords(info, "OO|O", (char **)keywords, &a1, &a2, &a3);
            REQUIRE(result == true);
            REQUIRE(a1->As<Napi::Number>().Int32Value() == 42);
            REQUIRE(a2->As<Napi::String>().Utf8Value() == "test");
            REQUIRE(a3 == NULL);
            return std::string("");
        };
        RunTest(info, PREFIX + "Basic test with one optional arguments non provided", lambda);
    }
    {
        NapiStringCallback lambda = [](const Napi::CallbackInfo &info_)
        {
            Napi::Env env = info_.Env();
            FakeCallbackInfo info(info_, {Napi::Number::New(env, 42), Napi::String::New(env, "test"), Napi::Number::New(env, 13)});
            const Napi::Value *a1 = NULL;
            const Napi::Value *a2 = NULL;
            const Napi::Value *a3 = NULL;
            const char *keywords[] = {"ext", "img", "opt", NULL};
            bool result = JsArg_ParseTupleAndKeywords(info, "OO|O", (char **)keywords, &a1, &a2, &a3);
            REQUIRE(result == true);
            REQUIRE(a1 && a1->As<Napi::Number>().Int32Value() == 42);
            REQUIRE(a2 && a2->As<Napi::String>().Utf8Value() == "test");
            REQUIRE(a3 && a3->As<Napi::Number>().Int32Value() == 13);
            return std::string("");
        };
        RunTest(info, PREFIX + "Basic test with one optional arguments provided", lambda);
    }
    {
        NapiStringCallback lambda = [](const Napi::CallbackInfo &info_)
        {
            Napi::Env env = info_.Env();
            Napi::Object optional_obj = Napi::Object::New(env);
            optional_obj.Set("opt1", Napi::Number::New(env, 13));
            FakeCallbackInfo info(info_, {Napi::Number::New(env, 42), optional_obj});
            const Napi::Value *a1 = NULL;
            const Napi::Value *a2 = NULL;
            const char *keywords[] = {"ext", "opt1", NULL};
            bool result = JsArg_ParseTupleAndKeywords(info, "O|O", (char **)keywords, &a1, &a2);
            REQUIRE(result == true);
            REQUIRE(a1 && a1->As<Napi::Number>().Int32Value() == 42);
            REQUIRE(a2 && a2->As<Napi::Number>().Int32Value() == 13);
            return std::string("");
        };
        RunTest(info, PREFIX + "Basic test with one optional arguments provided in an object", lambda);
    }
 
    {
        NapiStringCallback lambda = [](const Napi::CallbackInfo &info_)
        {
            Napi::Env env = info_.Env();
            Napi::Object optional_obj = Napi::Object::New(env);
            optional_obj.Set("opt1", Napi::Boolean::New(env, true));
            optional_obj.Set("opt3", Napi::String::New(env, "value3"));
            FakeCallbackInfo info(info_, {optional_obj});
            const Napi::Value *a1 = NULL;
            const Napi::Value *a2 = NULL;
            const Napi::Value *a3 = NULL;
            const char *keywords[] = {"opt1", "opt2", "opt3", NULL};
            bool result = JsArg_ParseTupleAndKeywords(info, "|OOO", (char **)keywords, &a1, &a2, &a3);
            REQUIRE(result == true);
            REQUIRE(a1 != NULL);
            REQUIRE(a1->As<Napi::Boolean>().ToBoolean() == true);
            REQUIRE(a2 == NULL);
            REQUIRE(a3 != NULL);
            REQUIRE(a3->As<Napi::String>().Utf8Value() == "value3");
            return std::string("");
        };
        RunTest(info, PREFIX + "test with 3 optional arguments partialy provided", lambda);
    }

    // {
    //     auto lambda = [](const Napi::CallbackInfo &info_)
    //     {
    //         Napi::Env env = info_.Env();
    //         Napi::Value arg1_i42 = Napi::Number::New(env, 42);
    //         Napi::Value arg5_i13 = Napi::Number::New(env, 13);
    //         Napi::Value arg2_sTest = Napi::String::New(env, "test");
    //         Napi::Value arg3_bool = Napi::Boolean::New(env, true);
    //         Napi::Object optional_obj = Napi::Object::New(env);
    //         optional_obj.Set("opt1", arg5_i13);
    //         optional_obj.Set("opt2", Napi::String::New(env, "optional"));
    //         Napi::Value arg4 = optional_obj;
    //
    //
    //
    //         FakeCallbackInfo info(info_, {arg1_i42, arg2_sTest, arg3_bool, arg4});
    //         const Napi::Value *a1, *a2;
    //         const char *keywords[] = {"ext", "img", NULL};
    //         bool result = JsArg_ParseTupleAndKeywords(info, "OO", (char **)keywords, &a1, &a2);
    //         REQUIRE(result == true);
    //         REQUIRE(a1->As<Napi::Number>().Int32Value() == 42);
    //         REQUIRE(a2->As<Napi::String>().Utf8Value() == "test");
    //         return true;
    //     };
    //     RunTest(info, PREFIX + "Basic test with optional arguments", lambda);
    // }

    //     SECTION_START("Basic test with optional argumentss")
    //     {
    //         FakeCallbackInfo info(info_, {arg1_i42, arg2_sTest, arg5_i13, arg4});
    //         const Napi::Value *a1, *a2, *opt1, *opt2;
    //         const char *keywords[] = {"a1", "a2", "opt1", "opt2", nullptr};
    //         bool result = JsArg_ParseTupleAndKeywords(info, "OO|OO", (char **)keywords, &a1, &a2, &opt1, &opt2);
    //         REQUIRE(result == true);
    //         REQUIRE(a1->As<Napi::Number>().Int32Value() == 42);
    //         REQUIRE(a2->As<Napi::String>().Utf8Value() == "test");
    //         REQUIRE(opt1->As<Napi::Number>().Int32Value() == 13);
    //         REQUIRE(opt2->As<Napi::String>().Utf8Value() == "optional");
    //     }
    //     SECTION_END("Basic test with optional arguments")
    //
    //     SECTION_START("Test with optional arguments and optional object")
    //     {
    //         FakeCallbackInfo info(info_, {arg1_i42, arg2_sTest, arg3_bool, arg4});
    //         const Napi::Value *a1; // , *a2;// , *opt1, *opt2;
    //         const char *keywords[] = {"a1", "opt1", "opt2", nullptr};
    //         bool result = JsArg_ParseTupleAndKeywords(info, "O|OO", (char **)keywords, &a1, &optional_obj);
    //
    //         REQUIRE(result == true);
    //         REQUIRE(a1->As<Napi::Number>().Int32Value() == 42);
    //         // std::cout << NEW << opt1->IsNumber() << std::endl;
    //         // std::cout << NEW << "Value: " << opt1->As<Napi::Number>().Int32Value() << std::endl;
    //         // REQUIRE(opt1->As<Napi::Number>().Int32Value() == 42); // FIXME
    //         // REQUIRE(opt2->As<Napi::String>().Utf8Value() == "optional"); // FIX ME
    //     }
    //     SECTION_END("Test with optional arguments and optional object")
    //
    // SECTION_START("Test with invalid format string")
    //{
    //    FakeCallbackInfo info(info_, {arg1_i42, arg2_sTest, arg3_bool, arg4});
    //    const Napi::Value *a1, *a2, *opt1;
    //    const char *keywords[] = {"opt1", nullptr};
    //    bool result = JsArg_ParseTupleAndKeywords(info, "O||OO", (char **)keywords, &a1, &opt1, &a2);
    //    // The function should return false when the format string is invalid
    //    REQUIRE(result == false);
    //}
    // SECTION_END("Test with invalid format string")
    //
    // SECTION_START("Test with not enough required arguments provided")
    //{
    //    FakeCallbackInfo info(info_, {arg1_i42, arg2_sTest, arg3_bool, arg4});
    //    const Napi::Value *a1, *a2, *a3, *a4;
    //    const char *keywords[] = {nullptr};
    //    bool result = JsArg_ParseTupleAndKeywords(info, "OOOO", (char **)keywords, &a1, &a2, &a3, &a4);
    //    REQUIRE(result == false);
    //}
    // SECTION_END("Test with not enough required arguments provided")
    //
    // SECTION_START("Test with function name in format string")
    //{
    //    FakeCallbackInfo info(info_, {arg1_i42, arg2_sTest, arg3_bool, arg4});
    //    const Napi::Value *a1, *a2;
    //    const char *keywords[] = {nullptr};
    //    bool result = JsArg_ParseTupleAndKeywords(info, "OO:TestFunction", (char **)keywords, &a1, &a2);
    //    REQUIRE(result == true);
    //    REQUIRE(a1->As<Napi::Number>().Int32Value() == 42);
    //    REQUIRE(a2->As<Napi::String>().Utf8Value() == "test");
    //}
    // SECTION_END("Test with function name in format string")
    return true;
}
