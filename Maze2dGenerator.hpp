// #pragma once
#ifndef __MAZE2DGENERATOR__
#define __MAZE2DGENERATOR__
#include "Maze2d.hpp"

#include <chrono>

using namespace std;

class Maze2dGenerator
{
private:
public:
    // Constractors
    Maze2dGenerator() {};
    // Destractors
    virtual ~Maze2dGenerator() = 0;
    // Operators
    // Getters
    // Setters
    // Functions
    virtual Maze2d mazeGenerator() = 0;
    string measureAlgorithmTime()
    {
        chrono::time_point<chrono::system_clock> startTime = chrono::system_clock::now();
        mazeGenerator();
        chrono::time_point<chrono::system_clock>EndTime = chrono::system_clock::now();
        chrono::duration<double> timeDiff = EndTime -startTime;
        double timeMeasure = timeDiff.count();
        string result = "It took the algorithm " + to_string(timeMeasure) + " seconds";
        return result;
    };
};


#endif