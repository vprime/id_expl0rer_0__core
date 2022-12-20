#include <engine/engine.h>


void Engine::IEvent::AddObserver(IEventObserver* eventObserver)
{
    this->m_Actions.push_back(eventObserver);
}

void Engine::IEvent::Trigger()
{
    std::list<IEventObserver*>::iterator iterator = this->m_Actions.begin();
    while (iterator != this->m_Actions.end())
    {
        (*iterator)->Notify();
        ++iterator;
    }
}

Engine::IEvent::IEvent()
{
    m_Actions.clear();
}

void Engine::IEvent::RemoveObserver(Engine::IEventObserver *eventObserver)
{
    this->m_Actions.remove(eventObserver);
}
