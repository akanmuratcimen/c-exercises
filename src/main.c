#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

int main() {
  int values1[] = { 7, 1, 6 };
  int values2[] = { 5, 9, 2 };

  node_t* node1 = convert_to_linkedlist(values1, sizeof(values1) / sizeof(int));
  node_t* node2 = convert_to_linkedlist(values2, sizeof(values2) / sizeof(int));

  node_t* node = linkedlist_sum_reversed_order(node1, node2);

  linkedlist_clear(&node1);
  linkedlist_clear(&node2);

  linkedlist_print(node);
  linkedlist_clear(&node);

  return EXIT_SUCCESS;
}
