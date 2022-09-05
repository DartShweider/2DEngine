#include "datastorage.h"
#include "../objects/gameobject.h"
#include <SFML/Audio.hpp>


namespace engine
{
    TextureNode::TextureNode(std::string m_name)
    {
        name = m_name;
        texture = new sf::Texture;
    }

    SoundBufferNode::SoundBufferNode(std::string m_name)
    {
        name = m_name;
        soundBuffer = new sf::SoundBuffer;
    }

    void DataStorage::loadSound(std::string filePath)
    {
        SoundBufferNode* currentData = new SoundBufferNode(filePath);
        if (!currentData->soundBuffer->loadFromFile(filePath))
            throw;
        soundBuffers.push_back(currentData);
    }

    void DataStorage::loadTexture(std::string filePath)
    {
        TextureNode* currentData = new TextureNode(filePath);
        if (!currentData->texture->loadFromFile(filePath))
            throw;
        textures.push_back(currentData);
    }

    TextureNode* DataStorage::getTexture(std::string name)
    {
        for (auto elem : textures)
        {
            if (elem->name == name)
                return elem;
        }
        std::cout << "Texture not found" << std::endl;
        return nullptr;
    }

    void DataStorage::addObject(GameObject* object)
    {
        gameObjects.push_back(object);
    }

    DataStorage::DataStorage()
    {

    }

    bool DataStorage::isObjectExisting(std::string name)
    {
        for (auto elem : gameObjects)
            if (elem->name == name)
                return true;
        return false;
    }

    bool DataStorage::isObjectExisting(GameObject* object)
    {
        for (auto elem : gameObjects)
            if (elem == object)
                return true;
        return false;
    }

    GameObject* DataStorage::getObject(std::string name)
    {
        for (auto elem : gameObjects)
            if (elem->name == name)
                return elem;
        std::cout << "Object doesn't exist" << std::endl;
        return nullptr;
    }

    void DataStorage::removeObject(std::string name)
    {
        GameObject* object = getObject(name);
        if (object)
            gameObjects.erase(remove(gameObjects.begin(), gameObjects.end(), object), gameObjects.end());
    }

    void DataStorage::removeObject(GameObject* object)
    {
        if (object)
            gameObjects.erase(remove(gameObjects.begin(), gameObjects.end(), object), gameObjects.end());
    }

}
