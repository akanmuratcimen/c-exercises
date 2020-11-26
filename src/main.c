#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack_int.h"

struct node {
  int value;
  struct node* left;
  struct node* right;
};

struct node*
new_node(
  const int value
) {
  struct node* node = malloc(sizeof(struct node));

  node->value = value;
  node->left = NULL;
  node->right = NULL;

  return node;
}

void
print_pre_order(
  const struct node *const node
) {
  if (!node) {
    return;
  }

  printf("%d ", node->value);
  print_pre_order(node->left);
  print_pre_order(node->right);
}

void
print_in_order(
  const struct node *const node
) {
  if (!node) {
    return;
  }

  print_in_order(node->left);
  printf("%d ", node->value);
  print_in_order(node->right);
}

void
print_post_order(
  const struct node *const node
) {
  if (!node) {
    return;
  }

  print_post_order(node->left);
  print_post_order(node->right);
  printf("%d ", node->value);
}

void
delete_node(
  struct node *const node
) {
  if (!node) {
    return;
  }

  delete_node(node->left);
  delete_node(node->right);

  free(node);
}

size_t
get_height(
  const struct node *const node
) {
  if (!node) {
    return 0;
  }

  size_t left_height = get_height(node->left);
  size_t right_height = get_height(node->right);

  return left_height > right_height ?
    left_height + 1 : right_height + 1;
}

void
print_level_by_level(
  const struct node *const node,
  int *const *const rows,
  int *const cols,
  const size_t lvl
) {
  if (!node) {
    return;
  }

  print_level_by_level(node->left, rows, cols, lvl + 1);
  print_level_by_level(node->right, rows, cols, lvl + 1);

  rows[lvl][cols[lvl]++] = node->value;
}

void
print_levels(
  const struct node *const node
) {
  int** rows = calloc(10, sizeof(void*));
  int* cols = calloc(10, sizeof(int));

  for (int i = 0; i < 10; ++i) {
    rows[i] = calloc(10, sizeof(int));
  }

  print_level_by_level(node, rows, cols, 0);

  for (int i = 0; i < 10; ++i) {
    printf("%-2d - ", i + 1);

    for (int j = 0; j < 10; ++j) {
      if (rows[i][j] == 0) {
        continue;
      }

      printf("%-2d ", rows[i][j]);
    }

    printf("\n");
  }

  for (int i = 0; i < 10; ++i) {
    free(rows[i]);
  }

  free(rows);
  free(cols);
}

void
root_to_leaves(
  const struct node *const node,
  stack_int_t *const stack
) {
  if (!node) {
    return;
  }

  stack_int_push(stack, node->value);

  if (!node->left && !node->right) {
    stack_int_print_reverse(stack);
  }

  root_to_leaves(node->left, stack);
  root_to_leaves(node->right, stack);

  stack_int_pop(stack);
}

void
dfs(
  const struct node *const node,
  size_t *const max_depth,
  const size_t depth,
  int *const sum
) {
  if (!node) {
    return;
  }
  
  dfs(node->left, max_depth, depth + 1, sum);
  dfs(node->right, max_depth, depth + 1, sum);

  if (!node->left && !node->right) {
    if (depth > *max_depth) {
      *max_depth = depth;
      *sum = node->value;
    } else if (depth == *max_depth) {
      *sum += node->value;
    }
  }
}

int
deepest_leaves_sum(
  const struct node *const node
) {
  int sum = 0;
  size_t max_depth = 0;

  dfs(node, &max_depth, 1, &sum);

  return sum;
}

int
main(
  void
) {
  struct node* root = new_node(1);

  root->left = new_node(2);
  root->right = new_node(3);

  root->left->left = new_node(4);
  root->left->right = new_node(7);

  root->right->right = new_node(12);

  root->left->left->left = new_node(5);
  root->left->left->right = new_node(6);

  root->left->left->right->left = new_node(8);
  root->left->left->right->right = new_node(9);

  root->left->left->right->right->right = new_node(10);
  root->left->left->right->left->right = new_node(14);

  print_levels(root);

  delete_node(root);

  return EXIT_SUCCESS;
}

