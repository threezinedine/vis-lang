#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <datatypes/array.hpp>
#include <datatypes/memory.hpp>

using namespace ntt;

class TestObject : public Object
{
public:
    String ToString() const override
    {
        return "TestObject";
    }
};

TEST(ArrayTest, TestArray)
{
    Array<U8> a({4, 4, 4});
    EXPECT_EQ(a.size(), 3);

    EXPECT_THAT(a.ToString(), testing::Eq("[4, 4, 4]"));

    EXPECT_THAT(a[0], testing::Eq(4));
    EXPECT_THAT(a[1], testing::Eq(4));
    EXPECT_THAT(a[2], testing::Eq(4));

    a[1] = 2;
    EXPECT_THAT(a[1], testing::Eq(2));
}

TEST(ArrayTest, Test_Array_Of_Unique_Ptr)
{
    Array<Scope<TestObject>> arr;
    arr.push_back(CreateScope<TestObject>());

    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr.ToString(), "[<Scope value=TestObject />]");

    Array<Scope<U8>> arr2;
    arr2.push_back(CreateScope<U8>(3));
    arr2.push_back(CreateScope<U8>(4));

    EXPECT_EQ(arr2.size(), 2);
    EXPECT_EQ(*arr2[0], 3);

    EXPECT_EQ(arr2.ToString(),
              "[<Scope value=3 />, <Scope value=4 />]");
}