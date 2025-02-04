#pragma once
#include <type_traits>
#include "common.hpp"
#include "object.hpp"

namespace ntt
{
    /**
     * Use for specifying the all types that are allowed to be used in generic datatypes (like
     *      Array, List, Map, etc.).
     */
    template <typename T>
    struct IsAllowtypes : std::false_type
    {
    };

#define DEFINE_ALLOW_TYPE(type)                \
    template <>                                \
    struct IsAllowtypes<type> : std::true_type \
    {                                          \
    };

    DEFINE_ALLOW_TYPE(U8)
    DEFINE_ALLOW_TYPE(U16)
    DEFINE_ALLOW_TYPE(U32)
    DEFINE_ALLOW_TYPE(U64)
    DEFINE_ALLOW_TYPE(I8)
    DEFINE_ALLOW_TYPE(I16)
    DEFINE_ALLOW_TYPE(I32)
    DEFINE_ALLOW_TYPE(I64)
    DEFINE_ALLOW_TYPE(F32)
    DEFINE_ALLOW_TYPE(F64)
    DEFINE_ALLOW_TYPE(B8)
    DEFINE_ALLOW_TYPE(Object)
    DEFINE_ALLOW_TYPE(std::nullptr_t)
} // namespace ntt
