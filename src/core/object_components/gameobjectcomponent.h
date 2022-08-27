#ifndef GAMEOBJECTCOMPONENT_H
#define GAMEOBJECTCOMPONENT_H
#include <string>
#include <iostream>

namespace engine
{
    class GameObject;
    enum ObjComponentName
    {
        basicScript,
        renderer,
        rectCollider,
        physicalBody,
        animation
    };

    class GameObjectComponent
    {
    public:
        GameObjectComponent();
        std::string name = "GameObjectComponent";
        GameObject* parentObject = nullptr;
        virtual ~GameObjectComponent() { std::cout << "GameObjectComponent destructor" << std::endl;}
    };
}
#endif // GAMEOBJECTCOMPONENT_H
