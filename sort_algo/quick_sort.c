#include "sorting_strategy.h"
#include <stdlib.h>

#define DELAY 3


static int idx_pivot_selection(sort_array *array, int start, int end)
{  
  return rand()%(end-start) + start;
}


static int partition(sort_array *array, int start, int end, int idx_pivot)
{
  sort_array_swap(array, start, idx_pivot, DELAY);
  int pivot = sort_array_get(array, start);
  
  int left = start+1, right = end-1;
  while( left <= right ) {
    if( sort_array_get(array, left) < pivot )
      left++;
    else if( sort_array_get(array, right) >= pivot )
      right--;
    else
      sort_array_swap(array, left, right, DELAY);
  }

  sort_array_swap(array, start, right, DELAY);

  return right;
}


static void quick_sort_aux(sort_array *array, int start, int end)
{
  if(end - start <= 1)
    return;

  int idx_pivot = idx_pivot_selection(array, start, end);
  idx_pivot = partition(array, start, end, idx_pivot);

  quick_sort_aux(array, start, idx_pivot);
  quick_sort_aux(array, idx_pivot+1, end);
}


void quick_sort(sort_array *array)
{
  quick_sort_aux(array, 0, sort_array_size(array));
}
