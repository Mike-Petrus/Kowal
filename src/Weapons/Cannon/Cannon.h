#pragma once

#include "../Weapon.h"
#include "../../Projectiles/Bullet/Bullet.h"

#define COOLDOWN 100.0f
#define FIRE_RATE 5.0f

class Cannon : public Weapon{
    public:
        Cannon(Properties* properties, Vec2f direction);

        virtual void Fire();

        virtual void Draw();
        virtual void Update(float dt);
        virtual void Clean();

    protected:
        std::vector<Bullet> m_Bullets;
        float m_Cooldown;
};