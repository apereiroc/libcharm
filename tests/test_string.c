#include "string.h"
#include "testing_lib.h"

static inline void test_strlen(void) {
  assert_true(strlen("123") == 3, "strlen test failed");
  assert_true(strlen("123 456 789") == 11, "strlen test failed");
  assert_true(strlen("") == 0, "strlen empty string test failed");
}

int main(void) {
  test_strlen();

  print_success();
  return 0;
}
