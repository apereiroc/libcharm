#include "testing_lib.h"

int main(void) {

  assert_true(1, "assert true failed");
  assert_false(0, "assert false failed");

  print_success();
  return 0;
}
