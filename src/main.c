#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main() {

  node_t* intersection_node = linkedlist_new_node(8);
  intersection_node->next = linkedlist_new_node(9);

  node_t* head1 = linkedlist_new_node(1);
  head1->next = linkedlist_new_node(2);
  head1->next->next = linkedlist_new_node(3);
  head1->next->next->next = intersection_node;

  node_t* head2 = linkedlist_new_node(1);
  head2->next = linkedlist_new_node(2);
  head2->next->next = intersection_node;

  node_t* intersection = linkedlist_intersection_node(head1, head2);

  if (intersection) {
    printf("has_intersection: %d\n", intersection->value);
  }

  linkedlist_clear(&head1);
  linkedlist_clear(&head2);

  return EXIT_SUCCESS;
}
