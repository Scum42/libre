#pragma once

#include <iostream>

#include "libre/core/Component.h"
#include "libre/util/Time.h"

namespace libre
{
    class TimeOutputComponent : public Component
    {
    public:
        inline virtual void Update() { std::cout << "dt: " << Time::deltaTime << std::endl << "tt: " << Time::totalTime << std:: endl; }
    };
}