#pragma once

#include "../Objects/GameObject.h"

class Weapon : public GameObject{
    public:
        Weapon(Properties* properties, Vec2f direction): GameObject(properties){}

        virtual void SetPosition(Vec2f position);
        virtual void SetDirection(Vec2f direction);

        virtual void Fire()=0;

        virtual void Draw()=0;
        virtual void Update(float dt)=0;
        virtual void Clean()=0;

    protected:

        float m_FireRate;
        Vec2f* m_Direction;
};