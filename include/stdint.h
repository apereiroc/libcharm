#pragma once

/*
 * fixed-width integer types
 * */

// clang-format off

// intN_t: signed integer of exactly N bits
// uintN_t: unsigned integer of exactly N bits
typedef   signed char        int8_t;
typedef unsigned char       uint8_t;
typedef   signed short      int16_t;
typedef unsigned short     uint16_t;
typedef   signed int        int32_t;
typedef unsigned int       uint32_t;
typedef   signed long       int64_t;
typedef unsigned long      uint64_t;

// int_leastN_t: signed integer of at least N bits
// uint_leastN_t: unsigned integer of at least N bits
typedef   int8_t       int_least8_t;
typedef  uint8_t      uint_least8_t;
typedef  int16_t      int_least16_t;
typedef uint16_t     uint_least16_t;
typedef  int32_t      int_least32_t;
typedef uint32_t     uint_least32_t;
typedef  int64_t      int_least64_t;
typedef uint64_t     uint_least64_t;

// int_fastN_t: fastest-to-operate signed integer of at least N bits
// uint_fastN_t: fastest-to-operate unsigned integer of at least N bits
// what the ...
// let's play safe for 64-bit machines
typedef  int64_t        int_fast8_t;
typedef uint64_t       uint_fast8_t;
typedef  int64_t       int_fast16_t;
typedef uint64_t      uint_fast16_t;
typedef  int64_t       int_fast32_t;
typedef uint64_t      uint_fast32_t;
typedef  int64_t       int_fast64_t;
typedef uint64_t      uint_fast64_t;

// intptr_t: signed integer capable of holding a void pointer
// uintptr_t: unsigned integer capable of holding a void pointer
typedef  int64_t           intptr_t;
typedef uint64_t          uintptr_t;

// intmax_t: signed integer capable of holding any value of any signed integer type
// uintmax_t: usigned integer capable of holding any value of any usigned integer type
typedef  int64_t           intmax_t;
typedef uint64_t          uintmax_t;
