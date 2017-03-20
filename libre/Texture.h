#pragma once

#include "SDL.h"

#include <string>
#include <memory>

#include "LibreMath.h"

namespace libre
{
    class Renderer;
    class Sprite;

    class Texture; typedef std::shared_ptr<Texture> TexturePtr;

    class Texture
    {
    public:
        inline static TexturePtr Make() { return std::make_shared<Texture>(); }

        friend Renderer;

        inline Texture() { mpSDLTex = nullptr; }
        inline ~Texture() { SDL_DestroyTexture(mpSDLTex); }

        // Load the texture from a file.
        void LoadFromFile(std::string path);

        // Returns a sprite set up to be the given subsection of this texture. NOTE: This creates a NEW sprite. It is up to you to delete it when you're done.
        Sprite* CreateSpriteFromSubsection(Recti spriteRect);

    private:
        SDL_Texture* mpSDLTex;
    };
}