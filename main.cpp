#include "src/Core/Engine.h"
#include "src/Input/Input.h"

//WTM: can't close window
//kill PID or
//kill -9 $(jobs -p)

int main(int argc, char* args[]){

    Engine::GetInstance()->Init();
    
    while(Engine::GetInstance()->IsRunning()){
        Engine::GetInstance()->Events();
        Engine::GetInstance()->Render();

        if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_ESCAPE)){
            Engine::GetInstance()->Quit();
        }
    }

    Engine::GetInstance()->Clean();

    return 0;
}