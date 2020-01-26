#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  struct node_t* next;
  int value;
} node_t;

void linkedlist_print(const node_t* head);
void linkedlist_clear(node_t** head_node);

node_t* linkedlist_new_node(const int value);
node_t* linkedlist_push_back(node_t* node, const int value);
node_t* convert_to_linkedlist(const int* values, const size_t length);
void linkedlist_remove_duplicates(node_t* node);
void linkedlist_remove_by_value(node_t** node, const int value);
int linkedlist_print_last_kth_element(node_t* head, int k);
node_t* linkedlist_last_kth_element(node_t* head, int k);
node_t* linkedlist_last_kth_element_itr(node_t* head, int k);
node_t* linkedlist_sum_reversed_order(node_t* node1, node_t* node2);
bool linkedlist_is_palindrome_reversed_check(node_t* head);
void linkedlist_reverse(node_t** head);
node_t* linkedlist_copy(node_t* head);
int linkedlist_length(node_t* head);
bool linkedlist_is_palindrome_recursive(node_t* head);
node_t* linkedlist_intersection_node(node_t* head1, node_t* head2);
node_t* linkedlist_get_loop_node(node_t* head);
node_t* linkedlist_index_partition_odd_even(node_t* head);

#endif // LINKEDLIST_H
