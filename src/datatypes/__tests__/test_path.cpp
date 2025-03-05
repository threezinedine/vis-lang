#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <fstream>

#include "../path.hpp"

using namespace ntt;

class TestPath : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // Create a test file
        std::ofstream file(testFile);
        file.close();

        // create test directory
        fs::create_directory("./test_dir_only");
    }

    void TearDown() override
    {
        fs::remove(testFile);

        fs::remove("./test_dir_only");
    }

    fs::path testFile = "./main.tst";
};

TEST_F(TestPath, WithRelativeString)
{
    Path path("./main.tst");
    EXPECT_EQ(path.GetFileName(), "main.tst");
}

TEST_F(TestPath, WithAbsoluteString)
{
    Path path(__FILE__);
    EXPECT_EQ(path.GetFileName(), "test_path.cpp");
}

TEST_F(TestPath, WithRelativeStringWithoutExtension)
{
    Path path("./main.tst");
    EXPECT_EQ(path.GetFileName(False), "main");
}

TEST_F(TestPath, TestExisted)
{
    Path path("./test_dir_only");
    EXPECT_TRUE(path.Exists());
}

TEST_F(TestPath, TestNotExisted)
{
    Path path("./test_dir_only_not_existed");
    EXPECT_FALSE(path.Exists());
}

TEST_F(TestPath, IsDirectoryTest)
{
    Path path("./test_dir_only");
    EXPECT_TRUE(path.IsDirectory());
}

TEST_F(TestPath, TestPath_IsNotDirectory_Test)
{
    Path path("./main.tst");
    EXPECT_FALSE(path.IsDirectory());
}

TEST_F(TestPath, CheckIsDirectoryOfNonExistedFile)
{
    Path path("./test_dir_only_not_existed");
    EXPECT_THROW(path.IsDirectory(), std::runtime_error);
}

TEST_F(TestPath, SimplePathOperations)
{
    Path path("./main_test.tst");
    Path path2("main_test.tst");

    path.Open(True);
    path2.Open(True);

    if (path.IsOpened())
    {
        path.Write("Hello, World!", False);
    }

    EXPECT_EQ(path2.IsOpened(), True);
    EXPECT_EQ(path2.Read(), "Hello, World!");

    path2.Close();
    path.Close();
}