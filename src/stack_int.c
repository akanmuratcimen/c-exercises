#include "stack_int.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

stack_int_t* stack_int_initialize() {
  stack_int_t* stack = (stack_int_t*)malloc(sizeof(stack_int_t));

  stack->length = 0;
  stack->top = NULL;

  return stack;
}

stack_int_node_t* stack_int_push(stack_int_t* stack, int value) {
  stack_int_node_t* node = (stack_int_node_t*)malloc(sizeof(stack_int_node_t));

  node->value = value;
  node->next = stack->top;

  stack->top = node;
  stack->length++;

  return node;
}

bool stack_int_is_empty(stack_int_t* stack) {
  return stack->length == 0;
}

bool stack_int_pop(stack_int_t* stack, int* value) {
  if (stack_int_is_empty(stack)) {
    return false;
  }

  stack_int_node_t* next = stack->top->next;

  *value = stack->top->value;

  free(stack->top);

  stack->top = next;
  stack->length--;

  return true;
}

void stack_int_print(stack_int_t* stack) {
  if (stack_int_is_empty(stack)) {
    return;
  }

  printf("size: %d\n", stack->length);

  stack_int_node_t* node = stack->top;

  while (node) {
    printf("%d ", node->value);
    node = node->next;
  }

  printf("\n");
}
