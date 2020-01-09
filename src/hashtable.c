#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

static unsigned int hash(const char* key, const int mod) {
  unsigned long hash = 5381;
  int c;

  while ((c = *key++)) {
    hash = ((hash << 5) + hash) + c;
  }

  return hash % mod;
}

ht_entry_t* ht_pair(const char* key, const char* value) {
  ht_entry_t* entry = malloc(sizeof(ht_entry_t));

  entry->key = malloc(strlen(key) + 1);
  entry->value = malloc(strlen(value) + 1);

  strcpy(entry->key, key);
  strcpy(entry->value, value);

  entry->next = NULL;

  return entry;
}

ht_t* ht_create(int size) {
  ht_t* hashtable = malloc(sizeof(ht_t));

  hashtable->entries = malloc(sizeof(ht_entry_t*) * size);

  for (int i = 0; i < size; ++i) {
    hashtable->entries[i] = NULL;
  }

  hashtable->size = size;

  return hashtable;
}

void ht_set(ht_t* hashtable, const char* key, const char* value) {
  unsigned int slot = hash(key, hashtable->size);

  ht_entry_t* entry = hashtable->entries[slot];

  if (entry == NULL) {
    hashtable->entries[slot] = ht_pair(key, value);
    return;
  }

  ht_entry_t* prev;

  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      free(entry->value);
      entry->value = malloc(strlen(value) + 1);
      strcpy(entry->value, value);
      return;
    }

    prev = entry;
    entry = prev->next;
  }

  prev->next = ht_pair(key, value);
}

char* ht_get(ht_t* hashtable, const char* key) {
  ht_entry_t* entry = hashtable->entries[hash(key, hashtable->size)];

  if (entry == NULL) {
    return NULL;
  }

  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      return entry->value;
    }

    entry = entry->next;
  }

  return NULL;
}

void ht_del(ht_t* hashtable, const char* key) {
  unsigned int bucket = hash(key, hashtable->size);

  ht_entry_t* entry = hashtable->entries[bucket];

  if (entry == NULL) {
    return;
  }

  ht_entry_t* prev;
  int idx = 0;

  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      if (entry->next == NULL && idx == 0) {
        hashtable->entries[bucket] = NULL;
      }

      if (entry->next != NULL && idx == 0) {
        hashtable->entries[bucket] = entry->next;
      }

      if (entry->next == NULL && idx != 0) {
        prev->next = NULL;
      }

      if (entry->next != NULL && idx != 0) {
        prev->next = entry->next;
      }

      free(entry->key);
      free(entry->value);
      free(entry);

      return;
    }

    prev = entry;
    entry = prev->next;

    ++idx;
  }
}

void ht_dump(ht_t* hashtable) {
  for (int i = 0; i < hashtable->size; ++i) {
    ht_entry_t* entry = hashtable->entries[i];

    if (entry == NULL) {
      continue;
    }

    printf("[%8d]: ", i);

    for (;;) {
      printf("%s = %s ", entry->key, entry->value);

      if (entry->next == NULL) {
        break;
      }

      entry = entry->next;
    }

    printf("\n");
  }
}

void ht_destroy(ht_t* hashtable) {
  for (int i = 0; i < hashtable->size; ++i) {
    ht_entry_t* entry = hashtable->entries[i];

    if (entry == NULL) {
      continue;
    }

    ht_entry_t* next = entry->next;

    for (;;) {
      free(entry->key);
      free(entry->value);
      free(entry);

      if (next == NULL) {
        break;
      }

      entry = next;
      next = entry->next;
    }
  }

  free(hashtable->entries);
  free(hashtable);
}