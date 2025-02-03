#pragma once
#include "common.hpp"
#include "object.hpp"
#include "allow_types.hpp"
#include "utilities/format_string.hpp"

namespace ntt
{
    /**
     * A generic datatype to store a series of the same type of values with supported
     *      utility functions. The size of the array can be changed dynamically.
     */
    template <typename T, typename = std::enable_if_t<IsAllowtypes<T>::value>>
    class Array : public Object
    {
    public:
        Array(U32 count, T defaultValue) : Object(), m_count(count)
        {
            m_data = new T[count];
            for (U32 i = 0; i < count; i++)
            {
                m_data[i] = defaultValue;
            }
        }

        virtual ~Array()
        {
            if (m_data != nullptr)
            {
                delete[] m_data;
            }
        }

        /**
         * Get the number of the elements in the array.
         *
         * @return The number of elements in the array.
         */
        inline U32 Count() const { return m_count; }

        /**
         * Add new element into the array. If the array is full, the array will be resized
         *      to double the size.
         *
         * @param value The value to be added into the array.
         */
        void Append(T value)
        {
            if (m_count == Count())
            {
                ResizeArray(m_count * 2);
            }

            m_data[m_count++] = value;
        }

        String ToString() const override
        {
            String result = "[";
            for (U32 i = 0; i < m_count; i++)
            {
                result = result + ConvertToString(m_data[i]);
                if (i < m_count - 1)
                {
                    result = result + ", ";
                }
            }
            result = result + "]";
            return result;
        }

    private:
        void ResizeArray(U32 newSize)
        {
            T *newData = (T *)malloc(newSize * sizeof(T));
            for (U32 i = 0; i < m_count; i++)
            {
                newData[i] = m_data[i];
            }
            delete[] m_data;
            m_data = newData;
        }

    private:
        T *m_data;
        U32 m_count;
    };
}