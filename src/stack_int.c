#include "stack_int.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

stack_int_t* stack_int_initialize(int size) {
  stack_int_t* stack = (stack_int_t*)malloc(sizeof(stack_int_t));

  stack->size = 0;
  stack->values = malloc(sizeof(int) * size);

  return stack;
}

void stack_int_push(stack_int_t* stack, int value) {
  stack->values[stack->size++] = value;
}

bool stack_int_is_empty(stack_int_t* stack) {
  return stack->size == 0;
}

int stack_int_peek(stack_int_t* stack) {
  return stack->values[stack->size - 1];
}

int stack_int_pop(stack_int_t* stack) {
  if (stack_int_is_empty(stack)) {
    return -1;
  }

  int value = stack_int_peek(stack);

  stack->values[--stack->size] = 0;

  return value;
}

void stack_int_print(stack_int_t* stack) {
  if (stack_int_is_empty(stack)) {
    return;
  }

  for (int i = stack->size - 1; i >= 0; --i) {
    printf("%d ", stack->values[i]);
  }

  printf("\n");
}

void stack_int_clear(stack_int_t** stack) {
  free((*stack)->values);
  free(*stack);

  *stack = NULL;
}
