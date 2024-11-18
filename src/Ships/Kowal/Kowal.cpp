#include "Kowal.h"
#include "../../Input/Input.h"
#include <SDL2/SDL_render.h>
#include <linalg.h>

Kowal::Kowal(Attributes* attributes, Properties* properties) : Ship(attributes, properties){
    v0 = {{m_Transform->X}, {m_Transform->Y - 20}};
    v1 = {{m_Transform->X - 10}, {m_Transform->Y + 10}};
    v2 = {{m_Transform->X + 10}, {m_Transform->Y + 10}};

    m_Vertices[0] = {{v0.x, v0.y}, {255, 0, 0, 255}, {1, 1}};
    m_Vertices[1] = {{v1.x, v1.y}, {255, 0, 0, 255}, {1, 1}};
    m_Vertices[2] = {{v2.x, v2.y}, {255, 0, 0, 255}, {1, 1}};

    m_Direction = linalg::normalize(Vec2f{v0.x - m_Transform->X, v0.y - m_Transform->Y});

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
        Rotate(1);
    }
        if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A)){
        Rotate(-1);
    }
}

void Kowal::MoveFoward(){
    m_Transform->Translate(m_Direction * m_SPD);
    v0 += m_Direction * m_SPD;
    v1 += m_Direction * m_SPD;
    v2 += m_Direction * m_SPD;

    m_Vertices[0].position = {v0.x, v0.y};
    m_Vertices[1].position = {v1.x, v1.y};
    m_Vertices[2].position = {v2.x, v2.y};
}

void Kowal::Rotate(int clockwise){
    m_Angle -= 1;
    v0 = {{v0.x - m_Transform->X}, {v0.y - m_Transform->Y}};
    v1 = {{v1.x - m_Transform->X}, {v1.y - m_Transform->Y}};
    v2 = {{v2.x - m_Transform->X}, {v2.y - m_Transform->Y}};

    v0 = linalg::rot((clockwise * PI / 180), v0);
    v1 = linalg::rot((clockwise * PI / 180), v1);
    v2 = linalg::rot((clockwise * PI / 180), v2);

    v0 = {{v0.x + m_Transform->X}, {v0.y + m_Transform->Y}};
    v1 = {{v1.x + m_Transform->X}, {v1.y + m_Transform->Y}};
    v2 = {{v2.x + m_Transform->X}, {v2.y + m_Transform->Y}};

    m_Vertices[0].position = {v0.x, v0.y};
    m_Vertices[1].position = {v1.x, v1.y};
    m_Vertices[2].position = {v2.x, v2.y};
}

void Kowal::Clean(){
    SDL_Log("Clean");
}