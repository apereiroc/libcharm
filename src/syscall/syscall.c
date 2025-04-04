#include "syscall.h"

#if defined(__x86_64__)

/* Syscalls for Linux/Darwin x86_64 :
 *   - registers are 64-bit
 *   - syscall number goes to rax
 *   - arguments are passed to: rdi, rsi, rdx, r10, r8, r9
 *   - the system call is performed by calling the syscall instruction
 *   - syscall return comes in rax
 *   - rcx and r11 are clobbered, others are preserved.
 *   - the arguments are cast to long and assigned into the target registers
 *     which are then simply passed as registers to the asm code, so that we
 *     don't have to experience issues with register constraints.
 */

inline long syscall0(long number) {
  long ret;
  register long _num __asm__("rax") = (number);

  __asm__ volatile("syscall\n"
                   : "=a"(ret)
                   : "0"(_num)
                   : "rcx", "r11", "memory", "cc");

  return ret;
}

inline long syscall1(long number, long arg1) {

  long ret;
  register long _num __asm__("rax") = (number);
  register long _arg1 __asm__("rdi") = (long)(arg1);

  __asm__ volatile("syscall\n"
                   : "=a"(ret)
                   : "r"(_arg1), "0"(_num)
                   : "rcx", "r11", "memory", "cc");

  return ret;
}

inline long syscall2(long number, long arg1, long arg2) {

  long ret;
  register long _num __asm__("rax") = (number);
  register long _arg1 __asm__("rdi") = (long)(arg1);
  register long _arg2 __asm__("rsi") = (long)(arg2);

  __asm__ volatile("syscall\n"
                   : "=a"(ret)
                   : "r"(_arg1), "r"(_arg2), "0"(_num)
                   : "rcx", "r11", "memory", "cc");

  return ret;
}

inline long syscall3(long number, long arg1, long arg2, long arg3) {

  long ret;
  register long _num __asm__("rax") = (number);
  register long _arg1 __asm__("rdi") = (long)(arg1);
  register long _arg2 __asm__("rsi") = (long)(arg2);
  register long _arg3 __asm__("rdx") = (long)(arg3);

  __asm__ volatile("syscall\n"
                   : "=a"(ret)
                   : "r"(_arg1), "r"(_arg2), "r"(_arg3), "0"(_num)
                   : "rcx", "r11", "memory", "cc");

  return ret;
}

inline long syscall4(long number, long arg1, long arg2, long arg3, long arg4) {

  long ret;
  register long _num __asm__("rax") = (number);
  register long _arg1 __asm__("rdi") = (long)(arg1);
  register long _arg2 __asm__("rsi") = (long)(arg2);
  register long _arg3 __asm__("rdx") = (long)(arg3);
  register long _arg4 __asm__("r10") = (long)(arg4);

  __asm__ volatile("syscall\n"
                   : "=a"(ret)
                   : "r"(_arg1), "r"(_arg2), "r"(_arg3), "r"(_arg4), "0"(_num)
                   : "rcx", "r11", "memory", "cc");

  return ret;
}

inline long syscall5(long number, long arg1, long arg2, long arg3, long arg4,
                     long arg5) {

  long ret;
  register long _num __asm__("rax") = (number);
  register long _arg1 __asm__("rdi") = (long)(arg1);
  register long _arg2 __asm__("rsi") = (long)(arg2);
  register long _arg3 __asm__("rdx") = (long)(arg3);
  register long _arg4 __asm__("r10") = (long)(arg4);
  register long _arg5 __asm__("r8") = (long)(arg5);

  __asm__ volatile("syscall\n"
                   : "=a"(ret)
                   : "r"(_arg1), "r"(_arg2), "r"(_arg3), "r"(_arg4), "r"(_arg5),
                     "0"(_num)
                   : "rcx", "r11", "memory", "cc");

  return ret;
}

inline long syscall6(long number, long arg1, long arg2, long arg3, long arg4,
                     long arg5, long arg6) {

  long ret;
  register long _num __asm__("rax") = (number);
  register long _arg1 __asm__("rdi") = (long)(arg1);
  register long _arg2 __asm__("rsi") = (long)(arg2);
  register long _arg3 __asm__("rdx") = (long)(arg3);
  register long _arg4 __asm__("r10") = (long)(arg4);
  register long _arg5 __asm__("r8") = (long)(arg5);
  register long _arg6 __asm__("r9") = (long)(arg6);

  __asm__ volatile("syscall\n"
                   : "=a"(ret)
                   : "r"(_arg1), "r"(_arg2), "r"(_arg3), "r"(_arg4), "r"(_arg5),
                     "r"(_arg6), "0"(_num)
                   : "rcx", "r11", "memory", "cc");

  return ret;
}

#endif
