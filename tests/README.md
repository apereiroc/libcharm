## Testing framework

Every file containing tests goes here. Source files placed in this folder are compiled into the `target` directory, under the `tests` folder

The basic structure of a test is

```c
// the actual testing library
#include "testing_lib.h"
// other includes where your functions are declared ...

static inline void test_of_my_functions(void) {
  assert_true(my_function_to_be_tested() == my_expected_result, "fail message to be shown");
  assert_false(my_other_function_to_be_tested() == my_not_expected_result, "some other fail message to be shown");
}

int main(void) {
  // put here all your test functions
  test_of_my_functions();

  // displays an ok message
  print_success();
  return 0;
}
```
