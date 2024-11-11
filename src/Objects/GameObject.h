#pragma once

#include "IObject.h"
#include "../Core/Common.h"
#include "../Physics/Transform.h"
using namespace vam;

struct Properties{
    public:

        Properties(int x, int y, int w, int h){
            X = x;
            Y = y;
            Width = w;
            Height = h;
        }

        float X, Y;
        int Width, Height;
};

class GameObject : public IObject{
    public:

        GameObject(Properties* properties, Vec2f* origin): m_Width(properties->Width), m_Height(properties->Height){

            m_Transform = new Transform(properties->X, properties->Y);
            m_Origin = new Vec2f(origin->x, origin->y);    
        }

        inline Vec2f* GetOrigin(){return m_Origin;}

        virtual void Draw()=0;
        virtual void Update(float dt)=0;
        virtual void Clean()=0;

    protected:
        Vec2f* m_Origin;
        Transform* m_Transform;
        int m_Width, m_Height;
};