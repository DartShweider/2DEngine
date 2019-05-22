
#ifndef PICTURESCRIPT_H
#define PICTURESCRIPT_H
#include "../core/engine.h"

#include "SFML/Graphics.hpp"

class TestScript : public engine::BasicScript
{
public:

    void update();
    void start();
    void collide(engine::CollisionDetails& details);

};

class EnemyScript : public engine::BasicScript
{
public:
    double timeCounter = 0;
    void update();
    void start();
    void collide(engine::CollisionDetails& details);

};


void TestScript::update()
{
    parentObject->getComponent<PhysicalBody>()->velocity = sf::Vector2f(0, 0);

    if (_2DEngine::KeyboardInput::getKey(KeyCode::A))
    {
        parentObject->position.x  -= 300*_2DEngine::Time::deltaTime;
    }


    if (_2DEngine::KeyboardInput::getKey(KeyCode::D))
    {

        parentObject->position.x  += 300*_2DEngine::Time::deltaTime;

        parentObject->getComponent<Animation>()->update();
    }

    if (_2DEngine::KeyboardInput::getKey(KeyCode::W))
    {
        parentObject->position.y  -= 300*_2DEngine::Time::deltaTime;
    }

    if (_2DEngine::KeyboardInput::getKey(KeyCode::S))
    {
        parentObject->position.y  += 300*_2DEngine::Time::deltaTime;
    }

}

void TestScript::start()
 {
        parentObject->setPosition(600, 0);
        parentObject->addComponent<Renderer>();
        parentObject->addComponent<Animation>();
        for(int i = 1; i<=8; i++)
        {
            parentObject->getComponent<Animation>()->upload("sprites/" + std::to_string(i) + ".png");
        }
        parentObject->getComponent<Renderer>()->setSprite(parentObject->getComponent<Animation>()->pictures[0]);
        parentObject->getComponent<Animation>()->timeMultiplier = 32;
        parentObject->addComponent<RectCollider>();
        parentObject->addComponent<PhysicalBody>();
        parentObject->getComponent<RectCollider>()->setCollider(-100, -100, 100, 100);
        parentObject->getComponent<RectCollider>()->display();


}


void TestScript::collide(engine::CollisionDetails& details)
{

}

void EnemyScript::update()
{
    if(parentObject->position.x  > 600 || parentObject->position.x < 0)
    {

        parentObject->getComponent<PhysicalBody>()->velocity.x = -parentObject->getComponent<PhysicalBody>()->velocity.x;

    }

}

void EnemyScript::start()
 {
    parentObject->setPosition(200, 200);
    sf::Texture enemyFirstTexture;
    enemyFirstTexture.loadFromFile("enemy.png");
    parentObject->addComponent<Renderer>();
    parentObject->getComponent<Renderer>()->setSprite(enemyFirstTexture);
    parentObject->addComponent<RectCollider>();
    parentObject->getComponent<RectCollider>()->setCollider(-100, -100, 100, 100);
    parentObject->getComponent<RectCollider>()->display();
    parentObject->addComponent<PhysicalBody>();
    parentObject->getComponent<PhysicalBody>()->velocity = sf::Vector2f(150, 0);
 }
void EnemyScript::collide(engine::CollisionDetails& details)
{
    parentObject->getComponent<PhysicalBody>()->velocity = - parentObject->getComponent<PhysicalBody>()->velocity;
}


#endif // PICTURESCRIPT_H
