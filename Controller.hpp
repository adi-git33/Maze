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
    map<string, Maze2d> mazesArr;
    // Model *m_model;
    // View *m_view;

public:
    // Constractor
    Controller()
    {
        // Model *m_model();
        // View *m_view();
    }
    // Destractor
    ~Controller(){};
    // Operators
    // Getters
    // Setters
    // Functions
    // virtual void doCommand(){};
};

// #endif