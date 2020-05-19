#include "sorting_strategy.h"

#define DELAY 50


static long min_index_from(sort_array *arr, int from)
{
  long idx = from;
  for(int i=from+1; i < sort_array_size(arr); i++) {
    if( sort_array_get(arr, i) < sort_array_get(arr, idx) )
      idx = i;    
  }
  return idx;
}

  

void selection_sort(sort_array *arr)
{
  for(int i=0; i < sort_array_size(arr); i++) {
    int j = min_index_from(arr, i);
    if(j != i)
      sort_array_swap(arr, i, j, DELAY);
  }
}
