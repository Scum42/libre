#include "RigidbodyComponent.h"

#include "libre/core/GameObject.h"
#include "libre/core/Scene.h"

#include <iostream>

void libre::RigidbodyComponent::Update()
{
    libre::Transform& trans = GetGameObject()->transform;

    trans.position = mpB2Body->GetPosition();
    trans.rotation = mpB2Body->GetAngle() * RAD_TO_DEG_FACTOR;

    std::cout << "transform position " << trans.position.x << ", " << trans.position.y << std::endl;
}

void libre::RigidbodyComponent::Initialize()
{
    Vector2f position = GetGameObject()->transform.position;
    float rotation = GetGameObject()->transform.rotation;

    b2BodyDef bodyDef;
    bodyDef.type = b2_kinematicBody;//isKinematic ? b2_kinematicBody : b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.angle = rotation;

    mpB2Body = GetGameObject()->GetScene()->mB2World.CreateBody(&bodyDef);

    b2PolygonShape shape;
    shape.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;//mDensity;
    fixtureDef.friction = 0.3f;//mFriction;

    mpB2Body->CreateFixture(&fixtureDef);
}