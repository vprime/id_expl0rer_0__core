#include <engine/engine.h>


void Engine::Event::AddListener(void (*listener)())
{
    this->m_Actions.push_back((long long)&listener);
}

void Engine::Event::Trigger()
{
    for(int i = 0; i < this->m_Actions.size(); i++)
    {
        void (*function)() = (void(*)())this->m_Actions[i];
        function();
    }
}

Engine::Event::Event()
{
    m_Actions.clear();
}
