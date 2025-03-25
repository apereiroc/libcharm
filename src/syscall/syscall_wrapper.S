#ifdef __APPLE__
#define SYSCALL_FUNCTION_NAME ___syscall_wrapper  // macOS requires an underscore prefix
#elif defined(__linux__)
#define SYSCALL_FUNCTION_NAME __syscall_wrapper   // Linux does not
#endif

 // export the function so it can be called from C
.global SYSCALL_FUNCTION_NAME

#if defined(__x86_64__)

SYSCALL_FUNCTION_NAME:
    movq %rdi, %rax   // syscall number
    movq %rsi, %rdi   // arg1
    movq %rdx, %rsi   // arg2
    movq %rcx, %rdx   // arg3
    movq %r8, %r10    // arg4
    movq %r9, %r8     // arg5
    movq 8(%rsp), %r9 // arg6

    // perform system call
    syscall

    // check for error (Linux: returns -errno)
    cmpq $-4096, %rax 
    jb .ret_no_error

    // convert to positive errno
    negq %rax

#elif defined(__aarch64__)

SYSCALL_FUNCTION_NAME:
#ifdef __APPLE__
    // on macOS, syscall number goes in x16
    mov x16, x0
#elif defined(__linux__)
    // on Linux, syscall number goes in x8
    mov x8, x0
#endif

    mov x0, x1        // arg1
    mov x1, x2        // arg2
    mov x2, x3        // arg3
    mov x3, x4        // arg4
    mov x4, x5        // arg5
    mov x5, x6        // arg6

    // perform system call
    svc #0

    // check for error (Linux: returns -errno)
    cmp x0, #-4096
    b.lo .ret_no_error

    // convert to positive errno
    neg x0, x0

#endif

.ret_no_error:
    ret
