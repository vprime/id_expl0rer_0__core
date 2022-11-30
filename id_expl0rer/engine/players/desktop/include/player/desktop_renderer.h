//
// Created by nohbu on 11/21/2022.
//

#ifndef ID_EXPL0RER_DEVELOPMENT_DESKTOP_RENDERER_H
#define ID_EXPL0RER_DEVELOPMENT_DESKTOP_RENDERER_H

#include <engine/graphics.h>
#include <SFML/Graphics.hpp>
namespace DesktopPlayer
{
    class Renderer : public Graphics::Renderer
    {
    public:
        void Draw(const Graphics::Texture* texture);
        sf::RenderWindow window;

    };

    class RenderTexture : public sf::Drawable
    {
    public:
        RenderTexture(const Graphics::Texture* texture);

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            glBegin(GL_QUADS);

            glEnd();
        }
    };
}

#endif //ID_EXPL0RER_DEVELOPMENT_DESKTOP_RENDERER_H
