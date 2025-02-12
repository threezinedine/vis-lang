#include "string.hpp"
#include <cstring>
#include <datatypes/common.hpp>
#include <string>

namespace ntt
{
    String::String()
        : std::string("")
    {
    }

    String::String(const char *msg)
        : std::string(msg)
    {
    }

    String::String(const std::string &msg)
        : std::string(msg)
    {
    }

    String::String(const String &other)
        : std::string(other)
    {
    }

    String::~String()
    {
    }

    String String::Replace(const String &old_str, const String &new_str, B8 all) const
    {
        if (old_str == "")
        {
            return *this;
        }

        // TODO: Try to use raw char array instead of std::string later
        std::string replaced_str = "";

        size_t pos = 0;
        U32 index = 0;
        while ((pos = this->find(old_str, pos)) != std::string::npos)
        {
            replaced_str += this->substr(index, pos - index);
            replaced_str += new_str;
            pos += old_str.length();
            index = pos;

            if (!all)
            {
                break;
            }
        }

        if (index == 0)
        {
            return *this;
        }

        replaced_str += this->substr(index, this->length() - index);

        return String(replaced_str.c_str());
    }

    String String::FillWith(U32 length, const String &fill_str, B8 atStart, B8 exact) const
    {
        if (fill_str == "")
        {
            return *this;
        }

        if (this->length() >= length)
        {
            return *this;
        }

        String result = *this;
        if (atStart)
        {
            while (result.length() < length)
            {
                result = fill_str + result;
            }
        }
        else
        {
            while (result.length() < length)
            {
                result += fill_str;
            }
        }

        if (exact)
        {
            result = result.SubString(0, length);
        }

        return result;
    }

    String String::SubString(U32 start, U32 length) const
    {
        if (start >= this->length())
        {
            return "";
        }

        if (start + length > this->length())
        {
            length = this->length() - start;
        }

        std::string buffer;
        buffer.resize(length);
        std::memcpy(&buffer[0], &(*this)[start], length);
        return String(buffer.c_str());
    }
} // namespace ntt