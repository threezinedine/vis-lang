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