#include "Renderer.h"

#include "SDL_render.h"

#include "Window.h"

const libre::Color DEFAULT_CLEAR_COLOR = { 100, 100, 100, 255 };

libre::Renderer::Renderer(Window* window)
{
    mpSDLRenderer = nullptr;
    mpSDLRenderer = SDL_CreateRenderer(window->mpSDLWindow, -1, SDL_RENDERER_ACCELERATED);

    mClearColor = DEFAULT_CLEAR_COLOR;
    SetClearColor(mClearColor);
}

libre::Renderer::~Renderer()
{
    SDL_DestroyRenderer(mpSDLRenderer);
    mpSDLRenderer = nullptr;
}

inline void libre::Renderer::SetClearColor(Color c)
{
    mClearColor = c;
    SetRendererColor(c);
}

void libre::Renderer::Clear()
{
    SetRendererColor(mClearColor);
    SDL_RenderClear(mpSDLRenderer);
}

void libre::Renderer::Flip()
{
    SDL_RenderPresent(mpSDLRenderer);
}

void libre::Renderer::DrawLine(Color c, int x1, int y1, int x2, int y2)
{
    SetRendererColor(c);
    SDL_RenderDrawLine(mpSDLRenderer, x1, y1, x2, y2);
}

void libre::Renderer::DrawPoint(Color c, int x, int y)
{
    SetRendererColor(c);
    SDL_RenderDrawPoint(mpSDLRenderer, x, y);
}

void libre::Renderer::DrawRect(Color c, int x, int y, int w, int h)
{
    SDL_Rect r = { x, y, w, h };

    SetRendererColor(c);
    SDL_RenderDrawRect(mpSDLRenderer, &r);
}

void libre::Renderer::DrawSprite(Sprite sprite)
{
    // TODO: Draw sprite
}

void libre::Renderer::SetRendererColor(Color c)
{
    SDL_SetRenderDrawColor(mpSDLRenderer, c.r, c.g, c.b, c.a);
}
