#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include "../include/player/desktop_renderer.h"


void DesktopPlayer::Renderer::Draw(const Graphics::Texture* texture)
{
    RenderTexture renderTexture = RenderTexture(texture);
    window.draw(renderTexture);
}

DesktopPlayer::RenderTexture::RenderTexture(const Graphics::Texture* texture)
{
    m_Texture = texture;
}

void DesktopPlayer::RenderTexture::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    glClear(GL_COLOR_BUFFER_BIT);
    glRasterPos2i(0, 0);
    glDrawPixels(m_Texture->width, m_Texture->height, GL_RGBA, GL_UNSIGNED_BYTE, m_Texture->pixels.data());
    glFlush();
}
