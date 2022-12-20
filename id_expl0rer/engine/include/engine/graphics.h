#ifndef ID_EXPL0RER_DEVELOPMENT_GRAPHICS_H
#define ID_EXPL0RER_DEVELOPMENT_GRAPHICS_H

#include <vector>
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

    struct Palette
    {
    public:
        Palette();
        explicit Palette(Color colors[256]);
        Color colors[256];
    };

    struct PaletteMap
    {
    public:
        PaletteMap();
        explicit PaletteMap(const unsigned char map[256]);
        unsigned char map[256];
        const Color Get(Palette palette, unsigned char index) const;

    };

    class Texture
    {
    public:
        Texture(short width, short height, Palette palette, PaletteMap paletteMap);
        Texture();
        short width;
        short height;
        Palette palette;
        PaletteMap paletteMap;
        std::vector<unsigned char> pixels;
        const Color GetColorAtIndex(unsigned int index) const;
        const unsigned char GetPaletteColorAtIndex(unsigned int index) const;
        const Color GetColorAtPoint(short x, short y);
        const static unsigned int GetIndex(short x, short y, short width);
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
        virtual void Draw(const Graphics::Texture* texture) = 0;
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
        Palette m_Palette;
        PaletteMap m_PaletteMap;
        std::vector<Engine::Layer *> m_Layers;
    };

    class Bitmap : public Texture
    {
    public:
        Bitmap(const char *filepath);

    };

}
#endif //ID_EXPL0RER_DEVELOPMENT_GRAPHICS_H
