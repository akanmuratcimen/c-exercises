#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main() {

  node_t* loop = linkedlist_new_node(3);
  loop->next = linkedlist_new_node(4);
  loop->next->next = loop;

  node_t* head = linkedlist_new_node(1);
  head->next = linkedlist_new_node(2);
  head->next->next = loop;

  node_t* found_loop = linkedlist_get_loop_node(head);

  if (found_loop) {
    printf("found loop: %d\n", found_loop->value);
  }

  linkedlist_clear(&head);

  return EXIT_SUCCESS;
}
