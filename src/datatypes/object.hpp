#pragma once
#include "string.hpp"

namespace ntt
{
    /**
     * The core object class which all other classes (except the datatypes like U8, I32, etc. and String
     *      can be ignored) will inherit from.
     *
     * @note Other classes should not inherit from class directly.
     */
    class Object
    {
    public:
        /**
         * Overide this method and the result of this method will be displayed when
         *      the object is printed or formatted as a new parameter of a string.
         *
         * @return The string representation of the object. The default implementation
         *      will return "<Object />".
         */
        virtual String ToString() const;
    };
} // namespace ntt
