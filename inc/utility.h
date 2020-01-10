#ifndef UTILITY_H
#define UTILITY_H

#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define INT_SIZE (sizeof(int) * CHAR_BIT / 3 + 3)

inline char* itoa(int i) {
  char buf[INT_SIZE];
  char* p = &buf[sizeof buf - 1];
  *p = '\0';

  int j = i;
  if (j > 0) {
    j = -j;
  }

  do {
    p--;
    *p = '0' - j % 10;
    j /= 10;
  } while (j);

  if (i < 0) {
    p--;
    *p = '-';
  }

  size_t size = (size_t)(&buf[sizeof buf] - p);
  char* dest = malloc(size);

  if (dest) {
    memcpy(dest, p, size);
  }

  return dest;
}

inline unsigned long hash(const char* key, const unsigned long mod) {
  unsigned long hash = 5381;
  int c;

  while ((c = *key++)) {
    hash = ((hash << 5) + hash) + (unsigned long)c;
  }

  return hash % mod;
}

#endif // UTILITY_H
