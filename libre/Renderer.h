#ifndef LIBRE_RENDERER_H
#define LIBRE_RENDERER_H


#include "Sprite.h"
#include "Math.h"
#include "Color.h"

struct SDL_Renderer;
class Window;

namespace libre
{
    class Renderer
    {
    public:

        Renderer(Window* window);
        ~Renderer();

        inline void SetClearColor(Color c);
        void Clear();

        void DrawLine(Color c, PointInt start, PointInt end) { DrawLine(c, start.x, start.y, end.x, end.y); }
        void DrawLine(Color c, int x1, int y1, int x2, int y2);

        void DrawPoint(Color c, PointInt position) { DrawPoint(c, position.x, position.y); }
        void DrawPoint(Color c, int x, int y);

        void DrawRect(Color c, RectInt rect) { DrawRect(c, rect.x, rect.y, rect.w, rect.h); }
        void DrawRect(Color c, int x, int y, int w, int h);

        void DrawSprite(Sprite sprite);

    private:

        void SetRendererColor(Color c);

        SDL_Renderer* mpSDLRenderer;
        Color mClearColor;
    };
}

#endif