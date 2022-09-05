#include "drawmanager.h"
#include "../object_components/renderer.h"
#include "../object_components/rectcollider.h"
#include "../engine.h"
#include <SFML/Graphics.hpp>





namespace engine
{
    DrawManager::DrawManager()
    {
        window = new sf::RenderWindow(sf::VideoMode(WindowSettings::width, WindowSettings::height), WindowSettings::name);
        //window->setFramerateLimit(60);
    }

    void DrawManager::drawAllObjects()
    {
        window->clear();

        for (auto element : Engine::instance() -> drawManager -> allRenderers)
            {
                element->update();
                window->draw(*element);
            };
        for (auto element : Engine::instance() -> drawManager -> allRectColliders)
            {
                drawCollider(element);
            };

        window->display();
    }

    sf::RenderWindow* DrawManager::getWindow()
    {
        return window;
    }

    void DrawManager::drawObject(sf::Drawable& object)
    {
        window->draw(object);
    }

    void DrawManager::addRenderer(Renderer* renderer)
    {
        allRenderers.push_back(renderer);
    }

    void DrawManager::removeRenderer(Renderer* renderer)
    {
        allRenderers.erase(remove(allRenderers.begin(), allRenderers.end(), renderer), allRenderers.end());
    }

    void DrawManager::addCollider(RectCollider* collider)
    {
        allRectColliders.push_back(collider);
    }

    void DrawManager::removeCollider(RectCollider* collider)
    {
        allRectColliders.erase(remove(allRectColliders.begin(), allRectColliders.end(), collider), allRectColliders.end());
    }

    void DrawManager::drawCollider(RectCollider* collider)
    {
        sf::Vertex lines[8];
        lines[0] = sf::Vertex(sf::Vector2f(collider->leftUpper.x, collider->leftUpper.y));
        lines[1] = sf::Vertex(sf::Vector2f(collider->leftUpper.x, collider->rightBottom.y));

        lines[2] = sf::Vertex(sf::Vector2f(collider->leftUpper.x, collider->leftUpper.y));
        lines[3] = sf::Vertex(sf::Vector2f(collider->rightBottom.x, collider->leftUpper.y));

        lines[4] = sf::Vertex(sf::Vector2f(collider->rightBottom.x, collider->leftUpper.y));
        lines[5] = sf::Vertex(sf::Vector2f(collider->rightBottom.x, collider->rightBottom.y));

        lines[6] = sf::Vertex(sf::Vector2f(collider->leftUpper.x, collider->rightBottom.y));
        lines[7] = sf::Vertex(sf::Vector2f(collider->rightBottom.x, collider->rightBottom.y));
        for (auto& line : lines)
            line.position = sf::Vector2f(line.position.x + collider->parentObject->getPosition().x, line.position.y + collider->parentObject->getPosition().y);

        getWindow()->draw(lines, 8, sf::Lines);
    }
}
