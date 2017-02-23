#include <iostream>
using namespace std;

/*
#include "SDL.h"
#include "SDL_image.h"
#undef main

#include "Box2D/Box2D.h"
*/

#include "MyGame.h"

int main(int argc, char *argv[])
{
    /*
    SDL_Window *window = nullptr;
    SDL_Surface *screen = nullptr;
    SDL_Renderer *renderer = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) return 1;

    window = SDL_CreateWindow("Hello SDL!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr) return 1;

    renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 114, 144, 154, 255);

    SDL_Surface *surf = IMG_Load("../res/stones.png");
    SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);

    while (true)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            //;
        }

        SDL_Rect destRect;
        destRect.x = 0;
        destRect.y = 0;
        destRect.w = 500;
        destRect.h = 325;

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, tex, nullptr, nullptr);
        SDL_RenderPresent(renderer);
    }
    */

    MyGame game;
    return game.Start();
}