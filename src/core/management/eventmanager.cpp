#include <SFML/Graphics.hpp>

#include <iostream>

#include "../engine.h"
#include "eventmanager.h"
#include "../tools/input.h"


namespace engine
{

    EventManager::EventManager()
    {

    }

    void EventManager::catchEvents()
    {
        sf::Event event;
        auto window = Engine::instance()->drawManager->getWindow();

        while(window->pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
                KeyboardInput::keyPressed(event.key.code);

            if (event.type == sf::Event::KeyReleased)
                KeyboardInput::keyReleased(event.key.code);

            catchedEvents.push_back(event);

            if (event.type == sf::Event::Closed)
                window->close();

        }

    }

    void EventManager::clearEvents()
    {
        catchedEvents.clear();
    }

    std::vector<sf::Event> EventManager::getEventsThisType(sf::Event::EventType eventType)
    {

        std::vector<sf::Event> eventsThisType;

        for (auto event : catchedEvents)
        {
            if (event.type == eventType)
            {
                eventsThisType.push_back(event);
            }
        }

                return eventsThisType;
    }


}
