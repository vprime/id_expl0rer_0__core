

#include <engine/engine.h>
#include <stdint.h>

typedef int64_t msec_t;
#if defined(__WIN32__)

#include <windows.h>

msec_t time_ms(void)
{
    return timeGetTime();
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


engine::mainLoop::mainLoop()
{
    milliseconds = 0;
    running = false;
    frame = 0;
    deltatime = 0;
    start = time_ms();
}

void engine::mainLoop::update()
{
    long long now = time_ms();
    long long  newMilliseconds = now - start;
    deltatime = newMilliseconds - milliseconds;
    milliseconds = newMilliseconds;

    frame++;
}