#include "sorting_strategy.h"
#include <stdio.h>

#define ASCENDING 1
#define DELAY 5

static int prev_power_of_two(int n)
{
  int p = 1;
  while(p < n)
    p = p<<1;

  return p>>1;
}

static void bitonic_merge(sort_array *array, int start, int end, short dir)
{
  if(end - start <= 1)
    return;

  int m = prev_power_of_two(end-start);
  for(int i=start; i < end - m; i++) {
    if (dir == (sort_array_get(array, i) > sort_array_get(array, i+m)) )
      sort_array_swap(array, i, i+m, DELAY);
  }
  
  bitonic_merge(array, start, start+m, dir);
  bitonic_merge(array, start+m, end, dir);
}

static void bitonic_sort_aux(sort_array *array, int start, int end, short dir)
{
  if(end - start <= 1)
    return;
  
  int m = (end+start)/2;
  bitonic_sort_aux(array, start, m, !dir);
  bitonic_sort_aux(array, m, end, dir);
  
  bitonic_merge(array, start, end, dir);
}

void bitonic_sort(sort_array *array)
{
  bitonic_sort_aux(array, 0, sort_array_size(array), ASCENDING);
}
