#include "RectRendererComponent.h"

#include "libre/core/Game.h"
#include "libre/core/GameObject.h"

void libre::RectRendererComponent::Render()
{
    Game::GetRenderer()
        ->DrawRect(mDrawColor,
                   Round(GetGameObject()->GetGlobalTransform().position.x - mHalfWidth),
                   Round(GetGameObject()->GetGlobalTransform().position.y - mHalfHeight),
                   Round(mWidth),
                   Round(mHeight));
}
