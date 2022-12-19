#include <engine/engine.h>
#include <iostream>


void Engine::Event::AddListener(void (*listener)())
{
    this->m_Actions.push_back((long long)&listener);
}

void Engine::Event::Trigger()
{
    for(auto i = 0; i < this->m_Actions.size(); i++)
    {
        void (*function)() = (void(*)())this->m_Actions[i];
        function();
    }
}