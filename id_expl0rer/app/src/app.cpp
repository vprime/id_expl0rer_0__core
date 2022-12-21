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
    }
    std::string path;
} initializer;

void UpdateLoop()
{
    // Render bitmap that was created
}


app::app::app(Player::Player* player)
{
    this->player = player;
    initializer.path = std::string(this->player->resourceDirectory + bitmapLocalPath);
    std::cout << "Path Set: " << initializer.path << std::endl;
    mainLoop = new Engine::Loop;
    mainLoop->OnInitialize.AddObserver(&initializer);

}
