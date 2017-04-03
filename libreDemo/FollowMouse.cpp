#include "FollowMouse.h"

#include "libre/core/GameObject.h"
#include "libre/input/Mouse.h"

void FollowMouse::Update()
{
    GetGameObject()->transform.position = { (float)Mouse::GetPosition().x, (float)Mouse::GetPosition().y };
}
