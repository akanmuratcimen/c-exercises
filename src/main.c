#include <stdio.h>
#include <stdlib.h>

#include "set_of_stacks_int.h"

int main() {
  set_of_stacks_int_t* set_of_stacks = set_of_stacks_int_initialize(5);

  free(set_of_stacks);

  return EXIT_SUCCESS;
}
