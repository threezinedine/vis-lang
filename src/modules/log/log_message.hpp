#pragma once
#include <datatypes/datatypes.hpp>

namespace ntt
{
    /**
     * The object which consists whole needed information of an record
     *      which the user wants to log. This object will be passed to
     *      every `LogHandler` object when the log is called.
     */
    struct LogMessage : public Object
    {
        String fileName; ///< The file name where the log is called.
        U32 lineNumber;  ///< The line number where the log is called.
        String message;  ///< The message which the user wants to log.

        String ToString() const override
        {
            return "<LogMessage />";
        }
    };
} // namespace ntt
