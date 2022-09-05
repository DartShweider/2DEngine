#ifndef SCRIPTS_H
#define SCRIPTS_H
#include "../core/object_components/basicscript.h"
#include "../core/object_components/renderer.h"
#include "../core/tools/tools.h"
#include "../core/tools/time.h"
#include <vector>

using namespace engine;

class Player_1_Script : public _2DEngine::BasicScript
{
public:
    float velocity = 150;
    void update()
    {
        parentObject->setVelocity(0, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            parentObject->rotate(-70.f*_2DEngine::Time::deltaTime);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            parentObject->rotate(70.f*_2DEngine::Time::deltaTime);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            parentObject->setVelocity(velocity * sin(parentObject->getRotation() * 3.1416/180),
                                        velocity * -cos(parentObject->getRotation() * 3.1416/180));
            parentObject->getComponent<Animation>()->updateForward();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            parentObject->setVelocity(-velocity * sin(parentObject->getRotation() * 3.1416/180),
                                                                                velocity * cos(parentObject->getRotation() * 3.1416/180));
            parentObject->getComponent<Animation>()->updateBackward();
        }
    }

    void start()
    {
        parentObject->setPosition(600, 600);
        _2DEngine::addComponent<Renderer>(parentObject->name);
        parentObject->getComponent<Renderer>()->setTexture("tank/Tank3.png");
        _2DEngine::addComponent<Animation>(parentObject->name);
        parentObject->getComponent<Animation>()->addFrame(sf::IntRect(0,0,128,128));
        parentObject->getComponent<Animation>()->addFrame(sf::IntRect(128,0,128,128));
        parentObject->getComponent<Animation>()->addFrame(sf::IntRect(256,0,128,128));
        parentObject->getComponent<Animation>()->addFrame(sf::IntRect(384,0,128,128));
        parentObject->getComponent<Animation>()->setTexture();
        parentObject->getComponent<Animation>()->fps = 70;

        _2DEngine::addComponent<PhysicalBody>(parentObject->name);
        _2DEngine::addComponent<RectCollider>(parentObject->name);
        parentObject->getComponent<RectCollider>()->setCollider(-15,-15, 14,14);
        parentObject->getComponent<Animation>()->updateForward();
        parentObject->getComponent<RectCollider>()->display();
    }

    void collide(engine::CollisionDetails& details)
    {

    }
private:
    virtual ~Player_1_Script()
    {
        std::cout << "Player_1_Script destructor" << std::endl;
    }
};



class LevelScript : public _2DEngine::BasicScript
{
public:
    std::vector<std::vector<unsigned int>> level  {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
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

    void update(){}
    void start()
    {
        for (int i = 0; i < level.size(); i++)
        {
            for (int j = 0; j < level[i].size(); j++)
            {
                if(level[i][j])
                {
                        GameObject* currentObj =_2DEngine::createObject("block" + std::to_string(i) + std::to_string(j));
                        currentObj->setPosition(25 + 50* j, 25 + 50*i);
                        _2DEngine::addComponent<Renderer>(currentObj);
                        if (level[i][j] == 1 )
                            currentObj->getComponent<Renderer>()->setTexture("blocks/undeadblock.png");
                        if (level[i][j] == 2 )
                            currentObj->getComponent<Renderer>()->setTexture("blocks/crashblock.png");
                        currentObj->getComponent<Renderer>()->setSprite();
                        _2DEngine::addComponent<PhysicalBody>(currentObj);
                        _2DEngine::addComponent<RectCollider>(currentObj);
                        currentObj->getComponent<RectCollider>()->setCollider(-25,-25,24,24);
                        currentObj->getComponent<RectCollider>()->isDynamic = false;
                }
            }
        }
    }
private:
    virtual ~LevelScript()
    {
        std::cout << "Level_Script destructor" << std::endl;
    }

};

class Gun_2_Script : public _2DEngine::BasicScript
{
public:
    GameObject* tank = _2DEngine::getObject("player_2");
    void update()
    {
        tank = _2DEngine::getObject("player_2");
        if (tank)
        {
            parentObject->setPosition(tank->getPosition());

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
                parentObject->rotate(70.f*_2DEngine::Time::deltaTime);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
                parentObject->rotate(-70.f*_2DEngine::Time::deltaTime);
        }
        else
            _2DEngine::deleteObject(parentObject);
    }
    void start()
    {
        parentObject->setPosition(tank->getPosition());
        parentObject->setRotation(tank->getRotation());
        _2DEngine::addComponent<Renderer>(parentObject);
        parentObject->getComponent<Renderer>()->setTexture("tank/gun_2.png");
        parentObject->getComponent<Renderer>()->setSprite();
    }
    void collide(engine::CollisionDetails& details){}
private:
    virtual ~Gun_2_Script()
    {
        std::cout << "Gun_2_Script destructor" << std::endl;
    }
};

class Player_2_Script : public _2DEngine::BasicScript
{
public:
    float velocity = 150;
    std::vector<GameObject*> childrens;
    void update()
    {
        parentObject->setVelocity(0,0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
        {
            parentObject->rotate(-70.f*_2DEngine::Time::deltaTime);
            childrens[0]->rotate(-70.f*_2DEngine::Time::deltaTime);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        {
            parentObject->rotate(70.f*_2DEngine::Time::deltaTime);
            childrens[0]->rotate(70.f*_2DEngine::Time::deltaTime);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        {
            parentObject->setVelocity(velocity * sin(parentObject->getRotation() * 3.1416/180),
                                        velocity * -cos(parentObject->getRotation() * 3.1416/180));
            parentObject->getComponent<Animation>()->updateForward();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        {
            parentObject->setVelocity(-velocity * sin(parentObject->getRotation() * 3.1416/180),
                                        velocity * cos(parentObject->getRotation() * 3.1416/180));
            parentObject->getComponent<Animation>()->updateBackward();
        }
    }
    void start()
    {
        parentObject->setPosition(400, 75);
        _2DEngine::addComponent<Renderer>(parentObject->name);
        parentObject->getComponent<Renderer>()->setTexture("tank/Tank.png");
        _2DEngine::addComponent<Animation>(parentObject->name);
        parentObject->getComponent<Animation>()->addFrame(sf::IntRect(0,0,128,128));
        parentObject->getComponent<Animation>()->addFrame(sf::IntRect(128,0,128,128));
        //parentObject->getComponent<Animation>()->addFrame(sf::IntRect(256,0,128,128));
        //parentObject->getComponent<Animation>()->addFrame(sf::IntRect(384,0,128,128));
        parentObject->getComponent<Animation>()->setTexture();
        parentObject->getComponent<Animation>()->fps = 70;

        _2DEngine::addComponent<PhysicalBody>(parentObject->name);
        _2DEngine::addComponent<RectCollider>(parentObject->name);
        parentObject->getComponent<RectCollider>()->setCollider(-15,-15, 14,14);
        parentObject->getComponent<Animation>()->updateForward();
        parentObject->getComponent<RectCollider>()->display();

        childrens.push_back(_2DEngine::getObject("gun_2"));
    }
    void collide(engine::CollisionDetails& details)
    {
        if (_2DEngine::getObject("player_1"))
            if (details.collider1->parentObject->name == "player_1" || details.collider2->parentObject->name == "player_1" )
                _2DEngine::deleteObject(parentObject);
    }
private:
    virtual ~Player_2_Script()
    {
        std::cout << "Player_2_Script destructor" << std::endl;
    }
};





#endif
