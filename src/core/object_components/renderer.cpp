#include "renderer.h"
#include "../engine.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

namespace engine
{
    void Renderer::setSprite()
    {
        sprite.setTexture(*texture);
        sprite.setOrigin(texture->getSize().x/2, texture->getSize().y/2);
    }

    void Renderer::update()
    {
        sprite.setPosition(this->parentObject->getPosition());
        sprite.setRotation(parentObject->getRotation());
    }

    void Renderer::setTexture(sf::Texture* newTexture)
    {
        if(newTexture)
            texture = newTexture;
        else
            std::cout << "unable to set texture" << std::endl;
    }

    void Renderer::setTexture(std::string name)
    {
        texture = Engine::instance()->dataStorage->getTexture(name)->texture;
    }

    void Renderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(sprite, states);
    }

    sf::Sprite& Renderer::getSprite()
    {
        return sprite;
    }

    sf::Texture* Renderer::getTexture()
    {
        return texture;
    }
}
