#include <stdio.h>

void insertion_sort(int* values, size_t n) {
  int j, key;

  for (int i = 1; i < n; ++i) {
    key = values[i];

    for (j = i - 1; j >= 0 && values[j] > key; --j) {
      values[j + 1] = values[j];
    }

    values[j + 1] = key;
  }
}

int main() {
  int values[] = { 5, 67, 3, 1, 6, 7, 8, 3, 34, 67, 34, 12, 45, 343 };
  size_t n = sizeof(values) / sizeof(values[0]);

  insertion_sort(values, n);

  for (int i = 0; i < n; ++i) {
    printf("%d ", values[i]);
  }

  puts("");
}