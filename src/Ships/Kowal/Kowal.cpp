#include "Kowal.h"
#include "../../Input/Input.h"
#include <SDL2/SDL_render.h>

Kowal::Kowal(Attributes* attributes, Properties* properties) : Ship(attributes, properties){
    v0 = {{properties->X, properties->Y - 20}, {255, 0, 0, 255}, {1, 1}};
    v1 = {{properties->X - 10, properties->Y + 10}, {255, 0, 0, 255}, {1, 1}};
    v2 = {{properties->X + 10, properties->Y + 10}, {255, 0, 0, 255}, {1, 1}};

    m_Vertices[0] = v0;
    m_Vertices[1] = v1;
    m_Vertices[2] = v2;

    SDL_Log("V1 pos x: %f\n", m_Vertices[0].position.x);
    SDL_Log("V1 pos y: %f \n\n", m_Vertices[0].position.y );

    SDL_Log("V2 pos x: %f\n", m_Vertices[1].position.x);
    SDL_Log("V2 pos y: %f \n\n", m_Vertices[1].position.y );

    SDL_Log("V3 pos x: %f\n", m_Vertices[2].position.x);
    SDL_Log("V3 pos y: %f \n\n", m_Vertices[2].position.y);

    angle = 90;
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