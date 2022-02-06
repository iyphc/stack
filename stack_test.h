#include <stdio.h>

typedef enum test_Exceptions {
  complete,
  failure  
} test_Exceptions;

test_Exceptions test_hash_verify();
test_Exceptions test_resize_down();
test_Exceptions test_resize_up();
test_Exceptions test_construct();
test_Exceptions test_verify();
test_Exceptions test_push();
test_Exceptions test_pop();
void run_all_tests() ;