#include "string.h"
#include "testing_lib.h"

static inline void test_strlen1(void) {
  assert_eq(strlen(""), 0, "empty string");
  assert_eq(strlen("A"), 1, "single char");
  assert_eq(strlen("hello"), 5, "short word");
  assert_eq(strlen("  "), 2, "whitespace");
  assert_eq(strlen("|V|y `c@de` !$ wºrk!ng"), 23, "special chars");
}

int main(void) {
  TEST_FUNCTION(test_strlen1);

  return 0;
}
