#include "sort_array.h"
#include "sorting_strategy.h"

#define ARRAY_SIZE 200

int main(void)
{
  sorting_algo algos[1] = {insertion_sort};

  
  sort_array *arr = sort_array_new(ARRAY_SIZE, 0);
  sort_array_init_display(arr);

  int n = sizeof(algos)/sizeof(algos[0]);
  for(int i=0; i < n; i++) {
    if(i != 0)
      shuffle(arr);
    algos[i](arr);      
  }

  
  sort_array_quit_display(arr);
  sort_array_free(arr);

  return 0;
}
