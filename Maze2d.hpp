// ----- Code by: Moran Sinai ID: 206402281 and Adi Levi ID: 316116052

#pragma once
#include "Memory.hpp"

using namespace std;

class Maze2d
{
private:
    int m_mazeID;
    pair<int, int> m_start;
    pair<int, int> m_goal;
    pair<int, int> m_position;
    int m_rows;
    int m_cols;
    int *m_arrMaze; // int m_salary;

public:
    // Constractor
    Maze2d(){};
    // maze2d(int newIDLen, string newId, int newSalary, int newSenior) : m_IDLen(newIDLen), m_id(newId), m_salary(newSalary), m_seniority(newSenior){};
    // Destractor
    ~Maze2d(){};
    // Operators
    friend ostream &operator<<(ostream &os, pair<int, int> const &output)
    {
        // prints pair
    }
    friend ostream &operator<<(ostream &os, int const &m_arrMaze)
    {
        // prints maze
    }
    // Getters
    pair<int, int> getStartPosition() { return m_start; };
    pair<int, int> getGoalPosition() { return m_goal; };
    pair<int, int> getCurrentPosition() { return m_position; };
    // Setters
    void setPosition(pair<int, int> newPos) { m_position = newPos; };
    // Functions
    void getData()
    {
        // info of the maze
        // enterance
        // goal
        // rows and cols
    }
    void buildMaze(int arrmaze[])
    {
        // gets array and decompose
    }
};

void save(vector<Maze2d> &EmployeeVec);
vector<Maze2d> load(vector<Maze2d> newVec);

// class EightPuzzel
// {
// public:
// 	EightPuzzel() {};
// 	~EightPuzzel() {};

// public:
// 	//All the methods for the game
// 	std::string getStart() { return m_startPos; }
// 	std::string getEnd() { return m_endPos; }
// 	std::vector<string> getPossibleMoves(string& state)
// 	{
// 		std::vector<string>* vec = new vector<string>();
// 		return *vec;
// 		//get possible moves...
// 	}

// private:
// 	int m_board[3][3];
// 	std::string m_startPos;
// 	std::string m_endPos;
// };
