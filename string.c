#include "string.h"
#include "stddef.h"

size_t strlen(const char *s) {
  size_t len = 0;

  const char *str = s;

  while (*s++ != '\0') {
    len++;
  }

  return len;
}
