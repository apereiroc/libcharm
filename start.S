.global _start
.extern _main

_start:
#if defined(__aarch64__)
  // argc is the first value on the stack
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
  // Get argc (first value in stack)
    xor %ebp, %ebp            # effectively RBP := 0, mark the end of stack frames
    mov (%rsp), %edi          # get argc from the stack (implicitly zero-extended to 64-bit)
    lea 8(%rsp), %rsi         # take the address of argv from the stack
    lea 16(%rsp,%rdi,8), %rdx # take the address of envp from the stack
    xor %eax, %eax            # per ABI and compatibility with icc
    call main                 # %edi, %rsi, %rdx are the three args (of which first two are C standard) to main

    mov %eax, %edi    # transfer the return of main to the first argument of _exit
    movq $60, %rax
    syscall
#endif
