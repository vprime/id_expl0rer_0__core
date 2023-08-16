#include <engine/app.h>
#include <iostream>
#include "player/desktop_renderer.h"

DesktopPlayer::Renderer desktopRenderer;
Player::Player player(desktopRenderer);
App::App mainApp(&player);

int main(int argc, char **argv)
{

    std::cout << "Starting App ";

    bool appRunning = true;
    while (appRunning)
    {
        appRunning = mainApp.mainLoop->Update();
    }
    return 3;
}
