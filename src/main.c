#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms.h"

int main() {
  int nums1[6] = { 1, 2, 3 };
  int nums2[] = { 2, 5, 6 };

  merge_sorted_arr(nums1, 3, nums2, 3);

  for (int i = 0; i < 6; ++i) {
    printf("%d ", nums1[i]);
  }

  printf("\n");

  return EXIT_SUCCESS;
}
