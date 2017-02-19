#include "Renderer.h"

#include "SDL_render.h"

#include "Window.h"

libre::Renderer::Renderer(Window* window)
{
	SDL_CreateRenderer(window->mpSDLWindow, -1, SDL_RENDERER_ACCELERATED);
}

libre::Renderer::~Renderer()
{
	SDL_DestroyRenderer(mpSDLRenderer);
}

inline void libre::Renderer::SetClearColor(Color c)
{
	mClearColor = c;
	SetRendererColor(c);
}

void libre::Renderer::Clear()
{
	SDL_RenderClear(mpSDLRenderer);
}

void libre::Renderer::DrawLine(Color c, int x1, int y1, int x2, int y2)
{
	SetRendererColor(c);
	SDL_RenderDrawLine(mpSDLRenderer, x1, y1, x2, y2);
	SetRendererColor(mClearColor);
}

void libre::Renderer::DrawPoint(Color c, int x, int y)
{
	SetRendererColor(c);
	SDL_RenderDrawPoint(mpSDLRenderer, x, y);
	SetRendererColor(mClearColor);
}

void libre::Renderer::DrawRect(Color c, int x, int y, int w, int h)
{
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;

	SetRendererColor(c);
	SDL_RenderDrawRect(mpSDLRenderer, &r);
	SetRendererColor(mClearColor);
}

void libre::Renderer::DrawSprite(Sprite sprite)
{

}

void libre::Renderer::SetRendererColor(Color c)
{
	SetRendererColor(c);
}
