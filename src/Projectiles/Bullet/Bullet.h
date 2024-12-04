#pragma once

#include "../Projectile.h"

class Bullet : public Projectile{
    public:

        Bullet();

        virtual void Draw();
        virtual void Update(float dt);
        virtual void Clean();

    protected:

        SDL_Rect m_Bullet;
};