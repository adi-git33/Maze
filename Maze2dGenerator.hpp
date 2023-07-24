#pragma once
#include "Maze2d.hpp"
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

using namespace std;

class Maze2dGenerator
{
private:
public:
    // Constractors
    Maze2dGenerator();
    // Destractors
    virtual ~Maze2dGenerator() = 0;
    // Operators
    // Getters
    // Setters
    // Functions
    virtual Maze2d mazeGenerator(int row, int col);
    virtual string measureAlgorithmTime(alg A, Maze2d M){
        // system clock start time
        // mazeGenerator()
        // system clock end time
        // return measure time that is comfrotable to read
    };
};

class SimplaMaze2dGenerator : public Maze2dGenerator
{
private:
    Maze2d *m_arrMaze;

public:
    // Constractors
    SimplaMaze2dGenerator();
    // Destractors
    virtual ~SimplaMaze2dGenerator();
    // Operators

    // Getters
    // Setters
    // Functions
    virtual Maze2d mazeGenerator(int row, int col){
        // creates random maze with prim
    };
};
