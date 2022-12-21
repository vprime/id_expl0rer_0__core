#include <engine/engine.h>
#include <iostream>
#include "engine/app.h"
#include "engine/graphics.h"

Graphics::Texture texture;

class InitializeApp : public Engine::IEventObserver
{
public:
    virtual void Notify()
    {
        // Create texture from bitmap file
        texture = Graphics::Bitmap(bitmapPath.c_str());
    }
    std::string bitmapPath;
} initializer;

void UpdateLoop()
{
    // Render bitmap that was created
}


app::app::app(Player::Player* player)
{
    player = player;
    initializer.bitmapPath = player->resourceDirectory + "/tilesets/outside-ground-small-pallette.bmp";

    mainLoop = new Engine::Loop;
    mainLoop->OnInitialize.AddObserver(&initializer);

}
