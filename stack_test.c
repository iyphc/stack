#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stack_test.h"

test_Exceptions test_construct() {
  stack* stack = construct();
  if (stack == NULL || stack->size != 4 || stack->pointer != -1) {
    free(stack);
    return failure;
  }
  if (stack->status != OK || stack->arr == NULL || stack->arr[stack->pointer+1] != (elem_t)canary) {
    free(stack);
    return failure;
  }
  free(stack);
  return complete;
}

test_Exceptions test_verify() {
  stack* stack = construct();
  if(stack->arr[stack->pointer+1] != (elem_t)canary) {
    free(stack);
    return failure;
  }
  stack->arr[stack->pointer+1] = 11;
  if(stack->arr[stack->pointer+1] == (elem_t)canary) {
    free(stack);
    return failure;
  }  
  free(stack);
  return complete;
}

test_Exceptions test_push() {
  stack* stack = construct();
  push(stack, 10);
  if (stack->pointer != 0 || stack->arr[stack->pointer] != 10 || stack->status != OK || stack->arr[stack->pointer+1] != (elem_t)canary) {
    free(stack);
    return failure;
  }
  stack->arr[stack->pointer+1] = 11;
  push(stack, 20);
  if (stack->arr[stack->pointer] == 20 && stack->status != size_problem) {
    free(stack);
    return failure;
  }
  free(stack);
  return complete;
}

test_Exceptions test_pop() {
  stack* stack = construct();
  push(stack, 100);
  elem_t temp = pop(stack);
  if(temp != 100 || stack->pointer != -1 || stack->status != OK || stack->arr[stack->pointer+1] != (elem_t)canary) {
    free(stack);
    return failure;
  }
  temp = pop(stack);
  if(temp != (elem_t)-10e7) {
    free(stack);
    return failure;
  }
  free(stack);
  return complete;
}

test_Exceptions test_resize_up() {
  stack* stack = construct();
  int temp_size = stack->size;
  for(int i = 0; i < 5; i++) {
    push(stack, i+1);
  }
  if(temp_size*2 != stack->size) {
    free(stack);
    return failure;
  }
  free(stack);
  return complete;
} 

test_Exceptions test_resize_down() {
  stack* stack = construct();
  for(int i = 0; i < 8; i++) {
    push(stack, i+1);
  }
  int temp_size = stack->size;
  resize_down(stack);
  if(temp_size/2 != stack->size || stack->arr[stack->pointer+1] != (elem_t)canary) {
    free(stack);
    return failure;
  }
  free(stack);
  return complete;
} 

void run_all_tests() {
  assert(test_construct() == complete);
  assert(test_verify() == complete);
  assert(test_push() == complete);
  assert(test_pop() == complete);
  assert(test_resize_up() == complete);
  assert(test_resize_down() == complete);
  printf("\nALL TESTS PASSED!\n");
}