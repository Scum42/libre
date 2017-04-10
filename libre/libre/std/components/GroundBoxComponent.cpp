#include "GroundBoxComponent.h"

#include "libre/core/GameObject.h"
#include "libre/core/Scene.h"
#include "libre/core/Game.h"
#include "libre/std/components/RectRendererComponent.h"

void libre::GroundBoxComponent::Initialize()
{
    mpB2WorldFromScene = GetGameObject()->GetScene()->internal_GetB2World();
    float ptom = GetGameObject()->GetScene()->GetPixelToMeterFactor();
    float mtop = GetGameObject()->GetScene()->GetMeterToPixelFactor();

    Vector2f dim = Game::GetInstance()->GetWindow()->GetDimensions();

    Vector2f finalpos;
    finalpos.x = dim.x * 0.5f;
    finalpos.y = dim.y - (mGroundHeightInPixels * 0.5f);
    finalpos *= ptom;

    Vector2f finaldim;
    finaldim.x = dim.x * 0.5f;
    finaldim.y = mGroundHeightInPixels * 0.5f;
    mHeightInPixels = finaldim.y;
    finaldim *= ptom;

    mWidthInPixels = dim.x;
    mHeightInPixels = mGroundHeightInPixels;

    mB2GroundBoxDef.position.Set(finalpos.x, finalpos.y);
    mB2GroundBoxDef.type = b2_kinematicBody;
    mpB2GroundBoxBody = mpB2WorldFromScene->CreateBody(&mB2GroundBoxDef);
    mB2GroundBox.SetAsBox(finaldim.x, finaldim.y);
    mpB2GroundBoxBody->CreateFixture(&mB2GroundBox, 0.0f);

    GetGameObject()->transform.position.x = mpB2GroundBoxBody->GetPosition().x * mtop - dim.x * 0.5f;
    GetGameObject()->transform.position.y = mpB2GroundBoxBody->GetPosition().y * mtop - mGroundHeightInPixels * 0.5f;
}

void libre::GroundBoxComponent::Startup()
{
    RectRendererComponent* rrc = GetGameObject()->GetComponent<RectRendererComponent>();

    if (rrc)
    {
        rrc->SetColor(Color(20, 20, 20));
        rrc->SetWidth(mWidthInPixels);
        rrc->SetHeight(mHeightInPixels);
    }
}

void libre::GroundBoxComponent::Update()
{
    Transform& t = GetGameObject()->transform;
    t.position = mpB2GroundBoxBody->GetPosition();
    t.rotation = mpB2GroundBoxBody->GetAngle() * RAD_TO_DEG_FACTOR;

    t.position *= GetGameObject()->GetScene()->GetMeterToPixelFactor();
    t.position -= { mWidthInPixels * 0.5f, mHeightInPixels * 0.5f };
}
