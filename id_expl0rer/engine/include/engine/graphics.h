//
// Created by nohbu on 11/21/2022.
//

#ifndef ID_EXPL0RER_DEVELOPMENT_GRAPHICS_H
#define ID_EXPL0RER_DEVELOPMENT_GRAPHICS_H
#include "math.h"
#include "core.h"

namespace Graphics
{
    struct Color
    {
    public:
        unsigned char red;
        unsigned char green;
        unsigned char blue;
        unsigned char alpha;
    };

    class Texture
    {
    public:
        short width;
        short height;
        Color* pixels;
    };

    class IDrawable
    {
    public:
        const Texture* Draw(unsigned int width, unsigned int height);
    };

    class Renderer
    {
    public:
        void Draw(IDrawable *drawable);
        void Clear();
        int ViewportWidth;
        int ViewportHeight;
    };

    class Sprite : IDrawable
    {
    public:
        Engine::Transform transform;
        Texture* texture;
    };

}
#endif //ID_EXPL0RER_DEVELOPMENT_GRAPHICS_H
