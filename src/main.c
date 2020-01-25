#include <stdio.h>
#include <stdlib.h>

#include "queue_int.h"

int main() {
  queue_int_t* queue = queue_int_initialize(10);

  queue_int_enqueue(queue, 1);
  queue_int_enqueue(queue, 2);
  queue_int_enqueue(queue, 3);
  queue_int_enqueue(queue, 4);
  queue_int_enqueue(queue, 5);

  queue_int_dequeue(queue);
  queue_int_dequeue(queue);

  printf("peek: %d\n", queue_int_peek(queue));

  queue_int_enqueue(queue, 6);

  queue_int_print(queue);
  queue_int_clear(&queue);

  return EXIT_SUCCESS;
}
