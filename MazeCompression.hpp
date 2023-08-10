// ----- Code by: Moran Sinai ID: 206402281 and Adi Levi ID: 316116052
// #pragma once
#ifndef __MAZECOMPRESSION__
#define __MAZECOMPRESSION__
#include "Maze2d.hpp"
#include "Memory.hpp"

class MazeCompression
{
private:
public:
    void save(vector<int> &mazeVector, string mazeName)
    {
        std::ofstream mazeData("" + mazeName + ".txt");
        if (mazeData.is_open())
        {
            for (const int &value : mazeVector)
            {
                mazeData << value << " ";
            }
            mazeData.close();
            std::cout << "Vector data saved to file." << std::endl;
        }
        else
        {
            std::cerr << "Error opening file for writing." << std::endl;
        }
    }
    vector<int> load(string mazeName)
    {
        std::vector<int> loadedVector;
        std::ifstream mazeData("" + mazeName + ".txt");
        int value;
        while (mazeData >> value)
        {
            loadedVector.push_back(value);
        }
        mazeData.close();
        return loadedVector;
    }

};
#endif
