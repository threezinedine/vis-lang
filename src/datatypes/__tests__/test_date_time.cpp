#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../date_time.hpp"

using namespace ntt;

TEST(DateTimeTest, Test_InitializeData)
{
    DateTime dt(2021, 10, 10, 10, 10, 10); // 2021-10-10 10:10:10
    EXPECT_EQ(dt.ToString(), "<DateTime 2021-10-10 10:10:10 />");
}

TEST(DateTimeTest, Test_FormatDate)
{
    DateTime dt(2021, 10, 10, 10, 10, 10); // 2021-10-10 10:10:10
    EXPECT_EQ(dt.WithFormat("Time: %H:%M:%S, Date: %Y-%m-%d"),
              "Time: 10:10:10, Date: 2021-10-10");

    EXPECT_EQ(dt.WithFormat("Time: %H:%M:%S, Date: %Y-%m-%d %H:%M:%S"),
              "Time: 10:10:10, Date: 2021-10-10 10:10:10");

    EXPECT_EQ(dt.WithFormat("%C %Y"),
              "Oct 2021");
}