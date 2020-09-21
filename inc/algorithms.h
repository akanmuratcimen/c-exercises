#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stdbool.h>
#include "tree_node.h"

int* two_sum(int* nums, int nums_size, int target, int* return_size);
bool is_palindrome(char* str, size_t start, size_t end);
char* get_range(char* str, size_t start, size_t end);
char* longest_palindrome(char* str);
int roman_to_int(char* str);
int remove_element(int* nums, int nums_size, int val);
int search_insert_positon(int* nums, int nums_size, int target);
int length_of_last_word(char* s);
char* reverse(char* str);
char* add_binary(char* a, char* b);
int climb_stairs(int n);
void merge_sorted_arr(int* nums1, int m, int* nums2, int n);
bool is_same_tree(struct tree_node* p, struct tree_node* q);
int add_digits(int num);

#endif // ALGORITHMS_H
