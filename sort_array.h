#ifndef SORT_ARRAY
#define SORT_ARRAY

#include <stdbool.h>

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 480

typedef struct sort_array sort_array;

sort_array* sort_array_new (long size, bool is_identity );
void sort_array_free (sort_array *array);

void shuffle (sort_array *array);

int sort_array_size(sort_array *array);
int sort_array_get (sort_array *array, long index);
void sort_array_set (sort_array *array, long index, int value);
void sort_array_swap(sort_array *array, long i, long j);

int sort_array_init_display(sort_array *array);
void sort_array_quit_display(sort_array *array);

#endif
