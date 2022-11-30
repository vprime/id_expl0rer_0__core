#ifndef ID_EXPL0RER_DEVELOPMENT_GRAPHICS_H
#define ID_EXPL0RER_DEVELOPMENT_GRAPHICS_H

#include "math.h"

namespace Graphics
{
    struct Color
    {
    public:
        Color();
        Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 0xFF);
        static Color Blend(Color * a, Color * b);
        unsigned char red;
        unsigned char green;
        unsigned char blue;
        unsigned char alpha;
    };

    class Texture
    {
    public:
        Texture(short width, short height);
        short width;
        short height;
        std::vector<Color> pixels;
    };

#include "core.h"

    class IDrawable : public Engine::SceneComponent
    {
    public:
        virtual const Texture* GetTexture() = 0;
        virtual ~IDrawable() = 0;
    };

    class Renderer
    {
    public:
        virtual void Draw(const Texture* texture) = 0;
        virtual void Clear() = 0;
        virtual Math::Vector2Short GetViewport() = 0;
    };



    class Sprite : public IDrawable
    {
    public:
        Texture* texture;
    };

    class Camera : Engine::SceneComponent
    {
    public:
        Graphics::Texture * renderTexture;
        void Render();
    private:
        Texture m_RenderTexture;
        std::vector<Engine::Layer *> m_Layers;
    };

}
#endif //ID_EXPL0RER_DEVELOPMENT_GRAPHICS_H
