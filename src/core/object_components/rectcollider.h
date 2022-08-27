#ifndef RECTCOLLIDER_H
#define RECTCOLLIDER_H
#include "gameobjectcomponent.h"
#include "SFML/Graphics.hpp"
#include <iostream>




namespace engine
{
    //class RectCollider;




    class RectCollider : public GameObjectComponent
    {
    public:
        RectCollider();
        virtual ~RectCollider(){std::cout << "RectCollider destructor" << std::endl;}
        std::string name = "RectCollider";
        ObjComponentName name2 = rectCollider;
        void setCollider(float x_1, float y_1, float x_2, float y_2);
        void setColliderBySprite();

        void display();
        void hide();

        sf::Vector2f leftUpper;
        sf::Vector2f rightBottom;
        //sf::Vector2f velocity;

        bool isDynamic = true;
        bool isActive = true;
        bool isPossibleCollision = true;

     private:
        bool displayed = false;

    };
}
#endif // RECTCOLLIDER_H
