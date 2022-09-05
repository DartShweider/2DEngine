#ifndef LOGICSMANAGER_H
#define LOGICSMANAGER_H
#include <vector>
#include "../objects/gameobject.h"
//#include "eventmanager.h" --// Disabled input module


namespace engine
{
    class CollisionDetails;
    class LogicsManager
    {
    public:
        LogicsManager();
        void updateLogics();
        void startAllScripts();
        void addScript(BasicScript* script);
        void removeScript(BasicScript* script);
        void collideObject(CollisionDetails& details);

        //EventManager* eventManager; --// Disabled input module
    private:
        std::vector<BasicScript*> notStartedScripts;
        std::vector<BasicScript*> allScripts;
        void updateAllScripts();


    };
}



#endif // LOGICSMANAGER_H
