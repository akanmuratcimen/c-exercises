#include <stdio.h>
#include <stdlib.h>

#include "stack_int.h"

int main() {
  stack_int_t* stack = stack_int_initialize(5);

  stack_int_push(stack, -1);
  stack_int_push(stack, 2);
  stack_int_push(stack, -4);
  stack_int_push(stack, 6);
  stack_int_push(stack, 7);
  stack_int_push(stack, -8);
  stack_int_push(stack, 3);
  stack_int_push(stack, -5);
  stack_int_push(stack, -21);

  printf("%d\n", stack_int_min(stack));

  stack_int_pop(stack);

  printf("%d\n", stack_int_min(stack));

  stack_int_pop(stack);
  stack_int_pop(stack);
  stack_int_pop(stack);

  printf("%d\n", stack_int_min(stack));

  stack_int_clear(&stack);

  return EXIT_SUCCESS;
}
