#include <stdio.h>
#include "stack.h"

int main() {
 stack* stack = construct();
 push(stack, 10);
 push(stack, 20);
 push(stack, 30);
 push(stack, 40);
 elem_t a = pop(stack);
 printf("%d\n", (int)a);
 return 0; 
}