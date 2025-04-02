#include "testing_lib.h"

static inline void test_assert_libtest(void) {
  assert_true(1, "assert true");
  assert_false(0, "assert false");
  assert_eq(1, 1, "assert eq");
  assert_neq(1, 2, "assert neq");
}

int main(void) {
  TEST_FUNCTION(test_assert_libtest);

  return 0;
}
