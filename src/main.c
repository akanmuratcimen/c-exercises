#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms.h"

int main() {
  int nums[] = { 1, 3, 5, 6 };
  int size = sizeof(nums) / sizeof(nums[0]);
  int insert_position = search_insert_positon(nums, size, 7);

  printf("position: %d\n", insert_position);

  return EXIT_SUCCESS;
}
