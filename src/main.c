#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashmap_int.h"

int main() {
  map_int_t* map_int = map_int_create(0);

  map_int_set(map_int, 0, 99);
  map_int_set(map_int, -2, 1);
  map_int_set(map_int, 5, 1);
  map_int_set(map_int, 8, 1);
  map_int_set(map_int, 13, 7);
  map_int_set(map_int, 13 * 2, 8);

  map_int_dump(map_int);

  map_int_destroy(map_int);

  return 0;
}
