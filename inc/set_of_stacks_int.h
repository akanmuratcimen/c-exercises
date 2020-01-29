#ifndef SET_OF_STACKS_INT_H
#define SET_OF_STACKS_INT_H

#include <stdbool.h>

typedef struct set_of_stacks_int_stack_t {
  int size;
  int capacity;
  int* values;
} set_of_stacks_int_stack_t;

typedef struct set_of_stacks_int_t {
  int single_stack_capacity;
  set_of_stacks_int_stack_t** stacks;
} set_of_stacks_int_t;

set_of_stacks_int_t* set_of_stacks_int_initialize(int capacity);
void set_of_stacks_int_push(set_of_stacks_int_t* stack, int value);
int set_of_stacks_int_peek(set_of_stacks_int_t* stack);
int set_of_stacks_int_pop(set_of_stacks_int_t* stack);
bool set_of_stacks_int_is_empty(set_of_stacks_int_t* stack);
bool set_of_stacks_int_is_full(set_of_stacks_int_t* stack);
void set_of_stacks_int_print(set_of_stacks_int_t* stack);
void set_of_stacks_int_clear(set_of_stacks_int_t** stack);

#endif // SET_OF_STACKS_INT_H
