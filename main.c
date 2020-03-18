#include <SDL2/SDL.h>

#include "sort_array.h"

#define ARRAY_SIZE 100

int main(void)
{
  sort_array *arr = sort_array_new(ARRAY_SIZE, 0);


  sort_array_free(arr);
  return 0;
}
