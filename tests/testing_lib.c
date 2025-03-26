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
// static inline long __str_len(const char *str) {
//   long len = 0;
//   while (*str != '\0') {
//     len++;
//     str++;
//   }
//
//   return len;
// }

// basic itoa
// converts integer to null-terminated string
static inline void __itoa(int num, char *outbuf) {
  // this should be enough for any 32-bit integer
  // 10 digits + 1 sign + null terminator
  char temp[12];
  int i = 0, j = 0;
  if (num == 0) {
    outbuf[j++] = '0';
  } else {
    while (num > 0) {
      temp[i++] = '0' + (num % 10);
      num /= 10;
    }
    while (i > 0) {
      // reverse the digits
      outbuf[j++] = temp[--i];
    }
  }
  outbuf[j] = '\0';
}

void print_success(void) { __write(1, "All tests passed\n", 17); }

void __report_error(const char *file, int line, const char *msg) {
  // buffer to be sent to stderr
  char buf[256];
  // 12 bytes should be enough for 32-bit integers
  char line_num_buf[12];

  // convert line number into a null-terminated string
  __itoa(line, line_num_buf);

  long i = 0;
  // copy file into output buffer
  while (*file)
    buf[i++] = *file++;
  buf[i++] = ':';

  // copy line number where error occurred
  const char *lptr = line_num_buf;
  while (*lptr)
    buf[i++] = *lptr++;
  buf[i++] = ':';
  buf[i++] = ' ';

  // copy error message
  while (*msg)
    buf[i++] = *msg++;
  buf[i++] = '\n';

  // write buffer to stderr
  __write(2, buf, i);

  // exit with code 1
  __exit(1);
}

// void assert_true(int condition, const char *msg) {
//   if (!condition) {
//     long msg_len = __str_len(msg);
//
//     __write(2, "Test failed: ", 13);
//     __write(2, msg, msg_len);
//     __write(2, "\n", 1);
//     __write(2, "Line: ", 6);
//     char linebuf[12];
//     __itoa(__LINE__, linebuf);
//     __write(2, linebuf, 12);
//     __exit(1);
//   }
// }
//
// void assert_false(int condition, const char *msg) {
//   assert_true(!condition, msg);
// }
