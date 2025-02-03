#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <datatypes/string.hpp>

using namespace ntt;

TEST(StringTest, Check_String_Equality)
{
    EXPECT_EQ(String("Hello, World!"), String("Hello, World!"));
    EXPECT_THAT(String("Hello, World!"), testing::Eq(String("Hello, World!")));
    EXPECT_EQ(String("Hello, World!"), "Hello, World!");
    EXPECT_THAT(String("Hello, World!"), testing::Not("Hello, World"));
}

TEST(StringTest, Test_Replace_String_Portion)
{
    EXPECT_THAT(String("Hello, World!").Replace("World", "Universe"), testing::Eq("Hello, Universe!"));
    EXPECT_THAT(String("Hello, World!").Replace("World", ""), testing::Eq("Hello, !"));
    EXPECT_THAT(String("Hello, World!").Replace("", "Universe"), testing::Eq("Hello, World!"));
    EXPECT_THAT(String("Hello, World!")
                    .Replace("World", "Universe")
                    .Replace("Hello", "Hi"),
                testing::Eq("Hi, Universe!"));
    EXPECT_THAT(String("Hello, World!")
                    .Replace("Word", "Universe"),
                testing::Eq("Hello, World!"));

    EXPECT_THAT(String("Hello, World! World!")
                    .Replace("World", "Universe"),
                testing::Eq("Hello, Universe! World!"));
}

TEST(StringTest, Test_Replace_All_Occurrences)
{
    EXPECT_THAT(String("Hello, World! World!")
                    .Replace("World", "Universe", True),
                testing::Eq("Hello, Universe! Universe!"));
}