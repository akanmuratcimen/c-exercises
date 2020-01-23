#ifndef STACK_INT_H
#define STACK_INT_H

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

#endif // STACK_INT_H
