#include "RectRendererComponent.h"

#include "libre/core/Game.h"
#include "libre/core/GameObject.h"

void libre::RectRendererComponent::Render()
{
    Game::GetInstance()->GetWindow()->GetRenderer()
        ->DrawRect(mDrawColor,
                   Round(GetGameObject()->transform.position.x),
                   Round(GetGameObject()->transform.position.y),
                   Round(mWidth),
                   Round(mHeight));
}
