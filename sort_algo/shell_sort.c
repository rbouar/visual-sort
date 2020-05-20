#include "sorting_strategy.h"

#define DELAY 3

void shell_sort(sort_array *array)
{
  int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
  for(int g=0; g < sizeof(gaps)/sizeof(int); g++) {

    for(int i=gaps[g]; i < sort_array_size(array); i++) {
      int key = sort_array_get(array, i);
      int j = i;
      while(j >= gaps[g] && sort_array_get(array, j-gaps[g]) > key) {
	sort_array_set(array, j, sort_array_get(array, j-gaps[g]), DELAY);
	j -= gaps[g];	
      }
      sort_array_set(array, j, key, DELAY);
    }    
  }
}
