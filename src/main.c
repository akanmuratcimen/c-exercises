#include <stdio.h>
#include <stdlib.h>

#include "algorithms.h"

int main() {
  int nums[] = { 3, 2, 4 };
  int return_size;
  int* x = two_sum(nums, sizeof(nums) / sizeof(nums[0]), 6, &return_size);

  for (int i = 0; i < return_size; ++i) {
    printf("%d ", x[i]);
  }

  printf("\n");

  return EXIT_SUCCESS;
}
