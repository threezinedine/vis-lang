#pragma once
#include "memory.hpp"

namespace ntt
{
    /**
     * Application self-defined string data type. This class will contains multiple supported
     *      string operations that are not available in the standard C++ string class.
     */
    class String
    {
    public:
        String(const char *msg);
        String(const String &other);
        ~String();

        bool operator==(const String &other) const;

    private:
        class Impl;
        Scope<Impl> m_impl;
    };
} // namespace ntt
