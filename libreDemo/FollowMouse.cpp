#include "FollowMouse.h"

#include "GameObject.h"
#include "Mouse.h"

void FollowMouse::Update()
{
    GetGameObject()->transform.position = { (float)Mouse::GetPosition().x, (float)Mouse::GetPosition().y };
}
