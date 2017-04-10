#include "GroundBoxComponent.h"

#include "libre/core/GameObject.h"
#include "libre/core/Scene.h"
#include "libre/core/Game.h"

void libre::GroundBoxComponent::Initialize()
{
    mpB2WorldFromScene = GetGameObject()->GetScene()->internal_GetB2World();
    float ptom = GetGameObject()->GetScene()->GetMetersPerPixel();

    Vector2f dim = Game::GetInstance()->GetWindow()->GetDimensions();
    Vector2f pos = GetGameObject()->transform.position;

    Vector2f finalpos;
    finalpos.x = dim.x * 0.5f;
    finalpos.y = pos.y * 0.5f; // If origin is bottom-left
    //finalpos.y = dim.y - (pos.y * 0.5f); // If origin is top-left
    finalpos *= ptom;

    Vector2f finaldim;
    finaldim.x = dim.x * 0.5f;
    finaldim.y = pos.y * 0.5f;
    finaldim *= ptom;

    mB2GroundBoxDef.position.Set(finalpos.x, finalpos.y);
    mB2GroundBoxDef.type = b2_kinematicBody;
    mpB2GroundBoxBody = mpB2WorldFromScene->CreateBody(&mB2GroundBoxDef);
    mB2GroundBox.SetAsBox(finaldim.x, finaldim.y);
    mpB2GroundBoxBody->CreateFixture(&mB2GroundBox, 0.0f);

    GetGameObject()->transform.position.x = mpB2GroundBoxBody->GetPosition().x;
    GetGameObject()->transform.position.y = mpB2GroundBoxBody->GetPosition().y;
}
