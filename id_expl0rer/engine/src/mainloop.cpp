

#include <engine/engine.h>
#include <stdint.h>
#include <iostream>

typedef int64_t msec_t;
#if defined(__WIN32__)

#include <sysinfoapi.h>

msec_t time_ms(void)
{
    return GetTickCount();
}

#else

#include <sys/time.h>

msec_t time_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (msec_t)tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

#endif


Engine::Loop::Loop()
{
    milliseconds = 0;
    running = false;
    frame = 0;
    deltatime = 0;
    m_Start = time_ms();
    m_Initialized = false;
}


bool Engine::Loop::Update()
{
    long long now = time_ms();
    long long  newMilliseconds = now - m_Start;
    deltatime = newMilliseconds - milliseconds;
    milliseconds = newMilliseconds;
    std::cout << "Time: " << milliseconds << "Frame: " << frame << std::endl;
    frame++;

    Initialize();
    this->OnUpdate.Trigger();
    this->OnRender.Trigger();
    this->OnEndUpdate.Trigger();

    return !(milliseconds > 3000 || frame > 3000);
}

void Engine::Loop::Initialize()
{
    if (this->m_Initialized == true)
        return;
    this->OnInitialize.Trigger();
    this->m_Initialized = true;
}
