#pragma once
#include "log_handler.hpp"
#include "log_message.hpp"
#include <datatypes/datatypes.hpp>

namespace ntt
{
    /**
     * Configure and initialize the system with the certain
     *      global configuration. The Log system will be
     *      unique and will be used by the whole system.
     *
     * This function must be called at the start of the system (
     *      before any log is called) to configure the log system.
     *
     * @param handlers The list of log handlers which will be used
     *      to handle the log message when the log is called. Each
     *      handler will have its own configuration.
     */
    void LogInit(Array<Ref<LogHandler>> handlers);

    /**
     * The main method of the log system, user will call this method
     *      for creating the record for all the handlers.
     *
     * @param level The level of the log message.
     * @param fileName The file name where the log is called.
     * @param line The line number where the log is called.
     * @param message The message which the user wants to log.
     *
     * @note Should not this method directly, use the `NTT_LOG_*` macro
     *      instead.
     */
    void Log(LogLevel level, const String &fileName, U32 line, const String &message);

    /**
     * Destroy and release all needed resources for the log system.
     * This method must be called at the end of the system (after
     *      all the log is called) to release the log system.
     */
    void LogShutdown();
} // namespace ntt

#include "console_handler.hpp"

/**
 * Used for logging the message at functional level. The level `NTT_LOG_LEVEL_TRACE`
 *      will be used for the trace message.
 *
 * @example
 * ```cpp
 * NTT_LOG_TRACE("This is a trace message: {}", 10.3);
 * ```
 */
#define NTT_LOG_TRACE(...) \
    ::ntt::Log(NTT_LOG_LEVEL_TRACE, __FILE__, __LINE__, ::ntt::Format(__VA_ARGS__))

/**
 * Used for logging the message at functional level. The level `NTT_LOG_LEVEL_DEBUG`
 *      will be used for the debug message.
 *
 * @example
 * ```cpp
 * NTT_LOG_DEBUG("This is a debug message: {}", 10.3);
 * ```
 */
#define NTT_LOG_DEBUG(...) \
    ::ntt::Log(NTT_LOG_LEVEL_DEBUG, __FILE__, __LINE__, ::ntt::Format(__VA_ARGS__))

/**
 * Used for logging the message at functional level. The level `NTT_LOG_LEVEL_INFO`
 *      will be used for the info message.
 *
 * @example
 * ```cpp
 * NTT_LOG_INFO("This is an info message: {}", 10.3);
 * ```
 */
#define NTT_LOG_INFO(...) \
    ::ntt::Log(NTT_LOG_LEVEL_INFO, __FILE__, __LINE__, ::ntt::Format(__VA_ARGS__))

/**
 * Used for logging the message at functional level. The level `NTT_LOG_LEVEL_WARN`
 *      will be used for the warn message.
 *
 * @example
 * ```cpp
 * NTT_LOG_WARN("This is a warn message: {}", 10.3);
 * ```
 */
#define NTT_LOG_WARN(...) \
    ::ntt::Log(NTT_LOG_LEVEL_WARN, __FILE__, __LINE__, ::ntt::Format(__VA_ARGS__))

/**
 * Used for logging the message at functional level. The level `NTT_LOG_LEVEL_ERROR`
 *     will be used for the error message.
 *
 * @example
 * ```cpp
 * NTT_LOG_ERROR("This is an error message: {}", 10.3);
 * ```
 */
#define NTT_LOG_ERROR(...) \
    ::ntt::Log(NTT_LOG_LEVEL_ERROR, __FILE__, __LINE__, ::ntt::Format(__VA_ARGS__))

/**
 * Used for logging the message at functional level. The level `NTT_LOG_LEVEL_FATAL`
 *     will be used for the fatal message.
 *
 * @example
 * ```cpp
 * NTT_LOG_FATAL("This is a fatal message: {}", 10.3);
 * ```
 */
#define NTT_LOG_FATAL(...) \
    ::ntt::Log(NTT_LOG_LEVEL_FATAL, __FILE__, __LINE__, ::ntt::Format(__VA_ARGS__))
