#include "engine.h"
#include <iostream>
#include <iterator>

namespace engine
{

    Engine* Engine::ex_instance = 0;

    Engine::Engine()
    {
    }

    Engine* Engine::instance()
    {
        if (!ex_instance)
        {
            ex_instance = new Engine();
        }

        return ex_instance;

    }
    void Engine::selfInit()
    {
        this->drawManager = new DrawManager();
        this->dataStorage = new DataStorage();
        this->logicsManager = new LogicsManager();
        this->physicsManager = new PhysicsManager();

    }

    void Engine::engineRun()
    {
        while (drawManager->getWindow()->isOpen())
        {
            sf::Event event;
            drawManager->getWindow()->pollEvent(event);
            if (event.type == sf::Event::Closed)
            {
                drawManager->getWindow()->close();
            }
            Time::updateTime();
            logicsManager->updateLogics();
            physicsManager->updatePhysics();
            drawManager->drawAllObjects();
        }
    }
}
