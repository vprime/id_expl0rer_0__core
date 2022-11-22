

#include "renderer.cpp"
#include <engine/app.h>
#include <iostream>

app::app mainApp;

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
