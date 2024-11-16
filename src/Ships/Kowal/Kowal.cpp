#include "Kowal.h"
#include "../../Input/Input.h"
#include <SDL2/SDL_render.h>

Kowal::Kowal(Attributes* attributes, Properties* properties) : Ship(attributes, properties){

}

SDL_Vertex* Kowal::getVertices(){
    return m_Vertices;
}

void Kowal::Draw(){
    SDL_Log("Draw");
}

void Kowal::Update(float dt){
    SDL_Log("Update");
}

void Kowal::Clean(){
    SDL_Log("Clean");
}