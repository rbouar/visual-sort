#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "sort_array.h"

/* create the default sort_array corresponding to identity with size s*/
sort_array* sort_array_new (long s)
{
  assert(s > 0);
  
  sort_array* arr = malloc(sizeof(sort_array));

  assert(arr);
  
  arr->size     = s;
  arr->data     = malloc(s*sizeof(int));

  assert(arr->data);

  for(int i=0; i < s; i++)
    arr->data[i]=i;
  
  return arr;
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
