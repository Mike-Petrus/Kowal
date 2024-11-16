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

        GameObject(Properties* properties): m_Width(properties->Width), m_Height(properties->Height){

            m_Transform = new Transform(properties->X, properties->Y);  
        }

        virtual void Draw()=0;
        virtual void Update(float dt)=0;
        virtual void Clean()=0;

    protected:
    
        Transform* m_Transform;
        int m_Width, m_Height;
};