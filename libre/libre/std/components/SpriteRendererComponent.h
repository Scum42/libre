#pragma once

#include <string>

#include "libre/core/Component.h"
#include "libre/util/LibreMath.h"

#include "libre/util/Time.h"
#include "libre/core/GameObject.h"

#include "BoundingBoxComponent.h"

namespace libre
{
    class Sprite;
    class Renderer;

    class SpriteRendererComponent : public Component
    {
    public:
        // Render from Component
        virtual void Render() override;

        // Set the sprite that will be rendered
        Sprite* SetSprite(Sprite* sprite);
        // Set the sprite that will be rendered
        Sprite* SetSprite(std::string filename);
        // Set the sprite that will be rendered
        Sprite* SetSprite(std::string filename, Recti spriteRect);

        // Get the sprite that this component renders
        Sprite* GetSprite() { return mpSprite; }

        // Add a BoundingBoxComponent with my dimensions
        BoundingBoxComponent* AddBoundingBoxComponent();

    private:
        Sprite* mpSprite;
    };
}