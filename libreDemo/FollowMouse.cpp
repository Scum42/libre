#include "FollowMouse.h"

#include "libre/core/GameObject.h"
#include "libre/input/Mouse.h"
#include "libre/std/components/SpriteRendererComponent.h"

#include <iostream>

void FollowMouse::Startup()
{
    sprite = GetGameObject()->GetComponent<SpriteRendererComponent>()->GetSprite();
}

void FollowMouse::Update()
{
    Vector2f newPos = Vector2f::One() * 10.0f;
    newPos.x = (float)(Mouse::GetPosition().x);
    newPos.y = (float)(Mouse::GetPosition().y);

    GetGameObject()->transform.position = newPos;
}
