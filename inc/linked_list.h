#pragma once

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int value;
  struct node_t* next;
} node_t;

void linked_list_print(node_t* head);
void linked_list_clear(node_t** head_node);

node_t* linked_list_new_node(int value);
node_t* linked_list_push_back(node_t* node, int value);
node_t* convert_to_linked_list(int* values, size_t length);