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
                if (element->gravitation)
                    element->velocity += sf::Vector2f(0, element->gravitationValue);

                element->parentObject->position += element->velocity * Time::deltaTime;
            }
    }

    void PhysicsManager::detectCollisions()
    {

        for (auto firstCollider : rectColliders)
        {
            for (auto secondCollider : rectColliders)
            {
                /*
                if (!firstCollider->parentObject->hasComponent<PhysicalBody>())
                    continue;
                */
                if (firstCollider == secondCollider)
                    continue;

                if (checkCollision(firstCollider, secondCollider))
                {

                        auto details_1 = setCollisionDetails(firstCollider, secondCollider);
                        auto details_2 = details_1;
                        details_2.collider1 = details_1.collider2;
                        details_2.collider2 = details_1.collider1;
                        pushApart(details_1);
                        Engine::instance()->logicsManager->collideObject(firstCollider->parentObject, details_1);
                        Engine::instance()->logicsManager->collideObject(secondCollider->parentObject, details_2);

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
        object_1->position -= object_1->getComponent<PhysicalBody>()->velocity * Time::deltaTime;
        object_2->position -= object_2->getComponent<PhysicalBody>()->velocity * Time::deltaTime;



    }

    bool PhysicsManager::checkCollision(RectCollider* collider_1, RectCollider* collider_2)
    {
        sf::Vector2f leftUpper_1 = collider_1->parentObject->position + collider_1->leftUpper;
        sf::Vector2f leftUpper_2 = collider_2->parentObject->position + collider_2->leftUpper;

        sf::Vector2f rightBottom_1 = collider_1->parentObject->position + collider_1->rightBottom;
        sf::Vector2f rightBottom_2 = collider_2->parentObject->position + collider_2->rightBottom;

        if (rightBottom_1.x < leftUpper_2.x)
            //std::cout << rightBottom_1.x << std::endl;
            return false;

        if (leftUpper_1.x > rightBottom_2.x)
            //std::cout << rightBottom_1.x << std::endl;
            return false;

        if (rightBottom_1.y < leftUpper_2.y)
            //std::cout << rightBottom_1.y << std::endl;
            return false;

        if (leftUpper_1.y > rightBottom_2.y)
            //std::cout << rightBottom_1.y << std::endl;
            return false;

        return true;
    }

    CollisionDetails PhysicsManager::setCollisionDetails(RectCollider* collider_1, RectCollider* collider_2)
        {

            float depth_x_1 = abs(collider_1->parentObject->position.x + collider_1->leftUpper.x - collider_2->rightBottom.x - collider_2->parentObject->position.x);
            float depth_x_2 = abs(collider_1->parentObject->position.x + collider_1->rightBottom.x - collider_2->leftUpper.x - collider_2->parentObject->position.x);
            float depth_y_1 = abs(collider_1->parentObject->position.y + collider_1->leftUpper.y - collider_2->rightBottom.y - collider_2->parentObject->position.y);
            float depth_y_2 = abs(collider_1->parentObject->position.y + collider_1->rightBottom.y - collider_2->leftUpper.y - collider_2->parentObject->position.x);

            return CollisionDetails(collider_1, collider_2, std::min(depth_x_1, depth_x_2), std::min(depth_y_1, depth_y_2));
        }


}

