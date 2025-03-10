#if defined(__APPLE__)
#define STARTNAME _start
#define MAINNAME _main
#elif defined(__linux__)
#define STARTNAME _start
#define MAINNAME main
#else
#error Unsupported platform
#endif

.global STARTNAME
.extern MAINNAME

_start:
#if defined(__aarch64__)
  // load argc, which is the first value on the stack
  ldr x0, [sp]

  // then argv is obtained as sp + 8, since argc is 8 bytes
  add x1, sp, #8

  // call main
  bl _main
  // Now x0 contains the exit status

  // macOS syscall number for SYS_exit
  mov x16, #1

  // will exit with the value in x0, which was updated by main()
  svc #0x80

#elif defined(__x86_64__)
    // rbp = 0
    xor %ebp, %ebp

    // get argc from the stack (implicitly zero-extended to 64-bit)
    mov (%rsp), %edi

    // take the address of argv from the stack
    lea 8(%rsp), %rsi

    // take the address of envp from the stack
    ;lea 16(%rsp,%rdi,8), %rdx 

    // per ABI and compatibility with icc
    ;xor %eax, %eax
 
    // %edi, %rsi, %rdx are the three args (of which first two are C standard) to main
    call MAINNAME

    // transfer the return of main to the first argument of _exit
    mov %eax, %edi
    movq $60, %rax
    syscall
#else
#error Unsupported platform
#endif
