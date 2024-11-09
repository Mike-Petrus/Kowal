#include "Engine.h"

Engine* Engine::s_Instance = nullptr;

bool Engine::Init(){

    if (SDL_Init(SDL_INIT_VIDEO) !=0 || IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) !=3){
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }

    m_Window = SDL_CreateWindow("Kowal", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (m_Window == nullptr){
        SDL_Log("Failed to create Window: %s", SDL_GetError());
        return false;
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_Renderer == nullptr){
        SDL_Log("Failed to created renderer: %s", SDL_GetError());
        return false;
    }

    return m_IsRunning = true;
}

void Engine::Render(){
    SDL_RenderClear(m_Renderer);
    SDL_RenderPresent(m_Renderer);
}

void Engine::Clean(){
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    IMG_Quit();
    SDL_Quit();
}

void Engine::Quit(){
    m_IsRunning = false;
}