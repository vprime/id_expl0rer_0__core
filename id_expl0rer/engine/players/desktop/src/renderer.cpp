#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <iostream>
#include "../include/player/desktop_renderer.h"


void DesktopPlayer::Renderer::Draw(const Graphics::Texture* texture)
{
    std::cout << "Desktop Renderer Draw" << std::endl;
    RenderTexture renderTexture = RenderTexture(texture);
    std::cout << "RenderTexture created, drawing to window." << std::endl;
    window.draw(renderTexture);
}

void DesktopPlayer::Renderer::Clear()
{
    window.clear();
}

DesktopPlayer::Renderer::Renderer()
{
    this->window.create(sf::VideoMode(800, 600), "Test Window");
}

Math::Vector2Short DesktopPlayer::Renderer::GetViewport()
{
    const sf::Vector2u windowSize = window.getSize();
    return Math::Vector2Short(windowSize.x, windowSize.y);
}

DesktopPlayer::RenderTexture::RenderTexture(const Graphics::Texture* texture)
{
    m_Texture = texture;
}

void DesktopPlayer::RenderTexture::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    std::cout << "Drawing Render Texture" << std::endl;
    glClear(GL_COLOR_BUFFER_BIT);
    glRasterPos2i(0, 0);
    glDrawPixels(m_Texture->width, m_Texture->height, GL_COLOR_INDEX, GL_UNSIGNED_BYTE, m_Texture->pixels.data());
    glFlush();
}
