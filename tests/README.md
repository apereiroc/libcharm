## Testing framework

Every file containing tests goes here. Source files placed in this folder are compiled into the `target` directory, under the `tests` folder

The basic structure of a test is

```c
// the actual testing library
#include "testing_lib.h"
// other includes where your functions are declared ...

static inline void test_of_function1(void) {
  assert_true(my_function_to_be_tested() == my_expected_result, "fail message to be shown");
  assert_false(my_other_function_to_be_tested() == my_not_expected_result, "some other fail message to be shown");
}

static inline void test_of_function2(void) {
  int left = 1, right = 1;
  assert_eq(left, right, "left is equal to right");
  right = 2;
  // this one would raise an error
  // assert_eq(left, right, "left is equal to right");
  assert_neq(left, right, "left is not equal to right")
}

// wrap your test functions and put them in the main function 
int main(void) {
  // displays an ok message if the test is passed
  // exits with code 1 and displays information otherwise
  TEST_FUNCTION(test_of_function1);
  TEST_FUNCTION(test_of_function2);

  return 0;
}
```

From the main repository folder, you can run all the tests with

```bash
scons test
```

Or from this folder with

```bash
scons test -C ..
```
