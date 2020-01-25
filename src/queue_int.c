#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "queue_int.h"

queue_int_t* queue_int_initialize(const int capacity) {
  queue_int_t* queue = malloc(sizeof(queue_int_t));

  queue->size = 0;
  queue->head = 0;
  queue->tail = -1;
  queue->capacity = capacity;
  queue->values = malloc(sizeof(int) * capacity);

  return queue;
}

void queue_int_enqueue(queue_int_t* queue, const int value) {
  queue->values[++queue->tail] = value;
  queue->size++;
}

void queue_int_dequeue(queue_int_t* queue) {
  queue->values[queue->head++] = 0;
  queue->size--;
}

void queue_int_print(queue_int_t* queue) {
  if (queue->size == 0) {
    return;
  }

  for (int i = queue->head; i <= queue->tail; i++) {
    printf("%d ", queue->values[i]);
  }

  printf("\n");
}

int queue_int_peek(queue_int_t* queue) {
  return queue->values[queue->head];
}

bool queue_int_is_empty(queue_int_t* queue) {
  return queue->size == 0;
}

bool queue_int_is_full(queue_int_t* queue) {
  return queue->size == queue->capacity;
}

void queue_int_clear(queue_int_t** queue) {
  free((*queue)->values);
  free(*queue);

  *queue = NULL;
}
