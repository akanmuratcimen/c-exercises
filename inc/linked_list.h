#pragma once

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int value;
  struct node_t* next;
} node_t;

void linked_list_print(const node_t* head);
void linked_list_clear(node_t** head_node);

node_t* linked_list_new_node(const int value);
node_t* linked_list_push_back(node_t* node, const int value);
node_t* convert_to_linked_list(const int* const values, const size_t length);
