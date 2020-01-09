#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <assert.h>
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
node_t* convert_to_linkedlist(const int* const values, const size_t length);
void linkedlist_remove_duplicates(const node_t* node);

#endif // LINKEDLIST_H
