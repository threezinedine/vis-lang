#include "string.hpp"
#include <cstring>
#include <datatypes/common.hpp>
#include <string>

namespace ntt
{
    String::String(const char *msg)
    {
        m_msg = new char[strlen(msg) + 1];
        strcpy(m_msg, msg);
    }

    String::String(const String &other)
    {
        m_msg = new char[strlen(other.m_msg) + 1];
        strcpy(m_msg, other.m_msg);
    }

    String::~String()
    {
        delete[] m_msg;
    }

    String String::Replace(const String &old_str, const String &new_str, B8 all) const
    {
        if (old_str == "")
        {
            return *this;
        }

        // TODO: Try to use raw char array instead of std::string later
        std::string original_str(m_msg);
        std::string old_str_str(old_str.m_msg);
        std::string new_str_str(new_str.m_msg);
        std::string replaced_str = "";

        size_t pos = 0;
        U32 index = 0;
        while ((pos = original_str.find(old_str_str, pos)) != std::string::npos)
        {
            replaced_str += original_str.substr(index, pos - index);
            replaced_str += new_str_str;
            pos += old_str_str.length();
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

        replaced_str += original_str.substr(index, original_str.length() - index);

        return String(replaced_str.c_str());
    }

    U32 String::Length() const
    {
        return strlen(m_msg);
    }

    void String::ToCharArray(char *&buffer, U32 &buffer_size) const
    {
        // check if the buffer is not allocated
        if (buffer == nullptr)
        {
            buffer = (char *)malloc(strlen(m_msg) + 1);
            buffer_size = strlen(m_msg);
        }
        else
        {
            // check if the buffer size is not enough
            if (sizeof(buffer) < strlen(m_msg))
            {
                delete[] buffer;
                buffer = (char *)malloc(strlen(m_msg) + 1);
                buffer_size = strlen(m_msg);
            }
        }

        memcpy(buffer, m_msg, buffer_size);
        buffer[buffer_size] = '\0';
    }

    String String::operator=(const String &other)
    {
        if (this == &other)
        {
            return *this;
        }

        delete[] m_msg;
        m_msg = new char[strlen(other.m_msg) + 1];
        strcpy(m_msg, other.m_msg);

        return *this;
    }

    bool String::operator==(const String &other) const
    {
        return strcmp(m_msg, other.m_msg) == 0;
    }

    String String::operator+(const String &other) const
    {
        std::string result(m_msg);
        result += other.m_msg;
        return String(result.c_str());
    }
} // namespace ntt