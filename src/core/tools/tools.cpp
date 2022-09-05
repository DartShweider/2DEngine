#include "tools.h"
#include <iostream>
#include "../engine.h"
#include <iterator>
#include <typeinfo>



namespace _2DEngine
{
    using namespace engine;

    GameObject* getObject(std::string name)
    {
        return Engine::instance()->dataStorage->getObject(name);
    }

    GameObject* createObject(std::string name)
    {
        if(!Engine::instance()->dataStorage->isObjectExisting(name))
        {
            GameObject* object = new GameObject(name);
            Engine::instance()->dataStorage->addObject(object);
            return object;
        }

        else
        {
            std::cout<< "Object with same name exists" << std::endl;
            return nullptr;
        }
    }

    void deleteObject(std::string name)
    {
        if(Engine::instance()->dataStorage->isObjectExisting(name))
        {
            GameObject* object = getObject(name);
            delete object;
            Engine::instance()->dataStorage->removeObject(object);
        }
        else
        {
            std::cout << "Object cannot be deleted" << std::endl;
        }
    }

    void deleteObject(GameObject* object)
    {
        if(Engine::instance()->dataStorage->isObjectExisting(object))
        {
            delete object;
            Engine::instance()->dataStorage->removeObject(object);
        }
    }
}

