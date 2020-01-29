#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "set_of_stacks_int.h"

set_of_stacks_int_stack_t* set_of_stacks_int_create_stack(int capacity) {
  set_of_stacks_int_stack_t* stack = malloc(sizeof(set_of_stacks_int_stack_t));

  stack->size = 0;
  stack->capacity = capacity;
  stack->values = malloc(sizeof(int) * capacity);

  return stack;
}

set_of_stacks_int_t* set_of_stacks_int_initialize(int single_stack_capacity) {
  set_of_stacks_int_t* stack = malloc(sizeof(set_of_stacks_int_t));

  stack->single_stack_capacity = single_stack_capacity;
  stack->stacks = malloc(sizeof(set_of_stacks_int_t));

  stack->stacks[0] = set_of_stacks_int_create_stack(single_stack_capacity);

  return stack;
}
