#include <engine/engine.h>
#include <iostream>
#include "engine/app.h"
#include "engine/graphics.h"

Graphics::Texture texture;
std::string bitmapLocalPath("/tilesets/outside-ground-small-pallette.bmp");

class InitializeApp : public Engine::IEventObserver
{
public:
    virtual void Notify()
    {
        // Create texture from bitmap file
        texture = Graphics::Bitmap(path);
        std::cout << "Texture created at: " << &texture << std::endl;
        std::cout << "Width:" << texture.width << " Height:" << texture.height << " Size:" << texture.pixels.size() << std::endl;
    }
    std::string path;
} initializer;

class RenderUpdate : public Engine::IEventObserver
{
public:
    virtual void Notify()
    {
        std::cout << "Render Update!" << std::endl;
        app->player->renderer.Draw(&texture);
        std::cout << "Drawing Completed!" << std::endl;
    }
    App::App * app;
} renderUpdate;

App::App::App(Player::Player* player)
{
    this->player = player;
    initializer.path = std::string(this->player->resourceDirectory + bitmapLocalPath);

    std::cout << "Path Set: " << initializer.path << std::endl;
    mainLoop = new Engine::Loop;
    mainLoop->OnInitialize.AddObserver(&initializer);
    renderUpdate.app = this;
    mainLoop->OnUpdate.AddObserver(&renderUpdate);
    std::cout << "Observers added" << std::endl;
}
