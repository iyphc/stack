#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack* construct() {
  stack* stack;
  stack->size = 10;
  stack->pointer = -1;
  elem_t* arr = (elem_t*)calloc(stack->size, sizeof(elem_t));
  (stack->arr) = arr;
  return stack;
}

void push(stack* stack, elem_t elem) {
  if (stack->size - 1 > stack->pointer) {
    stack->pointer++;
    stack->arr[stack->pointer] = elem;
  }
  else {
    stack->status = size_problem;
  }
}

elem_t pop(stack* stack) {
  if(stack->pointer >= 0) {
    return stack->arr[stack->pointer--];
  }
  else {
    return (elem_t)-10e7;
  }
} 
