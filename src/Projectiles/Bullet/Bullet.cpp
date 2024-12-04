#include "Bullet.h"
#include "../../Core/Engine.h"
#include <SDL2/SDL_render.h>

Bullet::Bullet() : Projectile(){
    m_Position = {0, 0};
    m_Direction = {0, 0};
    m_Bullet = {m_Position.x, m_Position.y, 2, 2};
    m_SPD = 10;
    m_Active = false;
}

void Bullet::Draw(){
    SDL_RenderDrawRect(Engine::GetInstance()->GetRenderer(), &m_Bullet);
}

void Bullet::Update(float dt){
    if (m_Position.x < 0 || m_Position.x > SCREEN_WIDTH || m_Position.y < 0 || m_Position.y > SCREEN_HEIGHT){
        m_Active = false;
    }
    if (m_Active){
        m_Position.x += m_Direction.x * m_SPD;
        m_Position.y += m_Direction.y * m_SPD;

        m_Bullet.x = m_Position.x;
        m_Bullet.y = m_Position.y;
    }
}

void Bullet::Clean(){

}