#include "sorting_strategy.h"

#define DELAY 3

static void sift_down(sort_array *tree, int node, int length)
{
  int left = 2*node + 1;
  int right = 2*node + 2;
  int win = node;

  if( left < length && sort_array_get(tree, win) < sort_array_get(tree, left))
    win = left;
  if( right < length && sort_array_get(tree, win) < sort_array_get(tree, right))
    win = right;

  if(win != node) {
    sort_array_swap(tree, win, node, DELAY);
    sift_down(tree, win, length);
  }
}


static void heapsort_aux(sort_array *array, int length)
{
  for(int i=length/2-1;i >= 0; i--)
    sift_down(array, i, length);

  for(int i=sort_array_size(array)-1; i >= 0; i--) {
    sort_array_swap(array, i, 0, DELAY);
    sift_down(array, 0, i);
  }
}

void heapsort(sort_array *array)
{
  heapsort_aux(array, sort_array_size(array));
}
