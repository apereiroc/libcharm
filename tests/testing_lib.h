#pragma once

void print_success(void);
void __report_error(const char *file, int line, const char *msg);

// assert macro to report file and line
#define assert_true(cond, msg)                                                 \
  do {                                                                         \
    if (!(cond))                                                               \
      __report_error(__FILE__, __LINE__, msg);                                 \
  } while (0)

#define assert_false(cond, msg) assert_true(!(cond), msg)
