#pragma once

#include "../Weapon.h"

class Cannon : public Weapon{
    public:
        Cannon(Properties* properties, Vec2f direction);

        virtual void Fire();

        virtual void Draw();
        virtual void Update(float dt);
        virtual void Clean();

};