#include "GroundBoxComponent.h"

#include "libre/core/GameObject.h"
#include "libre/core/Scene.h"
#include "libre/core/Game.h"
#include "libre/std/components/RectRendererComponent.h"

void libre::GroundBoxComponent::Initialize()
{
    mpB2WorldFromScene = GetGameObject()->GetScene()->internal_GetB2World();
    float ptom = GetGameObject()->GetScene()->GetMetersPerPixel();
    float mtop = GetGameObject()->GetScene()->GetPixelsPerMeter();

    Vector2f dim = Game::GetInstance()->GetWindow()->GetDimensions();

    Vector2f finalpos;
    finalpos.x = dim.x * 0.5f;
    finalpos.y = dim.y - (mGroundHeight * 0.5f);
    finalpos *= ptom;

    Vector2f finaldim;
    finaldim.x = dim.x * 0.5f;
    finaldim.y = mGroundHeight * 0.5f;
    mHeight = finaldim.y;
    finaldim *= ptom;

    mWidth = dim.x;
    mHeight = mGroundHeight;

    mB2GroundBoxDef.position.Set(finalpos.x, finalpos.y);
    mB2GroundBoxDef.type = b2_kinematicBody;
    mpB2GroundBoxBody = mpB2WorldFromScene->CreateBody(&mB2GroundBoxDef);
    mB2GroundBox.SetAsBox(finaldim.x, finaldim.y);
    mpB2GroundBoxBody->CreateFixture(&mB2GroundBox, 0.0f);

    GetGameObject()->transform.position.x = mpB2GroundBoxBody->GetPosition().x * mtop - dim.x * 0.5f;
    GetGameObject()->transform.position.y = mpB2GroundBoxBody->GetPosition().y * mtop - mGroundHeight * 0.5f;
}

void libre::GroundBoxComponent::Startup()
{
    RectRendererComponent* rrc = GetGameObject()->GetComponent<RectRendererComponent>();

    if (rrc)
    {
        rrc->SetColor(Color(20, 20, 20));
        rrc->SetWidth(mWidth);
        rrc->SetHeight(mHeight);
    }
}
