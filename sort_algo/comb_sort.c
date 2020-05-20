#include <math.h>
#include "sorting_strategy.h"

#define DELAY 5

void comb_sort(sort_array *array)
{
  int gap = sort_array_size(array);
  double factor = 1.3;
  short sorted = 0;
  
  while( !sorted ) {
    
    gap /= factor;
    if( gap <= 1 ) {
      gap = 1;
      sorted = 1;
    }

    for(int i=0; i < sort_array_size(array)-gap; i++) {
      if( sort_array_get(array, i) > sort_array_get(array, i+gap) ) {
	sort_array_swap(array, i, i+gap, DELAY);
	sorted = 0;
      }
    }
  }
}
