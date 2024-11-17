#pragma once

#include "../Ship.h"
#include <SDL2/SDL_render.h>

class Kowal : public Ship{
    public:

        Kowal(Attributes* attributes, Properties* properties);

        SDL_Vertex* getVertices();

        virtual void Draw();
        virtual void Update(float dt);
        virtual void Clean();

    protected:

        virtual void MoveFoward();
        virtual void RotateRight();
        virtual void RotateLeft();

        float angle;
        SDL_Vertex v0, v1, v2;
        SDL_Vertex m_Vertices[3];
};