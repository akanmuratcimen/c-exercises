#ifndef HASHMAP_INT_C
#define HASHMAP_INT_C

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "hashmap_int.h"

bool is_prime(const unsigned int n) {
  if ((n & 1) == 0) {
    return n == 2;
  }

  unsigned int i, limit = sqrt(n);

  for (i = 3; i <= limit; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

unsigned int next_prime(unsigned int n) {
  unsigned int c;

  if (n < 13) {
    c = 13;
  } else if (n & 1) {
    n += 2;
    c = is_prime(n) ? n : next_prime(n);
  } else {
    c = next_prime(n - 1);
  }

  return c;
}

inline static int get_slot(const unsigned int size, const int key) {
  return key % size;
}

map_int_t* map_int_create(void) {
  map_int_t* map = malloc(sizeof(map_int_t));
  const unsigned int size = next_prime(0);

  map->entries = malloc(sizeof(map_int_entry_t) * size);

  for (unsigned int i = 0; i < size; ++i) {
    map->entries[i] = NULL;
  }

  map->size = size;

  return map;
}

map_int_entry_t* create_map_int_entry(const int key, const int value) {
  map_int_entry_t* entry = (map_int_entry_t*)malloc(sizeof(map_int_entry_t));

  entry->key = key;
  entry->value = value;

  return entry;
}

void map_int_set(const map_int_t* map_int, const int key, const int value) {
  const unsigned int slot = get_slot(map_int->size, key);
  map_int_entry_t* entry = map_int->entries[slot];

  if (entry == NULL) {
    map_int->entries[slot] = create_map_int_entry(key, value);

    return;
  }

  map_int_entry_t* prev;

  while (entry != NULL) {
    if (entry->key == key) {
      entry->value = value;
      return;
    }

    prev = entry;
    entry = prev->next;
  }

  prev->next = create_map_int_entry(key, value);
}

inline static map_int_entry_t* map_int_get_entry(
    const map_int_t* map_int, const int key) {
  const unsigned int slot = get_slot(map_int->size, key);
  map_int_entry_t* entry = map_int->entries[slot];

  while (entry != NULL) {
    if (entry->key == key) {
      return entry;
    }

    entry = entry->next;
  }

  return NULL;
}

bool map_int_is_key_exists(const map_int_t* map_int, const int key) {
  return map_int_get_entry(map_int, key) != NULL;
}

int map_int_get(const map_int_t* map_int, const int key) {
  map_int_entry_t* entry = map_int_get_entry(map_int, key);

  if (entry == NULL) {
    return -1;
  }

  return entry->value;
}

void map_int_inc_value(const map_int_t* map_int, const int key) {
  map_int_entry_t* entry = map_int_get_entry(map_int, key);

  if (entry == NULL) {
    return;
  }

  entry->value++;
}

void map_int_dec_value(const map_int_t* map_int, const int key) {
  map_int_entry_t* entry = map_int_get_entry(map_int, key);

  if (entry == NULL) {
    return;
  }

  entry->value--;
}

void map_int_del(const map_int_t* map_int, const int key) {
  const unsigned int slot = get_slot(map_int->size, key);
  map_int_entry_t* entry = map_int->entries[slot];

  if (entry == NULL) {
    return;
  }

  int idx = 0;
  map_int_entry_t* prev;

  while (entry != NULL) {
    if (entry->key == key) {
      if (idx == 0) {
        if (entry->next == NULL) {
          map_int->entries[slot] = NULL;
        } else if (entry->next != NULL) {
          map_int->entries[slot] = entry->next;
        }
      } else {
        if (entry->next != NULL) {
          prev->next = entry->next;
        } else if (entry->next == NULL) {
          prev->next = NULL;
        }
      }

      free(entry);

      return;
    }

    prev = entry;
    entry = prev->next;

    ++idx;
  }
}

#endif // HASHMAP_INT_C
