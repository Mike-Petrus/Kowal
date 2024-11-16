#include "Kowal.h"
#include "../Input/Input.h"

Kowal::Kowal(Attributes* attributes, Properties* properties, Vec2f* origin) : Ship(attributes, properties, origin){
    m_Angle = 90;

    v0 = {{origin->x, origin->y - 20}, {255, 0, 0, 255}, {1, 1}};
    v1 = {{origin->x - 10, origin->y + 10}, {255, 0, 0, 255}, {1, 1}};
    v2 = {{origin->x + 10, origin->y + 10}, {255, 0, 0, 255}, {1, 1}};

    m_Vertices[0] = v0;
    m_Vertices[1] = v1;
    m_Vertices[2] = v2;
}

void Kowal::Update(float dt){
    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_W)){
        MoveForward();
    }
    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D)){
        RotateRight();
    }
    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A)){
        RotateLeft();
    }
}