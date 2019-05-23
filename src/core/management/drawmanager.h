#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "../object_components/renderer.h"
#include "../object_components/rectcollider.h"
#include <math.h>


namespace engine
{

    struct WindowSettings
    {
        inline static const  std::string name = "Example";
        static const int width = 1600;
        static const int height = 900;
    };

    class DrawManager
    {
    public:
        DrawManager();

        sf::RenderWindow* getWindow();

        void drawObject(sf::Drawable& object);
        void drawCollider(RectCollider* collider);
        void drawAllObjects();

        std::vector<Renderer*> allRenderers;
        std::vector<RectCollider*> allRectColliders;

        void addRenderer(Renderer* renderer);
        void removeRenderer(Renderer* renderer);

        void addCollider(RectCollider* collider);
        void removeCollider(RectCollider* collider);

    private:
        sf::RenderWindow* window;
    };
}


#endif // DRAWMANAGER_H
