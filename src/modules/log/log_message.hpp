#pragma once
#include <datatypes/datatypes.hpp>

/**
 * Used for detailed information like
 *      function call and return, etc.
 */
#define NTT_LOG_LEVEL_TRACE (1 << 0)

/**
 * Used for debugging purposes like
 *      debug messages and debug information.
 */
#define NTT_LOG_LEVEL_DEBUG (1 << 1)

/**
 * Used for some critical information like
 *      application start, stop, etc.
 */
#define NTT_LOG_LEVEL_INFO (1 << 2)

/**
 * Used for some error which will not affact the
 *      system but need to be logged.
 */
#define NTT_LOG_LEVEL_WARN (1 << 3)

/**
 * Used for some critical error which will affact
 *      the system and need to be logged.
 */
#define NTT_LOG_LEVEL_ERROR (1 << 4)

/**
 * Used for some bugs which will crash the system
 *      like memory leak, etc.
 */
#define NTT_LOG_LEVEL_FATAL (1 << 5)

namespace ntt
{
    /**
     * Register the type which is alias for using inside the log system.
     */
    typedef U8 LogLevel;

    /**
     * The object which consists whole needed information of an record
     *      which the user wants to log. This object will be passed to
     *      every `LogHandler` object when the log is called.
     */
    struct LogMessage : public Object
    {
        LogLevel level;  ///< The level of the log message.
        String fileName; ///< The file name where the log is called.
        U32 lineNumber;  ///< The line number where the log is called.
        String message;  ///< The message which the user wants to log.

        LogMessage(LogLevel level, const String &fileName, U32 lineNumber, const String &message)
            : level(level), fileName(fileName), lineNumber(lineNumber), message(message)
        {
        }

        String ToString() const override
        {
            return "<LogMessage />";
        }
    };
} // namespace ntt
