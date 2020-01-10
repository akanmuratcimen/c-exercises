#ifndef HASHMAP_INT_H
#define HASHMAP_INT_H

#include <stdbool.h>

typedef struct map_int_entry_t {
  int key;
  int value;
  struct map_int_entry_t* next;
} map_int_entry_t;

typedef struct map_int_t {
  unsigned int size;
  map_int_entry_t** entries;
} map_int_t;

map_int_t* map_int_create(void);

void map_int_set(const map_int_t* map_int, const int key, const int value);
bool map_int_is_key_exists(const map_int_t* map_int, const int key);
int map_int_get(const map_int_t* map_int, const int key);

void map_int_inc_value(const map_int_t* map_int, const int key);
void map_int_dec_value(const map_int_t* map_int, const int key);

void map_int_del(const map_int_t* map_int, const int key);

#endif // HASHMAP_INT_H
