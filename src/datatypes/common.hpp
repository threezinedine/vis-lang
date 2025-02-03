#pragma once
#include <assert.h>

namespace ntt
{
    typedef unsigned char U8;   ///< 1 byte data
    constexpr U8 U8_MAX = 0xFF; ///< Maximum value of U8 (255)
    constexpr U8 U8_MIN = 0x00; ///< Minimum value of U8 (0)
    static_assert(sizeof(U8) == 1, "Size of U8 is not 1 byte");

    typedef unsigned short U16;     ///< 2-byte data
    constexpr U16 U16_MAX = 0xFFFF; ///< Maximum value of U16 (65535)
    constexpr U16 U16_MIN = 0x0000; ///< Minimum value of U16 (0)
    static_assert(sizeof(U16) == 2, "Size of U16 is not 2 bytes");

    typedef unsigned int U32;           ///< 4-byte data
    constexpr U32 U32_MAX = 0xFFFFFFFF; ///< Maximum value of U32 (4294967295)
    constexpr U32 U32_MIN = 0x00000000; ///< Minimum value of U32 (0)
    static_assert(sizeof(U32) == 4, "Size of U32 is not 4 bytes");

    typedef unsigned long long U64;             ///< 8-byte data
    constexpr U64 U64_MAX = 0xFFFFFFFFFFFFFFFF; ///< Maximum value of U64 (18446744073709551615)
    constexpr U64 U64_MIN = 0x0000000000000000; ///< Minimum value of U64 (0)
    static_assert(sizeof(U64) == 8, "Size of U64 is not 8 bytes");

    typedef signed char I8;      ///< 1 byte signed data
    constexpr I8 I8_MAX = 0x7F;  ///< Maximum value of I8 (127)
    constexpr I8 I8_MIN = -0x80; ///< Minimum value of I8 (-128)
    static_assert(sizeof(I8) == 1, "Size of I8 is not 1 byte");

    typedef signed short I16;        ///< 2-byte signed data
    constexpr I16 I16_MAX = 0x7FFF;  ///< Maximum value of I16 (32767)
    constexpr I16 I16_MIN = -0x8000; ///< Minimum value of I16 (-32768)
    static_assert(sizeof(I16) == 2, "Size of I16 is not 2 bytes");

    typedef signed int I32;              ///< 4-byte signed data
    constexpr I32 I32_MAX = 0x7FFFFFFF;  ///< Maximum value of I32 (2147483647)
    constexpr I32 I32_MIN = -0x80000000; ///< Minimum value of I32 (-2147483648)
    static_assert(sizeof(I32) == 4, "Size of I32 is not 4 bytes");

    typedef signed long long I64;                ///< 8-byte signed data
    constexpr I64 I64_MAX = 0x7FFFFFFFFFFFFFFF;  ///< Maximum value of I64 (9223372036854775807)
    constexpr I64 I64_MIN = -0x8000000000000000; ///< Minimum value of I64 (-9223372036854775808)
    static_assert(sizeof(I64) == 8, "Size of I64 is not 8 bytes");

    typedef float F32;                         ///< 4-byte floating point data
    constexpr F32 F32_MAX = 3.402823466e+38F;  ///< Maximum value of F32 (3.402823466e+38)
    constexpr F32 F32_MIN = -3.402823466e+38F; ///< Minimum value of F32 (-3.402823466e+38)
    static_assert(sizeof(F32) == 4, "Size of F32 is not 4 bytes");

    typedef double F64;                               ///< 8-byte floating point data
    constexpr F64 F64_MAX = 1.7976931348623158e+308;  ///< Maximum value of F64 (1.7976931348623158e+308)
    constexpr F64 F64_MIN = -1.7976931348623158e+308; ///< Minimum value of F64 (-1.7976931348623158e+308)
    static_assert(sizeof(F64) == 8, "Size of F64 is not 8 bytes");

    typedef bool B8; ///< 1 byte boolean data
    constexpr B8 True = true;
    constexpr B8 False = false;
    static_assert(sizeof(B8) == 1, "Size of B8 is not 1 byte");
} // namespace ntt
