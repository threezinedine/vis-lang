#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../path.hpp"

using namespace ntt;

TEST(TestPath, WithRelativeString)
{
    Path path("../main.cpp");
    EXPECT_EQ(path.GetFileName(), "main.cpp");
}

TEST(TestPath, WithAbsoluteString)
{
    Path path(__FILE__);
    EXPECT_EQ(path.GetFileName(), "test_path.cpp");
}

TEST(TestPath, WithRelativeStringWithoutExtension)
{
    Path path("../main.cpp");
    EXPECT_EQ(path.GetFileName(False), "main");
}

TEST(TestPath, TestExisted)
{
    Path path("../docs");
    EXPECT_TRUE(path.Exists());
}

TEST(TestPath, TestNotExisted)
{
    Path path("../doc");
    EXPECT_FALSE(path.Exists());
}

TEST(TestPath, IsDirectoryTest)
{
    Path path("../docs");
    EXPECT_TRUE(path.IsDirectory());
}

TEST(TestPath, TestPath_IsNotDirectory_Test)
{
    Path path("../docs/Doxyfile");
    EXPECT_FALSE(path.IsDirectory());
}

TEST(TestPath, CheckIsDirectoryOfNonExistedFile)
{
    Path path("../doc");
    EXPECT_THROW(path.IsDirectory(), std::runtime_error);
}