#include "fstream.h"

void ReadFile(std::string filename, HackerTyper* hackertyper)
{
    std::ifstream DATABASE(filename);
    while (!DATABASE.eof()) {std::string str; std::getline(DATABASE, str); hackertyper->AppText += str; hackertyper->AppText += "\n";}

}
