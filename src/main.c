#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

int main() {
  int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  size_t size = sizeof(values) / sizeof(int);
  node_t* node = convert_to_linkedlist(values, size);

  linkedlist_reverse(&node);
  linkedlist_print(node);
  linkedlist_clear(&node);

  return EXIT_SUCCESS;
}
