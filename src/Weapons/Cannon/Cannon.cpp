#include "Cannon.h"
#include <SDL2/SDL.h>

Cannon::Cannon(Properties* properties, Vec2f direction) : Weapon(properties, direction){
    m_Direction = new Vec2f(direction.x, direction.y);
    m_FireRate = 10;
}

void Cannon::Fire(){

}

void Cannon::Draw(){

}

void Cannon::Update(float dt){
    SDL_Log("m_position: %f, %f", m_Transform->X, m_Transform->Y);
    SDL_Log("m_direction: %f, %f", m_Direction->x, m_Direction->y);
}

void Cannon::Clean(){

}