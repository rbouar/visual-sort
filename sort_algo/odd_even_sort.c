#include "sorting_strategy.h"

#define DELAY 3

void odd_even_sort  (sort_array *array)
{
  for(int i=1; i < sort_array_size(array) - 1; i++)
    {
      for(int j=1; j < sort_array_size(array)-1; j += 2)
	if( sort_array_get(array,j) > sort_array_get(array,j+1) )
	  sort_array_swap(array, j, j+1, DELAY);
      
      for(int j=0; j < sort_array_size(array)-1; j += 2)
	if( sort_array_get(array,j) > sort_array_get(array,j+1) )
	  sort_array_swap(array, j, j+1, DELAY);
    }
}
