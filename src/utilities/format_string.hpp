#pragma once
#include <datatypes/string.hpp>
#include <datatypes/common.hpp>
#include <datatypes/object.hpp>
#include <constants.hpp>

namespace ntt
{
    // Configuration for the ToString functionalities of
    //     the primitive datatypes and Object based.

    String ToString(const U8 &value);
    String ToString(const U16 &value);
    String ToString(const U32 &value);
    String ToString(const U64 &value);
    String ToString(const I8 &value);
    String ToString(const I16 &value);
    String ToString(const I32 &value);
    String ToString(const I64 &value);
    String ToString(const F32 &value);
    String ToString(const F64 &value);
    String ToString(const B8 &value);
    String ToString(const Object &value);

    /**
     * Formats the given string with the given list of arguments.
     *
     * @example
     * ```cpp
     * Print(Format("Hello, {}!", 10)); // Output: "Hello, 10!"" to the console
     *
     * Print(Format("Hello, {}! I'm {} years old.", 10, 20.3));
     * // Output: "Hello, 10! I'm 20.3 years old." to the console
     * ```
     */

    template <typename T, typename... Args>
    String Format(const String &format_str, T arg, Args... args)
    {
        String step = format_str.Replace(FORMAT_SIGN, ToString(arg));
        return Format(step, args...);
    }

    template <typename T>
    String Format(const String &format_str, T arg)
    {
        return format_str.Replace(FORMAT_SIGN, ToString(arg));
    }

    String Format(const String &format_str, const String &arg);
}