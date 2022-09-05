#ifndef ANIMATION_H
#define ANIMATION_H
#include "gameobjectcomponent.h"
#include "SFML/Graphics.hpp"
#include <vector>



namespace engine
{
    class TextureNode;
    class GameObjectComponent;
    class Animation : public GameObjectComponent
    {
    public:

        Animation();
        virtual ~Animation(){std::cout << "Animation Destructor" << std::endl;}
        void setTexture();
        void addFrame(sf::IntRect rect);
        void updateForward();
        void updateBackward();
        float timeCounter = 0;
        int fps = 1;

        sf::IntRect& getFrame(std::size_t n);
        std::size_t getFramesSize();
    private:
        std::vector<sf::IntRect> frames;
        sf::Texture* texture = nullptr;
        std::size_t currentFrame = 0;
    };
}


#endif // ANIMATION_H
