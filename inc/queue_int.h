#ifndef QUEUE_INT_H
#define QUEUE_INT_H

#include <stdbool.h>

typedef struct queue_int_t {
  int* values;
  int size;
  int head;
  int tail;
  int capacity;
} queue_int_t;

queue_int_t* queue_int_initialize(const int size);
void queue_int_enqueue(queue_int_t* queue, const int value);
void queue_int_dequeue(queue_int_t* queue);
int queue_int_peek(queue_int_t* queue);
bool queue_int_is_empty(queue_int_t* queue);
bool queue_int_is_full(queue_int_t* queue);
void queue_int_print(queue_int_t* queue);
void queue_int_clear(queue_int_t** queue);

#endif // QUEUE_INT_H
