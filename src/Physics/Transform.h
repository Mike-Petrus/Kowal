#pragma once

#include <linalg.h>
#include "../Core/Common.h"
using namespace vam;

class Transform{
    public:

        float X, Y;
        Transform(float x=0, float y=0): X(x), Y(y){}

        inline void TranslateX(float x){X += x;}
        inline void TranslateY(float y){Y += y;}
        inline void Translate(Vec2f v){
            X += v.x;
            Y += v.y;
            }
};