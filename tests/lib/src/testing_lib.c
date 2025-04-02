#include "testing_lib.h"
#include "syscall.h"

// length of the char buffer used when converting ints to strings
// this should be enough for any 32-bit integer
// 10 digits + 1 sign + null terminator
#define BUFLEN_FOR_INTS 12

// length of the buffer to be sent to stderr
// when one of the tests fails
// will store `Failed: assertion failed at xxx: with msg xxx`
#define BUFLEN_ASRT_FAIL 256

/*
 * Utils
 * It is assumed that all of the util functions used here work perfectly :-)
 * so they will not be tested
 */

// colours

// hex colour #E82424 → RGB(232, 36, 36)
#define RED_COLOUR "\033[38;2;232;36;36m"
// hex colour #76946A: RGB(118, 148, 106)
#define GREEN_COLOUR "\033[38;2;118;148;106m"
// hex colour #FF9E3B: RGB(255, 211, 60)
#define YELLOW_COLOUR "\033[38;2;255;211;60m"
// hex colour #A3D4D5:  RGB(163, 228, 229)
#define LIGHT_BLUE_COLOUR "\033[38;2;163;228;229m"
// reset
#define RESET_COLOUR "\033[0m"

// string wrappers
#define wrap_str_in_red(msg) RED_COLOUR msg RESET_COLOUR
#define wrap_str_in_green(msg) GREEN_COLOUR msg RESET_COLOUR
#define wrap_str_in_yellow(msg) YELLOW_COLOUR msg RESET_COLOUR
#define wrap_str_in_light_blue(msg) LIGHT_BLUE_COLOUR msg RESET_COLOUR

// private libc-like functions

// basic write syscall
static inline long __write(int fd, const void *buf, long count) {
  return syscall3(SYS_write, fd, (long)buf, count);
}

// basic exit syscall
static inline void __exit(int status) {
  syscall1(SYS_exit, status);
  __builtin_unreachable();
}

// basic strlen function
static inline long __strlen(const char *str) {
  long len = 0;
  while (*str != '\0') {
    len++;
    str++;
  }

  return len;
}

// basic itoa (int to null-terminated string)
static inline void __itoa(int num, char *outbuf) {
  char temp[BUFLEN_FOR_INTS];
  int i = 0, j = 0;
  if (num == 0) {
    outbuf[j++] = '0';
  } else {
    while (num > 0) {
      // '0' is the root of digits
      // '0' + i = 'i'
      // so, the last digit of num is pushed at the end of temp
      // num is eventually set to 0 when is < 10 and is divided by 10
      temp[i++] = '0' + (char)(num % 10);
      num /= 10;
    }
    while (i > 0) {
      // reverse the digits
      outbuf[j++] = temp[--i];
    }
  }
  // append null terminator
  outbuf[j] = '\0';
}

static void __fill_buf_with_str(char *dest_buf, long *buf_idx,
                                const char *from_str) {
  while (*from_str != '\0') {
    // protect against dest_buf overflow
    if (*buf_idx == BUFLEN_ASRT_FAIL) {
      const char *err_msg =
          wrap_str_in_red("\nERROR: buffer overflow. ") "`BUFLEN_ASRT_FAIL` "
                                                        "has been exceeded\n";
      __write(2, err_msg, __strlen(err_msg));
      __exit(1);
    }
    dest_buf[(*buf_idx)++] = *from_str++;
  }
}

static void __build_assert_fail_message(char *buf, long *buf_idx,
                                        const char *asrt_type, const char *file,
                                        int line, const char *msg) {

  // buffer to store a 32-bit integer
  char line_num_buf[BUFLEN_FOR_INTS];

  // convert line number into a null-terminated string
  __itoa(line, line_num_buf);

  // print failure message
  __fill_buf_with_str(buf, buf_idx, wrap_str_in_red("FAILED\n"));
  __fill_buf_with_str(buf, buf_idx, "  assertion ");
  __fill_buf_with_str(buf, buf_idx, asrt_type);
  __fill_buf_with_str(buf, buf_idx, " failed at ");

  // copy file into output buffer
  __fill_buf_with_str(buf, buf_idx, YELLOW_COLOUR);
  __fill_buf_with_str(buf, buf_idx, file);
  __fill_buf_with_str(buf, buf_idx, ":");

  // copy line number where error occurred
  __fill_buf_with_str(buf, buf_idx, line_num_buf);
  __fill_buf_with_str(buf, buf_idx, RESET_COLOUR);
  __fill_buf_with_str(buf, buf_idx, " with message: `");

  // copy error message
  __fill_buf_with_str(buf, buf_idx, YELLOW_COLOUR);
  __fill_buf_with_str(buf, buf_idx, msg);
  __fill_buf_with_str(buf, buf_idx, RESET_COLOUR);
  __fill_buf_with_str(buf, buf_idx, "`\n");
}

/*
 * Implementations
 */

void __log_running_test_function(const char *func_name) {
  const char *buf = "Running tests in `";

  // write to stdout
  __write(1, buf, __strlen(buf));
  __write(1, func_name, __strlen(func_name));
  __write(1, "`: ... ", 7);
}

void __test_ok(void) {
  const char *buf = wrap_str_in_green("ok\n");

  // write to stdout
  __write(1, buf, __strlen(buf));
}

void __assertion_bool_failed(const char *file, int line, const char *msg) {
  // buffer to be sent to stderr
  char buf[BUFLEN_ASRT_FAIL];
  long buf_idx = 0;

  // build message
  __build_assert_fail_message(buf, &buf_idx, "", file, line, msg);

  // write buffer to stderr
  __write(2, buf, buf_idx);

  // exit with code 1
  __exit(1);
}

void __assertion_left_right_failed(const char *file, int line, const char *left,
                                   const char *right, const char *msg) {
  // buffer to be sent to stderr
  char buf[BUFLEN_ASRT_FAIL];
  long buf_idx = 0;

  // build message
  __build_assert_fail_message(buf, &buf_idx, "`left == right`", file, line,
                              msg);

  // build left == right test info
  // assertion `left == right` failed
  // left: 0
  // right: 1
  __fill_buf_with_str(buf, &buf_idx, "\n");
  __fill_buf_with_str(buf, &buf_idx, "  left: ");
  __fill_buf_with_str(buf, &buf_idx, left);
  __fill_buf_with_str(buf, &buf_idx, "\n");
  __fill_buf_with_str(buf, &buf_idx, "  right: ");
  __fill_buf_with_str(buf, &buf_idx, right);
  __fill_buf_with_str(buf, &buf_idx, "\n");

  // write buffer to stderr
  __write(2, buf, buf_idx);

  // exit with code 1
  __exit(1);
}
