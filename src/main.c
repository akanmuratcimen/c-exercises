#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

int main() {
  int values[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
  size_t size = sizeof(values) / sizeof(int);
  node_t* node = convert_to_linkedlist(values, size);
  node_t* intersetion = linkedlist_intersection_node(node);

  if (intersetion != NULL) {
    printf("has_intersection: %d\n", intersetion->value);
  }

  linkedlist_clear(&node);

  return EXIT_SUCCESS;
}
