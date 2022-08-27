#include "tools.h"
#include <iostream>
#include "../engine.h"
#include <iterator>
#include <typeinfo>



namespace _2DEngine
{
    using namespace engine;

    void createObject(std::string name)
    {
        GameObject* obj = findObject(name);
        if(!obj)
        {
            Engine::instance()->dataStorage->gameObjects.push_back(new GameObject(name));
        }
        else
        {
            std::cout<< "Object with same name exists" << std::endl;
        }
        //std::cout << Engine::instance()->dataStorage->gameObjects.size() << std::endl;
    }




    void deleteObject(std::string name)
    {
        GameObject* object = findObject(name);
        if(object)
        {
            delete object;
            Engine::instance()->dataStorage->removeObject(object);
        }
    }
    void deleteObject(GameObject* object)
    {
        if(object)
        {

            delete object;
            Engine::instance()->dataStorage->removeObject(object);
        }
    }

    GameObject* findObject(std::string name)
    {
        return Engine::instance()->dataStorage->findObject(name);

    }

}

