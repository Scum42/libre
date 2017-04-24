#pragma once

#include <string>

#include "SDL_render.h"

#include "Renderer.h"
#include "libre/util/LibreMath.h"

namespace libre
{
    enum WindowCreationFlags
    {
        // Represents no flags.
        LIBRE_WINDOW_NONE               = 0b000,

        // Fullscreen, at the resolution specified.
        LIBRE_WINDOW_FULLSCREEN         = 0b001,

        // Fullscreen, the the current resolution of the desktop.
        LIBRE_WINDOW_FULLSCREEN_MATCH   = 0b010,

        // Center the position of the window
        LIBRE_WINDOW_POSITION_CENTER    = 0b100
    };

    class Game;

    class Window
    {
    public:
        friend Game;
        friend Renderer;

        // Constructor with the name of the window, resolution width, resolution height, and any flags.
        Window(std::string name, int width, int height, WindowCreationFlags flags);
        // Constructor without width and height. Useful when using a flag that causes them to be ignored; will default to 800 by 600 if you aren't.
        inline Window(std::string name, WindowCreationFlags flags) : Window(name, 800, 600, flags) {}
        // Destructor
        ~Window();

        // Get the width of the screen
        int GetWidth() { return GetDimensions().x; }

        // Get the height of the screen
        int GetHeight() { return GetDimensions().y; }

        // Get the width and height of the screen
        Vector2i GetDimensions();

        // Get the renderer associated with this window
        //Renderer* GetRenderer() { return mpRenderer; }

    private:

        Uint32 LibreToSQLFlags(WindowCreationFlags flags);

        SDL_Window* mpSDLWindow;
        Renderer* mpRenderer;
    };
}