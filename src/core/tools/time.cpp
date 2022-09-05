#include "time.h"
#include "../engine.h"

namespace _2DEngine
{
    using namespace engine;

    float Time::deltaTime = 0;
    std::chrono::time_point <std::chrono::_V2::system_clock> Time::previousTime = std::chrono::system_clock::now();

    Time::Time()
    {
    }

    void Time::updateTime()
    {
        auto currentTime = std::chrono::system_clock::now();

        std::chrono::duration<double> delta = currentTime - previousTime;
        deltaTime = delta.count();

        previousTime = currentTime;
    }
}
