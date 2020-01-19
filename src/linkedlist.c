#include <stdbool.h>

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
  node_t* node = (node_t*)malloc(sizeof(node_t));

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

int linkedlist_print_last_kth_element(node_t* head, int k) {
  if (head == NULL) {
    return 0;
  }

  if (k == 0) {
    k = 1;
  }

  int index = linkedlist_print_last_kth_element(head->next, k) + 1;

  if (index == k) {
    printf("%dth last element: %d\n", k, head->value);
  }

  return index;
}

node_t* linkedlist_last_kth_element_impl(node_t* node, int k, int* i) {
  if (node == NULL) {
    return NULL;
  }

  node_t* x = linkedlist_last_kth_element_impl(node->next, k, i);

  return ++(*i) == k ? node : x;
}

node_t* linkedlist_last_kth_element(node_t* head, int k) {
  node_t* current = head;
  int i = 0;

  if (k == 0) {
    k = 1;
  }

  return linkedlist_last_kth_element_impl(current, k, &i);
}

node_t* linkedlist_last_kth_element_itr(node_t* head, int k) {
  if (k == 0) {
    k = 1;
  }

  node_t* node_ptr1 = head;

  while (k--) {
    if (node_ptr1 == NULL) {
      return NULL;
    }

    node_ptr1 = node_ptr1->next;
  }

  node_t* node_ptr2 = head;

  while (node_ptr1) {
    node_ptr1 = node_ptr1->next;
    node_ptr2 = node_ptr2->next;
  }

  return node_ptr2;
}

node_t* linkedlist_sum_reversed_order(node_t* node1, node_t* node2) {
  node_t *head = NULL, *tail = NULL;

  int carry = 0;

  while (node1 || node2) {
    int total = carry;

    if (node1) {
      total += node1->value;
      node1 = node1->next;
    }

    if (node2) {
      total += node2->value;
      node2 = node2->next;
    }

    carry = total > 10 ? 1 : 0;
    total = total % 10;

    if (head == NULL) {
      head = tail = linkedlist_new_node(total);
    } else {
      tail->next = linkedlist_new_node(total);
      tail = tail->next;
    }
  }

  if (carry > 1) {
    tail->next = linkedlist_new_node(carry);
  }

  return head;
}

void linkedlist_reverse(node_t** head) {
  node_t *current = *head, *prev = NULL, *next = NULL;

  while (current) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  *head = prev;
}

bool linkedlist_is_palindrome(node_t* head) {
  return head != NULL;
}
