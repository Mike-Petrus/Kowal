#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include "../Timer/Timer.h"

Timer* Timer::s_Instance = nullptr;

void Timer::Tick(){
    m_DeltaTime = (SDL_GetTicks() - m_LastTime) * (TARGET_FPS/1000.0f);

    if (m_DeltaTime > TARGET_DELTATIME){
        m_DeltaTime = 1.5f;
    }

    m_LastTime = SDL_GetTicks();
}