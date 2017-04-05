#pragma once

#include <string>

#include "libre/core/Component.h"
#include "libre/util/LibreMath.h"

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

    private:
        Sprite* mpSprite;
    };
}