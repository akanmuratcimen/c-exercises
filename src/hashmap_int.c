#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "hashmap_int.h"

const float load_factor = 0.8;

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

inline static int hash(const unsigned int capacity, const int key) {
  return key % capacity;
}

map_int_t* map_int_create(const int initial_capacity) {
  map_int_t* map = malloc(sizeof(map_int_t));
  const unsigned int capacity = next_prime(initial_capacity);

  map->entries = malloc(sizeof(map_int_entry_t) * capacity);

  for (unsigned int i = 0; i < capacity; ++i) {
    map->entries[i] = NULL;
  }

  map->capacity = capacity;
  map->entry_count = 0;

  return map;
}

bool should_growth_capacity(const map_int_t* map_int) {
  return map_int->entry_count >= map_int->capacity * load_factor;
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

void growth_capacity(map_int_t* map_int) {
  const unsigned int old_capacity = map_int->capacity;
  const unsigned int new_capacity = next_prime(old_capacity * 2);

  map_int_entry_t** old_entries = map_int->entries;

  map_int->entries = malloc(sizeof(map_int_entry_t) * new_capacity);
  map_int->capacity = new_capacity;

  for (unsigned int i = 0; i < old_capacity; ++i) {
    map_int_entry_t* old_entry = old_entries[i];

    while (old_entry) {
      map_int_entry_t* old_entry_next = old_entry->next;
      const unsigned int slot = hash(new_capacity, old_entry->key);
      map_int_entry_t* new_entry = map_int->entries[slot];

      if (new_entry == NULL) {
        map_int->entries[slot] =
            map_int_create_entry(old_entry->key, old_entry->value);
      } else {
        map_int_entry_t* prev_new_entry;

        while (new_entry) {
          if (new_entry->next == NULL) {
            break;
          }

          prev_new_entry = new_entry;
          new_entry = new_entry->next;
        }

        prev_new_entry->next =
            map_int_create_entry(old_entry->key, old_entry->value);
      }

      free(old_entry);
      old_entry = old_entry_next;
    }
  }

  free(old_entries);
}

void map_int_set(map_int_t* map_int, const int key, const int value) {
  const unsigned int slot = hash(map_int->capacity, key);
  map_int_entry_t* entry = map_int->entries[slot];

  if (entry == NULL) {
    if (should_growth_capacity(map_int) == true) {
      growth_capacity(map_int);
    }

    map_int->entries[slot] = map_int_create_entry(key, value);
    map_int->entry_count++;

    return;
  }

  map_int_entry_t* prev;

  while (entry) {
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

  if (should_growth_capacity(map_int) == true) {
    growth_capacity(map_int);
  }

  prev->next = map_int_create_entry(key, value);
  map_int->entry_count++;
}

inline static map_int_entry_t* map_int_get_entry(
    const map_int_t* map_int, const int key) {
  const unsigned int slot = hash(map_int->capacity, key);
  map_int_entry_t* entry = map_int->entries[slot];

  while (entry) {
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

void map_int_inc_value(map_int_t* map_int, const int key) {
  map_int_entry_t* entry = map_int_get_entry(map_int, key);

  if (entry == NULL) {
    map_int_set(map_int, key, 1);

    return;
  }

  entry->value++;
}

void map_int_dec_value(map_int_t* map_int, const int key) {
  map_int_entry_t* entry = map_int_get_entry(map_int, key);

  if (entry == NULL) {
    map_int_set(map_int, key, -1);

    return;
  }

  entry->value--;
}

void map_int_del(map_int_t* map_int, const int key) {
  const unsigned int slot = hash(map_int->capacity, key);
  map_int_entry_t* entry = map_int->entries[slot];

  if (entry == NULL) {
    return;
  }

  int idx = 0;
  map_int_entry_t* prev;

  while (entry) {
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
      map_int->entry_count--;

      return;
    }

    prev = entry;
    entry = prev->next;

    ++idx;
  }
}

void map_int_destroy(map_int_t* map_int) {
  for (unsigned int i = 0; i < map_int->capacity; ++i) {
    map_int_entry_t* entry = map_int->entries[i];

    while (entry) {
      map_int_entry_t* next = entry->next;

      free(entry);

      entry = next;
    }
  }

  free(map_int->entries);
  free(map_int);
}

void map_int_dump(const map_int_t* map_int) {
  for (unsigned int i = 0; i < map_int->capacity; ++i) {
    map_int_entry_t* entry = map_int->entries[i];

    if (entry == NULL) {
      continue;
    }

    printf("[%d]:", entry->key);

    for (;;) {
      printf(" %d:%d", entry->key, entry->value);

      if (entry->next == NULL) {
        break;
      }

      entry = entry->next;
    }

    printf("\n");
  }
}
