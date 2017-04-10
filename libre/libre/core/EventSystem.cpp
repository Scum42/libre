#include "EventSystem.h"

void libre::EventSystem::Initialize()
{
    if (!spInstance) spInstance = new EventSystem();
}

libre::EventSystem* libre::EventSystem::GetInstance()
{
    Initialize();
    return spInstance;
}

void libre::EventSystem::Register(EventListenerComponent* listener, int type)
{
    mListeners[type].push_back(listener);
}

void libre::EventSystem::Deregister(EventListenerComponent* listener, int type)
{
    // Get a reference to the relevant list
    auto& list = mListeners[type];
    
    // Set up an iterator and loop
    auto iter = list.begin();
    for (; iter != list.end(); iter++)
    {
        // Break when the iterator points to the thing we're trying to remove
        if (*iter == listener) break;
    }

    // If we found the listener, erase it
    if (iter != list.end()) list.erase(iter);
}

void libre::EventSystem::Deregister(EventListenerComponent* listener)
{
    for (auto iter : mListeners)
    {
        Deregister(listener, iter.first);
    }
}

void libre::EventSystem::FireEvent(Event e)
{
    auto& list = mListeners[e.GetType()];
    for (EventListenerComponent* elc : list)
    {
        elc->mQueue.push(e);
    }
}

libre::EventSystem* libre::EventSystem::spInstance = nullptr;
