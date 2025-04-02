#include "testing_lib.h"
#include "unistd.h"

static inline void test_write(void) {
  assert_true(write(1, "testing write\n", 14) == 14, "write test failed");
  assert_false(write(1, "testing write 2\n", 16) == 14, "write test failed");
}

int main(void) {
  TEST_FUNCTION(test_write);

  return 0;
}
