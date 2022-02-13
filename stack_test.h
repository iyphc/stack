#include <stdio.h>

typedef enum test_exceptions {
  complete,
  failure  
} test_exceptions;

test_exceptions test_hash_verify();
test_exceptions test_resize_down();
test_exceptions test_resize_up();
test_exceptions test_construct();
test_exceptions test_verify();
test_exceptions test_push();
test_exceptions test_pop();
void run_all_tests();