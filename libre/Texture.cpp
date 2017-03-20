#include "Texture.h"

#include "SDL_image.h"

#include "Renderer.h"
#include "Game.h"

void libre::Texture::LoadFromFile(std::string path)
{
    // Load an image into a temporary surface
    SDL_Surface *surf = IMG_Load(path.c_str());

    // Destroy the texture if we already have one;
    // then convert the surface to a texture
    if (mpSDLTex) SDL_DestroyTexture(mpSDLTex);
    mpSDLTex = SDL_CreateTextureFromSurface(Game::GetInstance()->GetWindow()->GetRenderer()->mpSDLRenderer, surf);

    // Delete the temporary surface
    SDL_FreeSurface(surf);
}

libre::Sprite* libre::Texture::CreateSpriteFromSubsection(libre::Recti spriteRect)
{
    return new Sprite(this, spriteRect);
}
