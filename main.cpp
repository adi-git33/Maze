#include "SimpleMaze2dGenerator.hpp"
#include "BFS.hpp"
#include "AStar.hpp"
#include "Maze2dSearchable.hpp"
#include "Demo.hpp"
#include "Player.hpp"
#include "MazeCompression.hpp"
#include "CLI.hpp"
#include "DFSGen.hpp"

int main()
{
    vector<string> cmndString = {"Display Files", "Generate Maze", "Display Maze", "Save Maze", "Load Maze", "Maze Size", "File Size", "Solve Maze", "Display Solution"};
    CommandHM cmdHashMap;
    cmdHashMap.insertCommand(cmndString[0], new FilePath);
    cmdHashMap.insertCommand(cmndString[1], new GenerateMaze);
    cmdHashMap.insertCommand(cmndString[2], new DisplayMaze);
    cmdHashMap.insertCommand(cmndString[3], new SaveMaze);
    cmdHashMap.insertCommand(cmndString[4], new LoadMaze);
    cmdHashMap.insertCommand(cmndString[5], new MazeObjSize);
    cmdHashMap.insertCommand(cmndString[6], new MazeFileSize);
    cmdHashMap.insertCommand(cmndString[7], new SolveMaze);
    cmdHashMap.insertCommand(cmndString[8], new DisplayMazeSolution);
    CLI slay(&cmdHashMap);
    slay.Start();

    return 0;
}