#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable_g.h"

int main() {
  ht_g_t* ht_g = create_g(100);

  set_g(ht_g, 1, 1);

  return 0;
}
