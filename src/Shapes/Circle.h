#pragma once

#include "../Core/Common.h"
using namespace vam;

class Circle{
    public:
        Circle();
        Circle(int radius, Vec2f position);

        void Draw();
        void SetPosition(Vec2f Position);

    private:

        int m_Radius;
        Vec2f m_Position;
        std::vector<std::pair<int, int>> m_Lines;
};