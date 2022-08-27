#ifndef ANIMATION_H
#define ANIMATION_H
#include "gameobjectcomponent.h"
#include "SFML/Graphics.hpp"
#include <vector>



namespace engine
{
    class Animation : public GameObjectComponent
    {
    public:

        Animation();
        virtual ~Animation(){std::cout << "Animation Destructor" << std::endl;}
        std::string name = "Animation";
        ObjComponentName name2 = animation;

        std::vector<sf::Texture> pictures;
        void upload(std::string filePath);
        void update();
        float timeCounter = 0;
        int timeMultiplier = 0;


    };
}


#endif // ANIMATION_H
