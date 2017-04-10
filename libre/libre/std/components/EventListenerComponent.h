#pragma once

#include <queue>
#include "libre/core/Component.h"
#include "libre/core/Event.h"

namespace libre
{
    class EventSystem;

    class EventListenerComponent : public Component
    {
    public:
        friend EventSystem;

        // TODO: EventListenerComponent

    private:
        std::queue<Event> mQueue;
    };
}