#include <stdlib.h>
#include "tree_node.h"

struct tree_node* tree_node_create(int value) {
  struct tree_node* node = (struct tree_node*)malloc(sizeof(struct tree_node));

  node->left = NULL;
  node->right = NULL;
  node->value = value;
  
  return node;
}
