#ifndef GAMEOBJECTCOMPONENT_H
#define GAMEOBJECTCOMPONENT_H
#include <string>
#include <iostream>

namespace engine
{
    class GameObject;

    class GameObjectComponent
    {
    public:
        GameObjectComponent();
        GameObject* parentObject = nullptr;
        virtual ~GameObjectComponent() { std::cout << "GameObjectComponent destructor" << std::endl;}
    };
}
#endif // GAMEOBJECTCOMPONENT_H
