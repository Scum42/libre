#pragma once

#include <unordered_map>
#include <vector>

#include "libre/std/components/EventListenerComponent.h"
#include "libre/core/Event.h"

namespace libre
{
    class EventSystem
    {
    public:
        // static

        // Create the instance if it doesn't exist
        static void Initialize();

        // 
        static EventSystem* GetInstance();

        // non-static
        
        // Register a listener component to the system
        void Register(EventListenerComponent* listener, int type);

        // Deregister a listener from a specific event
        void Deregister(EventListenerComponent* listener, int type);

        // Deregister a listener from all events
        void Deregister(EventListenerComponent* listener);

        // Deregister all
        inline void DeregisterAll() { mListeners.clear(); }

        // Fire an event
        void FireEvent(Event e);

    private:
        // static

        static EventSystem* spInstance;

        // non-static

        EventSystem() { /* Do nothing -- only here to make sure the constructor is private */ }
        ~EventSystem() { /* Do nothing -- only here to make sure the destructor is private */ }

        std::unordered_map<int, std::vector<EventListenerComponent*>> mListeners;
    };
}
