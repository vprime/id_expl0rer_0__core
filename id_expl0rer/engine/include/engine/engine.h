#pragma once
#include <time.h>

namespace Engine
{
    class MainLoop
    {
    public:
        MainLoop();
        bool Update();
        bool running;
        long long frame;
        long long milliseconds;
        long long deltatime;
    private:
        long long m_Start;
    };
}
