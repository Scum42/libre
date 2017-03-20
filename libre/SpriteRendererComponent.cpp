#include "SpriteRendererComponent.h"

#include "Renderer.h"
#include "GameObject.h"
#include "Game.h"

/*libre::SpriteRendererComponent::SpriteRendererComponent(libre::Renderer* rend)
{
    mpRenderer = rend;
}*/

void libre::SpriteRendererComponent::Render()
{
    Renderer* rend = Game::GetInstance()->GetWindow()->GetRenderer();

    Vector2f posf = GetGameObject()->transform.position;
    Vector2i pos = { Round(posf.x), Round(posf.y) };
    rend->DrawSprite(mpSprite, pos);
}

void libre::SpriteRendererComponent::SetSprite(Sprite* sprite)
{
    mpSprite = sprite;
}
