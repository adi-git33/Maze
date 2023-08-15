#ifndef __COMMANDS__
#define __COMMANDS__

#include "../Maze2dModel.hpp"
#include <string>
#include <vector>

using namespace std;
//
class Command
{
private:
public:
    virtual void doCommand(const vector<string> &param, Maze2dModel *model) = 0;
};

class FilePath : public Command
{
private:
public:
    void doCommand(const vector<string> &param, Maze2dModel *model)
    {
        model->FilePath(param);
    };
};

class GenerateMaze : public Command
{
private:
public:
    void doCommand(const vector<string> &param, Maze2dModel *model)
    {
        model->generateMaze(param);
    }
};

class DisplayMaze : public Command
{
private:
public:
    void doCommand(const vector<string> &param, Maze2dModel *model)
    {
        model->displayMaze(param);
    };
};

class SaveMaze : public Command
{
private:
public:
    void doCommand(const vector<string> &param, Maze2dModel *model)
    {
        model->saveMaze(param);
    };
};

class LoadMaze : public Command
{
private:
public:
    void doCommand(const vector<string> &param, Maze2dModel *model)
    {
        model->loadMaze(param);
    };
};

class MazeObjSize : public Command
{
private:
public:
    void doCommand(const vector<string> &param, Maze2dModel *model)
    {
        model->MazeObjectSize(param);
    };
};
class MazeFileSize : public Command
{
private:
public:
    void doCommand(const vector<string> &param, Maze2dModel *model)
    {
        model->mazeFileSize(param);
    };
};

class SolveMazeManualy : public Command
{
private:
public:
    void doCommand(const vector<string> &param, Maze2dModel *model)
    {
        model->solveMazeManualy(param);
    };
};

class SolveMazeAlgorithm : public Command
{
private:
public:
    void doCommand(const vector<string> &param, Maze2dModel *model)
    {
        model->solveMazeAlgorithm(param);
    };
};

class DisplayMazeSolution : public Command
{
private:
public:
    void doCommand(const vector<string> &param, Maze2dModel *model)
    {
        model->displayMazeSolution(param);
    };
};

#endif