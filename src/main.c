#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashmap_int.h"

int main() {
  map_int_t* map_int = map_int_create(0);

  for (int i = 0; i < 100; i++) {
    map_int_set(map_int, i, i);
  }

  map_int_dump(map_int);
  map_int_destroy(map_int);

  return EXIT_SUCCESS;
}
