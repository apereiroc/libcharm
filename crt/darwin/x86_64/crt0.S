  /*
  *
  * Darwin -- x86_64
  * 
  *
  * ABI:
  *   functions:
  *       args: rdi, rsi, rdx, rcx, r8, r9
  *       return val: rax
  *   syscalls:
  *       args: rdi, rsi, rdx, r10, r8, r9
  *       return val: rax
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
.extern _main


_start:
  // ebp = 0
  xor %ebp, %ebp

  // pop the top of the stack (argc) into rdi
  pop %rdi

  // pop the top of the stack (argv[0]) into rsi
  pop %rsi

  // call main
  call _main

  // the return value of main is in rax
  // move it to rdi to make the system call
  mov %eax, %edi

  // move system call number 1 (exit) to rax
  mov $0x2000001, %eax

  // call
  syscall
