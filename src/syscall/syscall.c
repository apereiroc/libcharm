#include <syscall.h>

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

#elif defined(__aarch64__)

/* Syscalls for Linux/Darwin aarch64/arm64 :
 *   - registers are 64-bit
 *   - syscall number goes to x8 (Linux) / x16 (Darwin)
 *   - arguments are passed to: x0, x1, x2, x3, x4, x5
 *   - the system call is performed by calling svc 0
 *   - syscall return comes in x0.
 *   - rcx and r11 are clobbered, others are preserved.
 *   - the arguments are cast to long and assigned into the target registers
 *     which are then simply passed as registers to the asm code, so that we
 *     don't have to experience issues with register constraints.
 */

inline long syscall0(long number) {
#if defined(__APPLE__)
  register long _num __asm__("x16") = number;
#elif defined(__linux__)
  register long _num __asm__("x8") = number;
#endif
  register long x0 __asm__("x0");

  __asm__ volatile("svc 0\n" : "=r"(x0) : "r"(_num) : "memory", "cc");

  // syscall output is in x0
  return x0;
}

inline long syscall1(long number, long arg1) {

#if defined(__APPLE__)
  register long _num __asm__("x16") = number;
#elif defined(__linux__)
  register long _num __asm__("x8") = number;
#endif
  register long x0 __asm__("x0") = arg1;

  __asm__ volatile("svc 0\n" : "=r"(x0) : "r"(x0), "r"(_num) : "memory", "cc");

  // syscall output is in x0
  return x0;
}

inline long syscall2(long number, long arg1, long arg2) {

#if defined(__APPLE__)
  register long _num __asm__("x16") = number;
#elif defined(__linux__)
  register long _num __asm__("x8") = number;
#endif
  register long x0 __asm__("x0") = arg1;
  register long x1 __asm__("x1") = arg2;

  __asm__ volatile("svc 0\n"
                   : "=r"(x0)
                   : "r"(x0), "r"(x1), "r"(_num)
                   : "memory", "cc");

  // syscall output is in x0
  return x0;
}

inline long syscall3(long number, long arg1, long arg2, long arg3) {

#if defined(__APPLE__)
  register long _num __asm__("x16") = number;
#elif defined(__linux__)
  register long _num __asm__("x8") = number;
#endif
  register long x0 __asm__("x0") = arg1;
  register long x1 __asm__("x1") = arg2;
  register long x2 __asm__("x2") = arg3;

  __asm__ volatile("svc 0\n"
                   : "=r"(x0)
                   : "r"(x0), "r"(x1), "r"(x2), "r"(_num)
                   : "memory", "cc");

  // syscall output is in x0
  return x0;
}

inline long syscall4(long number, long arg1, long arg2, long arg3, long arg4) {

#if defined(__APPLE__)
  register long _num __asm__("x16") = number;
#elif defined(__linux__)
  register long _num __asm__("x8") = number;
#endif
  register long x0 __asm__("x0") = arg1;
  register long x1 __asm__("x1") = arg2;
  register long x2 __asm__("x2") = arg3;
  register long x3 __asm__("x3") = arg4;

  __asm__ volatile("svc 0\n"
                   : "=r"(x0)
                   : "r"(x0), "r"(x1), "r"(x2), "r"(x3), "r"(_num)
                   : "memory", "cc");

  // syscall output is in x0
  return x0;
}

inline long syscall5(long number, long arg1, long arg2, long arg3, long arg4,
                     long arg5) {
#if defined(__APPLE__)
  register long _num __asm__("x16") = number;
#elif defined(__linux__)
  register long _num __asm__("x8") = number;
#endif
  register long x0 __asm__("x0") = arg1;
  register long x1 __asm__("x1") = arg2;
  register long x2 __asm__("x2") = arg3;
  register long x3 __asm__("x3") = arg4;
  register long x4 __asm__("x4") = arg5;

  __asm__ volatile("svc 0\n"
                   : "=r"(x0)
                   : "r"(x0), "r"(x1), "r"(x2), "r"(x3), "r"(x4), "r"(_num)
                   : "memory", "cc");

  // syscall output is in x0
  return x0;
}

inline long syscall6(long number, long arg1, long arg2, long arg3, long arg4,
                     long arg5, long arg6) {

#if defined(__APPLE__)
  register long _num __asm__("x16") = number;
#elif defined(__linux__)
  register long _num __asm__("x8") = number;
#endif
  register long x0 __asm__("x0") = arg1;
  register long x1 __asm__("x1") = arg2;
  register long x2 __asm__("x2") = arg3;
  register long x3 __asm__("x3") = arg4;
  register long x4 __asm__("x4") = arg5;
  register long x5 __asm__("x5") = arg6;

  __asm__ volatile("svc 0\n"
                   : "=r"(x0)
                   : "r"(x0), "r"(x1), "r"(x2), "r"(x3), "r"(x4), "r"(x5),
                     "r"(_num)
                   : "memory", "cc");

  // syscall output is in x0
  return x0;
}

#endif
