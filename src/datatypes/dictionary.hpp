#pragma once
#include <map>
#include "string.hpp"
#include "object.hpp"
#include <utilities/utilities.hpp>

namespace ntt
{
    template <typename K, typename V>
    class Dictionary : public std::map<K, V>, public Object
    {
    public:
        Dictionary() {}
        Dictionary(const Dictionary &other) : std::map<K, V>(other) {}
        Dictionary(Dictionary &&other) : std::map<K, V>(other) {}

        String ToString() const override
        {
            String result = "{\n";
            for (const auto &pair : *this)
            {
                result += Format("\t{}: {},\n", pair.first, pair.second);
            }
            result += "}";
            return result;
        }
    };
} // namespace ntt
