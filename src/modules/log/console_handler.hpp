#pragma once
#include "log_handler.hpp"

namespace ntt
{
    /**
     * Used for printing the log message into the console/terminal/command line, etc.
     * This handler can be used in both development and production environment.
     */
    class ConsoleHandler : public LogHandler
    {
    public:
        ConsoleHandler(LogLevel level, const String &format = "[@level] - @message");
        ~ConsoleHandler() override;

    protected:
        /**
         * Display the log message into the console/terminal/command line, etc.
         */
        virtual void HandleImpl(const LogMessage &message, const String &formatted) override;
    };
} // namespace ntt
