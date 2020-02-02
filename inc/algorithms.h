#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stdbool.h>

int* two_sum(int* nums, int nums_size, int target, int* return_size);
bool is_palindrome(char* str, size_t start, size_t end);
char* get_range(char* str, size_t start, size_t end);
char* longest_palindrome(char* str);
int roman_to_int(char* str);
int remove_element(int* nums, int nums_size, int val);

#endif // ALGORITHMS_H
