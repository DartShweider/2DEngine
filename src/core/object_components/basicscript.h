#ifndef BASICSCRIPT_H
#define BASICSCRIPT_H
#include "gameobjectcomponent.h"


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
    };
}
#endif // BASICSCRIPT_H
