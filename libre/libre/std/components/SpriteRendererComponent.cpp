#include "SpriteRendererComponent.h"

#include "libre/core/Renderer.h"
#include "libre/core/GameObject.h"
#include "libre/core/Game.h"
#include "libre/core/Texture.h"

void libre::SpriteRendererComponent::Render()
{
    Renderer* rend = Game::GetInstance()->GetWindow()->GetRenderer();

    Vector2f posf = GetGameObject()->transform.position;
    Vector2i pos = { Round(posf.x), Round(posf.y) };
    rend->DrawSprite(mpSprite, pos);
}

libre::Sprite* libre::SpriteRendererComponent::SetSprite(libre::Sprite* sprite)
{
    mpSprite = sprite;
    return mpSprite;
}

libre::Sprite* libre::SpriteRendererComponent::SetSprite(std::string filename)
{
    return SetSprite(filename, { 0,0,0,0 });
}

libre::Sprite* libre::SpriteRendererComponent::SetSprite(std::string filename, libre::Recti spriteRect)
{
    Texture* tex = new Texture();
    tex->LoadFromFile(filename);
    Sprite* spr = tex->CreateSpriteFromSubsection(spriteRect);
    return SetSprite(spr);
}
