
#include <engine/app.h>
#include <iostream>

Player::Player player;
app::app mainApp(&player);

int main(int argc, char **argv)
{

    std::cout << "Starting app ";

    bool appRunning = true;
    while (appRunning)
    {
        appRunning = mainApp.mainLoop->Update();
    }
    return 3;
}
