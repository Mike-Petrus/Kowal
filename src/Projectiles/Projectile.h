#pragma once

#include "../Core/Common.h"
#include <SDL2/SDL_rect.h>
using namespace vam;

class Projectile{
    public:
        Projectile(){}

        virtual void SetDirection(Vec2f direction){m_Direction = direction;}
        virtual void SetPosition(Vec2f position){
            m_Position.x = position.x;
            m_Position.y = position.y;
        }

        virtual bool isActive(){return m_Active;}
        virtual void setActive(bool state){m_Active = state;}

        virtual void Draw()=0;
        virtual void Update(float dt)=0;
        virtual void Clean()=0;

    protected:    
        Vec2i m_Position;
        Vec2f m_Direction;

        float m_SPD;
        bool m_Active;
};