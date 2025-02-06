#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../string.hpp"
#include "../json.hpp"

using namespace ntt;

class JsonTest : public testing::Test
{
protected:
    void SetUp() override
    {
        json_str = R"(
        {
            "int": 300,
            "float": 123.456,
            "bool": true,
            "string": "hello world",
            "array": [1, 2, 3, 4, 5],
            "object": {
                "key1": "value1",
                "key2": "value2",
                "key3": "value3"
            }
        })";

        json = Json(json_str);
    }

    Json json;

private:
    String json_str;
};

TEST_F(JsonTest, Test_ToString)
{
    Json json("{\"hello\": \"world\"}");
    EXPECT_THAT(json.ToString(), testing::Eq("{\n    \"hello\": \"world\"\n}"));
}

TEST_F(JsonTest, Test_Get)
{
    EXPECT_EQ(json.GetU32("int", 9), 300);
    EXPECT_EQ(json.GetU32("int-non-exist", 9), 9);
    EXPECT_EQ(json.GetU32("float", 9), 123);

    EXPECT_EQ(json.GetU16("int", 9.0), 300);
    EXPECT_EQ(json.GetU8("int", 9.0), 44);

    EXPECT_THAT(json.GetF32("float", 9.0), testing::FloatEq(123.456));
    EXPECT_THAT(json.GetF32("float-non-exist", 9.0), testing::FloatEq(9.0));
    EXPECT_THAT(json.GetF32("int", 9.0), testing::FloatEq(300.0));

    EXPECT_THAT(json.GetF64("float", 9.0), testing::DoubleEq(123.456));

    EXPECT_EQ(json.GetB8("bool", False), True);
    EXPECT_EQ(json.GetB8("bool-non-exist", False), False);

    EXPECT_EQ(json.GetString("string", "default"), "hello world");
    EXPECT_EQ(json.GetString("string-non-exist", "default"), "default");
}

TEST_F(JsonTest, Test_GetWithInvalidType)
{
    EXPECT_EQ(json.GetString("float", "default"), "default");
    EXPECT_EQ(json.GetU32("string", 9), 9);
    EXPECT_EQ(json.GetB8("int", False), True);
}