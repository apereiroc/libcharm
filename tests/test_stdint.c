#include "stdint.h"
#include "testing_lib.h"

static inline void test_exact_widths(void) {
  assert_eq(sizeof(int8_t) * 8, 8, "8-bit signed int");
  assert_eq(sizeof(uint8_t) * 8, 8, "8-bit unsigned int");
  assert_eq(sizeof(int16_t) * 8, 16, "16-bit signed int");
  assert_eq(sizeof(uint16_t) * 8, 16, "16-bit unsigned int");
  assert_eq(sizeof(int32_t) * 8, 32, "32-bit signed int");
  assert_eq(sizeof(uint32_t) * 8, 32, "32-bit unsigned int");
  assert_eq(sizeof(int64_t) * 8, 64, "64-bit signed int");
  assert_eq(sizeof(uint64_t) * 8, 64, "64-bit unsigned int");
}

static inline void test_least_widths(void) {
  assert_true(sizeof(int_least8_t) * 8 >= 8, "at least 8-bit signed int");
  assert_true(sizeof(uint_least8_t) * 8 >= 8, "at least 8-bit unsigned int");
  assert_true(sizeof(int_least16_t) * 8 >= 16, "at least 16-bit signed int");
  assert_true(sizeof(uint_least16_t) * 8 >= 16, "at least 16-bit unsigned int");
  assert_true(sizeof(int_least32_t) * 8 >= 32, "at least 32-bit signed int");
  assert_true(sizeof(uint_least32_t) * 8 >= 32, "at least 32-bit unsigned int");
  assert_true(sizeof(int_least64_t) * 8 >= 64, "at least 64-bit signed int");
  assert_true(sizeof(uint_least64_t) * 8 >= 64, "at least 64-bit unsigned int");
}
static inline void test_fast_widths(void) {
  // just testing widths are enough
  assert_true(sizeof(int_fast8_t) * 8 >= 8, "fast 8-bit signed int");
  assert_true(sizeof(uint_fast8_t) * 8 >= 8, "fast 8-bit unsigned int");
  assert_true(sizeof(int_fast16_t) * 8 >= 16, "fast 16-bit signed int");
  assert_true(sizeof(uint_fast16_t) * 8 >= 16, "fast 16-bit unsigned int");
  assert_true(sizeof(int_fast32_t) * 8 >= 32, "fast 32-bit signed int");
  assert_true(sizeof(uint_fast32_t) * 8 >= 32, "fast 32-bit unsigned int");
  assert_true(sizeof(int_fast64_t) * 8 >= 64, "fast 64-bit signed int");
  assert_true(sizeof(uint_fast64_t) * 8 >= 64, "fast 64-bit unsigned int");
}

static inline void test_intptr_uintptr(void) {
  // variables to be used in the test
  int8_t test_variable_int8 = (int8_t)1u << 6;
  int16_t test_variable_int16 = (int16_t)1 << 14;
  int32_t test_variable_int32 = (int32_t)1 << 30;
  int64_t test_variable_int64 = (int64_t)1 << 62;

  uint8_t test_variable_uint8 = (uint8_t)1u << 6;
  uint16_t test_variable_uint16 = (uint16_t)1 << 14;
  uint32_t test_variable_uint32 = (uint32_t)1 << 30;
  uint64_t test_variable_uint64 = (uint64_t)1 << 62;

  void *void_ptr;
  int8_t *int8_ptr;
  int16_t *int16_ptr;
  int32_t *int32_ptr;
  int64_t *int64_ptr;
  uint8_t *uint8_ptr;
  uint16_t *uint16_ptr;
  uint32_t *uint32_ptr;
  uint64_t *uint64_ptr;
  intptr_t intptr_addr_holder;
  uintptr_t uintptr_addr_holder;

  // test intptr_t
  void_ptr = &test_variable_int8;
  intptr_addr_holder = (intptr_t)void_ptr;
  int8_ptr = (int8_t *)intptr_addr_holder;
  assert_eq(*int8_ptr, test_variable_int8, "intptr_t failed with int8_t");

  void_ptr = &test_variable_int16;
  intptr_addr_holder = (intptr_t)void_ptr;
  int16_ptr = (int16_t *)intptr_addr_holder;
  assert_eq(*int16_ptr, test_variable_int16, "intptr_t failed with int16_t");

  void_ptr = &test_variable_int32;
  intptr_addr_holder = (intptr_t)void_ptr;
  int32_ptr = (int32_t *)intptr_addr_holder;
  assert_eq(*int32_ptr, test_variable_int32, "intptr_t failed with int32_t");

  void_ptr = &test_variable_int64;
  intptr_addr_holder = (intptr_t)void_ptr;
  int64_ptr = (int64_t *)intptr_addr_holder;
  assert_eq(*int64_ptr, test_variable_int64, "intptr_t failed with int64_t");

  void_ptr = &test_variable_uint8;
  intptr_addr_holder = (intptr_t)void_ptr;
  uint8_ptr = (uint8_t *)intptr_addr_holder;
  assert_eq(*uint8_ptr, test_variable_uint8, "intptr_t failed with uint8_t");

  void_ptr = &test_variable_uint16;
  intptr_addr_holder = (intptr_t)void_ptr;
  uint16_ptr = (uint16_t *)intptr_addr_holder;
  assert_eq(*uint16_ptr, test_variable_uint16, "intptr_t failed with uint16_t");

  void_ptr = &test_variable_uint32;
  intptr_addr_holder = (intptr_t)void_ptr;
  uint32_ptr = (uint32_t *)intptr_addr_holder;
  assert_eq(*uint32_ptr, test_variable_uint32, "intptr_t failed with uint32_t");

  void_ptr = &test_variable_uint64;
  intptr_addr_holder = (intptr_t)void_ptr;
  uint64_ptr = (uint64_t *)intptr_addr_holder;
  assert_eq(*uint64_ptr, test_variable_uint64, "intptr_t failed with uint64_t");

  // test uintptr_t
  void_ptr = &test_variable_int8;
  uintptr_addr_holder = (uintptr_t)void_ptr;
  int8_ptr = (int8_t *)uintptr_addr_holder;
  assert_eq(*int8_ptr, test_variable_int8, "uintptr_t failed with int8_t");

  void_ptr = &test_variable_int16;
  uintptr_addr_holder = (uintptr_t)void_ptr;
  int16_ptr = (int16_t *)uintptr_addr_holder;
  assert_eq(*int16_ptr, test_variable_int16, "uintptr_t failed with int16_t");

  void_ptr = &test_variable_int32;
  uintptr_addr_holder = (uintptr_t)void_ptr;
  int32_ptr = (int32_t *)uintptr_addr_holder;
  assert_eq(*int32_ptr, test_variable_int32, "uintptr_t failed with int32_t");

  // clang-format off
  void_ptr = &test_variable_int64;
  uintptr_addr_holder = (uintptr_t)void_ptr;
  int64_ptr = (int64_t *)uintptr_addr_holder;
  assert_eq(*int64_ptr, test_variable_int64, "uintptr_t failed with int64_t");

  void_ptr = &test_variable_uint8;
  uintptr_addr_holder = (uintptr_t)void_ptr;
  uint8_ptr = (uint8_t *)uintptr_addr_holder;
  assert_eq(*uint8_ptr, test_variable_uint8, "uintptr_t failed with uint8_t");

  void_ptr = &test_variable_uint16;
  uintptr_addr_holder = (uintptr_t)void_ptr;
  uint16_ptr = (uint16_t *)uintptr_addr_holder;
  assert_eq(*uint16_ptr, test_variable_uint16, "uintptr_t failed with uint16_t");

  void_ptr = &test_variable_uint32;
  uintptr_addr_holder = (uintptr_t)void_ptr;
  uint32_ptr = (uint32_t *)uintptr_addr_holder;
  assert_eq(*uint32_ptr, test_variable_uint32, "uintptr_t failed with uint32_t");

  void_ptr = &test_variable_uint64;
  uintptr_addr_holder = (uintptr_t)void_ptr;
  uint64_ptr = (uint64_t *)uintptr_addr_holder;
  assert_eq(*uint64_ptr, test_variable_uint64, "uintptr_t failed with uint64_t");
  // clang-format on
}

#define __INT64MIN (-9223372036854775807L - 1)
#define __INT64MAX 9223372036854775807L
#define __UINT64MAX 18446744073709551615UL

static inline void test_intmax_uintmax(void) {
  intmax_t intmin = __INT64MIN;
  intmax_t intmax = __INT64MAX;
  // do not overflow
  assert_eq(intmin, __INT64MIN, "intmax_t holding int64min");
  assert_eq(intmax, __INT64MAX, "intmax_t holding int64max");

  uintmax_t uintmax = __UINT64MAX;
  // do not overflow
  assert_eq(uintmax, __UINT64MAX, "uintmax_t holding uint64max");
}

#undef __INT64MIN
#undef __INT64MAX

int main(void) {
  TEST_FUNCTION(test_exact_widths);
  TEST_FUNCTION(test_least_widths);
  TEST_FUNCTION(test_fast_widths);
  TEST_FUNCTION(test_intptr_uintptr);
  TEST_FUNCTION(test_intmax_uintmax);

  return 0;
}
