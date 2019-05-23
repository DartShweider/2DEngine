#ifndef PHYSICALBODY_H
#define PHYSICALBODY_H
#include "gameobjectcomponent.h"
#include "SFML/Graphics.hpp"



namespace engine
{
    class PhysicalBody : public GameObjectComponent
    {
    public:
        PhysicalBody();
        float gravitationValue = 1.0f;
        bool gravitation = false;

        float mass = 1.0f;

        sf::Vector2f velocity = {0,0};
        //sf::Vector2f prevPosition;

    };
}


#endif // PHYSICALBODY_H
