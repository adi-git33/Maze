// ----- Code by: Moran Sinai ID: 206402281 and Adi Levi ID: 316116052

#pragma once

#include "Memory.hpp"

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

// template<class T1, class T2>
class Maze2d
{
private:
    int m_mazeID;
    int m_start[2];
    int m_goal[2];
    int m_position[2];
    int m_rows;
    int m_cols;
    vector<vector<int>> m_arrMaze;

public:
    // Constractor
    Maze2d(int *newStart, int *newGoal, int newRows, int newCols, vector<vector<int>> mazeArr)
    {
        static int mazeCount = 1;
        m_mazeID = mazeCount;
        m_rows = newRows;
        m_cols = newCols;

        for (int i = 0; i < 2; i++)
            m_start[i] = newStart[i];

        for (int i = 0; i < 2; i++)
            m_goal[i] = newGoal[i];

        for (int i = 0; i < 2; i++)
            m_position[i] = m_start[i];

        m_arrMaze = mazeArr;

        mazeCount++;
    };

    Maze2d(Maze2d const &copyMaze)
    {
        m_mazeID = copyMaze.m_mazeID;
        m_rows = copyMaze.m_rows;
        m_cols = copyMaze.m_cols;

        for (int i = 0; i < 2; i++)
            m_start[i] = copyMaze.m_start[i];

        for (int i = 0; i < 2; i++)
            m_goal[i] = copyMaze.m_goal[i];

        for (int i = 0; i < 2; i++)
            m_position[i] = copyMaze.m_position[i];

        m_arrMaze = copyMaze.m_arrMaze;
    };
    // Destractor
    ~Maze2d(){};
    // Operators
    friend ostream &operator<<(ostream &os, int const *output)
    {
        os << output[0] << "," << output[1] << endl;
        return os;
    }

    friend ostream &operator<<(ostream &os, Maze2d const &Maze)
    {
        for (int i = 0; i < Maze.m_arrMaze.size(); i++)
        {
            for (int j = 0; j < Maze.m_arrMaze[i].size(); j++)
            {
                os << Maze.m_arrMaze[i][j] << " ";
            }
            os << endl;
        }
        return os;
    };

    Maze2d &operator=(const Maze2d &assignMaze)
    {
        this->m_mazeID = assignMaze.m_mazeID;
        this->m_rows = assignMaze.m_rows;
        this->m_cols = assignMaze.m_cols;

        for (int i = 0; i < 2; i++)
            this->m_start[i] = assignMaze.m_start[i];

        for (int i = 0; i < 2; i++)
            this->m_goal[i] = assignMaze.m_goal[i];

        for (int i = 0; i < 2; i++)
            this->m_position[i] = assignMaze.m_position[i];

        this->m_arrMaze = assignMaze.m_arrMaze;

        return *this;
    };
    // Getters
    int getStartPosition() { return *m_start; };
    int getGoalPosition() { return *m_goal; };
    int getCurrentPosition() { return *m_position; };
    // Setters
    void setPosition(int *newPos)
    {
        m_position[0] = newPos[0];
        m_position[1] = newPos[1];
    };
    // Functions
    void getData()
    {
        cout << "Maze Info" << endl;
        cout << "Maze id: " << m_mazeID << endl;
        cout << "Maze Start Point: [" << m_start[0] << "," << m_start[1] << endl;
        cout << "Maze End Point: [" << m_goal[0] << "," << m_goal[1] << endl;
        cout << "Maze Height: " << m_cols << endl;
        cout << "Maze Width: " << m_rows << endl;
    };
    void buildMaze(int arrmaze[])
    {
        cout << "Loaded Maze from Memory";
        // gets array and decompose
    };
};
