#ifndef DATASTORAGE_H
#define DATASTORAGE_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include "../objects/gameobject.h"




namespace engine
{
    class DataStorage
    {
    public:
        DataStorage();
        std::vector<GameObject*> gameObjects;
        GameObject* findObject(std::string name);
        GameObject* findObject(GameObject* object);
        void removeObject(std::string name);
        void removeObject(GameObject* object);
    };
}
#endif // DATASTORAGE_H
