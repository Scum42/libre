#pragma once

namespace libre
{
    // These are built-in event types as an enum. Because it is used as an int,
    // in projects, you can create your own enum for custom events and start
    // the first element at CUSTOM_EVENT_START.

    enum EventType
    {
        MOUSE_MOVED = 0,

        CUSTOM_EVENT_START
    };
}