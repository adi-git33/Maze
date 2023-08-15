#ifndef __MAZE2D__
#define __MAZE2D__

#include <iostream>
#include <vector>

using namespace std;

class Maze2d
{
private:
    int m_id;
    string m_mazeName;
    int m_start[2];
    int m_goal[2];
    int m_position[2];
    int m_rows;
    int m_cols;
    vector<vector<int>> m_arrMaze;

public:
    // Constractor
    Maze2d(string name, int *newStart, int *newGoal, int newRows, int newCols, vector<vector<int>> mazeArr)
    {
        int static count = 1;
        m_id = count;
        m_mazeName = name;
        m_rows = newRows;
        m_cols = newCols;

        for (int i = 0; i < 2; i++)
            m_start[i] = newStart[i];

        for (int i = 0; i < 2; i++)
            m_goal[i] = newGoal[i];

        for (int i = 0; i < 2; i++)
            m_position[i] = m_start[i];

        m_arrMaze = mazeArr;
        count++;
    };
    Maze2d(Maze2d const &copyMaze)
    {
        m_id = copyMaze.m_id;
        m_mazeName = copyMaze.m_mazeName;
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
    Maze2d(vector<int> &mazeInVector, string mazeName)
    {
        m_mazeName = mazeName;

        m_id = mazeInVector.at(0);
        m_rows = mazeInVector.at(1);
        m_cols = mazeInVector.at(2);
        m_start[0] = mazeInVector.at(3);
        m_start[1] = mazeInVector.at(4);
        m_goal[0] = mazeInVector.at(5);
        m_goal[1] = mazeInVector.at(6);
        m_position[0] = m_start[0];
        m_position[1] = m_start[1];

        int index = 7;
        vector<int> row;
        for (int i = 0; i < m_rows; i++)
        {
            for (int j = 0; j < m_cols; j++)
            {
                row.push_back(mazeInVector.at(index));
                index++;
            }
            m_arrMaze.push_back(row);
            row.resize(0);
        }
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

        for (int i = 0; i < Maze.m_arrMaze[0].size() + 2; i++)
        {
            os << "#";
        }
        os << endl;

        for (int i = 0; i < Maze.m_arrMaze.size(); i++)
        {
            os << "#";
            for (int j = 0; j < Maze.m_arrMaze[i].size(); j++)
            {
                switch ((Maze.m_arrMaze[i][j]))
                {
                case 0: // way
                {
                    os << " ";
                    break;
                }
                case 1: // wall
                    os << "#";
                    break;
                case 2: // start
                    os << "S";
                    break;
                case 3: // goal
                    os << "G";
                    break;
                case 4: // Player
                    os << "P";
                    break;
                case 5: // solved path
                    os << "O";
                    break;
                }
            }
            os << "#";
            os << endl;
        }
        for (int i = 0; i < Maze.m_arrMaze[0].size() + 2; i++)
        {
            os << "#";
        }
        os << endl;
        return os;
    };

    Maze2d &operator=(const Maze2d &assignMaze)
    {
        this->m_mazeName = assignMaze.m_mazeName;
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
    int *getStartPosition() { return m_start; };
    int *getGoalPosition() { return m_goal; };
    int *getCurrentPosition() { return m_position; };
    int getPositionInfo(int row, int col) { return m_arrMaze[row][col]; };
    int getRow() { return m_rows; };
    int getColumn() { return m_cols; };
    string getMazeName() { return m_mazeName; };
    int getMazeSize()
    {
        int sumSize = 0;
        sumSize += sizeof(m_id);
        sumSize += m_mazeName.size();
        sumSize += sizeof(m_start[0]);
        sumSize += sizeof(m_start[1]);
        sumSize += sizeof(m_goal[0]);
        sumSize += sizeof(m_goal[1]);
        sumSize += sizeof(m_position[0]);
        sumSize += sizeof(m_position[1]);
        sumSize += sizeof(m_rows);
        sumSize += sizeof(m_cols);
        for (const auto &innerVector : m_arrMaze)
        {
            sumSize += sizeof(innerVector);
            sumSize += innerVector.size() * sizeof(int);
        }
        return sumSize;
    };
    // Setters
    void setPosition(int *newPos)
    {
        if (m_arrMaze[m_position[0]][m_position[1]] != 3 && m_arrMaze[m_position[0]][m_position[1]] != 2)
        {
            m_arrMaze[m_position[0]][m_position[1]] = 0;
        }
        m_position[0] = newPos[0];
        m_position[1] = newPos[1];
        if (m_arrMaze[m_position[0]][m_position[1]] != 3 && m_arrMaze[m_position[0]][m_position[1]] != 2)
        {
            m_arrMaze[m_position[0]][m_position[1]] = 4;
        }
    };

    // Functions
    vector<int> getData()
    {
        vector<int> mazeData;
        mazeData = {m_id, m_rows, m_cols, m_start[0], m_start[1], m_goal[0], m_goal[1]};

        for (const auto &row : m_arrMaze)
        {
            mazeData.insert(mazeData.end(), row.begin(), row.end());
        }
        return mazeData;
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
    };

    string mazeToString()
    {
        string m;
        for (int i = 0; i < m_arrMaze[0].size() + 2; i++)
        {
            m += "#";
        }
        m += "\n";

        for (int i = 0; i < m_arrMaze.size(); i++)
        {
            m += "#";
            for (int j = 0; j < m_arrMaze[i].size(); j++)
            {
                switch ((m_arrMaze[i][j]))
                {
                case 0: // way
                {
                    m += " ";
                    break;
                }
                case 1: // wall
                    m += "#";
                    break;
                case 2: // start
                    m += "S";
                    break;
                case 3: // goal
                    m += "G";
                    break;
                case 4: // Player
                    m += "P";
                    break;
                case 5: // solved path
                    m += "O";
                    break;
                }
            }
            m += "#";
            m += "\n";
        }
        for (int i = 0; i < m_arrMaze[0].size() + 2; i++)
        {
            m += "#";
        }
        m += "\n";
        return m;
    }
};

#endif