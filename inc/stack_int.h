#ifndef STACK_INT_H
#define STACK_INT_H

#include <stdbool.h>

typedef struct stack_int_entry_t {
  int value;
  int min_value;
} stack_int_entry_t;

typedef struct stack_int_t {
  int size;
  int capacity;
  stack_int_entry_t** entries;
} stack_int_t;

stack_int_t* stack_int_initialize(int capacity);
void stack_int_push(stack_int_t* stack, int value);
void stack_int_print(stack_int_t* stack);
void stack_int_print_reverse(stack_int_t* stack);
bool stack_int_is_empty(stack_int_t* stack);
bool stack_int_is_full(stack_int_t* stack);
int stack_int_peek(stack_int_t* stack);
int stack_int_pop(stack_int_t* stack);
int stack_int_min(stack_int_t* stack);
void stack_int_clear(stack_int_t** stack);

#endif // STACK_INT_H
