#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>
#include <vector>
#include <typeinfo>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Transformable.hpp>



namespace engine
{
    class Engine;
    class BasicScript;
    class GameObjectComponent;
    class GameObject : public sf::Transformable
    {
    public:
        ~GameObject();
        GameObject();
        GameObject(std::string m_name);
        std::string name;

        void setVelocity(float vel_x, float vel_y);
        void setVelocity(sf::Vector2f vel);
        sf::Vector2f getVelocity();

        template <typename ComponentType>
        void addComponent(ComponentType* component);

        template <typename ComponentType>
        ComponentType* getComponent();

        template <typename ComponentType>
        bool hasComponent();

        void registerObjComponent(GameObjectComponent* component);
        void unregisterObjComponent(GameObjectComponent* component);

    private:
        std::vector<GameObjectComponent*> components;
        sf::Vector2f velocity = {0,0};
    };

    template <typename ComponentType>
    void GameObject::addComponent(ComponentType* component)
    {
        components.push_back(component);
    }

    template <typename ComponentType>
    ComponentType* GameObject::getComponent()
    {
        for (auto component : components)
        {
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
