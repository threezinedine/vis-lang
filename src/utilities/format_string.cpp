#include "format_string.hpp"
#include <string>
#include <sstream>
#include <iomanip>

namespace ntt
{
    String ToString(const U8 &value)
    {
        return String(std::to_string(value).c_str());
    }

    String ToString(const U16 &value)
    {
        return String(std::to_string(value).c_str());
    }

    String ToString(const U32 &value)
    {
        return String(std::to_string(value).c_str());
    }

    String ToString(const U64 &value)
    {
        return String(std::to_string(value).c_str());
    }

    String ToString(const I8 &value)
    {
        return String(std::to_string(value).c_str());
    }

    String ToString(const I16 &value)
    {
        return String(std::to_string(value).c_str());
    }

    String ToString(const I32 &value)
    {
        return String(std::to_string(value).c_str());
    }

    String ToString(const I64 &value)
    {
        return String(std::to_string(value).c_str());
    }

    String ToString(const F32 &value)
    {
        std::ostringstream ss;
        ss << std::fixed << std::setprecision(2) << value;
        return String(ss.str().c_str());
    }

    String ToString(const F64 &value)
    {
        std::ostringstream ss;
        ss << std::fixed << std::setprecision(2) << value;
        return String(ss.str().c_str());
    }

    String ToString(const B8 &value)
    {
        return value ? "true" : "false";
    }

    String ToString(const Object &value)
    {
        return value.ToString();
    }

    String Format(const String &format_str, const String &arg)
    {
        return format_str.Replace(FORMAT_SIGN, arg);
    }
} // namespace ntt
