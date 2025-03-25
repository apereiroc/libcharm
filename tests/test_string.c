#include "string.h"
#include "testing_lib.h"

void test_strlen(void) {
  assert_true(strlen("abc") == 3, "strlen test failed");
  assert_true(strlen("abc def 123") == 11, "strlen test failed");
  assert_true(strlen("") == 0, "strlen empty string test failed");
}

int main(void) {
  test_strlen();

  print_success();
  return 0;
}
