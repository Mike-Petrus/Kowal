#pragma once

#include "../Weapon.h"
#include "../../Projectiles/Bullet/Bullet.h"

class Cannon : public Weapon{
    public:
        Cannon(Properties* properties, Vec2f direction);

        virtual void Fire();

        virtual void Draw();
        virtual void Update(float dt);
        virtual void Clean();

    protected:
        std::vector<Bullet> m_Bullets;

};