#include "renderer.h"
#include "../engine.h"

namespace engine
{
    void Renderer::draw(sf::RenderWindow* window)
    {
        sf::Vector2u textureSize = texture.getSize();
        sprite.setPosition(parentObject->position.x, parentObject->position.y);
        Engine::instance()->drawManager->drawObject(sprite);
    }

    void Renderer::setSprite(sf::Texture& newTexture)
    {
        texture = newTexture;
        sprite.setTexture(texture);
        sprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);

    }

    void Renderer::setTexture(sf::Texture& newTexture)
    {

        setSprite(newTexture);
    }


}
