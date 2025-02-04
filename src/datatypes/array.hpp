#pragma once
#include "common.hpp"
#include "object.hpp"
#include "allow_types.hpp"
#include "utilities/format_string.hpp"
#include <vector>

// TODO: Add self-defined exception later
#include <stdexcept>

namespace ntt
{
    /**
     * A generic datatype to store a series of the same type of values with supported
     *      utility functions. The size of the array can be changed dynamically.
     */
    template <typename T>
    class Array : public std::vector<T>, public Object
    {
    public:
        Array() = default;
        Array(const std::vector<T> &vec) : std::vector<T>(vec) {}
        Array(std::vector<T> &&vec) : std::vector<T>(std::move(vec)) {}
        Array(std::initializer_list<T> list) : std::vector<T>(list) {}

        String ToString() const override
        {
            String str = "[";
            for (auto i = 0; i < this->size(); i++)
            {
                str += ConvertToString((*this)[i]);
                if (i != this->size() - 1)
                {
                    str += ", ";
                }
            }
            str += "]";
            return str;
        }
    };
}