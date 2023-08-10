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
        string name;
        cout << "Enter maze name: " << endl
             << ">";
        cin >> name;

        int rows = 0, cols = 0;
        do
        {
            cout << "Enter number of rows: " << endl
                 << ">";
            cin >> rows;
        } while (rows <= 0);

        do
        {
            cout << "Enter number of columns: " << endl
                 << ">";
            cin >> cols;
        } while (cols <= 0);

        int startPoint[2];
        startPoint[0] = 0;
        startPoint[1] = 0;

        int goalPoint[2];
        goalPoint[0] = rows - 1;
        goalPoint[1] = cols - 1;

        vector<vector<int>> newMaze;
        // creates random maze
        srand(time(nullptr));
        vector<int> row;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int random = rand() % 2;
                row.push_back(random);
            }
            newMaze.push_back(row);
            row.resize(0);
        }

        // vector<int> row;
        // // creates random maze
        // for (int i = 0; i < m_rows; i++)
        // {
        //     for (int j = 0; j < m_cols; j++)
        //     {
        //         row.push_back(mazeInVector.at(index));
        //         index++;
        //     }
        //     m_arrMaze.push_back(row);
        //     row.resize(0);
        // }
        newMaze[startPoint[0]][startPoint[1]] = 2;
        newMaze[goalPoint[0]][goalPoint[1]] = 3;

        Maze2d ctorMaze(name, startPoint, goalPoint, rows, cols, newMaze);
        cout << "Maze Generated Successfully." << endl;
        return ctorMaze;
    };
};

#endif