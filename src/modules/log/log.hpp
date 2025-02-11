#pragma once
#include "LogHandler.hpp"
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
