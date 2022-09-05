#ifndef TOOLS_H
#define TOOLS_H
#include "../objects/gameobject.h"
#include "../engine.h"
#include <string>




namespace _2DEngine
{
    using namespace engine;
    GameObject* createObject(std::string name);
    void deleteObject(std::string name);
    void deleteObject(GameObject* object);
    GameObject* getObject(std::string name);

    template <typename AssetType>
    void loadAsset(std::string filePath)
    {
        Engine::instance()->dataStorage->loadAsset<AssetType>(filePath);
    }

    template <typename ComponentType>
    void addComponent(std::string name)
    {
        if(Engine::instance()->dataStorage->isObjectExisting(name))
        {
            GameObject* currentObj = getObject(name);
            if (!currentObj->hasComponent<ComponentType>())
            {
                ComponentType* component = new ComponentType;
                component->parentObject = currentObj;
                currentObj->addComponent(component);
                currentObj->registerObjComponent(component);
            }
            else
            {
                std::cout << "Unable to add component: " << typeid(ComponentType).name() << std::endl;
            }
        }
        else
            std::cout << "Object not found: " << name << std::endl;
    }

    template <typename ComponentType>
    void addComponent(GameObject* currentObj)
    {
        if (currentObj)
        {
            if (!currentObj->hasComponent<ComponentType>())
            {
                ComponentType* component = new ComponentType;
                component->parentObject = currentObj;
                currentObj->addComponent(component);
                currentObj->registerObjComponent(component);
            }
            else
            {
                std::cout << "Unable to add component: " << typeid(ComponentType).name() << std::endl;
            }
        }
        else
            std::cout << "Object not found: " << currentObj << std::endl;
    }
}

#endif // TOOLS_H
