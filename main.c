#include <SDL.h>
#include <time.h>

#define SCR_W 500
#define SCR_H 500
#define ARR_S 200

static int arr[ARR_S];

void init_arr() {
  int i;
  for (i = 0; i < ARR_S; i++) {
    arr[i] = rand() % 50;
  }
}
int quit() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      return 1;
    }
  }

  return 0;
}

void print_arr() {
  int i;
  for (i = 0; i < 200; i++) {
    printf("Pos %d = %d\n", i, arr[i]);
  }
}

void draw(SDL_Renderer *render) {
  int i;
  for (i = 0; i < ARR_S; i++) {
    SDL_RenderDrawLine(render, 200 + i, 400, 200 + i, 400 - arr[i]);
  }
}

void swap(int i, int j){
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
  

void bubble_sort(void){
  int loop = 0;
  int i;
  do{
    for(i = 0; i < ARR_S; i++){
      if(arr[i] > arr[i+1]){
	swap(i, i+1);
	loop = 1;
	  }
    }
	  } while(loop);
      
}

int main() {

  srand(time(NULL));
  SDL_Window *window = SDL_CreateWindow("Sorting", SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED, SCR_W, SCR_H,
                                        SDL_WINDOW_RESIZABLE);

  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

  init_arr();
  
  while (1) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    draw(renderer);
    SDL_RenderPresent(renderer);
    if (quit()) {
      break;
    }
  }

  return 0;
}
