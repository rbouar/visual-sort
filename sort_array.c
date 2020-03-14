#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sort_array.h"

/* create a sort_array corresponding to a permutation of size s*/
sort_array* sort_array_new (long s, bool is_identity)
{
  assert(s > 0);
  
  sort_array* arr = malloc(sizeof(sort_array));

  assert(arr);
  
  arr->size     = s;
  arr->data     = malloc(s*sizeof(int));

  assert(arr->data);

  for(int i=0; i < s; i++)
    arr->data[i]=i+1;

  if( !is_identity)
    shuffle(arr);
  
  return arr;
}


void shuffle (sort_array *arr)
{
  srand(time(NULL)); // use current time as seed for random generator
  for(int i=0; i < arr->size; i++)
    {
      int j = rand()%(arr->size - i) + i; 
      if( i != j)
	sort_array_swap(arr,i,j);
    }
}

/* free a sort_array created by sort_array_new */
void sort_array_free (sort_array *arr)
{
  assert(arr);
  
  free(arr->data);

  free(arr);
}


/* set the value of the element at index i in arr to v */
void sort_array_set (sort_array *arr, long i, int v)
{
  assert(0 <= i && i < arr->size);

  arr->data[i]=v;
}


/* return the value of element at index i in arr */
int sort_array_get (sort_array *arr, long i)
{
  assert(0 <= i && i < arr->size);

  return arr->data[i];
}


void sort_array_swap(sort_array *arr, long i, long j)
{
  assert(0 <= i && i < arr->size);
  assert(0 <= j && j < arr->size);

  int tmp = arr->data[i];
  arr->data[i] = arr->data[j];
  arr->data[j] = tmp;
}
