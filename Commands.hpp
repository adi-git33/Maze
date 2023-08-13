// #ifndef __COMMANDS__
// #define __COMMANDS__

#pragma once

#include "Controller.hpp"
#include "Demo.hpp"
#include "SimpleMaze2dGenerator.hpp"
#include "MazeCompression.hpp"
#include "BFS.hpp"
#include "AStar.hpp"
#include "Files.hpp"
#include "DFSGen.hpp"

bool isNum(string check)
{
    for (int i = 0; i < check.size(); i++)
    {
        if (!isdigit(check[i]))
        {
            return false;
        }
    }
    return true;
};

using namespace std;
//
class Command
{
private:
public:
    virtual void doCommand(const vector<string> &param){};
};

class FilePath : public Command
{
private:
public:
    void doCommand(const vector<string> &param)
    {
        if (param.size() == 1)
        {
            Files fd;
            fd.printFilesInPath(param[0]);
        }
        else
        {
            cout << "invalid numbers of parameters." << endl;
        }
    };
};

class GenerateMaze : public Command
{
private:
public:
    void doCommand(const vector<string> &param)
    {
        if (param.size() == 4)
        {
            if (!(Controller::checkIfExist(param[0])))
            {
                if (param[3] == "DFS" || param[3] == "Simple")
                {
                    if (isNum(param[1]) && isNum(param[2]))
                    {
                        int height = stoi(param[1]);
                        int width = stoi(param[2]);
                        if ((height >= 2 && height <= 27) && (width >= 2 && width <= 27))
                        {
                            if (param[3] == "DFS")
                            {
                                DFSMaze2dGenerator createMaze;
                                Maze2d *newMaze = new Maze2d(createMaze.mazeGenerator(param[0], height, width));
                                Controller::insertMaze(newMaze);
                                cout << "Maze " << newMaze->getMazeName() << " is ready" << endl;
                            }
                            else
                            {
                                SimpleMaze2dGenerator createMaze;
                                Maze2d *newMaze = new Maze2d(createMaze.mazeGenerator(param[0], height, width));
                                Controller::insertMaze(newMaze);
                                cout << "Maze " << newMaze->getMazeName() << " is ready" << endl;
                            }
                        }
                        else
                        {
                            cout << "Height and Width must be between 2-27." << endl;
                        }
                    }
                    else
                    {
                        cout << "Height and Width must be numbers." << endl;
                    }
                }
                else
                {
                    cout << "Not a generate option." << endl;
                }
            }
            else
            {
                cout << "Maze already exists with this name." << endl;
            }
        }
        else
        {
            cout << "Invalid number of paramters." << endl;
        }
    };
};

class DisplayMaze : public Command
{
private:
public:
    void doCommand(const vector<string> &param)
    {
        if (param.size() != 1)
        {
            cout << "invalid numbers of parameters." << endl;
        }
        else
        {
            if (Controller::checkIfExist(param[0]))
            {
                Controller::displayMaze(param[0]);
            }
            else
            {
                cout << "Maze doesn't exists." << endl;
            }
        }
    };
};

class SaveMaze : public Command
{
private:
public:
    void doCommand(const vector<string> &param)
    {
        if (param.size() != 2)
        {
            cout << "invalid numbers of parameters" << endl;
        }
        else
        {
            if (Controller::checkIfExist(param[0]))
            {
                MazeCompression mazeFiles;
                Maze2d *saveMaze = Controller::getMaze(param[0]);
                vector<int> mazeData = saveMaze->getData();
                mazeFiles.save(mazeData, param[1]);
                cout << "The maze named " << saveMaze->getMazeName() << " is saved." << endl;
            }
            else
            {
                cout << "Maze doesn't exists." << endl;
            }
        }
    };
};

class LoadMaze : public Command
{
private:
public:
    void doCommand(const vector<string> &param)
    {
        if (param.size() == 2)
        {
            if (!(Controller::checkIfExist(param[0])))
            {
                MazeCompression mazeFiles;
                vector<int> loadedArr = mazeFiles.load(param[0]);
                Maze2d *LoadedMaze = new Maze2d(loadedArr, param[1]);
                Controller::insertMaze(LoadedMaze);
                cout << LoadedMaze->getMazeName() << " maze has been loaded from file: " << param[0] << "." << endl;
            }
            else
            {
                cout << "Maze already exists." << endl;
            }
        }
        else
        {
            cout << "invalid numbers of parameters." << endl;
        }
    };
};

class MazeObjSize : public Command
{
private:
public:
    void doCommand(const vector<string> &param)
    {
        if (param.size() != 1)
        {
            cout << "invalid numbers of parameters" << endl;
        }
        else
        {
            if (Controller::checkIfExist(param[0]))
            {
                Maze2d *mazeObj = Controller::getMaze(param[0]);
                double mazeObjFile = sizeof((*mazeObj));
                cout << "The size of the maze object is " << mazeObjFile << " bytes." << endl;
            }
            else
            {
                cout << "Maze doesn't exists." << endl;
            }
        }
    };
};
class MazeFileSize : public Command
{
private:
public:
    void doCommand(const vector<string> &param)
    {
        if (param.size() == 1)
        {
            Files fd;
            int size = fd.getFileSize(param[0]);
            if (size == -1)
            {
                cout << "File does not exist in the current folder." << endl;
            }
            else
            {
                cout << "File Size is " << size << " bytes." << endl;
            }
        }
    };
};

class SolveMaze : public Command
{
private:
public:
    void doCommand(const vector<string> &param)
    {
        if (param.size() != 2)
        {
            cout << "invalid numbers of parameters" << endl;
        }
        else
        {
            if ((Controller::checkIfExist(param[0])))
            {
                Maze2d *mazeObj = Controller::getMaze(param[0]);
                if (param[1] == "Manualy")
                {
                    Player p;
                    p.Move(mazeObj);
                }
                else if (param[1] == "Algorithm")
                {
                    string algName = param[1];
                    Maze2dSearchable Searchie((*mazeObj));
                    if (algName == "BFS")
                    {
                        BFS<int *> *searchBFS = new BFS<int *>();
                        Solution<int *> soluchie = searchBFS->search(Searchie);
                    }
                    else if (algName == "AStar")
                    {
                        AStar<int *> *searchAStar = new AStar<int *>();
                        Solution<int *> soluchie = searchAStar->search(Searchie);
                    }
                    else
                    {
                        cout << "Not a valid Search Algorithm." << endl;
                    }
                }
                else
                {
                    cout << "Not a valid option" << endl;
                }
            }
            else
            {
                cout << "Maze doesn't exists." << endl;
            }
        }
    };
};

class DisplayMazeSolution : public Command
{
private:
public:
    void doCommand(const vector<string> &param)
    {
        if (param.size() != 1)
        {
            cout << "invalid numbers of parameters" << endl;
        }
        else
        {
            if ((Controller::checkIfExist(param[0])))
            {
                cout << "Display Solution." << endl;
            }
            else
            {
                cout << "Maze doesn't exists." << endl;
            }
        }
    };
};
// run demo
// play
// measure creation maze time

// #endif