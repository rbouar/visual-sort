#include "sorting_strategy.h"

#define ROTATE_DELAY 2
#define FINAL_ROTATE_DELAY 1

void insertion_sort(sort_array *arr)
{
  const int n = sort_array_size(arr);
  
  for(int i=1; i < n; i++) {
    int key = sort_array_get(arr, i);
    int j = i - 1;
    while( j >= 0 && sort_array_get(arr, j) > key ) {
      sort_array_set(arr, j+1, sort_array_get(arr, j), ROTATE_DELAY);
      j--;
    }
    sort_array_set(arr, j+1, key, FINAL_ROTATE_DELAY);    
  }
  
}
