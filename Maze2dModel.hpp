// #pragma once
#ifndef __MAZE2DMODEL__
#define __MAZE2DMODEL__

using namespace std;
#include "Maze2d.hpp"
#include "Player.hpp"
#include "ModelSubject.hpp"
#include "Memory/MazeCompression.hpp"
#include "Memory/Files.hpp"
#include "Search/Maze2dSearchable.hpp"
#include "Search/BFS.hpp"
#include "Search/AStar.hpp"
#include "GenerateMaze/SimpleMaze2dGenerator.hpp"
#include "GenerateMaze/DFSMaze2dGenerator.hpp"

class Maze2dModel : public ModelSubject
{
private:
    map<string, Maze2d *> m_mazes;

public:
    // Constractor
    Maze2dModel(){};
    // Destractor
    ~Maze2dModel(){};
    // Operators
    // Getters
    Maze2d *getMaze(string mazeName) { return m_mazes.find(mazeName)->second; };
    // Setters
    // Update Observers
    void modelUpdate(string result)
    {
        for (auto it = m_observers.begin(); it != m_observers.end(); ++it)
        {
            (*it)->modelUpdate(result);
        }
    }
    // Mazes vector Functions

    bool checkIfExist(string mazeName)
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
    void insertMaze(Maze2d *newMaze)
    {
        m_mazes.insert(pair<string, Maze2d *>(newMaze->getMazeName(), newMaze));
    };

    // Functions
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

    // Command Functions

    void FilePath(const vector<string> &param)
    {
        if (param.size() == 1)
        {

            Files fd;
            string r = fd.printFilesInPath(param[0]);
            modelUpdate(r);
        }
        else
        {
            string r = "invalid numbers of parameters.";
            modelUpdate(r);
        }
    }

    void generateMaze(const vector<string> &param)
    {
        string r;
        if (param.size() == 4)
        {
            if (!(Maze2dModel::checkIfExist(param[0])))
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
                                Maze2dModel::insertMaze(newMaze);
                                r = newMaze->getMazeName() + " is ready";
                            }
                            else
                            {
                                SimpleMaze2dGenerator createMaze;
                                Maze2d *newMaze = new Maze2d(createMaze.mazeGenerator(param[0], height, width));
                                Maze2dModel::insertMaze(newMaze);
                                r = newMaze->getMazeName() + " is ready";
                            }
                        }
                        else
                        {
                            r = "Height and Width must be between 2-27.";
                        }
                    }
                    else
                    {
                        r = "Height and Width must be numbers.";
                    }
                }
                else
                {
                    r = "Not a generate option.";
                }
            }
            else
            {
                r = "Maze already exists with this name.";
            }
        }
        else
        {
            r = "Invalid number of paramters.";
        }
        modelUpdate(r);
    };

    void displayMaze(const vector<string> &param)
    {
        string r;
        if (param.size() != 1)
        {
            r = "invalid numbers of parameters.";
        }
        else
        {
            if (Maze2dModel::checkIfExist(param[0]))
            {

                r = (m_mazes.find(param[0])->second->mazeToString());
            }
            else
            {
                r = "Maze doesn't exists.";
            }
        }
        modelUpdate(r);
    };

    void saveMaze(const vector<string> &param)
    {
        string r;
        if (param.size() != 2)
        {
            r = "invalid numbers of parameters";
        }
        else
        {
            if (checkIfExist(param[0]))
            {
                MazeCompression mazeFiles;
                Maze2d *saveMaze = getMaze(param[0]);
                vector<int> mazeData = saveMaze->getData();
                mazeFiles.save(mazeData, param[1]);
                r = "The maze named " + saveMaze->getMazeName() + " is saved.";
            }
            else
            {
                r = "Maze doesn't exists.";
            }
        }
        modelUpdate(r);
    };

    void loadMaze(const vector<string> &param)
    {
        string r;
        if (param.size() == 2)
        {
            if (!(checkIfExist(param[0])))
            {
                MazeCompression mazeFiles;
                vector<int> loadedArr = mazeFiles.load(param[0]);
                Maze2d *LoadedMaze = new Maze2d(loadedArr, param[1]);
                Maze2dModel::insertMaze(LoadedMaze);
                r = LoadedMaze->getMazeName() + " maze has been loaded from file: " + param[0] + ".txt.";
            }
            else
            {
                r = "Maze already exists.";
            }
        }
        else
        {
            r = "invalid numbers of parameters.";
        }
        modelUpdate(r);
    };

    void MazeObjectSize(const vector<string> &param)
    {
        string r;
        if (param.size() != 1)
        {
            r = "invalid numbers of parameters";
        }
        else
        {
            if (checkIfExist(param[0]))
            {
                Maze2d *mazeObj = Maze2dModel::getMaze(param[0]);
                int mazeObjSize = mazeObj->getMazeSize();
                string size = to_string(mazeObjSize);
                r = "The size of the maze object is " + size + " bytes.";
            }
            else
            {
                r = "Maze doesn't exists.";
            }
        }
        modelUpdate(r);
    };

    void mazeFileSize(const vector<string> &param)
    {
        string r;
        if (param.size() == 1)
        {
            Files fd;
            int size = fd.getFileSize(param[0]);
            if (size == -1)
            {
                r = "File does not exist in the current folder.";
            }
            else
            {
                string sizeStr = to_string(size);

                r = "File Size is " + sizeStr + " bytes.";
            }
        }
        modelUpdate(r);
    };

    void solveMazeManualy(const vector<string> &param)
    {
        string r;
        if (param.size() != 2)
        {
            r = "invalid numbers of parameters";
        }
        else
        {
            Maze2d *mazeObj = getMaze(param[0]);
            Player p;
            r = p.Move(mazeObj, param[1]);
        }
        modelUpdate(r);
    };

    void solveMazeAlgorithm(const vector<string> &param)
    {
        string r;
        if (param.size() != 2)
        {
            r = "invalid numbers of parameters";
        }
        else
        {
            if ((checkIfExist(param[0])))
            {
                Maze2d *mazeObj = getMaze(param[0]);
                Maze2dSearchable SearchableMaze((*mazeObj));
                if (param[1] == "BFS")
                {
                    BFS<int *> *searchBFS = new BFS<int *>();
                    Solution<int *> solvedMaze = searchBFS->search(SearchableMaze);
                    r = "Solution for " + mazeObj->getMazeName() + " is ready.";
                }
                else if (param[1] == "AStar")
                {
                    AStar<int *> *searchAStar = new AStar<int *>();
                    Solution<int *> solvedMaze = searchAStar->search(SearchableMaze);
                    r = "Solution for " + mazeObj->getMazeName() + " is ready.";
                }
                else
                {
                    r = "Not a valid Search Algorithm.";
                }
            }
            else
            {
                r = "Maze doesn't exists.";
            }
        }
        modelUpdate(r);
    };

    void displayMazeSolution(const vector<string> &param)
    {
        string r;
        if (param.size() != 1)
        {
            r = "invalid numbers of parameters";
        }
        else
        {
            if ((Maze2dModel::checkIfExist(param[0])))
            {
                r = "Displayed Solution.";
            }
            else
            {
                r = "Maze doesn't exists.";
            }
        }
        modelUpdate(r);
    };
};

#endif