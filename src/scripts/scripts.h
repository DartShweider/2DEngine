
#ifndef PICTURESCRIPT_H
#define PICTURESCRIPT_H
#include "../core/engine.h"
#include <vector>
#include "SFML/Graphics.hpp"

class Player_1_Script : public _2DEngine::BasicScript
{
public:
    float velocity = 150;
    void update();
    void start();
    void collide(engine::CollisionDetails& details);

};

class LevelScript : public _2DEngine::BasicScript
{
public:

    std::vector<std::vector<int>> level   {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                           {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,1},
                                           {1,0,2,2,2,0,2,2,0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0,0,0,0,2,2,0,0,1},
                                           {1,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,2,2,0,0,1},
                                           {1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,2,2,0,0,1},
                                           {1,0,0,0,0,2,0,0,0,0,2,2,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,2,2,0,0,1},
                                           {1,0,0,0,0,2,2,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,1},
                                           {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
                                           {1,0,0,0,0,2,2,2,2,0,2,0,0,0,0,0,0,0,0,0,1,0,0,2,2,0,0,0,0,0,0,1},
                                           {1,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,2,2,0,0,1,0,0,0,0,0,2,2,2,0,0,1},
                                           {1,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,2,2,0,1,0,0,0,0,0,0,0,2,0,0,1},
                                           {1,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,2,2,0,1,0,0,0,2,2,0,0,2,0,0,1},
                                           {1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,1},
                                           {1,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,1},
                                           {1,0,0,2,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,1},
                                           {1,0,0,2,0,0,0,1,0,0,2,2,2,2,0,0,0,2,2,2,2,2,2,0,0,0,0,0,2,0,0,1},
                                           {1,0,0,2,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,0,0,2,1,1,1,0,0,0,0,0,0,1},
                                           {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

    void update();
    void start();

};

class Player_2_Script : public _2DEngine::BasicScript
{
public:
    float velocity = 150;
    void update();
    void start();
    void collide(engine::CollisionDetails& details);
};


void LevelScript::update()
{

}

void LevelScript::start()
{
    for (int i = 0; i < level.size(); i++)
    {
        for (int j = 0; j < level[i].size(); j++)
        {
            if (level[i][j] == 1 )
            {
                _2DEngine::createObject("block" + std::to_string(i) + std::to_string(j));
                _2DEngine::findObject("block" + std::to_string(i) + std::to_string(j))->setPosition(25 + 50* j, 25 + 50*i);
                _2DEngine::findObject("block" + std::to_string(i) + std::to_string(j))->addComponent<Renderer>();
                sf::Texture texture;
                texture.loadFromFile("blocks/undeadblock.png");
                _2DEngine::findObject("block" + std::to_string(i) + std::to_string(j))->getComponent<Renderer>()->setSprite(texture);
                _2DEngine::findObject("block" + std::to_string(i) + std::to_string(j))->addComponent<PhysicalBody>();
                _2DEngine::findObject("block" + std::to_string(i) + std::to_string(j))->addComponent<RectCollider>();
                _2DEngine::findObject("block" + std::to_string(i) + std::to_string(j))->getComponent<RectCollider>()->setCollider(-25,-25,25,25);
            }

            if (level[i][j] == 2 )
            {
                _2DEngine::createObject("block" + std::to_string(i) + std::to_string(j));
                _2DEngine::findObject("block" + std::to_string(i) + std::to_string(j))->setPosition(25 + 50* j, 25 + 50*i);
                _2DEngine::findObject("block" + std::to_string(i) + std::to_string(j))->addComponent<Renderer>();
                sf::Texture texture;
                texture.loadFromFile("blocks/crashblock.png");
                _2DEngine::findObject("block" + std::to_string(i) + std::to_string(j))->getComponent<Renderer>()->setSprite(texture);
                _2DEngine::findObject("block" + std::to_string(i) + std::to_string(j))->addComponent<PhysicalBody>();
                _2DEngine::findObject("block" + std::to_string(i) + std::to_string(j))->addComponent<RectCollider>();
                _2DEngine::findObject("block" + std::to_string(i) + std::to_string(j))->getComponent<RectCollider>()->setCollider(-25,-25,25,25);
            }
        }
    }

}

void Player_1_Script::update()
{

    parentObject->getComponent<PhysicalBody>()->velocity = sf::Vector2f(0,0);
    if (_2DEngine::KeyboardInput::getKey(KeyCode::A))
    {
        parentObject->directionAngle  -= 70.f*_2DEngine::Time::deltaTime;
        parentObject->getComponent<Renderer>()->sprite.setRotation(parentObject->directionAngle + 90);
    }


    if (_2DEngine::KeyboardInput::getKey(KeyCode::D))
    {

        parentObject->directionAngle  += 70.f*_2DEngine::Time::deltaTime;
        parentObject->getComponent<Renderer>()->sprite.setRotation(parentObject->directionAngle + 90);

    }

    if (_2DEngine::KeyboardInput::getKey(KeyCode::W))
    {
        parentObject->getComponent<PhysicalBody>()->velocity = sf::Vector2f(velocity * cos(parentObject->directionAngle * 3.1416/180),
                                                                            velocity * sin(parentObject->directionAngle * 3.1416/180));
        //parentObject->position.x += velocity * cos(parentObject->directionAngle * 3.1416/180) * _2DEngine::Time::deltaTime;
        //parentObject->position.y += velocity * sin(parentObject->directionAngle * 3.1416/180) * _2DEngine::Time::deltaTime;
        parentObject->getComponent<Animation>()->update();
    }

    if (_2DEngine::KeyboardInput::getKey(KeyCode::S))
    {
        parentObject->getComponent<PhysicalBody>()->velocity = sf::Vector2f(-velocity * cos(parentObject->directionAngle * 3.1416/180),
                                                                            -velocity * sin(parentObject->directionAngle * 3.1416/180));
        //parentObject->position.x -= velocity * cos(parentObject->directionAngle * 3.1416/180) * _2DEngine::Time::deltaTime;
        //parentObject->position.y -= velocity * sin(parentObject->directionAngle * 3.1416/180) * _2DEngine::Time::deltaTime;
        parentObject->getComponent<Animation>()->update();
    }

}

void Player_1_Script::start()
 {
        parentObject->setPosition(75, 75);
        parentObject->addComponent<Renderer>();
        parentObject->addComponent<Animation>();
        for(int i = 1; i<=2; i++)
        {
            parentObject->getComponent<Animation>()->upload("tank/tank_" + std::to_string(i) + ".png");
        }
        parentObject->getComponent<Renderer>()->setSprite(parentObject->getComponent<Animation>()->pictures[0]);
        parentObject->getComponent<Renderer>()->sprite.setRotation(parentObject->directionAngle + 90);
        parentObject->getComponent<Animation>()->timeMultiplier = 32;

        parentObject->addComponent<PhysicalBody>();
        parentObject->addComponent<RectCollider>();
        parentObject->getComponent<RectCollider>()->setCollider(-20,-20, 20,20);
        //parentObject->getComponent<RectCollider>()->display();


}


void Player_1_Script::collide(engine::CollisionDetails& details)
{

}

void Player_2_Script::update()
{
    parentObject->getComponent<PhysicalBody>()->velocity = sf::Vector2f(0,0);
    if (_2DEngine::KeyboardInput::getKey(KeyCode::J))
    {
        parentObject->directionAngle  -= 70.f*_2DEngine::Time::deltaTime;
        parentObject->getComponent<Renderer>()->sprite.setRotation(parentObject->directionAngle + 90);
    }


    if (_2DEngine::KeyboardInput::getKey(KeyCode::L))
    {

        parentObject->directionAngle  += 70.f*_2DEngine::Time::deltaTime;
        parentObject->getComponent<Renderer>()->sprite.setRotation(parentObject->directionAngle + 90);

    }

    if (_2DEngine::KeyboardInput::getKey(KeyCode::I))
    {
        parentObject->getComponent<PhysicalBody>()->velocity = sf::Vector2f(velocity * cos(parentObject->directionAngle * 3.1416/180),
                                                                            velocity * sin(parentObject->directionAngle * 3.1416/180));
        //parentObject->position.x += velocity * cos(parentObject->directionAngle * 3.1416/180) * _2DEngine::Time::deltaTime;
        //parentObject->position.y += velocity * sin(parentObject->directionAngle * 3.1416/180) * _2DEngine::Time::deltaTime;
        parentObject->getComponent<Animation>()->update();
    }

    if (_2DEngine::KeyboardInput::getKey(KeyCode::K))
    {
        parentObject->getComponent<PhysicalBody>()->velocity = sf::Vector2f(-velocity * cos(parentObject->directionAngle * 3.1416/180),
                                                                            -velocity * sin(parentObject->directionAngle * 3.1416/180));
        //parentObject->position.x -= velocity * cos(parentObject->directionAngle * 3.1416/180) * _2DEngine::Time::deltaTime;
        //parentObject->position.y -= velocity * sin(parentObject->directionAngle * 3.1416/180) * _2DEngine::Time::deltaTime;
        parentObject->getComponent<Animation>()->update();
}
}

void Player_2_Script::start()
{
    parentObject->setPosition(400, 75);
    parentObject->addComponent<Renderer>();
    parentObject->addComponent<Animation>();
    for(int i = 1; i<=2; i++)
    {
        parentObject->getComponent<Animation>()->upload("tank/tank_" + std::to_string(i) + ".png");
    }
    parentObject->getComponent<Renderer>()->setSprite(parentObject->getComponent<Animation>()->pictures[0]);
    parentObject->getComponent<Renderer>()->sprite.setRotation(parentObject->directionAngle + 90);
    parentObject->getComponent<Animation>()->timeMultiplier = 32;

    parentObject->addComponent<PhysicalBody>();
    parentObject->addComponent<RectCollider>();
    parentObject->getComponent<RectCollider>()->setCollider(-20,-20, 20,20);
    //parentObject->getComponent<RectCollider>()->display();
 }
void Player_2_Script::collide(engine::CollisionDetails& details)
{
    parentObject->getComponent<PhysicalBody>()->velocity = - parentObject->getComponent<PhysicalBody>()->velocity;
}


#endif // PICTURESCRIPT_H
