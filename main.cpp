#include "src/Core/Engine.h"
#include <unistd.h>

//WTM: can't close window
//kill PID or
//kill -9 $(jobs -p)

int main(int argc, char* args[]){

    Engine::GetInstance()->Init();
    
    while(Engine::GetInstance()->IsRunning()){
        Engine::GetInstance()->Render();
    }

    Engine::GetInstance()->Clean();

    return 0;
}