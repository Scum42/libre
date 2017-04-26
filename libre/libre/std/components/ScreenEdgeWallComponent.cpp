#include "ScreenEdgeWallComponent.h"
#include "libre/util/LibreMath.h"

void libre::ScreenEdgeWallComponent::Initialize()
{
    b2BodyDef bodydefs[4];
    b2PolygonShape boxes[4];

    Vector2f screenHalfDim = (Vector2f)Game::GetWindow()->GetDimensions();
    float halfThickness = 20;

    screenHalfDim *= 0.5f * PIXEL_TO_METER_FACTOR;
    halfThickness *= 0.5f * PIXEL_TO_METER_FACTOR;

    for (int i = 0; i < 4; ++i)
    {
        if (i % 2 == 0)
        {
            float ypos = i == 0 ? -halfThickness : screenHalfDim.y * 2 + halfThickness;
            bodydefs[i].position.Set(screenHalfDim.x, ypos);
            boxes[i].SetAsBox(screenHalfDim.x, halfThickness);
        }
        else
        {
            float xpos = i == 1 ? -halfThickness : screenHalfDim.x * 2 + halfThickness;
            bodydefs[i].position.Set(xpos, screenHalfDim.y);
            boxes[i].SetAsBox(halfThickness, screenHalfDim.y);
        }

        bodydefs[i].type = b2_kinematicBody;
        mpB2bodies[i] = Game::GetCurrentScene()->internal_GetB2World()->CreateBody(bodydefs + i);
        mpB2bodies[i]->CreateFixture(boxes + i, 1.0f);
    }
}

void libre::ScreenEdgeWallComponent::Cleanup()
{
    for (int i = 0; i < 4; ++i)
    {
        Game::GetCurrentScene()->internal_GetB2World()->DestroyBody(mpB2bodies[i]);
    }
}
