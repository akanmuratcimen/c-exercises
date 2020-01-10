#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

#include "hashtable_g.h"
#include "utility.h"

ht_g_t* create_g(const unsigned long size) {
  ht_g_t* ht_g = (ht_g_t*)malloc(sizeof(ht_g_t));

  ht_g->entries = malloc(sizeof(ht_g_entry_t) * size);

  for (unsigned long i = 0; i < size; ++i) {
    ht_g->entries[i] = NULL;
  }

  ht_g->size = size;

  return ht_g;
}

void set_g(ht_g_t* ht_g, const void* key, const void* value) {
  const unsigned long slot = hash(key, ht_g->size);

}
