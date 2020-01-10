#ifndef HASHTABLE_G_H
#define HASHTABLE_G_H

typedef struct ht_g_entry_t {
  struct ht_g_entry_t* next;
  void* key;
  void* value;
} ht_g_entry_t;

typedef struct ht_g_t {
  void* type;
  unsigned long size;
  ht_g_entry_t** entries;
} ht_g_t;

ht_g_t* create_g(const unsigned long size);
void set_g(ht_g_t* ht_g, const void* key, const void* value);

#endif // HASHTABLE_G_H
