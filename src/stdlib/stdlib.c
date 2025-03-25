#include "stdlib.h"
#include "syscall.h"

__attribute__((noreturn)) void exit(int exit_code) {
  syscall1(SYS_exit, exit_code);
  __builtin_unreachable();
}
