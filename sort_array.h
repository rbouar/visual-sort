#ifndef SORT_ARRAY
#define SORT_ARRAY


typedef struct sort_array {
  long size;
  int *data;
} sort_array;


sort_array* sort_array_new (long size);

void sort_array_free (sort_array *array);

void sort_array_set (sort_array *array, long index, int value);

int sort_array_get (sort_array *array, long index);


#endif
