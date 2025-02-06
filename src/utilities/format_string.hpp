#pragma once
#include <datatypes/string.hpp>
#include <datatypes/common.hpp>
#include <datatypes/object.hpp>
#include <constants.hpp>

namespace ntt
{
    // Configuration for the ToString functionalities of
    //     the primitive datatypes and Object based.

    String ConvertToString(const U8 &value);
    String ConvertToString(const U16 &value);
    String ConvertToString(const U32 &value);
    String ConvertToString(const U64 &value);
    String ConvertToString(const I8 &value);
    String ConvertToString(const I16 &value);
    String ConvertToString(const I32 &value);
    String ConvertToString(const I64 &value);
    String ConvertToString(const F32 &value);
    String ConvertToString(const F64 &value);
    String ConvertToString(const B8 &value);
    String ConvertToString(const Object &value);
    String ConvertToString(const std::nullptr_t &value);
    String ConvertToString(const String &value);

    /**
     * Formats the given string with the given list of arguments.
     * If there are more arguments than the placeholders in the string,
     *      the extra arguments will be ignored.
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
    String Format(const String &format_str, const T &arg, Args... args)
    {
        String step = format_str.Replace(FORMAT_SIGN, ConvertToString(arg));
        return Format(step, args...);
    }

    template <typename T>
    String Format(const String &format_str, const T &arg)
    {
        return format_str.Replace(FORMAT_SIGN, ConvertToString(arg));
    }

    String Format(const String &format_str);
}