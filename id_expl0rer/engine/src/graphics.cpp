#include <vector>
#include <string>
#include "engine/graphics.h"


Graphics::Color::Color()
{
    this->red = 0x00;
    this->green = 0x00;
    this->blue = 0x00;
    this->alpha = 0xFF;
}

Graphics::Color::Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;
}

Graphics::Color Graphics::Color::Blend(Graphics::Color *a, Graphics::Color *b)
{
    unsigned char alpha = a->alpha + (b->alpha * (255 - a->alpha) / 255);
    unsigned char red = (a->red * a->alpha + b->red * b->alpha * (255 - a->alpha) / 255)/alpha;
    unsigned char green = (a->green * a->alpha + b->green * b->alpha * (255 - a->alpha) / 255)/alpha;
    unsigned char blue = (a->blue * a->alpha + b->blue * b->alpha * (255 - a->alpha) / 255)/alpha;

    return Graphics::Color(red, green, blue, alpha);
}

Graphics::Texture::Texture(short width, short height, Palette palette, PaletteMap paletteMap)
{
    this->width = width;
    this->height = height;
    this->palette = palette;
    this->paletteMap = paletteMap;
}


void Graphics::Camera::Render()
{
    if (!renderTexture)
    {
        renderTexture = &m_RenderTexture;
    }
    // Get the palette and palette map

    // Initialize the render texture.
    Math::Vector2Int cameraSize = transform.bounds.GetSize();
    if ((short)cameraSize.X != m_RenderTexture.width
    || (short)cameraSize.Y != m_RenderTexture.height)
    {
        m_RenderTexture = *new Texture(
                (short)cameraSize.X,
                (short)cameraSize.Y,
                m_Palette, m_PaletteMap);
    }

    // Get all the drawables from the layers within the bounds
    std::vector<IDrawable *> drawables;
    for(int il = 0;  il < m_Layers.size(); il++)
    {
        for(int ic = 0; ic < m_Layers[il]->components.size(); ic++)
        {
            if (transform.bounds.Intersects(&m_Layers[il]->components[ic]->transform.bounds))
            {
                Graphics::IDrawable *drawableComponent;
                drawableComponent = dynamic_cast<Graphics::IDrawable *>(m_Layers[il]->components[ic]);
                if (drawableComponent)
                {
                    drawables.push_back(drawableComponent);
                }
            }
        }
    }

    // Draw each drawable
    for(int id = 0; id < drawables.size(); id++)
    {
        const Texture* drawnTexture = drawables[id]->GetTexture();
        Math::BoundsInt* drawnBounds = &drawables[id]->transform.bounds;
        Math::Vector2Int viewportMin = transform.bounds.GetMin();
        Math::Vector2Int viewportSize = transform.bounds.GetSize();

        Math::BoundsInt visibleBounds = Math::BoundsInt::Intersection(drawnBounds, &transform.bounds);
        Math::Vector2Int visibleBoundsMin = visibleBounds.GetMin();
        Math::Vector2Int visibleBoundsMax = visibleBounds.GetMax();
        Math::Vector2Int cursor = visibleBounds.GetMin();
        Math::Vector2Int drawnBoundsMin = drawnBounds->GetMin();
        Math::Vector2Int drawnBoundsMax = drawnBounds->GetMax();
        Math::Vector2Int drawnBoundsSize = drawnBounds->GetSize();

        while (true)
        {
            // Get drawableTexture pixel index from cursor position.
            int dtIndex = cursor.X - drawnBoundsMin.X + ((cursor.Y - drawnBoundsMin.Y) * drawnBoundsSize.X);
            // Get renderTexture pixel index from cursor position
            int rtIndex = cursor.X - viewportMin.X + ((cursor.Y - viewportMin.Y) * viewportSize.X);
            // Color currentPixel = m_RenderTexture.GetColorAtIndex(rtIndex);
            // Blend pixel into renderTexture
            m_RenderTexture.pixels[rtIndex] = drawnTexture->GetPaletteColorAtIndex(dtIndex);
            // Move cursor into next position, or end drawing.
            int nextX = cursor.X + 1;
            int nextY = cursor.Y;
            if (nextX > visibleBoundsMax.X)
            {
                nextX = visibleBoundsMin.X;
                nextY++;
            }
            if (nextY > visibleBoundsMax.Y)
            {
                break;
            }
            cursor.X = nextX;
            cursor.Y = nextY;
        }
    }

}

Graphics::Palette::Palette() : colors()
{
    for (unsigned int i = 0; i <= 0xff; i++)
    {
        this->colors[i] = *new Color();
    }
}

Graphics::Palette::Palette(Graphics::Color *colors) : colors()
{
    for (unsigned int i = 0; i <= 0xff; i++)
    {
        this->colors[i] = colors[i];
    }
}


Graphics::PaletteMap::PaletteMap() : map()
{
    for (unsigned int i = 0; i <= 0xff; i++)
    {
        this->map[i] = i;
    }
}

Graphics::PaletteMap::PaletteMap(const unsigned char *map) : map()
{
    for (unsigned char i = 0; i <= 0xff; i++)
    {
        this->map[i] = map[i];
    }
}

const Graphics::Color Graphics::PaletteMap::Get(Graphics::Palette palette, unsigned char index) const {
    return palette.colors[map[index]];
}

//Graphics::Texture::Texture(short width, short height, Graphics::Palette palette, Graphics::PaletteMap paletteMap)
//{
//    this->width = width;
//    this->height = height;
//    this->palette = palette;
//    this->paletteMap = paletteMap;
//}

const Graphics::Color Graphics::Texture::GetColorAtIndex(unsigned int index) const
{
    return this->paletteMap.Get(palette, index);
}

const Graphics::Color Graphics::Texture::GetColorAtPoint(short x, short y)
{
    return this->GetColorAtIndex(Graphics::Texture::GetIndex(x, y, this->width));
}

const unsigned Graphics::Texture::GetIndex(short x, short y, short width)
{
    return (y * width) + x;
}

Graphics::Texture::Texture() : width(), height()
{

}

const unsigned char Graphics::Texture::GetPaletteColorAtIndex(unsigned int index) const
{
    return paletteMap.map[index];
}

#include <iostream>
#include <fstream>
Graphics::Bitmap::Bitmap(const char *filepath)
{
    std::streampos size;
    char * memblock;

    std::ifstream file ( filepath, std::ios::in | std::ios::binary | std::ios::ate);
    if (file.is_open())
    {
        size = file.tellg();
        memblock = new char [size];
        file.seekg (0, std::ios::beg);
        file.read (memblock, size);
        file.close();

        std::cout << "the entire file content is in memory";

        delete[] memblock;
    }
    else std::cout << "Unable to open file";

}
