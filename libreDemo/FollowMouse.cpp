#include "FollowMouse.h"

#include "libre/core/GameObject.h"
#include "libre/input/Mouse.h"
#include "libre/std/components/SpriteRendererComponent.h"

void FollowMouse::Startup()
{
    sprite = GetGameObject()->GetComponent<SpriteRendererComponent>()->GetSprite();
}

void FollowMouse::Update()
{
    Vector2f newPos = Vector2f::One() * 10.0f;
    newPos.x = (float)(Mouse::GetPosition().x - sprite->GetRect().w / 2);
    newPos.y = (float)(Mouse::GetPosition().y - sprite->GetRect().h / 2);

    GetGameObject()->transform.position = newPos;
}
