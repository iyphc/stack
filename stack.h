#include <stdio.h>
#include <assert.h>

typedef enum Exceptions {
  OK,
  size_problem,
  hash_problem  
} Exceptions;

typedef int elem_t;

typedef struct stack {
  int size;
  int pointer;
  int hash;
  Exceptions status;
  elem_t* arr;
} stack;

const unsigned long long canary = 15000987876788768;

stack* construct();
void push(stack* stack, elem_t elem);
elem_t pop(stack* stack);
Exceptions verify(stack* stack);
void resize_up(stack* stack);
void resize_down(stack* stack);
int MurmurHash2 (stack* stack);
Exceptions hash_verify(stack* stack); //выключена