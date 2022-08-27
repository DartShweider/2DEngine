#ifndef BASICSCRIPT_H
#define BASICSCRIPT_H
#include "gameobjectcomponent.h"
#include "rectcollider.h"


namespace engine
{
    struct CollisionDetails;
    class BasicScript: public GameObjectComponent
    {
    public:
        virtual void update() = 0;
        virtual void start() = 0;
        virtual void collide(CollisionDetails& details){}
        virtual ~BasicScript() { std::cout << "BasicScript destructor" << std::endl;}
        std::string name = "BasicScript";
        ObjComponentName name2 = basicScript;
    };
}
#endif // BASICSCRIPT_H
