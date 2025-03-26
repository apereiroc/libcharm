#include "stddef.h"
#include "syscall.h"
#include "unistd.h"

ssize_t write(int fildes, const void *buf, size_t nbyte) {
  ssize_t res = syscall3(SYS_write, fildes, (long)buf, (long)nbyte);
  return res;
}
