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
        Ship(Attributes* attributes, Properties* properties, Vec2f* origin): GameObject(properties, origin){}

        virtual void Draw();
        virtual void Update(float dt);
        virtual void Clean();

        private:

        

};