#include "Circle.h"
#include "../Core/Engine.h"
#include <SDL2/SDL_render.h>
#include <stack>

Circle::Circle(int radius, Vec2f position){
    std::stack<int> xVals;

    m_Radius = radius;
    m_Position = position;

    for (int i = 0; i < radius - 1; ++i){
        float x1;

        x1 = sqrt((radius * radius) - pow(radius - i, 2));
        SDL_Log("about to push x1: %f, y1: %i", x1, i);
        m_Lines.push_back({x1, i});
        xVals.push(x1);
    }


    for (int i = 0; i < radius; ++i){
        if (radius%2 != 0 && i == 0){
            SDL_Log("about to push ODD CENTER x1: %i, y1: %i", radius, radius - 1);

            m_Lines.push_back({radius, radius - 1});
            continue;
        }

        SDL_Log("about to push x1: %i, y1: %i", xVals.top(), i + radius);
        
        m_Lines.push_back({xVals.top(), i + radius - 1});
        xVals.pop();
    }

}

void Circle::Draw(){
    int x1, x2, y1;
    SDL_SetRenderDrawColor(Engine::GetInstance()->GetRenderer(), 200, 100, 100, 255);

    for (size_t i = 0; i < m_Lines.size(); ++i){
        x1 = m_Position.x - m_Lines[i].first;
        x2 = m_Position.x + m_Lines[i].first;
        y1 = m_Position.y - m_Lines[i].second;

        //SDL_Log("x1: %i, x2: %i, y1: %i, y2: %i \n", x1, x2, y1, y2);

        SDL_RenderDrawLine(Engine::GetInstance()->GetRenderer(), x1, y1, x2, y1);
    }
}