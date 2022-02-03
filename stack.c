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
  stack->hash = MurmurHash2(stack);
  return stack;
}

void push(stack* stack, elem_t elem) {
  if (verify(stack) != OK || hash_verify(stack) != OK) {
    return;
  }
  stack->pointer++;
  stack->arr[stack->pointer] = elem;
  stack->arr[stack->pointer+1] = (elem_t)canary;
  resize_up(stack);
  stack->hash = MurmurHash2(stack);
  if (verify(stack) != OK || hash_verify(stack) != OK) {
    return;
  }
}

elem_t pop(stack* stack) {
  if (verify(stack) != OK || hash_verify(stack) != OK) {
    return (elem_t)-10e7;
  }
  if(stack->pointer >= 0) {
    elem_t temp = stack->arr[stack->pointer];
    stack->arr[stack->pointer] = (elem_t)canary;
    stack->pointer--;
    stack->hash = MurmurHash2(stack);
    return temp;
  }
  printf("\n\n");
  if (verify(stack) != OK || hash_verify(stack) != OK) {
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

Exceptions hash_verify(stack* stack) {
  if(stack->hash != MurmurHash2(stack)) {
    stack->status = hash_problem;
    return hash_problem;
  }
  stack->status = OK;
  return OK;
}

void resize_up(stack* stack) {
  if(stack->pointer+1 == stack->size) {
    stack->arr = realloc(stack->arr, sizeof(elem_t)*(stack->size)*2+1);
    stack->size*=2;
  }
  stack->hash = MurmurHash2(stack);
}

void resize_down(stack* stack) {
  if(stack->size > 4) {
    stack->arr = realloc(stack->arr, sizeof(elem_t)*((stack->size)/2)+1);
    stack->size/=2;
    stack->arr[stack->size] = (elem_t)canary;
    stack->pointer = stack->size - 1;
    stack->hash = MurmurHash2(stack);
  }
}

int MurmurHash2 (stack* stack)
{
  const unsigned int m = 0x5bd1e995;
  const unsigned int seed = 0;
  const int r = 24;
  unsigned int len = stack->pointer+1;

  unsigned int h = seed ^ len;

  elem_t * data = stack->arr;
  unsigned int k = 0;

  while (len >= 4)
  {
      k  = data[0];
      k |= data[1] << 8;
      k |= data[2] << 16;
      k |= data[3] << 24;

      k *= m;
      k ^= k >> r;
      k *= m;

      h *= m;
      h ^= k;

      data += 4;
      len -= 4;
  }

  switch (len)
  {
    case 3:
      h ^= data[2] << 16;
    case 2:
      h ^= data[1] << 8;
    case 1:
      h ^= data[0];
      h *= m;
  };

  h ^= h >> 13;
  h *= m;
  h ^= h >> 15;

  return h;
}