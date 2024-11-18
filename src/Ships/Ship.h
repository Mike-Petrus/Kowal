#pragma once

#include "../Objects/GameObject.h"

struct Attributes{
    public:

        Attributes(int health, int energy, int armor, float speed, float acceleration){
            HP = health;
            EP = energy;
            AP = armor;
            SPD = speed;
            ACCEL = acceleration;
        }

    int HP, EP, AP;
    float SPD, ACCEL;
};

class Ship : public GameObject{
    public:
        Ship(Attributes* attributes, Properties* properties): GameObject(properties), m_HP(attributes->HP), m_EP(attributes->EP), m_AP(attributes->AP),
        m_SPD(attributes->SPD), m_ACCEL(attributes->ACCEL){}

        virtual void Draw()=0;
        virtual void Update(float dt)=0;
        virtual void Clean()=0;

    protected:

        virtual void MoveFoward()=0;
        virtual void Rotate(int clockwise)=0;

        int m_HP, m_EP, m_AP;
        float m_SPD, m_ACCEL;
        Vec2f m_Direction; 
};