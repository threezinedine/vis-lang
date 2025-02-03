#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <datatypes/array.hpp>

using namespace ntt;

TEST(ArrayTest, TestArray)
{
    Array<U8> a(3, 4);
    EXPECT_EQ(a.Count(), 3);

    EXPECT_THAT(a.ToString(), testing::Eq("[4, 4, 4]"));
}