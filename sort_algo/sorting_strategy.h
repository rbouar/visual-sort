#ifndef SORTING_STRATEGY
#define SORTING_STRATEGY

#include "../sort_array.h"

typedef void (*sorting_algo)(sort_array *array);

void insertion_sort(sort_array *array);
void merge_sort(sort_array *array);
void selection_sort(sort_array *array);
void bubble_sort(sort_array *array);
void quick_sort(sort_array *array);

#endif
