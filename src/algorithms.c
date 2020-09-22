#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms.h"
#include "map_int.h"
#include "tree_node.h"

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

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
    char next = *(str + 1);

    switch (*str) {
    case 'I':
      if (next && (next == 'V' || next == 'X')) {
        result -= 1;
        break;
      }

      result += 1;
      break;
    case 'V': result += 5; break;
    case 'X':
      if (next && (next == 'L' || next == 'C')) {
        result -= 10;
        break;
      }

      result += 10;
      break;
    case 'L': result += 50; break;
    case 'C':
      if (next && (next == 'D' || next == 'M')) {
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

int remove_element(int* nums, int nums_size, int val) {
  int i, j;

  for (i = 0, j = 0; i < nums_size; ++i) {
    if (nums[i] != val) {
      nums[j++] = nums[i];
    }
  }

  return j;
}

int search_insert_positon(int* nums, int nums_size, int target) {
  int i;

  for (i = 0; i < nums_size; ++i) {
    if (nums[i] >= target) {
      return i;
    }
  }

  return i;
}

int length_of_last_word(char* s) {
  int counter = 0, last_word_length = 0;
  bool is_previous_space = false;

  while (s) {
    if (*s == 0x20 || *s == '\0') {
      if (!is_previous_space) {
        last_word_length = counter;
      }

      is_previous_space = true;
      counter = 0;
    } else {
      is_previous_space = false;
      counter++;
    }

    if (*s == '\0') {
      break;
    }

    s++;
  }

  return last_word_length ? last_word_length : counter;
}

char* reverse(char* str) {
  char t, n = strlen(str);

  for (int i = 0; i < (n / 2); ++i) {
    t = str[i];
    str[i] = str[n - i - 1];
    str[n - i - 1] = t;
  }

  return str;
}

char* add_binary(char* a, char* b) {
  int ai = strlen(a) - 1, bi = strlen(b) - 1, c = 0, i;
  char* r = (char*)malloc(sizeof(char) * (max(ai, bi) + 2));

  for (i = 0; ai >= 0 || bi >= 0; --ai, --bi, ++i) {
    int sum = c;

    if (ai >= 0) {
      sum += a[ai] - '0';
    }

    if (bi >= 0) {
      sum += b[bi] - '0';
    }

    c = sum / 2;
    r[i] = sum % 2 + '0';
  }

  if (c) {
    r[i++] = c + '0';
  }

  r[i] = '\0';

  return reverse(r);
}

int climb_stairs(const int n) {
  if (n <= 1) {
    return n;
  }

  int m[n];

  m[0] = 1;
  m[1] = 2;

  for (int i = 2; i <= n; ++i) {
    m[i] = m[i - 2] + m[i - 1];
  }

  return m[n - 1];
}

void merge_sorted_arr(int* nums1, int m, int* nums2, int n) {
  for (int i = m - 1, j = n - 1, k = m + n - 1; j >= 0;) {
    nums1[k--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
  }
}

bool is_same_tree(struct tree_node* p, struct tree_node* q) {
  if (p == NULL && q == NULL) {
    return true;
  } 
  
  if (p == NULL || q == NULL) {
    return false;
  }

  if (p->value != q->value) {
    return false;
  }
  
  if (!is_same_tree(p->left, q->left)) {
    return false;
  }
  
  if (!is_same_tree(p->right, q->right)) {
    return false;
  }

  return true;
}

int add_digits(int num) {
  int result = 0;

  while (num) {
    int x = num % 10;
    result += x;
    num = num / 10;
  }
  
  if (result >= 10) {
    return add_digits(result);
  }

  return result;
}

bool is_ugly(int num) {
  if (num < 1) {
    return false;
  }

  if (num == 1) {
    return true;
  }

  if (num % 2 != 0 && num % 3 != 0 && num % 5 != 0) {
    return false;
  }

  if (num % 2 == 0) {
    return is_ugly(num / 2);
  }
  
  if (num % 3 == 0) {
    return is_ugly(num / 3);
  }

  if (num % 5 == 0) {
    return is_ugly(num / 5);
  }

  return true;
}
