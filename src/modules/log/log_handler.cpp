#include "log_handler.hpp"

namespace ntt
{
    namespace
    {
        String LogLevelToString(LogLevel level)
        {
            switch (level)
            {
            case NTT_LOG_LEVEL_TRACE:
                return "TRACE";
            case NTT_LOG_LEVEL_DEBUG:
                return "DEBUG";
            case NTT_LOG_LEVEL_INFO:
                return "INFO";
            case NTT_LOG_LEVEL_WARN:
                return "WARN";
            case NTT_LOG_LEVEL_ERROR:
                return "ERROR";
            case NTT_LOG_LEVEL_FATAL:
                return "FATAL";
            default:
                return "UNKNOWN";
            }
        }
    } // namespace anonymous

    LogHandler::LogHandler(LogLevel level, const String &format)
        : m_level(level), m_format(format)
    {
    }

    LogHandler::~LogHandler()
    {
    }

    void LogHandler::Handle(const LogMessage &message)
    {
        String formatted = m_format;
        formatted = formatted.Replace("@level", LogLevelToString(message.level));
        formatted = formatted.Replace("@message", message.message);
        formatted = formatted.Replace("@file", message.fileName.GetFileName());
        formatted = formatted.Replace("@line", ConvertToString(message.lineNumber));
        formatted = formatted.Replace("@time", message.time.WithFormat("%Y-%m-%d %H:%M:%S"));

        if (message.level >= m_level)
        {
            HandleImpl(message, formatted);
        }
    }
} // namespace ntt
