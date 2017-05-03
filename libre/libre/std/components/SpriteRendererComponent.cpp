#include "SpriteRendererComponent.h"

#include "libre/core/Renderer.h"
#include "libre/core/GameObject.h"
#include "libre/core/Game.h"
#include "libre/core/Texture.h"

void libre::SpriteRendererComponent::Render()
{
    Renderer* rend = Game::GetRenderer();

    Vector2f posf = GetGameObject()->GetGlobalTransform().position - Vector2f(mpSprite->GetRect().w * 0.5f, mpSprite->GetRect().h * 0.5f);
    Vector2i pos = { Round(posf.x), Round(posf.y) };
    rend->DrawSprite(mpSprite, GetGameObject()->GetGlobalTransform().scale, pos, GetGameObject()->GetGlobalTransform().rotation);
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

libre::BoundingBoxComponent* libre::SpriteRendererComponent::AddBoundingBoxComponent()
{
    BoundingBoxComponent* bb = GetGameObject()->AddComponent<BoundingBoxComponent>();
    bb->SetDimensions(mpSprite->GetRect().dim);

    return bb;
}