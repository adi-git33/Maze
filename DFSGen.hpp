#pragma once
#include "Maze2d.hpp"
#include "Maze2dGenerator.hpp"
#include <iostream>
#include <vector>
// #include <stack>
// #include <cstdlib>
// #include <ctime>
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

    bool isValid(int row, int col)
    {
        return row >= 0 && row < m_rows && col >= 0 && col < m_cols && !m_visited[row][col];
    };

    vector<vector<int>> DFS(int row, int col)
    {
        m_visited[row][col] = true;
        m_maze[row][col] = 1;
        int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        vector<int> directionIndicator = {0, 1, 2, 3};
        shuffle(directionIndicator.begin(), directionIndicator.end(), std::mt19937(std::random_device()()));
        for (int i = 0; i < 4; i++)
        {
            int dir = directionIndicator[i];
            int newRow = row + directions[dir][0];
            int newCol = col + directions[dir][1];

            if (isValid(newRow, newCol))
            {
                m_maze[row + directions[dir][0] / 2][col + directions[dir][1] / 2] = 0;
                DFS(newRow, newCol);
            };
        }
        return m_maze;
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
        m_maze.resize(rows, vector<int>(cols));

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                m_maze[i][j] = 1;
            }
        }

        m_visited.resize(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                m_visited[i][j] = false;
            }
        }
        vector<vector<int>> newMaze = DFS(rows, cols);

        int startPoint[2];
        startPoint[0] = 0;
        startPoint[1] = 0;

        int goalPoint[2];
        goalPoint[0] = rows - 1;
        goalPoint[1] = cols - 1;

        newMaze[startPoint[0]][startPoint[1]] = 2;
        newMaze[goalPoint[0]][goalPoint[1]] = 3;

        Maze2d maze(name, startPoint, goalPoint, rows, cols, newMaze);
        cout << "Maze Generated Successfully." << endl;
        return maze;
    };
};