#include "Kowal.h"
#include "../../Input/Input.h"
#include <SDL2/SDL_render.h>

Kowal::Kowal(Attributes* attributes, Properties* properties) : Ship(attributes, properties){

}

SDL_Vertex* Kowal::getVertices(){
    return m_Vertices;
}

void Kowal::Draw(){
    SDL_Log("Draw");
}

void Kowal::Update(float dt){
    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_W)){
        MoveFoward();
    }
        if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D)){
        RotateRight();
    }
        if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A)){
        RotateLeft();
    }
}

void Kowal::MoveFoward(){
    SDL_Log("Forward");
}

void Kowal::RotateRight(){
    SDL_Log("Right");
}

void Kowal::RotateLeft(){
    SDL_Log("Left");
}

void Kowal::Clean(){
    SDL_Log("Clean");
}