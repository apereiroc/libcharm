  /*
  *
  * Linux -- aarch64
  * 
  *
  * ABI:
  *   functions:
  *       args: x0, x1, x2, x3, x4, x5, x6, x7
  *       return val: x0
  *   syscalls:
  *       args: x0, x1, x2, x3, x4, x5
  *       syscall number: x8
  *       return val: x0
  *
  * Stack grows downwards:
  *
  *     -----------------
  *         argc
  *     -----------------
  *         argv[0]
  *     -----------------
  *         ...
  *     -----------------
  *         argv[argc-1]
  *     -----------------
  *         null
  *     -----------------
  *         envp[0]
  *     -----------------
  *         ....
  *     -----------------
  *         envp[N]
  *     -----------------
  *         null
  *     -----------------
  * 
  * */


.global _start
.extern main


_start:
  // load top of the stack (argc) into x0
  // [] dereference the register
  ldr x0, [sp]

  // load argv[0] into x1
  // argv[0] is sp (argc) + 8 bytes
  add x1, sp, #8

  // call main
  // the return value of main will be moved
  // to x0
  bl main

  // move system call number 93 (exit) to x8
  mov x8, 93

  // make syscall
  svc 0
