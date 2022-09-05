#include "application.h"
#include <iostream>
#include "core/engine.h"
#include "scripts/scripts.h"

using namespace engine;

Application::Application()
{

}

void Application::loadAssets()
{
    _2DEngine::loadAsset<sf::Texture>("tank/Tank3.png");
    _2DEngine::loadAsset<sf::Texture>("tank/Tank.png");
    _2DEngine::loadAsset<sf::Texture>("blocks/undeadblock.png");
    _2DEngine::loadAsset<sf::Texture>("blocks/crashblock.png");
    _2DEngine::loadAsset<sf::Texture>("tank/gun_2.png");
}

void Application::createObjects()
{
    //create player object
    _2DEngine::createObject("player_1");
    _2DEngine::addComponent<Player_1_Script>("player_1");
    //_2DEngine::deleteObject("player_1");

    //create enemy object
    _2DEngine::createObject("player_2");
    _2DEngine::addComponent<Player_2_Script>("player_2");

    //create level
    _2DEngine::createObject("level_1");
    _2DEngine::addComponent<LevelScript>("level_1");

    //create gun
    _2DEngine::createObject("gun_2");
    _2DEngine::addComponent<Gun_2_Script>("gun_2");
}

void Application::appRun()
{
    _2DEngine::Engine::instance()->selfInit();
    loadAssets();
    createObjects();
    _2DEngine::Engine::instance()->engineRun();
}
