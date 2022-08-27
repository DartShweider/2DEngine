#ifndef RENDERER_H
#define RENDERER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "gameobjectcomponent.h"

namespace engine
{
    class Renderer: public GameObjectComponent
    {
    public:
        sf::Sprite sprite;
        sf::Texture texture;
        std::string name = "Renderer";
        ObjComponentName name2 = renderer;
        void draw();
        void setSprite(sf::Texture& newTexture);
        void setTexture(sf::Texture& newTexture);
        virtual ~Renderer(){std::cout << "Renderer destructor" << std::endl;}

    };
}


#endif // RENDERER_H
