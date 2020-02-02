#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms.h"

int main() {
  int nums[] = { 3, 2, 2, 3 };
  int size = sizeof(nums) / sizeof(nums[0]);
  int new_size = remove_element(nums, size, 3);

  printf("new size: %d\n", new_size);

  for (int i = 0; i < new_size; ++i) {
    printf("%d ", nums[i]);
  }

  printf("\n");

  return EXIT_SUCCESS;
}
