#include "Cannon.h"
#include "../../Projectiles/Bullet/Bullet.h"
#include "../../Core/Engine.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

Cannon::Cannon(Properties* properties, Vec2f direction) : Weapon(properties, direction){
    m_Direction = new Vec2f(direction.x, direction.y);
    m_FireRate = 10;


}

void Cannon::Fire(){
    Bullet b;
    b.SetPosition(Vec2f{m_Transform->X, m_Transform->Y});
    b.SetDirection(*m_Direction);
    b.setActive(true);
    m_Bullets.push_back(b);
}

void Cannon::Draw(){
    SDL_SetRenderDrawColor(Engine::GetInstance()->GetRenderer(), 255, 255, 255, 255);
    for (size_t i = 0; i < m_Bullets.size(); ++i){
        if (m_Bullets[i].isActive()){
            m_Bullets[i].Draw();
        }
    }
    SDL_SetRenderDrawColor(Engine::GetInstance()->GetRenderer(), 0, 0, 0, 255);
}

void Cannon::Update(float dt){
    for (size_t i = 0; i < m_Bullets.size(); ++i){
        if (!m_Bullets[i].isActive()){
            m_Bullets.erase(m_Bullets.begin() + i);
            i--;
            continue;
        }
        m_Bullets[i].Update(dt);
    }
}

void Cannon::Clean(){

}