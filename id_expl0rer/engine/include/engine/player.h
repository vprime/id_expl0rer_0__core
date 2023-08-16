//
// Created by nohbu on 11/17/2022.
//

#ifndef ID_EXPL0RER_DEVELOPMENT_PLAYER_H
#define ID_EXPL0RER_DEVELOPMENT_PLAYER_H

#include <string>
#include "graphics.h"

namespace Player
{
    class Player
    {
    public:
        Player(Graphics::Renderer &renderer);
        std::string resourceDirectory;
        Graphics::Renderer & renderer;
    };

}

#endif //ID_EXPL0RER_DEVELOPMENT_PLAYER_H

