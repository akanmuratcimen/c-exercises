#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

int main() {
  const int size = 20;
  ht_t* ht = ht_create(size * 3);

  for (unsigned long i = 0; i < size; i++) {
    char name[20];

    sprintf(name, "%lu", i);
    ht_set(ht, name, "foobar");
  }

  ht_dump(ht);
  ht_destroy(ht);

  return 0;
}
