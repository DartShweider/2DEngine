#include "gameobject.h"
#include "../engine.h"
#include <typeinfo>

namespace engine
{

    void GameObject::registerObjComponent(GameObjectComponent* component)
    {
        if (dynamic_cast<BasicScript*>(component))
        {
            Engine::instance()->logicsManager->addScript(static_cast<BasicScript*>(component));
        }
        if (dynamic_cast<Renderer*>(component))
        {
            Engine::instance()->drawManager->addRenderer(static_cast<Renderer*>(component));
        }
        if (dynamic_cast<RectCollider*>(component))
        {
            Engine::instance()->physicsManager->addCollider(static_cast<RectCollider*>(component));
        }
        if (dynamic_cast<PhysicalBody*>(component))
        {
            Engine::instance()->physicsManager->addPhysicalBody(static_cast<PhysicalBody*>(component));
        }
    }
    void GameObject::unregisterObjComponent(GameObjectComponent* component)
    {
        if (dynamic_cast<BasicScript*>(component))
        {
            Engine::instance()->logicsManager->removeScript(static_cast<BasicScript*>(component));
        }
        if (dynamic_cast<Renderer*>(component))
        {
            Engine::instance()->drawManager->removeRenderer(static_cast<Renderer*>(component));
        }
        if (dynamic_cast<RectCollider*>(component))
        {
            Engine::instance()->physicsManager->removeCollider(static_cast<RectCollider*>(component));
        }
        if (dynamic_cast<PhysicalBody*>(component))
        {
            Engine::instance()->physicsManager->removePhysicalBody(static_cast<PhysicalBody*>(component));
        }
    }

    GameObject::~GameObject()
    {
        for (auto component : components)
        {
            unregisterObjComponent(component);
            delete component;
        }
        components.clear();
    };


    void GameObject::setPosition(int x, int y)
    {
        position = {x, y};
    }

    GameObject::GameObject(std::string m_name)
    {
        name = m_name;
    }

}

