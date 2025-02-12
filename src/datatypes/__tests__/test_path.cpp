#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../path.hpp"

using namespace ntt;

TEST(TestPath, WithEmptyConstructor)
{
    Path path;
    EXPECT_EQ(path.GetFileName(), "test_path.cpp");
}