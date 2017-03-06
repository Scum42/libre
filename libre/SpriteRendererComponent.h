#pragma once

#include "Component.h"

namespace libre
{
    class Sprite;
    class Renderer;

    class SpriteRendererComponent : public Component
    {
        DEFINE_TYPE_ID(SpriteRendererComponent)

    public:
        // Constructor: give renderer reference
        SpriteRendererComponent(Renderer* rend); // TODO: This is temporary

        // Render from Component
        virtual void Render() override;

        // Set the sprite that will be rendered
        void SetSprite(Sprite* sprite);

    private:
        Sprite* mpSprite;
        Renderer* mpRenderer;
    };
}