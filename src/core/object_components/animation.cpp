#include "animation.h"
#include "renderer.h"
#include "../tools/time.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

namespace engine
{
    Animation::Animation()
    {

    }

    void Animation::setTexture()
    {
        texture = parentObject->getComponent<Renderer>()->getTexture();
    }

    void Animation::addFrame(sf::IntRect rect)
    {
        frames.push_back(rect);
    }

    sf::IntRect& Animation::getFrame(std::size_t n)
    {
        return frames[n];
    }

    std::size_t Animation::getFramesSize()
    {
        return frames.size();
    }

    void Animation::updateForward()
    {
        timeCounter += _2DEngine::Time::deltaTime;
        currentFrame = timeCounter*fps;
        if (currentFrame + 1 > frames.size())
        {
            timeCounter = 0;
            currentFrame = 0;
        }
        parentObject->getComponent<Renderer>()->setSprite();
        parentObject->getComponent<Renderer>()->getSprite().setTextureRect(frames[currentFrame]);
        parentObject->getComponent<Renderer>()->getSprite().setOrigin(frames[currentFrame].width/2, frames[currentFrame].height/2);
    }

     void Animation::updateBackward()
    {
        timeCounter += _2DEngine::Time::deltaTime;
        currentFrame = frames.size() - timeCounter*fps;

        if (currentFrame < 1)
        {
            timeCounter = 0;
            currentFrame = frames.size() - 1;
        }
        parentObject->getComponent<Renderer>()->setSprite();
        parentObject->getComponent<Renderer>()->getSprite().setTextureRect(frames[currentFrame]);
        parentObject->getComponent<Renderer>()->getSprite().setOrigin(frames[currentFrame].width/2, frames[currentFrame].height/2);
    }
}
