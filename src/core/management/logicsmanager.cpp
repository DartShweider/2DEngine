#include "logicsmanager.h"
#include "../engine.h"

namespace engine
{

    LogicsManager::LogicsManager()
    {
        //eventManager = new EventManager; --// Disabled input module
    }

    void LogicsManager::updateLogics()
    {


        //eventManager->catchEvents(); --// Disabled input module

        startAllScripts();
        //std::cout << "logics manager start scripts" << std::endl;
        updateAllScripts();

        //eventManager->clearEvents(); --// Disabled input module
    }

    void LogicsManager::startAllScripts()
    {
        if (notStartedScripts.size())
        {
            for (auto script : notStartedScripts)
                script->start();

            notStartedScripts.clear();
        }
    }

    void LogicsManager::updateAllScripts()
    {
        for (auto script : allScripts)
            script->update();
    }

    void LogicsManager::collideObject(CollisionDetails& details)
    {
        for (auto script : allScripts)
            if (script->parentObject == details.collider1->parentObject || script->parentObject == details.collider2->parentObject)
            {
                script->collide(details);
            }
    }

    void LogicsManager::addScript(BasicScript* script)
    {
        notStartedScripts.push_back(script);
        allScripts.push_back(script);
    }

    void LogicsManager::removeScript(BasicScript* script)
    {
        allScripts.erase(remove(allScripts.begin(), allScripts.end(), script), allScripts.end());
        notStartedScripts.erase(remove(notStartedScripts.begin(), notStartedScripts.end(), script), notStartedScripts.end());
    }
}
