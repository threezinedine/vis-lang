#pragma once
#include <datatypes/datatypes.hpp>

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
    };
} // namespace ntt
