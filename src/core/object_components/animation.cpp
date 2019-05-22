#include "animation.h"
#include "../engine.h"



namespace engine
{
    Animation::Animation()
    {

    }
    void Animation::upload(std::string filePath)
    {
        sf::Texture texture;
        texture.loadFromFile(filePath);
        pictures.push_back(texture);
    }
    void Animation::update()
    {
        timeCounter += engine::Time::deltaTime;
        int spriteCounter = timeCounter*timeMultiplier;
        if (spriteCounter > pictures.size() - 1)
        {
            timeCounter = 0;
            spriteCounter = 0;
        }
        parentObject->getComponent<Renderer>()->setSprite(pictures[spriteCounter]);

    }

}
