#include "stack_int.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

stack_int_t* stack_int_initialize(int capacity) {
  stack_int_t* stack = (stack_int_t*)malloc(sizeof(stack_int_t));

  stack->size = 0;
  stack->capacity = capacity;
  stack->entries = malloc(sizeof(stack_int_entry_t) * capacity);

  for (int i = 0; i < capacity; ++i) {
    stack->entries[i] = NULL;
  }

  return stack;
}

stack_int_entry_t* stack_int_create_entry(int value, int min_value) {
  stack_int_entry_t* entry = malloc(sizeof(stack_int_entry_t));

  entry->value = value;
  entry->min_value = min_value;

  return entry;
}

void stack_int_push(stack_int_t* stack, int value) {
  if (stack_int_is_full(stack)) {
    puts("stack is full.");
    exit(EXIT_FAILURE);
  }

  int min_value = stack_int_min(stack);

  if (min_value > value) {
    min_value = value;
  }

  stack_int_entry_t* entry = stack_int_create_entry(value, min_value);
  stack->entries[stack->size++] = entry;
}

bool stack_int_is_empty(stack_int_t* stack) {
  return stack->size == 0;
}

bool stack_int_is_full(stack_int_t* stack) {
  return stack->size == stack->capacity;
}

int stack_int_peek(stack_int_t* stack) {
  if (stack_int_is_empty(stack)) {
    puts("stack is empty.");
    exit(EXIT_FAILURE);
  }

  return stack->entries[stack->size - 1]->value;
}

int stack_int_pop(stack_int_t* stack) {
  if (stack_int_is_empty(stack)) {
    puts("stack is empty.");
    exit(EXIT_FAILURE);
  }

  stack_int_entry_t* entry = stack->entries[stack->size - 1];
  int value = entry->value;

  stack->entries[--stack->size] = 0;
  free(entry);

  return value;
}

int stack_int_min(stack_int_t* stack) {
  if (stack_int_is_empty(stack)) {
    return INT_MAX;
  }

  return stack->entries[stack->size - 1]->min_value;
}

void stack_int_print(stack_int_t* stack) {
  if (stack_int_is_empty(stack)) {
    return;
  }

  for (int i = stack->size - 1; i >= 0; --i) {
    printf("%d ", stack->entries[i]->value);
  }

  printf("\n");
}

void stack_int_clear(stack_int_t** stack) {
  for (int i = 0; i < (*stack)->capacity; ++i) {
    free((*stack)->entries[i]);
  }

  free((*stack)->entries);
  free(*stack);

  *stack = NULL;
}
