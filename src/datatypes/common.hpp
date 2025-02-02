#pragma once
#include <assert.h>

namespace ntt
{
    typedef unsigned char u8;   ///< 1 byte data
    constexpr u8 U8_MAX = 0xFF; ///< Maximum value of u8 (255)
    constexpr u8 U8_MIN = 0x00; ///< Minimum value of u8 (0)
    static_assert(sizeof(u8) == 1, "Size of u8 is not 1 byte");

    typedef unsigned short u16;     ///< 2-byte data
    constexpr u16 U16_MAX = 0xFFFF; ///< Maximum value of u16 (65535)
    constexpr u16 U16_MIN = 0x0000; ///< Minimum value of u16 (0)
    static_assert(sizeof(u16) == 2, "Size of u16 is not 2 bytes");

    typedef unsigned int u32;           ///< 4-byte data
    constexpr u32 U32_MAX = 0xFFFFFFFF; ///< Maximum value of u32 (4294967295)
    constexpr u32 U32_MIN = 0x00000000; ///< Minimum value of u32 (0)
    static_assert(sizeof(u32) == 4, "Size of u32 is not 4 bytes");

    typedef unsigned long long u64;             ///< 8-byte data
    constexpr u64 U64_MAX = 0xFFFFFFFFFFFFFFFF; ///< Maximum value of u64 (18446744073709551615)
    constexpr u64 U64_MIN = 0x0000000000000000; ///< Minimum value of u64 (0)
    static_assert(sizeof(u64) == 8, "Size of u64 is not 8 bytes");

    typedef signed char i8;      ///< 1 byte signed data
    constexpr i8 I8_MAX = 0x7F;  ///< Maximum value of i8 (127)
    constexpr i8 I8_MIN = -0x80; ///< Minimum value of i8 (-128)
    static_assert(sizeof(i8) == 1, "Size of i8 is not 1 byte");

    typedef signed short i16;        ///< 2-byte signed data
    constexpr i16 I16_MAX = 0x7FFF;  ///< Maximum value of i16 (32767)
    constexpr i16 I16_MIN = -0x8000; ///< Minimum value of i16 (-32768)
    static_assert(sizeof(i16) == 2, "Size of i16 is not 2 bytes");

    typedef signed int i32;              ///< 4-byte signed data
    constexpr i32 I32_MAX = 0x7FFFFFFF;  ///< Maximum value of i32 (2147483647)
    constexpr i32 I32_MIN = -0x80000000; ///< Minimum value of i32 (-2147483648)
    static_assert(sizeof(i32) == 4, "Size of i32 is not 4 bytes");

    typedef signed long long i64;                ///< 8-byte signed data
    constexpr i64 I64_MAX = 0x7FFFFFFFFFFFFFFF;  ///< Maximum value of i64 (9223372036854775807)
    constexpr i64 I64_MIN = -0x8000000000000000; ///< Minimum value of i64 (-9223372036854775808)
    static_assert(sizeof(i64) == 8, "Size of i64 is not 8 bytes");

    typedef float f32;                         ///< 4-byte floating point data
    constexpr f32 F32_MAX = 3.402823466e+38F;  ///< Maximum value of f32 (3.402823466e+38)
    constexpr f32 F32_MIN = -3.402823466e+38F; ///< Minimum value of f32 (-3.402823466e+38)
    static_assert(sizeof(f32) == 4, "Size of f32 is not 4 bytes");

    typedef double f64;                               ///< 8-byte floating point data
    constexpr f64 F64_MAX = 1.7976931348623158e+308;  ///< Maximum value of f64 (1.7976931348623158e+308)
    constexpr f64 F64_MIN = -1.7976931348623158e+308; ///< Minimum value of f64 (-1.7976931348623158e+308)
    static_assert(sizeof(f64) == 8, "Size of f64 is not 8 bytes");

    typedef bool b8; ///< 1 byte boolean data
    static_assert(sizeof(b8) == 1, "Size of b8 is not 1 byte");
} // namespace ntt
