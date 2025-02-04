#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <utilities/format_string.hpp>

using namespace ntt;

TEST(FormatStringTest, FormatStringWithIntData)
{
    EXPECT_THAT(Format("Hello, {}!", 10), testing::Eq("Hello, 10!"));
    EXPECT_THAT(Format("Hello, {}! I'm {} years old.", 10, 20.3),
                testing::Eq("Hello, 10! I'm 20.30 years old."));

    EXPECT_THAT(Format("Hello, {}!", nullptr),
                testing::Eq("Hello, null!"));

    EXPECT_THAT(Format("Hello, {}!", 10, 20.3),
                testing::Eq("Hello, 10!"));

    EXPECT_THAT(Format("Hello, {}! I'm {} years old.", 10),
                testing::Eq("Hello, 10! I'm {} years old."));

    EXPECT_THAT(Format("Hello, {}!", True),
                testing::Eq("Hello, true!"));

    EXPECT_THAT(Format("Hello, {}!", False),
                testing::Eq("Hello, false!"));
}