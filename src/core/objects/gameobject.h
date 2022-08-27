#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>
#include <vector>
#include <typeinfo>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../object_components/renderer.h"
#include "../object_components/basicscript.h"
#include "../object_components/rectcollider.h"
#include "../object_components/physicalbody.h"
#include "../object_components/animation.h"
#include "../object_components/gameobjectcomponent.h"


namespace engine
{
    class Engine;
    class GameObject
    {
    public:
        ~GameObject();
        GameObject();
        GameObject(std::string m_name);

        std::string name;
        sf::Vector2f position;
        float directionAngle = 0.f;
        std::vector<GameObjectComponent*> components;

        void setPosition(int x, int y);

        template <typename ComponentType>
        void addComponent();

        template <typename ComponentType>
        ComponentType* getComponent();

        template <typename ComponentType>
        bool hasComponent();

        void registerObjComponent(GameObjectComponent* component);
        void unregisterObjComponent(GameObjectComponent* component);

        void registerObjectScript(GameObjectComponent* script);
        void unregisterObjectScript(GameObjectComponent* script);

        void registerObjectRenderer(GameObjectComponent* renderer);
        void unregisterObjectRenderer(GameObjectComponent* renderer);

        void registerObjectRectCollider(GameObjectComponent* collider);
        void unregisterObjectRectCollider(GameObjectComponent* collider);

        void registerObjectPhysicalBody(GameObjectComponent* physBody);
        void unregisterObjectPhysicalBody(GameObjectComponent* physBody);

    };

    template <typename ComponentType>
    ComponentType* GameObject::getComponent()
    {
        for (auto component : components)
        {
            //std::cout << typeid(*component).name() << "\t\t" << typeid(ComponentType).name() << "\t getcomponent" << std::endl;
            if (typeid(*component).name() == typeid(ComponentType).name())
            {
                ComponentType* wired = static_cast<ComponentType*>(component);
                return wired;
            }
        }
        return nullptr;
    }

    template <typename ComponentType>
    bool GameObject::hasComponent()
    {
        for (auto component : components)
        {
            if (typeid(*component).name() == typeid(ComponentType).name() || std::is_base_of<BasicScript, ComponentType>() )
            {
                return true;
            }
        }
        return false;
    }



}
#endif // GAMEOBJECT_H
