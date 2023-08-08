#ifndef __MAZE2D__
#define __MAZE2D__

#include <iostream>
#include <vector>

using namespace std;

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
                switch ((Maze.m_arrMaze[i][j]))
                {
                case 0: // way
                {
                    os << "o";
                    break;
                }
                case 1: // wall
                    os << "x";
                    break;
                case 2: // start
                    os << "S";
                    break;
                case 3: // goal
                    os << "G";
                    break;
                }
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
    int* getStartPosition() { return m_start; };
    int* getGoalPosition() { return m_goal; };
    int* getCurrentPosition() { return m_position; };
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
        cout << "Maze Start Point: [" << m_start[0] << "," << m_start[1] << "]" << endl;
        cout << "Maze End Point: [" << m_goal[0] << "," << m_goal[1] << "]" << endl;
        cout << "Maze Height: " << m_cols << endl;
        cout << "Maze Width: " << m_rows << endl;
    };
    void buildMaze(int arrmaze[])
    {
        cout << "Loaded Maze from Memory";
        // gets array and decompose
    };
    vector<int *> *getPossibleMoves(int *state)
    {
        vector<int *> *possibleMoves = new vector<int *>;
        int row = state[0];
        int column = state[1];
        int pos[2] = {0};
        if (m_arrMaze[row + 1][column] == 0)
        {
            pos[0] = (row + 1);
            pos[1] = (column);
            possibleMoves->push_back(pos);
        }
        if (m_arrMaze[row - 1][column] == 0)
        {
            pos[0] = (row - 1);
            pos[1] = (column);
            possibleMoves->push_back(pos);
        }
        if (m_arrMaze[row][column + 1] == 0)
        {
            pos[0] = (row);
            pos[1] = (column + 1);
            possibleMoves->push_back(pos);
        }
        if (m_arrMaze[row][column - 1] == 0)
        {
            pos[0] = (row);
            pos[1] = (column - 1);
            possibleMoves->push_back(pos);
        }

        return possibleMoves;
    }
};


#endif