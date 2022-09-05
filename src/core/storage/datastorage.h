#ifndef DATASTORAGE_H
#define DATASTORAGE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>




namespace engine
{
    class TextureNode
    {
    public:
        TextureNode(std::string m_name);
        std::string name;
        sf::Texture* texture;
    };

    class SoundBufferNode
    {
    public:
        SoundBufferNode(std::string m_name);
        std::string name;
        sf::SoundBuffer* soundBuffer;
    };

    class GameObject;

    class DataStorage
    {
    public:
        DataStorage();
        TextureNode* getTexture(std::string name);
        GameObject* getObject(std::string name);

        void loadTexture(std::string filePath);
        void loadSound(std::string filePath);
        void addObject(GameObject* object);
        void removeObject(std::string name);
        void removeObject(GameObject* object);
        bool isObjectExisting(std::string name);
        bool isObjectExisting(GameObject* object);

        template <typename AssetType>
        void loadAsset(std::string filePath);
    private:
        std::vector<GameObject*> gameObjects;
        std::vector<TextureNode*> textures;
        std::vector<SoundBufferNode*> soundBuffers;
    };

    template <typename AssetType>
    void DataStorage::loadAsset(std::string filePath)
    {
        if (typeid(AssetType).name() == typeid(sf::Texture).name())
        {
            loadTexture(filePath);
            return;
        }

        if (typeid(AssetType).name() == typeid(sf::Sound).name())
        {
            loadSound(filePath);
            return;
        }
    }
}
#endif // DATASTORAGE_H
