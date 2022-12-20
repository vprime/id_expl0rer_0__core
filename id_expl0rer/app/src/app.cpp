//
// Created by nohbu on 11/17/2022.
//

#include <engine/engine.h>
#include "engine/app.h"
#include "engine/graphics.h"

Graphics::Texture texture;

class InitializeApp : public Engine::IEventObserver
{
public:
    virtual void Notify()
    {
        // Create texture from bitmap file
        texture = Graphics::Bitmap("app/data/tilesets/outside-ground-small-pallette.bmp");

    }
} initializer;

void UpdateLoop()
{
    // Render bitmap that was created
}


app::app::app()
{
    mainLoop = new Engine::Loop;
    mainLoop->OnInitialize.AddObserver(&initializer);

}
