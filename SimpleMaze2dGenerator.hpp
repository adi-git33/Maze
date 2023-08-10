// #pragma once
#ifndef __SIMPLEMAZE2DGENERATOR__
#define __SIMPLEMAZE2DGENERATOR__
#include "Maze2d.hpp"
#include "Maze2dGenerator.hpp"

#include <iostream>
#include <string>
// #include <memory>
// #include <map>
// #include <utility>
// #include <exception>
#include <vector>
// #include <iterator>
// #include <fstream>
// #include <cstring>
#include <cstdlib>

using namespace std;

class SimplaMaze2dGenerator : public Maze2dGenerator
{
private:
public:
    // Constractors
    SimplaMaze2dGenerator(){};
    // Destractors
    ~SimplaMaze2dGenerator(){};
    // Operators
    // Getters
    // Setters
    // Functions
    virtual Maze2d mazeGenerator()
    {
        int startPoint[2];

        startPoint[0] = 0;
        startPoint[1] = 0;

        int goalPoint[2];
        goalPoint[0] = rows - 1;
        goalPoint[1] = cols - 1;

        vector<vector<int>> newMaze;
        vector<int> row;
        // creates random maze
        srand(time(nullptr));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // newMaze[i][j] = 0;
                int random = rand() % 2;
                row.push_back(random);
            }
            newMaze.push_back(row);
            row.resize(0);
        }
        newMaze[startPoint[0]][startPoint[1]] = 2;
        newMaze[goalPoint[0]][goalPoint[1]] = 3;

        Maze2d torMaze(startPoint, goalPoint, rows, cols, newMaze);
        cout << "Maze Generated Successfully." << endl;
        return torMaze;
    };
};

#endif