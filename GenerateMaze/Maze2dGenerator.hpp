// ----- Code by: Moran Sinai ID: 206402281 and Adi Levi ID: 316116052

#ifndef __MAZE2DGENERATOR__
#define __MAZE2DGENERATOR__

#include "../Maze2d.hpp"

#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Maze2dGenerator
{
private:
public:
    // Constractors
    Maze2dGenerator(){};
    // Destractors
    virtual ~Maze2dGenerator(){};
    // Operators
    // Getters
    // Setters
    // Functions
    virtual Maze2d mazeGenerator(string name, int rows, int cols) = 0;
    string measureAlgorithmTime(string name, int rows, int cols)
    {
        chrono::time_point<chrono::system_clock> startTime = chrono::system_clock::now();
        mazeGenerator(name, rows, cols);
        chrono::time_point<chrono::system_clock> EndTime = chrono::system_clock::now();
        chrono::duration<double> timeDiff = EndTime - startTime;
        double timeMeasure = timeDiff.count();
        string result = "It took the algorithm " + to_string(timeMeasure) + " seconds";
        return result;
    };
};

#endif