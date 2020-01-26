#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main() {
  int values[] = { 2, 1, 3, 5, 6, 4, 7 };
  size_t size = sizeof(values) / sizeof(values[0]);
  node_t* linkedlist = convert_to_linkedlist(values, size);

  node_t* partitioned = linkedlist_index_partition_odd_even(linkedlist);

  linkedlist_print(partitioned);
  linkedlist_clear(&partitioned);

  return EXIT_SUCCESS;
}
