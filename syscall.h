#pragma once

extern long __syscall_wrapper(long number, long arg1, long arg2, long arg3,
                              long arg4, long arg5, long arg6);

long syscall0(long number);
long syscall1(long number, long arg1);
long syscall2(long number, long arg1, long arg2);
long syscall3(long number, long arg1, long arg2, long arg3);
long syscall4(long number, long arg1, long arg2, long arg3, long arg4);
long syscall5(long number, long arg1, long arg2, long arg3, long arg4,
              long arg5);
long syscall6(long number, long arg1, long arg2, long arg3, long arg4,
              long arg5, long arg6);

#ifdef __APPLE__
#ifdef __aarch64__
#define SYS_exit 1
#define SYS_fork 2
#define SYS_read 3
#define SYS_write 4
#define SYS_open 5
#define SYS_close 6
// TODO:...
#endif // __aarch64__
#ifdef __x86_64__
// TODO:...
#endif // __x86_64__
#endif // __APPLE__

#ifdef __linux__
#ifdef __aarch64__
#endif // __aarch64__
// TODO:...
#ifdef __x86_64__
// TODO:...
#endif // __x86_64__
#endif // __linux__
