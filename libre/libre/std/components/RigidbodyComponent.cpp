#include "RigidbodyComponent.h"

#include "libre/core/GameObject.h"
#include "libre/core/Scene.h"

#include <iostream>

libre::RigidbodyComponent::RigidbodyComponent()
{
    mIsKinematic = false;
    mDensity = 1.0f;
    mFriction = 1.0f;

    mpB2Body = nullptr;
}

void libre::RigidbodyComponent::PhysicsUpdate()
{
    libre::Transform& trans = GetGameObject()->transform;

    trans.position = (Vector2f)(mpB2Body->GetPosition()) * GetGameObject()->GetScene()->GetMeterToPixelFactor();
    trans.rotation = mpB2Body->GetAngle() * RAD_TO_DEG_FACTOR;
}

inline bool libre::RigidbodyComponent::SetIsKinematic(bool isKinematic)
{
    mIsKinematic = isKinematic;
    mpB2Body->SetType(mIsKinematic ? b2_kinematicBody : b2_dynamicBody);
    return mIsKinematic;
}

inline float libre::RigidbodyComponent::SetDensity(float density)
{
    return mDensity = density;
}

inline float libre::RigidbodyComponent::SetFriction(float friction)
{
    return mFriction = friction;
}

void libre::RigidbodyComponent::Initialize()
{
    Vector2f position = GetGameObject()->transform.position;
    float rotation = GetGameObject()->transform.rotation;

    float ptom = GetGameObject()->GetScene()->GetPixelToMeterFactor();

    b2BodyDef bodyDef;
    bodyDef.type = mIsKinematic ? b2_kinematicBody : b2_dynamicBody;
    bodyDef.position.Set(position.x * ptom, position.y * ptom);
    bodyDef.angle = rotation * DEG_TO_RAD_FACTOR;

    mpB2Body = GetGameObject()->GetScene()->mB2World.CreateBody(&bodyDef);

    b2PolygonShape shape;
    shape.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = mDensity;
    fixtureDef.friction = mFriction;

    mpB2Body->CreateFixture(&fixtureDef);
}

void libre::RigidbodyComponent::Cleanup()
{
    GetGameObject()->GetScene()->internal_GetB2World()->DestroyBody(mpB2Body);
    mpB2Body = nullptr;
}
