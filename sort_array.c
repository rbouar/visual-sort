#include <SDL2/SDL.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sort_array.h"

struct sort_array {
  //model
  long size;
  int *data;
  
  //view
  bool displayable;
  SDL_Window *window;
  SDL_Renderer *renderer;
};

//clear screen with black color
static void clear_screen(sort_array *arr)
{
  SDL_SetRenderDrawColor( arr->renderer, 0x00, 0x00, 0x00, 0xFF ); //black
  SDL_RenderClear( arr->renderer );
}

static void render_sort_array(sort_array *arr, unsigned int delay)
{
  clear_screen(arr);
  
  SDL_SetRenderDrawColor( arr->renderer, 0xFF, 0xFF, 0xFF, 0xFF ); //white

  const int width = SCREEN_WIDTH/arr->size;
  for(int i=0; i < arr->size; i++) {
    SDL_Rect rect = {.x=i*width,
		     .y=0,
		     .w=width,
		     .h=(SCREEN_HEIGHT*arr->data[i])/arr->size};
    SDL_RenderFillRect(arr->renderer, &rect);
      
  }  
  SDL_RenderPresent(arr->renderer);

  SDL_Delay(delay);
}



/* create a sort_array corresponding to a permutation of size s*/
sort_array* sort_array_new (long s, bool is_identity)
{
  assert(s > 0);
  
  sort_array* arr = malloc(sizeof(sort_array));

  assert(arr);

  // init model
  arr->size        = s;
  arr->data        = malloc(s*sizeof(int));

  assert(arr->data);
  
  // init view
  arr->displayable = false;
  arr->window      = NULL;
  arr->renderer    = NULL;
  
  for(int i=0; i < s; i++)
    arr->data[i]=i+1;

  if( !is_identity )
    shuffle(arr);
  
  return arr;
}


/* free a sort_array created by sort_array_new */
void sort_array_free (sort_array *arr)
{
  assert(arr);
  
  free(arr->data);

  free(arr);
}


void shuffle (sort_array *arr)
{
  srand(time(NULL)); // use current time as seed for random generator
  for(int i=0; i < arr->size; i++)
    {
      int j = rand()%(arr->size - i) + i; 
      if( i != j)
	sort_array_swap(arr,i,j,1);
    }
}



int sort_array_size (sort_array *arr)
{
  return arr->size;
}


/* return the value of element at index i in arr */
int sort_array_get (sort_array *arr, long i)
{
  assert(0 <= i && i < arr->size);
  
  return arr->data[i];
}


/* set the value of the element at index i in arr to v */
void sort_array_set (sort_array *arr, long i, int v, unsigned int delay)
{
  assert(0 <= i && i < arr->size);

  arr->data[i]=v;
  
  if(arr->displayable)
    render_sort_array(arr, delay);  
}


void sort_array_swap(sort_array *arr, long i, long j, unsigned int delay)
{
  assert(0 <= i && i < arr->size);
  assert(0 <= j && j < arr->size);

  int tmp = arr->data[i];
  arr->data[i] = arr->data[j];
  arr->data[j] = tmp;

  if(arr->displayable)
    render_sort_array(arr, delay);
}


int sort_array_init_display(sort_array *arr) {
  arr->displayable = true;
  
  if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
      fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
      goto Quit;
    }
  
  arr->window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if(NULL == arr->window)
    {
      fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
      goto Quit;
    }
  
  arr->renderer = SDL_CreateRenderer(arr->window, -1, SDL_RENDERER_ACCELERATED);
  if(NULL == arr->renderer)
    {
      fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
      goto Quit;
    }

  return EXIT_SUCCESS;

 Quit:
  if(NULL != arr->renderer)
    SDL_DestroyRenderer(arr->renderer);
  if(NULL != arr->window)
    SDL_DestroyWindow(arr->window);
  SDL_Quit();
  return EXIT_FAILURE;
}

void sort_array_quit_display(sort_array *arr) {
  SDL_DestroyRenderer(arr->renderer);
  SDL_DestroyWindow(arr->window);
  SDL_Quit();  
}
