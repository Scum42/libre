#include "BoundingBoxComponent.h"

libre::Vector2f libre::BoundingBoxComponent::SetDimensions(Vector2f dim)
{
    mDimensions = dim;
    mExtents = dim * 0.5f;

    return mDimensions;
}

libre::Vector2f libre::BoundingBoxComponent::SetExtents(Vector2f ext)
{
    mExtents = ext;
    mDimensions = ext * 2.0f;

    return mExtents;
}
