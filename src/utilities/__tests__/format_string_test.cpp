#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <utilities/format_string.hpp>

using namespace ntt;

TEST(FormatStringTest, FormatStringWithIntData)
{
    EXPECT_THAT(Format("Hello, {}!", 10), testing::Eq("Hello, 10!"));
}