#include "log_handler.hpp"

namespace ntt
{
    LogHandler::LogHandler(LogLevel level) : m_level(level)
    {
    }

    LogHandler::~LogHandler()
    {
    }

    void LogHandler::Handle(const LogMessage &message)
    {
        if (message.level >= m_level)
        {
            HandleImpl(message);
        }
    }
} // namespace ntt
