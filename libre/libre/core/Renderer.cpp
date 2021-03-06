#include "Renderer.h"

#include "SDL_render.h"

#include "Window.h"
#include "Texture.h"

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
    SDL_RenderFillRect(mpSDLRenderer, &r);
}

void libre::Renderer::DrawSprite(Sprite* sprite, Vector2f scale, Vector2i position)
{
    SDL_Rect sdlrSource, sdlrDest;
    Recti r = sprite->GetRect();
    sdlrSource = { r.x, r.y, r.w, r.h };
    sdlrDest = { position.x, position.y, Round(r.w * scale.x), Round(r.h * scale.y) };

    SDL_RenderCopy(mpSDLRenderer, sprite->GetTexture()->mpSDLTex, &sdlrSource, &sdlrDest);
}

void libre::Renderer::DrawSprite(Sprite * sprite, Vector2f scale, Vector2i position, float angle)
{
    // If the angle is 0...
    if (angle == 0.0f)
    {
        // Use the faster version that doesn't bother with rotate
        DrawSprite(sprite, scale, position);
        return;
    }

    SDL_Rect sdlrSource, sdlrDest;
    Recti r = sprite->GetRect();
    sdlrSource = { r.x, r.y, r.w, r.h };
    sdlrDest = { position.x, position.y, Round(r.w * scale.x), Round(r.h * scale.y) };

    SDL_RenderCopyEx(mpSDLRenderer, sprite->GetTexture()->mpSDLTex, &sdlrSource, &sdlrDest, angle, NULL, SDL_FLIP_NONE);
}

void libre::Renderer::SetRendererColor(Color c)
{
    SDL_SetRenderDrawColor(mpSDLRenderer, c.r, c.g, c.b, c.a);
}
