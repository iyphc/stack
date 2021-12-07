#include <stdio.h>

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

stack* construct();
void push(stack* stack, elem_t elem);
elem_t pop(stack* stack);