#include "string.hpp"
#include <cstring>

namespace ntt
{
    class String::Impl
    {
    public:
        char *m_msg;
    };

    String::String(const char *msg)
        : m_impl(CreateScope<Impl>())
    {
        m_impl->m_msg = new char[strlen(msg) + 1];
        strcpy(m_impl->m_msg, msg);
    }

    String::String(const String &other) : m_impl(CreateScope<Impl>())
    {
        m_impl->m_msg = new char[strlen(other.m_impl->m_msg) + 1];
        strcpy(m_impl->m_msg, other.m_impl->m_msg);
    }

    String::~String()
    {
        delete[] m_impl->m_msg;
    }

    bool String::operator==(const String &other) const
    {
        return strcmp(m_impl->m_msg, other.m_impl->m_msg) == 0;
    }
} // namespace ntt