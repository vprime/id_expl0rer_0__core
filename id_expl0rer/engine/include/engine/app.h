#ifndef ID_EXPL0RER_DEVELOPMENT_APP_H
#define ID_EXPL0RER_DEVELOPMENT_APP_H

#include "engine.h"
#include "player.h"
namespace App{
    class App{
        public:
            explicit App(Player::Player* player);
            Engine::Loop* mainLoop;
            Player::Player* player;

    };
}


#endif //ID_EXPL0RER_DEVELOPMENT_APP_H
