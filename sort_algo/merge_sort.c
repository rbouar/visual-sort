#include "sorting_strategy.h"
#include <stdlib.h>

#define DELAY 4

/* fusionne [start, sep[ et [sep, end[ */
static void merge(sort_array *arr, int start, int sep, int end)
{
  int n1 = sep-start, n2 = end-sep;

  int *L = malloc( (n1)*sizeof(int) );
  int *R = malloc( (n2)*sizeof(int) );

  int i,j;
  for(i=0; i < n1; i++)
    L[i] = sort_array_get(arr, start+i);

  for(j=0; j < n2; j++)
    R[j] = sort_array_get(arr, sep+j);

  i=0, j=0;
  while(i < n1 && j < n2) {
    if( L[i] < R[j] ) {
      sort_array_set(arr, start+i+j, L[i], DELAY);
      i++;
    }
    else {
      sort_array_set(arr, start+i+j, R[j], DELAY);
      j++;
    }
  }
  
  for(;i<n1;i++)
    sort_array_set(arr, start+i+j, L[i], DELAY);
  
  for(;j<n2;j++)
    sort_array_set(arr, start+i+j, R[j], DELAY);

  free(L);
  free(R);
}

/* sort arr from start (include) to end (exclude) */
static void merge_sort_aux(sort_array *arr, int start, int end)
{
  if( end - start <= 1)
    return;
  
  int mid = (start+end)/2;
  merge_sort_aux(arr, start, mid);
  merge_sort_aux(arr, mid,   end);
  merge(arr, start, mid, end);
}


void merge_sort(sort_array *arr)
{
  merge_sort_aux(arr, 0, sort_array_size(arr));
}
