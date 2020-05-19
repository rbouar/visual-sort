#include "sorting_strategy.h"

#define DELAY 2

void bubble_sort(sort_array *arr)
{
  short sorted;
  for(int i=0; i < sort_array_size(arr)-1; i++) {
    sorted = 1;
    
    for(int j=0; j < sort_array_size(arr)-i-1; j++) {	
      if( sort_array_get(arr,j+1) < sort_array_get(arr,j) ) {
	sort_array_swap(arr, j+1, j, DELAY);
	sorted = 0;
      }
    }

    if(sorted)
      return;
  }  
}
