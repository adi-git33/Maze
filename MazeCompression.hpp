// ----- Code by: Moran Sinai ID: 206402281 and Adi Levi ID: 316116052
// #pragma once
#ifndef __MAZECOMPRESSION__
#define __MAZECOMPRESSION__
#include "Maze2d.hpp"
#include "Memory.hpp"


void save(vector<Maze2d> &EmployeeVec)  // compress maze and save to memory
{
    ofstream empsBin("emps.bin", ios::binary | std::ios::trunc);
    if (empsBin.is_open() == true)
    {
        for (int i = 0; i < EmployeeVec.size(); i++)
        {
            empsBin.write((char *)&EmployeeVec[i], sizeof(Maze2d));
        }
        empsBin.close();
    }
    else
    {
        FileNotRead err;
        throw(err);
    }
}

vector<Maze2d> load(vector<Maze2d> newVec)  // load comppressed maze
{
    ifstream bin;
    bin.open("emps.bin", ios::binary);
    if (bin.is_open() == true)
    {
        // Maze2d *tmpMaze = new Maze2d();
        // while (bin.read((char *)(tmpMaze), sizeof(Maze2d)))
        // {
        //     newVec.push_back(*tmpMaze);
        // }
        // bin.close();
    }
    else
    {
        FileNotRead err;
        throw(err);
    }
    return newVec;
}

#endif