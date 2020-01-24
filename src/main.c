#include <stdio.h>
#include <stdlib.h>

#include "stack_int.h"

int main() {
  stack_int_t* stack = stack_int_initialize(10);

  stack_int_push(stack, 1);
  stack_int_push(stack, 2);
  stack_int_push(stack, 3);
  stack_int_push(stack, 4);
  stack_int_push(stack, 5);
  stack_int_push(stack, 6);
  stack_int_push(stack, 7);

  printf("top: %d\n", stack_int_peek(stack));

  stack_int_pop(stack);

  printf("top: %d\n", stack_int_peek(stack));

  stack_int_print(stack);
  stack_int_clear(&stack);

  return EXIT_SUCCESS;
}
