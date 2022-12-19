#pragma once
#include <time.h>
#include <functional>
#include <vector>

namespace Engine
{
    class Event
    {
    public:
        void AddListener( void (*listener)() );
        void Trigger();
    private:
        std::vector<long long> m_Actions;
    };

    class Loop
    {
    public:
        Loop();
        bool Update();
        bool running;
        long long frame;
        long long milliseconds;
        long long deltatime;
        Event OnInitialize;
        Event OnUpdate;
        Event OnRender;
        Event OnEndUpdate;
        Event OnEndLoop;

    private:
        long long m_Start;
        bool m_Initialized;
        void Initialize();
    };
}
