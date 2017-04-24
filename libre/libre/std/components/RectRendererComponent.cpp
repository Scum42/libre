#include "RectRendererComponent.h"

#include "libre/core/Game.h"
#include "libre/core/GameObject.h"

void libre::RectRendererComponent::Render()
{
    Game::GetRenderer()
        ->DrawRect(mDrawColor,
                   Round(GetGameObject()->transform.position.x - mHalfWidth),
                   Round(GetGameObject()->transform.position.y - mHalfHeight),
                   Round(mWidth),
                   Round(mHeight));
}
