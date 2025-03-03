#include "stdlib.h"
#include "syscall.h"

void exit(int exit_code) { syscall1(SYS_exit, exit_code); }
