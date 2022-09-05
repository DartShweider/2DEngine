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
        virtual ~PhysicalBody(){std::cout << "PhysicalBody destructor" << std::endl;}
        float mass = 1.0f;
    };
}


#endif // PHYSICALBODY_H
