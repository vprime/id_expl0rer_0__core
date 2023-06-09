
#include <engine/app.h>
#include <iostream>

Player::Player player;
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
