#pragma once

long syscall0(long number);
long syscall1(long number, long arg1);
long syscall2(long number, long arg1, long arg2);
long syscall3(long number, long arg1, long arg2, long arg3);
long syscall4(long number, long arg1, long arg2, long arg3, long arg4);
long syscall5(long number, long arg1, long arg2, long arg3, long arg4,
              long arg5);
long syscall6(long number, long arg1, long arg2, long arg3, long arg4,
              long arg5, long arg6);

#if defined(__APPLE__)

#define SYS_exit 0x2000001
#define SYS_write 0x2000004
// TODO:add the rest...

#endif // __APPLE__

#if defined(__linux__) && defined(__aarch64__)

#define SYS_write 64
#define SYS_exit 93
// TODO:add the rest...

#endif // linux __aarch64__

#if defined(__linux__) && defined(__x86_64__)

#define SYS_write 1
#define SYS_exit 60
// TODO:add the rest...

#endif // linux __x86_64__
