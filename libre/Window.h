#pragma once

#include "SDL_render.h"

#include "Renderer.h"
#include "Math.h"

namespace libre
{
    class Window
    {
    public:
        friend Renderer;

        Renderer& GetRenderer() { return *mpRenderer; }

    private:

        SDL_Window* mpSDLWindow;
        Renderer* mpRenderer;
    };
}