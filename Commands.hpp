// #ifndef __COMMANDS__
// #define __COMMANDS__

#pragma once

#include "Maze2d.hpp"
#include "Demo.hpp"
#include "SimpleMaze2dGenerator.hpp"
// #include "Controller.hpp"

using namespace std;
//: public Controller
class Command
{
private:
public:
};

class runDemoCommand : public Command
{
private:
    Demo m_demo;

public:
    void doCommand(){};
};

class GenerateMaze : public Command
{
private:
public:
    void doCommand(){
        // int rows = 0, cols = 0;
        // cout << "Enter number of rows: " << endl
        //      << ">";
        // cin >> rows;

        // cout << "Enter number of columns: " << endl
        //      << ">";
        // cin >> cols;
        // string cmd;
        // SimplaMaze2dGenerator m_generator;
        // m_generator.mazeGenerator();
    };
};

class PrintMaze : public Command
{
private:
    Maze2d m_maze;

public:
    void doCommand();
};

class GetMazeData : public Command
{
private:
    Maze2d m_maze;

public:
    void doCommand();
};

class LoadMaze : public Command
{
private:
    Demo m_demo;

public:
    void doCommand();
};

// #endif