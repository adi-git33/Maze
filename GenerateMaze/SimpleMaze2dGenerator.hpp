#ifndef __SIMPLEMAZE2DGENERATOR__
#define __SIMPLEMAZE2DGENERATOR__
#include "Maze2dGenerator.hpp"

using namespace std;

class SimpleMaze2dGenerator : public Maze2dGenerator
{
private:
public:
    // Constractors
    SimpleMaze2dGenerator(){};
    // Destractors
    ~SimpleMaze2dGenerator(){};
    // Operators
    // Getters
    // Setters
    // Functions
    virtual Maze2d mazeGenerator(string name, int rows, int cols)
    {
        int startPoint[2];
        startPoint[0] = 0;
        startPoint[1] = 0;

        int goalPoint[2];
        goalPoint[0] = rows - 1;
        goalPoint[1] = cols - 1;

        vector<vector<int>> newMaze;
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

        newMaze[startPoint[0]][startPoint[1]] = 2;
        newMaze[goalPoint[0]][goalPoint[1]] = 3;

        Maze2d ctorMaze(name, startPoint, goalPoint, rows, cols, newMaze);
        return ctorMaze;
    };
};

#endif