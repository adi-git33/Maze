#include "CLI.hpp"
#include "Controller.hpp"

int main()
{
    vector<string> cmndString = {"Display Files", "Generate Maze", "Display Maze", "Save Maze", "Load Maze", "Maze Size", "File Size", "Solve Maze Manualy", "Solve Maze Algorithm",
                                 "Display Solution"};
    CommandHM cmdHashMap;
    unique_ptr<Command> filePathCommand = make_unique<FilePath>();
    cmdHashMap.insertCommand(cmndString[0], move(filePathCommand));

    unique_ptr<Command> generateMazeCommand = make_unique<GenerateMaze>();
    cmdHashMap.insertCommand(cmndString[1], move(generateMazeCommand));

    unique_ptr<Command> DisplayMazeCommand = make_unique<DisplayMaze>();
    cmdHashMap.insertCommand(cmndString[2], move(DisplayMazeCommand));

    unique_ptr<Command> SaveMazeCommand = make_unique<SaveMaze>();
    cmdHashMap.insertCommand(cmndString[3], move(SaveMazeCommand));

    unique_ptr<Command> LoadMazeCommand = make_unique<LoadMaze>();
    cmdHashMap.insertCommand(cmndString[4], move(LoadMazeCommand));

    unique_ptr<Command> MazeObjSizeCommand = make_unique<MazeObjSize>();
    cmdHashMap.insertCommand(cmndString[5], move(MazeObjSizeCommand));

    unique_ptr<Command> MazeFileSizeCommand = make_unique<MazeFileSize>();
    cmdHashMap.insertCommand(cmndString[6], move(MazeFileSizeCommand));

    unique_ptr<Command> SolveMazeManualyCommand = make_unique<SolveMazeManualy>();
    cmdHashMap.insertCommand(cmndString[7], move(SolveMazeManualyCommand));

    unique_ptr<Command> SolveMazeAlgorithmCommand = make_unique<SolveMazeAlgorithm>();
    cmdHashMap.insertCommand(cmndString[8], move(SolveMazeAlgorithmCommand));

    unique_ptr<Command> DisplayMazeSolutionCommand = make_unique<DisplayMazeSolution>();
    cmdHashMap.insertCommand(cmndString[9], move(DisplayMazeSolutionCommand));

    Controller *MyController = new Controller(new Maze2dModel, new CLI, &cmdHashMap);
    MyController->startFunc();

    return 0;
}