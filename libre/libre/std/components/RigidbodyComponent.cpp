#include "RigidbodyComponent.h"

#include "libre\core\Game.h"
#include "libre/core/GameObject.h"
#include "libre/core/Scene.h"

#include "BoundingBoxComponent.h"

#include <iostream>

libre::RigidbodyComponent::RigidbodyComponent()
{
    mIsKinematic = false;
    mDensity = 1.0f;
    mFriction = 0.5f;

    mpB2Body = nullptr;
}

void libre::RigidbodyComponent::PhysicsUpdate()
{
    libre::Transform& trans = GetGameObject()->transform;

    if (IsKinematic())
    {
        b2Vec2 pos;
        pos.x = trans.position.x * PIXEL_TO_METER_FACTOR;
        pos.y = trans.position.y * PIXEL_TO_METER_FACTOR;

        mpB2Body->SetTransform(pos, trans.rotation * DEG_TO_RAD_FACTOR);
    }
    else
    {
        trans.position = (Vector2f)(mpB2Body->GetPosition()) * METER_TO_PIXEL_FACTOR;
        trans.rotation = mpB2Body->GetAngle() * RAD_TO_DEG_FACTOR;
    }
}

bool libre::RigidbodyComponent::SetIsKinematic(bool isKinematic)
{
    mIsKinematic = isKinematic;
    if (mpB2Body) mpB2Body->SetType(mIsKinematic ? b2_kinematicBody : b2_dynamicBody);
    return mIsKinematic;
}

float libre::RigidbodyComponent::SetDensity(float density)
{
    mDensity = density;
    if (mpB2Body)
    {
        for (b2Fixture* f = mpB2Body->GetFixtureList(); f; f = f->GetNext())
        {
            f->SetDensity(mDensity);
        }
    }
    return mDensity = density;
}

float libre::RigidbodyComponent::SetFriction(float friction)
{
    mFriction = friction;
    if (mpB2Body)
    {
        for (b2Fixture* f = mpB2Body->GetFixtureList(); f; f = f->GetNext())
        {
            f->SetFriction(mFriction);
        }
    }
    return mFriction;
}

void libre::RigidbodyComponent::Initialize()
{
    Vector2f position = GetGameObject()->transform.position;
    float rotation = GetGameObject()->transform.rotation;

    b2BodyDef bodyDef;
    bodyDef.type = mIsKinematic ? b2_kinematicBody : b2_dynamicBody;
    bodyDef.position.Set(position.x * PIXEL_TO_METER_FACTOR, position.y * PIXEL_TO_METER_FACTOR);
    bodyDef.angle = rotation * DEG_TO_RAD_FACTOR;

    mpB2Body = Game::GetCurrentScene()->mB2World.CreateBody(&bodyDef);
}

void libre::RigidbodyComponent::Startup()
{
    BoundingBoxComponent* bb = GetGameObject()->GetComponent<BoundingBoxComponent>();

    if (bb)
    {
        b2PolygonShape shape;
        shape.SetAsBox(bb->GetHalfWidth() * PIXEL_TO_METER_FACTOR, bb->GetHalfHeight() * PIXEL_TO_METER_FACTOR);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        fixtureDef.density = mDensity;
        fixtureDef.friction = mFriction;

        mpB2Body->CreateFixture(&fixtureDef);
    }
}

void libre::RigidbodyComponent::Cleanup()
{
    Game::GetCurrentScene()->internal_GetB2World()->DestroyBody(mpB2Body);
    mpB2Body = nullptr;
}
