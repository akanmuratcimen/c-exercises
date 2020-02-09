#ifndef TREE_NODE_H
#define TREE_NODE_H

struct tree_node {
  int value;
  struct tree_node* left;
  struct tree_node* right;
};

struct tree_node* tree_node_create(int value);

#endif // TREE_NODE_H
