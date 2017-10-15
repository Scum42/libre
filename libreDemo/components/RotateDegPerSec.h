#pragma once

#include "libre/libre.h"
using namespace libre;

class RotateDegPerSec : public Component
{
public:

    inline void SetSpeed(float speed) { mSpeed = speed; }
    inline float GetSpeed() { return mSpeed; }

    inline void Update() override { GetGameObject()->transform.rotation += mSpeed * Time::deltaTime; }

private:
    float mSpeed;
};