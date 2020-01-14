#ifndef HASHMAP_INT_H
#define HASHMAP_INT_H

#include <stdbool.h>

typedef struct map_int_entry_t {
  int key;
  int value;
  struct map_int_entry_t* next;
} map_int_entry_t;

typedef struct map_int_t {
  unsigned int capacity;
  unsigned int entry_count;
  map_int_entry_t** entries;
} map_int_t;

extern const float load_factor;

map_int_t* map_int_create(const int initial_capacity);

void map_int_set(map_int_t* map, const int key, const int value);
bool map_int_is_key_exists(const map_int_t* map, const int key);
int map_int_get(const map_int_t* map, const int key);

void map_int_inc_value(map_int_t* map, const int key);
void map_int_dec_value(map_int_t* map, const int key);

void map_int_del(map_int_t* map, const int key);
void map_int_destroy(map_int_t* map);

void map_int_dump(const map_int_t* map);

#endif // HASHMAP_INT_H
