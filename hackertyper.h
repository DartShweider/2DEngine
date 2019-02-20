#ifndef HACKERTYPER_H
#define HACKERTYPER_H
#include <iostream>
#include <SFML/Graphics.hpp>



struct ScreenResolution
{
    int x;
    int y;

};



class HackerTyper
{
private:

    ScreenResolution Resolution;
    std::string Title;
    int Edge = 30;
    float Velocity = 0.05;

public:

    std::string AppText;
    std::string TmpText;
    HackerTyper(int ScrResX, int ScrResY, std::string title);
    void AppRun();




};

#endif // HACKERTYPER_H
