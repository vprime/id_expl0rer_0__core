#import <vector>
#include <typeinfo>
#import "engine/graphics.h"

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

Graphics::Texture::Texture(short width, short height)
{
    this->width = width;
    this->height = height;
}


void Graphics::Camera::Render()
{
    if (!renderTexture)
    {
        renderTexture = &m_RenderTexture;
    }
    // Initialize the render texture.
    auto cameraSize = transform.bounds.GetSize();
    if ((short)cameraSize.X != m_RenderTexture.width
    || (short)cameraSize.Y != m_RenderTexture.height)
    {
        m_RenderTexture = *new Texture(
                (short)cameraSize.X,
                (short)cameraSize.Y);
    }

    // Get all the drawables from the layers within the bounds
    std::vector<IDrawable *> drawables;
    for(int il = 0;  il < m_Layers.size(); il++)
    {
        for(int ic = 0; ic < m_Layers[il]->components.size(); ic++)
        {
            if (transform.bounds.Intersects(&m_Layers[il]->components[ic]->transform.bounds))
            {
                auto* drawableComponent = dynamic_cast<Graphics::IDrawable*>(m_Layers[il]->components[ic]);
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
        auto* drawnTexture = drawables[id]->GetTexture();
        auto* drawnBounds = &drawables[id]->transform.bounds;
        Math::Vector2Int viewportMin = transform.bounds.GetMin();
        Math::Vector2Int viewportSize = transform.bounds.GetSize();

        auto visibleBounds = Math::BoundsInt::Intersection(drawnBounds, &transform.bounds);
        Math::Vector2Int visibleBoundsMin = visibleBounds.GetMin();
        Math::Vector2Int visibleBoundsMax = visibleBounds.GetMax();
        Math::Vector2Int cursor = visibleBounds.GetMin();
        Math::Vector2Int drawnBoundsMin = drawnBounds->GetMin();
        Math::Vector2Int drawnBoundsMax = drawnBounds->GetMax();
        Math::Vector2Int drawnBoundsSize = drawnBounds->GetSize();

        bool drawing = true;
        while (drawing)
        {
            // Get drawableTexture pixel index from cursor position.
            int dtIndex = cursor.X - drawnBoundsMin.X + ((cursor.Y - drawnBoundsMin.Y) * drawnBoundsSize.X);
            // Get pixel from index in drawnTexture;
            Graphics::Color pixel = drawnTexture->pixels[dtIndex];
            // Get renderTexture pixel index from cursor position
            int rtIndex = cursor.X - viewportMin.X + ((cursor.Y - viewportMin.Y) * viewportSize.X);
            auto currentPixel = m_RenderTexture.pixels[rtIndex];
            // Blend pixel into renderTexture
            m_RenderTexture.pixels[rtIndex] = Color::Blend(&currentPixel, &pixel);
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
                drawing = false;
                break;
            }
            cursor.X = nextX;
            cursor.Y = nextY;
        }
    }

}