#include <stddef.h>
#include <stdint.h>
#include <string.h>

void *memcpy(void *restrict s1, const void *restrict s2, size_t n) {
  // cast to byte
  // byte-by-byte copy
  uint8_t *dest = s1;
  const uint8_t *source = s2;

  for (size_t i = 0; i < n; i++)
    dest[i] = source[i];

  return dest;
}
