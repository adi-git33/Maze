#pragma once
#include "Maze2d.hpp"
#include "Maze2dGenerator.hpp"

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

using namespace std;


class SimplaMaze2dGenerator : public Maze2dGenerator
{
private:
public:
    // Constractors
    SimplaMaze2dGenerator();
    // Destractors
    ~SimplaMaze2dGenerator();
    // Operators
    // Getters
    // Setters
    // Functions
    virtual Maze2d mazeGenerator()
    {
        int rows = 0, cols = 0;
        cout << "Enter number of rows: " << endl
             << ">";
        cin >> rows;

        cout << "Enter number of columns: " << endl
             << ">";
        cin >> cols;

        int startPoint[2];

        for (int i = 0; i < 2; i++)
            startPoint[i] = 0;

        int goalPoint[2];
        goalPoint[0] = (rows - 1);
        goalPoint[1] = (cols - 1);

    vector<vector<int>> newMaze;

        // creates random maze
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                newMaze[i][j] = 0;
            }
        }

        Maze2d torMaze(startPoint, goalPoint, rows, cols, newMaze);
        cout << "Maze Generated Successfully." << endl;
        return torMaze;
    };
};