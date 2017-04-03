#include "Window.h"

libre::Window::Window(std::string name, int width, int height, WindowCreationFlags flags)
{
    // Set them to null at first
    mpSDLWindow = nullptr;
    mpRenderer = nullptr;

    // Convert from Libre flags to SQL ones
    Uint32 sdlFlags = LibreToSQLFlags(flags);

    // Set the x and y positions of the window
    int sdlX, sdlY;
    sdlX = sdlY = flags & LIBRE_WINDOW_POSITION_CENTER ? SDL_WINDOWPOS_CENTERED : SDL_WINDOWPOS_UNDEFINED;

    // Create the sdl window
    mpSDLWindow = SDL_CreateWindow(name.c_str(), sdlX, sdlY, width, height, sdlFlags);
    // Create the renderer
    mpRenderer = new Renderer(this);
}

libre::Window::~Window()
{
    if (mpRenderer) delete mpRenderer;

    if (mpSDLWindow)
    {
        SDL_DestroyWindow(mpSDLWindow);
        mpSDLWindow = nullptr;
    }
}

Uint32 libre::Window::LibreToSQLFlags(WindowCreationFlags flags)
{
    Uint32 sdlFlags = 0;

    if (flags & LIBRE_WINDOW_FULLSCREEN) sdlFlags |= SDL_WINDOW_FULLSCREEN;
    if (flags & LIBRE_WINDOW_FULLSCREEN_MATCH) sdlFlags |= SDL_WINDOW_FULLSCREEN_DESKTOP;

    return sdlFlags;
}
