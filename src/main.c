#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms.h"

int main() {
  int nums[] = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };

  printf("missing_number: %d\n", missing_number(nums, 9));

  return EXIT_SUCCESS;
}
