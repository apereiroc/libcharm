#include "stdio.h"
#include "unistd.h"

int puts(const char *s) {
  if (!s)
    return -1;
  int fd_stdout = 1;
  // size_t len = strlen(s);

  // TODO: define eof
  const int eof = -1;

  // provisional meanwhile i don't have memcpy
  while (*s) {
    if (write(fd_stdout, s, 1) != 1)
      return eof;
    s++;
  }

  if (write(fd_stdout, "\n", 1) != 1)
    return eof;

  return 1;

  // create a buffer with extra space for '\n'
  // char buf[len + 1];
  //
  // memcpy(buf, str, len);
  //
  // buf[len] = '\n';
  //
  // int res = write(fd_stdout, buf, len + 1);
  // return res;
}
