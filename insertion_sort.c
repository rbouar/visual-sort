#include "sorting_strategy.h"

#define DELAY 1

void insertion_sort(sort_array *arr)
{
  const int n = sort_array_size(arr);
  for(int i=1; i < n; i++) {
    for(int j = i-1; j >= 0 && sort_array_get(arr, j) > sort_array_get(arr, j+1); j--) {
      sort_array_swap(arr, j, j+1, DELAY);
    }
  }
}
