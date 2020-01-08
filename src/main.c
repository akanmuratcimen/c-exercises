#include "linked_list.h"

int main() {
  int values[] = { 1, 2, 3, 4, 5 };
  node_t* head = convert_to_linked_list(values, sizeof(values) / sizeof(int));

  linked_list_print(head);
  linked_list_clear(&head);

  return 0;
}
