#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct ht_entry_t {
  struct ht_entry_t* next;
  char* key;
  char* value;
} ht_entry_t;

typedef struct {
  ht_entry_t** entries;
  unsigned long size;
} ht_t;

ht_entry_t* ht_pair(const char* key, const char* value);
ht_t* ht_create(const unsigned long size);
void ht_set(ht_t* hashtable, const char* key, const char* value);
char* ht_get(ht_t* hashtable, const char* key);
void ht_del(ht_t* hashtable, const char* key);
void ht_dump(const ht_t* hashtable);
void ht_destroy(ht_t* hashtable);

#endif // HASHTABLE_H
