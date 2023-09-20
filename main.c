#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int test;

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;

    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("SDL2", 100, 100,
                                 640, 480, SDL_WINDOW_SHOWN);

    if(NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        return 2;
    }
     
    /*test = SDL_SetWindowFullscreen(SDL_Window* window, Uint32 flags);

    SDL_DestroyWindow(window);
    Quit:
    SDL_Quit();
    */
    return 0;
}
