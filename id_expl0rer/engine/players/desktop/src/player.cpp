#include <cstdio>
#include <climits>
#include <io.h>
#include "engine/player.h"
#include "player/desktop_renderer.h"

std::string GetCurrentWorkingDirectory()
{
    char buffer[PATH_MAX];
    if (getcwd(buffer, sizeof(buffer)) != NULL) {
        printf("Current working directory : %s\n", buffer);
        return (std::string)buffer;
    } else {
        perror("getcwd() error");
    }
    return "/";
}

Player::Player::Player(Graphics::Renderer &renderer) : renderer(renderer) {
    this->resourceDirectory = GetCurrentWorkingDirectory() + "/resource";
}