#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms.h"
#include "map_int.h"

int* two_sum(int* nums, int nums_size, int target, int* return_size) {
  *return_size = 2;
  int* result = malloc(*return_size * sizeof(int));

  map_int_t* map = map_int_create(nums_size);

  for (int i = 0; i < nums_size; ++i) {
    map_int_set(map, nums[i], i);
  }

  for (int i = 0; i < nums_size; ++i) {
    int complement = target - nums[i];

    if (map_int_is_key_exists(map, complement)) {
      int map_index = map_int_get(map, complement);

      if (map_index == i) {
        continue;
      }

      result[0] = i;
      result[1] = map_index;

      map_int_destroy(map);

      return result;
    }
  }

  map_int_destroy(map);

  result[0] = -1;
  result[1] = -1;

  return result;
}

bool is_palindrome(char* str, size_t start, size_t end) {
  while (end > start) {
    if (str[start++] != str[end--]) {
      return false;
    }
  }

  return true;
}

char* get_range(char* str, size_t start, size_t end) {
  char* result = malloc(sizeof(char) * (end - start + 1));
  return memcpy(result, str + start, end - start + 1);
}

char* longest_palindrome(char* str) {
  char *start, *end;
  char *p = str, *subStart = str;
  int maxLen = 1;

  while (*p) {
    start = p;
    end = p;

    while (*(end + 1) && *(end + 1) == *end) {
      end++;
    }

    p = end + 1;

    while (*(end + 1) && (start > str) && *(end + 1) == *(start - 1)) {
      start--;
      end++;
    }

    if (end - start + 1 > maxLen) {
      maxLen = end - start + 1;
      subStart = start;
    }
  }

  char* rst = (char*)calloc(maxLen + 1, sizeof(char));
  strncpy(rst, subStart, maxLen);

  return rst;
}

int roman_to_int(char* str) {
  int result = 0;

  while (str && *str != '\0') {
    switch (*str) {
    case 'I':
      if (*(str + 1) && (*(str + 1) == 'V' || *(str + 1) == 'X')) {
        result -= 1;
        break;
      }

      result += 1;
      break;
    case 'V': result += 5; break;
    case 'X':
      if (*(str + 1) && (*(str + 1) == 'L' || *(str + 1) == 'C')) {
        result -= 10;
        break;
      }

      result += 10;
      break;
    case 'L': result += 50; break;
    case 'C':
      if (*(str + 1) && (*(str + 1) == 'D' || *(str + 1) == 'M')) {
        result -= 100;
        break;
      }

      result += 100;
      break;
    case 'D': result += 500; break;
    case 'M': result += 1000; break;
    }

    str = str + 1;
  }

  return result;
}
