#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../log.hpp"

using namespace ntt;

static Array<LogMessage> s_messages;
static Array<String> s_formatteds;

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

protected:
    void HandleImpl(const LogMessage &message, const String &formatted) override
    {
        s_messages.push_back(message);
        s_formatteds.push_back(formatted);
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

    Log(NTT_LOG_LEVEL_INFO, __FILE__, 10, "Hello, World!");

    ASSERT_EQ(s_messages.size(), 1);
    auto message = s_messages[0];
    ASSERT_EQ(message.level, NTT_LOG_LEVEL_INFO);
    EXPECT_EQ(s_formatteds[0], "[INFO] - Hello, World!");
}

TEST_F(TestLogHandler, DonotHandleMessageWithLowerLogLevel)
{
    LogInit({
        static_cast<Ref<LogHandler>>(CreateRef<TestHandler>(NTT_LOG_LEVEL_INFO)),
    });

    Log(NTT_LOG_LEVEL_DEBUG, __FILE__, 10, "Hello, World!");

    ASSERT_EQ(s_messages.size(), 0);
}