#include "hash_table.h"
#include "linked_list.h"

int main() {
  ht_t* ht = ht_create();

  ht_set(ht, "name1", "em");
  ht_set(ht, "name2", "russian");
  ht_set(ht, "name3", "pizza");
  ht_set(ht, "name4", "doge");
  ht_set(ht, "name5", "pyro");
  ht_set(ht, "name6", "joost");
  ht_set(ht, "name7", "kalix");

  ht_dump(ht);
  ht_destroy(ht);

  return 0;
}
