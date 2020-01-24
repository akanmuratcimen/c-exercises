#include <stdio.h>
#include <stdlib.h>

#include "stack_int.h"

int main() {
  stack_int_t* stack_int = stack_int_initialize();

  stack_int_push(stack_int, 1);
  stack_int_push(stack_int, 2);
  stack_int_push(stack_int, 3);
  stack_int_push(stack_int, 4);
  stack_int_push(stack_int, 5);
  stack_int_push(stack_int, 6);
  stack_int_push(stack_int, 7);

  stack_int_print(stack_int);

  int value = 0;

  stack_int_pop(stack_int, &value);
  stack_int_pop(stack_int, &value);
  stack_int_pop(stack_int, &value);
  stack_int_pop(stack_int, &value);
  stack_int_pop(stack_int, &value);
  stack_int_pop(stack_int, &value);
  stack_int_pop(stack_int, &value);
  stack_int_pop(stack_int, &value);

  stack_int_print(stack_int);

  return EXIT_SUCCESS;
}
