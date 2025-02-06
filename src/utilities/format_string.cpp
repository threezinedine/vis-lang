#include "format_string.hpp"
#include <string>
#include <sstream>
#include <iomanip>

namespace ntt
{
    String ConvertToString(const U8 &value)
    {
        return String(std::to_string(value).c_str());
    }

    String ConvertToString(const U16 &value)
    {
        return String(std::to_string(value).c_str());
    }

    String ConvertToString(const U32 &value)
    {
        return String(std::to_string(value).c_str());
    }

    String ConvertToString(const U64 &value)
    {
        return String(std::to_string(value).c_str());
    }

    String ConvertToString(const I8 &value)
    {
        return String(std::to_string(value).c_str());
    }

    String ConvertToString(const I16 &value)
    {
        return String(std::to_string(value).c_str());
    }

    String ConvertToString(const I32 &value)
    {
        return String(std::to_string(value).c_str());
    }

    String ConvertToString(const I64 &value)
    {
        return String(std::to_string(value).c_str());
    }

    String ConvertToString(const F32 &value)
    {
        std::ostringstream ss;
        ss << std::fixed << std::setprecision(2) << value;
        return String(ss.str().c_str());
    }

    String ConvertToString(const F64 &value)
    {
        std::ostringstream ss;
        ss << std::fixed << std::setprecision(2) << value;
        return String(ss.str().c_str());
    }

    String ConvertToString(const B8 &value)
    {
        return value ? "true" : "false";
    }

    String ConvertToString(const Object &value)
    {
        return value.ToString();
    }

    String ConvertToString(const std::nullptr_t &value)
    {
        return "null";
    }

    String ConvertToString(const String &value)
    {
        return value;
    }

    String Format(const String &format_str)
    {
        return format_str;
    }
} // namespace ntt
