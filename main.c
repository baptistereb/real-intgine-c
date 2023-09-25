#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    window = SDL_CreateWindow("REAL-INTGINE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);

    if (NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (NULL == renderer)
    {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Event e;
    int quit = 0;

    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = 1;
            }
        }

        // Efface le rendu précédent
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        //pts du triangle
        SDL_Point points[3] = {{320, 50}, {220, 430}, {420, 430}};
        SDL_Vertex pts[3] = {
            (SDL_Vertex){(SDL_FPoint){320, 50}, (SDL_Color){255, 0, 0, 255}, (SDL_FPoint){0}},
            (SDL_Vertex){(SDL_FPoint){220, 430}, (SDL_Color){255, 0, 0, 255}, (SDL_FPoint){0}},
            (SDL_Vertex){(SDL_FPoint){420, 430}, (SDL_Color){255, 0, 0, 255}, (SDL_FPoint){0}}
        };

        // remplissage
        SDL_RenderGeometry(renderer, NULL, pts, 3, NULL, 0); //rendu, texture, points, nb de points, l'ordre d'affichage des points, un truc d'openGL 
        
        /*SDL_FPoint trianglePoints[3] = {{320.0f, 50.0f}, {220.0f, 430.0f}, {420.0f, 430.0f}};
        SDL_RenderGeometry(renderer, SDL_FLT_RECT(trianglePoints), 0);*/
        
        // bordure
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //blanc
        SDL_RenderDrawLine(renderer, 320, 50, 220, 430);
        SDL_RenderDrawLine(renderer, 220, 430, 420, 430);
        SDL_RenderDrawLine(renderer, 420, 430, 320, 50);

        // Met à jour le rendu
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
