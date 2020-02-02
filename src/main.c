#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms.h"

int main() {
  char* str = "MCMXCIV";
  printf("%d\n", roman_to_int(str));

  return EXIT_SUCCESS;
}
