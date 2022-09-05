#include "gameobject.h"
#include "../object_components/renderer.h"
#include "../object_components/basicscript.h"
#include "../object_components/rectcollider.h"
#include "../object_components/physicalbody.h"
#include "../object_components/animation.h"
#include "../object_components/gameobjectcomponent.h"
#include "../engine.h"
#include <typeinfo>

namespace engine
{
    void GameObject::registerObjComponent(GameObjectComponent* component)
    {
        if (dynamic_cast<BasicScript*>(component))
        {
            Engine::instance()->logicsManager->addScript(static_cast<BasicScript*>(component));
            return;
        }
        if (dynamic_cast<Renderer*>(component))
        {
            Engine::instance()->drawManager->addRenderer(static_cast<Renderer*>(component));
            return;
        }
        if (dynamic_cast<RectCollider*>(component))
        {
            Engine::instance()->physicsManager->addCollider(static_cast<RectCollider*>(component));
            return;
        }
        if (dynamic_cast<PhysicalBody*>(component))
        {
            Engine::instance()->physicsManager->addPhysicalBody(static_cast<PhysicalBody*>(component));
            return;
        }
    }

    void GameObject::unregisterObjComponent(GameObjectComponent* component)
    {
        if (dynamic_cast<BasicScript*>(component))
        {
            Engine::instance()->logicsManager->removeScript(static_cast<BasicScript*>(component));
            return;
        }
        if (dynamic_cast<Renderer*>(component))
        {
            Engine::instance()->drawManager->removeRenderer(static_cast<Renderer*>(component));
            return;
        }
        if (dynamic_cast<RectCollider*>(component))
        {
            Engine::instance()->physicsManager->removeCollider(static_cast<RectCollider*>(component));
            return;
        }
        if (dynamic_cast<PhysicalBody*>(component))
        {
            Engine::instance()->physicsManager->removePhysicalBody(static_cast<PhysicalBody*>(component));
            return;
        }
    }

    void GameObject::setVelocity(float vel_x, float vel_y)
    {
        velocity.x = vel_x;
        velocity.y = vel_y;
    }

    void GameObject::setVelocity(sf::Vector2f vel)
    {
        velocity = vel;
    }

    sf::Vector2f GameObject::getVelocity()
    {
        return velocity;
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


    GameObject::GameObject(std::string m_name)
    {
        name = m_name;
    }

    GameObject::GameObject()
    {

    }

}

