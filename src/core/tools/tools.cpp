#include "tools.h"
#include <iostream>
#include "../engine.h"
#include <iterator>




namespace _2DEngine
{
    void createObject(std::string name)
    {
        if(findObject(name) == 0)
        {
            Engine::instance()->dataStorage->gameObjects[name] = new GameObject(name);
        }
        else
        {
            std::cout<< "Object with same name exists" << std::endl;
        }
    }


    void deleteObject(std::string name)
    {
        GameObject* object = findObject(name);
        if(object != 0)
        {
            delete object;
            Engine::instance()->dataStorage->gameObjects.erase(name);
        }
    }
    void deleteObject(GameObject* object)
    {
            delete object;
            Engine::instance()->dataStorage->gameObjects.erase(object->name);
    }

    GameObject* findObject(std::string name)
    {

        return Engine::instance()->dataStorage->gameObjects[name];

    }
}

