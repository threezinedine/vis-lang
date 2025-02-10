#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../event_system.hpp"

using namespace ntt;

class TestEventSystem : public ::testing::Test
{
protected:
};

TEST_F(TestEventSystem, TestPassed)
{
    ASSERT_TRUE(true);
}