#pragma once

#include <SDL2/SDL.h>
#include "Ship.h"

class Kowal : public Ship{
    public:

        Kowal();
        Kowal(Attributes* attributes, Properties* properties, Vec2f* origin);

        virtual void Draw();
        virtual void Update(float dt);
        virtual void Clean();

    private:

        void MoveForward();
        void RotateRight();
        void RotateLeft();

        void setVertices(SDL_Vertex *vertices[3]);

        float m_Angle;
        SDL_Vertex v0, v1, v2;
        SDL_Vertex m_Vertices[3];
        
};