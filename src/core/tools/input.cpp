#include "input.h"

#include "../engine.h"

namespace engine
{
    std::map<KeyCode, bool> KeyboardInput::isKeyHold;
    std::map<KeyCode, bool> KeyboardInput::isPressedOnce;

    bool KeyboardInput::getKey(KeyCode key)
    {
        return isKeyHold[key];
    }

    bool KeyboardInput::getKeyDown(KeyCode key)
    {
        auto keyPressedEvents = Engine::instance()->logicsManager->eventManager->getEventsThisType(sf::Event::KeyPressed);

        for (auto event : keyPressedEvents)
            if (event.key.code == key && isPressedOnce[key])
                return true;

        return false;
    }

    bool KeyboardInput::getKeyUp(KeyCode key)
    {
        auto keyPressedEvents = Engine::instance()->logicsManager->eventManager->getEventsThisType(sf::Event::KeyReleased);

        for (auto event : keyPressedEvents)
            if (event.key.code == key)
                return true;

        return false;
    }

    void KeyboardInput::keyPressed(sf::Keyboard::Key key)
    {
        auto keyCode = convertFromSfmlKey(key);

        isPressedOnce[keyCode] = true;

        if (isKeyHold[keyCode])
            isPressedOnce[keyCode] = false;

        isKeyHold[keyCode] = true;
    }

    void KeyboardInput::keyReleased(sf::Keyboard::Key key)
    {
        auto keyCode = convertFromSfmlKey(key);

        //isPressedOnce[keyCode] = false;
        isKeyHold[keyCode] = false;
    }


    KeyCode KeyboardInput::convertFromSfmlKey(sf::Keyboard::Key key)
    {
        switch(key)
        {
            case KeyCode::W:        return W;
            case KeyCode::A:        return A;
            case KeyCode::S:        return S;
            case KeyCode::D:        return D;
            case KeyCode::Space:    return Space;

        }
    }
}
