#include <cstdio>
#include <climits>
#include <csignal>
#include "engine/player.h"

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

Player::Player::Player()
{
    this->resourceDirectory = GetCurrentWorkingDirectory() + "/resource";
}