#ifndef TIME_H
#define TIME_H

#include <chrono>
#include <ctime>

namespace engine
{
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
