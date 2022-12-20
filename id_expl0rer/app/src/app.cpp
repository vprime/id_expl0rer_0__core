//
// Created by nohbu on 11/17/2022.
//

#include <engine/engine.h>
#include "engine/app.h"
#include "engine/graphics.h"

Graphics::Texture texture;

void InitalizeApp()
{
    // Create texture from bitmap file
    texture = Graphics::Bitmap("app/data/tilesets/outside-ground-small-pallette.bmp");

}

void UpdateLoop()
{
    // Render bitmap that was created
}


app::app::app()
{
    mainLoop = new Engine::Loop;
    mainLoop->OnInitialize.AddListener(&InitalizeApp);

}
