#include "console_handler.hpp"
#include "platforms/platforms.hpp"

namespace ntt
{
    ConsoleHandler::ConsoleHandler(LogLevel level)
        : LogHandler(level)
    {
    }

    ConsoleHandler::~ConsoleHandler()
    {
    }

    void ConsoleHandler::HandleImpl(const LogMessage &message)
    {
        auto finalMessage = Format("{} - {}:{} - {}",
                                   message.time.ToString(),
                                   message.fileName,
                                   message.lineNumber,
                                   message.message);

        DefaultColor color;
        switch (message.level)
        {
        case NTT_LOG_LEVEL_TRACE:
            color = DefaultColor::WHITE;
            break;
        case NTT_LOG_LEVEL_DEBUG:
            color = DefaultColor::CYAN;
            break;
        case NTT_LOG_LEVEL_INFO:
            color = DefaultColor::GREEN;
            break;
        case NTT_LOG_LEVEL_WARN:
            color = DefaultColor::YELLOW;
            break;
        case NTT_LOG_LEVEL_ERROR:
            color = DefaultColor::RED;
            break;
        case NTT_LOG_LEVEL_FATAL:
            color = DefaultColor::MAGENTA;
            break;
        default:
            color = DefaultColor::WHITE;
            break;
        }

        Print(finalMessage, color);
    }
}