#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms.h"
#include "tree_node.h"

int main() {
  struct tree_node* p = tree_node_create(1);

  p->left = tree_node_create(2);
  p->right = tree_node_create(3);

  struct tree_node* q = tree_node_create(1);

  q->left = tree_node_create(2);
  q->right = tree_node_create(3);

  printf("is_same_tree: %d\n", is_same_tree(p, q));

  return EXIT_SUCCESS;
}
