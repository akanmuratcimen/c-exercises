#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

int main() {
  int values[] = { 1, 1, 2, 2, 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7 };
  node_t* head = convert_to_linkedlist(values, sizeof(values) / sizeof(int));

  linkedlist_remove_duplicates(head);

  linkedlist_print(head);
  linkedlist_clear(&head);

  return EXIT_SUCCESS;
}
