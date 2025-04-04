#include "string.h"
#include "testing_lib.h"

static inline void test_strlen(void) {
  assert_eq(strlen(""), 0, "empty string");
  assert_eq(strlen("A"), 1, "single char");
  assert_eq(strlen("hello"), 5, "short word");
  assert_eq(strlen("  "), 2, "whitespace");
  assert_eq(strlen("|V|y `c@de` !$ wºrk!ng"), 23, "special chars");
}

static inline void test_memcpy(void) {
  const char src[] = "hello!";
  char dest[6];
  memcpy(dest, src, 6);
  assert_eq(dest[0], 'h', "testing memcpy - char `h`");
  assert_eq(dest[1], 'e', "testing memcpy - char `e`");
  assert_eq(dest[2], 'l', "testing memcpy - char `l`");
  assert_eq(dest[3], 'l', "testing memcpy - char `l`");
  assert_eq(dest[4], 'o', "testing memcpy - char `o`");
  assert_eq(dest[5], '!', "testing memcpy - char `!`");
}

int main(void) {
  TEST_FUNCTION(test_strlen);
  TEST_FUNCTION(test_memcpy);

  return 0;
}
