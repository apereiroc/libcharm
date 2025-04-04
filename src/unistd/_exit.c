#include <syscall.h>
#include <unistd.h>

__attribute__((noreturn)) void _exit(int exit_code) {
  syscall1(SYS_exit, exit_code);
  // tell the compiler that never returns
  __builtin_unreachable();
}
