typedef struct ht_entry_t {
  
  char* key;
  char* value;
  struct ht_entry_t* next;
} ht_entry_t;

typedef struct {
  unsigned int size;
  ht_entry_t** entries;
} ht_t;

ht_entry_t* ht_pair(const char* key, const char* value);
ht_t* ht_create(int size);
void ht_set(ht_t* hashtable, const char* key, const char* value);
char* ht_get(ht_t* hashtable, const char* key);
void ht_del(ht_t* hashtable, const char* key);
void ht_dump(ht_t* hashtable);
void ht_destroy(ht_t* hashtable);
