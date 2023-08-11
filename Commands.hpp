// #ifndef __COMMANDS__
// #define __COMMANDS__

#pragma once

#include "Controller.hpp"
#include "Demo.hpp"
#include "SimpleMaze2dGenerator.hpp"
#include "MazeCompression.hpp"
#include "BFS.hpp"
#include "AStar.hpp"

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
    void doCommand(const vector<string> &param){};
};

class GenerateMaze : public Command
{
private:
public:
    void doCommand(const vector<string> &param)
    {
        // string name;
        // cout << "Enter maze name: " << endl
        //      << ">";
        // cin >> name;

        // int rows = 0, cols = 0;
        // do
        // {
        //     cout << "Enter Height: " << endl
        //          << ">";
        //     cin >> rows;
        //     if (rows <= 0)
        //     {
        //         cout << "Invalid height number." << endl;
        //     }
        // } while (rows <= 0);

        // do
        // {
        //     cout << "Enter Width: " << endl
        //          << ">";
        //     cin >> cols;
        //     if (cols <= 0)
        //     {
        //         cout << "Invalid width number." << endl;
        //     }
        // } while (cols <= 0);
        if (param.size() == 3)
        {
            if (!(Controller::checkIfExist(param[0])))
            {
                SimplaMaze2dGenerator createMaze;
                Maze2d *newMaze = new Maze2d(createMaze.mazeGenerator(param[0], stoi(param[1]), stoi(param[2])));
                Controller::insertMaze(newMaze);
                cout << "Maze " << newMaze->getMazeName() << " is ready" << endl;
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
            // cout << "Mazes size: " << existMaze(param[0]).size() << endl;

            // for (auto it = Controller::mazesArr.cbegin(); it != Controller::mazesArr.cend(); ++it)
            // {
            //     std::cout << "{" << (*it).first << ": " << (*it).second->getMazeName() << "}\n";
            // }

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
            // cout << "Mazes size: " << Controller::mazesArr.size() << endl;
            // for (auto it = Controller::mazesArr.cbegin(); it != Controller::mazesArr.cend(); ++it)
            // {
            //     std::cout << "{" << (*it).first << ": " << (*it).second->getMazeName() << "}\n";
            // }

            if (Controller::checkIfExist(param[0]))
            {
                MazeCompression mazeFiles;
                Maze2d *saveMaze = Controller::getMaze(param[0]);
                vector<int> mazeData = saveMaze->getData();
                mazeFiles.save(mazeData, saveMaze->getMazeName());
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
                double mazeObjFile = sizeof(mazeObj);
                cout << "The size of the maze object is: " << mazeObjFile << endl;
            }
            else
            {
                cout << "Maze doesn't exists." << endl;
            }
        }
    };
};
// class MazeFileSize : public Command
// {
// private:
// public:
//     void doCommand(const vector<string> &param)
//     {
//         if (param.size() == 1)
//         {
//             Maze2d mazeObj = mazesArr.find(param[0])->second;
//             string mazeFileName = mazeObj.getMazeName() + ".txt";
//             string directoryPath = ".";
//         try {
//             for (const auto& entry : fs::directory_iterator(directoryPath)) {
//             if (fs::is_regular_file(entry) && entry.path().filename() == mazeFileName) {
//                 std::cout << "File: " << entry.path().filename() << " | Size: " << fs::file_size(entry) << " bytes" << std::endl;
//                 return 0; // Exit after finding the first occurrence
//             }
//         }

//         }
//         else
//         {
//             cout << "invalid numbers of parameters." << endl;
//         }
//     };
//};

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
                string algName = param[1];
                Maze2dSearchable Searchie((*mazeObj));
                if (algName == "BFS")
                {
                    BFS<int *> *searchBFS = new BFS<int *>();
                    Solution<int *> soluchie = searchBFS->search(Searchie);
                }
                if (algName == "AStar")
                {
                    AStar<int *> *searchAStar = new AStar<int *>();
                    Solution<int *> soluchie = searchAStar->search(Searchie);
                }
            }
        }
    };
};

class DisplayMazeSolution : public Command
{
private:
public:
    void doCommand(const vector<string> &param){};
};

// run demo
// play
// measure creation maze time

// #endif