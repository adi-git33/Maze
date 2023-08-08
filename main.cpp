#include "Maze2d.hpp"
#include "Maze2dGenerator.hpp"
#include "SimpleMaze2dGenerator.hpp"


#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <utility>
#include <exception>
#include <vector>
#include <iterator>
#include <fstream>
#include <cstring>


int main(){

    SimplaMaze2dGenerator createMaze;
    Maze2d myMaze = createMaze.mazeGenerator();

    myMaze.getData();

    return 0;
}