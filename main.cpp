#include "SimpleMaze2dGenerator.hpp"
#include "BFS.hpp"
#include "AStar.hpp"
#include "Maze2dSearchable.hpp"
#include "Demo.hpp"
#include "Player.hpp"
#include "MazeCompression.hpp"
#include "CLI.hpp"

int main()
{
    CommandHM cmdHashMap;
    string generate = "Generate Maze";
    vector<string> cmndString = {"Generate Maze", "Display Maze", "Save Maze", "Load Maze", "Maze Object Size", "Solve Maze"};
    cmdHashMap.insertCommand(generate, new GenerateMaze);
    cmdHashMap.insertCommand(generate, new GenerateMaze);

    cmdHashMap.insertCommand(cmndString[1], new DisplayMaze);

    cmdHashMap.insertCommand(cmndString[2], new SaveMaze);

    cmdHashMap.insertCommand(cmndString[3], new LoadMaze);

    cmdHashMap.insertCommand(cmndString[4], new MazeObjSize);

    cmdHashMap.insertCommand(cmndString[5], new SolveMaze);

    vector<string> paramYing = {"WWX", "10", "10"};
    vector<string> paramZhan = {"LZ", "13", "13"};
    cmdHashMap.executeCommand(generate, paramYing);
    cmdHashMap.executeCommand(cmndString[0], paramZhan);
    cmdHashMap.executeCommand(cmndString[0], paramZhan);

    vector<string> disParam = {"WWX"};
    vector<string> saveParam = {"LZ", "LanZhan"};
    cmdHashMap.executeCommand(cmndString[1], disParam);
    cmdHashMap.executeCommand(cmndString[2], saveParam);
    
    vector<string> zibiParam = {"zibi", "Binghe"};
    cmdHashMap.executeCommand(cmndString[3], zibiParam);

    vector<string> annoyingDog = {"Binghe"};
    cmdHashMap.executeCommand(cmndString[4], annoyingDog);

    vector<string> solveWWX = {"WWX", "AStar"};
    cmdHashMap.executeCommand(cmndString[5], solveWWX);
    // CLI clip(&cmdHashMap);
    // clip.Start();
    // MazeCompression mazeFiles;
    // SimplaMaze2dGenerator createMaze;
    // Maze2d myMaze1 = createMaze.mazeGenerator();
    // cout << myMaze1;

    // vector<int> maze1Data = myMaze1.getData();
    // mazeFiles.save(maze1Data, myMaze1.getMazeName());

    // vector<int> loadmazeArr = mazeFiles.load(myMaze1.getMazeName());
    // Maze2d loadedMaze1(loadmazeArr, myMaze1.getMazeName());

    // cout << "maze 1" << endl;
    // cout << loadedMaze1;

    // Maze2dSearchable Searchie(myMaze1);
    // BFS<int *> *searchBFS = new BFS<int *>();
    // Solution<int *> soluchie = searchBFS->search(Searchie);

    // cout << myMaze1;
    // int *currentPosition = myMaze1.getCurrentPosition();
    // Player weiying("wwx");
    // weiying.Move(Up, &myMaze1);
    // cout << myMaze1;
    // weiying.Move(Left, &myMaze1);
    // cout << myMaze1;
    // weiying.Move(Down, &myMaze1);
    // cout << myMaze1;
    // weiying.Move(Right, &myMaze1);

    // State<int *> currentState(currentPosition);
    // Searchie.getAllPossibleStates(currentState);

    // myMaze1.getGoalPosition();
    // myMaze1.getStartPosition();

    // Demo demonic;
    // demonic.Run();

    // cli newsli;
    // view gameView(cli);
    // model gameModel;
    // controller gameController(gameView, gameModel);
    // gameController.view.cli.start();

    return 0;
}