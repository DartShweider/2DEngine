#include "rectcollider.h"
#include "renderer.h"
#include "../engine.h"



namespace engine
{
    RectCollider::RectCollider()
    {

    }

    void RectCollider::setCollider(float x_1, float y_1, float x_2, float y_2)
    {
        leftUpper.x = x_1;
        leftUpper.y = y_1;
        rightBottom.x = x_2;
        rightBottom.y = y_2;
        setLines();
    }

    void RectCollider::setCollider(sf::Vector2f left_Upper, sf::Vector2f right_Bottom)
    {
        leftUpper = left_Upper;
        rightBottom = right_Bottom;// - sf::Vector2f(1 , 1);
        setLines();
    }

    void RectCollider::setLines()
    {
        lines[0] = sf::Vertex(sf::Vector2f(leftUpper.x, leftUpper.y));
        lines[1] = sf::Vertex(sf::Vector2f(leftUpper.x, rightBottom.y));

        lines[2] = sf::Vertex(sf::Vector2f(leftUpper.x, leftUpper.y));
        lines[3] = sf::Vertex(sf::Vector2f(rightBottom.x, leftUpper.y));

        lines[4] = sf::Vertex(sf::Vector2f(rightBottom.x, leftUpper.y));
        lines[5] = sf::Vertex(sf::Vector2f(rightBottom.x, rightBottom.y));

        lines[6] = sf::Vertex(sf::Vector2f(leftUpper.x, rightBottom.y));
        lines[7] = sf::Vertex(sf::Vector2f(rightBottom.x, rightBottom.y));
    }

    void RectCollider::setColliderBySprite()
    {
        if (!parentObject->hasComponent<Renderer>())
            return;

        auto textureSize = parentObject->getComponent<Renderer>()->getTexture()->getSize();

        leftUpper.x = 0 - textureSize.x / 2.0;
        leftUpper.y = 0 + textureSize.y / 2.0;

        rightBottom.x = 0 + textureSize.x / 2.0;
        rightBottom.y = 0 - textureSize.y / 2.0;

    }

    void RectCollider::display()
    {
        if (!displayed)
        {
            Engine::instance()->drawManager->addCollider(this);
            displayed = true;
        }
    }

    void RectCollider::hide()
    {
        if (displayed)
        {
            Engine::instance()->drawManager->removeCollider(this);
            displayed = false;
        }
    }

}
