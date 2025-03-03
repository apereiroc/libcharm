#include "syscall.h"

inline long syscall0(long number) {
  return __syscall_wrapper(number, 0, 0, 0, 0, 0, 0);
}

inline long syscall1(long number, long arg1) {

  return __syscall_wrapper(number, arg1, 0, 0, 0, 0, 0);
}

inline long syscall2(long number, long arg1, long arg2) {

  return __syscall_wrapper(number, arg1, arg2, 0, 0, 0, 0);
}

inline long syscall3(long number, long arg1, long arg2, long arg3) {

  return __syscall_wrapper(number, arg1, arg2, arg3, 0, 0, 0);
}

inline long syscall4(long number, long arg1, long arg2, long arg3, long arg4) {

  return __syscall_wrapper(number, arg1, arg2, arg3, arg4, 0, 0);
}

inline long syscall5(long number, long arg1, long arg2, long arg3, long arg4,
                     long arg5) {

  return __syscall_wrapper(number, arg1, arg2, arg3, arg4, arg5, 0);
}

inline long syscall6(long number, long arg1, long arg2, long arg3, long arg4,
                     long arg5, long arg6) {

  return __syscall_wrapper(number, arg1, arg2, arg3, arg4, arg5, arg6);
}
