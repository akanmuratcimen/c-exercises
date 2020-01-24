#ifndef STACK_INT_H
#define STACK_INT_H

#include <stdbool.h>

typedef struct stack_int_node_t {
  int value;
  struct stack_int_node_t* next;
} stack_int_node_t;

typedef struct stack_int_t {
  int length;
  stack_int_node_t* top;
} stack_int_t;

stack_int_t* stack_int_initialize();
stack_int_node_t* stack_int_push(stack_int_t* stack, int value);
void stack_int_print(stack_int_t* stack);
bool stack_int_is_empty(stack_int_t* stack);
bool stack_int_pop(stack_int_t* stack, int* value);

#endif // STACK_INT_H
