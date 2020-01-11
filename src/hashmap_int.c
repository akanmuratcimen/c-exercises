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

  for (unsigned int i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

unsigned int next_prime(unsigned int n) {
  if (n < 13) {
    return 13;
  }

  if (n & 1) {
    n += 2;
    return is_prime(n) ? n : next_prime(n);
  }

  return next_prime(n - 1);
}

inline static int hash(const unsigned int size, const int key) {
  return key % size;
}

map_int_t* map_int_create(const int initial_size) {
  map_int_t* map = malloc(sizeof(map_int_t));
  const unsigned int size = initial_size == 0 ? next_prime(0) : initial_size;

  map->entries = malloc(sizeof(map_int_entry_t) * size);

  for (unsigned int i = 0; i < size; ++i) {
    map->entries[i] = NULL;
  }

  map->size = size;

  return map;
}

map_int_entry_t* map_int_create_entry(const int key, const int value) {
  map_int_entry_t* entry = (map_int_entry_t*)malloc(sizeof(map_int_entry_t));

  if (entry == NULL) {
    return NULL;
  }

  entry->key = key;
  entry->value = value;
  entry->next = NULL;

  return entry;
}

void map_int_set(const map_int_t* map_int, const int key, const int value) {
  const unsigned int slot = hash(map_int->size, key);
  map_int_entry_t* entry = map_int->entries[slot];

  if (entry == NULL) {
    map_int->entries[slot] = map_int_create_entry(key, value);

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

  if (prev == NULL) {
    return;
  }

  prev->next = map_int_create_entry(key, value);
}

inline static map_int_entry_t* map_int_get_entry(
    const map_int_t* map_int, const int key) {
  const unsigned int slot = hash(map_int->size, key);
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
    map_int_set(map_int, key, 1);

    return;
  }

  entry->value++;
}

void map_int_dec_value(const map_int_t* map_int, const int key) {
  map_int_entry_t* entry = map_int_get_entry(map_int, key);

  if (entry == NULL) {
    map_int_set(map_int, key, -1);

    return;
  }

  entry->value--;
}

void map_int_del(const map_int_t* map_int, const int key) {
  const unsigned int slot = hash(map_int->size, key);
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
      } else if (prev != NULL) {
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

void map_int_destroy(map_int_t* map_int) {
  for (unsigned int i = 0; i < map_int->size; ++i) {
    map_int_entry_t* entry = map_int->entries[i];

    while (entry != NULL) {
      map_int_entry_t* next = entry->next;

      free(entry);

      entry = next;
    }
  }

  free(map_int->entries);
  free(map_int);
}

void map_int_dump(const map_int_t* map_int) {
  for (unsigned int i = 0; i < map_int->size; ++i) {
    map_int_entry_t* entry = map_int->entries[i];

    if (entry == NULL) {
      continue;
    }

    for (;;) {
      printf("%d: %d\n", entry->key, entry->value);

      if (entry->next == NULL) {
        break;
      }

      entry = entry->next;
    }
  }
}

#endif // HASHMAP_INT_C
