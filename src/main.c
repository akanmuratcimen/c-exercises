#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashmap_int.h"

int main() {
  map_int_t* map_int = map_int_create();

  map_int_set(map_int, 13, 1);
  map_int_set(map_int, 13 * 2, 2);

  map_int_del(map_int, 13 * 2);

  printf("%d\n", map_int_is_key_exists(map_int, 13));
  printf("%d\n", map_int_is_key_exists(map_int, 13 * 2));

  return 0;
}
