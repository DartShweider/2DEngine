#ifndef RECTCOLLIDER_H
#define RECTCOLLIDER_H
#include "gameobjectcomponent.h"
#include <SFML/Graphics.hpp>
#include <iostream>




namespace engine
{
    class RectCollider : public GameObjectComponent//, public sf::Drawable
    {
    public:
        RectCollider();
        virtual ~RectCollider(){std::cout << "RectCollider destructor" << std::endl;}

        void setCollider(float x_1, float y_1, float x_2, float y_2);
        void setCollider(sf::Vector2f left_Upper, sf::Vector2f right_Bottom);
        void setColliderBySprite();

        sf::Vertex lines[8];
        void setLines();

        void display();
        void hide();

        sf::Vector2f leftUpper;
        sf::Vector2f rightBottom;

        bool isDynamic = true;
        bool isActive = true;
        bool isPossibleCollision = true;

    private:
        bool displayed = false;

    };
}
#endif // RECTCOLLIDER_H
