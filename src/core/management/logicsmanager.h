#ifndef LOGICSMANAGER_H
#define LOGICSMANAGER_H
#include <vector>
#include "../objects/gameobject.h"
//#include "eventmanager.h" --// Disabled input module


namespace engine
{
    class LogicsManager
    {
    public:
        LogicsManager();
        void updateLogics();
        void startAllScripts();
        void updateAllScripts();
        void collideObject(CollisionDetails& details);
        void addScript(BasicScript* script);
        void removeScript(BasicScript* script);
        std::vector<BasicScript*> notStartedScripts;
        std::vector<BasicScript*> allScripts;

        //EventManager* eventManager; --// Disabled input module
    private:



    };
}



#endif // LOGICSMANAGER_H
