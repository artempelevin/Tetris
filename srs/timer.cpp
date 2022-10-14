#ifdef WINDOWS
#include <SDL_timer.h>
#endif // WINDOWS
#ifdef LINUX

#include <SDL2/SDL_timer.h>

#endif // LINUX

#include "timer.h"

Timer::Timer() {
    time = SDL_GetTicks();
}

bool Timer::isPass(int millisecond) {
    SDL_Delay(2);
    if (SDL_GetTicks() - time >= millisecond) {
        time = SDL_GetTicks();
        return true;
    }
    return false;
}

