#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

int main() {
  int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  node_t* head = convert_to_linkedlist(values, sizeof(values) / sizeof(int));
  node_t* node = linkedlist_last_kth_element(head, 2);

  if (node) {
    printf("%d\n", node->value);
  }

  linkedlist_clear(&head);

  return EXIT_SUCCESS;
}
