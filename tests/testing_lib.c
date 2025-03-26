#include "testing_lib.h"
#include "syscall.h"

// it is assumed that all of the functions used here work perfectly :-)

// basic write
static inline long __write(int fd, const void *buf, long count) {
  return syscall3(SYS_write, fd, (long)buf, count);
}

// basic exit
static inline void __exit(int status) {
  syscall1(SYS_exit, status);
  __builtin_unreachable();
}

// basic strlen
static inline long __str_len(const char *str) {
  long len = 0;
  while (*str != '\0') {
    len++;
    str++;
  }

  return len;
}

void print_success(void) { __write(1, "All tests passed\n", 17); }

void assert_true(int condition, const char *msg) {
  if (!condition) {
    long msg_len = __str_len(msg);

    __write(2, "Test failed: ", 13);
    __write(2, msg, msg_len);
    __write(2, "\n", 1);
    __exit(1);
  }
}

void assert_false(int condition, const char *msg) {
  assert_true(!condition, msg);
}
