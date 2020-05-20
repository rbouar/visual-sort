#include "sort_algo/sorting_strategy.h"
#include "sort_array.h"
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1280

int main(void)
{
  sorting_algo algos[] = {quick_sort};

  srand(time(NULL)); // use current time as seed for random generator
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
