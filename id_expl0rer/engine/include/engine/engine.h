#pragma once
#include <time.h>
#include <functional>
#include <list>

namespace Engine
{
    class IEventObserver
    {
    public:
        virtual void Notify() = 0;
    };

    class IEvent
    {
    public:
        IEvent();
        virtual void AddObserver( IEventObserver* eventObserver );
        virtual void RemoveObserver( IEventObserver* eventObserver );
        void Trigger();
    private:
        std::list<IEventObserver*> m_Actions;
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
        IEvent OnInitialize;
        IEvent OnUpdate;
        IEvent OnRender;
        IEvent OnEndUpdate;
        IEvent OnEndLoop;

    private:
        long long m_Start;
        bool m_Initialized;
        void Initialize();
    };
}
