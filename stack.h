#include <stdio.h>
#include <assert.h>

typedef enum Exceptions {
  OK,
  size_problem  
} Exceptions;

typedef int elem_t;

typedef struct stack {
  int size;
  int pointer;
  Exceptions status;
  elem_t* arr;
} stack;

const unsigned long long canary;

stack* construct();
void push(stack* stack, elem_t elem);
elem_t pop(stack* stack);
Exceptions verify(stack* stack);
void resize_up(stack* stack);
void resize_down(stack* stack);