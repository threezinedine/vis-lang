#pragma once
#include <datatypes/datatypes.hpp>
#include "log_message.hpp"

namespace ntt
{
    /**
     * Base interface for the log handler which will receive every
     *      the `LogMessage` object when the log is called. All the
     *      log handlers must inherit from this class. This class
     *      cannot be instantiated.
     */
    class LogHandler : public Object
    {
    public:
        /**
         * @param level The level of the log handler, this level will be used to
         *      filter out the log message based on the level.
         *
         * @param format The string which indicates how the log message should be
         *      formed. This string have some predefined keywords which will be
         *      replaced by the actual value. The predefined keywords are:
         *      - `@level` - The level of the log message (like INFO, DEBUG, etc.)
         *      - `@message` - The actual message which is passed to the log.
         *      - `@file` - The file name where the log is called.
         *      - `@line` - The line number where the log is called.
         *      - `@time` - The time when the log is called with the format
         *          `YYYY-MM-DD HH:MM:SS` (24-hour format).
         */
        LogHandler(LogLevel level, const String &format = "[@level] - @message");

        virtual ~LogHandler();

        /**
         * Method which will be used for each log message, it will filter
         *      out the message based on the configured level and only
         *      the message which is greater than or equal to the level
         *      will be passed to the `HandleImpl` method.
         *
         * @param message The log message which will be passed to the handler.
         *      This message will contain all the information about the log
         *      like the message, level, etc.
         */
        void Handle(const LogMessage &message);

    protected:
        /**
         * User defined method which will be called for each log message (if
         *      the level is matched). This method must be implemented by the
         *      derived class.
         *
         * @param message The log message which will be passed to the handler.
         *      This message will contain all the information about the log
         *      like the message, level, etc.
         *
         * @param formatted The string which is convereted by the format string
         *      which is passed to the constructor, this string will be used to
         *      display the log message.
         */
        virtual void HandleImpl(const LogMessage &message, const String &formatted) = 0;

    private:
        U8 m_level;
        String m_format;
    };
} // namespace ntt
