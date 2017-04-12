#include "RigidbodyComponent.h"

#include "libre/core/GameObject.h"
#include "libre/core/Scene.h"

#include <iostream>

void libre::RigidbodyComponent::Update()
{
    libre::Transform& trans = GetGameObject()->transform;

    trans.position = (Vector2f)(mpB2Body->GetPosition()) * GetGameObject()->GetScene()->GetMeterToPixelFactor();
    trans.rotation = mpB2Body->GetAngle() * RAD_TO_DEG_FACTOR;

    //std::cout << "rb position " <<  "transform position " << trans.position.x << ", " << trans.position.y << std::endl;
}

libre::RigidbodyComponent::RigidbodyComponent()
{
    mIsKinematic = true;
    mDensity = 1.0f;
    mFriction = 0.3f;

    mpB2Body = nullptr;
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
}
