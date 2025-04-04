#include "stdio.h"
#include "testing_lib.h"

static inline void test_puts(void) {
  assert_eq(puts((void *)0), -1, "testing NULL");
  assert_eq(puts("testing puts"), 1, "testing standard usage");
}

int main(void) {
  TEST_FUNCTION(test_puts);

  return 0;
}
