#include <limits.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* strchrx(register const char* s, int c) {
  do {
    if (*s == c) {
      return (char*)s;
    }
  } while (*s++);
  return (0);
}

char* get(char* value, const char* seperators) {
  int seperator_index = strchrx(value, ',') - value;

  char* result = malloc(seperator_index);
  memcpy(result, &value, seperator_index);
  result[seperator_index] = '\0';

  return result;
}

int main() {
  const char seperators[] = { ',', ' ' };

  clock_t t = clock();

  for (size_t i = 0; i < LONG_MAX; ++i) {
    free(get("213.14.79.242, 40.68.59.123:32822", seperators));
  }

  float elapsed_seconds = (((double)(clock() - t)) / CLOCKS_PER_SEC);

  printf("%f seconds to execute \n", elapsed_seconds);

  return 0;
}