#ifndef RENDERER_H
#define RENDERER_H
#include <SFML/Graphics.hpp>
#include "gameobjectcomponent.h"
#include <SFML/Graphics/Drawable.hpp>


namespace engine
{
    class Renderer: public GameObjectComponent, public sf::Drawable
    {
    public:
        sf::Sprite& getSprite();
        sf::Texture* getTexture();

        void setSprite();
        void setTexture(sf::Texture* newTexture);
        void setTexture(std::string name);
        void update();

    private:
        sf::Sprite sprite;
        sf::Texture* texture;

        virtual ~Renderer(){std::cout << "Renderer destructor" << std::endl;}
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


    };
}


#endif // RENDERER_H
