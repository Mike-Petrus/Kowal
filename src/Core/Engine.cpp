#include "Engine.h"
#include "../Ships/Kowal/Kowal.h"
#include "../Input/Input.h"
#include "../Timer/Timer.h"
#include <SDL2/SDL_render.h>

Engine* Engine::s_Instance = nullptr;;
Kowal* player = nullptr;

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

    player = new Kowal(new Attributes(10, 10, 0, 2, 10), new Properties(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 20, 30));

    return m_IsRunning = true;
}

void Engine::Update(){
    float dt = Timer::getInstance()->GetDeltaTime();
    player->Update(dt);
}

void Engine::Render(){
    SDL_RenderClear(m_Renderer);
    SDL_RenderGeometry(m_Renderer, nullptr, player->getVertices(), 3, nullptr, 0);

    player->Draw();
    SDL_RenderPresent(m_Renderer);
}

void Engine::Events(){
    Input::GetInstance()->Listen();
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