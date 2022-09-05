#ifndef TIME_H
#define TIME_H
#include "../objects/gameobject.h"
#include <chrono>
#include <ctime>

namespace _2DEngine
{
    using namespace engine;
    class Time
    {
     public:
        static float deltaTime;
        static void updateTime();

     private:
        Time();

        static std::chrono::time_point <std::chrono::_V2::system_clock> previousTime;
    };
}

#endif // TIME_H
