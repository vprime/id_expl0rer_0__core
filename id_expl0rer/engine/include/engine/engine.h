#pragma once
#include <time.h>

namespace engine {
    class mainLoop {
        public:
            mainLoop();
            void update();
            bool running;
            long long frame;
            long long milliseconds;
            long long deltatime;
        private:
            long long start;
    };
}