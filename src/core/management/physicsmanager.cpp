#include "physicsmanager.h"
#include "SFML/Graphics.hpp"
#include "../tools/time.h"
#include "../engine.h"

namespace engine
{
    PhysicsManager::PhysicsManager()
    {

    }

    void PhysicsManager::updatePhysics()
    {
        calculatePhysics();
        detectCollisions();
    }

    void PhysicsManager::addCollider(RectCollider* collider)
    {
        rectColliders.push_back(collider);
    }

    void PhysicsManager::removeCollider(RectCollider* collider)
    {
        collider->hide();
        rectColliders.erase(remove(rectColliders.begin(), rectColliders.end(), collider), rectColliders.end());
    }

    void PhysicsManager::addPhysicalBody(PhysicalBody* physicalBody)
    {
        physicalBodies.push_back(physicalBody);
    }

    void PhysicsManager::removePhysicalBody(PhysicalBody* physicalBody)
    {
        physicalBodies.erase(remove(physicalBodies.begin(), physicalBodies.end(), physicalBody), physicalBodies.end());
    }

    void PhysicsManager::calculatePhysics()
    {
        for (auto element : physicalBodies)
            {
                element->parentObject->move(element->parentObject->getVelocity()*_2DEngine::Time::deltaTime);
            }
    }

    void PhysicsManager::detectCollisions()
    {
        if(rectColliders.size() > 1)
            for (auto firstElem = rectColliders.begin(); firstElem != rectColliders.end() - 1; firstElem++)
            {
                for (auto secondElem = firstElem + 1; secondElem != rectColliders.end(); secondElem++)
                {

                    if (checkCollision(*firstElem, *secondElem))
                    {
                        auto details_1 = setCollisionDetails(*firstElem, *secondElem);
                        pushApart(details_1);
                        Engine::instance()->logicsManager->collideObject(details_1);
                    }
                }
            }
    }

    void PhysicsManager::collide(CollisionDetails& details)
    {

    }

    void PhysicsManager::pushApart(CollisionDetails& details)
    {
        auto object_1 = details.collider1->parentObject;
        auto object_2 = details.collider2->parentObject;
        if (!details.collider1->isActive || !details.collider2->isActive)
        {
            return;
        }
        if (abs(details.depth_x) < abs(details.depth_y))
        {
            object_1->move(-details.depth_x * details.collider1->isDynamic, 0);
            object_2->move(details.depth_x * details.collider2->isDynamic, 0);
        }
        else// if (abs(details.depth_x) > abs(details.depth_y))
        {
            object_1->move(0, -details.depth_y * details.collider1->isDynamic);
            object_2->move(0, details.depth_y * details.collider2->isDynamic);
        }

    }

    bool PhysicsManager::checkCollision(RectCollider* collider_1, RectCollider* collider_2)
    {
        sf::Vector2f leftUpper_1 = collider_1->parentObject->getPosition() + collider_1->leftUpper;
        sf::Vector2f leftUpper_2 = collider_2->parentObject->getPosition() + collider_2->leftUpper;

        sf::Vector2f rightBottom_1 = collider_1->parentObject->getPosition() + collider_1->rightBottom;
        sf::Vector2f rightBottom_2 = collider_2->parentObject->getPosition() + collider_2->rightBottom;

        if (rightBottom_1.x < leftUpper_2.x)
            return false;

        if (leftUpper_1.x > rightBottom_2.x)
            return false;

        if (rightBottom_1.y < leftUpper_2.y)
            return false;

        if (leftUpper_1.y > rightBottom_2.y)
            return false;
        return true;
    }

    CollisionDetails PhysicsManager::setCollisionDetails(RectCollider* collider_1, RectCollider* collider_2)
        {
            float depth_x_1 = collider_1->parentObject->getPosition().x + collider_1->leftUpper.x - collider_2->rightBottom.x - collider_2->parentObject->getPosition().x;
            float depth_x_2 = collider_1->parentObject->getPosition().x + collider_1->rightBottom.x - collider_2->leftUpper.x - collider_2->parentObject->getPosition().x;
            float depth_y_1 = collider_1->parentObject->getPosition().y + collider_1->leftUpper.y - collider_2->rightBottom.y - collider_2->parentObject->getPosition().y;
            float depth_y_2 = collider_1->parentObject->getPosition().y + collider_1->rightBottom.y - collider_2->leftUpper.y - collider_2->parentObject->getPosition().y;
            float depth_x;
            float depth_y;

            if (abs(depth_x_1) < abs(depth_x_2))
                depth_x = depth_x_1;
            else
                depth_x = depth_x_2;

            if (abs(depth_y_1) < abs(depth_y_2))
                depth_y = depth_y_1;
            else
                depth_y = depth_y_2;

            return CollisionDetails(collider_1, collider_2, depth_x, depth_y);
        }
}

