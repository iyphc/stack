#include <stdio.h>
#include "stack.h"
//#include "stack_test.h"

/**  
 * @file main.c
 * @brief Contains main function
*/

int main() {
 stack* stack = construct();
 printf("LOL\n");
 stack->hash = MurmurHash2(stack);
 for(int i = 0; i < 14; i++) {
  push(stack, (i+1)*10);
 }

 while(stack->pointer >= 0) {
  printf("%d\n", (elem_t)pop(stack));
 }
 //run_all_tests();
 return 0; 
}
