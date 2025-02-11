#include "log.hpp"

namespace ntt
{
    namespace
    {
        Array<Ref<LogHandler>> s_handlers;
    } // namespace anonymous

    void LogInit(Array<Ref<LogHandler>> handlers)
    {
        s_handlers = std::move(handlers);
    }

    void Log(LogLevel level, const String &fileName, U32 line, const String &message)
    {
        for (auto &handler : s_handlers)
        {
            handler->Handle(LogMessage{level, fileName, line, message});
        }
    }

    void LogShutdown()
    {
    }
} // namespace ntt
