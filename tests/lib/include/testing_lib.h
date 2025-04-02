#pragma once

/*
 * private API (development)
 */

void __test_ok(void);
void __log_running_test_function(const char *func_name);
void __assertion_bool_failed(const char *file, int line, const char *msg);
void __assertion_left_right_failed(const char *file, int line, const char *left,
                                   const char *right, const char *msg);

#define _assert_bool_base(cond, msg)                                           \
  do {                                                                         \
    if (!(cond))                                                               \
      __assertion_bool_failed(__FILE__, __LINE__, msg);                        \
  } while (0)

#define _assert_eq_base(left, right, msg)                                      \
  do {                                                                         \
    if ((left) != (right))                                                     \
      __assertion_left_right_failed(__FILE__, __LINE__, #left, #right, msg);   \
  } while (0)

#define _assert_neq_base(left, right, msg)                                     \
  do {                                                                         \
    if ((left) == (right))                                                     \
      __assertion_left_right_failed(__FILE__, __LINE__, #left, #right, msg);   \
  } while (0)

/*
 * public API
 */

// macro to define a test function
#define TEST_FUNCTION(func)                                                    \
  do {                                                                         \
    __log_running_test_function(#func);                                        \
    func();                                                                    \
    __test_ok();                                                               \
  } while (0)

// assert macros
#define assert_true(cond, msg) _assert_bool_base(cond, msg)
#define assert_false(cond, msg) _assert_bool_base(!(cond), msg)
#define assert_eq(left, right, msg) _assert_eq_base(left, right, msg)
#define assert_neq(left, right, msg) _assert_neq_base(left, right, msg)
