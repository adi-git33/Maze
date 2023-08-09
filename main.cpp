#include "SimpleMaze2dGenerator.hpp"
#include "BFS.hpp"
#include "AStar.hpp"
#include "Maze2dSearchable.hpp"
#include "Demo.hpp"
#include "Player.hpp"
#include "MazeCompression.hpp"

int main()
{
    MazeCompression mazeFiles;
    SimplaMaze2dGenerator createMaze;
    Maze2d myMaze1 = createMaze.mazeGenerator();
    cout << myMaze1;

    vector<vector<int>> mazesArr;
    vector<int> maze1Data = myMaze1.getData();
    mazesArr.push_back(maze1Data);
    mazeFiles.save(mazesArr);

    vector<vector<int>> loadmazeArr = mazeFiles.load();
    Maze2d loadedMaze1(loadmazeArr.at(0));

    cout << "maze 1" << endl;
    cout << loadedMaze1;

    Maze2dSearchable Searchie(myMaze1);
    BFS<int *> *searchBFS = new BFS<int *>();
    Solution<int *> soluchie = searchBFS->search(Searchie);

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