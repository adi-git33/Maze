#ifndef __COMMANDS__
#define __COMMANDS__

#include "Maze2d.hpp"
#include "Demo.hpp"
#include "SimpleMaze2dGenerator.hpp"

using namespace std;

class Command{
    private:
    public:
    virtual void doCommand();
};


class runDemoCommand : public Command{
    private:
    Demo m_demo;
    public:
    void doCommand();
};

class CreateMaze : public Command{
    private:
    SimplaMaze2dGenerator m_generator;
    public:
    void doCommand();
};

class PrintMaze : public Command{
    private:
    Maze2d m_maze;
    public:
    void doCommand();
};

class GetMazeData : public Command{
    private:
    Maze2d m_maze;
    public:
    void doCommand();
};

class LoadMaze : public Command{
    private:
    Demo m_demo;
    public:
    void doCommand();
};


#endif