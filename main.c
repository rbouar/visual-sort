#include "sort_array.h"
#include "sort_algo/sorting_strategy.h"

#define ARRAY_SIZE 320

int main(void)
{
  sorting_algo algos[] = {merge_sort};
  
  sort_array *arr = sort_array_new(ARRAY_SIZE, 0);

  int n = sizeof(algos)/sizeof(algos[0]);
  for(int i=0; i < n; i++) {
    if(i != 0)
      shuffle(arr);
    algos[i](arr);      
  }
  
  sort_array_free(arr);

  return 0;
}
