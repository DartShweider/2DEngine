#include "application.h"
//#include "core/tools/tools.h"
#include <iostream>
#include "core/engine.h"
//#include "core/objects/gameobject.h"
#include "scripts/scripts.h"

Application::Application()
{

}


void Application::createObjects()
{
    //creation player object
    _2DEngine::createObject("player_1");
    _2DEngine::addComponent<Player_1_Script>("player_1");
    //_2DEngine::deleteObject("player_1");
    //


    //creation enemy object
    _2DEngine::createObject("player_2");
    _2DEngine::addComponent<Player_2_Script>("player_2");

    //creation level
    _2DEngine::createObject("level_1");
    _2DEngine::addComponent<LevelScript>("level_1");

    //creation gun
    _2DEngine::createObject("gun_2");
    _2DEngine::addComponent<Gun_2_Script>("gun_2");

}



void Application::appRun()
{
    _2DEngine::Engine::instance()->selfInit();
    createObjects();
    _2DEngine::Engine::instance()->engineRun();


}
