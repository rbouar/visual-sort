#ifndef SORT_ARRAY
#define SORT_ARRAY

#include <stdbool.h>

typedef struct sort_array {
  long size;
  int *data;
} sort_array;


sort_array* sort_array_new (long size, bool is_identity );

void shuffle (sort_array *array);

void sort_array_free (sort_array *array);

void sort_array_set (sort_array *array, long index, int value);

int sort_array_get (sort_array *array, long index);

void sort_array_swap(sort_array *array, long i, long j);

#endif
