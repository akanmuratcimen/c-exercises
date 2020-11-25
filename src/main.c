#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack_int.h"

struct node {
  int v;
  struct node* l;
  struct node* r;
};

struct node* 
new_node(
  int v
) {
  struct node* n = malloc(sizeof struct node);

  n->v = v;
  n->l = NULL;
  n->r = NULL;

  return n;
}

void 
print_pre_order(
  struct node* n
) {
  if (!n) {
    return;
  }

  printf("%d ", n->v);
  print_pre_order(n->l);
  print_pre_order(n->r);
}

void 
print_in_order(
  struct node* n
) {
  if (!n) {
    return;
  }

  print_in_order(n->l);
  printf("%d ", n->v);
  print_in_order(n->r);
}

void 
print_post_order(
  struct node* n
) {
  if (!n) {
    return;
  }

  print_post_order(n->l);
  print_post_order(n->r);
  printf("%d ", n->v);
}

void 
delete_node(
  struct node* n
) {
  if (!n) {
    return;
  }

  delete_node(n->l);
  delete_node(n->r);
  
  free(n);
}

bool 
does_have_children(
  struct node* n
) {
  return n != NULL && (n->l || n->r);
}

size_t 
get_height(
  struct node* n
) {
  if (!n) {
    return 0;
  }

  size_t l_h = get_height(n->l);
  size_t r_h = get_height(n->r);

  return l_h > r_h ? l_h + 1 : r_h + 1;
}

void 
print_level_by_level(
  struct node* n, 
  int** rows, 
  int* cols, 
  size_t lvl
) {
  if (!n) {
    return;
  }

  lvl++;

  print_level_by_level(n->l, rows, cols, lvl);
  print_level_by_level(n->r, rows, cols, lvl);

  rows[lvl - 1][cols[lvl - 1]++] = n->v;
}

void 
print_levels(
  struct node* n
) {
  int** rows = calloc(10, sizeof void*);
  int* cols = calloc(10, sizeof int);

  for (int i = 0; i < 10; ++i) {
    rows[i] = calloc(10, sizeof int);
  }

  print_level_by_level(n, rows, cols, 0);

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
  struct node* n, 
  stack_int_t* stack
) {
  if (!n) {
    return;
  }

  stack_int_push(stack, n->v);

  if (!n->l && !n->r) {
    stack_int_print_reverse(stack);
  }

  root_to_leaves(n->l, stack);
  root_to_leaves(n->r, stack);

  stack_int_pop(stack);
}

int 
main(
  void
) {
  struct node* root = new_node(1);

  root->l = new_node(2);
  root->r = new_node(3);

  root->l->l = new_node(4);
  root->l->r = new_node(7);

  root->r->r = new_node(12);

  root->l->l->l = new_node(5);
  root->l->l->r = new_node(6);

  root->l->l->r->l = new_node(8);
  root->l->l->r->r = new_node(9);

  root->l->l->r->r->r = new_node(10);
  
  stack_int_t* rtl_stack = stack_int_initialize(20);
  root_to_leaves(root, rtl_stack);
  stack_int_clear(&rtl_stack);

  delete_node(root);

  return EXIT_SUCCESS;
}
