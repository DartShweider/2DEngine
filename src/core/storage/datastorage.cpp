#include "datastorage.h"




namespace engine
{

    DataStorage::DataStorage()
    {

    }
    GameObject* DataStorage::findObject(std::string name)
    {
        for (auto elem : gameObjects)
            if (elem->name == name)
                return elem;

        return nullptr;
    }
    GameObject* DataStorage::findObject(GameObject* objPtr)
    {
        for (auto elem : gameObjects)
            if (elem == objPtr)
                return elem;
        return nullptr;
    }
    void DataStorage::removeObject(std::string name)
    {
        GameObject* object = findObject(name);
        if (object)
            gameObjects.erase(remove(gameObjects.begin(), gameObjects.end(), object), gameObjects.end());
    }

    void DataStorage::removeObject(GameObject* object)
    {
        if (object)
            gameObjects.erase(remove(gameObjects.begin(), gameObjects.end(), object), gameObjects.end());
    }
}
