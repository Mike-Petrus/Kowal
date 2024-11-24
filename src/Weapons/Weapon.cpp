#include "Weapon.h"

void Weapon::SetPosition(Vec2f position){
    m_Transform->X = position.x;
    m_Transform->Y = position.y;
}

void Weapon::SetDirection(Vec2f direction){
    m_Direction->x = direction.x;
    m_Direction->y = direction.y;
}