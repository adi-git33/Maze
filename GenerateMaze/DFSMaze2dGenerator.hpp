#ifndef __DFSMAZE2DGENERATOR__
#define __DFSMAZE2DGENERATOR__

#include "Maze2dGenerator.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class DFSMaze2dGenerator : public Maze2dGenerator
{
private:
    int m_rows;
    int m_cols;
    vector<vector<bool>> m_visited;
    vector<vector<int>> m_maze;


    void DFS(int row, int col)
    {
        vector<int> directionIndicator = {0, 1, 2, 3};
        shuffle(directionIndicator.begin(), directionIndicator.end(), std::mt19937(std::random_device()()));
        for (int i = 0; i < 4; i++)
        {
            switch(directionIndicator[i]){
                case 0: //down
                if (col -2 <= 0) continue;
                if (m_maze[row][col-2] != 0){
                    m_maze[row][col-2] =0;
                    m_visited[row][col-2] = true;
                    m_maze[row][col-1] =0;
                    m_visited[row][col-1] = true;
                    DFS(row,col-2);
                }
                break;
                case 1: //up
                if (col +2 >= m_cols) continue;
                if (m_maze[row][col+2] != 0){
                    m_maze[row][col+2] =0;
                    m_visited[row][col+2] = true;
                    m_maze[row][col+1] =0;
                    m_visited[row][col+1] = true;
                    DFS(row,col+2);
                }
                break;
                case 2: //left
                if (row -2 <= 0) continue;
                if (m_maze[row-2][col] != 0){
                    m_maze[row-2][col] =0;
                    m_visited[row-2][col] = true;
                    m_maze[row-1][col] =0;
                    m_visited[row-1][col] = true;
                    DFS(row-2,col);
                }
                break;
                case 3:
                if (row +2 >= m_rows) continue;
                if (m_maze[row+2][col] != 0){
                    m_maze[row+2][col] =0;
                    m_visited[row+2][col] = true;
                    m_maze[row+1][col] =0;
                    m_visited[row+1][col] = true;
                    DFS(row+2,col);
                }
                break;
            }
        }; 
    };

public:
    // Constractors
    DFSMaze2dGenerator(){};
    // Destractors
    ~DFSMaze2dGenerator(){};
    // Operators
    // Getters
    // Setters
    // Functions
    virtual Maze2d mazeGenerator(string name, int rows, int cols)
    {
        m_rows = rows;
        m_cols = cols;
        int startPoint[2];
        startPoint[0] = rand() % rows;
        startPoint[1] = rand() % cols;
        m_maze.resize(rows, vector<int>(cols, 1));
        m_visited.resize(rows, vector<bool>(cols, false));
        DFS(startPoint[0],startPoint[1]);

        cout << "Maze Returned" << endl;

        int goalPoint[2];
        do {
        goalPoint[0] = rand() % rows; // Random row index
        goalPoint[1] = rand() % cols; // Random column index
        } while ((goalPoint[0] == startPoint[0]) && (goalPoint[1] == startPoint[1]) && (m_visited[goalPoint[0]][goalPoint[1]] == false));

        m_maze[startPoint[0]][startPoint[1]] = 2;
        m_maze[goalPoint[0]][goalPoint[1]] = 3;

        Maze2d maze(name, startPoint, goalPoint, rows, cols, m_maze);
        cout << "Maze Generated Successfully." << endl;
        return maze;
    };
};

#endif