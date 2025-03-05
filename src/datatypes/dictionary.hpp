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

        /**
         * Check whether the key exists in the dictionary or not.
         *
         * @tparam K The type of the key.
         * @return True if the key exists in the dictionary, False otherwise.
         */
        inline B8 Contains(const K &key) const { return this->find(key) != this->end(); }

        /**
         * Remove the key-value pair from the dictionary. If the key does not
         *      exist in the dictionary, nothing will happen.
         *
         * @tparam K The type of the key.
         * @tparam key The key to be removed from the dictionary.
         */
        inline void Remove(const K &key) { this->erase(key); }

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
