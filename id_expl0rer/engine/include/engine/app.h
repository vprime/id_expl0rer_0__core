//
// Created by nohbu on 11/17/2022.
//

#ifndef ID_EXPL0RER_DEVELOPMENT_APP_H
#define ID_EXPL0RER_DEVELOPMENT_APP_H

#include "engine.h"
#include "player.h"
namespace app{
    class app{
        public:
            app(Player::Player* player);
            Engine::Loop* mainLoop;
            Player::Player* player;

    };
}


#endif //ID_EXPL0RER_DEVELOPMENT_APP_H
