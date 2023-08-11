// #ifndef __CONTROLLER__
// #define __CONTROLLER__
#pragma once

#include <map>
#include "Maze2d.hpp"
// #include "Model.hpp"
// #include "View.hpp"

using namespace std;

class Controller
{
protected:
    static map<string, Maze2d *> m_mazes;
    // Model *m_model;
    // View *m_view;

public:
    // Constractor
    Controller(){};
    // Destractor
    ~Controller(){};
    // Operators
    // Getters
    static std::map<std::string, Maze2d *>::iterator getEndMazes() { return m_mazes.end(); };
    static int getMazesSize() { return m_mazes.size(); };
    static Maze2d *getMaze(string mazeName) { return m_mazes.find(mazeName)->second; };
    // Setters
    // Functions
    static bool checkIfExist(string mazeName)
    {
        if (m_mazes.find(mazeName) == m_mazes.end())
        {
            return false;
        }
        else
        {
            return true;
        }
    };
    static void insertMaze(Maze2d *newMaze)
    {
        Controller::m_mazes.insert(pair<string, Maze2d *>(newMaze->getMazeName(), newMaze));
    }
    static void displayMaze(string mazeName)
    {
        cout << *(m_mazes.find(mazeName)->second) << endl;
    }
};
map<string, Maze2d *> Controller::m_mazes;

// #endif