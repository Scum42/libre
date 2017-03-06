/*
#include <iostream>
using namespace std;

#include "SDL.h"
#include "SDL_image.h"
#include "Box2D/Box2D.h"
#undef main
*/

#include "MyGame.h"

int main(int argc, char *argv[])
{
    /*
    SDL_Window *window = nullptr;
    SDL_Surface *screen = nullptr;
    SDL_Renderer *renderer = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) return 1;

    window = SDL_CreateWindow("Hello SDL!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900, SDL_WINDOW_FULLSCREEN_DESKTOP);
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

/*
#include "SDL.h"

#include <iostream>
using namespace std;

#define DEFAULT_RESOLUTION  1
#undef main

static int ticks = 0;

static Uint32 SDLCALL
ticktock(Uint32 interval, void *param)
{
    ++ticks;
    return (interval);
}

static Uint32 SDLCALL
callback(Uint32 interval, void *param)
{
    SDL_Log("Timer %d : param = %d", interval, (int)(uintptr_t)param);
    return interval;
}

int
main(int argc, char *argv[])
{
    int i, desired;
    SDL_TimerID t1, t2, t3;
    Uint32 start32, now32;
    Uint64 start, now;

    // Enable standard application logging
    SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO);

    if (SDL_Init(SDL_INIT_TIMER) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return (1);
    }

    // Start the timer
    desired = 0;
    if (argv[1])
    {
        desired = SDL_atoi(argv[1]);
    }
    if (desired == 0)
    {
        desired = DEFAULT_RESOLUTION;
    }
    t1 = SDL_AddTimer(desired, ticktock, NULL);

    // Wait 10 seconds
    SDL_Log("Waiting 10 seconds");
    SDL_Delay(10 * 1000);

    // Stop the timer 
    SDL_RemoveTimer(t1);

    // Print the results
    if (ticks)
    {
        SDL_Log("Timer resolution: desired = %d ms, actual = %f ms",
                desired, (double)(10 * 1000) / ticks);
    }

    // Test multiple timers
    SDL_Log("Testing multiple timers...");
    t1 = SDL_AddTimer(100, callback, (void *)1);
    if (!t1)
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create timer 1: %s", SDL_GetError());
    t2 = SDL_AddTimer(50, callback, (void *)2);
    if (!t2)
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create timer 2: %s", SDL_GetError());
    t3 = SDL_AddTimer(233, callback, (void *)3);
    if (!t3)
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create timer 3: %s", SDL_GetError());

    // Wait 10 seconds
    SDL_Log("Waiting 10 seconds");
    SDL_Delay(10 * 1000);

    SDL_Log("Removing timer 1 and waiting 5 more seconds");
    SDL_RemoveTimer(t1);

    SDL_Delay(5 * 1000);

    SDL_RemoveTimer(t2);
    SDL_RemoveTimer(t3);

    start = SDL_GetPerformanceCounter();
    for (i = 0; i < 1000000; ++i)
    {
        ticktock(0, NULL);
    }
    now = SDL_GetPerformanceCounter();
    SDL_Log("1 million iterations of ticktock took %f ms", (double)((now - start) * 1000) / SDL_GetPerformanceFrequency());

    SDL_Log("Performance counter frequency: %d", (unsigned long long) SDL_GetPerformanceFrequency());
    SDL_Log("Performance counter frequency: %d", (unsigned long long) SDL_GetPerformanceFrequency());
    SDL_Log("Performance counter frequency: %d", (unsigned long long) SDL_GetPerformanceFrequency());
    SDL_Log("Performance counter frequency: %d", (unsigned long long) SDL_GetPerformanceFrequency());
    start32 = SDL_GetTicks();
    start = SDL_GetPerformanceCounter();
    SDL_Delay(1000);
    now = SDL_GetPerformanceCounter();
    now32 = SDL_GetTicks();
    SDL_Log("Delay 1 second = %d ms in ticks, %f ms according to performance counter", (now32 - start32), (double)((now - start) * 1000) / SDL_GetPerformanceFrequency());

    SDL_Quit();
    cin.get();
    return (0);
}
*/