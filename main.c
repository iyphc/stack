#include <stdio.h>
#include "stack.h"
#include "stack_test.h"

/**  
 * @file main.c
 * @brief Contains main function
*/

int main() {
 stack* stack = construct();
 for(int i = 0; i < 14; i++) {
  push(stack, (i+1)*10);
 }
 resize_down(stack);
 for(int i = 0; i < stack->size; i++) {
  printf("%d\n", (elem_t)pop(stack));
 }
 run_all_tests();
 return 0; 
}