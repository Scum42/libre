#include "SpriteRendererComponent.h"

#include "Renderer.h"
#include "GameObject.h"

libre::SpriteRendererComponent::SpriteRendererComponent(libre::Renderer* rend)
{
    mpRenderer = rend;
}

void libre::SpriteRendererComponent::Render()
{
    Vector2f posf = GetGameObject()->transform.position;
    Vector2i pos = { (int)posf.x, (int)posf.y };
    mpRenderer->DrawSprite(mpSprite, pos);
}

void libre::SpriteRendererComponent::SetSprite(Sprite* sprite)
{
    mpSprite = sprite;
}
