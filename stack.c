#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

const unsigned long long canary = 15000987876788768;

stack* construct() {
  stack* stack = (struct stack*)calloc(1, sizeof(stack));
  stack->size = 10;
  stack->pointer = -1;
  Exceptions status = OK;
  elem_t* arr = (elem_t*)calloc(stack->size+1, sizeof(elem_t));
  arr[stack->size+1] = (elem_t)canary;
  (stack->arr) = arr;
  return stack;
}

void push(stack* stack, elem_t elem) {
  if (verify(stack) != OK) {
    return;
  }
  if (stack->size - 1 > stack->pointer) {
    stack->pointer++;
    stack->arr[stack->pointer] = elem;
  }
  else {
    stack->status = size_problem;
  }
  if (verify(stack) != OK) {
    return;
  }
}

elem_t pop(stack* stack) {
  if (verify(stack) != OK) {
    return (elem_t)-10e7;
  }
  if(stack->pointer >= 0) {
    return stack->arr[stack->pointer--];
  }
  if (verify(stack) != OK) {
    return (elem_t)-10e7;
  }
  return (elem_t)-10e7;
} 

Exceptions verify(stack* stack) {
  if(stack->arr[stack->size+1] != (elem_t)canary) {
    stack->status = size_problem;
    return size_problem;
  }
  stack->status = OK;
  return OK;
}
