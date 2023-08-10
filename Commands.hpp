// #ifndef __COMMANDS__
// #define __COMMANDS__

#pragma once

#include "Maze2d.hpp"
#include "Demo.hpp"
#include "SimpleMaze2dGenerator.hpp"
#include "Controller.hpp"
#include "MazeCompression.hpp"
#include "BFS.hpp"
#include "AStar.hpp"

using namespace std;
//
class Command : public Controller
{
private:
public:
    void doCommand(const vector<string> &param){};
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
        string name;
        cout << "Enter maze name: " << endl
             << ">";
        cin >> name;

        int rows = 0, cols = 0;
        do
        {
            cout << "Enter Height: " << endl
                 << ">";
            cin >> rows;
            if (rows <= 0)
            {
                cout << "Invalid height number." << endl;
            }
        } while (rows <= 0);

        do
        {
            cout << "Enter Width: " << endl
                 << ">";
            cin >> cols;
            if (cols <= 0)
            {
                cout << "Invalid width number." << endl;
            }
        } while (cols <= 0);

        if (param.size() == 3)
        {

            SimplaMaze2dGenerator createMaze;
            Maze2d newMaze = createMaze.mazeGenerator(param[0], stoi(param[1]), stoi(param[2]));
            mazesArr.insert(pair<string, Maze2d>(newMaze.getMazeName(), newMaze));
            cout << "Maze" << newMaze.getMazeName() << "is ready" << endl;
        }
        else
        {
            cout << "Invalid number of paramters." << endl;
        }
        // string cmd;
        // SimplaMaze2dGenerator m_generator;
        // m_generator.mazeGenerator();
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
            Maze2d printedMaze = mazesArr.find(param[0])->second;
            cout << printedMaze;
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
            MazeCompression mazeFiles;
            Maze2d saveMaze = mazesArr.find(param[0])->second;
            vector<int> mazeData = saveMaze.getData();
            mazeFiles.save(mazeData, saveMaze.getMazeName());
            cout << "The maze named " << saveMaze.getMazeName() << " is saved." << endl;
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
            if (mazesArr.find(param[0]) != mazesArr.end())
            {
                MazeCompression mazeFiles;
                vector<int> loadedArr = mazeFiles.load(param[0]);
                Maze2d LoadedMaze(loadedArr, param[1]);
                mazesArr.insert(pair<string, Maze2d>(LoadedMaze.getMazeName(), LoadedMaze));
                cout << LoadedMaze.getMazeName() << "maze has been loaded from file" << param[0] << "." << endl;
            }
            else
            {
                cout << "invalid numbers of parameters." << endl;
            }
        }
        else
        {
            cout << "Maze already exists." << endl;
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
            Maze2d mazeObj = mazesArr.find(param[0])->second;
            double mazeObjFile = sizeof(mazeObj);
            cout << "The size of the maze object is: " << mazeObjFile << endl;
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
            Maze2d mazeObj = mazesArr.find(param[0])->second;
            string mazeFileName = mazeObj.getMazeName() + ".txt";
            string directoryPath = ".";
        try {
            for (const auto& entry : fs::directory_iterator(directoryPath)) {
            if (fs::is_regular_file(entry) && entry.path().filename() == mazeFileName) {
                std::cout << "File: " << entry.path().filename() << " | Size: " << fs::file_size(entry) << " bytes" << std::endl;
                return 0; // Exit after finding the first occurrence
            }
        }

        }
        else
        {
            cout << "invalid numbers of parameters." << endl;
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
            Maze2d mazeObj = mazesArr.find(param[0])->second;
            string algName = param[1];
            Maze2dSearchable Searchie(mazeObj);
            if (algName == "BFS"){
            BFS<int *> *searchBFS = new BFS<int *>();
            Solution<int *> soluchie = searchBFS->search(Searchie);
            }
            if (algName == "AStar"){
            AStar<int *> *searchAStar = new AStar<int *>();
            Solution<int *> soluchie = searchAStar->search(Searchie);
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