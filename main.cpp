#include "SimpleMaze2dGenerator.hpp"
#include "BFS.hpp"
#include "AStar.hpp"
#include "Maze2dSearchable.hpp"
#include "Demo.hpp"


int main()
{
    // SimplaMaze2dGenerator createMaze;
    // Maze2d myMaze1 = createMaze.mazeGenerator();
    // Maze2d myMaze2 = createMaze.mazeGenerator();

    // Maze2dSearchable Searchie(myMaze1);
    // BFS<int *> *searchBFS = new BFS<int *>();
    // Solution<int *> soluchie = searchBFS->search(Searchie);

    // int *currentPosition = myMaze1.getCurrentPosition();
    // State<int *> currentState(currentPosition);
    // Searchie.getAllPossibleStates(currentState);

    // myMaze1.getGoalPosition();
    // myMaze1.getStartPosition();

    Demo demonic;
    demonic.Run();

    return 0;
}