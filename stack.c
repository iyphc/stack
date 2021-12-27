#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

const unsigned long long canary = 15000987876788768;

stack* construct() {
  stack* stack = (struct stack*)calloc(1, sizeof(stack));
  stack->size = 4; // не работает при size < 4
  stack->pointer = -1;
  stack->status = OK;
  elem_t* arr = (elem_t*)calloc(stack->size+1, sizeof(elem_t));
  arr[stack->pointer+1] = (elem_t)canary;
  (stack->arr) = arr;
  return stack;
}

void push(stack* stack, elem_t elem) {
  if (verify(stack) != OK) {
    //stack->arr[stack->pointer+1] = (elem_t)canary;
    return;
  }
  stack->pointer++;
  stack->arr[stack->pointer] = elem;
  stack->arr[stack->pointer+1] = (elem_t)canary;
  resize_up(stack);
  if (verify(stack) != OK) {
    //stack->arr[stack->pointer+1] = (elem_t)canary;
    return;
  }
}

elem_t pop(stack* stack) {
  if (verify(stack) != OK) {
    //stack->arr[stack->pointer+1] = (elem_t)canary;
    return (elem_t)-10e7;
  }
  if(stack->pointer >= 0) {
    elem_t temp = stack->arr[stack->pointer];
    stack->arr[stack->pointer--] = (elem_t)canary;
    return temp;
  }
  if (verify(stack) != OK) {
    //stack->arr[stack->pointer+1] = (elem_t)canary;
    return (elem_t)-10e7;
  }
  return (elem_t)-10e7;
} 

Exceptions verify(stack* stack) {
  if(stack->arr[stack->pointer+1] != (elem_t)canary) {
    stack->status = size_problem;
    return size_problem;
  }
  stack->status = OK;
  return OK;
}


void resize_up(stack* stack) {
  if(stack->pointer+1 == stack->size) {
    stack->arr = realloc(stack->arr, sizeof(elem_t)*(stack->size)*2+1);
    stack->size*=2;
  }
}

void resize_down(stack* stack) {
  if(stack->size > 4) {
    stack->arr = realloc(stack->arr, sizeof(elem_t)*((stack->size)/2)+1);
    stack->size/=2;
    stack->arr[stack->size] = (elem_t)canary;
    stack->pointer = stack->size - 1;
  }
}