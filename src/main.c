#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashmap_int.h"

int main() {
  map_int_t* map_int = map_int_create(1);

  for (int i = 0; i < 50; i++) {
    map_int_set(map_int, i, i * 2);
  }

  // printf("%d\n", map_int->capacity);
  // printf("%d\n", map_int->entry_count);

  // map_int_destroy(map_int);

  return 0;
}
