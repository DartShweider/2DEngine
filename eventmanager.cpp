#include "eventmanager.h"
#include <SFML/Graphics.hpp>
#include "eventhandler.h"

EventManager::EventManager()
{

}



void EventManager::Execute(EventHandler Handler, sf::RenderWindow window)
{

    sf::Event event;
    while(window.pollEvent(event))
    {
        //std::string action = Binder.find(event.type);


    }




}
