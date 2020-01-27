#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

      return result;
    }
  }

  result[0] = -1;
  result[1] = -1;

  return result;
}
