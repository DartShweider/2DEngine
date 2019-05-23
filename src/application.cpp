#include "application.h"
#include "core/tools/tools.h"
#include <iostream>
#include "core/objects/gameobject.h"
#include "scripts/scripts.h"

Application::Application()
{

}


void Application::createObjects()
{
    //creation player object
    _2DEngine::createObject("player_1");
    _2DEngine::findObject("player_1")->addComponent<Player_1_Script>();



    //creation enemy object
    _2DEngine::createObject("player_2");
    _2DEngine::findObject("player_2")->addComponent<Player_2_Script>();

    //creation level
    _2DEngine::createObject("level_1");
    _2DEngine::findObject("level_1")->addComponent<LevelScript>();

    //creation gun
    _2DEngine::createObject("gun_2");
    _2DEngine::findObject("gun_2")->addComponent<Gun_2_Script>();

}



void Application::appRun()
{
    _2DEngine::Engine::instance()->selfInit();
    createObjects();
    _2DEngine::Engine::instance()->engineRun();

}
