#include "rectcollider.h"
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

    }

    void RectCollider::setColliderBySprite()
    {
        if (!parentObject->hasComponent<Renderer>())
                    return;

        auto textureSize = parentObject->getComponent<Renderer>()->texture.getSize();

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
