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

template<class T1, class T2>
class Maze2d
{
private:
    int m_mazeID;
    pair<T1, T2> m_start;
    pair<T1, T2> m_goal;
    pair<T1, T2> m_position;
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
    friend ostream &operator<<(ostream &os, pair<T1, T2> const &output)
    {
        // prints pair
    }
    friend ostream &operator<<(ostream &os, int const &m_arrMaze)
    {
        // prints maze
    }
    // Getters
    pair<T1, T2> getStartPosition() { return m_start; };
    pair<T1, T2> getGoalPosition() { return m_goal; };
    pair<T1, T2> getCurrentPosition() { return m_position; };
    // Setters
    void setPosition(pair<T1, T2> newPos) { m_position = newPos; };
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

// void save(vector<Maze2d> &EmployeeVec);
// vector<Maze2d> load(vector<Maze2d> newVec);

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
