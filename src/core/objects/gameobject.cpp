#include "gameobject.h"
#include "../engine.h"

namespace engine
{

    GameObject::~GameObject()
        {
            for (auto component : components)
            {
                if (component->name == typeid(Renderer).name())
                {
                    unregisterObjectRenderer(component);
                    delete component;
                    continue;
                }
                if (component->name == typeid(RectCollider).name())
                {
                    unregisterObjectRectCollider(component);
                    continue;
                }

                if (component->name == typeid(PhysicalBody).name())
                {
                    unregisterObjectPhysicalBody(component);
                    continue;
                }
                if (component->name == typeid(Animation).name())
                {
                    continue;
                }



                unregisterObjectScript(component);
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

    void GameObject::registerObjectScript(GameObjectComponent* script)
    {
        Engine::instance()->logicsManager->addScript(static_cast<BasicScript*>(script));
    }

    void GameObject::unregisterObjectScript(GameObjectComponent* script)
    {
        Engine::instance()->logicsManager->removeScript(static_cast<BasicScript*>(script));
    }

    void GameObject::registerObjectRenderer(GameObjectComponent* renderer)
    {
        Engine::instance()->drawManager->addRenderer(static_cast<Renderer*>(renderer));
    }

    void GameObject::unregisterObjectRenderer(GameObjectComponent* renderer)
    {
        Engine::instance()->drawManager->removeRenderer(static_cast<Renderer*>(renderer));
    }

    void GameObject::registerObjectRectCollider(GameObjectComponent* collider)
    {
        Engine::instance()->physicsManager->addCollider(static_cast<RectCollider*>(collider));
    }

    void GameObject::unregisterObjectRectCollider(GameObjectComponent* collider)
    {
        Engine::instance()->physicsManager->removeCollider(static_cast<RectCollider*>(collider));
    }
    void GameObject::registerObjectPhysicalBody(GameObjectComponent* physBody)
    {
        Engine::instance()->physicsManager->addPhysicalBody(static_cast<PhysicalBody*>(physBody));
    }

    void GameObject::unregisterObjectPhysicalBody(GameObjectComponent* physBody)
    {
        Engine::instance()->physicsManager->removePhysicalBody(static_cast<PhysicalBody*>(physBody));
    }

}

