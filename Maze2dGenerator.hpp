#pragma once
#include "Maze2d.hpp"
#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <utility>
#include <exception>
#include <vector>
#include <iterator>
#include <fstream>
#include <cstring>
#include <chrono>

using namespace std;

class Maze2dGenerator
{
private:
public:
    // Constractors
    Maze2dGenerator();
    // Destractors
    virtual ~Maze2dGenerator() = 0;
    // Operators
    // Getters
    // Setters
    // Functions
    virtual Maze2d mazeGenerator();
    virtual string measureAlgorithmTime()
    {
        chrono::time_point<chrono::system_clock> startTime = chrono::system_clock::now();
        mazeGenerator();
        chrono::time_point<chrono::system_clock>EndTime = chrono::system_clock::now();
        chrono::duration<double> timeDiff = startTime - EndTime;
        double timeMeasure = timeDiff.count();
        string result = "It took the algorithm " + to_string(timeMeasure) + " seconds";
        return result;
    };
};


