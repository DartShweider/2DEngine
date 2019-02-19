#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#include <SFML/Graphics.hpp>
#include "eventhandler.h"
#include <map>


class EventManager
{
private:



public:

    EventManager();
    void Execute(EventHandler Handler, sf::RenderWindow window);
    std::map <sf::Event.type, std::string> Binder;

};

#endif // EVENTMANAGER_H
