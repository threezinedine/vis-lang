#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../log.hpp"

using namespace ntt;

static Array<LogMessage> s_messages;

///////////////////// TestHandler Define //////////////////////
/**
 * Only used for testing purposes.
 */
class TestHandler : public LogHandler
{
public:
    TestHandler(U8 level) : LogHandler(level)
    {
    }

    ~TestHandler() override
    {
    }

    static Array<LogMessage> messages;

protected:
    void HandleImpl(const LogMessage &message) override
    {
        s_messages.push_back(message);
    }
};

///////////////////// TestHandler Define //////////////////////

class TestLogHandler : public ::testing::Test
{
protected:
    void SetUp() override
    {
        s_messages.clear();
    }

    void TearDown() override
    {
        LogShutdown();
    }
};

TEST_F(TestLogHandler, ConfigureLogHandle)
{
    LogInit({
        static_cast<Ref<LogHandler>>(CreateRef<TestHandler>(NTT_LOG_LEVEL_INFO)),
    });

    Log(NTT_LOG_LEVEL_INFO, "Testfile.cpp", 10, "Hello, World!");

    ASSERT_EQ(s_messages.size(), 1);
    auto message = s_messages[0];
}

TEST_F(TestLogHandler, DonotHandleMessageWithLowerLogLevel)
{
    LogInit({
        static_cast<Ref<LogHandler>>(CreateRef<TestHandler>(NTT_LOG_LEVEL_INFO)),
    });

    Log(NTT_LOG_LEVEL_DEBUG, "Testfile.cpp", 10, "Hello, World!");

    ASSERT_EQ(s_messages.size(), 0);
}