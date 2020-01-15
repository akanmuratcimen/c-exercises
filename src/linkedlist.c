#include "linkedlist.h"
#include "map_int.h"
#include "utility.h"

void linkedlist_print(const node_t* head) {
  while (head != NULL) {
    printf("%d ", head->value);
    head = head->next;
  }

  printf("\n");
}

node_t* linkedlist_new_node(const int value) {
  node_t* node = NULL;
  node = (node_t*)malloc(sizeof(node_t));

  if (node == NULL) {
    return NULL;
  }

  node->value = value;
  node->next = NULL;

  return node;
}

node_t* linkedlist_push_back(node_t* node, const int value) {
  node_t* result = linkedlist_new_node(value);

  if (node == NULL) {
    return result;
  }

  node_t* previous_next = node->next;

  node->next = result;
  node->next->next = previous_next;

  return result;
}

void linkedlist_clear(node_t** head_node) {
  while (*head_node) {
    node_t* next = (*head_node)->next;
    free(*head_node);
    *head_node = next;
  }

  assert(*head_node == NULL);
}

node_t* convert_to_linkedlist(const int* values, const size_t length) {
  node_t* head = NULL;
  node_t* tail = NULL;

  for (size_t i = 0; i < length; i++) {
    if (head == NULL) {
      head = tail = linkedlist_push_back(head, values[i]);
      continue;
    }

    tail = linkedlist_push_back(tail, values[i]);
  }

  return head;
}

void linkedlist_remove_duplicates(node_t* node) {
  map_int_t* map = map_int_create(0);
  node_t* prev = NULL;

  while (node) {
    if (map_int_is_key_exists(map, node->value)) {
      node_t* next = node->next;
      prev->next = next;
      free(node);
      node = next;

      continue;
    }

    map_int_inc_value(map, node->value);

    prev = node;
    node = node->next;
  }

  map_int_destroy(map);
}

void linkedlist_remove_by_value(node_t** node, const int value) {
  if (node == NULL) {
    return;
  }

  node_t* prev = NULL;
  node_t* current = *node;

  while (current) {
    if (current->value != value) {
      prev = current;
      current = current->next;

      continue;
    }

    node_t* next = current->next;

    if (prev) {
      prev->next = next;
    } else {
      *node = next;
    }

    free(current);
    current = next;
  }
}
