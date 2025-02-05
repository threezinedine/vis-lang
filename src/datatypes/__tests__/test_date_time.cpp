#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <chrono>

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

TEST(DateTimeTest, Test_AutoFillWithZeros)
{
    DateTime dt(2021, 1, 1, 1, 1, 1); // 2021-01-01 01:01:01

    EXPECT_EQ(dt.WithFormat("Time: %H:%M:%S, Date: %Y-%m-%d"),
              "Time: 01:01:01, Date: 2021-01-01");
}

TEST(DateTimeTest, Test_Now)
{
    DateTime dt = DateTime::Now();

    // Get current date
    auto now = std::chrono::system_clock::now();
    auto now_time = std::chrono::system_clock::to_time_t(now);

    struct tm *time_info;
    time_info = std::localtime(&now_time);

    EXPECT_EQ(dt.GetYear(), time_info->tm_year + 1900);
    EXPECT_EQ(dt.GetMonth(), time_info->tm_mon + 1);
    EXPECT_EQ(dt.GetDay(), time_info->tm_mday);
}