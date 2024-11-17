#include "Kowal.h"
#include "../../Input/Input.h"
#include <SDL2/SDL_render.h>
#include <linalg.h>

Kowal::Kowal(Attributes* attributes, Properties* properties) : Ship(attributes, properties){
    v0 = {{properties->X, properties->Y - 20}, {255, 0, 0, 255}, {1, 1}};
    v1 = {{properties->X - 10, properties->Y + 10}, {255, 0, 0, 255}, {1, 1}};
    v2 = {{properties->X + 10, properties->Y + 10}, {255, 0, 0, 255}, {1, 1}};

    m_Vertices[0] = v0;
    m_Vertices[1] = v1;
    m_Vertices[2] = v2;

    m_Direction = linalg::normalize(Vec2f{v0.position.x - properties->X, v0.position.y - properties->Y});
    m_Angle = 90;

    SDL_Log("V1 pos x: %f\n", m_Vertices[0].position.x);
    SDL_Log("V1 pos y: %f \n\n", m_Vertices[0].position.y );

    SDL_Log("V2 pos x: %f\n", m_Vertices[1].position.x);
    SDL_Log("V2 pos y: %f \n\n", m_Vertices[1].position.y );

    SDL_Log("V3 pos x: %f\n", m_Vertices[2].position.x);
    SDL_Log("V3 pos y: %f \n\n", m_Vertices[2].position.y);

    SDL_Log("Direction x: %f\n", m_Direction.x);
    SDL_Log("Direction y: %f\n\n", m_Direction.y);
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
    m_Vertices[0].position.x += m_Direction.x * m_SPD;
    m_Vertices[0].position.y += m_Direction.y * m_SPD;

    m_Vertices[1].position.x += m_Direction.x * m_SPD;
    m_Vertices[1].position.y += m_Direction.y * m_SPD;

    m_Vertices[2].position.x += m_Direction.x * m_SPD;
    m_Vertices[2].position.y += m_Direction.y * m_SPD;
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