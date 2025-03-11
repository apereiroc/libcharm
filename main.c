#include "unistd.h"

int main(void) {
  write(1, "hello from my own libc!\n", 24);
  return 0;
}
