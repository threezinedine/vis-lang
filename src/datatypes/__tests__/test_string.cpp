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

TEST(StringTest, Test_Add_Operator)
{
    EXPECT_THAT(String("Hello, ") + String("World!"), testing::Eq("Hello, World!"));
    EXPECT_THAT(String("Hello, ") + "World!", testing::Eq("Hello, World!"));

    String str = "Hello, ";
    str += "World!";
    EXPECT_THAT(str, testing::Eq("Hello, World!"));

    str = "Hello, ";
    String newStr = str + "World!";
    EXPECT_THAT(newStr, testing::Eq("Hello, World!"));
}

TEST(StringTest, TestFillWith)
{
    EXPECT_EQ(String("Test").FillWith(2, " "), "Test");
    EXPECT_EQ(String("Test").FillWith(6, " "), "  Test");
    EXPECT_EQ(String("Test").FillWith(6, " ", False), "Test  ");
}

TEST(StringTest, TestSubString)
{
    EXPECT_EQ(String("Hello, World!").SubString(0, 5), "Hello");
    EXPECT_EQ(String("Hello, World!").SubString(7, 5), "World");
    EXPECT_EQ(String("Hello, World!").SubString(7, 10), "World!");
    EXPECT_EQ(String("Hello, World!").SubString(7, 100), "World!");
    EXPECT_EQ(String("Hello, World!").SubString(30, 100), "");
    EXPECT_EQ(String("Hello, World!").SubString(1, 0), "");
}