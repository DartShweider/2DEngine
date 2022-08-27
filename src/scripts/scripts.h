
#ifndef PICTURESCRIPT_H
#define PICTURESCRIPT_H
#include "../core/engine.h"
#include <vector>


class Player_1_Script : public _2DEngine::BasicScript
{
public:
    float velocity = 150;
    std::string name = "BasicScript";
    int name2 = 10;
    void update()
    {
        parentObject->getComponent<PhysicalBody>()->velocity = sf::Vector2f(0,0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            parentObject->directionAngle  -= 70.f*_2DEngine::Time::deltaTime;
            parentObject->getComponent<Renderer>()->sprite.setRotation(parentObject->directionAngle + 90);
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {

            parentObject->directionAngle  += 70.f*_2DEngine::Time::deltaTime;
            parentObject->getComponent<Renderer>()->sprite.setRotation(parentObject->directionAngle + 90);

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            parentObject->getComponent<PhysicalBody>()->velocity = sf::Vector2f(velocity * cos(parentObject->directionAngle * 3.1416/180),
                                                                                velocity * sin(parentObject->directionAngle * 3.1416/180));
            //parentObject->position.x += velocity * cos(parentObject->directionAngle * 3.1416/180) * _2DEngine::Time::deltaTime;
            //parentObject->position.y += velocity * sin(parentObject->directionAngle * 3.1416/180) * _2DEngine::Time::deltaTime;
            parentObject->getComponent<Animation>()->update();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            parentObject->getComponent<PhysicalBody>()->velocity = sf::Vector2f(-velocity * cos(parentObject->directionAngle * 3.1416/180),
                                                                                -velocity * sin(parentObject->directionAngle * 3.1416/180));
            //parentObject->position.x -= velocity * cos(parentObject->directionAngle * 3.1416/180) * _2DEngine::Time::deltaTime;
            //parentObject->position.y -= velocity * sin(parentObject->directionAngle * 3.1416/180) * _2DEngine::Time::deltaTime;
            parentObject->getComponent<Animation>()->update();
        }
    }
    void start()
    {
        parentObject->setPosition(600, 600);
        _2DEngine::addComponent<Renderer>(parentObject->name);
        _2DEngine::addComponent<Animation>(parentObject->name);

        for(int i = 1; i<=2; i++)
        {
            parentObject->getComponent<Animation>()->upload("tank/tank_" + std::to_string(i) + ".png");
        }
        parentObject->getComponent<Renderer>()->setSprite(parentObject->getComponent<Animation>()->pictures[0]);
        parentObject->getComponent<Renderer>()->sprite.setRotation(parentObject->directionAngle + 90);
        parentObject->getComponent<Animation>()->timeMultiplier = 32;

        _2DEngine::addComponent<PhysicalBody>(parentObject->name);
        _2DEngine::addComponent<RectCollider>(parentObject->name);
        parentObject->getComponent<RectCollider>()->setCollider(-15,-15, 15,15);

        parentObject->getComponent<RectCollider>()->display();

        //creation gun

    }
    void collide(engine::CollisionDetails& details)
    {
    }

    virtual ~Player_1_Script()
    {
        std::cout << "Player_1_Script destructor" << std::endl;
    }

};

class LevelScript : public _2DEngine::BasicScript
{
public:
    std::string name = "BasicScript";

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

    void update(){}
    void start()
    {
        for (int i = 0; i < level.size(); i++)
        {
            for (int j = 0; j < level[i].size(); j++)
            {
                if (level[i][j] == 1 )
                {
                    _2DEngine::createObject("block" + std::to_string(i) + std::to_string(j));
                    _2DEngine::findObject("block" + std::to_string(i) + std::to_string(j))->setPosition(25 + 50* j, 25 + 50*i);
                    _2DEngine::addComponent<Renderer>("block" + std::to_string(i) + std::to_string(j));
                    sf::Texture texture;
                    texture.loadFromFile("blocks/undeadblock.png");
                    _2DEngine::findObject("block" + std::to_string(i) + std::to_string(j))->getComponent<Renderer>()->setSprite(texture);
                    _2DEngine::addComponent<PhysicalBody>("block" + std::to_string(i) + std::to_string(j));
                    _2DEngine::addComponent<RectCollider>("block" + std::to_string(i) + std::to_string(j));
                    _2DEngine::findObject("block" + std::to_string(i) + std::to_string(j))->getComponent<RectCollider>()->setCollider(-25,-25,25,25);
                }

                if (level[i][j] == 2 )
                {
                     _2DEngine::createObject("block" + std::to_string(i) + std::to_string(j));
                    _2DEngine::findObject("block" + std::to_string(i) + std::to_string(j))->setPosition(25 + 50* j, 25 + 50*i);
                    _2DEngine::addComponent<Renderer>("block" + std::to_string(i) + std::to_string(j));
                    sf::Texture texture;
                    texture.loadFromFile("blocks/crashblock.png");
                    _2DEngine::findObject("block" + std::to_string(i) + std::to_string(j))->getComponent<Renderer>()->setSprite(texture);
                    _2DEngine::addComponent<PhysicalBody>("block" + std::to_string(i) + std::to_string(j));
                    _2DEngine::addComponent<RectCollider>("block" + std::to_string(i) + std::to_string(j));
                    _2DEngine::findObject("block" + std::to_string(i) + std::to_string(j))->getComponent<RectCollider>()->setCollider(-25,-25,25,25);
                }
            }
        }
    }

};

class Player_2_Script : public _2DEngine::BasicScript
{
public:
    std::string name = "BasicScript";
    float velocity = 150;
    void update()
    {
        parentObject->getComponent<PhysicalBody>()->velocity = sf::Vector2f(0,0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
        {
            parentObject->directionAngle  -= 70.f*_2DEngine::Time::deltaTime;
            parentObject->getComponent<Renderer>()->sprite.setRotation(parentObject->directionAngle + 90);
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        {

            parentObject->directionAngle  += 70.f*_2DEngine::Time::deltaTime;
            parentObject->getComponent<Renderer>()->sprite.setRotation(parentObject->directionAngle + 90);

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        {
            parentObject->getComponent<PhysicalBody>()->velocity = sf::Vector2f(velocity * cos(parentObject->directionAngle * 3.1416/180),
                                                                                velocity * sin(parentObject->directionAngle * 3.1416/180));
            //parentObject->position.x += velocity * cos(parentObject->directionAngle * 3.1416/180) * _2DEngine::Time::deltaTime;
            //parentObject->position.y += velocity * sin(parentObject->directionAngle * 3.1416/180) * _2DEngine::Time::deltaTime;
            parentObject->getComponent<Animation>()->update();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        {
            parentObject->getComponent<PhysicalBody>()->velocity = sf::Vector2f(-velocity * cos(parentObject->directionAngle * 3.1416/180),
                                                                                -velocity * sin(parentObject->directionAngle * 3.1416/180));
            //parentObject->position.x -= velocity * cos(parentObject->directionAngle * 3.1416/180) * _2DEngine::Time::deltaTime;
            //parentObject->position.y -= velocity * sin(parentObject->directionAngle * 3.1416/180) * _2DEngine::Time::deltaTime;

            parentObject->getComponent<Animation>()->update();

        }
    }
    void start()
    {
        parentObject->setPosition(400, 75);
        _2DEngine::addComponent<Renderer>(parentObject->name);
        _2DEngine::addComponent<Animation>(parentObject->name);

        for(int i = 1; i<=2; i++)
        {
            parentObject->getComponent<Animation>()->upload("tank/tank_" + std::to_string(i) + ".png");
        }
        parentObject->getComponent<Renderer>()->setSprite(parentObject->getComponent<Animation>()->pictures[0]);
        parentObject->getComponent<Renderer>()->sprite.setRotation(parentObject->directionAngle + 90);
        parentObject->getComponent<Animation>()->timeMultiplier = 32;

        _2DEngine::addComponent<PhysicalBody>(parentObject->name);
        _2DEngine::addComponent<RectCollider>(parentObject->name);
        parentObject->getComponent<RectCollider>()->setCollider(-15,-15, 15,15);

        parentObject->getComponent<RectCollider>()->display();
        //parentObject->getComponent<RectCollider>()->display();y = sf::Vector2f(150, 0);
    }
    void collide(engine::CollisionDetails& details)
    {
        if (_2DEngine::findObject("player_1"))
            if (details.collider1->parentObject->name == "player_1" || details.collider2->parentObject->name == "player_1" )
                _2DEngine::deleteObject(parentObject);
    }
    virtual ~Player_2_Script()
    {
        std::cout << "Player_2_Script destructor" << std::endl;
    }

};

class Gun_2_Script : public _2DEngine::BasicScript
{
public:
    std::string name = "BasicScript";
    GameObject* tank = _2DEngine::findObject("player_2");
    void update()
    {
        tank = _2DEngine::findObject("player_2");
        if (tank)
        {
            parentObject->setPosition(tank->position.x, tank->position.y);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
                parentObject->directionAngle  += 70.f*_2DEngine::Time::deltaTime;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                parentObject->directionAngle  -= 70.f*_2DEngine::Time::deltaTime;

            parentObject->getComponent<Renderer>()->sprite.setRotation(parentObject->directionAngle + 90 + tank->directionAngle);
        }
        else
            _2DEngine::deleteObject(parentObject);

    }
    void start()
    {
        parentObject->setPosition(tank->position.x, tank->position.y);
        sf::Texture texture;
        parentObject->directionAngle = tank->directionAngle;
        texture.loadFromFile("tank/gun_2.png");
        _2DEngine::addComponent<Renderer>(parentObject);
        parentObject->getComponent<Renderer>()->setSprite(texture);
    }
    void collide(engine::CollisionDetails& details){}
    virtual ~Gun_2_Script()
    {
        std::cout << "Gun_2_Script destructor" << std::endl;
    }
};
/*
class Event_1_Script : public _2DEngine::BasicScript
{
public:

    GameObject* tank = _2DEngine::findObject("player_1");
    void update()
    {
        parentObject->setPosition(tank->position.x, tank->position.y);


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            parentObject->directionAngle  += 70.f*_2DEngine::Time::deltaTime;

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            parentObject->directionAngle  -= 70.f*_2DEngine::Time::deltaTime;

        }
        parentObject->getComponent<Renderer>()->sprite.setRotation(parentObject->directionAngle + 90 + tank->directionAngle);
    }
    void start()
    {
        parentObject->setPosition(tank->position.x, tank->position.y);
        sf::Texture texture;
        parentObject->directionAngle = tank->directionAngle;
        texture.loadFromFile("tank/gun_2.png");
        parentObject->addComponent<Renderer>();
        parentObject->getComponent<Renderer>()->setSprite(texture);
    }
    void collide(engine::CollisionDetails& details){}
};
*/




#endif
